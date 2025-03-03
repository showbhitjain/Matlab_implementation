//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// isDeltaXTooSmall.cpp
//
// Code generation for function 'isDeltaXTooSmall'
//

// Include files
#include "isDeltaXTooSmall.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo nf_emlrtRSI{
    1,                  // lineNo
    "isDeltaXTooSmall", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/isDeltaXTooSmall.p" // pathName
};

static emlrtBCInfo hb_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    1,                  // lineNo
    1,                  // colNo
    "",                 // aName
    "isDeltaXTooSmall", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/isDeltaXTooSmall.p", // pName
    0                               // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
boolean_T isDeltaXTooSmall(const emlrtStack &sp,
                           const array<real_T, 1U> &xCurrent,
                           const array<real_T, 1U> &delta_x, int32_T nVar)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T exitg1;
  boolean_T tf;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tf = true;
  st.site = &nf_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    if ((idx + 1 < 1) || (idx + 1 > xCurrent.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, xCurrent.size(0), &hb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((idx + 1 < 1) || (idx + 1 > delta_x.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, delta_x.size(0), &hb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if (1.0E-6 * muDoubleScalarMax(1.0, muDoubleScalarAbs(xCurrent[idx])) <=
        muDoubleScalarAbs(delta_x[idx])) {
      tf = false;
      exitg1 = true;
    } else {
      idx++;
    }
  }
  return tf;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (isDeltaXTooSmall.cpp)
