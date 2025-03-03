//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: soc.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "soc.h"
#include "addAeqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const array<double, 2U> &Hessian
//                const array<double, 1U> &grad
//                j_struct_T &b_TrialState
//                h_struct_T &memspace
//                d_struct_T &WorkingSet
//                e_struct_T &b_QRManager
//                f_struct_T &b_CholManager
//                g_struct_T &QPObjective
//                const k_struct_T &qpoptions
// Return Type  : boolean_T
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
boolean_T soc(const array<double, 2U> &Hessian, const array<double, 1U> &grad,
              j_struct_T &b_TrialState, h_struct_T &memspace,
              d_struct_T &WorkingSet, e_struct_T &b_QRManager,
              f_struct_T &b_CholManager, g_struct_T &QPObjective,
              const k_struct_T &qpoptions)
{
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,    // iFirst
      -1,    // iLast
      1,     // lineNo
      1,     // colNo
      "",    // aName
      "soc", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
      "soc.p", // pName
      0        // checkKind
  };
  static rtBoundsCheckInfo x_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      1,                  // lineNo
      1,                  // colNo
      "",                 // aName
      "updateWorkingSet", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
      "+soc/updateWorkingSet.p", // pName
      0                          // checkKind
  };
  static rtBoundsCheckInfo y_emlrtBCI{
      -1,                  // iFirst
      -1,                  // iLast
      1,                   // lineNo
      1,                   // colNo
      "",                  // aName
      "restoreWorkingSet", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
      "+soc/restoreWorkingSet.p", // pName
      0                           // checkKind
  };
  array<double, 1U> r;
  k_struct_T b_qpoptions;
  double lenSOC;
  int b;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int idxIneqOffset;
  int idx_Aineq;
  int idx_Partition;
  int idx_lower;
  int idx_upper;
  int mConstrMax;
  int mIneq;
  int nVar;
  int nWIneq_old;
  int nWLower_old;
  int nWUpper_old;
  boolean_T success;
  nWIneq_old = WorkingSet.nWConstr[2];
  nWLower_old = WorkingSet.nWConstr[3];
  nWUpper_old = WorkingSet.nWConstr[4];
  nVar = WorkingSet.nVar;
  mConstrMax = WorkingSet.mConstrMax;
  if (WorkingSet.nVar > 2147483646) {
    check_forloop_overflow_error();
  }
  i = (nVar < 1600);
  if (i) {
    for (int k{0}; k < nVar; k++) {
      b_TrialState.xstarsqp[k] = b_TrialState.xstarsqp_old[k];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int k = 0; k < nVar; k++) {
      b_TrialState.xstarsqp[k] = b_TrialState.xstarsqp_old[k];
    }
  }
  if (WorkingSet.nVar > 2147483646) {
    check_forloop_overflow_error();
  }
  for (idx_Aineq = 0; idx_Aineq < nVar; idx_Aineq++) {
    i1 = b_TrialState.xstar.size(0);
    if ((idx_Aineq + 1 < 1) || (idx_Aineq + 1 > i1)) {
      rtDynamicBoundsError(idx_Aineq + 1, 1, i1, w_emlrtBCI);
    }
    i1 = b_TrialState.socDirection.size(0);
    if (idx_Aineq + 1 > i1) {
      rtDynamicBoundsError(idx_Aineq + 1, 1, i1, w_emlrtBCI);
    }
    b_TrialState.socDirection[idx_Aineq] = b_TrialState.xstar[idx_Aineq];
  }
  if (WorkingSet.mConstrMax > 2147483646) {
    check_forloop_overflow_error();
  }
  i1 = (mConstrMax < 1600);
  if (i1) {
    for (int k{0}; k < mConstrMax; k++) {
      b_TrialState.lambdaStopTest[k] = b_TrialState.lambda[k];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int k = 0; k < mConstrMax; k++) {
      b_TrialState.lambdaStopTest[k] = b_TrialState.lambda[k];
    }
  }
  mIneq = WorkingSet.sizes[2];
  idxIneqOffset = WorkingSet.isActiveIdx[2];
  if (WorkingSet.sizes[1] > 0) {
    if (WorkingSet.sizes[1] > 2147483646) {
      check_forloop_overflow_error();
    }
    i2 = static_cast<unsigned char>(WorkingSet.sizes[1]);
    i3 = b_TrialState.cEq.size[0];
    for (int idx{0}; idx < i2; idx++) {
      if (idx + 1 > i3) {
        rtDynamicBoundsError(idx + 1, 1, i3, x_emlrtBCI);
      }
      i4 = WorkingSet.beq.size[0];
      if (idx + 1 > i4) {
        rtDynamicBoundsError(idx + 1, 1, i4, x_emlrtBCI);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    r.set_size(WorkingSet.beq.size[0]);
    idx_Aineq = WorkingSet.beq.size[0];
    for (i2 = 0; i2 < idx_Aineq; i2++) {
      r[i2] = WorkingSet.beq.data[i2];
    }
    ::coder::internal::blas::b_xgemv(WorkingSet.nVar, WorkingSet.sizes[1],
                                     WorkingSet.Aeq, WorkingSet.ldA,
                                     b_TrialState.searchDir, r);
    WorkingSet.beq.size[0] = r.size(0);
    idx_Aineq = r.size(0);
    if (static_cast<int>(r.size(0) < 1600)) {
      for (int k{0}; k < idx_Aineq; k++) {
        WorkingSet.beq.data[k] = r[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < idx_Aineq; k++) {
        WorkingSet.beq.data[k] = r[k];
      }
    }
    if (WorkingSet.sizes[1] > 2147483646) {
      check_forloop_overflow_error();
    }
    i2 = static_cast<unsigned char>(WorkingSet.sizes[1]);
    for (idx_Aineq = 0; idx_Aineq < i2; idx_Aineq++) {
      WorkingSet.bwset[WorkingSet.sizes[0] + idx_Aineq] =
          WorkingSet.beq.data[idx_Aineq];
    }
  }
  if (WorkingSet.sizes[2] > 0) {
    if (WorkingSet.sizes[2] > 2147483646) {
      check_forloop_overflow_error();
    }
    i2 = b_TrialState.cIneq.size(0);
    for (int idx{0}; idx < mIneq; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i2)) {
        rtDynamicBoundsError(idx + 1, 1, i2, x_emlrtBCI);
      }
      i3 = WorkingSet.bineq.size(0);
      if (idx + 1 > i3) {
        rtDynamicBoundsError(idx + 1, 1, i3, x_emlrtBCI);
      }
      WorkingSet.bineq[idx] = -b_TrialState.cIneq[idx];
    }
    ::coder::internal::blas::b_xgemv(WorkingSet.nVar, WorkingSet.sizes[2],
                                     WorkingSet.Aineq, WorkingSet.ldA,
                                     b_TrialState.searchDir, WorkingSet.bineq);
    idx_Aineq = 1;
    idx_lower = WorkingSet.sizes[2] + 1;
    idx_upper = (WorkingSet.sizes[2] + WorkingSet.sizes[3]) + 1;
    b = WorkingSet.nActiveConstr;
    if ((WorkingSet.isActiveIdx[2] <= WorkingSet.nActiveConstr) &&
        (WorkingSet.nActiveConstr > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (int idx{idxIneqOffset}; idx <= b; idx++) {
      i2 = WorkingSet.Wid.size(0);
      if ((idx < 1) || (idx > i2)) {
        rtDynamicBoundsError(idx, 1, i2, x_emlrtBCI);
      }
      i2 = WorkingSet.Wlocalidx.size(0);
      if (idx > i2) {
        rtDynamicBoundsError(idx, 1, i2, x_emlrtBCI);
      }
      switch (WorkingSet.Wid[idx - 1]) {
      case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        i2 = WorkingSet.bineq.size(0);
        i3 = WorkingSet.Wlocalidx[idx - 1];
        if ((i3 < 1) || (i3 > i2)) {
          rtDynamicBoundsError(WorkingSet.Wlocalidx[idx - 1], 1, i2,
                               x_emlrtBCI);
        }
        i2 = WorkingSet.bwset.size(0);
        if (idx > i2) {
          rtDynamicBoundsError(idx, 1, i2, x_emlrtBCI);
        }
        WorkingSet.bwset[idx - 1] = WorkingSet.bineq[i3 - 1];
        break;
      case 4:
        idx_Partition = idx_lower;
        idx_lower++;
        break;
      default:
        idx_Partition = idx_upper;
        idx_upper++;
        break;
      }
      i2 = b_TrialState.workingset_old.size(0);
      if ((idx_Partition < 1) || (idx_Partition > i2)) {
        rtDynamicBoundsError(idx_Partition, 1, i2, x_emlrtBCI);
      }
      b_TrialState.workingset_old[idx_Partition - 1] =
          WorkingSet.Wlocalidx[idx - 1];
    }
  }
  if (WorkingSet.nVar > 2147483646) {
    check_forloop_overflow_error();
  }
  if (i) {
    for (int k{0}; k < nVar; k++) {
      b_TrialState.xstar[k] = b_TrialState.xstarsqp[k];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int k = 0; k < nVar; k++) {
      b_TrialState.xstar[k] = b_TrialState.xstarsqp[k];
    }
  }
  b_qpoptions = qpoptions;
  ::coder::optim::coder::qpactiveset::driver(
      Hessian, grad, b_TrialState, memspace, WorkingSet, b_QRManager,
      b_CholManager, QPObjective, b_qpoptions, qpoptions.MaxIterations);
  if (WorkingSet.indexEqRemoved.size[0] > 0) {
    boolean_T exitg1;
    exitg1 = false;
    while ((!exitg1) && (WorkingSet.mEqRemoved > 0)) {
      i = WorkingSet.indexEqRemoved.size[0];
      if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > i)) {
        rtDynamicBoundsError(WorkingSet.mEqRemoved, 1, i, w_emlrtBCI);
      }
      if (WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1] >=
          b_TrialState.iNonEq0) {
        i = WorkingSet.indexEqRemoved.size[0];
        if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > i)) {
          rtDynamicBoundsError(WorkingSet.mEqRemoved, 1, i, w_emlrtBCI);
        }
        qpactiveset::WorkingSet::addAeqConstr(
            WorkingSet,
            WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1]);
        WorkingSet.mEqRemoved--;
      } else {
        exitg1 = true;
      }
    }
  }
  if (nVar > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int idx{0}; idx < nVar; idx++) {
    i = b_TrialState.socDirection.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
    }
    lenSOC = b_TrialState.socDirection[idx];
    i = b_TrialState.xstar.size(0);
    if (idx + 1 > i) {
      rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
    }
    i = b_TrialState.socDirection.size(0);
    if (idx + 1 > i) {
      rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
    }
    b_TrialState.socDirection[idx] = b_TrialState.xstar[idx] - lenSOC;
    i = b_TrialState.xstar.size(0);
    if (idx + 1 > i) {
      rtDynamicBoundsError(idx + 1, 1, i, w_emlrtBCI);
    }
    b_TrialState.xstar[idx] = lenSOC;
  }
  double lenQPNormal;
  lenSOC = ::coder::internal::blas::xnrm2(nVar, b_TrialState.socDirection);
  lenQPNormal = ::coder::internal::blas::xnrm2(nVar, b_TrialState.xstar);
  success = (lenSOC <= 2.0 * lenQPNormal);
  mIneq = WorkingSet.sizes[2] + 1;
  idx_Partition = WorkingSet.sizes[3];
  if (WorkingSet.sizes[1] > 0) {
    if (WorkingSet.sizes[1] > 2147483646) {
      check_forloop_overflow_error();
    }
    i = static_cast<unsigned char>(WorkingSet.sizes[1]);
    i2 = b_TrialState.cEq.size[0];
    for (int idx{0}; idx < i; idx++) {
      if (idx + 1 > i2) {
        rtDynamicBoundsError(idx + 1, 1, i2, y_emlrtBCI);
      }
      i3 = WorkingSet.beq.size[0];
      if (idx + 1 > i3) {
        rtDynamicBoundsError(idx + 1, 1, i3, y_emlrtBCI);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    if (WorkingSet.sizes[1] > 2147483646) {
      check_forloop_overflow_error();
    }
    for (idx_Aineq = 0; idx_Aineq < i; idx_Aineq++) {
      WorkingSet.bwset[WorkingSet.sizes[0] + idx_Aineq] =
          WorkingSet.beq.data[idx_Aineq];
    }
  }
  if (WorkingSet.sizes[2] > 0) {
    if (WorkingSet.sizes[2] > 2147483646) {
      check_forloop_overflow_error();
    }
    i = b_TrialState.cIneq.size(0);
    for (int idx{0}; idx <= mIneq - 2; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        rtDynamicBoundsError(idx + 1, 1, i, y_emlrtBCI);
      }
      i2 = WorkingSet.bineq.size(0);
      if (idx + 1 > i2) {
        rtDynamicBoundsError(idx + 1, 1, i2, y_emlrtBCI);
      }
      WorkingSet.bineq[idx] = -b_TrialState.cIneq[idx];
    }
    if (!success) {
      qpactiveset::WorkingSet::removeAllIneqConstr(WorkingSet);
      if (nWIneq_old > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int idx{0}; idx < nWIneq_old; idx++) {
        i = b_TrialState.workingset_old.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          rtDynamicBoundsError(idx + 1, 1, i, y_emlrtBCI);
        }
        idx_Aineq = b_TrialState.workingset_old[idx];
        WorkingSet.nWConstr[2]++;
        i = WorkingSet.isActiveConstr.size(0);
        i2 = (WorkingSet.isActiveIdx[2] + idx_Aineq) - 1;
        if ((i2 < 1) || (i2 > i)) {
          rtDynamicBoundsError(i2, 1, i, q_emlrtBCI);
        }
        WorkingSet.isActiveConstr[i2 - 1] = true;
        WorkingSet.nActiveConstr++;
        i = WorkingSet.Wid.size(0);
        if ((WorkingSet.nActiveConstr < 1) || (WorkingSet.nActiveConstr > i)) {
          rtDynamicBoundsError(WorkingSet.nActiveConstr, 1, i, q_emlrtBCI);
        }
        i = WorkingSet.nActiveConstr - 1;
        WorkingSet.Wid[i] = 3;
        i2 = WorkingSet.Wlocalidx.size(0);
        if ((WorkingSet.nActiveConstr < 1) || (WorkingSet.nActiveConstr > i2)) {
          rtDynamicBoundsError(WorkingSet.nActiveConstr, 1, i2, q_emlrtBCI);
        }
        WorkingSet.Wlocalidx[i] = idx_Aineq;
        idx_lower = WorkingSet.ldA * (idx_Aineq - 1) + 1;
        idx_upper = WorkingSet.ldA * i + 1;
        i2 = WorkingSet.nVar - 1;
        for (idxIneqOffset = 0; idxIneqOffset <= i2; idxIneqOffset++) {
          i3 = WorkingSet.Aineq.size(0);
          i4 = idx_lower + idxIneqOffset;
          if ((i4 < 1) || (i4 > i3)) {
            rtDynamicBoundsError(i4, 1, i3, r_emlrtBCI);
          }
          i3 = WorkingSet.ATwset.size(0);
          b = idx_upper + idxIneqOffset;
          if ((b < 1) || (b > i3)) {
            rtDynamicBoundsError(b, 1, i3, r_emlrtBCI);
          }
          WorkingSet.ATwset[b - 1] = WorkingSet.Aineq[i4 - 1];
        }
        i2 = WorkingSet.bineq.size(0);
        if ((idx_Aineq < 1) || (idx_Aineq > i2)) {
          rtDynamicBoundsError(idx_Aineq, 1, i2, r_emlrtBCI);
        }
        i2 = WorkingSet.bwset.size(0);
        if ((WorkingSet.nActiveConstr < 1) || (WorkingSet.nActiveConstr > i2)) {
          rtDynamicBoundsError(WorkingSet.nActiveConstr, 1, i2, r_emlrtBCI);
        }
        WorkingSet.bwset[i] = WorkingSet.bineq[idx_Aineq - 1];
      }
      if (nWLower_old > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int idx{0}; idx < nWLower_old; idx++) {
        i = b_TrialState.workingset_old.size(0);
        i2 = idx + mIneq;
        if ((i2 < 1) || (i2 > i)) {
          rtDynamicBoundsError(i2, 1, i, y_emlrtBCI);
        }
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            WorkingSet, b_TrialState.workingset_old[i2 - 1]);
      }
      if (nWUpper_old > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int idx{0}; idx < nWUpper_old; idx++) {
        i = b_TrialState.workingset_old.size(0);
        i2 = (idx + mIneq) + idx_Partition;
        if ((i2 < 1) || (i2 > i)) {
          rtDynamicBoundsError(i2, 1, i, y_emlrtBCI);
        }
        qpactiveset::WorkingSet::b_addBoundToActiveSetMatrix_(
            WorkingSet, b_TrialState.workingset_old[i2 - 1]);
      }
    }
  }
  if (!success) {
    if (mConstrMax > 2147483646) {
      check_forloop_overflow_error();
    }
    if (i1) {
      for (int k{0}; k < mConstrMax; k++) {
        b_TrialState.lambda[k] = b_TrialState.lambdaStopTest[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < mConstrMax; k++) {
        b_TrialState.lambda[k] = b_TrialState.lambdaStopTest[k];
      }
    }
  } else {
    qpactiveset::parseoutput::sortLambdaQP(
        b_TrialState.lambda, WorkingSet.nActiveConstr, WorkingSet.sizes,
        WorkingSet.isActiveIdx, WorkingSet.Wid, WorkingSet.Wlocalidx,
        memspace.workspace_double);
  }
  return success;
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for soc.cpp
//
// [EOF]
//
