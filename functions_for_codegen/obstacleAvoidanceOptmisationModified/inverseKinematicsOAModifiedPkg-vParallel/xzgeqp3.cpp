//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "xzgeqp3.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : array<double, 2U> &A
//                int m
//                int n
//                int nfxd
//                array<double, 1U> &tau
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void qrf(array<double, 2U> &A, int m, int n, int nfxd, array<double, 1U> &tau)
{
  array<double, 1U> work;
  double atmp;
  int ii;
  int lda;
  lda = A.size(0);
  work.set_size(A.size(1));
  ii = A.size(1);
  if (static_cast<int>(ii < 1600)) {
    for (int i{0}; i < ii; i++) {
      work[i] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int i = 0; i < ii; i++) {
      work[i] = 0.0;
    }
  }
  if (nfxd > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int b_i{0}; b_i < nfxd; b_i++) {
    double d;
    int mmi;
    ii = b_i * lda + b_i;
    mmi = m - b_i;
    if (b_i + 1 < m) {
      atmp = A[ii];
      d = xzlarfg(mmi, atmp, A, ii + 2);
      tau[b_i] = d;
      A[ii] = atmp;
    } else {
      d = 0.0;
      tau[b_i] = 0.0;
    }
    if (b_i + 1 < n) {
      atmp = A[ii];
      A[ii] = 1.0;
      xzlarf(mmi, (n - b_i) - 1, ii + 1, d, A, (ii + lda) + 1, lda, work);
      A[ii] = atmp;
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzgeqp3.cpp
//
// [EOF]
//
