//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factorQR.cpp
//
// Code generation for function 'factorQR'
//

// Include files
#include "factorQR.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "xgeqrf.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void factorQR(const emlrtStack &sp, e_struct_T &obj, const array<real_T, 1U> &A,
              int32_T mrows, int32_T ncols, int32_T ldA)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  boolean_T guard1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = mrows * ncols;
  guard1 = false;
  if (i > 0) {
    st.site = &hg_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < ncols; idx++) {
      st.site = &hg_emlrtRSI;
      if (mrows >= 1) {
        n_t = (ptrdiff_t)mrows;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, (real_T *)&A[ldA * idx], &incx_t, &obj.QR[obj.ldq * idx],
              &incy_t);
      }
    }
    guard1 = true;
  } else if (i == 0) {
    obj.mrows = mrows;
    obj.ncols = ncols;
    obj.minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    obj.usedPivoting = false;
    obj.mrows = mrows;
    obj.ncols = ncols;
    st.site = &hg_emlrtRSI;
    if (ncols > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < ncols; idx++) {
      i = obj.jpvt.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &vc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.jpvt[idx] = idx + 1;
    }
    obj.minRowCol = muIntScalarMin_sint32(mrows, ncols);
    st.site = &hg_emlrtRSI;
    internal::lapack::xgeqrf(st, obj.QR, mrows, ncols, obj.tau);
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factorQR.cpp)
