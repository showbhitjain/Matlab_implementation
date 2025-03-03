//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mtimes.cpp
//
// Code generation for function 'mtimes'
//

// Include files
#include "mtimes.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    x_emlrtRSI{
        178,           // lineNo
        "mtimes_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRTEInfo
    qc_emlrtRTEI{
        218,      // lineNo
        20,       // colNo
        "mtimes", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pName
    };

static emlrtRTEInfo
    rc_emlrtRTEI{
        140,      // lineNo
        5,        // colNo
        "mtimes", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pName
    };

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void mtimes(const emlrtStack &sp, const array<real_T, 2U> &B,
            array<real_T, 2U> &C)
{
  static const real_T A[36]{1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (B.size(1) == 0) {
    C.set_size(&rc_emlrtRTEI, &sp, 6, 0);
  } else {
    st.site = &w_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)B.size(1);
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)6;
    C.set_size(&qc_emlrtRTEI, &b_st, 6, B.size(1));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[0],
          &lda_t, &(((array<real_T, 2U> *)&B)->data())[0], &ldb_t, &beta1,
          &(C.data())[0], &ldc_t);
  }
}

void mtimes(const emlrtStack &sp, const array<real_T, 1U> &A,
            const array<real_T, 2U> &B, array<real_T, 2U> &C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((A.size(0) == 0) || (B.size(0) == 0) || (B.size(1) == 0)) {
    int32_T loop_ub;
    C.set_size(&rc_emlrtRTEI, &sp, 1, B.size(1));
    loop_ub = B.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      C[i] = 0.0;
    }
  } else {
    st.site = &w_emlrtRSI;
    b_st.site = &x_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)B.size(1);
    k_t = (ptrdiff_t)A.size(0);
    lda_t = (ptrdiff_t)A.size(0);
    ldb_t = (ptrdiff_t)B.size(0);
    ldc_t = (ptrdiff_t)1;
    C.set_size(&qc_emlrtRTEI, &b_st, 1, B.size(1));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
          &(((array<real_T, 1U> *)&A)->data())[0], &lda_t,
          &(((array<real_T, 2U> *)&B)->data())[0], &ldb_t, &beta1, &C[0],
          &ldc_t);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (mtimes.cpp)
