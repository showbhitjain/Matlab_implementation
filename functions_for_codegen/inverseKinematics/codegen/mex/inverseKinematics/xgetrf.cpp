//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgetrf.cpp
//
// Code generation for function 'xgetrf'
//

// Include files
#include "xgetrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo ac_emlrtRSI{
    24,       // lineNo
    "ixamax", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
    "ixamax.m" // pathName
};

static emlrtRSInfo
    je_emlrtRSI{
        30,       // lineNo
        "xgetrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgetrf.m" // pathName
    };

static emlrtRSInfo ke_emlrtRSI{
    36,        // lineNo
    "xzgetrf", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" // pathName
};

static emlrtRSInfo le_emlrtRSI{
    50,        // lineNo
    "xzgetrf", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" // pathName
};

static emlrtRSInfo me_emlrtRSI{
    58,        // lineNo
    "xzgetrf", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" // pathName
};

static emlrtRSInfo
    ne_emlrtRSI{
        23,       // lineNo
        "ixamax", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "ixamax.m" // pathName
    };

static emlrtRSInfo
    oe_emlrtRSI{
        45,      // lineNo
        "xgeru", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgeru.m" // pathName
    };

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void xgetrf(const emlrtStack &sp, real_T A[36], int32_T ipiv[6])
{
  __m128i r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &je_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  r = _mm_add_epi32(_mm_set1_epi32(1),
                    _mm_add_epi32(_mm_set1_epi32(0),
                                  _mm_loadu_si128((const __m128i *)&iv[0])));
  _mm_storeu_si128((__m128i *)&ipiv[0], r);
  ipiv[4] = 5;
  ipiv[5] = 6;
  for (int32_T j{0}; j < 5; j++) {
    real_T smax;
    int32_T a;
    int32_T b_tmp;
    int32_T i;
    int32_T jA;
    int32_T jp1j;
    b_tmp = j * 7;
    jp1j = b_tmp + 2;
    jA = 6 - j;
    b_st.site = &ke_emlrtRSI;
    c_st.site = &ne_emlrtRSI;
    a = 0;
    smax = muDoubleScalarAbs(A[b_tmp]);
    d_st.site = &ac_emlrtRSI;
    for (int32_T k{2}; k <= jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (A[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = jA + 1;
        for (int32_T k{0}; k < 6; k++) {
          a = j + k * 6;
          smax = A[a];
          i = jA + k * 6;
          A[a] = A[i];
          A[i] = smax;
        }
      }
      i = (b_tmp - j) + 6;
      b_st.site = &le_emlrtRSI;
      for (a = jp1j; a <= i; a++) {
        A[a - 1] /= A[b_tmp];
      }
    }
    i = 4 - j;
    b_st.site = &me_emlrtRSI;
    c_st.site = &oe_emlrtRSI;
    d_st.site = &pe_emlrtRSI;
    e_st.site = &wb_emlrtRSI;
    jA = b_tmp + 8;
    f_st.site = &xb_emlrtRSI;
    for (jp1j = 0; jp1j <= i; jp1j++) {
      smax = A[(b_tmp + jp1j * 6) + 6];
      if (smax != 0.0) {
        a = (jA - j) + 4;
        f_st.site = &qe_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          g_st.site = &f_emlrtRSI;
          check_forloop_overflow_error(g_st);
        }
        for (int32_T k{jA}; k <= a; k++) {
          A[k - 1] += A[((b_tmp + k) - jA) + 1] * -smax;
        }
      }
      jA += 6;
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xgetrf.cpp)
