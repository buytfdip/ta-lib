/* TA-LIB Copyright (c) 1999-2005, Mario Fortier
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
#ifndef TA_DATA_H
#define TA_DATA_H

#include <stdio.h>

#ifndef TA_COMMON_H
    #include "ta_common.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int TA_UDBase;

/* Function to create a new unified database. */
TA_RetCode TA_UDBaseAlloc( TA_UDBase **newUDBase );

/* Function to free all ressource of an unified database. */
TA_RetCode TA_UDBaseFree( TA_UDBase *toBefreed );

#define TA_SOURCELOCATION_MAX_LENGTH  2048  /* Maximum number of character. */
#define TA_SOURCEINFO_MAX_LENGTH      1024  /* Maximum number of character. */
#define TA_CATEGORY_MAX_LENGTH        1024  /* Maximum number of character. */
#define TA_SYMBOL_MAX_LENGTH          1024  /* Maximum number of character. */

/* A category respecting the TA-LIB guideline shall
 * respect the following limit for its 3 components.
 */
#define TA_CAT_COUNTRY_MAX_LENGTH     2  /* Max length for the country id.    */
#define TA_CAT_EXCHANGE_MAX_LENGTH    25 /* Max length for the exchange id.   */
#define TA_CAT_TYPE_MAX_LENGTH        10 /* Max length for the security type. */

/* Default category name. */
#define TA_DEFAULT_CATEGORY          "ZZ.OTHER.OTHER"
#define TA_DEFAULT_CATEGORY_COUNTRY  "ZZ"
#define TA_DEFAULT_CATEGORY_EXCHANGE "OTHER"
#define TA_DEFAULT_CATEGORY_TYPE     "OTHER"

/* The user build the "unified database" by specifying the
 * list of data source by calling TA_AddDataSource().
 * All data source, even when of different data format, are
 * transparently merged.
 *
 * See the API documentation for more info.
 */
typedef enum
{
   /* For a complete explanation on how to use these
    * data sources, see the HTML documentation.
    */
   TA_ASCII_FILE,
   TA_SIMULATOR,
   TA_YAHOO_WEB,
   TA_SQL,
   TA_CSI,
   TA_CSIM,
   TA_YAHOO_ONE_SYMBOL,
   TA_NUM_OF_SOURCE_ID
} TA_SourceId;

/* A group of flags can be specified to describe characteristics
 * of the data source.
 *
 * Some of these flags allow to enable/disable some functionality
 * for a specific data source.
 *
 * TA_AddDataSource will fail with TA_NOT_SUPPORTED if a flag request a
 * functionality not applicable to the data source.
 *
 * TA_REPLACE_ZERO_PRICE_BAR
 * =========================
 *    Some datasource return a price bar with some price to be zero as an
 *    an indication that there was no change in price. This option allows 
 *    to replace these "zero" price with the previous close.
 *    If the zero price are in the initial bars e.g. no previous valid close
 *    are known, these zero price bar will be ignored.
 *    Without this option, a "zero" detected in a price bar will be considered 
 *    an error and a call to TA_HistoryAlloc will fail. 
 *    A volume of zero is valid.
 *
 * TA_DO_NOT_SPLIT_ADJUST
 * ======================
 *    Return data that is not split adjusted.
 *
 * TA_DO_NOT_VALUE_ADJUST
 * ======================
 *    Return data that is not dividend adjusted.
 *
 * TA_SOURCE_USES_END_OF_PERIOD
 * ============================
 *    The datasource uses the convention that quotes periods are timestamed
 *    at the end of the period (by default, datasources set the timestamp
 *    at the beginning of the period). By using this option, a quotes record
 *    stamped by a 'timestamp' is interpreted as covering interval
 *    ['timestamp'-'period','timestamp).  Without this option, it would be
 *    interpreted as covering interval ['timestamp','timestamp'+'period').
 *
 */

typedef int TA_SourceFlag;
#define TA_NO_FLAGS  0
#define TA_REPLACE_ZERO_PRICE_BAR       (1<<0)
#define TA_DO_NOT_SPLIT_ADJUST          (1<<1)
#define TA_DO_NOT_VALUE_ADJUST          (1<<2)
#define TA_SOURCE_USES_END_OF_PERIOD    (1<<4)

typedef struct
{
   /* The whole structure should be first initialize
    * with zero, and only the relevant parameter
    * to your application needs to be set.
    *
    * The safest way is to ALWAYS do something like:
    *    TA_AddDataSourceParam param;
    *    memset( &param, 0, sizeof( TA_AddDataSourceParam ) );
    *    ... set only the parameter you need...
    *    retCode = TA_AddDataSource( udb, &param ); 
    *
    * Initializing the whole structure to zero assure
    * that the actual (or future) unused parameters
    * will not interfere.
    */

   /* Identify the data source. */
   TA_SourceId   id;

   /* Indicates the type of functionality that
    * must be enabled for this data source.
    */
   TA_SourceFlag flags;

   /* Indicates the period requested to be return 
    * for this data source.  Some data sources may
    * ignore this value and extract the period 
    * directly from the data or other parameters.
    */
   TA_Period period;

   /* The usage of the following two parameters are
    * data source dependent. See documentation.
    */
   const char *location;
   const char *info;

   /* For data source requiring authentication. */
   const char *username;
   const char *password;

   /* The category can be specified in two way.
    *
    * By setting "category" or by setting
    * individual category component following
    * the TA-Lib guideline.
    * Example:
    *    param.category = "My Category";
    *
    *     or
    *
    *    param.country  = "US";
    *    param.exchange = "NASDAQ";
    *    param.type     = "STOCK";
    *
    * Some data source will ignore the category 
    * provided here.
    */
   const char *category;
   const char *country;
   const char *exchange;
   const char *type;

   /* The following is sometimes used for data source
    * that return only one symbol.
    */
   const char *symbol;

   /* The user can optionaly name this data source. */
   const char *sourceName;

} TA_AddDataSourceParam;

TA_RetCode TA_AddDataSource( TA_UDBase *unifiedDatabase,
                             const TA_AddDataSourceParam *param );


/* The following are some pre-defined ASCII file format.
 * These can be used for the 'sourceInfo' for TA_ASCII_FILE format.
 *
 * Note: If these file format are not convenient, you can
 *       specify your own. See documentation.
 */
#define TA_DOHLCV "[Y][M][D][O][H][L][C][V]"
#define TA_DOCHLV "[Y][M][D][O][C][H][L][V]"
#define TA_DOCV   "[Y][M][D][O][C][V]"
#define TA_DCV    "[Y][M][D][C][V]"

/* The following functions are used to obtain the list of
 * category found in an unified database.
 *
 * On success, it becomes the responsibility of the caller to
 * call TA_CategoryTableFree once the 'table' is no longuer needed.
 *
 * Simple example printing out all the category:
 *
 *   TA_StringTable *table;
 *   TA_RetCode retCode;
 *   int i;
 *
 *   retCode = TA_CategoryTableAlloc( udBase, &table );
 *
 *   if( retCode == TA_SUCCESS )
 *   {
 *      for( i=0; i < table->size; i++ )
 *         printf( "%s\n", table->string[i] );
 *
 *      TA_CategoryTableFree( table );
 *   }
 */
TA_RetCode TA_CategoryTableAlloc( TA_UDBase *unifiedDatabase,
                                  TA_StringTable **table );

TA_RetCode TA_CategoryTableFree ( TA_StringTable *table );

/* The following functions are used to obtain the list of
 * symbols provided by the unified database.
 *
 * Note: To obtain the list of symbol not classify under
 *       any particular category, just pass NULL for the
 *       category string.
 *
 * On success, it becomes the responsibility of the caller to
 * call TA_SymbolTableFree once the 'table' is no longuer needed.
 *
 * Example:
 * This code snippet will print out all the supported
 * symbol for the "US.NASDAQ.STOCK" category:
 *
 *   TA_StringTable *table;
 *   TA_RetCode retCode;
 *   int i;
 *
 *   retCode = TA_SymbolTableAlloc( udBase, "US.NASDAQ.STOCK", &table );
 *
 *   if( retCode == TA_SUCCESS )
 *   {
 *      for( i=0; i < table->size; i++ )
 *         printf( "%s\n", table->string[i] );
 *
 *      TA_SymbolTableFree( table );
 *   }
 */
TA_RetCode TA_SymbolTableAlloc( TA_UDBase *unifiedDatabase,
                                const char *category,
                                TA_StringTable **table );

TA_RetCode TA_SymbolTableFree ( TA_StringTable *table );


/* An alternate way to get the index of all symbols is
 * through the use of the TA_ForEachSymbol(). You can
 * setup a function to be called for each symbols currently
 * in the unified database.
 *
 * Example:
 *  This code will print the name and category of all symbols
 *  actually in the unified database.
 *
 *  void printSymbolInfo( TA_UDBase *udBase,
 *                        const char *category,
 *                        const char *symbol,
 *                        void *opaqueData )
 *  {
 *     printf( "Category=%s Symbol=%s\n", category, symbol );
 *  }
 *
 *  void printAll( TA_UDBase *udBase )
 *  {
 *     TA_ForEachSymbol( udBase, printSymbolInfo, NULL );
 *  }
 */
typedef void (*TA_ForEachSymbolFunc)( TA_UDBase *unifiedDatabase,
                                      const char *category,
                                      const char *symbol,
                                      void *opaqueData );

TA_RetCode TA_ForEachSymbol( TA_UDBase *unifiedDatabase,
                             TA_ForEachSymbolFunc functionToCall,
                             void *opaqueData );

/* The following functions allows to access historic data.
 * On success, it becomes the responsibility of the caller to
 * call TA_HistoryFree once the 'history' is no longuer needed.
 *
 * Example:
 *   This code will print out all the available daily close values of
 *   the company "LNUX". It is assume that this symbol is part of
 *   the unified database under the "US.NASDAQ.STOCK" category.
 *
 *   TA_History *history;
 *   TA_HistoryAllocParam param;
 *   TA_RetCode retCode;
 *   int i;
 *
 *   memset( param, 0, sizeof(TA_HistoryAllocParam) );
 *   param.category = "US.NASDAQ.STOCK";
 *   param.symbol   = "LNUX";
 *   param.period   = TA_DAILY;
 *   retCode = TA_HistoryAlloc( udBase, &param, &history );
 *
 *   if( retCode == TA_SUCCESS )
 *   {
 *      for( i=0; i < history->nbBars; i++ )
 *         printf( "Close = %f\n", history->close[i] );
 *
 *      TA_HistoryFree( history );
 *   }
 */
typedef int TA_Field;
#define TA_ALL           0 /* Includes all fields available from database. */
#define TA_OPEN         (1<<0)
#define TA_HIGH         (1<<1)
#define TA_LOW          (1<<2)
#define TA_CLOSE        (1<<3)
#define TA_VOLUME       (1<<4)
#define TA_OPENINTEREST (1<<5)
#define TA_TIMESTAMP    (1<<6)

typedef struct
{
   unsigned int nbBars; /* Nb of element into the following arrays. */
   TA_Period period;    /* Amount of time between each bar. */

   /* The arrays containing data. Unused array are set to NULL. */
   TA_Timestamp *timestamp;
   TA_Real      *open;
   TA_Real      *high;
   TA_Real      *low;
   TA_Real      *close;
   TA_Integer   *volume;
   TA_Integer   *openInterest;

   /* Enumerate all the data source that did contribute. */
   TA_StringTable listOfSource;

   /* Hidden data for internal use by TA-Lib. Do not modify. */
   void *hiddenData;
} TA_History;


/* Flags that can be specified when allocating a TA_History.
 *
 * TA_ALLOW_INCOMPLETE_PRICE_BARS
 * ==============================
 *    When TA-Lib does data consolidation to weekly, monthly, quarterly 
 *    and yearly period, the default behavior is to not return incomplete
 *    starting/ending price bars. This flag disable this filtering.
 *
 *    A starting price bar period is determine completed when one of 
 *    the following is true:
 *     - The end-of-day price bar for the first weekday of the target 
 *       period is available.
 *     - Some data is found for the previous price bar.
 *
 *    A ending price bar period is determine completed when one of 
 *    the following is true:
 *     - The end-of-day price bar for the last weekday of the target 
 *       period is available.
 *     - Some data is found for the next price bar.
 *
 *    Examples:
 *       (1) Requesting historical monthly data will not return the
 *           ending month until at least the last week day is available OR
 *           a price bar in the following month is found in the database.
 *
 *       (2) Requesting historical weekly data will not return the starting
 *           week if it was an incomplete week AND no data is found for 
 *           the previous week in the database.
 *
 *       (3) Requesting historical yearly data will not return the starting
 *           year if the first week day of the year is not available AND 
 *           no data is found for the previous year in the database.
 *
 * TA_USE_TOTAL_VOLUME
 * ===================
 *    This option makes TA-Lib to sum the daily volume when doing price bar
 *    consolidation e.g. when converting daily data to period equal or greater 
 *    to weekly.Without this flag, the default behavior is to return the daily 
 *    average volume.
 *    
 *
 * TA_USE_TOTAL_OPENINTEREST
 * =========================
 *    This option makes TA-Lib to sum the daily open interest when doing price 
 *    bar consolidation e.g. when converting daily data to period equal or  
 *    greater to weekly.Without this flag, the default behavior is to return 
 *    the daily average open interest.
 *
 *
 * TA_DISABLE_PRICE_VALIDATION
 * ===========================
 *    By default TA-Lib fails a TA_HistoryAlloc call when an inconsistency is
 *    found among the high, low, close, open e.g. high<low. This option disable 
 *    these price validations and the caller is left on its own to detect 
 *    erroneous data.
 *
 * TA_USE_END_OF_PERIOD
 * ====================
 *    Retrieve the history data using the end-of-period logic, i.e. set the
 *    timestamps to the end of the period the records are covering rather than 
 *    the beginning of the period.
 *
 */
typedef int TA_HistoryFlag;
#define TA_ALLOW_INCOMPLETE_PRICE_BARS (1<<0)
#define TA_USE_TOTAL_VOLUME            (1<<1)
#define TA_USE_TOTAL_OPENINTEREST      (1<<2)
#define TA_DISABLE_PRICE_VALIDATION    (1<<3)
#define TA_USE_END_OF_PERIOD           (1<<4)

typedef struct
{
   /* The whole structure should be first initialize
    * with zero, and only the relevant parameter
    * to your application needs to be set.
    *
    * The safest way is to ALWAYS do something like:
    *    TA_HistoryAllocParam param;
    *    TA_History *history;
    *    memset( &param, 0, sizeof( TA_HistoryAllocParam ) );
    *    ... set only the parameter you need...
    *    retCode = TA_HistoryAlloc( udb, &param, &history ); 
    *
    * Initializing the whole structure to zero assure
    * that the actual (or future) unused parameters
    * will not interfere.
    */

   /* You can request the data from a particular source. Use the optional 
    * name who was provided with TA_AddDataSource. Leave to zero to 
    * let TA-Lib choose a data source or perform data merging.    
    */    
   const char    *sourceName;

   /* Identify the instrument for which you want historical data. */
   const char    *category;
   const char    *symbol;   

   /* Amount of time for each price bar. TA-Lib will consolidate the
    * data as needed.
    */
   TA_Period      period;

   /* Inclusive starting and ending date. Only the granularity specify
    * by period is consider from these timestamps. Example, requesting
    * with period equal TA_MONTHLY means that only the Year and Month 
    * component of start/end will be used and the day and time will be
    * ignored.
    */
   TA_Timestamp   start;
   TA_Timestamp   end;
   
   /* List of field to allocate. */
   TA_Field       field;

   /* Optional flags. */
   TA_HistoryFlag flags;

   /* Timeout
    *
    * Define the maximum amount of time that 
    * TA-Lib should retry to get the data.
    *
    * Leave to zero for reasonable best-effort
    * retries: 
    *     - up to 1/2 hour for online data.
    *     - No retries for SQL and ASCII files.
    *     etc...
    */
   unsigned int timeout; /* Nb of seconds */

} TA_HistoryAllocParam;

TA_RetCode TA_HistoryAlloc( TA_UDBase *unifiedDatabase,
                            const TA_HistoryAllocParam *param,
                            TA_History **history );

TA_RetCode TA_HistoryFree( TA_History *history );

/* TA_HistoryEqual
 *  Return 1 if two TA_History are equivalent (same content).
 *  Return 0 if a difference is found.
 */
int TA_HistoryEqual( const TA_History *history1, const TA_History *history2 );

/* TA_Report is provided for printing out the
 * contents of the unified database.
 */

/* Flags that can be used for TA_Report. */
typedef int TA_ReportFlag;
#define TA_REPORT_SYMBOL    (1<<0)
#define TA_REPORT_CATEGORY  (1<<1)
#define TA_REPORT_SOURCE    (1<<2)
#define TA_REPORT_TOTAL     (1<<3)

TA_RetCode TA_Report( TA_UDBase *unifiedDatabase,
                      FILE *out,
                      TA_ReportFlag flags );

/* A utility function to fetch a web page and send the raw data
 * to the provided FILE pointer. This ptr could be "stdout" to
 * display on the console.
 *
 * Examples:
 *        TA_WebFetch( "www.yahoo.com", stdout );
 *           or
 *        TA_WebFetch( "http://www.yahoo.com//mt", myFile );
 */
TA_RetCode TA_WebFetch( const char *url, FILE *out );

#ifdef __cplusplus
}
#endif

#endif

