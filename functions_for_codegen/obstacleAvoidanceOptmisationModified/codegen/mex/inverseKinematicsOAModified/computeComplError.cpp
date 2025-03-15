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
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo nf_emlrtRSI{
    1,                   // lineNo
    "computeComplError", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeComplError.p" // pathName
};

static emlrtBCInfo gb_emlrtBCI{
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
real_T computeComplError(
    const emlrtStack &sp, int32_T fscales_lineq_constraint_size,
    const array<real_T, 1U> &xCurrent, int32_T mIneq, const real_T cIneq_data[],
    int32_T cIneq_size, const array<int32_T, 1U> &finiteLB, int32_T mLB,
    const real_T lb_data[], int32_T lb_size, const array<int32_T, 1U> &finiteUB,
    int32_T mUB, const real_T ub_data[], int32_T ub_size,
    const real_T lambda_data[], int32_T lambda_size, int32_T iL0)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T nlpComplError;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nlpComplError = 0.0;
  if ((mIneq + mLB) + mUB > 0) {
    real_T lbDelta;
    real_T lbLambda;
    int32_T i;
    int32_T lbOffset;
    int32_T ubOffset;
    st.site = &nf_emlrtRSI;
    for (int32_T idx{0}; idx < fscales_lineq_constraint_size; idx++) {
      if (idx + 1 > fscales_lineq_constraint_size) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, fscales_lineq_constraint_size,
                                      &gb_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if (idx + 1 > cIneq_size) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cIneq_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = iL0 + idx;
      if ((i < 1) || (i > lambda_size)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbDelta = lambda_data[i - 1];
      if (idx + 1 > cIneq_size) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cIneq_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (i > lambda_size) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbLambda = cIneq_data[idx];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbLambda * lbDelta),
              muDoubleScalarMin(muDoubleScalarAbs(lbLambda), lbDelta)));
    }
    lbOffset = iL0 + mIneq;
    ubOffset = lbOffset + mLB;
    st.site = &nf_emlrtRSI;
    if (mLB > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < mLB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > finiteLB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB.size(0),
                                      &gb_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((finiteLB[idx] < 1) || (finiteLB[idx] > xCurrent.size(0))) {
        emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, xCurrent.size(0),
                                      &gb_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((finiteLB[idx] < 1) || (finiteLB[idx] > lb_size)) {
        emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, lb_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbDelta = xCurrent[finiteLB[idx] - 1] - lb_data[finiteLB[idx] - 1];
      i = lbOffset + idx;
      if ((i < 1) || (i > lambda_size)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbLambda = lambda_data[i - 1];
      nlpComplError = muDoubleScalarMax(
          nlpComplError,
          muDoubleScalarMin(
              muDoubleScalarAbs(lbDelta * lbLambda),
              muDoubleScalarMin(muDoubleScalarAbs(lbDelta), lbLambda)));
    }
    st.site = &nf_emlrtRSI;
    if (mUB > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < mUB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > finiteUB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteUB.size(0),
                                      &gb_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((finiteUB[idx] < 1) || (finiteUB[idx] > ub_size)) {
        emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, ub_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((finiteUB[idx] < 1) || (finiteUB[idx] > xCurrent.size(0))) {
        emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, xCurrent.size(0),
                                      &gb_emlrtBCI, (emlrtConstCTX)&sp);
      }
      lbDelta = ub_data[finiteUB[idx] - 1] - xCurrent[finiteUB[idx] - 1];
      i = ubOffset + idx;
      if ((i < 1) || (i > lambda_size)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, lambda_size, &gb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lbLambda = lambda_data[i - 1];
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
