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
 *  010802 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */

#if defined( _MANAGED )
   #using <mscorlib.dll>
   #include "Core.h"
   namespace TA { namespace Lib {
#else
   #include <string.h>
   #include <math.h>
   #include "ta_func.h"
#endif

#ifndef TA_UTILITY_H
   #include "ta_utility.h"
#endif

#ifndef TA_MEMORY_H
   #include "ta_memory.h"
#endif

#if defined( _MANAGED )
int Core::PLUS_DM_Lookback( int           optInTimePeriod_0 )  /* From 2 to TA_INTEGER_MAX */

#else
int TA_PLUS_DM_Lookback( int           optInTimePeriod_0 )  /* From 2 to TA_INTEGER_MAX */

#endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   if( optInTimePeriod_0 > 1 )
      return optInTimePeriod_0 + TA_Globals->unstablePeriod[TA_FUNC_UNST_PLUS_DM] - 1;
   else
      return 1;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_PLUS_DM - Plus Directional Movement
 * 
 * Input  = High, Low
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod_0:(From 2 to TA_INTEGER_MAX)
 *    Number of period
 * 
 * 
 */


#if defined( _MANAGED )
enum TA_RetCode Core::PLUS_DM( int    startIdx,
                               int    endIdx,
                               double       inHigh_0 __gc [],
                               double       inLow_0 __gc [],
                               int           optInTimePeriod_0, /* From 2 to TA_INTEGER_MAX */
                               [OutAttribute]Int32 *outBegIdx,
                               [OutAttribute]Int32 *outNbElement,
                               double        outReal_0 __gc [] )
#else
TA_RetCode TA_PLUS_DM( int    startIdx,
                       int    endIdx,
                       const double inHigh_0[],
                       const double inLow_0[],
                       int           optInTimePeriod_0, /* From 2 to TA_INTEGER_MAX */
                       int          *outBegIdx,
                       int          *outNbElement,
                       double        outReal_0[] )
#endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */
   int today, lookbackTotal, outIdx;
   double prevHigh, prevLow, tempReal;
   double prevPlusDM;
   double diffP, diffM;
   int i;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   /* Verify required price component. */
   if(!inHigh_0||!inLow_0)
      return TA_BAD_PARAM;

   /* min/max are checked for optInTimePeriod_0. */
   if( (int)optInTimePeriod_0 == TA_INTEGER_DEFAULT )
      optInTimePeriod_0 = 14;
   else if( ((int)optInTimePeriod_0 < 2) || ((int)optInTimePeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* 
    * The DM1 (one period) is base on the largest part of
    * today's range that is outside of yesterdays range.
    * 
    * The following 7 cases explain how the +DM and -DM are
    * calculated on one period:
    *
    * Case 1:                       Case 2:
    *    C|                        A|
    *     |                         | C|
    *     | +DM1 = (C-A)           B|  | +DM1 = 0
    *     | -DM1 = 0                   | -DM1 = (B-D)
    * A|  |                           D| 
    *  | D|                    
    * B|
    *
    * Case 3:                       Case 4:
    *    C|                           C|
    *     |                        A|  |
    *     | +DM1 = (C-A)            |  | +DM1 = 0
    *     | -DM1 = 0               B|  | -DM1 = (B-D)
    * A|  |                            | 
    *  |  |                           D|
    * B|  |
    *    D|
    * 
    * Case 5:                      Case 6:
    * A|                           A| C|
    *  | C| +DM1 = 0                |  |  +DM1 = 0
    *  |  | -DM1 = 0                |  |  -DM1 = 0
    *  | D|                         |  |
    * B|                           B| D|
    *
    *
    * Case 7:
    * 
    *    C|
    * A|  |
    *  |  | +DM=0
    * B|  | -DM=0
    *    D|
    *
    * In case 3 and 4, the rule is that the smallest delta between
    * (C-A) and (B-D) determine which of +DM or -DM is zero.
    *
    * In case 7, (C-A) and (B-D) are equal, so both +DM and -DM are
    * zero.
    *
    * The rules remain the same when A=B and C=D (when the highs
    * equal the lows).
    *
    * When calculating the DM over a period > 1, the one-period DM
    * for the desired period are initialy sum. In other word, 
    * for a +DM14, sum the +DM1 for the first 14 days (that's 
    * 13 values because there is no DM for the first day!)
    * Subsequent DM are calculated using the Wilder's
    * smoothing approach:
    * 
    *                                    Previous +DM14
    *  Today's +DM14 = Previous +DM14 -  -------------- + Today's +DM1
    *                                         14
    *
    * Reference:
    *    New Concepts In Technical Trading Systems, J. Welles Wilder Jr
    */

   if( optInTimePeriod_0 > 1 )
      lookbackTotal = optInTimePeriod_0 + TA_Globals->unstablePeriod[TA_FUNC_UNST_PLUS_DM] - 1;
   else
      lookbackTotal = 1;

   /* Adjust startIdx to account for the lookback period. */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx    = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   /* Indicate where the next output should be put
    * in the outReal_0.
    */
   outIdx = 0;

   /* Trap the case where no smoothing is needed. */
   if( optInTimePeriod_0 <= 1 )
   {
      /* No smoothing needed. Just do a simple DM1
       * for each price bar.
       */
      *outBegIdx = startIdx;
      today = startIdx-1;
      prevHigh = inHigh_0[today-1];
      prevLow  = inLow_0[today-1];
      while( today < endIdx )
      {      
         today++;
         tempReal = inHigh_0[today];
         diffP    = tempReal-prevHigh; /* Plus Delta */
         prevHigh = tempReal;
         tempReal = inLow_0[today];
         diffM    = prevLow-tempReal;   /* Minus Delta */
         prevLow  = tempReal;
         if( (diffP > 0) && (diffP > diffM) )
         {
            /* Case 1 and 3: +DM=diffP,-DM=0 */
            outReal_0[outIdx++] = diffP;
         }
         else
            outReal_0[outIdx++] = 0;
      }

      *outNbElement = outIdx;
      return TA_SUCCESS;
   }

   /* Process the initial DM */
   *outBegIdx = startIdx;

   prevPlusDM  = 0.0;
   today       = startIdx - lookbackTotal;
   prevHigh    = inHigh_0[today];
   prevLow     = inLow_0[today];
   i           = optInTimePeriod_0-1;
   while( i-- > 0 )
   {
      today++;
      tempReal = inHigh_0[today];
      diffP    = tempReal-prevHigh; /* Plus Delta */
      prevHigh = tempReal;
      tempReal = inLow_0[today];
      diffM    = prevLow-tempReal;   /* Minus Delta */
      prevLow  = tempReal;

      if( (diffP > 0) && (diffP > diffM) )
      {
         /* Case 1 and 3: +DM=diffP,-DM=0 */
         prevPlusDM += diffP;
      }
   }

   /* Process subsequent DM */

   /* Skip the unstable period. */
   i = TA_Globals->unstablePeriod[TA_FUNC_UNST_PLUS_DM];
   while( i-- != 0 )
   {
      today++;
      tempReal = inHigh_0[today];
      diffP    = tempReal-prevHigh; /* Plus Delta */
      prevHigh = tempReal;
      tempReal = inLow_0[today];
      diffM    = prevLow-tempReal;   /* Minus Delta */
      prevLow  = tempReal;
      if( (diffP > 0) && (diffP > diffM) )
      {
         /* Case 1 and 3: +DM=diffP,-DM=0 */
         prevPlusDM = prevPlusDM - (prevPlusDM/optInTimePeriod_0) + diffP;
      }
      else
      {
         /* Case 2,4,5 and 7 */
         prevPlusDM = prevPlusDM - (prevPlusDM/optInTimePeriod_0);
      }
   }

   /* Now start to write the output in
    * the caller provided outReal_0.
    */
   outReal_0[0] = prevPlusDM;
   outIdx = 1;

   while( today < endIdx )
   {
      today++;
      tempReal = inHigh_0[today];
      diffP    = tempReal-prevHigh; /* Plus Delta */
      prevHigh = tempReal;
      tempReal = inLow_0[today];
      diffM    = prevLow-tempReal;   /* Minus Delta */
      prevLow  = tempReal;

      if( (diffP > 0) && (diffP > diffM) )
      {
         /* Case 1 and 3: +DM=diffP,-DM=0 */
         prevPlusDM = prevPlusDM - (prevPlusDM/optInTimePeriod_0) + diffP;
      }
      else
      {
         /* Case 2,4,5 and 7 */
         prevPlusDM = prevPlusDM - (prevPlusDM/optInTimePeriod_0);
      }

      outReal_0[outIdx++] = prevPlusDM;
   }

   *outNbElement = outIdx;

   return TA_SUCCESS;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
#if defined( _MANAGED )
   }} // Close namespace TA.Lib
#endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

