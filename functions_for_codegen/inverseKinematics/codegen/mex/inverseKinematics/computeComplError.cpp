//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeComplError.cpp
//
// Code generation for function 'computeComplError'
//

// Include files
#include "computeComplError.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo rf_emlrtRSI{
    1,                   // lineNo
    "computeComplError", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeComplError.p" // pathName
};

static emlrtBCInfo t_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    1,                   // lineNo
    1,                   // colNo
    "",                  // aName
    "computeComplError", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeComplError.p", // pName
    0                                // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
real_T computeComplError(const emlrtStack &sp,
                         const array<real_T, 1U> &xCurrent,
                         const array<int32_T, 1U> &finiteLB, int32_T mLB,
                         const array<real_T, 1U> &lb,
                         const array<int32_T, 1U> &finiteUB, int32_T mUB,
                         const array<real_T, 1U> &ub,
                         const array<real_T, 1U> &lambda, int32_T iL0)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T nlpComplError;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nlpComplError = 0.0;
  if (mLB + mUB > 0) {
    real_T lbDelta;
    real_T lbLambda;
    int32_T i;
    int32_T ubOffset;
    ubOffset = iL0 + mLB;
    st.site = &rf_emlrtRSI;
    if (mLB > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < mLB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > finiteLB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB.size(0), &t_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((finiteLB[idx] < 1) || (finiteLB[idx] > xCurrent.size(0))) {
        emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, xCurrent.size(0),
                                      &t_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((finiteLB[idx] < 1) || (finiteLB[idx] > lb.size(0))) {
        emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, lb.size(0), &t_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbDelta = xCurrent[finiteLB[idx] - 1] - lb[finiteLB[idx] - 1];
      i = iL0 + idx;
      if ((i < 1) || (i > lambda.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda.size(0), &t_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbLambda = lambda[i - 1];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbDelta * lbLambda),
              muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
    }
    st.site = &rf_emlrtRSI;
    if (mUB > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < mUB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > finiteUB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteUB.size(0), &t_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((finiteUB[idx] < 1) || (finiteUB[idx] > ub.size(0))) {
        emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, ub.size(0), &t_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((finiteUB[idx] < 1) || (finiteUB[idx] > xCurrent.size(0))) {
        emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, xCurrent.size(0),
                                      &t_emlrtBCI, (emlrtConstCTX)&sp);
      }
      lbDelta = ub[finiteUB[idx] - 1] - xCurrent[finiteUB[idx] - 1];
      i = ubOffset + idx;
      if ((i < 1) || (i > lambda.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda.size(0), &t_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbLambda = lambda[i - 1];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbDelta * lbLambda),
              muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
    }
  }
  return nlpComplError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeComplError.cpp)
