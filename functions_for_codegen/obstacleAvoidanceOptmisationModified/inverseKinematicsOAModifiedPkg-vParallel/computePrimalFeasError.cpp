//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computePrimalFeasError.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "computePrimalFeasError.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const array<double, 1U> &x
//                int mLinIneq
//                const array<double, 1U> &cIneq
//                int mLinEq
//                const double cEq_data[]
//                int cEq_size
//                const array<int, 1U> &finiteLB
//                int mLB
//                const array<double, 2U> &lb
//                const array<int, 1U> &finiteUB
//                int mUB
//                const array<double, 2U> &ub
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
double computePrimalFeasError(const array<double, 1U> &x, int mLinIneq,
                              const array<double, 1U> &cIneq, int mLinEq,
                              const double cEq_data[], int cEq_size,
                              const array<int, 1U> &finiteLB, int mLB,
                              const array<double, 2U> &lb,
                              const array<int, 1U> &finiteUB, int mUB,
                              const array<double, 2U> &ub)
{
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,                       // iFirst
      -1,                       // iLast
      1,                        // lineNo
      1,                        // colNo
      "",                       // aName
      "computePrimalFeasError", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
      "+stopping/computePrimalFeasError.p", // pName
      0                                     // checkKind
  };
  double b_feasErrorPrime;
  double b_x;
  double c_feasErrorPrime;
  double d_feasErrorPrime;
  double feasError;
  double feasErrorPrime;
  int idx;
  int idxFiniteLB;
  feasError = 0.0;
  if (mLinEq > 2147483646) {
    check_forloop_overflow_error();
  }
  if (static_cast<int>(mLinEq < 1600)) {
    for (idx = 0; idx < mLinEq; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > cEq_size)) {
        rtDynamicBoundsError(idx + 1, 1, cEq_size, w_emlrtBCI);
      }
      feasError = std::fmax(feasError, std::abs(cEq_data[idx]));
    }
  } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(feasErrorPrime, b_x)
    {
      feasErrorPrime = rtMinusInf;
#pragma omp for nowait
      for (idx = 0; idx < mLinEq; idx++) {
        if (idx + 1 > cEq_size) {
          rtDynamicBoundsError(idx + 1, 1, cEq_size, w_emlrtBCI);
        }
        b_x = cEq_data[idx];
        feasErrorPrime = std::fmax(feasErrorPrime, std::abs(b_x));
      }
      omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      {

        feasError = std::fmax(feasError, feasErrorPrime);
      }
      omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
    }
  }
  if (mLinIneq > 2147483646) {
    check_forloop_overflow_error();
  }
  if (static_cast<int>(mLinIneq < 1600)) {
    for (idx = 0; idx < mLinIneq; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > cIneq.size(0))) {
        rtDynamicBoundsError(idx + 1, 1, cIneq.size(0), w_emlrtBCI);
      }
      feasError = std::fmax(feasError, cIneq[idx]);
    }
  } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(b_feasErrorPrime)
    {
      b_feasErrorPrime = rtMinusInf;
#pragma omp for nowait
      for (idx = 0; idx < mLinIneq; idx++) {
        if (idx + 1 > cIneq.size(0)) {
          rtDynamicBoundsError(idx + 1, 1, cIneq.size(0), w_emlrtBCI);
        }
        b_feasErrorPrime = std::fmax(b_feasErrorPrime, cIneq[idx]);
      }
      omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      {

        feasError = std::fmax(feasError, b_feasErrorPrime);
      }
      omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
    }
  }
  if (mLB > 2147483646) {
    check_forloop_overflow_error();
  }
  if (static_cast<int>(mLB < 1600)) {
    for (idx = 0; idx < mLB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > finiteLB.size(0))) {
        rtDynamicBoundsError(idx + 1, 1, finiteLB.size(0), w_emlrtBCI);
      }
      idxFiniteLB = finiteLB[idx] - 1;
      if ((finiteLB[idx] < 1) || (finiteLB[idx] > lb.size(0))) {
        rtDynamicBoundsError(finiteLB[idx], 1, lb.size(0), w_emlrtBCI);
      }
      if ((finiteLB[idx] < 1) || (finiteLB[idx] > x.size(0))) {
        rtDynamicBoundsError(finiteLB[idx], 1, x.size(0), w_emlrtBCI);
      }
      feasError = std::fmax(feasError, lb[idxFiniteLB] - x[idxFiniteLB]);
    }
  } else {
#pragma omp parallel num_threads(                                              \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(c_feasErrorPrime, idxFiniteLB)
    {
      c_feasErrorPrime = rtMinusInf;
#pragma omp for nowait
      for (idx = 0; idx < mLB; idx++) {
        if (idx + 1 > finiteLB.size(0)) {
          rtDynamicBoundsError(idx + 1, 1, finiteLB.size(0), w_emlrtBCI);
        }
        idxFiniteLB = finiteLB[idx] - 1;
        if ((finiteLB[idx] < 1) || (finiteLB[idx] > lb.size(0))) {
          rtDynamicBoundsError(finiteLB[idx], 1, lb.size(0), w_emlrtBCI);
        }
        if ((finiteLB[idx] < 1) || (finiteLB[idx] > x.size(0))) {
          rtDynamicBoundsError(finiteLB[idx], 1, x.size(0), w_emlrtBCI);
        }
        c_feasErrorPrime =
            std::fmax(c_feasErrorPrime, lb[idxFiniteLB] - x[idxFiniteLB]);
      }
      omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      {

        feasError = std::fmax(feasError, c_feasErrorPrime);
      }
      omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
    }
  }
  if (mUB > 2147483646) {
    check_forloop_overflow_error();
  }
  if (static_cast<int>(mUB < 1600)) {
    for (idx = 0; idx < mUB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > finiteUB.size(0))) {
        rtDynamicBoundsError(idx + 1, 1, finiteUB.size(0), w_emlrtBCI);
      }
      idxFiniteLB = finiteUB[idx] - 1;
      if ((finiteUB[idx] < 1) || (finiteUB[idx] > x.size(0))) {
        rtDynamicBoundsError(finiteUB[idx], 1, x.size(0), w_emlrtBCI);
      }
      if ((finiteUB[idx] < 1) || (finiteUB[idx] > ub.size(0))) {
        rtDynamicBoundsError(finiteUB[idx], 1, ub.size(0), w_emlrtBCI);
      }
      feasError = std::fmax(feasError, x[idxFiniteLB] - ub[idxFiniteLB]);
    }
  } else {
#pragma omp parallel num_threads(                                              \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(d_feasErrorPrime, idxFiniteLB)
    {
      d_feasErrorPrime = rtMinusInf;
#pragma omp for nowait
      for (idx = 0; idx < mUB; idx++) {
        if (idx + 1 > finiteUB.size(0)) {
          rtDynamicBoundsError(idx + 1, 1, finiteUB.size(0), w_emlrtBCI);
        }
        idxFiniteLB = finiteUB[idx] - 1;
        if ((finiteUB[idx] < 1) || (finiteUB[idx] > x.size(0))) {
          rtDynamicBoundsError(finiteUB[idx], 1, x.size(0), w_emlrtBCI);
        }
        if ((finiteUB[idx] < 1) || (finiteUB[idx] > ub.size(0))) {
          rtDynamicBoundsError(finiteUB[idx], 1, ub.size(0), w_emlrtBCI);
        }
        d_feasErrorPrime =
            std::fmax(d_feasErrorPrime, x[idxFiniteLB] - ub[idxFiniteLB]);
      }
      omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      {

        feasError = std::fmax(feasError, d_feasErrorPrime);
      }
      omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
    }
  }
  return feasError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computePrimalFeasError.cpp
//
// [EOF]
//
