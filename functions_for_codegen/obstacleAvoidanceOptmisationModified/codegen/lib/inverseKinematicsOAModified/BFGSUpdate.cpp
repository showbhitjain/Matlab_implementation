//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: BFGSUpdate.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 15:44:26
//

// Include Files
#include "BFGSUpdate.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : int nvar
//                array<double, 2U> &Bk
//                const array<double, 1U> &sk
//                array<double, 1U> &yk
//                array<double, 2U> &workspace
// Return Type  : boolean_T
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
boolean_T BFGSUpdate(int nvar, array<double, 2U> &Bk,
                     const array<double, 1U> &sk, array<double, 1U> &yk,
                     array<double, 2U> &workspace)
{
  double curvatureS;
  double dotSY;
  double theta;
  int b;
  int b_tmp;
  int ijA;
  int ix;
  int ldBk;
  boolean_T success;
  ldBk = Bk.size(0);
  dotSY = 0.0;
  if (nvar >= 1) {
    if (nvar > 2147483646) {
      check_forloop_overflow_error();
    }
    for (ix = 0; ix < nvar; ix++) {
      dotSY += sk[ix] * yk[ix];
    }
  }
  if (nvar != 0) {
    boolean_T overflow;
    if (static_cast<int>(nvar < 400)) {
      for (int iy{0}; iy < nvar; iy++) {
        workspace[iy] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

      for (int iy = 0; iy < nvar; iy++) {
        workspace[iy] = 0.0;
      }
    }
    ix = 0;
    b_tmp = Bk.size(0) * (nvar - 1) + 1;
    if ((Bk.size(0) == 0) || (b_tmp < 1)) {
      overflow = false;
    } else {
      overflow = (b_tmp > MAX_int32_T - Bk.size(0));
    }
    if (Bk.size(0) == 0) {
      m_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
    }
    if (overflow) {
      check_forloop_overflow_error();
    }
    for (int iac{1}; ldBk < 0 ? iac >= b_tmp : iac <= b_tmp; iac += ldBk) {
      b = (iac + nvar) - 1;
      if ((iac <= b) && (b > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int ia{iac}; ia <= b; ia++) {
        ijA = ia - iac;
        workspace[ijA] = workspace[ijA] + Bk[ia - 1] * sk[ix];
      }
      ix++;
    }
  }
  curvatureS = 0.0;
  if (nvar >= 1) {
    for (ix = 0; ix < nvar; ix++) {
      curvatureS += sk[ix] * workspace[ix];
    }
  }
  if (dotSY < 0.2 * curvatureS) {
    theta = 0.8 * curvatureS / (curvatureS - dotSY);
    ijA = (nvar < 400);
    if (ijA) {
      for (int iy{0}; iy < nvar; iy++) {
        yk[iy] = theta * yk[iy];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

      for (int iy = 0; iy < nvar; iy++) {
        yk[iy] = theta * yk[iy];
      }
    }
    if ((nvar >= 1) && (!(1.0 - theta == 0.0))) {
      ix = nvar - 1;
      if (ijA) {
        for (int iy{0}; iy <= ix; iy++) {
          yk[iy] = yk[iy] + (1.0 - theta) * workspace[iy];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

        for (int iy = 0; iy <= ix; iy++) {
          yk[iy] = yk[iy] + (1.0 - theta) * workspace[iy];
        }
      }
    }
    dotSY = 0.0;
    if (nvar >= 1) {
      for (ix = 0; ix < nvar; ix++) {
        dotSY += sk[ix] * yk[ix];
      }
    }
  }
  if ((curvatureS > 2.2204460492503131E-16) &&
      (dotSY > 2.2204460492503131E-16)) {
    success = true;
  } else {
    success = false;
  }
  if (success) {
    curvatureS = -1.0 / curvatureS;
    if (!(curvatureS == 0.0)) {
      ix = 1;
      for (b_tmp = 0; b_tmp < nvar; b_tmp++) {
        if (workspace[b_tmp] != 0.0) {
          theta = workspace[b_tmp] * curvatureS;
          b = (nvar + ix) - 1;
          if ((ix <= b) && (b > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (ijA = ix; ijA <= b; ijA++) {
            Bk[ijA - 1] = Bk[ijA - 1] + workspace[ijA - ix] * theta;
          }
        }
        ix += ldBk;
      }
    }
    curvatureS = 1.0 / dotSY;
    if (!(curvatureS == 0.0)) {
      ix = 1;
      for (b_tmp = 0; b_tmp < nvar; b_tmp++) {
        theta = yk[b_tmp];
        if (theta != 0.0) {
          theta *= curvatureS;
          b = (nvar + ix) - 1;
          if ((ix <= b) && (b > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (ijA = ix; ijA <= b; ijA++) {
            Bk[ijA - 1] = Bk[ijA - 1] + yk[ijA - ix] * theta;
          }
        }
        ix += ldBk;
      }
    }
  }
  return success;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for BFGSUpdate.cpp
//
// [EOF]
//
