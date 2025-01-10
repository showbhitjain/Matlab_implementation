//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factor.cpp
//
// Code generation for function 'factor'
//

// Include files
#include "factor.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "xpotrf.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace CholManager {
void factor(const emlrtStack &sp, e_struct_T &obj, const array<real_T, 2U> &A,
            int32_T ndims, int32_T ldA)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj.ndims = ndims;
  if ((A.size(0) != 0) && (A.size(1) != 0)) {
    st.site = &ph_emlrtRSI;
    if (ndims > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < ndims; idx++) {
      st.site = &ph_emlrtRSI;
      if (ndims >= 1) {
        n_t = (ptrdiff_t)ndims;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, (real_T *)&A[ldA * idx], &incx_t, &obj.FMat[obj.ldm * idx],
              &incy_t);
      }
    }
  }
  st.site = &ph_emlrtRSI;
  obj.info = internal::lapack::xpotrf(st, ndims, obj.FMat, obj.ldm);
}

} // namespace CholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factor.cpp)
