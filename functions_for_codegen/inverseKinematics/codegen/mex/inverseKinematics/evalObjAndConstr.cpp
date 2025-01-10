//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// evalObjAndConstr.cpp
//
// Code generation for function 'evalObjAndConstr'
//

// Include files
#include "evalObjAndConstr.h"
#include "computeObjective_.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo gj_emlrtRSI{
    1,                  // lineNo
    "evalObjAndConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
    "+ObjNonlinEvaluator/evalObjAndConstr.p" // pathName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace ObjNonlinEvaluator {
real_T evalObjAndConstr(const emlrtStack &sp,
                        const ::coder::internal::i_stickyStruct &obj,
                        const array<real_T, 1U> &x, int32_T &status)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T fval;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &gj_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ic_emlrtRSI;
  if (x.size(0) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &q_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:expectedNonempty", 3, 4, 5, "input");
  }
  st.site = &gj_emlrtRSI;
  fval = computeObjective_(st, obj, x, status);
  if (status == 1) {
    st.site = &gj_emlrtRSI;
    b_st.site = &af_emlrtRSI;
    c_st.site = &ic_emlrtRSI;
    if (x.size(0) == 0) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &q_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedNonempty",
          "MATLAB:expectedNonempty", 3, 4, 5, "input");
    }
    status = 1;
  }
  return fval;
}

} // namespace ObjNonlinEvaluator
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (evalObjAndConstr.cpp)
