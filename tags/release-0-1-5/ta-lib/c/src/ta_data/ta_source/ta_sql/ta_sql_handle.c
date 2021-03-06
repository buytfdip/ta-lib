/* TA-LIB Copyright (c) 1999-2004, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  PK       Pawel Konieczny
 *  MF       Mario Fortier
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  101703 PK   First version.
 *  110103 PK   Minidriver architecture
 *  012504 MF   Add some TA_ASSERT + minor changes to be more C vs C++.
 */

/* Description:
 *    Allows to allocate/de-allocate TA_DataSourceHandle structure.
 *    Executes SQL queries to build up the index of categories and symbols.
 */

/**** Headers ****/
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "ta_trace.h"
#include "ta_memory.h"
#include "ta_global.h"
#include "ta_sql_handle.h"
#include "ta_sql_local.h"

/**** External functions declarations. ****/
/* None */

/**** External variables declarations. ****/
/* None */

/**** Global variables definitions.    ****/
/* None */

/**** Local declarations.              ****/
/* None */

/**** Local functions.    ****/
static TA_PrivateSQLHandle *allocPrivateHandle( void );
static TA_RetCode freePrivateHandle( TA_PrivateSQLHandle *privateHandle );
static TA_RetCode freeCategoryIndex( void *toBeFreed );
static TA_RetCode freeSymbolsIndex( void *toBeFreed );
static TA_RetCode registerCategoryAndSymbol( TA_List *categoryIndex, TA_String *category, TA_String *symbol );
static TA_RetCode registerCategoryAndAllSymbols( TA_PrivateSQLHandle *privateHandle, TA_String *category);

/**** Local variables definitions.     ****/
TA_FILE_INFO;

/**** Global functions definitions.   ****/


TA_DataSourceHandle *TA_SQL_DataSourceHandleAlloc( const TA_AddDataSourceParamPriv *param )
{
   TA_DataSourceHandle *handle;

   TA_ASSERT_RET( param != NULL, (TA_DataSourceHandle *)NULL );
      
   handle = (TA_DataSourceHandle *)TA_Malloc(sizeof( TA_DataSourceHandle ));
   if( !handle )
      return NULL;

   /* Initialized fields. */
   handle->nbCategory = 0;

   /* Allocate the opaque data. */
   handle->opaqueData = allocPrivateHandle();
   if( !handle->opaqueData )
   {
      TA_SQL_DataSourceHandleFree( handle );
      return NULL;
   }

   ((TA_PrivateSQLHandle *)handle->opaqueData)->param = param;

   return handle;
}



TA_RetCode TA_SQL_DataSourceHandleFree( TA_DataSourceHandle *handle )
{
   TA_PROLOG
   TA_PrivateSQLHandle *privateHandle;

   TA_TRACE_BEGIN(  TA_SQL_DataSourceHandleFree );

   TA_ASSERT( handle != NULL );

   privateHandle = (TA_PrivateSQLHandle *)handle->opaqueData;

   if( handle )
   {
      if( freePrivateHandle( (TA_PrivateSQLHandle *)handle->opaqueData ) != TA_SUCCESS )
      {
         TA_FATAL(  NULL, handle, 0 );
      }

      TA_Free( handle );
   }

   TA_TRACE_RETURN( TA_SUCCESS );
}



TA_RetCode TA_SQL_BuildSymbolsIndex( TA_DataSourceHandle *handle )
{
   TA_PROLOG
   TA_RetCode retCode;
   TA_PrivateSQLHandle *privateHandle;
   TA_StringCache *stringCache;
   const char *strval;
   void *queryResult;
   int resColumns;
   int catCol, symCol;
   int rowNum;
   TA_String *cat_name;
   TA_String *sym_name;
   const char *name;

   TA_TRACE_BEGIN( TA_SQL_BuildSymbolsIndex );
  
   TA_ASSERT(handle != NULL );
   privateHandle = (TA_PrivateSQLHandle *)handle->opaqueData;

   TA_ASSERT( privateHandle != NULL );
   TA_ASSERT( privateHandle->param != NULL );
   TA_ASSERT( privateHandle->param->category != NULL );
   TA_ASSERT( privateHandle->param->location != NULL );
   TA_ASSERT( privateHandle->connection != NULL );
   TA_ASSERT( privateHandle->minidriver->executeQuery != NULL );

   /* Initialize variables. */
   retCode = TA_SUCCESS;
   stringCache = TA_GetGlobalStringCache();
   strval = NULL;

   /* De-allocate potentialy already existing category index. */
   if( privateHandle->theCategoryIndex != NULL )
   {
      retCode = TA_ListFreeAll(privateHandle->theCategoryIndex, freeCategoryIndex);
      privateHandle->theCategoryIndex = NULL;
      if( retCode != TA_SUCCESS )
      {
         TA_TRACE_RETURN( retCode );
      }
   }

   /* Allocate new category index. */
   privateHandle->theCategoryIndex = TA_ListAlloc();
   if( !privateHandle->theCategoryIndex )
   {
      TA_TRACE_RETURN( TA_ALLOC_ERR );
   }

   if( strnicmp("SELECT ", TA_StringToChar(privateHandle->param->category), 7) == 0)
   {
      /* This is an SQL query; execute it to obtain the list of categories */

      retCode = (*privateHandle->minidriver->executeQuery)(
                  privateHandle->connection,
                  TA_StringToChar(privateHandle->param->category),
                  &queryResult);
      if( retCode != TA_SUCCESS )
      {
         TA_TRACE_RETURN( retCode );
      }
      

      /* from now on: the query has to be released upon premature return */
      #define RETURN_ON_ERROR( rc )       \
      {                                   \
         if( rc != TA_SUCCESS )           \
         {                                \
            (*privateHandle->minidriver->releaseQuery)(queryResult); \
            TA_TRACE_RETURN( rc );        \
         }                                \
      }
      #define RETURN_FUNC( rc )           \
      {                                   \
         (*privateHandle->minidriver->releaseQuery)(queryResult); \
         TA_TRACE_RETURN( rc );        \
      }

      /* find the category column number, if present */
      retCode = (*privateHandle->minidriver->getNumColumns)(
                     queryResult,
                     &resColumns );
      RETURN_ON_ERROR( retCode );
      
      for ( catCol = 0; catCol < resColumns; catCol++) 
      { 
         retCode = (*privateHandle->minidriver->getColumnName)(
                              queryResult,
                              catCol,
                              &name );
         RETURN_ON_ERROR( retCode );
         if( stricmp(name, TA_SQL_CATEGORY_COLUMN) == 0 )
            break;
      } 
      if( catCol == resColumns )
      {
         RETURN_FUNC( TA_CATEGORY_NOT_FOUND );
      }

      /* find the symbol column number, if present */
      for ( symCol = 0; symCol < resColumns; symCol++) 
      { 
         retCode = (*privateHandle->minidriver->getColumnName)(
                              queryResult,
                              symCol,
                              &name );
         RETURN_ON_ERROR( retCode );
         if( stricmp(name, TA_SQL_SYMBOL_COLUMN) == 0 )
            break;
      }

      /* iterate through all rows */
      for( rowNum = 0;  
           (retCode = 
               (*privateHandle->minidriver->getRowString)(
                                 queryResult,
                                 rowNum, 
                                 catCol,
                                 &strval )
           ) != TA_END_OF_INDEX;
           rowNum++) 
      {
         cat_name = NULL;
         sym_name = NULL;

         RETURN_ON_ERROR( retCode );  /* retCode from the for-condition */

         if( strval && strval[0] != '\0' )  
         {
            cat_name = TA_StringAlloc( stringCache, strval );
         }
         else /* for NULL values fall back to default */
         {
            cat_name = TA_StringAlloc( stringCache, TA_DEFAULT_CATEGORY );
         }

         if( !cat_name )
         {
            RETURN_FUNC( TA_ALLOC_ERR );
         }

         if( symCol < resColumns )  /* we can collect symbols as well */
         {
            retCode = (*privateHandle->minidriver->getRowString)(
                                 queryResult,
                                 rowNum, 
                                 symCol,
                                 &strval );
            if ( retCode != TA_SUCCESS )
            {
               TA_StringFree(stringCache, cat_name);
               RETURN_ON_ERROR( retCode );
            }
       
            if( strval && strval[0] != '\0' )  /* not NULL value */
            {
                sym_name = TA_StringAlloc( stringCache, strval );

                if( !sym_name )
                {
                    RETURN_FUNC( TA_ALLOC_ERR );
                }
            }
         }

         if ( sym_name )
         {
            retCode = registerCategoryAndSymbol(privateHandle->theCategoryIndex, 
                                                cat_name,
                                                sym_name);
         }
         else
         {
            retCode = registerCategoryAndAllSymbols(privateHandle,
                                                    cat_name);
         }

         TA_StringFree(stringCache, cat_name);
         if( sym_name )
            TA_StringFree(stringCache, sym_name);

         if( retCode != TA_SUCCESS )
         {
            break;
         }
      } 

      if( retCode == TA_END_OF_INDEX )
      {
        retCode = TA_SUCCESS;
      }
   }
   else
   {
      /* Create one category, taking the category sting literally */
      retCode = registerCategoryAndAllSymbols(privateHandle, 
                                              privateHandle->param->category);
   }

#undef RETURN_ON_ERROR
#undef RETURN_FUNC
   
   TA_TRACE_RETURN( retCode );
}



/**** Local functions definitions.     ****/

static TA_PrivateSQLHandle *allocPrivateHandle( void  )
{
   TA_PrivateSQLHandle *privateHandle;

   privateHandle = (TA_PrivateSQLHandle *)TA_Malloc( sizeof( TA_PrivateSQLHandle ) );
   if( !privateHandle )
      return NULL;

   memset( privateHandle, 0, sizeof( TA_PrivateSQLHandle ) );

   return privateHandle;
}



static TA_RetCode freePrivateHandle( TA_PrivateSQLHandle *privateHandle )
{
   TA_RetCode retCode;
   TA_RetCode retCode2;

   retCode = TA_SUCCESS;
   if( privateHandle )
   {
      if( privateHandle->database )
      {
         TA_StringFree( TA_GetGlobalStringCache(), privateHandle->database );
      }

      if( privateHandle->theCategoryIndex )
      {
         retCode = TA_ListFreeAll(privateHandle->theCategoryIndex, freeCategoryIndex);
         privateHandle->theCategoryIndex = NULL;
      }

      if( privateHandle->connection )
      {
         if( privateHandle->minidriver->closeConnection )
         {
            retCode2 = (*privateHandle->minidriver->closeConnection)( privateHandle->connection );               
            if( retCode2 != TA_SUCCESS )
            {
               retCode = retCode2;
            }
         }
         else
         {
            retCode = TA_INTERNAL_ERR;
         }
         privateHandle->connection = NULL;
      }

      TA_Free( privateHandle );
   }

   return retCode;
}



static TA_RetCode freeCategoryIndex( void *toBeFreed )
{
   TA_SQLCategoryNode *node;
   TA_RetCode retCode;

   node = (TA_SQLCategoryNode*)toBeFreed;
   retCode = TA_SUCCESS;

   if( !node )
      return TA_SUCCESS;

   if( node->category && retCode == TA_SUCCESS )
   {
      TA_StringFree( TA_GetGlobalStringCache(), node->category );
      node->category = NULL;
   }

   if( node->theSymbols && retCode == TA_SUCCESS )
   {
      retCode = TA_ListFreeAll( node->theSymbols, freeSymbolsIndex);
      node->theSymbols = NULL;
   }
   
   if( retCode == TA_SUCCESS )
   {
      TA_Free(node);
   }

   return retCode;
}



static TA_RetCode freeSymbolsIndex( void *toBeFreed )
{
   TA_String *symbol;
   TA_RetCode retCode;

   symbol = (TA_String*)toBeFreed;
   retCode = TA_SUCCESS;

   if( symbol )
   {
      TA_StringFree( TA_GetGlobalStringCache(), symbol );
      symbol = NULL;
   }

   return retCode;
}



/* registerCategoryAndSymbol takes care of avoiding duplicates
 * The caller keeps ownership to passed parameters.
 * We will do dup here if needed.
 */
static TA_RetCode registerCategoryAndSymbol( TA_List *categoryIndex,
                                             TA_String *category, 
                                             TA_String *symbol )
{
   TA_String *known_symbol;
   TA_SQLCategoryNode *categoryNode;
   TA_RetCode retCode;

   if( !category )
      return TA_BAD_PARAM;

   /* Find out if the category is already registered */
   categoryNode = (TA_SQLCategoryNode*)TA_ListAccessHead(categoryIndex);
   while ( categoryNode 
        && strcmp(TA_StringToChar(categoryNode->category), TA_StringToChar(category)) != 0)
   {
      categoryNode = (TA_SQLCategoryNode*)TA_ListAccessNext(categoryIndex);
   }
 
   if( !categoryNode )
   {
      /* New category, allocate node for it */
      categoryNode = (TA_SQLCategoryNode*)TA_Malloc(sizeof( TA_SQLCategoryNode ));
      if( !categoryNode )
      {
         return TA_ALLOC_ERR;
      }
      memset(categoryNode, 0, sizeof( TA_SQLCategoryNode ));
      retCode = TA_ListAddTail( categoryIndex, categoryNode );
      if( retCode != TA_SUCCESS )
      {
         TA_Free(categoryNode);
         return retCode;
      }
      categoryNode->category = TA_StringDup(TA_GetGlobalStringCache(), category);
   }

   /* Register symbol, if not yet registered */
   if( symbol )
   {
      /* Find out if the symbol is already registered */
      known_symbol = (TA_String*)TA_ListAccessHead(categoryNode->theSymbols);
      while ( known_symbol 
           && strcmp(TA_StringToChar(known_symbol), TA_StringToChar(symbol)) != 0)
      {
         known_symbol = (TA_String*)TA_ListAccessNext(categoryNode->theSymbols);
      }

      if( !known_symbol )
      {
         /* New symbol, add it to the list */
         if( !categoryNode->theSymbols )
         {
            categoryNode->theSymbols = TA_ListAlloc();
            if( !categoryNode->theSymbols )
               return TA_ALLOC_ERR;
         }

         retCode = TA_ListAddTail( categoryNode->theSymbols, 
                                    (void*)TA_StringDup(TA_GetGlobalStringCache(), symbol) );
         if( retCode != TA_SUCCESS )
         {
            return retCode;
         }
      }
   }

   return TA_SUCCESS;
}



/* registerCategoryAndAllSymbols executes SQL query for the symbol and
 * registers all symbols in the same category
 */
static TA_RetCode registerCategoryAndAllSymbols( TA_PrivateSQLHandle *privateHandle,
                                                 TA_String *category)
{
   TA_PROLOG
   TA_RetCode retCode;
   TA_StringCache *stringCache;
   const char *strval;
   void *queryResult;
   int resColumns;
   int symCol;
   int rowNum;
   char *symQuery;
   TA_String *sym_name;
   const char *name;

   /* is trace allowed through static fuctions? */
   TA_TRACE_BEGIN( registerCategoryAndAllSymbols );

   stringCache = TA_GetGlobalStringCache();
   strval = NULL;

   if( !category )
   {
      TA_TRACE_RETURN(TA_BAD_PARAM);
   }

   if( privateHandle->param->symbol 
       && strnicmp("SELECT ", TA_StringToChar(privateHandle->param->symbol), 7) == 0)
   {
      /* This is an SQL query; execute it to obtain the list of symbols */
   
      /* Because the query may return no results, we must make sure that
       * at leas the category will be registered.
       */
      retCode = registerCategoryAndSymbol(privateHandle->theCategoryIndex, 
                                          category,
                                          NULL);
      if( retCode != TA_SUCCESS )
      {
         TA_TRACE_RETURN(retCode);
      }

      /* Now the SQL query */
      symQuery = TA_SQL_ExpandPlaceholders(TA_StringToChar(privateHandle->param->symbol),
                                            TA_SQL_CATEGORY_PLACEHOLDER,
                                            TA_StringToChar(category));
      if( !symQuery )
      {
         TA_TRACE_RETURN( TA_ALLOC_ERR );
      }

      retCode = (*privateHandle->minidriver->executeQuery)(
                  privateHandle->connection,
                  symQuery,
                  &queryResult);
      if( retCode != TA_SUCCESS )
      {
         TA_TRACE_RETURN( retCode );
      }
      
      /* from now on: the query has to be released upon premature return */
      #define RETURN_ON_ERROR( rc )       \
      {                                   \
         if( rc != TA_SUCCESS )           \
         {                                \
            (*privateHandle->minidriver->releaseQuery)(queryResult); \
            TA_TRACE_RETURN( rc );        \
         } \
      }
      #define RETURN_FUNC( rc )           \
      {                                   \
         (*privateHandle->minidriver->releaseQuery)(queryResult); \
         TA_TRACE_RETURN( rc );        \
      }


      /* find the symbol column number, if present */
      retCode = (*privateHandle->minidriver->getNumColumns)(
                     queryResult,
                     &resColumns );
      RETURN_ON_ERROR( retCode );

      for ( symCol = 0; symCol < resColumns; symCol++) 
      { 
         name = NULL;

         retCode = (*privateHandle->minidriver->getColumnName)(
                              queryResult,
                              symCol,
                              &name );
         RETURN_ON_ERROR( retCode );

         if( (stricmp(name, TA_SQL_SYMBOL_COLUMN) == 0) )
         {
            break;
         }
      }
      if( symCol == resColumns )
      {
         RETURN_FUNC( TA_BAD_QUERY );
      }

      /* iterate through all rows */
      for( rowNum = 0;  
           (retCode = 
               (*privateHandle->minidriver->getRowString)(
                              queryResult,
                              rowNum, 
                              symCol,
                              &strval )
           ) != TA_END_OF_INDEX;
           rowNum++) 
      {
         sym_name = NULL;

         RETURN_ON_ERROR( retCode );  /* retCode from the for-condition */

         if( strval )
         {
            sym_name = TA_StringAlloc( stringCache, strval );
         }

         if( !sym_name )
         {
            RETURN_FUNC( TA_ALLOC_ERR );
         }

         if( strcmp(TA_StringToChar(sym_name), "") != 0 )  /* ignore NULL fields */
         {
            retCode = registerCategoryAndSymbol(privateHandle->theCategoryIndex, 
                                                category,
                                                sym_name);
         }
         TA_StringFree(stringCache, sym_name);

         if( retCode != TA_SUCCESS )
         {
            break;
         }
      }
      if( retCode == TA_END_OF_INDEX )
      {
         retCode = TA_SUCCESS;
      }

      TA_Free(symQuery);
   }
   else if ( privateHandle->param->symbol
             && *TA_StringToChar(privateHandle->param->symbol) != '\0' )
   {
      /* Create one symbol, taking the symbol sting literally */
      retCode = registerCategoryAndSymbol(privateHandle->theCategoryIndex, 
                                          category,
                                          privateHandle->param->symbol);
   }
   else
   {
      /* Create one symbol, falling back to the database name */
      retCode = registerCategoryAndSymbol(privateHandle->theCategoryIndex, 
                                          category,
                                          privateHandle->database);
   }

#undef RETURN_ON_ERROR
#undef RETURN_FUNC
      
   TA_TRACE_RETURN( retCode );   
}


