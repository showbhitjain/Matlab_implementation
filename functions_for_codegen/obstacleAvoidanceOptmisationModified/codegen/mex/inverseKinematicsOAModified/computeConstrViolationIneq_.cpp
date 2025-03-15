//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeConstrViolationIneq_.cpp
//
// Code generation for function 'computeConstrViolationIneq_'
//

// Include files
#include "computeConstrViolationIneq_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ff_emlrtRSI{
    1,                             // lineNo
    "computeConstrViolationIneq_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+MeritFunction/computeConstrViolationIneq_.p" // pathName
};

static emlrtBCInfo eb_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    1,                             // lineNo
    1,                             // colNo
    "",                            // aName
    "computeConstrViolationIneq_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+MeritFunction/computeConstrViolationIneq_.p", // pName
    0                                               // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace MeritFunction {
real_T computeConstrViolationIneq_(const emlrtStack &sp, int32_T mIneq,
                                   const real_T ineq_workspace_data[],
                                   int32_T ineq_workspace_size)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T normResid;
  int32_T i;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  normResid = 0.0;
  st.site = &ff_emlrtRSI;
  if (mIneq > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  i = static_cast<uint8_T>(mIneq);
  for (int32_T idx{0}; idx < i; idx++) {
    real_T d;
    if (idx + 1 > ineq_workspace_size) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ineq_workspace_size,
                                    &eb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    d = ineq_workspace_data[idx];
    if (d > 0.0) {
      if (idx + 1 > ineq_workspace_size) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ineq_workspace_size,
                                      &eb_emlrtBCI, (emlrtConstCTX)&sp);
      }
      normResid += d;
    }
  }
  return normResid;
}

} // namespace MeritFunction
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeConstrViolationIneq_.cpp)
