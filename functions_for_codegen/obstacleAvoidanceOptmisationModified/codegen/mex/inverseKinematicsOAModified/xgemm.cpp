//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemm.cpp
//
// Code generation for function 'xgemm'
//

// Include files
#include "xgemm.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo
    wh_emlrtRSI{
        63,      // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    xh_emlrtRSI{
        70,      // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    yh_emlrtRSI{
        71,      // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    ai_emlrtRSI{
        125,     // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    bi_emlrtRSI{
        128,     // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    ci_emlrtRSI{
        135,     // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xgemm(const emlrtStack &sp, int32_T m, int32_T n, real_T A, real_T B,
           int32_T ldb, array<real_T, 2U> &C, int32_T ic0, int32_T ldc)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &wh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m != 0) && (n != 0)) {
    int32_T Coffset;
    int32_T b;
    int32_T br;
    int32_T lastColC;
    Coffset = ic0 - 1;
    lastColC = (ic0 + ldc * (n - 1)) - 1;
    b_st.site = &xh_emlrtRSI;
    if ((ic0 - 1 <= lastColC) && (lastColC > MAX_int32_T - ldc)) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (int32_T cr{Coffset}; ldc < 0 ? cr >= lastColC : cr <= lastColC;
         cr += ldc) {
      b = cr + m;
      b_st.site = &yh_emlrtRSI;
      if ((cr + 1 <= b) && (b > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
    }
    br = 0;
    b_st.site = &ai_emlrtRSI;
    for (int32_T cr{Coffset}; ldc < 0 ? cr >= lastColC : cr <= lastColC;
         cr += ldc) {
      br++;
      b = br + ldb * 47;
      b_st.site = &bi_emlrtRSI;
      if ((br <= b) && (b > MAX_int32_T - ldb)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T ib{br}; ldb < 0 ? ib >= b : ib <= b; ib += ldb) {
        int32_T a;
        int32_T b_b;
        int32_T scalarLB;
        int32_T vectorUB;
        a = cr + 1;
        b_b = cr + m;
        b_st.site = &ci_emlrtRSI;
        if ((cr + 1 <= b_b) && (b_b > 2147483646)) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        scalarLB = ((((b_b - cr) / 2) << 1) + cr) + 1;
        vectorUB = scalarLB - 2;
        for (int32_T ic{a}; ic <= vectorUB; ic += 2) {
          __m128d r;
          r = _mm_loadu_pd(&C[ic - 1]);
          _mm_storeu_pd(&C[ic - 1], _mm_add_pd(r, _mm_set1_pd(-B * A)));
        }
        for (int32_T ic{scalarLB}; ic <= b_b; ic++) {
          C[ic - 1] = C[ic - 1] + -B * A;
        }
      }
    }
  }
}

void xgemm(int32_T m, int32_T n, int32_T k, const array<real_T, 2U> &A,
           int32_T ia0, int32_T lda, const array<real_T, 2U> &B, int32_T ldb,
           array<real_T, 2U> &C, int32_T ldc)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((m >= 1) && (n >= 1) && (k >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    ldc_t = (ptrdiff_t)ldc;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[ia0 - 1],
          &lda_t, &(((array<real_T, 2U> *)&B)->data())[0], &ldb_t, &beta1,
          &(C.data())[0], &ldc_t);
  }
}

void xgemm(int32_T m, int32_T n, int32_T k, const array<real_T, 2U> &A,
           int32_T lda, const array<real_T, 2U> &B, int32_T ib0, int32_T ldb,
           array<real_T, 2U> &C, int32_T ldc)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((m >= 1) && (n >= 1) && (k >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)lda;
    ldb_t = (ptrdiff_t)ldb;
    ldc_t = (ptrdiff_t)ldc;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
          &(((array<real_T, 2U> *)&A)->data())[0], &lda_t,
          (real_T *)&B[ib0 - 1], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xgemm.cpp)
