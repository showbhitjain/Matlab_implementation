//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: maxConstraintViolation.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "maxConstraintViolation.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>

// Variable Definitions
static rtBoundsCheckInfo n_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    1,                                           // lineNo
    1,                                           // colNo
    "",                                          // aName
    "maxConstraintViolation_AMats_regularized_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_regularized_.p", // pName
    0                                                          // checkKind
};

static rtBoundsCheckInfo o_emlrtBCI{
    -1,                                             // iFirst
    -1,                                             // iLast
    1,                                              // lineNo
    1,                                              // colNo
    "",                                             // aName
    "maxConstraintViolation_AMats_nonregularized_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_nonregularized_.p", // pName
    0                                                             // checkKind
};

static rtBoundsCheckInfo p_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    1,                        // lineNo
    1,                        // colNo
    "",                       // aName
    "maxConstraintViolation", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation.p", // pName
    0                                       // checkKind
};

// Function Definitions
//
// Arguments    : d_struct_T &obj
//                const array<double, 2U> &x
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
double maxConstraintViolation(d_struct_T &obj, const array<double, 2U> &x)
{
  double b_vPrime;
  double c_vPrime;
  double d_vPrime;
  double e_vPrime;
  double v;
  double vPrime;
  int b_idx;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int idx;
  int idxLB;
  int mEq;
  int mFixed;
  int mIneq;
  int mLB;
  int mUB;
  int offsetEq2;
  mLB = obj.sizes[3];
  mUB = obj.sizes[4];
  mFixed = obj.sizes[0];
  if (obj.probType == 2) {
    v = 0.0;
    mIneq = obj.sizes[2] - 1;
    mEq = obj.sizes[1] - 1;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (static_cast<int>(mIneq + 1 < 1600)) {
        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      }
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[2], obj.Aineq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_idx = 0; b_idx <= mIneq; b_idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        i = x.size(0) * x.size(1);
        i2 = (obj.nVarOrig + b_idx) + 1;
        if ((i2 < 1) || (i2 > i)) {
          rtDynamicBoundsError(i2, 1, i, n_emlrtBCI);
        }
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        obj.maxConstrWorkspace[b_idx] =
            obj.maxConstrWorkspace[b_idx] - x[i2 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        v = std::fmax(v, obj.maxConstrWorkspace[b_idx]);
      }
    }
    if (obj.Aeq.size(0) != 0) {
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (mIneq = 0; mIneq <= mEq; mIneq++) {
        obj.maxConstrWorkspace[mIneq] = obj.beq.data[mIneq];
      }
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      mIneq = obj.nVarOrig + obj.sizes[2];
      offsetEq2 = mIneq + obj.sizes[1];
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_idx = 0; b_idx <= mEq; b_idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        i = x.size(0) * x.size(1);
        i2 = (mIneq + b_idx) + 1;
        if ((i2 < 1) || (i2 > i)) {
          rtDynamicBoundsError(i2, 1, i, n_emlrtBCI);
        }
        i3 = (offsetEq2 + b_idx) + 1;
        if ((i3 < 1) || (i3 > i)) {
          rtDynamicBoundsError(i3, 1, i, n_emlrtBCI);
        }
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        obj.maxConstrWorkspace[b_idx] =
            (obj.maxConstrWorkspace[b_idx] - x[i2 - 1]) + x[i3 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        v = std::fmax(v, std::abs(obj.maxConstrWorkspace[b_idx]));
      }
    }
  } else {
    v = 0.0;
    mIneq = obj.sizes[2] - 1;
    mEq = obj.sizes[1] - 1;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      i = (mIneq + 1 < 1600);
      if (i) {
        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      }
      internal::blas::xgemv(obj.nVar, obj.sizes[2], obj.Aineq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (i) {
        for (idx = 0; idx <= mIneq; idx++) {
          i = obj.maxConstrWorkspace.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            rtDynamicBoundsError(idx + 1, 1, i, o_emlrtBCI);
          }
          v = std::fmax(v, obj.maxConstrWorkspace[idx]);
        }
      } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(d_vPrime, i1)
        {
          d_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx <= mIneq; idx++) {
            i1 = obj.maxConstrWorkspace.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i1)) {
              rtDynamicBoundsError(idx + 1, 1, i1, o_emlrtBCI);
            }
            d_vPrime = std::fmax(d_vPrime, obj.maxConstrWorkspace[idx]);
          }
          omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
          {

            v = std::fmax(v, d_vPrime);
          }
          omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        }
      }
    }
    if (obj.Aeq.size(0) != 0) {
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (mIneq = 0; mIneq <= mEq; mIneq++) {
        obj.maxConstrWorkspace[mIneq] = obj.beq.data[mIneq];
      }
      internal::blas::xgemv(obj.nVar, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (static_cast<int>(mEq + 1 < 1600)) {
        for (idx = 0; idx <= mEq; idx++) {
          i = obj.maxConstrWorkspace.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            rtDynamicBoundsError(idx + 1, 1, i, o_emlrtBCI);
          }
          v = std::fmax(v, std::abs(obj.maxConstrWorkspace[idx]));
        }
      } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(b_vPrime, d_vPrime, i1)
        {
          b_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx <= mEq; idx++) {
            i1 = obj.maxConstrWorkspace.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i1)) {
              rtDynamicBoundsError(idx + 1, 1, i1, o_emlrtBCI);
            }
            d_vPrime = obj.maxConstrWorkspace[idx];
            b_vPrime = std::fmax(b_vPrime, std::abs(d_vPrime));
          }
          omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
          {

            v = std::fmax(v, b_vPrime);
          }
          omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        }
      }
    }
  }
  if (obj.sizes[3] > 0) {
    if (obj.sizes[3] > 2147483646) {
      check_forloop_overflow_error();
    }
    i1 = x.size(0) * x.size(1);
    if (static_cast<int>(mLB < 1600)) {
      for (idx = 0; idx < mLB; idx++) {
        i = obj.indexLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        idxLB = obj.indexLB[idx] - 1;
        if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i1)) {
          rtDynamicBoundsError(obj.indexLB[idx], 1, i1, p_emlrtBCI);
        }
        i = obj.lb.size(0);
        if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i)) {
          rtDynamicBoundsError(obj.indexLB[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, -x[idxLB] - obj.lb[idxLB]);
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(vPrime, idxLB, i4)          \
    firstprivate(i1)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mLB; idx++) {
          i4 = obj.indexLB.size(0);
          if (idx + 1 > i4) {
            rtDynamicBoundsError(idx + 1, 1, i4, p_emlrtBCI);
          }
          idxLB = obj.indexLB[idx] - 1;
          if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i1)) {
            rtDynamicBoundsError(obj.indexLB[idx], 1, i1, p_emlrtBCI);
          }
          i4 = obj.lb.size(0);
          if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i4)) {
            rtDynamicBoundsError(obj.indexLB[idx], 1, i4, p_emlrtBCI);
          }
          vPrime = std::fmax(vPrime, -x[idxLB] - obj.lb[idxLB]);
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  if (obj.sizes[4] > 0) {
    if (obj.sizes[4] > 2147483646) {
      check_forloop_overflow_error();
    }
    i1 = x.size(0) * x.size(1);
    if (static_cast<int>(mUB < 1600)) {
      for (idx = 0; idx < mUB; idx++) {
        i = obj.indexUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        idxLB = obj.indexUB[idx] - 1;
        if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i1)) {
          rtDynamicBoundsError(obj.indexUB[idx], 1, i1, p_emlrtBCI);
        }
        i = obj.ub.size(0);
        if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i)) {
          rtDynamicBoundsError(obj.indexUB[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, x[idxLB] - obj.ub[idxLB]);
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(c_vPrime, idxLB, i4)        \
    firstprivate(i1)
      {
        c_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mUB; idx++) {
          i4 = obj.indexUB.size(0);
          if (idx + 1 > i4) {
            rtDynamicBoundsError(idx + 1, 1, i4, p_emlrtBCI);
          }
          idxLB = obj.indexUB[idx] - 1;
          if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i1)) {
            rtDynamicBoundsError(obj.indexUB[idx], 1, i1, p_emlrtBCI);
          }
          i4 = obj.ub.size(0);
          if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i4)) {
            rtDynamicBoundsError(obj.indexUB[idx], 1, i4, p_emlrtBCI);
          }
          c_vPrime = std::fmax(c_vPrime, x[idxLB] - obj.ub[idxLB]);
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, c_vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  if (obj.sizes[0] > 0) {
    if (obj.sizes[0] > 2147483646) {
      check_forloop_overflow_error();
    }
    i1 = x.size(0) * x.size(1);
    if (static_cast<int>(mFixed < 1600)) {
      for (idx = 0; idx < mFixed; idx++) {
        i = obj.indexFixed.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i1)) {
          rtDynamicBoundsError(obj.indexFixed[idx], 1, i1, p_emlrtBCI);
        }
        i = obj.ub.size(0);
        if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i)) {
          rtDynamicBoundsError(obj.indexFixed[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, std::abs(x[obj.indexFixed[idx] - 1] -
                                  obj.ub[obj.indexFixed[idx] - 1]));
      }
    } else {
#pragma omp parallel num_threads(                                              \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(e_vPrime, i4) firstprivate(i1)
      {
        e_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mFixed; idx++) {
          i4 = obj.indexFixed.size(0);
          if (idx + 1 > i4) {
            rtDynamicBoundsError(idx + 1, 1, i4, p_emlrtBCI);
          }
          if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i1)) {
            rtDynamicBoundsError(obj.indexFixed[idx], 1, i1, p_emlrtBCI);
          }
          i4 = obj.ub.size(0);
          if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i4)) {
            rtDynamicBoundsError(obj.indexFixed[idx], 1, i4, p_emlrtBCI);
          }
          e_vPrime =
              std::fmax(e_vPrime, std::abs(x[obj.indexFixed[idx] - 1] -
                                           obj.ub[obj.indexFixed[idx] - 1]));
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, e_vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  return v;
}

//
// Arguments    : d_struct_T &obj
//                const array<double, 2U> &x
//                int ix0
// Return Type  : double
//
double maxConstraintViolation(d_struct_T &obj, const array<double, 2U> &x,
                              int ix0)
{
  double b_vPrime;
  double c_vPrime;
  double d_vPrime;
  double e_vPrime;
  double v;
  double vPrime;
  int b_idx;
  int i;
  int i1;
  int i2;
  int i3;
  int idx;
  int k;
  int mEq;
  int mFixed;
  int mIneq;
  int mLB;
  int mUB;
  int offsetEq2;
  mLB = obj.sizes[3];
  mUB = obj.sizes[4];
  mFixed = obj.sizes[0];
  if (obj.probType == 2) {
    v = 0.0;
    mIneq = obj.sizes[2] - 1;
    mEq = obj.sizes[1] - 1;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (static_cast<int>(mIneq + 1 < 1600)) {
        for (k = 0; k <= mIneq; k++) {
          obj.maxConstrWorkspace[k] = obj.bineq[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (k = 0; k <= mIneq; k++) {
          obj.maxConstrWorkspace[k] = obj.bineq[k];
        }
      }
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[2], obj.Aineq, obj.ldA, x,
                            ix0, obj.maxConstrWorkspace);
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_idx = 0; b_idx <= mIneq; b_idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        i = x.size(0) * x.size(1);
        i1 = (ix0 + obj.nVarOrig) + b_idx;
        if ((i1 < 1) || (i1 > i)) {
          rtDynamicBoundsError(i1, 1, i, n_emlrtBCI);
        }
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        obj.maxConstrWorkspace[b_idx] =
            obj.maxConstrWorkspace[b_idx] - x[i1 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        v = std::fmax(v, obj.maxConstrWorkspace[b_idx]);
      }
    }
    if (obj.Aeq.size(0) != 0) {
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (mIneq = 0; mIneq <= mEq; mIneq++) {
        obj.maxConstrWorkspace[mIneq] = obj.beq.data[mIneq];
      }
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            ix0, obj.maxConstrWorkspace);
      mIneq = (obj.nVarOrig + obj.sizes[2]) - 1;
      offsetEq2 = mIneq + obj.sizes[1];
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_idx = 0; b_idx <= mEq; b_idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        i = x.size(0) * x.size(1);
        i1 = ((ix0 + mIneq) + b_idx) + 1;
        if ((i1 < 1) || (i1 > i)) {
          rtDynamicBoundsError(i1, 1, i, n_emlrtBCI);
        }
        i2 = ((ix0 + offsetEq2) + b_idx) + 1;
        if ((i2 < 1) || (i2 > i)) {
          rtDynamicBoundsError(i2, 1, i, n_emlrtBCI);
        }
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        obj.maxConstrWorkspace[b_idx] =
            (obj.maxConstrWorkspace[b_idx] - x[i1 - 1]) + x[i2 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        v = std::fmax(v, std::abs(obj.maxConstrWorkspace[b_idx]));
      }
    }
  } else {
    v = 0.0;
    mIneq = obj.sizes[2] - 1;
    mEq = obj.sizes[1] - 1;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      i = (mIneq + 1 < 1600);
      if (i) {
        for (k = 0; k <= mIneq; k++) {
          obj.maxConstrWorkspace[k] = obj.bineq[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (k = 0; k <= mIneq; k++) {
          obj.maxConstrWorkspace[k] = obj.bineq[k];
        }
      }
      internal::blas::xgemv(obj.nVar, obj.sizes[2], obj.Aineq, obj.ldA, x, ix0,
                            obj.maxConstrWorkspace);
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (i) {
        for (idx = 0; idx <= mIneq; idx++) {
          i = obj.maxConstrWorkspace.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            rtDynamicBoundsError(idx + 1, 1, i, o_emlrtBCI);
          }
          v = std::fmax(v, obj.maxConstrWorkspace[idx]);
        }
      } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(d_vPrime, i3)
        {
          d_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx <= mIneq; idx++) {
            i3 = obj.maxConstrWorkspace.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i3)) {
              rtDynamicBoundsError(idx + 1, 1, i3, o_emlrtBCI);
            }
            d_vPrime = std::fmax(d_vPrime, obj.maxConstrWorkspace[idx]);
          }
          omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
          {

            v = std::fmax(v, d_vPrime);
          }
          omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        }
      }
    }
    if (obj.Aeq.size(0) != 0) {
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (mIneq = 0; mIneq <= mEq; mIneq++) {
        obj.maxConstrWorkspace[mIneq] = obj.beq.data[mIneq];
      }
      internal::blas::xgemv(obj.nVar, obj.sizes[1], obj.Aeq, obj.ldA, x, ix0,
                            obj.maxConstrWorkspace);
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (static_cast<int>(mEq + 1 < 1600)) {
        for (idx = 0; idx <= mEq; idx++) {
          i = obj.maxConstrWorkspace.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            rtDynamicBoundsError(idx + 1, 1, i, o_emlrtBCI);
          }
          v = std::fmax(v, std::abs(obj.maxConstrWorkspace[idx]));
        }
      } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(c_vPrime, d_vPrime, i3)
        {
          c_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx <= mEq; idx++) {
            i3 = obj.maxConstrWorkspace.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i3)) {
              rtDynamicBoundsError(idx + 1, 1, i3, o_emlrtBCI);
            }
            d_vPrime = obj.maxConstrWorkspace[idx];
            c_vPrime = std::fmax(c_vPrime, std::abs(d_vPrime));
          }
          omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
          {

            v = std::fmax(v, c_vPrime);
          }
          omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        }
      }
    }
  }
  if (obj.sizes[3] > 0) {
    if (obj.sizes[3] > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mLB < 1600)) {
      for (idx = 0; idx < mLB; idx++) {
        i = obj.indexLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        i = x.size(0) * x.size(1);
        i1 = (ix0 + obj.indexLB[idx]) - 1;
        if ((i1 < 1) || (i1 > i)) {
          rtDynamicBoundsError(i1, 1, i, p_emlrtBCI);
        }
        i = obj.lb.size(0);
        if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i)) {
          rtDynamicBoundsError(obj.indexLB[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, -x[i1 - 1] - obj.lb[obj.indexLB[idx] - 1]);
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(vPrime, d_vPrime, i3, k)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mLB; idx++) {
          i3 = obj.indexLB.size(0);
          if (idx + 1 > i3) {
            rtDynamicBoundsError(idx + 1, 1, i3, p_emlrtBCI);
          }
          i3 = x.size(0) * x.size(1);
          k = (ix0 + obj.indexLB[idx]) - 1;
          if ((k < 1) || (k > i3)) {
            rtDynamicBoundsError(k, 1, i3, p_emlrtBCI);
          }
          i3 = obj.lb.size(0);
          if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i3)) {
            rtDynamicBoundsError(obj.indexLB[idx], 1, i3, p_emlrtBCI);
          }
          d_vPrime = -x[k - 1] - obj.lb[obj.indexLB[idx] - 1];
          vPrime = std::fmax(vPrime, d_vPrime);
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  if (obj.sizes[4] > 0) {
    if (obj.sizes[4] > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mUB < 1600)) {
      for (idx = 0; idx < mUB; idx++) {
        i = obj.indexUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        i = x.size(0) * x.size(1);
        i1 = (ix0 + obj.indexUB[idx]) - 1;
        if ((i1 < 1) || (i1 > i)) {
          rtDynamicBoundsError(i1, 1, i, p_emlrtBCI);
        }
        i = obj.ub.size(0);
        if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i)) {
          rtDynamicBoundsError(obj.indexUB[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, x[i1 - 1] - obj.ub[obj.indexUB[idx] - 1]);
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(b_vPrime, d_vPrime, i3, k)
      {
        b_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mUB; idx++) {
          i3 = obj.indexUB.size(0);
          if (idx + 1 > i3) {
            rtDynamicBoundsError(idx + 1, 1, i3, p_emlrtBCI);
          }
          i3 = x.size(0) * x.size(1);
          k = (ix0 + obj.indexUB[idx]) - 1;
          if ((k < 1) || (k > i3)) {
            rtDynamicBoundsError(k, 1, i3, p_emlrtBCI);
          }
          i3 = obj.ub.size(0);
          if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i3)) {
            rtDynamicBoundsError(obj.indexUB[idx], 1, i3, p_emlrtBCI);
          }
          d_vPrime = x[k - 1] - obj.ub[obj.indexUB[idx] - 1];
          b_vPrime = std::fmax(b_vPrime, d_vPrime);
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, b_vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  if (obj.sizes[0] > 0) {
    if (obj.sizes[0] > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mFixed < 1600)) {
      for (idx = 0; idx < mFixed; idx++) {
        i = obj.indexFixed.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        i = x.size(0) * x.size(1);
        i1 = (ix0 + obj.indexFixed[idx]) - 1;
        if ((i1 < 1) || (i1 > i)) {
          rtDynamicBoundsError(i1, 1, i, p_emlrtBCI);
        }
        i = obj.ub.size(0);
        if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i)) {
          rtDynamicBoundsError(obj.indexFixed[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, std::abs(x[i1 - 1] - obj.ub[obj.indexFixed[idx] - 1]));
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(e_vPrime, d_vPrime, i3, k)
      {
        e_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mFixed; idx++) {
          i3 = obj.indexFixed.size(0);
          if (idx + 1 > i3) {
            rtDynamicBoundsError(idx + 1, 1, i3, p_emlrtBCI);
          }
          i3 = x.size(0) * x.size(1);
          k = (ix0 + obj.indexFixed[idx]) - 1;
          if ((k < 1) || (k > i3)) {
            rtDynamicBoundsError(k, 1, i3, p_emlrtBCI);
          }
          i3 = obj.ub.size(0);
          if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i3)) {
            rtDynamicBoundsError(obj.indexFixed[idx], 1, i3, p_emlrtBCI);
          }
          d_vPrime = x[k - 1] - obj.ub[obj.indexFixed[idx] - 1];
          e_vPrime = std::fmax(e_vPrime, std::abs(d_vPrime));
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, e_vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  return v;
}

//
// Arguments    : d_struct_T &obj
//                const array<double, 1U> &x
// Return Type  : double
//
double maxConstraintViolation(d_struct_T &obj, const array<double, 1U> &x)
{
  double b_vPrime;
  double c_vPrime;
  double d_vPrime;
  double e_vPrime;
  double v;
  double vPrime;
  int b_idx;
  int i;
  int i1;
  int i2;
  int i3;
  int idx;
  int idxLB;
  int mEq;
  int mFixed;
  int mIneq;
  int mLB;
  int mUB;
  int offsetEq2;
  mLB = obj.sizes[3];
  mUB = obj.sizes[4];
  mFixed = obj.sizes[0];
  if (obj.probType == 2) {
    v = 0.0;
    mIneq = obj.sizes[2] - 1;
    mEq = obj.sizes[1] - 1;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (static_cast<int>(mIneq + 1 < 1600)) {
        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      }
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[2], obj.Aineq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_idx = 0; b_idx <= mIneq; b_idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        i = (obj.nVarOrig + b_idx) + 1;
        if ((i < 1) || (i > x.size(0))) {
          rtDynamicBoundsError(i, 1, x.size(0), n_emlrtBCI);
        }
        i1 = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i1) {
          rtDynamicBoundsError(b_idx + 1, 1, i1, n_emlrtBCI);
        }
        obj.maxConstrWorkspace[b_idx] =
            obj.maxConstrWorkspace[b_idx] - x[i - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        v = std::fmax(v, obj.maxConstrWorkspace[b_idx]);
      }
    }
    if (obj.Aeq.size(0) != 0) {
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (mIneq = 0; mIneq <= mEq; mIneq++) {
        obj.maxConstrWorkspace[mIneq] = obj.beq.data[mIneq];
      }
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      mIneq = obj.nVarOrig + obj.sizes[2];
      offsetEq2 = mIneq + obj.sizes[1];
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (b_idx = 0; b_idx <= mEq; b_idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((b_idx + 1 < 1) || (b_idx + 1 > i)) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        i = (mIneq + b_idx) + 1;
        if ((i < 1) || (i > x.size(0))) {
          rtDynamicBoundsError(i, 1, x.size(0), n_emlrtBCI);
        }
        i1 = (offsetEq2 + b_idx) + 1;
        if ((i1 < 1) || (i1 > x.size(0))) {
          rtDynamicBoundsError(i1, 1, x.size(0), n_emlrtBCI);
        }
        i3 = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i3) {
          rtDynamicBoundsError(b_idx + 1, 1, i3, n_emlrtBCI);
        }
        obj.maxConstrWorkspace[b_idx] =
            (obj.maxConstrWorkspace[b_idx] - x[i - 1]) + x[i1 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (b_idx + 1 > i) {
          rtDynamicBoundsError(b_idx + 1, 1, i, n_emlrtBCI);
        }
        v = std::fmax(v, std::abs(obj.maxConstrWorkspace[b_idx]));
      }
    }
  } else {
    v = 0.0;
    mIneq = obj.sizes[2] - 1;
    mEq = obj.sizes[1] - 1;
    if (obj.Aineq.size(0) != 0) {
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      i = (mIneq + 1 < 1600);
      if (i) {
        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (idxLB = 0; idxLB <= mIneq; idxLB++) {
          obj.maxConstrWorkspace[idxLB] = obj.bineq[idxLB];
        }
      }
      internal::blas::xgemv(obj.nVar, obj.sizes[2], obj.Aineq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      if (obj.sizes[2] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (i) {
        for (idx = 0; idx <= mIneq; idx++) {
          i = obj.maxConstrWorkspace.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            rtDynamicBoundsError(idx + 1, 1, i, o_emlrtBCI);
          }
          v = std::fmax(v, obj.maxConstrWorkspace[idx]);
        }
      } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(d_vPrime, i2)
        {
          d_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx <= mIneq; idx++) {
            i2 = obj.maxConstrWorkspace.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i2)) {
              rtDynamicBoundsError(idx + 1, 1, i2, o_emlrtBCI);
            }
            d_vPrime = std::fmax(d_vPrime, obj.maxConstrWorkspace[idx]);
          }
          omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
          {

            v = std::fmax(v, d_vPrime);
          }
          omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        }
      }
    }
    if (obj.Aeq.size(0) != 0) {
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      for (mIneq = 0; mIneq <= mEq; mIneq++) {
        obj.maxConstrWorkspace[mIneq] = obj.beq.data[mIneq];
      }
      internal::blas::xgemv(obj.nVar, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      if (obj.sizes[1] > 2147483646) {
        check_forloop_overflow_error();
      }
      if (static_cast<int>(mEq + 1 < 1600)) {
        for (idx = 0; idx <= mEq; idx++) {
          i = obj.maxConstrWorkspace.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            rtDynamicBoundsError(idx + 1, 1, i, o_emlrtBCI);
          }
          v = std::fmax(v, std::abs(obj.maxConstrWorkspace[idx]));
        }
      } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(c_vPrime, d_vPrime, i2)
        {
          c_vPrime = rtMinusInf;
#pragma omp for nowait
          for (idx = 0; idx <= mEq; idx++) {
            i2 = obj.maxConstrWorkspace.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i2)) {
              rtDynamicBoundsError(idx + 1, 1, i2, o_emlrtBCI);
            }
            d_vPrime = obj.maxConstrWorkspace[idx];
            c_vPrime = std::fmax(c_vPrime, std::abs(d_vPrime));
          }
          omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
          {

            v = std::fmax(v, c_vPrime);
          }
          omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        }
      }
    }
  }
  if (obj.sizes[3] > 0) {
    if (obj.sizes[3] > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mLB < 1600)) {
      for (idx = 0; idx < mLB; idx++) {
        i = obj.indexLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        idxLB = obj.indexLB[idx] - 1;
        if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > x.size(0))) {
          rtDynamicBoundsError(obj.indexLB[idx], 1, x.size(0), p_emlrtBCI);
        }
        i = obj.lb.size(0);
        if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i)) {
          rtDynamicBoundsError(obj.indexLB[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, -x[idxLB] - obj.lb[idxLB]);
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(vPrime, idxLB, i2)
      {
        vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mLB; idx++) {
          i2 = obj.indexLB.size(0);
          if (idx + 1 > i2) {
            rtDynamicBoundsError(idx + 1, 1, i2, p_emlrtBCI);
          }
          idxLB = obj.indexLB[idx] - 1;
          if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > x.size(0))) {
            rtDynamicBoundsError(obj.indexLB[idx], 1, x.size(0), p_emlrtBCI);
          }
          i2 = obj.lb.size(0);
          if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i2)) {
            rtDynamicBoundsError(obj.indexLB[idx], 1, i2, p_emlrtBCI);
          }
          vPrime = std::fmax(vPrime, -x[idxLB] - obj.lb[idxLB]);
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  if (obj.sizes[4] > 0) {
    if (obj.sizes[4] > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mUB < 1600)) {
      for (idx = 0; idx < mUB; idx++) {
        i = obj.indexUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        idxLB = obj.indexUB[idx] - 1;
        if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > x.size(0))) {
          rtDynamicBoundsError(obj.indexUB[idx], 1, x.size(0), p_emlrtBCI);
        }
        i = obj.ub.size(0);
        if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i)) {
          rtDynamicBoundsError(obj.indexUB[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, x[idxLB] - obj.ub[idxLB]);
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(b_vPrime, idxLB, i2)
      {
        b_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mUB; idx++) {
          i2 = obj.indexUB.size(0);
          if (idx + 1 > i2) {
            rtDynamicBoundsError(idx + 1, 1, i2, p_emlrtBCI);
          }
          idxLB = obj.indexUB[idx] - 1;
          if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > x.size(0))) {
            rtDynamicBoundsError(obj.indexUB[idx], 1, x.size(0), p_emlrtBCI);
          }
          i2 = obj.ub.size(0);
          if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i2)) {
            rtDynamicBoundsError(obj.indexUB[idx], 1, i2, p_emlrtBCI);
          }
          b_vPrime = std::fmax(b_vPrime, x[idxLB] - obj.ub[idxLB]);
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, b_vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  if (obj.sizes[0] > 0) {
    if (obj.sizes[0] > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mFixed < 1600)) {
      for (idx = 0; idx < mFixed; idx++) {
        i = obj.indexFixed.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, p_emlrtBCI);
        }
        if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > x.size(0))) {
          rtDynamicBoundsError(obj.indexFixed[idx], 1, x.size(0), p_emlrtBCI);
        }
        i = obj.ub.size(0);
        if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i)) {
          rtDynamicBoundsError(obj.indexFixed[idx], 1, i, p_emlrtBCI);
        }
        v = std::fmax(v, std::abs(x[obj.indexFixed[idx] - 1] -
                                  obj.ub[obj.indexFixed[idx] - 1]));
      }
    } else {
#pragma omp parallel num_threads(16 > omp_get_max_threads()                    \
                                     ? omp_get_max_threads()                   \
                                     : 16) private(e_vPrime, i2)
      {
        e_vPrime = rtMinusInf;
#pragma omp for nowait
        for (idx = 0; idx < mFixed; idx++) {
          i2 = obj.indexFixed.size(0);
          if (idx + 1 > i2) {
            rtDynamicBoundsError(idx + 1, 1, i2, p_emlrtBCI);
          }
          if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > x.size(0))) {
            rtDynamicBoundsError(obj.indexFixed[idx], 1, x.size(0), p_emlrtBCI);
          }
          i2 = obj.ub.size(0);
          if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i2)) {
            rtDynamicBoundsError(obj.indexFixed[idx], 1, i2, p_emlrtBCI);
          }
          e_vPrime =
              std::fmax(e_vPrime, std::abs(x[obj.indexFixed[idx] - 1] -
                                           obj.ub[obj.indexFixed[idx] - 1]));
        }
        omp_set_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
        {

          v = std::fmax(v, e_vPrime);
        }
        omp_unset_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
      }
    }
  }
  return v;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for maxConstraintViolation.cpp
//
// [EOF]
//
