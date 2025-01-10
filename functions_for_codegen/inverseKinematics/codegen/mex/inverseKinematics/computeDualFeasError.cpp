//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeDualFeasError.cpp
//
// Code generation for function 'computeDualFeasError'
//

// Include files
#include "computeDualFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo qf_emlrtRSI{
    1,                      // lineNo
    "computeDualFeasError", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeDualFeasError.p" // pathName
};

static emlrtBCInfo q_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    1,                      // lineNo
    1,                      // colNo
    "",                     // aName
    "computeDualFeasError", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeDualFeasError.p", // pName
    0                                   // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
boolean_T computeDualFeasError(const emlrtStack &sp, int32_T nVar,
                               const array<real_T, 1U> &gradLag, real_T &val)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T exitg1;
  boolean_T gradOK;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  gradOK = true;
  val = 0.0;
  st.site = &qf_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    boolean_T b;
    b = ((idx + 1 < 1) || (idx + 1 > gradLag.size(0)));
    if (b) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, gradLag.size(0), &q_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    gradOK = ((!muDoubleScalarIsInf(gradLag[idx])) &&
              (!muDoubleScalarIsNaN(gradLag[idx])));
    if (!gradOK) {
      exitg1 = true;
    } else {
      val = muDoubleScalarMax(val, muDoubleScalarAbs(gradLag[idx]));
      idx++;
    }
  }
  return gradOK;
}

boolean_T computeDualFeasError(const emlrtStack &sp, int32_T nVar,
                               const array<real_T, 2U> &gradLag, real_T &val)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T exitg1;
  boolean_T gradOK;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  gradOK = true;
  val = 0.0;
  st.site = &qf_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    int32_T i;
    i = gradLag.size(0) * gradLag.size(1);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &q_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    gradOK = ((!muDoubleScalarIsInf(gradLag[idx])) &&
              (!muDoubleScalarIsNaN(gradLag[idx])));
    if (!gradOK) {
      exitg1 = true;
    } else {
      val = muDoubleScalarMax(val, muDoubleScalarAbs(gradLag[idx]));
      idx++;
    }
  }
  return gradOK;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeDualFeasError.cpp)
