//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeObjective_.cpp
//
// Code generation for function 'computeObjective_'
//

// Include files
#include "computeObjective_.h"
#include "anonymous_function.h"
#include "inverseKinematics.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types1.h"
#include "inverseKinematics_types.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo jc_emlrtRSI{
    1,                   // lineNo
    "computeObjective_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
    "+ObjNonlinEvaluator/computeObjective_.p" // pathName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace ObjNonlinEvaluator {
real_T computeObjective_(const emlrtStack &sp,
                         const ::coder::internal::i_stickyStruct &obj,
                         const array<real_T, 1U> &x, int32_T &status)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T fval;
  boolean_T b;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &jc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &m_emlrtRSI;
  fval = inverseKinematics_anonFcn1(
      b_st, obj.next.next.next.next.next.next.next.next.value.workspace.jacobi,
      obj.next.next.next.next.next.next.next.next.value.workspace.xd_eff_vel
          .data,
      obj.next.next.next.next.next.next.next.next.value.workspace.xd_eff_vel
          .size[0],
      obj.next.next.next.next.next.next.next.next.value.workspace
          .starting_joint_vel,
      obj.next.next.next.next.next.next.next.next.value.workspace.joint_values,
      obj.next.next.next.next.next.next.next.next.value.workspace.config, x);
  status = 1;
  b = muDoubleScalarIsNaN(fval);
  if (muDoubleScalarIsInf(fval) || b) {
    if (b) {
      status = -3;
    } else if (fval < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }
  return fval;
}

} // namespace ObjNonlinEvaluator
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeObjective_.cpp)
