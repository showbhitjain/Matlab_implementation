//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: factorQR.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "factorQR.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include "coder_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : e_struct_T &obj
//                const array<double, 1U> &A
//                int mrows
//                int ncols
//                int ldA
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void factorQR(e_struct_T &obj, const array<double, 1U> &A, int mrows, int ncols,
              int ldA)
{
  int ix0;
  int minmana;
  int minmn;
  boolean_T guard1;
  ix0 = mrows * ncols;
  guard1 = false;
  if (ix0 > 0) {
    if (ncols > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int idx{0}; idx < ncols; idx++) {
      ix0 = ldA * idx;
      minmana = obj.ldq * idx;
      if (mrows > 2147483646) {
        check_forloop_overflow_error();
      }
      for (minmn = 0; minmn < mrows; minmn++) {
        obj.QR[minmana + minmn] = A[ix0 + minmn];
      }
    }
    guard1 = true;
  } else if (ix0 == 0) {
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
    if (ncols > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int idx{0}; idx < ncols; idx++) {
      ix0 = obj.jpvt.size(0);
      if ((idx + 1 < 1) || (idx + 1 > ix0)) {
        rtDynamicBoundsError(idx + 1, 1, ix0, m_emlrtBCI);
      }
      obj.jpvt[idx] = idx + 1;
    }
    if (mrows <= ncols) {
      minmn = mrows;
    } else {
      minmn = ncols;
    }
    obj.minRowCol = minmn;
    ix0 = obj.QR.size(0);
    minmana = obj.QR.size(1);
    if (ix0 <= minmana) {
      minmana = ix0;
    }
    obj.tau.set_size(minmana);
    if (static_cast<int>(minmana < 1600)) {
      for (int i{0}; i < minmana; i++) {
        obj.tau[i] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int i = 0; i < minmana; i++) {
        obj.tau[i] = 0.0;
      }
    }
    if (minmn >= 1) {
      internal::reflapack::qrf(obj.QR, mrows, ncols, minmn, obj.tau);
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for factorQR.cpp
//
// [EOF]
//
