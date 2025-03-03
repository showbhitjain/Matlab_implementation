//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// saveJacobian.cpp
//
// Code generation for function 'saveJacobian'
//

// Include files
#include "saveJacobian.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo tf_emlrtRSI{
    1,              // lineNo
    "saveJacobian", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/saveJacobian.p" // pathName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void saveJacobian(const emlrtStack &sp, int32_T mIneq, int32_T ineqCol0,
                  int32_T mEq, int32_T eqCol0)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &tf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((mIneq - ineqCol0) + 1 > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  st.site = &tf_emlrtRSI;
  if ((mEq - eqCol0) + 1 > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
}

} // namespace TrialState
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (saveJacobian.cpp)
