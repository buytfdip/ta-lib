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
 *  AC       Angelo Ciceri
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  010705 AC   Creation           
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #using <mscorlib.dll>
/* Generated */    #include "Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */    #include "ta_trace.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::CDLKICKING_Lookback( void )
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_CDLKICKING_Lookback( void )
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
    return max( TA_CANDLEAVGPERIOD(TA_ShadowVeryShort), TA_CANDLEAVGPERIOD(TA_BodyLong)
            ) + 1;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CDLKICKING - Kicking
 * 
 * Input  = Open, High, Low, Close
 * Output = int
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ __value enum Core::TA_RetCode Core::CDLKICKING( int    startIdx,
/* Generated */                                                 int    endIdx,
/* Generated */                                                 double       inOpen __gc [],
/* Generated */                                                 double       inHigh __gc [],
/* Generated */                                                 double       inLow __gc [],
/* Generated */                                                 double       inClose __gc [],
/* Generated */                                                 [OutAttribute]Int32 *outBegIdx,
/* Generated */                                                 [OutAttribute]Int32 *outNbElement,
/* Generated */                                                 int           outInteger __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_CDLKICKING( int    startIdx,
/* Generated */                           int    endIdx,
/* Generated */                           const double inOpen[],
/* Generated */                           const double inHigh[],
/* Generated */                           const double inLow[],
/* Generated */                           const double inClose[],
/* Generated */                           int          *outBegIdx,
/* Generated */                           int          *outNbElement,
/* Generated */                           int           outInteger[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
    double ShadowVeryShortPeriodTotal[2], BodyLongPeriodTotal[2];
    int i, outIdx, totIdx, ShadowVeryShortTrailingIdx, BodyLongTrailingIdx, lookbackTotal;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    /* Verify required price component. */
/* Generated */    if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outInteger == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */

   lookbackTotal = TA_CDLKICKING_Lookback();

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   /* Do the calculation using tight loops. */
   /* Add-up the initial period, except for the last value. */
   ShadowVeryShortPeriodTotal[1] = 0;
   ShadowVeryShortPeriodTotal[0] = 0;
   ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_ShadowVeryShort);
   BodyLongPeriodTotal[1] = 0;
   BodyLongPeriodTotal[0] = 0;
   BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyLong);

   i = ShadowVeryShortTrailingIdx;
   while( i < startIdx ) {
        ShadowVeryShortPeriodTotal[1] += TA_CANDLERANGE( TA_ShadowVeryShort, i-1 );
        ShadowVeryShortPeriodTotal[0] += TA_CANDLERANGE( TA_ShadowVeryShort, i );
        i++;
   }
   i = BodyLongTrailingIdx;
   while( i < startIdx ) {
        BodyLongPeriodTotal[1] += TA_CANDLERANGE( TA_BodyLong, i-1 );
        BodyLongPeriodTotal[0] += TA_CANDLERANGE( TA_BodyLong, i );
        i++;
   }
   i = startIdx;

   /* Proceed with the calculation for the requested range.
    * Must have:
    * - first candle: marubozu
    * - second candle: opposite color marubozu
    * - gap between the two candles: upside gap if black then white, downside gap if white then black
    * The meaning of "long body" and "very short shadow" is specified with TA_SetCandleSettings
    * outInteger is positive (1 to 100) when bullish or negative (-1 to -100) when bearish
    */
   outIdx = 0;
   do
   {
        if( TA_CANDLECOLOR(i-1) == -TA_CANDLECOLOR(i) &&                                        // opposite candles
            // 1st marubozu
            TA_REALBODY(i-1) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[1], i-1 ) &&
            TA_UPPERSHADOW(i-1) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&
            TA_LOWERSHADOW(i-1) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&
            // 2nd marubozu
            TA_REALBODY(i) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[0], i ) &&
            TA_UPPERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&
            TA_LOWERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&
            // gap
            ( 
              ( TA_CANDLECOLOR(i-1) == -1 && TA_CANDLEGAPUP(i,i-1) )
              ||
              ( TA_CANDLECOLOR(i-1) == 1 && TA_CANDLEGAPDOWN(i,i-1) )
            )
          )
            outInteger[outIdx++] = TA_CANDLECOLOR(i) * 100;
        else
            outInteger[outIdx++] = 0;
        /* add the current range and subtract the first range: this is done after the pattern recognition 
         * when avgPeriod is not 0, that means "compare with the previous candles" (it excludes the current candle)
         */
        for (totIdx = 1; totIdx >= 0; --totIdx) {
            BodyLongPeriodTotal[totIdx] += TA_CANDLERANGE( TA_BodyLong, i-totIdx ) 
                                         - TA_CANDLERANGE( TA_BodyLong, BodyLongTrailingIdx-totIdx );
            ShadowVeryShortPeriodTotal[totIdx] += TA_CANDLERANGE( TA_ShadowVeryShort, i-totIdx ) 
                                                - TA_CANDLERANGE( TA_ShadowVeryShort, ShadowVeryShortTrailingIdx-totIdx );
        }
        i++;
        ShadowVeryShortTrailingIdx++;
        BodyLongTrailingIdx++;
   } while( i <= endIdx );

   /* All done. Indicate the output limits and return. */
   *outNbElement = outIdx;
   *outBegIdx    = startIdx;

   return TA_SUCCESS;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ __value enum Core::TA_RetCode Core::CDLKICKING( int    startIdx,
/* Generated */                                                 int    endIdx,
/* Generated */                                                 float        inOpen __gc [],
/* Generated */                                                 float        inHigh __gc [],
/* Generated */                                                 float        inLow __gc [],
/* Generated */                                                 float        inClose __gc [],
/* Generated */                                                 [OutAttribute]Int32 *outBegIdx,
/* Generated */                                                 [OutAttribute]Int32 *outNbElement,
/* Generated */                                                 int           outInteger __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CDLKICKING( int    startIdx,
/* Generated */                             int    endIdx,
/* Generated */                             const float  inOpen[],
/* Generated */                             const float  inHigh[],
/* Generated */                             const float  inLow[],
/* Generated */                             const float  inClose[],
/* Generated */                             int          *outBegIdx,
/* Generated */                             int          *outNbElement,
/* Generated */                             int           outInteger[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     double ShadowVeryShortPeriodTotal[2], BodyLongPeriodTotal[2];
/* Generated */     int i, outIdx, totIdx, ShadowVeryShortTrailingIdx, BodyLongTrailingIdx, lookbackTotal;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outInteger == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    lookbackTotal = TA_CDLKICKING_Lookback();
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }
/* Generated */    ShadowVeryShortPeriodTotal[1] = 0;
/* Generated */    ShadowVeryShortPeriodTotal[0] = 0;
/* Generated */    ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_ShadowVeryShort);
/* Generated */    BodyLongPeriodTotal[1] = 0;
/* Generated */    BodyLongPeriodTotal[0] = 0;
/* Generated */    BodyLongTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyLong);
/* Generated */    i = ShadowVeryShortTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         ShadowVeryShortPeriodTotal[1] += TA_CANDLERANGE( TA_ShadowVeryShort, i-1 );
/* Generated */         ShadowVeryShortPeriodTotal[0] += TA_CANDLERANGE( TA_ShadowVeryShort, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = BodyLongTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         BodyLongPeriodTotal[1] += TA_CANDLERANGE( TA_BodyLong, i-1 );
/* Generated */         BodyLongPeriodTotal[0] += TA_CANDLERANGE( TA_BodyLong, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = startIdx;
/* Generated */    outIdx = 0;
/* Generated */    do
/* Generated */    {
/* Generated */         if( TA_CANDLECOLOR(i-1) == -TA_CANDLECOLOR(i) &&                                        // opposite candles
/* Generated */             // 1st marubozu
/* Generated */             TA_REALBODY(i-1) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[1], i-1 ) &&
/* Generated */             TA_UPPERSHADOW(i-1) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&
/* Generated */             TA_LOWERSHADOW(i-1) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[1], i-1 ) &&
/* Generated */             // 2nd marubozu
/* Generated */             TA_REALBODY(i) > TA_CANDLEAVERAGE( TA_BodyLong, BodyLongPeriodTotal[0], i ) &&
/* Generated */             TA_UPPERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&
/* Generated */             TA_LOWERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal[0], i ) &&
/* Generated */             // gap
/* Generated */             ( 
/* Generated */               ( TA_CANDLECOLOR(i-1) == -1 && TA_CANDLEGAPUP(i,i-1) )
/* Generated */               ||
/* Generated */               ( TA_CANDLECOLOR(i-1) == 1 && TA_CANDLEGAPDOWN(i,i-1) )
/* Generated */             )
/* Generated */           )
/* Generated */             outInteger[outIdx++] = TA_CANDLECOLOR(i) * 100;
/* Generated */         else
/* Generated */             outInteger[outIdx++] = 0;
/* Generated */         for (totIdx = 1; totIdx >= 0; --totIdx) {
/* Generated */             BodyLongPeriodTotal[totIdx] += TA_CANDLERANGE( TA_BodyLong, i-totIdx ) 
/* Generated */                                          - TA_CANDLERANGE( TA_BodyLong, BodyLongTrailingIdx-totIdx );
/* Generated */             ShadowVeryShortPeriodTotal[totIdx] += TA_CANDLERANGE( TA_ShadowVeryShort, i-totIdx ) 
/* Generated */                                                 - TA_CANDLERANGE( TA_ShadowVeryShort, ShadowVeryShortTrailingIdx-totIdx );
/* Generated */         }
/* Generated */         i++;
/* Generated */         ShadowVeryShortTrailingIdx++;
/* Generated */         BodyLongTrailingIdx++;
/* Generated */    } while( i <= endIdx );
/* Generated */    *outNbElement = outIdx;
/* Generated */    *outBegIdx    = startIdx;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

