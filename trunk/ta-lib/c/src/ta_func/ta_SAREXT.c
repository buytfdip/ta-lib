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
 *  PP       Peter Pudaite
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  120802 MF   Template creation.
 *  150903 PP   Reworked TA_SAR to allow customisation of more SAR params.
 *  210903 MF   Some changes related on first round of tests
 *  230903 PP   Minor bug fixes.
 *
 */

/* SAR_ROUNDING is just for test purpose when cross-referencing that
 * function with example from Wilder's book. Wilder is using two
 * decimal rounding for simplification. TA-Lib does not round.
 */
/* #define SAR_ROUNDING(x) x=round_pos_2(x) */
#define SAR_ROUNDING(x)


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
/* Generated */ int Core::SAREXT_Lookback( double        optInStartValue, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                          double        optInOffsetOnReverse, /* From 0 to TA_REAL_MAX */
/* Generated */                          double        optInAccelerationInitLong, /* From 0 to TA_REAL_MAX */
/* Generated */                          double        optInAccelerationLong, /* From 0 to TA_REAL_MAX */
/* Generated */                          double        optInAccelerationMaxLong, /* From 0 to TA_REAL_MAX */
/* Generated */                          double        optInAccelerationInitShort, /* From 0 to TA_REAL_MAX */
/* Generated */                          double        optInAccelerationShort, /* From 0 to TA_REAL_MAX */
/* Generated */                          double        optInAccelerationMaxShort )  /* From 0 to TA_REAL_MAX */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_SAREXT_Lookback( double        optInStartValue, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                       double        optInOffsetOnReverse, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationInitLong, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationLong, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationMaxLong, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationInitShort, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationShort, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationMaxShort )  /* From 0 to TA_REAL_MAX */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   (void)optInStartValue;
   (void)optInOffsetOnReverse;
   (void)optInAccelerationInitLong;
   (void)optInAccelerationLong;
   (void)optInAccelerationMaxLong;
   (void)optInAccelerationInitShort;
   (void)optInAccelerationShort;
   (void)optInAccelerationMaxShort;

    /* SAR always sacrifices one price bar to establish the
     * initial extreme price.
     */

   return 1;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_SAREXT - Parabolic SAR - Extended
 * 
 * Input  = High, Low
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInStartValue:(From TA_REAL_MIN to TA_REAL_MAX)
 *    Start value and direction. 0 for Auto, >0 for Long, <0 for Short
 * 
 * optInOffsetOnReverse:(From 0 to TA_REAL_MAX)
 *    Percent offset added/removed to initial stop on short/long reversal
 * 
 * optInAccelerationInitLong:(From 0 to TA_REAL_MAX)
 *    Acceleration Factor initial value for the Long direction
 * 
 * optInAccelerationLong:(From 0 to TA_REAL_MAX)
 *    Acceleration Factor for the Long direction
 * 
 * optInAccelerationMaxLong:(From 0 to TA_REAL_MAX)
 *    Acceleration Factor maximum value for the Long direction
 * 
 * optInAccelerationInitShort:(From 0 to TA_REAL_MAX)
 *    Acceleration Factor initial value for the Short direction
 * 
 * optInAccelerationShort:(From 0 to TA_REAL_MAX)
 *    Acceleration Factor for the Short direction
 * 
 * optInAccelerationMaxShort:(From 0 to TA_REAL_MAX)
 *    Acceleration Factor maximum value for the Short direction
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::SAREXT( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     double       inHigh __gc [],
/* Generated */                                     double       inLow __gc [],
/* Generated */                                     double        optInStartValue, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                                     double        optInOffsetOnReverse, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationInitLong, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationLong, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationMaxLong, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationInitShort, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationShort, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationMaxShort, /* From 0 to TA_REAL_MAX */
/* Generated */                                     [OutAttribute]Int32 *outBegIdx,
/* Generated */                                     [OutAttribute]Int32 *outNbElement,
/* Generated */                                     double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_SAREXT( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       const double inHigh[],
/* Generated */                       const double inLow[],
/* Generated */                       double        optInStartValue, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                       double        optInOffsetOnReverse, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationInitLong, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationLong, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationMaxLong, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationInitShort, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationShort, /* From 0 to TA_REAL_MAX */
/* Generated */                       double        optInAccelerationMaxShort, /* From 0 to TA_REAL_MAX */
/* Generated */                       int          *outBegIdx,
/* Generated */                       int          *outNbElement,
/* Generated */                       double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */
   TA_RetCode retCode;

   int isLong; /* > 0 indicates long. == 0 indicates short */
   int todayIdx, outIdx;

   int tempInt;

   double newHigh, newLow, prevHigh, prevLow;
   double afLong, afShort, ep, sar;
   #if defined( _MANAGED )
      double ep_temp __gc [] = new double __gc [1];
   #else
      double ep_temp[1];
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
/* Generated */    if(!inHigh||!inLow)
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInStartValue == TA_REAL_DEFAULT )
/* Generated */       optInStartValue = 0.000000e+0;
/* Generated */    else if( (optInStartValue < -3.000000e+37) ||/* Generated */  (optInStartValue > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInOffsetOnReverse == TA_REAL_DEFAULT )
/* Generated */       optInOffsetOnReverse = 0.000000e+0;
/* Generated */    else if( (optInOffsetOnReverse < 0.000000e+0) ||/* Generated */  (optInOffsetOnReverse > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInAccelerationInitLong == TA_REAL_DEFAULT )
/* Generated */       optInAccelerationInitLong = 2.000000e-2;
/* Generated */    else if( (optInAccelerationInitLong < 0.000000e+0) ||/* Generated */  (optInAccelerationInitLong > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInAccelerationLong == TA_REAL_DEFAULT )
/* Generated */       optInAccelerationLong = 2.000000e-2;
/* Generated */    else if( (optInAccelerationLong < 0.000000e+0) ||/* Generated */  (optInAccelerationLong > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInAccelerationMaxLong == TA_REAL_DEFAULT )
/* Generated */       optInAccelerationMaxLong = 2.000000e-1;
/* Generated */    else if( (optInAccelerationMaxLong < 0.000000e+0) ||/* Generated */  (optInAccelerationMaxLong > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInAccelerationInitShort == TA_REAL_DEFAULT )
/* Generated */       optInAccelerationInitShort = 2.000000e-2;
/* Generated */    else if( (optInAccelerationInitShort < 0.000000e+0) ||/* Generated */  (optInAccelerationInitShort > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInAccelerationShort == TA_REAL_DEFAULT )
/* Generated */       optInAccelerationShort = 2.000000e-2;
/* Generated */    else if( (optInAccelerationShort < 0.000000e+0) ||/* Generated */  (optInAccelerationShort > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInAccelerationMaxShort == TA_REAL_DEFAULT )
/* Generated */       optInAccelerationMaxShort = 2.000000e-1;
/* Generated */    else if( (optInAccelerationMaxShort < 0.000000e+0) ||/* Generated */  (optInAccelerationMaxShort > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outReal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* This function is the same as TA_SAR, except that the caller has
    * greater control on the SAR dynamic and initial state.
    *
    * In additon, the TA_SAREXT returns negative values when the position
    * is short. This allow to distinguish when the SAR do actually reverse.
    */

   /* Implementation of the SAR has been a little bit open to interpretation
    * since Wilder (the original author) did not define a precise algorithm
    * on how to bootstrap the algorithm. Take any existing software application
    * and you will see slight variation on how the algorithm was adapted.
    *
    * What is the initial trade direction? Long or short?
    * ===================================================
    * The interpretation of what should be the initial SAR values is
    * open to interpretation, particularly since the caller to the function
    * does not specify the initial direction of the trade.
    *
    * In TA-Lib, the following default logic is used:
    *  - Calculate +DM and -DM between the first and
    *    second bar. The highest directional indication will
    *    indicate the assumed direction of the trade for the second
    *    price bar. 
    *  - In the case of a high between +DM and -DM,
    *    the direction is LONG by default.
    *
    * What is the initial "extreme point" and thus SAR?
    * =================================================
    * The following shows how different people took different approach:
    *  - Metastock use the first price bar high/low depending of
    *    the direction. No SAR is calculated for the first price
    *    bar.
    *  - Tradestation use the closing price of the second bar. No
    *    SAR are calculated for the first price bar.
    *  - Wilder (the original author) use the SIP from the
    *    previous trade (cannot be implement here since the
    *    direction and length of the previous trade is unknonw).
    *  - The Magazine TASC seems to follow Wilder approach which
    *    is not practical here.
    *
    * TA-Lib "consume" the first price bar and use its high/low as the
    * initial SAR of the second price bar. I found that approach to be
    * the closest to Wilders idea of having the first entry day use
    * the previous extreme point, except that here the extreme point is
    * derived solely from the first price bar. I found the same approach
    * to be used by Metastock.
    *
    *
    * Can I force the initial SAR?
    * ============================
    * Yes. Using the optInStartValue_0 parameter:
    *  optInStartValue_0 >  0 : SAR is long at optInStartValue_0.
    *  optInStartValue_0 <  0 : SAR is short at fabs(optInStartValue_0).
    *  
    * And when optInStartValue_0 == 0, the logic is the same as for TA_SAR
    * (See previous two sections).
    */

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    *
    * Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < 1 )
      startIdx = 1;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }   


   /* Check if the acceleration factors are being defined by the user.
    * Make sure the acceleration and maximum are coherent.
    * If not, correct the acceleration.    
    * Default afLong = 0.02
    * Default afShort = 0.02
    */

   afLong = optInAccelerationInitLong;
   afShort = optInAccelerationInitShort;

   if( afLong > optInAccelerationMaxLong )
      afLong = optInAccelerationInitLong = optInAccelerationMaxLong;

   if( optInAccelerationLong > optInAccelerationMaxLong )
      optInAccelerationLong = optInAccelerationMaxLong;

   if( afShort > optInAccelerationMaxShort) 
      afShort = optInAccelerationInitShort = optInAccelerationMaxShort;

   if( optInAccelerationShort > optInAccelerationMaxShort )
      optInAccelerationShort = optInAccelerationMaxShort;
      

   /* Initialise SAR calculations */

   if(optInStartValue == 0) /* Default action */
   {
      /* Identify if the initial direction is long or short.
       * (ep is just used as a temp buffer here, the name
       *  of the parameter is not significant).
       */
      retCode = TA_PREFIX(MINUS_DM)( startIdx-1, startIdx, inHigh, inLow,
                                  1, &tempInt, &tempInt, ep_temp );
      if( ep_temp[0] > 0 )
         isLong = 0;
      else
         isLong = 1;

      if( retCode != TA_SUCCESS )
      {
         *outBegIdx = 0;
         *outNbElement = 0;
         return retCode;
      }
   }
   else if( optInStartValue > 0 ) /* Start Long */
   {
      isLong = 1;
   }
   else /* optInStartValue_0 < 0 => Start Short */
   {
      isLong = 0;
   }

   *outBegIdx = startIdx;
   outIdx = 0;


   /* Write the first SAR. */
   todayIdx = startIdx;

   newHigh = inHigh[todayIdx-1];
   newLow  = inLow[todayIdx-1];

   SAR_ROUNDING(newHigh);
   SAR_ROUNDING(newLow);

   if(optInStartValue == 0) /* Default action */
   {
      if( isLong )
      {
         ep  = inHigh[todayIdx];
         sar = newLow;
      }
      else
      {
         ep  = inLow[todayIdx];
         sar = newHigh;
      }
   }
   else if ( optInStartValue > 0 ) /* Start Long at specified value. */
   {
      ep  = inHigh[todayIdx];
      sar = optInStartValue;
   }
   else /* if optInStartValue < 0 => Start Short at specified value. */
   {
      ep  = inLow[todayIdx];
      sar = fabs(optInStartValue);
   }


   SAR_ROUNDING(sar);

   /* Cheat on the newLow and newHigh for the
    * first iteration.
    */
   newLow  = inLow[todayIdx];
   newHigh = inHigh[todayIdx];

   while( todayIdx <= endIdx )
   {
      prevLow  = newLow;
      prevHigh = newHigh;
      newLow  = inLow[todayIdx];
      newHigh = inHigh[todayIdx];   
      todayIdx++;

      SAR_ROUNDING(newLow);
      SAR_ROUNDING(newHigh);

      if( isLong )
      {  
         /* Switch to short if the low penetrates the SAR value. */
         if( newLow <= sar )
         {
            /* Switch and Overide the SAR with the ep */
            isLong = 0;
            sar = ep;

            /* Make sure the overide SAR is within
             * yesterday's and today's range.
             */
            if( sar < prevHigh )
               sar = prevHigh;            
            if( sar < newHigh )
               sar = newHigh;

            /* Output the overide SAR  */
            if( optInOffsetOnReverse )
               sar += sar * optInOffsetOnReverse; 
            outReal[outIdx++] = -sar;

            /* Adjust afShort and ep */
            afShort = optInAccelerationInitShort;
            ep = newLow;
 
            /* Calculate the new SAR */
            sar = sar + afShort * (ep - sar);
            SAR_ROUNDING( sar );

            /* Make sure the new SAR is within
             * yesterday's and today's range.
             */
            if( sar < prevHigh )
               sar = prevHigh;            
            if( sar < newHigh )
               sar = newHigh;
         }
         else
         {
            /* No switch */

            /* Output the SAR (was calculated in the previous iteration) */
            outReal[outIdx++] = sar;
 
            /* Adjust afLong and ep. */
            if( newHigh > ep )
            {
               ep = newHigh;
               afLong += optInAccelerationLong;
               if( afLong > optInAccelerationMaxLong )
                  afLong = optInAccelerationMaxLong;
            }

            /* Calculate the new SAR */
            sar = sar + afLong * (ep - sar);
            SAR_ROUNDING( sar );

            /* Make sure the new SAR is within
             * yesterday's and today's range.
             */
            if( sar > prevLow )
               sar = prevLow;            
            if( sar > newLow )
               sar = newLow;
         }
      }
      else
      {
         /* Switch to long if the high penetrates the SAR value. */
         if( newHigh >= sar )
         {
            /* Switch and Overide the SAR with the ep */
            isLong = 1;
            sar = ep;

            /* Make sure the overide SAR is within
             * yesterday's and today's range.
             */
            if( sar > prevLow )
               sar = prevLow;            
            if( sar > newLow )
               sar = newLow;

            /* Output the overide SAR  */
            if( optInOffsetOnReverse )
               sar -= sar * optInOffsetOnReverse;
            outReal[outIdx++] = sar;

            /* Adjust afLong and ep */
            afLong = optInAccelerationInitLong;
            ep = newHigh;

            /* Calculate the new SAR */
            sar = sar + afLong * (ep - sar);
            SAR_ROUNDING( sar );

            /* Make sure the new SAR is within
             * yesterday's and today's range.
             */
            if( sar > prevLow )
               sar = prevLow;            
            if( sar > newLow )
               sar = newLow;
         }
         else
         {
            /* No switch */

            /* Output the SAR (was calculated in the previous iteration) */
            outReal[outIdx++] = -sar;

            /* Adjust afShort and ep. */
            if( newLow < ep )
            {
               ep = newLow;
               afShort += optInAccelerationShort;
               if( afShort > optInAccelerationMaxShort )
                  afShort = optInAccelerationMaxShort;
            }

            /* Calculate the new SAR */
            sar = sar + afShort * (ep - sar);
            SAR_ROUNDING( sar );

            /* Make sure the new SAR is within
             * yesterday's and today's range.
             */
            if( sar < prevHigh )
               sar = prevHigh;            
            if( sar < newHigh )
               sar = newHigh;
         }
      }
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
/* Generated */ enum Core::TA_RetCode Core::SAREXT( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     float        inHigh __gc [],
/* Generated */                                     float        inLow __gc [],
/* Generated */                                     double        optInStartValue, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                                     double        optInOffsetOnReverse, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationInitLong, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationLong, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationMaxLong, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationInitShort, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationShort, /* From 0 to TA_REAL_MAX */
/* Generated */                                     double        optInAccelerationMaxShort, /* From 0 to TA_REAL_MAX */
/* Generated */                                     [OutAttribute]Int32 *outBegIdx,
/* Generated */                                     [OutAttribute]Int32 *outNbElement,
/* Generated */                                     double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_SAREXT( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         const float  inHigh[],
/* Generated */                         const float  inLow[],
/* Generated */                         double        optInStartValue, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                         double        optInOffsetOnReverse, /* From 0 to TA_REAL_MAX */
/* Generated */                         double        optInAccelerationInitLong, /* From 0 to TA_REAL_MAX */
/* Generated */                         double        optInAccelerationLong, /* From 0 to TA_REAL_MAX */
/* Generated */                         double        optInAccelerationMaxLong, /* From 0 to TA_REAL_MAX */
/* Generated */                         double        optInAccelerationInitShort, /* From 0 to TA_REAL_MAX */
/* Generated */                         double        optInAccelerationShort, /* From 0 to TA_REAL_MAX */
/* Generated */                         double        optInAccelerationMaxShort, /* From 0 to TA_REAL_MAX */
/* Generated */                         int          *outBegIdx,
/* Generated */                         int          *outNbElement,
/* Generated */                         double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    TA_RetCode retCode;
/* Generated */    int isLong; 
/* Generated */    int todayIdx, outIdx;
/* Generated */    int tempInt;
/* Generated */    double newHigh, newLow, prevHigh, prevLow;
/* Generated */    double afLong, afShort, ep, sar;
/* Generated */    #if defined( _MANAGED )
/* Generated */       double ep_temp __gc [] = new double __gc [1];
/* Generated */    #else
/* Generated */       double ep_temp[1];
/* Generated */    #endif
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if(!inHigh||!inLow)
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInStartValue == TA_REAL_DEFAULT )
/* Generated */        optInStartValue = 0.000000e+0;
/* Generated */     else if( (optInStartValue < -3.000000e+37) ||  (optInStartValue > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInOffsetOnReverse == TA_REAL_DEFAULT )
/* Generated */        optInOffsetOnReverse = 0.000000e+0;
/* Generated */     else if( (optInOffsetOnReverse < 0.000000e+0) ||  (optInOffsetOnReverse > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInAccelerationInitLong == TA_REAL_DEFAULT )
/* Generated */        optInAccelerationInitLong = 2.000000e-2;
/* Generated */     else if( (optInAccelerationInitLong < 0.000000e+0) ||  (optInAccelerationInitLong > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInAccelerationLong == TA_REAL_DEFAULT )
/* Generated */        optInAccelerationLong = 2.000000e-2;
/* Generated */     else if( (optInAccelerationLong < 0.000000e+0) ||  (optInAccelerationLong > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInAccelerationMaxLong == TA_REAL_DEFAULT )
/* Generated */        optInAccelerationMaxLong = 2.000000e-1;
/* Generated */     else if( (optInAccelerationMaxLong < 0.000000e+0) ||  (optInAccelerationMaxLong > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInAccelerationInitShort == TA_REAL_DEFAULT )
/* Generated */        optInAccelerationInitShort = 2.000000e-2;
/* Generated */     else if( (optInAccelerationInitShort < 0.000000e+0) ||  (optInAccelerationInitShort > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInAccelerationShort == TA_REAL_DEFAULT )
/* Generated */        optInAccelerationShort = 2.000000e-2;
/* Generated */     else if( (optInAccelerationShort < 0.000000e+0) ||  (optInAccelerationShort > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInAccelerationMaxShort == TA_REAL_DEFAULT )
/* Generated */        optInAccelerationMaxShort = 2.000000e-1;
/* Generated */     else if( (optInAccelerationMaxShort < 0.000000e+0) ||  (optInAccelerationMaxShort > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outReal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    if( startIdx < 1 )
/* Generated */       startIdx = 1;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }   
/* Generated */    afLong = optInAccelerationInitLong;
/* Generated */    afShort = optInAccelerationInitShort;
/* Generated */    if( afLong > optInAccelerationMaxLong )
/* Generated */       afLong = optInAccelerationInitLong = optInAccelerationMaxLong;
/* Generated */    if( optInAccelerationLong > optInAccelerationMaxLong )
/* Generated */       optInAccelerationLong = optInAccelerationMaxLong;
/* Generated */    if( afShort > optInAccelerationMaxShort) 
/* Generated */       afShort = optInAccelerationInitShort = optInAccelerationMaxShort;
/* Generated */    if( optInAccelerationShort > optInAccelerationMaxShort )
/* Generated */       optInAccelerationShort = optInAccelerationMaxShort;
/* Generated */    if(optInStartValue == 0) 
/* Generated */    {
/* Generated */       retCode = TA_PREFIX(MINUS_DM)( startIdx-1, startIdx, inHigh, inLow,
/* Generated */                                   1, &tempInt, &tempInt, ep_temp );
/* Generated */       if( ep_temp[0] > 0 )
/* Generated */          isLong = 0;
/* Generated */       else
/* Generated */          isLong = 1;
/* Generated */       if( retCode != TA_SUCCESS )
/* Generated */       {
/* Generated */          *outBegIdx = 0;
/* Generated */          *outNbElement = 0;
/* Generated */          return retCode;
/* Generated */       }
/* Generated */    }
/* Generated */    else if( optInStartValue > 0 ) 
/* Generated */    {
/* Generated */       isLong = 1;
/* Generated */    }
/* Generated */    else 
/* Generated */    {
/* Generated */       isLong = 0;
/* Generated */    }
/* Generated */    *outBegIdx = startIdx;
/* Generated */    outIdx = 0;
/* Generated */    todayIdx = startIdx;
/* Generated */    newHigh = inHigh[todayIdx-1];
/* Generated */    newLow  = inLow[todayIdx-1];
/* Generated */    SAR_ROUNDING(newHigh);
/* Generated */    SAR_ROUNDING(newLow);
/* Generated */    if(optInStartValue == 0) 
/* Generated */    {
/* Generated */       if( isLong )
/* Generated */       {
/* Generated */          ep  = inHigh[todayIdx];
/* Generated */          sar = newLow;
/* Generated */       }
/* Generated */       else
/* Generated */       {
/* Generated */          ep  = inLow[todayIdx];
/* Generated */          sar = newHigh;
/* Generated */       }
/* Generated */    }
/* Generated */    else if ( optInStartValue > 0 ) 
/* Generated */    {
/* Generated */       ep  = inHigh[todayIdx];
/* Generated */       sar = optInStartValue;
/* Generated */    }
/* Generated */    else 
/* Generated */    {
/* Generated */       ep  = inLow[todayIdx];
/* Generated */       sar = fabs(optInStartValue);
/* Generated */    }
/* Generated */    SAR_ROUNDING(sar);
/* Generated */    newLow  = inLow[todayIdx];
/* Generated */    newHigh = inHigh[todayIdx];
/* Generated */    while( todayIdx <= endIdx )
/* Generated */    {
/* Generated */       prevLow  = newLow;
/* Generated */       prevHigh = newHigh;
/* Generated */       newLow  = inLow[todayIdx];
/* Generated */       newHigh = inHigh[todayIdx];   
/* Generated */       todayIdx++;
/* Generated */       SAR_ROUNDING(newLow);
/* Generated */       SAR_ROUNDING(newHigh);
/* Generated */       if( isLong )
/* Generated */       {  
/* Generated */          if( newLow <= sar )
/* Generated */          {
/* Generated */             isLong = 0;
/* Generated */             sar = ep;
/* Generated */             if( sar < prevHigh )
/* Generated */                sar = prevHigh;            
/* Generated */             if( sar < newHigh )
/* Generated */                sar = newHigh;
/* Generated */             if( optInOffsetOnReverse )
/* Generated */                sar += sar * optInOffsetOnReverse; 
/* Generated */             outReal[outIdx++] = -sar;
/* Generated */             afShort = optInAccelerationInitShort;
/* Generated */             ep = newLow;
/* Generated */             sar = sar + afShort * (ep - sar);
/* Generated */             SAR_ROUNDING( sar );
/* Generated */             if( sar < prevHigh )
/* Generated */                sar = prevHigh;            
/* Generated */             if( sar < newHigh )
/* Generated */                sar = newHigh;
/* Generated */          }
/* Generated */          else
/* Generated */          {
/* Generated */             outReal[outIdx++] = sar;
/* Generated */             if( newHigh > ep )
/* Generated */             {
/* Generated */                ep = newHigh;
/* Generated */                afLong += optInAccelerationLong;
/* Generated */                if( afLong > optInAccelerationMaxLong )
/* Generated */                   afLong = optInAccelerationMaxLong;
/* Generated */             }
/* Generated */             sar = sar + afLong * (ep - sar);
/* Generated */             SAR_ROUNDING( sar );
/* Generated */             if( sar > prevLow )
/* Generated */                sar = prevLow;            
/* Generated */             if( sar > newLow )
/* Generated */                sar = newLow;
/* Generated */          }
/* Generated */       }
/* Generated */       else
/* Generated */       {
/* Generated */          if( newHigh >= sar )
/* Generated */          {
/* Generated */             isLong = 1;
/* Generated */             sar = ep;
/* Generated */             if( sar > prevLow )
/* Generated */                sar = prevLow;            
/* Generated */             if( sar > newLow )
/* Generated */                sar = newLow;
/* Generated */             if( optInOffsetOnReverse )
/* Generated */                sar -= sar * optInOffsetOnReverse;
/* Generated */             outReal[outIdx++] = sar;
/* Generated */             afLong = optInAccelerationInitLong;
/* Generated */             ep = newHigh;
/* Generated */             sar = sar + afLong * (ep - sar);
/* Generated */             SAR_ROUNDING( sar );
/* Generated */             if( sar > prevLow )
/* Generated */                sar = prevLow;            
/* Generated */             if( sar > newLow )
/* Generated */                sar = newLow;
/* Generated */          }
/* Generated */          else
/* Generated */          {
/* Generated */             outReal[outIdx++] = -sar;
/* Generated */             if( newLow < ep )
/* Generated */             {
/* Generated */                ep = newLow;
/* Generated */                afShort += optInAccelerationShort;
/* Generated */                if( afShort > optInAccelerationMaxShort )
/* Generated */                   afShort = optInAccelerationMaxShort;
/* Generated */             }
/* Generated */             sar = sar + afShort * (ep - sar);
/* Generated */             SAR_ROUNDING( sar );
/* Generated */             if( sar < prevHigh )
/* Generated */                sar = prevHigh;            
/* Generated */             if( sar < newHigh )
/* Generated */                sar = newHigh;
/* Generated */          }
/* Generated */       }
/* Generated */    }
/* Generated */    *outNbElement = outIdx;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/


