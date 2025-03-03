//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeComplError.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "computeComplError.h"
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
// Arguments    : const array<double, 1U> &fscales_lineq_constraint
//                const array<double, 1U> &xCurrent
//                int mIneq
//                const array<double, 1U> &cIneq
//                const array<int, 1U> &finiteLB
//                int mLB
//                const array<double, 2U> &lb
//                const array<int, 1U> &finiteUB
//                int mUB
//                const array<double, 2U> &ub
//                const array<double, 1U> &lambda
//                int iL0
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
double computeComplError(const array<double, 1U> &fscales_lineq_constraint,
                         const array<double, 1U> &xCurrent, int mIneq,
                         const array<double, 1U> &cIneq,
                         const array<int, 1U> &finiteLB, int mLB,
                         const array<double, 2U> &lb,
                         const array<int, 1U> &finiteUB, int mUB,
                         const array<double, 2U> &ub,
                         const array<double, 1U> &lambda, int iL0)
{
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,                  // iFirst
      -1,                  // iLast
      1,                   // lineNo
      1,                   // colNo
      "",                  // aName
      "computeComplError", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
      "+stopping/computeComplError.p", // pName
      0                                // checkKind
  };
  double b_nlpComplErrorPrime;
  double b_y_tmp;
  double lbDelta;
  double lbLambda;
  double nlpComplError;
  double nlpComplErrorPrime;
  double y_tmp;
  int i;
  int i1;
  int idx;
  int mLinIneq;
  int ubOffset;
  boolean_T b;
  boolean_T b1;
  nlpComplError = 0.0;
  mLinIneq = fscales_lineq_constraint.size(0);
  if ((mIneq + mLB) + mUB > 0) {
    if (fscales_lineq_constraint.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(fscales_lineq_constraint.size(0) < 1600)) {
      for (idx = 0; idx < mLinIneq; idx++) {
        if (idx + 1 > fscales_lineq_constraint.size(0)) {
          rtDynamicBoundsError(idx + 1, 1, fscales_lineq_constraint.size(0),
                               w_emlrtBCI);
        }
        if (idx + 1 > cIneq.size(0)) {
          rtDynamicBoundsError(idx + 1, 1, cIneq.size(0), w_emlrtBCI);
        }
        i = iL0 + idx;
        b = ((i < 1) || (i > lambda.size(0)));
        if (b) {
          rtDynamicBoundsError(i, 1, lambda.size(0), w_emlrtBCI);
        }
        y_tmp = lambda[i - 1];
        if (idx + 1 > cIneq.size(0)) {
          rtDynamicBoundsError(idx + 1, 1, cIneq.size(0), w_emlrtBCI);
        }
        nlpComplError = std::fmax(
            nlpComplError, std::fmin(std::abs(cIneq[idx] * y_tmp),
                                     std::fmin(std::abs(cIneq[idx]), y_tmp)));
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(lbDelta, lbLambda, i1, b1,  \
                                                   b_y_tmp)
      {
        lbDelta = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mLinIneq; idx++) {
          if (idx + 1 > fscales_lineq_constraint.size(0)) {
            rtDynamicBoundsError(idx + 1, 1, fscales_lineq_constraint.size(0),
                                 w_emlrtBCI);
          }
          if (idx + 1 > cIneq.size(0)) {
            rtDynamicBoundsError(idx + 1, 1, cIneq.size(0), w_emlrtBCI);
          }
          i1 = iL0 + idx;
          b1 = ((i1 < 1) || (i1 > lambda.size(0)));
          if (b1) {
            rtDynamicBoundsError(i1, 1, lambda.size(0), w_emlrtBCI);
          }
          b_y_tmp = lambda[i1 - 1];
          if (idx + 1 > cIneq.size(0)) {
            rtDynamicBoundsError(idx + 1, 1, cIneq.size(0), w_emlrtBCI);
          }
          lbLambda = cIneq[idx] * b_y_tmp;
          lbDelta = std::fmax(
              lbDelta, std::fmin(std::abs(lbLambda),
                                 std::fmin(std::abs(cIneq[idx]), b_y_tmp)));
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          nlpComplError = std::fmax(nlpComplError, lbDelta);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
    mLinIneq = iL0 + mIneq;
    ubOffset = mLinIneq + mLB;
    if (mLB > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mLB < 1600)) {
      for (idx = 0; idx < mLB; idx++) {
        if ((idx + 1 < 1) || (idx + 1 > finiteLB.size(0))) {
          rtDynamicBoundsError(idx + 1, 1, finiteLB.size(0), w_emlrtBCI);
        }
        if ((finiteLB[idx] < 1) || (finiteLB[idx] > xCurrent.size(0))) {
          rtDynamicBoundsError(finiteLB[idx], 1, xCurrent.size(0), w_emlrtBCI);
        }
        if ((finiteLB[idx] < 1) || (finiteLB[idx] > lb.size(0))) {
          rtDynamicBoundsError(finiteLB[idx], 1, lb.size(0), w_emlrtBCI);
        }
        lbDelta = xCurrent[finiteLB[idx] - 1] - lb[finiteLB[idx] - 1];
        i = mLinIneq + idx;
        if ((i < 1) || (i > lambda.size(0))) {
          rtDynamicBoundsError(i, 1, lambda.size(0), w_emlrtBCI);
        }
        lbLambda = lambda[i - 1];
        nlpComplError = std::fmax(
            nlpComplError, std::fmin(std::abs(lbDelta * lbLambda),
                                     std::fmin(std::abs(lbDelta), lbLambda)));
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(nlpComplErrorPrime,         \
                                                   lbDelta, lbLambda, i1)
      {
        nlpComplErrorPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mLB; idx++) {
          if (idx + 1 > finiteLB.size(0)) {
            rtDynamicBoundsError(idx + 1, 1, finiteLB.size(0), w_emlrtBCI);
          }
          if ((finiteLB[idx] < 1) || (finiteLB[idx] > xCurrent.size(0))) {
            rtDynamicBoundsError(finiteLB[idx], 1, xCurrent.size(0),
                                 w_emlrtBCI);
          }
          if ((finiteLB[idx] < 1) || (finiteLB[idx] > lb.size(0))) {
            rtDynamicBoundsError(finiteLB[idx], 1, lb.size(0), w_emlrtBCI);
          }
          lbDelta = xCurrent[finiteLB[idx] - 1] - lb[finiteLB[idx] - 1];
          i1 = mLinIneq + idx;
          if ((i1 < 1) || (i1 > lambda.size(0))) {
            rtDynamicBoundsError(i1, 1, lambda.size(0), w_emlrtBCI);
          }
          lbLambda = lambda[i1 - 1];
          nlpComplErrorPrime =
              std::fmax(nlpComplErrorPrime,
                        std::fmin(std::abs(lbDelta * lbLambda),
                                  std::fmin(std::abs(lbDelta), lbLambda)));
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          nlpComplError = std::fmax(nlpComplError, nlpComplErrorPrime);
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
        if ((finiteUB[idx] < 1) || (finiteUB[idx] > ub.size(0))) {
          rtDynamicBoundsError(finiteUB[idx], 1, ub.size(0), w_emlrtBCI);
        }
        if ((finiteUB[idx] < 1) || (finiteUB[idx] > xCurrent.size(0))) {
          rtDynamicBoundsError(finiteUB[idx], 1, xCurrent.size(0), w_emlrtBCI);
        }
        lbDelta = ub[finiteUB[idx] - 1] - xCurrent[finiteUB[idx] - 1];
        i = ubOffset + idx;
        if ((i < 1) || (i > lambda.size(0))) {
          rtDynamicBoundsError(i, 1, lambda.size(0), w_emlrtBCI);
        }
        lbLambda = lambda[i - 1];
        nlpComplError = std::fmax(
            nlpComplError, std::fmin(std::abs(lbDelta * lbLambda),
                                     std::fmin(std::abs(lbDelta), lbLambda)));
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(b_nlpComplErrorPrime,       \
                                                   lbDelta, lbLambda, i1)
      {
        b_nlpComplErrorPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mUB; idx++) {
          if (idx + 1 > finiteUB.size(0)) {
            rtDynamicBoundsError(idx + 1, 1, finiteUB.size(0), w_emlrtBCI);
          }
          if ((finiteUB[idx] < 1) || (finiteUB[idx] > ub.size(0))) {
            rtDynamicBoundsError(finiteUB[idx], 1, ub.size(0), w_emlrtBCI);
          }
          if ((finiteUB[idx] < 1) || (finiteUB[idx] > xCurrent.size(0))) {
            rtDynamicBoundsError(finiteUB[idx], 1, xCurrent.size(0),
                                 w_emlrtBCI);
          }
          lbDelta = ub[finiteUB[idx] - 1] - xCurrent[finiteUB[idx] - 1];
          i1 = ubOffset + idx;
          if ((i1 < 1) || (i1 > lambda.size(0))) {
            rtDynamicBoundsError(i1, 1, lambda.size(0), w_emlrtBCI);
          }
          lbLambda = lambda[i1 - 1];
          b_nlpComplErrorPrime =
              std::fmax(b_nlpComplErrorPrime,
                        std::fmin(std::abs(lbDelta * lbLambda),
                                  std::fmin(std::abs(lbDelta), lbLambda)));
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          nlpComplError = std::fmax(nlpComplError, b_nlpComplErrorPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  return nlpComplError;
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeComplError.cpp
//
// [EOF]
//
