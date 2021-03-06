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
 *  JV       Jesus Viver <324122@cienz.unizar.es>
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *  100502 JV   Speed optimization of the algorithm
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *  090404 MF   Fix #978056. Trap sqrt with negative zero values.
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
/* Generated */ int Core::STDDEV_Lookback( int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                          double        optInNbDev )  /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_STDDEV_Lookback( int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                       double        optInNbDev )  /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* Lookback is driven by the variance. */
   return TA_VAR_Lookback( optInTimePeriod, optInNbDev );
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_STDDEV - Standard Deviation
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 2 to 100000)
 *    Number of period
 * 
 * optInNbDev:(From TA_REAL_MIN to TA_REAL_MAX)
 *    Nb of deviations
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ __value enum Core::TA_RetCode Core::STDDEV( int    startIdx,
/* Generated */                                             int    endIdx,
/* Generated */                                             double       inReal __gc [],
/* Generated */                                             int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                             double        optInNbDev, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                                             [OutAttribute]Int32 *outBegIdx,
/* Generated */                                             [OutAttribute]Int32 *outNbElement,
/* Generated */                                             double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_STDDEV( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       const double inReal[],
/* Generated */                       int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                       double        optInNbDev, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                       int          *outBegIdx,
/* Generated */                       int          *outNbElement,
/* Generated */                       double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   int i;
   TA_RetCode retCode;
   double tempReal;

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
/* Generated */    if( !inReal ) return TA_BAD_PARAM;
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 5;
/* Generated */    else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( optInNbDev == TA_REAL_DEFAULT )
/* Generated */       optInNbDev = 1.000000e+0;
/* Generated */    else if( (optInNbDev < -3.000000e+37) ||/* Generated */  (optInNbDev > 3.000000e+37) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outReal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Calculate the variance. */
   retCode = TA_PREFIX(INT_VAR)( startIdx, endIdx,
                                 inReal, optInTimePeriod,
                                 outBegIdx, outNbElement, outReal );

   if( retCode != TA_SUCCESS )
      return retCode;

   /* Calculate the square root of each variance, this
    * is the standard deviation.
    *
    * Multiply also by the ratio specified.
    */
   if( optInNbDev != 1.0 )
   {
      for( i=0; i < *outNbElement; i++ )
      {
         tempReal = outReal[i];
         if( !TA_IS_ZERO_OR_NEG(tempReal) )
            outReal[i] = sqrt(tempReal) * optInNbDev;
         else
            outReal[i] = (double)0.0;
      }
   }
   else
   {
      for( i=0; i < *outNbElement; i++ )
      {
         tempReal = outReal[i];
         if( !TA_IS_ZERO_OR_NEG(tempReal) )
            outReal[i] = sqrt(tempReal);
         else
            outReal[i] = (double)0.0;
      }
   }

   return TA_SUCCESS;
}

/* The inMovAvg is the moving average of the inReal. 
 *
 * inMovAvgBegIdx is relative to inReal, in other word
 * this is the 'outBegIdx' who was returned when doing the
 * MA on the inReal.
 *
 * inMovAvgNbElement is the number of element who was returned
 * when doing the MA on the inReal.
 *
 * Note: This function is not used by TA_STDDEV, since TA_STDDEV
 *       is optimized considering it uses always a simple moving
 *       average. Still the function is put here because it is 
 *       closely related.
 */
#if defined( _MANAGED )
void Core::TA_INT_stddev_using_precalc_ma( INPUT_TYPE inReal __gc[],
                                           double inMovAvg __gc [],
                                           int inMovAvgBegIdx,                                    
                                           int inMovAvgNbElement,
                                           int timePeriod,
                                           double output __gc [])
#else
void TA_PREFIX(INT_stddev_using_precalc_ma)( const INPUT_TYPE *inReal,
                                             const double *inMovAvg,
                                             int inMovAvgBegIdx,                                    
                                             int inMovAvgNbElement,
                                             int timePeriod,
                                             double *output )
#endif
{
   double tempReal, periodTotal2, meanValue2;
   int outIdx;

   /* Start/end index for sumation. */
   int startSum, endSum;

   startSum = 1+inMovAvgBegIdx-timePeriod;
   endSum = inMovAvgBegIdx;

   periodTotal2 = 0;

   for( outIdx = startSum; outIdx < endSum; outIdx++)
   {
      tempReal = inReal[outIdx];
      tempReal *= tempReal;
      periodTotal2 += tempReal;
   }

   for( outIdx=0; outIdx < inMovAvgNbElement; outIdx++, startSum++, endSum++ )
   {
      tempReal = inReal[endSum];
      tempReal *= tempReal;
      periodTotal2 += tempReal;
      meanValue2 = periodTotal2/timePeriod;

      tempReal = inReal[startSum];
      tempReal *= tempReal;
      periodTotal2 -= tempReal;

      tempReal = inMovAvg[outIdx];
      tempReal *= tempReal;
      meanValue2 -= tempReal;
      
      if( !TA_IS_ZERO_OR_NEG(meanValue2) )
         output[outIdx] = sqrt(meanValue2);
      else
         output[outIdx] = (double)0.0;
   }
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
/* Generated */ __value enum Core::TA_RetCode Core::STDDEV( int    startIdx,
/* Generated */                                             int    endIdx,
/* Generated */                                             float        inReal __gc [],
/* Generated */                                             int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                             double        optInNbDev, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                                             [OutAttribute]Int32 *outBegIdx,
/* Generated */                                             [OutAttribute]Int32 *outNbElement,
/* Generated */                                             double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_STDDEV( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         const float  inReal[],
/* Generated */                         int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                         double        optInNbDev, /* From TA_REAL_MIN to TA_REAL_MAX */
/* Generated */                         int          *outBegIdx,
/* Generated */                         int          *outNbElement,
/* Generated */                         double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    int i;
/* Generated */    TA_RetCode retCode;
/* Generated */    double tempReal;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if( !inReal ) return TA_BAD_PARAM;
/* Generated */     if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInTimePeriod = 5;
/* Generated */     else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( optInNbDev == TA_REAL_DEFAULT )
/* Generated */        optInNbDev = 1.000000e+0;
/* Generated */     else if( (optInNbDev < -3.000000e+37) ||  (optInNbDev > 3.000000e+37) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outReal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    retCode = TA_PREFIX(INT_VAR)( startIdx, endIdx,
/* Generated */                                  inReal, optInTimePeriod,
/* Generated */                                  outBegIdx, outNbElement, outReal );
/* Generated */    if( retCode != TA_SUCCESS )
/* Generated */       return retCode;
/* Generated */    if( optInNbDev != 1.0 )
/* Generated */    {
/* Generated */       for( i=0; i < *outNbElement; i++ )
/* Generated */       {
/* Generated */          tempReal = outReal[i];
/* Generated */          if( !TA_IS_ZERO_OR_NEG(tempReal) )
/* Generated */             outReal[i] = sqrt(tempReal) * optInNbDev;
/* Generated */          else
/* Generated */             outReal[i] = (double)0.0;
/* Generated */       }
/* Generated */    }
/* Generated */    else
/* Generated */    {
/* Generated */       for( i=0; i < *outNbElement; i++ )
/* Generated */       {
/* Generated */          tempReal = outReal[i];
/* Generated */          if( !TA_IS_ZERO_OR_NEG(tempReal) )
/* Generated */             outReal[i] = sqrt(tempReal);
/* Generated */          else
/* Generated */             outReal[i] = (double)0.0;
/* Generated */       }
/* Generated */    }
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ #if defined( _MANAGED )
/* Generated */ void Core::TA_INT_stddev_using_precalc_ma( INPUT_TYPE inReal __gc[],
/* Generated */                                            double inMovAvg __gc [],
/* Generated */                                            int inMovAvgBegIdx,                                    
/* Generated */                                            int inMovAvgNbElement,
/* Generated */                                            int timePeriod,
/* Generated */                                            double output __gc [])
/* Generated */ #else
/* Generated */ void TA_PREFIX(INT_stddev_using_precalc_ma)( const INPUT_TYPE *inReal,
/* Generated */                                              const double *inMovAvg,
/* Generated */                                              int inMovAvgBegIdx,                                    
/* Generated */                                              int inMovAvgNbElement,
/* Generated */                                              int timePeriod,
/* Generated */                                              double *output )
/* Generated */ #endif
/* Generated */ {
/* Generated */    double tempReal, periodTotal2, meanValue2;
/* Generated */    int outIdx;
/* Generated */    int startSum, endSum;
/* Generated */    startSum = 1+inMovAvgBegIdx-timePeriod;
/* Generated */    endSum = inMovAvgBegIdx;
/* Generated */    periodTotal2 = 0;
/* Generated */    for( outIdx = startSum; outIdx < endSum; outIdx++)
/* Generated */    {
/* Generated */       tempReal = inReal[outIdx];
/* Generated */       tempReal *= tempReal;
/* Generated */       periodTotal2 += tempReal;
/* Generated */    }
/* Generated */    for( outIdx=0; outIdx < inMovAvgNbElement; outIdx++, startSum++, endSum++ )
/* Generated */    {
/* Generated */       tempReal = inReal[endSum];
/* Generated */       tempReal *= tempReal;
/* Generated */       periodTotal2 += tempReal;
/* Generated */       meanValue2 = periodTotal2/timePeriod;
/* Generated */       tempReal = inReal[startSum];
/* Generated */       tempReal *= tempReal;
/* Generated */       periodTotal2 -= tempReal;
/* Generated */       tempReal = inMovAvg[outIdx];
/* Generated */       tempReal *= tempReal;
/* Generated */       meanValue2 -= tempReal;
/* Generated */       if( !TA_IS_ZERO_OR_NEG(meanValue2) )
/* Generated */          output[outIdx] = sqrt(meanValue2);
/* Generated */       else
/* Generated */          output[outIdx] = (double)0.0;
/* Generated */    }
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

