/* TA-LIB Copyright (c) 1999-2002, Mario Fortier
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
 *  112400 MF   First version.
 *
 */

/* Description:
 *     Regression test of MACD.
 */

/**** Headers ****/
#include <stdio.h>
#include <string.h>

#include "ta_test_priv.h"
#include "ta_test_func.h"
#include "ta_utility.h"
#include "ta_memory.h"

/**** External functions declarations. ****/
/* None */

/**** External variables declarations. ****/
/* None */

/**** Global variables definitions.    ****/
/* None */

/**** Local declarations.              ****/
typedef struct
{ 
   TA_Integer doRangeTestFlag;
   TA_Integer doMACD_FIX;

   TA_Integer startIdx;
   TA_Integer endIdx;

   TA_Integer optInFastPeriod_0;
   TA_Integer optInSlowPeriod_1;
   TA_Integer optInSignalPeriod_2;
   TA_Integer optInCompatibility_3;

   TA_RetCode expectedRetCode;

   TA_Integer expectedBegIdx;
   TA_Integer expectedNbElement;
   
   TA_Integer oneOfTheExpectedOutRealIndex0;
   TA_Real    oneOfTheExpectedOutReal0;

   TA_Integer oneOfTheExpectedOutRealIndex1;
   TA_Real    oneOfTheExpectedOutReal1;

   TA_Integer oneOfTheExpectedOutRealIndex2;
   TA_Real    oneOfTheExpectedOutReal2;

} TA_Test;
                                                                      
typedef struct
{
   const TA_Test *test;
   const TA_Real *close;
} TA_RangeTestParam;

/**** Local functions declarations.    ****/
static ErrorNumber do_test( TA_Libc *libHandle,
                            const TA_History *history,
                            const TA_Test *test );

/**** Local variables definitions.     ****/
static TA_Test tableTest[] =
{

   /*********************/
   /*   MACD - CLASSIC  */
   /*********************/

   /***********************/
   /*   MACD - METASTOCK  */
   /***********************/

   /***************************/
   /*   MACD FIX - CLASSIC    */
   /***************************/

   /***************************/
   /*   MACD FIX - METASTOCK  */
   /***************************/
   { 1, 1, 0, 251, 12, 26, 9, TA_MA_METASTOCK, TA_SUCCESS,  33, 252-33, /* 25, 252-25,*/  
                                                          0, -1.2185,  /* MACD */
                                                          0, -1.7119,  /* Signal */
                                                          0, (-1.2185)-(-1.7119) }, /* Histogram */

   { 0, 1, 0, 251, 12, 26, 9, TA_MA_METASTOCK, TA_SUCCESS, 33, 252-33, 
                                                        252-34,  0.8764, /* MACD */
                                                        252-34,  1.3533,   /* Signal */
                                                        252-34,  (0.8764)-(1.3533)} /* Histogram */

};

#define NB_TEST (sizeof(tableTest)/sizeof(TA_Test))

/**** Global functions definitions.   ****/
ErrorNumber test_func_macd( TA_Libc *libHandle, TA_History *history )
{
   unsigned int i;
   ErrorNumber retValue;

   for( i=0; i < NB_TEST; i++ )
   {

      if( (int)tableTest[i].expectedNbElement > (int)history->nbBars )
      {
         printf( "TA_MACD Failed Bad Parameter for Test #%d (%d,%d)\n",
                 i,
                 tableTest[i].expectedNbElement,
                 history->nbBars );
         return TA_TESTUTIL_TFRR_BAD_PARAM;
      }

      retValue = do_test( libHandle, history, &tableTest[i] );
      if( retValue != 0 )
      {
         printf( "TA_MACD Failed Test #%d (Code=%d)\n", i, retValue );
         return retValue;
      }
   }

   /* All test succeed. */
   return 0; 
}

/**** Local functions definitions.     ****/
static TA_RetCode rangeTestFunction( TA_Libc *libHandle, 
                                     TA_Integer startIdx,
                                     TA_Integer endIdx,
                                     TA_Real *outputBuffer,
                                     TA_Integer *outBegIdx,
                                     TA_Integer *outNbElement,
                                     TA_Integer *lookback,
                                     void *opaqueData,
                                     unsigned int outputNb )
{
  TA_RetCode retCode;
  TA_RangeTestParam *testParam;
  TA_Real *dummyBuffer1, *dummyBuffer2;
  TA_Real *out1, *out2, *out3;

  testParam = (TA_RangeTestParam *)opaqueData;   

  dummyBuffer1 = TA_Malloc( libHandle, ((endIdx-startIdx)+1)*sizeof(TA_Real));
  if( !dummyBuffer1 )
     return TA_ALLOC_ERR;

  dummyBuffer2 = TA_Malloc( libHandle, ((endIdx-startIdx)+1)*sizeof(TA_Real));
  if( !dummyBuffer2 )
  {
     TA_Free( libHandle, dummyBuffer1 );
     return TA_ALLOC_ERR;
  }

  switch( outputNb )
  {
  case 0:
     out1 = outputBuffer;
     out2 = dummyBuffer1;
     out3 = dummyBuffer2;
     break;
  case 1:
     out2 = outputBuffer;
     out1 = dummyBuffer1;
     out3 = dummyBuffer2;
     break;
  case 2:
     out3 = outputBuffer;
     out2 = dummyBuffer1;
     out1 = dummyBuffer2;
     break;
  default:
     TA_Free( libHandle, dummyBuffer1 );
     TA_Free( libHandle, dummyBuffer2 );
     return TA_BAD_PARAM;
  }

   if( testParam->test->doMACD_FIX )
   {
      retCode = TA_MACDFIX( libHandle,
                            startIdx,
                            endIdx,
                            testParam->close,
                            testParam->test->optInSignalPeriod_2,
                            testParam->test->optInCompatibility_3,
                            outBegIdx, outNbElement,
                            out1, out2, out3 );
     *lookback = TA_MACDFIX_Lookback( testParam->test->optInSignalPeriod_2,
                                      testParam->test->optInCompatibility_3 );
   }
   else
   {
      retCode = TA_MACD( libHandle,
                            startIdx,
                            endIdx,
                            testParam->close,
                            testParam->test->optInFastPeriod_0,
                            testParam->test->optInSlowPeriod_1,
                            testParam->test->optInSignalPeriod_2,
                            testParam->test->optInCompatibility_3,
                            outBegIdx, outNbElement,
                            out1, out2, out3 );

     *lookback = TA_MACD_Lookback( testParam->test->optInFastPeriod_0,
                                   testParam->test->optInSlowPeriod_1,
                                   testParam->test->optInSignalPeriod_2,
                                   testParam->test->optInCompatibility_3 );
   }

   TA_Free( libHandle, dummyBuffer1 );
   TA_Free( libHandle, dummyBuffer2 );

   return retCode;
}

static ErrorNumber do_test( TA_Libc *libHandle,
                            const TA_History *history,
                            const TA_Test *test )
{
   TA_RetCode retCode;
   ErrorNumber errNb;
   TA_Integer outBegIdx;
   TA_Integer outNbElement;
   TA_RangeTestParam testParam;

   retCode = TA_SetUnstablePeriod( libHandle, TA_FUNC_UNST_EMA, 0 );
   if( retCode != TA_SUCCESS )
      return TA_TEST_TFRR_SETUNSTABLE_PERIOD_FAIL;

   /* Set to NAN all the elements of the gBuffers.  */
   clearAllBuffers();

   /* Build the input. */
   setInputBuffer( 0, history->close, history->nbBars );
   setInputBuffer( 1, history->close, history->nbBars );
   setInputBuffer( 2, history->close, history->nbBars );
   setInputBuffer( 3, history->close, history->nbBars );
      
   CLEAR_EXPECTED_VALUE(0);
   CLEAR_EXPECTED_VALUE(1);
   CLEAR_EXPECTED_VALUE(2);

   /* Make a simple first call. */
   if( test->doMACD_FIX )
   {
      retCode = TA_MACDFIX( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[0].in,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[0].out0, 
                        gBuffer[0].out1,
                        gBuffer[0].out2 );
   }
   else
   {
      retCode = TA_MACD( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[0].in,
                        test->optInFastPeriod_0,
                        test->optInSlowPeriod_1,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[0].out0, 
                        gBuffer[0].out1,
                        gBuffer[0].out2 );
   }


   errNb = checkDataSame( gBuffer[0].in, history->close, history->nbBars );
   if( errNb != TA_TEST_PASS )
      return errNb;

   CHECK_EXPECTED_VALUE( gBuffer[0].out0, 0 );
   CHECK_EXPECTED_VALUE( gBuffer[0].out1, 1 );
   CHECK_EXPECTED_VALUE( gBuffer[0].out2, 2 );

   outBegIdx = outNbElement = 0;

   /* Make another call where the input and the output are the
    * same buffer.
    */
   if( test->doMACD_FIX )
   {
      retCode = TA_MACDFIX( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[1].in,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[1].in,   
                        gBuffer[1].out1,
                        gBuffer[1].out2 );
   }
   else
   {
      retCode = TA_MACD( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[1].in,
                        test->optInFastPeriod_0,
                        test->optInSlowPeriod_1,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[1].in,   
                        gBuffer[1].out1,
                        gBuffer[1].out2 );
   }

   /* The previous call should have the same output
    * as this call.
    *
    * checkSameContent verify that all value different than NAN in
    * the first parameter is identical in the second parameter.
    */
   errNb = checkSameContent( gBuffer[0].out0, gBuffer[1].in );
   if( errNb != TA_TEST_PASS )
      return errNb;

   CHECK_EXPECTED_VALUE( gBuffer[1].in,   0 );
   CHECK_EXPECTED_VALUE( gBuffer[1].out1, 1 );
   CHECK_EXPECTED_VALUE( gBuffer[1].out2, 2 );

   outBegIdx = outNbElement = 0;

   CLEAR_EXPECTED_VALUE(0);
   CLEAR_EXPECTED_VALUE(1);
   CLEAR_EXPECTED_VALUE(2);

   /* Make another call where the input and the output are the
    * same buffer.
    */
   if( test->doMACD_FIX )
   {
      retCode = TA_MACDFIX( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[2].in,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[2].out1,
                        gBuffer[2].in,
                        gBuffer[2].out2 );
   }
   else
   {
      retCode = TA_MACD( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[2].in,
                        test->optInFastPeriod_0,
                        test->optInSlowPeriod_1,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[2].out1,
                        gBuffer[2].in,
                        gBuffer[2].out2 );
   }

   /* The previous call should have the same output
    * as this call.
    *
    * checkSameContent verify that all value different than NAN in
    * the first parameter is identical in the second parameter.
    */
   errNb = checkSameContent( gBuffer[1].out1, gBuffer[2].in );
   if( errNb != TA_TEST_PASS )
      return errNb;

   CHECK_EXPECTED_VALUE( gBuffer[2].out1, 0 );
   CHECK_EXPECTED_VALUE( gBuffer[2].in,   1 );
   CHECK_EXPECTED_VALUE( gBuffer[2].out2, 2 );

   outBegIdx = outNbElement = 0;

   CLEAR_EXPECTED_VALUE(0);
   CLEAR_EXPECTED_VALUE(1);
   CLEAR_EXPECTED_VALUE(2);

   /* Make another call where the input and the output are the
    * same buffer.
    */
   if( test->doMACD_FIX )
   {
      retCode = TA_MACDFIX( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[3].in,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[3].out1, 
                        gBuffer[3].out2,
                        gBuffer[3].in );
   }
   else
   {
      retCode = TA_MACD( libHandle,
                        test->startIdx,
                        test->endIdx,
                        gBuffer[3].in,
                        test->optInFastPeriod_0,
                        test->optInSlowPeriod_1,
                        test->optInSignalPeriod_2,
                        test->optInCompatibility_3,
                        &outBegIdx, &outNbElement,
                        gBuffer[3].out1, 
                        gBuffer[3].out2,
                        gBuffer[3].in );
   }

   /* The previous call should have the same output
    * as this call.
    *
    * checkSameContent verify that all value different than NAN in
    * the first parameter is identical in the second parameter.
    */
   errNb = checkSameContent( gBuffer[2].out2, gBuffer[3].in );
   if( errNb != TA_TEST_PASS )
      return errNb;

   CHECK_EXPECTED_VALUE( gBuffer[3].out1, 0 );
   CHECK_EXPECTED_VALUE( gBuffer[3].out2, 1 );
   CHECK_EXPECTED_VALUE( gBuffer[3].in,   2 );

   /* Do a systematic test of most of the
    * possible startIdx/endIdx range.
    */
   testParam.test  = test;
   testParam.close = history->close;

   if( test->doRangeTestFlag )
   {
      errNb = doRangeTest( libHandle,
                           rangeTestFunction, 
                           TA_FUNC_UNST_EMA,
                           (void *)&testParam, 3, 0 );
      if( errNb != TA_TEST_PASS )
         return errNb;
   }

   return TA_TEST_PASS;
}
