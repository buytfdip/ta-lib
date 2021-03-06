#ifndef TA_SQL_MINIDRIVER_H
#define TA_SQL_MINIDRIVER_H

#ifndef TA_DEFS_H
#include "ta_defs.h"
#endif

#ifndef TA_COMMON_H
#include "ta_common.h"
#endif


typedef struct
{
   /* Function for establishing connection
    * Last parameter is the output parameter
    * It is opaque value, the minidriver can initialise it to any value it wants
    */
   TA_RetCode (*openConnection)(const char database[], 
                                const char host[], 
                                const char username[], 
                                const char password[],
                                unsigned int port,
                                void **connection);

   /* Function for running an SQL query
    * sql_query holds a string with the query statement
    * query_result is the output parameter
    * It is opaque value, the minidriver can initialise it to any value it wants
    * This function is multithread-safe, i.e. multiple threads can execute queries
    * in parallel on the same connection
    */
   TA_RetCode (*executeQuery)(void *connection, 
                              const char sql_query[], 
                              void **query_result);
   
   /* Functions for obtaining information about the query result set
    * Last parameter is output
    */
   TA_RetCode (*getNumColumns)(void *query_result, int *num);
   TA_RetCode (*getNumRows)(void *query_result, int *num);

   /* Get the name of the column at the given position (index zero-based)
    * Last parameter is output, string valid as long as query_result is not released
    */
   TA_RetCode (*getColumnName)(void *query_result, int column, const char **name);

   /* Get string value of the field in the given column at the given row
    * The caller assumes that the following columns are char/varchar columns:
    *       TA_SQL_CATEGORY_COLUMN
    *       TA_SQL_SYMBOL_COLUMN
    *       TA_SQL_DATE_COLUMN
    *       TA_SQL_TIME_COLUMN
    * Last parameter is output, string valid as long as no next row accessed 
    * or query_result is not released
    * Rows have to be accessed sequentially; return TA_END_OF_INDEX at the end
    */
   TA_RetCode (*getRowString)(void *query_reslut, int row, int column, const char **value);

   /* Get floating point value of the field in the given column at the given row
    * The caller assumes that the following columns are decimal/numeric columns:
    *       TA_SQL_OPEN_COLUMN
    *       TA_SQL_HIGH_COLUMN
    *       TA_SQL_LOW_COLUMN
    *       TA_SQL_CLOSE_COLUMN
    * Last parameter is output
    * Rows have to be accessed sequentially; return TA_END_OF_INDEX at the end
    */
   TA_RetCode (*getRowReal)(void *query_reslut, int row, int column, TA_Real *value);

   /* Get integer value of the field in the given column at the given row
    * The caller assumes that the following columns are integer columns:
    *       TA_SQL_VOLUME_COLUMN
    *       TA_SQL_OI_COLUMN
    * Last parameter is output
    * Rows have to be accessed sequentially; return TA_END_OF_INDEX at the end
    */
   TA_RetCode (*getRowInteger)(void *query_reslut, int row, int column, TA_Integer *value);
   
   /* Release resources for the given query
    * Called for each query created with executeQuery, if executeQuery returned
    * TA_SUCCESS
    */
   TA_RetCode (*releaseQuery)(void *query_result);

   /* Release resources for the given connection
    * Called for each connection opened with openConnection, if openConnection returned
    * TA_SUCCESS
    */
   TA_RetCode (*closeConnection)(void *connection);

} TA_SQL_Minidriver;


/* Return the minidriver for the corresponding scheme. Will return
 * NULL if the scheme is not recognized.
 */
const TA_SQL_Minidriver *TA_SQL_GetMinidriver( const char scheme[] );

/* Allows to dynamically add a mini-driver. */
TA_RetCode TA_SQL_AddMinidriver( const char scheme[], const TA_SQL_Minidriver * );

#endif
