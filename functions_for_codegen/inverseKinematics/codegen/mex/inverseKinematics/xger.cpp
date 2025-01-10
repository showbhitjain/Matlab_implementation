//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xger.cpp
//
// Code generation for function 'xger'
//

// Include files
#include "xger.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>
#include <emmintrin.h>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xger(const emlrtStack &sp, int32_T m, int32_T n, real_T alpha1, real_T x,
          real_T y, array<real_T, 2U> &A, int32_T ia0, int32_T lda)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &pe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &wb_emlrtRSI;
  if (!(alpha1 == 0.0)) {
    int32_T jA;
    jA = ia0;
    c_st.site = &xb_emlrtRSI;
    if (n > 2147483646) {
      d_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(d_st);
    }
    for (int32_T j{0}; j < n; j++) {
      if (y != 0.0) {
        real_T temp;
        int32_T b;
        int32_T scalarLB;
        int32_T vectorUB;
        temp = y * alpha1;
        b = (m + jA) - 1;
        c_st.site = &qe_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          d_st.site = &f_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        scalarLB = ((((b - jA) + 1) / 2) << 1) + jA;
        vectorUB = scalarLB - 2;
        for (int32_T ijA{jA}; ijA <= vectorUB; ijA += 2) {
          __m128d r;
          r = _mm_loadu_pd(&A[ijA - 1]);
          _mm_storeu_pd(&A[ijA - 1], _mm_add_pd(r, _mm_set1_pd(x * temp)));
        }
        for (int32_T ijA{scalarLB}; ijA <= b; ijA++) {
          A[ijA - 1] = A[ijA - 1] + x * temp;
        }
      }
      jA += lda;
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xger.cpp)
