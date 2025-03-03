//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeQ_.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 15:44:26
//

// Include Files
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : e_struct_T &obj
//                int nrows
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void computeQ_(e_struct_T &obj, int nrows)
{
  array<double, 2U> *A;
  array<double, 1U> work;
  int colbottom;
  int iQR0;
  int jA;
  int lastc;
  int lastv;
  int lda;
  int m;
  lastv = obj.minRowCol;
  if (obj.minRowCol > 2147483646) {
    check_forloop_overflow_error();
  }
  for (lastc = 0; lastc < lastv; lastc++) {
    iQR0 = obj.ldq * lastc + lastc;
    colbottom = (obj.mrows - lastc) - 1;
    if (colbottom > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < colbottom; k++) {
      jA = (iQR0 + k) + 1;
      obj.Q[jA] = obj.QR[jA];
    }
  }
  m = obj.mrows;
  lda = obj.ldq;
  if (nrows >= 1) {
    int itau;
    jA = nrows - 1;
    for (int k{lastv}; k <= jA; k++) {
      iQR0 = k * lda;
      colbottom = m - 1;
      for (int i{0}; i <= colbottom; i++) {
        obj.Q[iQR0 + i] = 0.0;
      }
      obj.Q[iQR0 + k] = 1.0;
    }
    itau = obj.minRowCol - 1;
    work.set_size(obj.Q.size(1));
    iQR0 = obj.Q.size(1);
    if (static_cast<int>(iQR0 < 400)) {
      for (int b_i{0}; b_i < iQR0; b_i++) {
        work[b_i] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

      for (int b_i = 0; b_i < iQR0; b_i++) {
        work[b_i] = 0.0;
      }
    }
    for (int i{obj.minRowCol}; i >= 1; i--) {
      int iaii;
      iaii = i + (i - 1) * lda;
      if (i < nrows) {
        obj.Q[iaii - 1] = 1.0;
        jA = iaii + lda;
        if (obj.tau[itau] != 0.0) {
          boolean_T exitg2;
          lastv = (m - i) + 1;
          iQR0 = (iaii + m) - i;
          while ((lastv > 0) && (obj.Q[iQR0 - 1] == 0.0)) {
            lastv--;
            iQR0--;
          }
          lastc = nrows - i;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int exitg1;
            iQR0 = jA + (lastc - 1) * lda;
            colbottom = (iQR0 + lastv) - 1;
            if ((iQR0 <= colbottom) && (colbottom > 2147483646)) {
              check_forloop_overflow_error();
            }
            do {
              exitg1 = 0;
              if (iQR0 <= colbottom) {
                if (obj.Q[iQR0 - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  iQR0++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        } else {
          lastv = 0;
          lastc = 0;
        }
        if (lastv > 0) {
          double alpha1;
          internal::blas::xgemv(lastv, lastc, obj.Q, jA, lda, obj.Q, iaii,
                                work);
          alpha1 = -obj.tau[itau];
          A = &obj.Q;
          if (!(alpha1 == 0.0)) {
            for (int k{0}; k < lastc; k++) {
              if (work[k] != 0.0) {
                double temp;
                temp = work[k] * alpha1;
                colbottom = (lastv + jA) - 1;
                if ((jA <= colbottom) && (colbottom > 2147483646)) {
                  check_forloop_overflow_error();
                }
                for (iQR0 = jA; iQR0 <= colbottom; iQR0++) {
                  (*A)[iQR0 - 1] =
                      (*A)[iQR0 - 1] + (*A)[((iaii + iQR0) - jA) - 1] * temp;
                }
              }
              jA += lda;
            }
          }
        }
      }
      if (i < m) {
        iQR0 = iaii + 1;
        colbottom = (iaii + m) - i;
        if ((iaii + 1 <= colbottom) && (colbottom > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int k{iQR0}; k <= colbottom; k++) {
          obj.Q[k - 1] = -obj.tau[itau] * obj.Q[k - 1];
        }
      }
      obj.Q[iaii - 1] = 1.0 - obj.tau[itau];
      for (int k{0}; k <= i - 2; k++) {
        obj.Q[(iaii - k) - 2] = 0.0;
      }
      itau--;
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeQ_.cpp
//
// [EOF]
//
