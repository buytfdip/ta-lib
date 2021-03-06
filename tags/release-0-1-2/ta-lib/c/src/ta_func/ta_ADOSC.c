/* TA-LIB Copyright (c) 1999-2003, Mario Fortier
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
 *  120802 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
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
/* Generated */ int Core::ADOSC_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSlowPeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_ADOSC_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                      int           optInSlowPeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* Use the slowest EMA period to evaluate the total lookback. */
   int slowestPeriod;

   if( optInFastPeriod < optInSlowPeriod )
      slowestPeriod = optInSlowPeriod;
   else
      slowestPeriod = optInFastPeriod;

   /* Adjust startIdx to account for the lookback period. */
   return TA_EMA_Lookback( slowestPeriod );
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_ADOSC - Chaikin A/D Oscillator
 * 
 * Input  = High, Low, Close, Volume
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInFastPeriod:(From 2 to 100000)
 *    Number of period for the fast MA
 * 
 * optInSlowPeriod:(From 2 to 100000)
 *    Number of period for the slow MA
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::ADOSC( int    startIdx,
/* Generated */                                    int    endIdx,
/* Generated */                                    double       inHigh __gc [],
/* Generated */                                    double       inLow __gc [],
/* Generated */                                    double       inClose __gc [],
/* Generated */                                    int          inVolume __gc [],
/* Generated */                                    int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                    int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                    [OutAttribute]Int32 *outBegIdx,
/* Generated */                                    [OutAttribute]Int32 *outNbElement,
/* Generated */                                    double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_ADOSC( int    startIdx,
/* Generated */                      int    endIdx,
/* Generated */                      const double inHigh[],
/* Generated */                      const double inLow[],
/* Generated */                      const double inClose[],
/* Generated */                      const int    inVolume[],
/* Generated */                      int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                      int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                      int          *outBegIdx,
/* Generated */                      int          *outNbElement,
/* Generated */                      double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */

   int today, outIdx, lookbackTotal;
   int slowestPeriod;
   double high, low, close, tmp;

   double slowEMA, slowk, one_minus_slowk;
   double fastEMA, fastk, one_minus_fastk;
   double ad;

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
/* Generated */    if(!inHigh||!inLow||!inClose||!inVolume)
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInFastPeriod. */
/* Generated */    if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInFastPeriod = 3;
/* Generated */    else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInSlowPeriod. */
/* Generated */    if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSlowPeriod = 10;
/* Generated */    else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outReal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Implementation Note:
    *     The fastEMA varaible is not neceseraly the
    *     fastest EMA.
    *     In the same way, slowEMA is not neceseraly the
    *     slowest EMA.
    *
    *     The ADOSC is always the (fastEMA - slowEMA) regardless
    *     of the period specified. In other word:
    * 
    *     ADOSC(3,10) = EMA(3,AD) - EMA(10,AD)
    *
    *        while
    *
    *     ADOSC(10,3) = EMA(10,AD)- EMA(3,AD)
    *
    *     In the first case the EMA(3) is truly a faster EMA,
    *     while in the second case, the EMA(10) is still call
    *     fastEMA in the algorithm, even if it is in fact slower.
    *
    *     This gives more flexibility to the user if they want to
    *     experiment with unusual parameter settings.
    */

   /* Identify the slowest period. 
    * This infomration is used soleley to bootstrap
    * the algorithm (skip the lookback period).
    */
   if( optInFastPeriod < optInSlowPeriod )
      slowestPeriod = optInSlowPeriod;
   else
      slowestPeriod = optInFastPeriod;

   /* Adjust startIdx to account for the lookback period. */
   lookbackTotal = TA_EMA_Lookback( slowestPeriod );
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   *outBegIdx = startIdx;
   today  = startIdx-lookbackTotal;

   /* The following variables and macro are used to
    * calculate the "ad".
    */
   ad = 0.0;
   #define CALCULATE_AD \
   { \
      high  = inHigh[today]; \
      low   = inLow[today]; \
      tmp   = high-low; \
      close = inClose[today]; \
      if( tmp > 0.0 ) \
         ad += (((close-low)-(high-close))/tmp)*((double)inVolume[today]); \
      today++; \
   }

   /* Constants for EMA */
   fastk = PER_TO_K( optInFastPeriod );
   one_minus_fastk = 1.0 - fastk;

   slowk = PER_TO_K( optInSlowPeriod );
   one_minus_slowk = 1.0 - slowk;

   /* Initialize the two EMA
    *
    * Use the same range of initialization inputs for
    * both EMA and simply seed with the first A/D value.
    *
    * Note: Metastock do the same.
    */   
   CALCULATE_AD;
   fastEMA = ad;
   slowEMA = ad;

   /* Initialize the EMA and skip the unstable period. */
   while( today < startIdx )
   {
      CALCULATE_AD;
      fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
      slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);
   }     
      
   /* Perform the calculation for the requested range */
   outIdx = 0;
   while( today <= endIdx )
   {
      CALCULATE_AD;
      fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
      slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);

      outReal[outIdx++] = fastEMA - slowEMA;
   }
   *outNbElement = outIdx;

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
/* Generated */ enum Core::TA_RetCode Core::ADOSC( int    startIdx,
/* Generated */                                    int    endIdx,
/* Generated */                                    float        inHigh __gc [],
/* Generated */                                    float        inLow __gc [],
/* Generated */                                    float        inClose __gc [],
/* Generated */                                    int          inVolume __gc [],
/* Generated */                                    int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                    int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                    [OutAttribute]Int32 *outBegIdx,
/* Generated */                                    [OutAttribute]Int32 *outNbElement,
/* Generated */                                    double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_ADOSC( int    startIdx,
/* Generated */                        int    endIdx,
/* Generated */                        const float  inHigh[],
/* Generated */                        const float  inLow[],
/* Generated */                        const float  inClose[],
/* Generated */                        const int    inVolume[],
/* Generated */                        int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                        int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                        int          *outBegIdx,
/* Generated */                        int          *outNbElement,
/* Generated */                        double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    int today, outIdx, lookbackTotal;
/* Generated */    int slowestPeriod;
/* Generated */    double high, low, close, tmp;
/* Generated */    double slowEMA, slowk, one_minus_slowk;
/* Generated */    double fastEMA, fastk, one_minus_fastk;
/* Generated */    double ad;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if(!inHigh||!inLow||!inClose||!inVolume)
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInFastPeriod = 3;
/* Generated */     else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSlowPeriod = 10;
/* Generated */     else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outReal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    if( optInFastPeriod < optInSlowPeriod )
/* Generated */       slowestPeriod = optInSlowPeriod;
/* Generated */    else
/* Generated */       slowestPeriod = optInFastPeriod;
/* Generated */    lookbackTotal = TA_EMA_Lookback( slowestPeriod );
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }
/* Generated */    *outBegIdx = startIdx;
/* Generated */    today  = startIdx-lookbackTotal;
/* Generated */    ad = 0.0;
/* Generated */    #define CALCULATE_AD \
/* Generated */    { \
/* Generated */       high  = inHigh[today]; \
/* Generated */       low   = inLow[today]; \
/* Generated */       tmp   = high-low; \
/* Generated */       close = inClose[today]; \
/* Generated */       if( tmp > 0.0 ) \
/* Generated */          ad += (((close-low)-(high-close))/tmp)*((double)inVolume[today]); \
/* Generated */       today++; \
/* Generated */    }
/* Generated */    fastk = PER_TO_K( optInFastPeriod );
/* Generated */    one_minus_fastk = 1.0 - fastk;
/* Generated */    slowk = PER_TO_K( optInSlowPeriod );
/* Generated */    one_minus_slowk = 1.0 - slowk;
/* Generated */    CALCULATE_AD;
/* Generated */    fastEMA = ad;
/* Generated */    slowEMA = ad;
/* Generated */    while( today < startIdx )
/* Generated */    {
/* Generated */       CALCULATE_AD;
/* Generated */       fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
/* Generated */       slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);
/* Generated */    }     
/* Generated */    outIdx = 0;
/* Generated */    while( today <= endIdx )
/* Generated */    {
/* Generated */       CALCULATE_AD;
/* Generated */       fastEMA = (fastk*ad)+(one_minus_fastk*fastEMA);
/* Generated */       slowEMA = (slowk*ad)+(one_minus_slowk*slowEMA);
/* Generated */       outReal[outIdx++] = fastEMA - slowEMA;
/* Generated */    }
/* Generated */    *outNbElement = outIdx;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

