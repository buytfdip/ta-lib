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
 *
 */

#include <math.h>

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */

#ifndef TA_FUNC_H
   #include "ta_func.h"
#endif

#ifndef TA_UTILITY_H
   #include "ta_utility.h"
#endif

int TA_KAMA_Lookback( TA_Integer    optInTimePeriod_0 )  /* From 2 to TA_INTEGER_MAX */

/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   return optInTimePeriod_0 + TA_Globals.unstablePeriod[TA_FUNC_UNST_KAMA];
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_KAMA - Kaufman Adaptive Moving Average
 * 
 * Input  = TA_Real
 * Output = TA_Real
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod_0:(From 2 to TA_INTEGER_MAX)
 *    Number of period
 * 
 * 
 */

TA_RetCode TA_KAMA( TA_Integer    startIdx,
                    TA_Integer    endIdx,
                    const TA_Real inReal_0[],
                    TA_Integer    optInTimePeriod_0, /* From 2 to TA_INTEGER_MAX */
                    TA_Integer   *outBegIdx,
                    TA_Integer   *outNbElement,
                    TA_Real       outReal_0[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */

   const double constMax  = 2.0/(30.0+1.0);
   const double constDiff = 2.0/(2.0+1.0) - constMax;

   TA_Real tempReal, tempReal2;
   TA_Real sumROC1, periodROC, prevKAMA;
   int i, today, outIdx, lookbackTotal;
   int trailingIdx;
   TA_Real trailingValue;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   if( !inReal_0 ) return TA_BAD_PARAM;
   /* min/max are checked for optInTimePeriod_0. */
   if( (TA_Integer)optInTimePeriod_0 == TA_INTEGER_DEFAULT )
      optInTimePeriod_0 = 30;
   else if( ((TA_Integer)optInTimePeriod_0 < 2) || ((TA_Integer)optInTimePeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Default return values */
   *outBegIdx    = 0;
   *outNbElement = 0;

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */
   lookbackTotal = optInTimePeriod_0 + TA_Globals.unstablePeriod[TA_FUNC_UNST_KAMA];

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
      
   /* Initialize the variables by going through
    * the lookback period.
    */
   sumROC1 = 0.0;
   today = startIdx-lookbackTotal;   
   trailingIdx = today;
   i = optInTimePeriod_0;
   while( i-- > 0 )
   {      
      tempReal  = inReal_0[today++];
      tempReal -= inReal_0[today];
      sumROC1  += fabs(tempReal);
   }

   /* At this point sumROC1 represent the 
    * summation of the 1-day price difference
    * over the (optInTimePeriod_0-1)
    */

   /* Calculate the first KAMA */

   /* The yesterday price is used here as the previous KAMA. */
   prevKAMA = inReal_0[today-1];

   tempReal  = inReal_0[today];
   tempReal2 = inReal_0[trailingIdx++];
   periodROC = tempReal-tempReal2;

   /* Save the trailing value. Do this because inReal_0
    * and outReal_0 can be pointers to the same buffer. 
    */
   trailingValue = tempReal2;

   /* Calculate the efficiency ratio */
   tempReal = fabs(periodROC/sumROC1);

   /* Calculate the smoothing constant */
   tempReal  = (tempReal*constDiff)+constMax;
   tempReal *= tempReal;

   /* Calculate the KAMA like an EMA, using the
    * smoothing constant as the adaptive factor.
    */
   prevKAMA = ((inReal_0[today++]-prevKAMA)*tempReal) + prevKAMA;

   /* 'today' keep track of where the processing is within the
    * input.
    */

   /* Skip the unstable period. Do the whole processing 
    * needed for KAMA, but do not write it in the output.
    */   
   while( today <= startIdx )
   {
      tempReal  = inReal_0[today];
      tempReal2 = inReal_0[trailingIdx++];
      periodROC = tempReal-tempReal2;

      /* Adjust sumROC1:
       *  - Remove trailing ROC1 
       *  - Add new ROC1
       */
      sumROC1 -= fabs(trailingValue-tempReal2);
      sumROC1 += fabs(tempReal-inReal_0[today-1]);

      /* Save the trailing value. Do this because inReal_0
       * and outReal_0 can be pointers to the same buffer. 
       */
      trailingValue = tempReal2;

      /* Calculate the efficiency ratio */
      tempReal = fabs(periodROC/sumROC1);

      /* Calculate the smoothing constant */
      tempReal  = (tempReal*constDiff)+constMax;
      tempReal *= tempReal;

      /* Calculate the KAMA like an EMA, using the
       * smoothing constant as the adaptive factor.
       */
      prevKAMA = ((inReal_0[today++]-prevKAMA)*tempReal) + prevKAMA;
   }

   /* Write the first value. */
   outReal_0[0] = prevKAMA;
   outIdx = 1;
   *outBegIdx = today-1;

   /* Do the KAMA calculation for the requested range. */
   while( today <= endIdx )
   {
      tempReal  = inReal_0[today];
      tempReal2 = inReal_0[trailingIdx++];
      periodROC = tempReal-tempReal2;

      /* Adjust sumROC1:
       *  - Remove trailing ROC1 
       *  - Add new ROC1
       */
      sumROC1 -= fabs(trailingValue-tempReal2);
      sumROC1 += fabs(tempReal-inReal_0[today-1]);

      /* Save the trailing value. Do this because inReal_0
       * and outReal_0 can be pointers to the same buffer. 
       */
      trailingValue = tempReal2;

      /* Calculate the efficiency ratio */
      tempReal = fabs(periodROC / sumROC1);

      /* Calculate the smoothing constant */
      tempReal  = (tempReal*constDiff)+constMax;
      tempReal *= tempReal;

      /* Calculate the KAMA like an EMA, using the
       * smoothing constant as the adaptive factor.
       */
      prevKAMA = ((inReal_0[today++]-prevKAMA)*tempReal) + prevKAMA;
      outReal_0[outIdx++] = prevKAMA;
   }

   *outNbElement = outIdx;

   return TA_SUCCESS;
}

