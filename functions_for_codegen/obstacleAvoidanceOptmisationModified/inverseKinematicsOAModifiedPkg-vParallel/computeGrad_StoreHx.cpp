//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeGrad_StoreHx.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "computeGrad_StoreHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : g_struct_T &obj
//                const array<double, 2U> &H
//                const array<double, 1U> &f
//                const array<double, 1U> &x
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void computeGrad_StoreHx(g_struct_T &obj, const array<double, 2U> &H,
                         const array<double, 1U> &f, const array<double, 1U> &x)
{
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,                    // iFirst
      -1,                    // iLast
      1,                     // lineNo
      1,                     // colNo
      "",                    // aName
      "computeGrad_StoreHx", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
      "+Objective/computeGrad_StoreHx.p", // pName
      0                                   // checkKind
  };
  int i1;
  switch (obj.objtype) {
  case 5: {
    int i;
    int ixlast;
    ixlast = obj.nvar;
    if (obj.nvar - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int idx{0}; idx <= ixlast - 2; idx++) {
      i = obj.grad.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
      }
      obj.grad[idx] = 0.0;
    }
    i = obj.grad.size(0);
    if ((obj.nvar < 1) || (obj.nvar > i)) {
      rtDynamicBoundsError(obj.nvar, 1, i, w_emlrtBCI);
    }
    obj.grad[obj.nvar - 1] = obj.gammaScalar;
  } break;
  case 3: {
    int ixlast;
    internal::blas::xgemv(obj.nvar, obj.nvar, H, obj.nvar, x, obj.Hx);
    ixlast = obj.nvar;
    if (obj.nvar > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int idx{0}; idx < ixlast; idx++) {
      int i;
      i = obj.Hx.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
      }
      i = obj.grad.size(0);
      if (idx + 1 > i) {
        rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
      }
      obj.grad[idx] = obj.Hx[idx];
    }
    if (obj.hasLinear && (obj.nvar >= 1)) {
      ixlast = obj.nvar - 1;
      if (static_cast<int>(ixlast + 1 < 1600)) {
        for (int k{0}; k <= ixlast; k++) {
          obj.grad[k] = obj.grad[k] + f[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k <= ixlast; k++) {
          obj.grad[k] = obj.grad[k] + f[k];
        }
      }
    }
  } break;
  default: {
    int i;
    int ixlast;
    int iy;
    iy = obj.maxVar - 1;
    internal::blas::xgemv(obj.nvar, obj.nvar, H, obj.nvar, x, obj.Hx);
    ixlast = obj.nvar + 1;
    if ((ixlast <= iy) && (iy > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (int idx{ixlast}; idx <= iy; idx++) {
      if ((idx < 1) || (idx > x.size(0))) {
        rtDynamicBoundsError(idx, 1, x.size(0), w_emlrtBCI);
      }
      i = obj.Hx.size(0);
      if (idx > i) {
        rtDynamicBoundsError(idx, 1, i, w_emlrtBCI);
      }
      obj.Hx[idx - 1] = obj.beta * x[idx - 1];
    }
    for (int idx{0}; idx < iy; idx++) {
      i = obj.Hx.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
      }
      i = obj.grad.size(0);
      if (idx + 1 > i) {
        rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
      }
      obj.grad[idx] = obj.Hx[idx];
    }
    if (obj.hasLinear && (obj.nvar >= 1)) {
      ixlast = obj.nvar - 1;
      if (static_cast<int>(ixlast + 1 < 1600)) {
        for (int k{0}; k <= ixlast; k++) {
          obj.grad[k] = obj.grad[k] + f[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k <= ixlast; k++) {
          obj.grad[k] = obj.grad[k] + f[k];
        }
      }
    }
    ixlast = (obj.maxVar - obj.nvar) - 1;
    if (ixlast >= 1) {
      iy = obj.nvar;
      i = ixlast - 1;
      if (static_cast<int>(ixlast < 1600)) {
        for (int k{0}; k <= i; k++) {
          ixlast = iy + k;
          obj.grad[ixlast] = obj.grad[ixlast] + obj.rho;
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16) private(i1)

        for (int k = 0; k <= i; k++) {
          i1 = iy + k;
          obj.grad[i1] = obj.grad[i1] + obj.rho;
        }
      }
    }
  } break;
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeGrad_StoreHx.cpp
//
// [EOF]
//
