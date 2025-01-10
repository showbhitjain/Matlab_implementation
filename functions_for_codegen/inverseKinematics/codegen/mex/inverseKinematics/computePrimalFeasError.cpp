//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computePrimalFeasError.cpp
//
// Code generation for function 'computePrimalFeasError'
//

// Include files
#include "computePrimalFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo pf_emlrtRSI{
    1,                        // lineNo
    "computePrimalFeasError", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computePrimalFeasError.p" // pathName
};

static emlrtBCInfo s_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    1,                        // lineNo
    1,                        // colNo
    "",                       // aName
    "computePrimalFeasError", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computePrimalFeasError.p", // pName
    0                                     // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
real_T computePrimalFeasError(const emlrtStack &sp, const array<real_T, 1U> &x,
                              int32_T mLinEq, const real_T cEq_data[],
                              int32_T cEq_size,
                              const array<int32_T, 1U> &finiteLB, int32_T mLB,
                              const array<real_T, 1U> &lb,
                              const array<int32_T, 1U> &finiteUB, int32_T mUB,
                              const array<real_T, 1U> &ub)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T feasError;
  int32_T idxFiniteLB;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  feasError = 0.0;
  st.site = &pf_emlrtRSI;
  if (mLinEq > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mLinEq; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > cEq_size)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cEq_size, &s_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    feasError = muDoubleScalarMax(feasError, muDoubleScalarAbs(cEq_data[idx]));
  }
  st.site = &pf_emlrtRSI;
  st.site = &pf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mLB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteLB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB.size(0), &s_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    idxFiniteLB = finiteLB[idx] - 1;
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > lb.size(0))) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, lb.size(0), &s_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > x.size(0))) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, x.size(0), &s_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    feasError = muDoubleScalarMax(feasError, lb[idxFiniteLB] - x[idxFiniteLB]);
  }
  st.site = &pf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mUB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteUB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteUB.size(0), &s_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    idxFiniteLB = finiteUB[idx] - 1;
    if ((finiteUB[idx] < 1) || (finiteUB[idx] > x.size(0))) {
      emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, x.size(0), &s_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((finiteUB[idx] < 1) || (finiteUB[idx] > ub.size(0))) {
      emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, ub.size(0), &s_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    feasError = muDoubleScalarMax(feasError, x[idxFiniteLB] - ub[idxFiniteLB]);
  }
  return feasError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computePrimalFeasError.cpp)
