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
 *  112400 MF   Template creation.
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
/* Generated */ int Core::ATR_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_ATR_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* The ATR lookback is the sum of:
    *    1 + (optInTimePeriod - 1)
    *
    * Where 1 is for the True Range, and
    * (optInTimePeriod-1) is for the simple
    * moving average.
    */
   return optInTimePeriod + TA_Globals->unstablePeriod[TA_FUNC_UNST_ATR];
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_ATR - Average True Range
 * 
 * Input  = High, Low, Close
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 1 to 100000)
 *    Number of period
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ __value enum Core::TA_RetCode Core::ATR( int    startIdx,
/* Generated */                                          int    endIdx,
/* Generated */                                          double       inHigh __gc [],
/* Generated */                                          double       inLow __gc [],
/* Generated */                                          double       inClose __gc [],
/* Generated */                                          int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                          [OutAttribute]Int32 *outBegIdx,
/* Generated */                                          [OutAttribute]Int32 *outNbElement,
/* Generated */                                          double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_ATR( int    startIdx,
/* Generated */                    int    endIdx,
/* Generated */                    const double inHigh[],
/* Generated */                    const double inLow[],
/* Generated */                    const double inClose[],
/* Generated */                    int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                    int          *outBegIdx,
/* Generated */                    int          *outNbElement,
/* Generated */                    double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   TA_RetCode retCode;
   int outIdx, today, lookbackTotal;
   int outBegIdxTmp, outNbElementTmp, nbATR;
   int outBegIdx_MA, outNbElement_MA;
   double prevATR;
   ARRAY_REF( tempBuffer );

   #if defined( _MANAGED )
      double prevATRTemp __gc [] = new double __gc [1];
   #else
      double prevATRTemp [1];
   #endif

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
/* Generated */    if(!inHigh||!inLow||!inClose)
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 14;
/* Generated */    else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outReal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Average True Range is the greatest of the following: 
    *
    *  val1 = distance from today's high to today's low.
    *  val2 = distance from yesterday's close to today's high.
    *  val3 = distance from yesterday's close to today's low.   
    *
    * These value are averaged for the specified period using
    * Wilder method. This method have an unstable period comparable
    * to and Exponential Moving Average (EMA).
    */
   *outBegIdx    = 0;
   *outNbElement = 0;

   /* Adjust startIdx to account for the lookback period. */
   lookbackTotal = TA_ATR_Lookback( optInTimePeriod );

   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
      return TA_SUCCESS;

   /* Trap the case where no smoothing is needed. */
   if( optInTimePeriod <= 1 )
   {
      /* No smoothing needed. Just do a TRANGE. */
      return TA_PREFIX(TRANGE)( startIdx, endIdx,
                                inHigh, inLow, inClose,
                                outBegIdx, outNbElement, outReal );
   }

   /* Allocate an intermediate buffer for TRANGE. */
   ARRAY_ALLOC(tempBuffer, lookbackTotal+(endIdx-startIdx)+1 );

   /* Do TRANGE in the intermediate buffer. */
   retCode = TA_PREFIX(TRANGE)( (startIdx-lookbackTotal+1), endIdx,
                                inHigh, inLow, inClose,
                                &outBegIdxTmp, &outNbElementTmp, tempBuffer );

   if( retCode != TA_SUCCESS )
   {
      ARRAY_FREE( tempBuffer );
      return retCode;
   }

   /* First value of the ATR is a simple Average of
    * the TRANGE output for the specified period.
    */
   retCode = TA_INT_SMA( optInTimePeriod-1,
                         optInTimePeriod-1,
                         tempBuffer, optInTimePeriod,
                         &outBegIdx_MA, &outNbElement_MA, prevATRTemp );

   if( retCode != TA_SUCCESS )
   {
      ARRAY_FREE( tempBuffer );
      return retCode;    
   }
   prevATR = prevATRTemp[0];

   /* Subsequent value are smoothed using the
    * previous ATR value (Wilder's approach).
    *  1) Multiply the previous ATR by 'period-1'. 
    *  2) Add today TR value. 
    *  3) Divide by 'period'.
    */
   today = optInTimePeriod;
   outIdx = TA_Globals->unstablePeriod[TA_FUNC_UNST_ATR];
   /* Skip the unstable period. */
   while( outIdx != 0 )
   {
      prevATR *= optInTimePeriod - 1;
      prevATR += tempBuffer[today++];
      prevATR /= optInTimePeriod;
      outIdx--;
   }

   /* Now start to write the final ATR in the caller 
    * provided outReal.
    */
   outIdx = 1;
   outReal[0] = prevATR;

   /* Now do the number of requested ATR. */
   nbATR = (endIdx - startIdx)+1;

   while( --nbATR != 0 )
   {
      prevATR *= optInTimePeriod - 1;
      prevATR += tempBuffer[today++];
      prevATR /= optInTimePeriod;
      outReal[outIdx++] = prevATR;
   }

   *outBegIdx    = startIdx;
   *outNbElement = outIdx;
   
   ARRAY_FREE( tempBuffer );
    
   return retCode;
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
/* Generated */ __value enum Core::TA_RetCode Core::ATR( int    startIdx,
/* Generated */                                          int    endIdx,
/* Generated */                                          float        inHigh __gc [],
/* Generated */                                          float        inLow __gc [],
/* Generated */                                          float        inClose __gc [],
/* Generated */                                          int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                          [OutAttribute]Int32 *outBegIdx,
/* Generated */                                          [OutAttribute]Int32 *outNbElement,
/* Generated */                                          double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_ATR( int    startIdx,
/* Generated */                      int    endIdx,
/* Generated */                      const float  inHigh[],
/* Generated */                      const float  inLow[],
/* Generated */                      const float  inClose[],
/* Generated */                      int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                      int          *outBegIdx,
/* Generated */                      int          *outNbElement,
/* Generated */                      double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    TA_RetCode retCode;
/* Generated */    int outIdx, today, lookbackTotal;
/* Generated */    int outBegIdxTmp, outNbElementTmp, nbATR;
/* Generated */    int outBegIdx_MA, outNbElement_MA;
/* Generated */    double prevATR;
/* Generated */    ARRAY_REF( tempBuffer );
/* Generated */    #if defined( _MANAGED )
/* Generated */       double prevATRTemp __gc [] = new double __gc [1];
/* Generated */    #else
/* Generated */       double prevATRTemp [1];
/* Generated */    #endif
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if(!inHigh||!inLow||!inClose)
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInTimePeriod = 14;
/* Generated */     else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outReal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    *outBegIdx    = 0;
/* Generated */    *outNbElement = 0;
/* Generated */    lookbackTotal = TA_ATR_Lookback( optInTimePeriod );
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */       return TA_SUCCESS;
/* Generated */    if( optInTimePeriod <= 1 )
/* Generated */    {
/* Generated */       return TA_PREFIX(TRANGE)( startIdx, endIdx,
/* Generated */                                 inHigh, inLow, inClose,
/* Generated */                                 outBegIdx, outNbElement, outReal );
/* Generated */    }
/* Generated */    ARRAY_ALLOC(tempBuffer, lookbackTotal+(endIdx-startIdx)+1 );
/* Generated */    retCode = TA_PREFIX(TRANGE)( (startIdx-lookbackTotal+1), endIdx,
/* Generated */                                 inHigh, inLow, inClose,
/* Generated */                                 &outBegIdxTmp, &outNbElementTmp, tempBuffer );
/* Generated */    if( retCode != TA_SUCCESS )
/* Generated */    {
/* Generated */       ARRAY_FREE( tempBuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    retCode = TA_INT_SMA( optInTimePeriod-1,
/* Generated */                          optInTimePeriod-1,
/* Generated */                          tempBuffer, optInTimePeriod,
/* Generated */                          &outBegIdx_MA, &outNbElement_MA, prevATRTemp );
/* Generated */    if( retCode != TA_SUCCESS )
/* Generated */    {
/* Generated */       ARRAY_FREE( tempBuffer );
/* Generated */       return retCode;    
/* Generated */    }
/* Generated */    prevATR = prevATRTemp[0];
/* Generated */    today = optInTimePeriod;
/* Generated */    outIdx = TA_Globals->unstablePeriod[TA_FUNC_UNST_ATR];
/* Generated */    while( outIdx != 0 )
/* Generated */    {
/* Generated */       prevATR *= optInTimePeriod - 1;
/* Generated */       prevATR += tempBuffer[today++];
/* Generated */       prevATR /= optInTimePeriod;
/* Generated */       outIdx--;
/* Generated */    }
/* Generated */    outIdx = 1;
/* Generated */    outReal[0] = prevATR;
/* Generated */    nbATR = (endIdx - startIdx)+1;
/* Generated */    while( --nbATR != 0 )
/* Generated */    {
/* Generated */       prevATR *= optInTimePeriod - 1;
/* Generated */       prevATR += tempBuffer[today++];
/* Generated */       prevATR /= optInTimePeriod;
/* Generated */       outReal[outIdx++] = prevATR;
/* Generated */    }
/* Generated */    *outBegIdx    = startIdx;
/* Generated */    *outNbElement = outIdx;
/* Generated */    ARRAY_FREE( tempBuffer );
/* Generated */    return retCode;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
