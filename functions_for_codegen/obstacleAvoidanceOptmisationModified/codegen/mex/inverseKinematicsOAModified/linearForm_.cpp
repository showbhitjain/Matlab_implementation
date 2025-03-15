//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linearForm_.cpp
//
// Code generation for function 'linearForm_'
//

// Include files
#include "linearForm_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo dh_emlrtRSI{
    1,             // lineNo
    "linearForm_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/linearForm_.p" // pathName
};

static emlrtBCInfo ed_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    1,             // lineNo
    1,             // colNo
    "",            // aName
    "linearForm_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/linearForm_.p", // pName
    0                           // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void linearForm_(const emlrtStack &sp, boolean_T obj_hasLinear,
                 int32_T obj_nvar, array<real_T, 2U> &workspace,
                 const array<real_T, 2U> &H, const array<real_T, 1U> &f,
                 const array<real_T, 1U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  beta1 = 0.0;
  if (obj_hasLinear) {
    st.site = &dh_emlrtRSI;
    if (obj_nvar > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T i{0}; i < obj_nvar; i++) {
      int32_T workspace_tmp;
      workspace_tmp = workspace.size(0) * workspace.size(1);
      if ((i + 1 < 1) || (i + 1 > f.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, f.size(0), &ed_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (i + 1 > workspace_tmp) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, workspace_tmp, &ed_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[i] = f[i];
    }
    beta1 = 1.0;
  }
  st.site = &dh_emlrtRSI;
  if (obj_nvar >= 1) {
    alpha1 = 0.5;
    TRANSA = 'N';
    m_t = (ptrdiff_t)obj_nvar;
    n_t = (ptrdiff_t)obj_nvar;
    lda_t = (ptrdiff_t)obj_nvar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 2U> *)&H)->data())[0],
          &lda_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t, &beta1,
          &(workspace.data())[0], &incy_t);
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (linearForm_.cpp)
