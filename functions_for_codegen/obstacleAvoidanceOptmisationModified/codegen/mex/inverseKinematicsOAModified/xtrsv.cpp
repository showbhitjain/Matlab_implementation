//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xtrsv.cpp
//
// Code generation for function 'xtrsv'
//

// Include files
#include "xtrsv.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xtrsv(int32_T n, const array<real_T, 2U> &A, int32_T lda,
           array<real_T, 2U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t lda_t;
  ptrdiff_t n_t;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  if (n >= 1) {
    DIAGA1 = 'N';
    TRANSA1 = 'N';
    UPLO1 = 'U';
    n_t = (ptrdiff_t)n;
    lda_t = (ptrdiff_t)lda;
    incx_t = (ptrdiff_t)1;
    dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t,
          &(((array<real_T, 2U> *)&A)->data())[0], &lda_t, &(x.data())[0],
          &incx_t);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xtrsv.cpp)
