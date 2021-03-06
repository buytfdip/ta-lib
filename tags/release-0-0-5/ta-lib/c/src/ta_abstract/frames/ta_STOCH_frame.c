/* DO NOT MODIFY this file.
 * This file is automatically generated by gen_Code.
 *
 * The function define in this file allows to have a consistent
 * framework for calling all the TA function through
 * the TA_CallFunc mechanism.
 *
 * See "ta_abstract.h"
 */

#include "ta_func.h"
#include "ta_frame_priv.h"
#include "ta_frame.h"

/* NEVER CALL directly this function! Use TA_CallFunc. */
 
TA_RetCode TA_STOCH_FramePP( TA_Libc            *libHandle,
                          TA_Integer          startIdx,
                          TA_Integer          endIdx,
                          TA_Integer         *outBegIdx,
                          TA_Integer         *outNbElement,
                          TA_ParamHolderPriv  in[],
                          TA_ParamHolderPriv  optIn[],
                          TA_ParamHolderPriv  out[] )
{
   return TA_STOCH( libHandle,
              startIdx,
              endIdx,
              in[0].p.in.data.inPrice.high, /* inHigh_0 */
              in[0].p.in.data.inPrice.low, /* inLow_0 */
              in[0].p.in.data.inPrice.close, /* inClose_0 */
              optIn[0].p.optIn.data.optInInteger, /* optInKPeriod_0 */
              optIn[1].p.optIn.data.optInInteger, /* optInKSlowPeriod_1 */
              optIn[2].p.optIn.data.optInInteger, /* optInDSlowPeriod_2 */
              optIn[3].p.optIn.data.optInInteger, /* optInMethod_3 */
              outBegIdx, 
              outNbElement, 
              out[0].p.out.data.outReal, /*  outRealK_0 */
              out[1].p.out.data.outReal /*  outRealD_1 */ );
}

/***************
 * End of File *
 ***************/
