//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgemv.cpp
//
// Code generation for function 'xgemv'
//

// Include files
#include "xgemv.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <algorithm>
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const array<real_T, 1U> &x, real_T y_data[], const int32_T &y_size)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T b_y_data[279];
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (m >= 1) {
    int32_T loop_ub;
    loop_ub = y_size;
    if (loop_ub - 1 >= 0) {
      std::copy(&y_data[0], &y_data[loop_ub], &b_y_data[0]);
    }
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 1U> *)&A)->data())[0],
          &lda_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t, &beta1,
          &b_y_data[0], &incy_t);
    if (y_size - 1 >= 0) {
      std::copy(&b_y_data[0], &b_y_data[y_size], &y_data[0]);
    }
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 2U> &A, int32_T ia0,
           int32_T lda, const array<real_T, 2U> &x, array<real_T, 1U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if (m >= 1) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, (real_T *)&A[ia0 - 1], &lda_t,
          &(((array<real_T, 2U> *)&x)->data())[0], &incx_t, &beta1,
          &(y.data())[0], &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const array<real_T, 1U> &x, array<real_T, 2U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 1U> *)&A)->data())[0],
          &lda_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t, &beta1,
          &(y.data())[0], &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 2U> &A, int32_T lda,
           const array<real_T, 1U> &x, array<real_T, 1U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 2U> *)&A)->data())[0],
          &lda_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t, &beta1,
          &(y.data())[0], &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const array<real_T, 2U> &x, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 1U> *)&A)->data())[0],
          &lda_t, &(((array<real_T, 2U> *)&x)->data())[0], &incx_t, &beta1,
          &y_data[0], &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const array<real_T, 2U> &x, int32_T ix0, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 1U> *)&A)->data())[0],
          &lda_t, (real_T *)&x[ix0 - 1], &incx_t, &beta1, &y_data[0], &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const array<real_T, 1U> &x, real_T y_data[])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = -1.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 1U> *)&A)->data())[0],
          &lda_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t, &beta1,
          &y_data[0], &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const real_T x_data[], int32_T ix0, array<real_T, 1U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 1U> *)&A)->data())[0],
          &lda_t, (real_T *)&x_data[ix0 - 1], &incx_t, &beta1, &(y.data())[0],
          &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 1U> &A, int32_T lda,
           const real_T x_data[], int32_T ix0, array<real_T, 2U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = 1.0;
    TRANSA = 'N';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 1U> *)&A)->data())[0],
          &lda_t, (real_T *)&x_data[ix0 - 1], &incx_t, &beta1, &(y.data())[0],
          &incy_t);
  }
}

void xgemv(int32_T m, int32_T n, const array<real_T, 2U> &A, int32_T lda,
           const array<real_T, 1U> &x, array<real_T, 2U> &y)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA;
  if ((m >= 1) && (n >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(((array<real_T, 2U> *)&A)->data())[0],
          &lda_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t, &beta1,
          &(y.data())[0], &incy_t);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xgemv.cpp)
