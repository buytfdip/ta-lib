
/* Provides common mathematical or analysis functions.
 *
 * These functions are all PRIVATE to ta-lib and should
 * never be called directly by the user of the TA-LIB.
 */

#ifndef TA_UTILITY_H
#define TA_UTILITY_H

#ifndef TA_FUNC_H
   #include "ta_func.h"
#endif

/* Calculate a Simple Moving Average.
 * This is an internal version, parameter are assumed validated.
 * (startIdx and endIdx cannot be -1).
 */
TA_RetCode TA_INT_SMA( TA_Integer    startIdx,
                       TA_Integer    endIdx,
                       const TA_Real *inReal_0,
                       TA_Integer    optInTimePeriod_0, /* From 1 to 200 */
                       TA_Integer   *outBegIdx,
                       TA_Integer   *outNbElement,
                       TA_Real      *outReal_0 );

/* Calculate a Weighted Moving Average.
 * This is an internal version, parameter are assumed validated.
 * (startIdx and endIdx cannot be -1).
 */
TA_RetCode TA_INT_WMA( TA_Integer    startIdx,
                       TA_Integer    endIdx,
                       const TA_Real *inReal_0,
                       TA_Integer    optInTimePeriod_0, /* From 1 to 200 */
                       TA_Integer   *outBegIdx,
                       TA_Integer   *outNbElement,
                       TA_Real      *outReal_0 );

/* Calculate an Exponential Moving Average.
 * This is an internal version, parameter are assumed validated.
 * (startIdx and endIdx cannot be -1).
 */
TA_RetCode TA_INT_EMA( TA_Integer    startIdx,
                       TA_Integer    endIdx,
                       const TA_Real *inReal_0,
                       TA_Integer    optInTimePeriod_0, /* From 1 to 200 */
                       TA_Real       optInK_1,
                       TA_Integer    optInCompatibility_1,
                       TA_Integer   *outBegIdx,
                       TA_Integer   *outNbElement,
                       TA_Real      *outReal_0 );

/* Calculate a MACD
 * This is an internal version, parameter are assumed validated.
 * (startIdx and endIdx cannot be -1).
 */
TA_RetCode TA_INT_MACD( TA_Libc      *libHandle,
                        TA_Integer    startIdx,
                        TA_Integer    endIdx,
                        const TA_Real inReal_0[],
                        TA_Integer    optInFastPeriod_0, /* From 1 to 200, 0 is fix 12 */
                        TA_Integer    optInSlowPeriod_1, /* From 1 to 200, 0 is fix 26 */
                        TA_Integer    optInSignalPeriod_2, /* From 1 to 200 */
                        TA_Integer    optInCompatibility_3,
                        TA_Integer   *outBegIdx,
                        TA_Integer   *outNbElement,
                        TA_Real       outRealMACD_0[],
                        TA_Real       outRealMACDSignal_1[],
                        TA_Real       outRealMACDHist_2[] );

/* Convert a period into the equivalent k:
 *
 *    k = 2 / (period + 1)
 *
 * Useful to calculate the 'k' for TA_INT_EMA().
 */
#define PER_TO_K( per ) ((TA_Real)2.0 / ((TA_Real)per + 1.0))

/* Internal Price Oscillator function.
 *
 * A buffer must be provided for intermediate processing
 * 'tempBuffer' must be of at least (endIdx-startIdx+1)
 */
TA_RetCode TA_INT_PO( TA_Libc      *libHandle,
                      TA_Integer    startIdx,
                      TA_Integer    endIdx,
                      const TA_Real *inReal_0,
                      TA_Integer    optInFastPeriod_0, /* From 1 to 200 */
                      TA_Integer    optInSlowPeriod_1, /* From 1 to 200 */
                      TA_Integer    optInMethod_2,
                      TA_Integer    optInCompatibility_3,
                      TA_Integer   *outBegIdx,
                      TA_Integer   *outNbElement,
                      TA_Real      *outReal_0,
                      TA_Real      *tempBuffer,
                      unsigned int  doPercentageOutput );

/* Internal variance function. */
TA_RetCode TA_INT_VAR( TA_Integer    startIdx,
                       TA_Integer    endIdx,
                       const TA_Real *inReal_0,
                       TA_Integer    optInTimePeriod_0,                       
                       TA_Integer   *outBegIdx,
                       TA_Integer   *outNbElement,
                       TA_Real      *outReal_0 );

/* A particular standard deviation who has the particularity
 * to work with other moving average than the simple moving average.
 *
 * To offer the maximum of flexibility, the caller must pre-calculate the
 * moving average of inReal and pass it as a parameter.
 */
void TA_INT_stddev_using_precalc_ma( const TA_Real *inReal,
                                     const TA_Real *inMovAvg,
                                     TA_Integer inMovAvgBegIdx,                                    
                                     TA_Integer inMovAvgNbElement,
                                     TA_Integer timePeriod,
                                     TA_Real *output );

extern unsigned int TA_UnstablePeriodTable[TA_FUNC_UNST_ALL];

#endif
