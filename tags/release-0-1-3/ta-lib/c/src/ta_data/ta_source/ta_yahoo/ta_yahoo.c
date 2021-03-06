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
 *  MF       Mario Fortier
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  070701 MF   First version.
 *  061104 MF   Add TA_YAHOO_ONE_SYMBOL.
 *  062104 MF   Server can now be override using the 'location' param.
 */

/* Description:
 *    This is the entry points of the data source driver for
 *    the Yahoo! web site.
 *
 *    It provides ALL the functions needed by the "TA_DataSourceDriver"
 *    structure (see ta_source.h).
 */

/**** Headers ****/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ta_source.h"
#include "ta_yahoo.h"
#include "ta_common.h"
#include "ta_memory.h"
#include "ta_trace.h"
#include "ta_list.h"
#include "ta_data.h"
#include "ta_system.h"
#include "ta_yahoo_idx.h"
#include "ta_yahoo_handle.h"
#include "ta_yahoo_priv.h"
#include "ta_global.h"
#include "ta_country_info.h"
#include "sfl.h"

/**** External functions declarations. ****/
/* None */

/**** External variables declarations. ****/
/* None */

/**** Global variables definitions.    ****/
/* None */

/**** Local declarations.              ****/

/* String used to specify an alternate "server" in the location parameter. */
#define TA_SERVER_STR "server="

/**** Local functions declarations.    ****/
static TA_RetCode initCategoryHandle( TA_DataSourceHandle *handle,
                                      TA_CategoryHandle   *categoryHandle,
                                      unsigned int index );

static TA_RetCode initSymbolHandle( TA_DataSourceHandle *handle,
                                    TA_CategoryHandle   *categoryHandle,
                                    TA_SymbolHandle     *symbolHandle,
                                    unsigned int index );

/**** Local variables definitions.     ****/
TA_FILE_INFO;

/**** Global functions definitions.   ****/
TA_RetCode TA_YAHOO_InitializeSourceDriver( void )
{
   TA_PROLOG
   TA_TRACE_BEGIN( TA_YAHOO_InitializeSourceDriver );

    /* Nothing to do for the time being. */
   TA_TRACE_RETURN( TA_SUCCESS );
}

TA_RetCode TA_YAHOO_ShutdownSourceDriver( void )
{
   TA_PROLOG
   TA_TRACE_BEGIN( TA_YAHOO_ShutdownSourceDriver );

    /* Nothing to do for the time being. */
   TA_TRACE_RETURN( TA_SUCCESS );
}

TA_RetCode TA_YAHOO_GetParameters( TA_DataSourceParameters *param )
{
   TA_PROLOG

   TA_TRACE_BEGIN( TA_YAHOO_GetParameters );

   memset( param, 0, sizeof( TA_DataSourceParameters ) );

   /* Internet access is considered slow. */
   param->flags = TA_SLOW_ACCESS;

   /* Indicate the support for split/value adjustment. */
   param->flags |= TA_DO_NOT_SPLIT_ADJUST;
   param->flags |= TA_DO_NOT_VALUE_ADJUST;

   TA_TRACE_RETURN( TA_SUCCESS );
}


TA_RetCode TA_YAHOO_OpenSource( const TA_AddDataSourceParamPriv *param,
                                TA_DataSourceHandle **handle )
{
   TA_PROLOG
   TA_DataSourceHandle *tmpHandle;
   TA_PrivateYahooHandle *privData;
   TA_RetCode retCode;
   TA_StringCache *stringCache;
   TA_CountryId countryId;
   TA_CountryId countryIdTemp;
   TA_Timestamp now;
   const char *locationPtr;
   char locationBuffer[3];
   int timeout_set; /* boolean */
   int i, again;
   unsigned int strLength, strServerLength;
   const char *strTemp;

   *handle = NULL;

   TA_TRACE_BEGIN( TA_YAHOO_OpenSource );

   stringCache = TA_GetGlobalStringCache();

   /* Verify that the requested functionality is supported or not. */
   if( param->flags & TA_REPLACE_ZERO_PRICE_BAR )
   {
      TA_TRACE_RETURN( TA_NOT_SUPPORTED );
   }

   /* Allocate and initialize the handle. This function will also allocate the
    * private handle (opaque data).
    */
   tmpHandle = TA_YAHOO_DataSourceHandleAlloc();

   if( tmpHandle == NULL )
   {
      TA_TRACE_RETURN( TA_ALLOC_ERR );
   }

   privData = (TA_PrivateYahooHandle *)(tmpHandle->opaqueData);

   /* Copy some parameters in the private handle. */
   privData->param = param;
   
   /* Indentify the country and replace with the default as needed.
    * At the same time, identify optional "server=" modifier.
    */
   countryId = TA_Country_ID_INVALID;
   if( privData->param->location )
   {
      locationPtr = TA_StringToChar(privData->param->location);

      /* Split into token (seperator is ';'). Check for a 2 character country 
       * string and the optional "server=" modifier.
       */
      i = -1; 
      strTemp = &locationPtr[0];
      strLength = 0;
      strServerLength = strlen(TA_SERVER_STR);
      again = 1;
      while( (++i < 1024) && again )
      {
         if( strLength == 0 )
            strTemp = &locationPtr[i];

         if( locationPtr[i] == '\0' )
            again = 0;         

         if( locationPtr[i] == ';' || !again )
         {
            if( strLength == 2 )
            {
               locationBuffer[0] = locationPtr[i-2];
               locationBuffer[1] = locationPtr[i-1];
               locationBuffer[2] = '\0';
               countryIdTemp = TA_CountryAbbrevToId(locationBuffer);
               if( countryIdTemp == TA_Country_ID_INVALID )
                  TA_TRACE_RETURN( TA_UNSUPPORTED_COUNTRY );
               if( countryId != TA_Country_ID_INVALID )
                  TA_TRACE_RETURN( TA_LIMIT_OF_ONE_COUNTRY_ID_EXCEEDED );
               countryId = countryIdTemp;         
            }
            else if( strLength>strServerLength && (strncmp(strTemp,TA_SERVER_STR,strServerLength)==0) )
            {              
               if( privData->userSpecifiedServer )
                  TA_TRACE_RETURN( TA_LIMIT_OF_ONE_SERVER_EXCEEDED );
               privData->userSpecifiedServer = TA_StringAllocN( stringCache, 
                                                                &strTemp[strServerLength],
                                                                strLength-strServerLength );
               TA_ASSERT( privData->userSpecifiedServer != NULL );
            }
            else
               TA_TRACE_RETURN( TA_LOCATION_PARAM_INVALID );

            strLength = 0;           
         }
         else
            strLength++;
      }
   }

   if( countryId == TA_Country_ID_INVALID )
   {
      /* Default is United States. */
      countryId = TA_Country_ID_US;
   }

   if( privData->param->id == TA_YAHOO_ONE_SYMBOL )
   {
      /* Check for the web site providing the data when adding
       * only ONE symbol to the index.
       */
      switch( countryId )
      {
      case TA_Country_ID_US:
         /* For this data source, US is the only Yahoo! web
          * site supported for now.
          */
         break;
      default:
         TA_YAHOO_DataSourceHandleFree( tmpHandle );
         TA_TRACE_RETURN( TA_UNSUPPORTED_COUNTRY );
      }
      privData->index = NULL;
      privData->webSiteCountry = countryId;
      privData->webSiteSymbol  = TA_StringDup(stringCache,privData->param->info);
      tmpHandle->nbCategory = 1;
   }
   else
   {
      /* Build the index using .dat files */
      switch( countryId )
      {
      case TA_Country_ID_US: /* United States */
      case TA_Country_ID_CA: /* Canada */
      case TA_Country_ID_UK: /* United Kingdom */
      case TA_Country_ID_DE: /* Germany */
      case TA_Country_ID_DK: /* Denmark */
      case TA_Country_ID_ES: /* Spain */
      case TA_Country_ID_FR: /* France */
      case TA_Country_ID_IT: /* Italy */
      case TA_Country_ID_SE: /* Sweden */
      case TA_Country_ID_NO: /* Norway */
         /* These country are currently supported. */
         break;
      default:
         TA_YAHOO_DataSourceHandleFree( tmpHandle );
         TA_TRACE_RETURN( TA_UNSUPPORTED_COUNTRY );
      }

      /* Establish the timeout for local cache of the index.
       * Let's make it 4 business days.
       */
      timeout_set = 0;
      TA_SetDefault( &now );
      retCode = TA_SetDateNow( &now );
      for( i=0; (i < 4) && (retCode == TA_SUCCESS); i++ )
         retCode = TA_PrevWeekday( &now );
      if( (i == 4) && (retCode == TA_SUCCESS) )
         timeout_set = 1;
      
      /* At this point, we got all the information we
       * need in the handle.
       * Now build the TA_YahooIdx.
       */
      retCode = TA_YahooIdxAlloc( countryId,
                                  &privData->index,
                                  TA_USE_LOCAL_CACHE|TA_USE_REMOTE_CACHE,
                                  NULL, timeout_set?&now:NULL, NULL );

      if( retCode != TA_SUCCESS )
      {
         TA_YAHOO_DataSourceHandleFree( tmpHandle );
         TA_TRACE_RETURN( retCode );
      }

      /* Set the total number of distinct category. */
      tmpHandle->nbCategory = privData->index->nbCategory;
   }

   *handle = tmpHandle;

   TA_TRACE_RETURN( TA_SUCCESS );
}

TA_RetCode TA_YAHOO_CloseSource( TA_DataSourceHandle *handle )
{
   TA_PROLOG

   TA_TRACE_BEGIN( TA_YAHOO_CloseSource );

   /* Free all ressource used by this handle. */
   if( handle )
      TA_YAHOO_DataSourceHandleFree( handle );

   TA_TRACE_RETURN( TA_SUCCESS );
}

TA_RetCode TA_YAHOO_GetFirstCategoryHandle( TA_DataSourceHandle *handle,
                                            TA_CategoryHandle   *categoryHandle )
{
   TA_PrivateYahooHandle *privData;

   privData = (TA_PrivateYahooHandle *)(handle->opaqueData);

   if( privData->param->id == TA_YAHOO_ONE_SYMBOL )
   {
      categoryHandle->nbSymbol = 1;
      categoryHandle->string = privData->param->category;
      return TA_SUCCESS;
   }

   return initCategoryHandle( handle, categoryHandle, 0 );
}

TA_RetCode TA_YAHOO_GetNextCategoryHandle( TA_DataSourceHandle *handle,
                                           TA_CategoryHandle   *categoryHandle,
                                           unsigned int index )
{
   TA_PrivateYahooHandle *privData;
   privData = (TA_PrivateYahooHandle *)(handle->opaqueData);

   if( privData->param->id == TA_YAHOO_ONE_SYMBOL )
      return TA_END_OF_INDEX;

   return initCategoryHandle( handle, categoryHandle, index );                              
}

TA_RetCode TA_YAHOO_GetFirstSymbolHandle( TA_DataSourceHandle *handle,
                                          TA_CategoryHandle   *categoryHandle,
                                          TA_SymbolHandle     *symbolHandle )
{
   TA_PrivateYahooHandle *privData;
   TA_String *symbol;
   TA_String *info;

   privData = (TA_PrivateYahooHandle *)(handle->opaqueData);

   if( privData->param->id == TA_YAHOO_ONE_SYMBOL )
   {
      info = privData->param->info;
      symbol = privData->param->symbol;
      if( !symbol )      
         symbol = info;
      symbolHandle->string = symbol;
      return TA_SUCCESS;
   }

   return initSymbolHandle( handle, categoryHandle, symbolHandle, 0 );
}


TA_RetCode TA_YAHOO_GetNextSymbolHandle( TA_DataSourceHandle *handle,
                                         TA_CategoryHandle   *categoryHandle,
                                         TA_SymbolHandle     *symbolHandle,
                                         unsigned int index )
{
    TA_PrivateYahooHandle *privData;
    privData = (TA_PrivateYahooHandle *)(handle->opaqueData);

    if( privData->param->id == TA_YAHOO_ONE_SYMBOL )
       return TA_END_OF_INDEX;

    return initSymbolHandle( handle, categoryHandle,                             
                             symbolHandle, index );
                             
}

TA_RetCode TA_YAHOO_GetHistoryData( TA_DataSourceHandle *handle,
                                    TA_CategoryHandle   *categoryHandle,
                                    TA_SymbolHandle     *symbolHandle,
                                    TA_Period            period,
                                    const TA_Timestamp  *start,
                                    const TA_Timestamp  *end,
                                    TA_Field             fieldToAlloc,
                                    TA_ParamForAddData  *paramForAddData )
{
   TA_PROLOG
   TA_RetCode retCode;
   TA_PrivateYahooHandle *yahooHandle;
   int again;

   TA_TRACE_BEGIN( TA_YAHOO_GetHistoryData );

   TA_ASSERT( handle != NULL );
   TA_ASSERT( paramForAddData != NULL );
   TA_ASSERT( categoryHandle != NULL );
   TA_ASSERT( symbolHandle != NULL );

   yahooHandle = (TA_PrivateYahooHandle *)handle->opaqueData;
   TA_ASSERT( yahooHandle != NULL );

   /* If the requested period is too precise for the
    * period that can be provided by this data source,
    * simply return without error.
    * Since no data has been added, the TA-LIB will ignore
    * this data source.
    */
   if( period < TA_DAILY )
   {
      TA_TRACE_RETURN( TA_SUCCESS );
   }

   /* Get the data from the WEB.
    *
    * Yahoo! sometimes have "gaps" in its data (like one
    * week missing), when this is being detected, we throw
    * away all the data up to now and start over (up to
    * 5 times before giving up).
    */
   again = 5;
   do
   {
      retCode = TA_GetHistoryDataFromWeb( handle,                                       
                                          categoryHandle, symbolHandle,
                                          TA_DAILY, start, end,                                            
                                          fieldToAlloc, paramForAddData );
      if( retCode == TA_DATA_GAP )
      {
         retCode = TA_HistoryAddDataReset( paramForAddData );
         if( retCode != TA_SUCCESS )
            again = 0; /* Give up */
         else
         {
            --again; /* Try again */

            /* Sometimes giving Yahoo! a break helps. */
            if( again < 2 )
               TA_Sleep( 10 ); /* Seconds */ 
            else
               TA_Sleep( 4 ); /* Seconds */ 
         }
      }
      else
      {
         again = 0; /* Exit the loop */
      }
   } while( again > 0 );


   TA_TRACE_RETURN( retCode );   
}

/**** Local functions definitions.     ****/
static TA_RetCode initCategoryHandle( TA_DataSourceHandle *handle,
                                      TA_CategoryHandle   *categoryHandle,
                                      unsigned int index )
{
   TA_PROLOG
   TA_PrivateYahooHandle *privData;
   TA_YahooIdx *yahooIndex;
   TA_String   *string;

   TA_TRACE_BEGIN( TA_YAHOO_GetFirstCategoryHandle );

   if( (handle == NULL) || (categoryHandle == NULL) )
   {
      TA_TRACE_RETURN( TA_BAD_PARAM );
   }

   privData = (TA_PrivateYahooHandle *)(handle->opaqueData);

   if( !privData )
   {
      TA_TRACE_RETURN( TA_INTERNAL_ERROR(99) );
   }

   yahooIndex = privData->index;

   if( !yahooIndex )
   {
      TA_TRACE_RETURN( TA_INTERNAL_ERROR(100) );
   }

   if( index >= yahooIndex->nbCategory )
      return TA_END_OF_INDEX;

   string = yahooIndex->categories[index]->name;

   if( !string )
   {
      TA_TRACE_RETURN( TA_INTERNAL_ERROR(101) ); /* At least one category must exist. */
   }

   /* Set the categoryHandle. */
   categoryHandle->string = string;
   categoryHandle->nbSymbol = yahooIndex->categories[index]->nbSymbol;
   categoryHandle->opaqueData = yahooIndex->categories[index];

   TA_TRACE_RETURN( TA_SUCCESS );
}

static TA_RetCode initSymbolHandle( TA_DataSourceHandle *handle,
                                    TA_CategoryHandle   *categoryHandle,
                                    TA_SymbolHandle     *symbolHandle,
                                    unsigned int index )
{
   TA_PROLOG
   TA_YahooCategory *category;

   TA_TRACE_BEGIN( TA_YAHOO_GetFirstSymbolHandle );

   if( (handle == NULL) || (categoryHandle == NULL) || (symbolHandle == NULL) )
   {
      TA_TRACE_RETURN( TA_BAD_PARAM );
   }

   category = (TA_YahooCategory *)categoryHandle->opaqueData;

   if( index >= category->nbSymbol )
      return TA_END_OF_INDEX;

   /* Set the symbolHandle. */
   symbolHandle->string = category->symbols[index];
   symbolHandle->opaqueData = NULL;

   TA_TRACE_RETURN( TA_SUCCESS );
}
