//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// soc.cpp
//
// Code generation for function 'soc'
//

// Include files
#include "soc.h"
#include "addAeqConstr.h"
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo yi_emlrtRSI{
    1,     // lineNo
    "soc", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "soc.p" // pathName
};

static emlrtRSInfo aj_emlrtRSI{
    1,                  // lineNo
    "updateWorkingSet", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p" // pathName
};

static emlrtRSInfo bj_emlrtRSI{
    1,                   // lineNo
    "restoreWorkingSet", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/restoreWorkingSet.p" // pathName
};

static emlrtBCInfo ge_emlrtBCI{
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

static emlrtBCInfo he_emlrtBCI{
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

static emlrtBCInfo ie_emlrtBCI{
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

static emlrtRTEInfo ud_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "updateWorkingSet", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
boolean_T soc(const emlrtStack &sp, const array<real_T, 2U> &Hessian,
              const array<real_T, 1U> &grad, j_struct_T &b_TrialState,
              h_struct_T &memspace, d_struct_T &WorkingSet,
              e_struct_T &b_QRManager, f_struct_T &b_CholManager,
              g_struct_T &QPObjective, const k_struct_T &qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  k_struct_T b_qpoptions;
  real_T lenQPNormal;
  real_T lenSOC;
  int32_T i;
  int32_T i1;
  int32_T idxIneqOffset;
  int32_T idx_Aineq;
  int32_T idx_lower;
  int32_T mConstrMax;
  int32_T mIneq;
  int32_T nVar;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  boolean_T success;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  nWIneq_old = WorkingSet.nWConstr[2];
  nWLower_old = WorkingSet.nWConstr[3];
  nWUpper_old = WorkingSet.nWConstr[4];
  nVar = WorkingSet.nVar;
  mConstrMax = WorkingSet.mConstrMax;
  st.site = &yi_emlrtRSI;
  if (WorkingSet.nVar >= 1) {
    b_st.site = &ub_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.xstarsqp_old.data())[0], &incx_t,
          &(b_TrialState.xstarsqp.data())[0], &incy_t);
  }
  st.site = &yi_emlrtRSI;
  if (WorkingSet.nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (mIneq = 0; mIneq < nVar; mIneq++) {
    i = b_TrialState.xstar.size(0);
    if ((mIneq + 1 < 1) || (mIneq + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(mIneq + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = b_TrialState.socDirection.size(0);
    if (mIneq + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(mIneq + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.socDirection[mIneq] = b_TrialState.xstar[mIneq];
  }
  st.site = &yi_emlrtRSI;
  if (WorkingSet.mConstrMax >= 1) {
    b_st.site = &ub_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.mConstrMax;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.lambda.data())[0], &incx_t,
          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
  }
  st.site = &yi_emlrtRSI;
  mIneq = WorkingSet.sizes[2];
  idxIneqOffset = WorkingSet.isActiveIdx[2];
  if (WorkingSet.sizes[1] > 0) {
    b_st.site = &aj_emlrtRSI;
    if (WorkingSet.sizes[1] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    i = static_cast<uint8_T>(WorkingSet.sizes[1]);
    i1 = b_TrialState.cEq.size[0];
    for (int32_T idx{0}; idx < i; idx++) {
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &ge_emlrtBCI, &st);
      }
      idx_lower = WorkingSet.beq.size[0];
      if (idx + 1 > idx_lower) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idx_lower, &ge_emlrtBCI, &st);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    r.set_size(&ud_emlrtRTEI, &st, WorkingSet.beq.size[0]);
    idx_Aineq = WorkingSet.beq.size[0];
    for (i = 0; i < idx_Aineq; i++) {
      r[i] = WorkingSet.beq.data[i];
    }
    b_st.site = &aj_emlrtRSI;
    ::coder::internal::blas::b_xgemv(WorkingSet.nVar, WorkingSet.sizes[1],
                                     WorkingSet.Aeq, WorkingSet.ldA,
                                     b_TrialState.searchDir, r);
    WorkingSet.beq.size[0] = r.size(0);
    idx_Aineq = r.size(0);
    for (i = 0; i < idx_Aineq; i++) {
      WorkingSet.beq.data[i] = r[i];
    }
    b_st.site = &aj_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.sizes[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.beq.data[0], &incx_t,
          &WorkingSet.bwset[WorkingSet.sizes[0]], &incy_t);
  }
  if (WorkingSet.sizes[2] > 0) {
    int32_T b;
    b_st.site = &aj_emlrtRSI;
    if (WorkingSet.sizes[2] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    i = b_TrialState.cIneq.size(0);
    for (int32_T idx{0}; idx < mIneq; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ge_emlrtBCI, &st);
      }
      i1 = WorkingSet.bineq.size(0);
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &ge_emlrtBCI, &st);
      }
      WorkingSet.bineq[idx] = -b_TrialState.cIneq[idx];
    }
    b_st.site = &aj_emlrtRSI;
    ::coder::internal::blas::b_xgemv(WorkingSet.nVar, WorkingSet.sizes[2],
                                     WorkingSet.Aineq, WorkingSet.ldA,
                                     b_TrialState.searchDir, WorkingSet.bineq);
    idx_Aineq = 1;
    idx_lower = WorkingSet.sizes[2] + 1;
    mIneq = (WorkingSet.sizes[2] + WorkingSet.sizes[3]) + 1;
    b = WorkingSet.nActiveConstr;
    b_st.site = &aj_emlrtRSI;
    if ((WorkingSet.isActiveIdx[2] <= WorkingSet.nActiveConstr) &&
        (WorkingSet.nActiveConstr > 2147483646)) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (int32_T idx{idxIneqOffset}; idx <= b; idx++) {
      int32_T idx_Partition;
      i = WorkingSet.Wid.size(0);
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ge_emlrtBCI, &st);
      }
      i = WorkingSet.Wlocalidx.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ge_emlrtBCI, &st);
      }
      switch (WorkingSet.Wid[idx - 1]) {
      case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        i = WorkingSet.bineq.size(0);
        i1 = WorkingSet.Wlocalidx[idx - 1];
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.Wlocalidx[idx - 1], 1, i,
                                        &ge_emlrtBCI, &st);
        }
        i = WorkingSet.bwset.size(0);
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ge_emlrtBCI, &st);
        }
        WorkingSet.bwset[idx - 1] = WorkingSet.bineq[i1 - 1];
        break;
      case 4:
        idx_Partition = idx_lower;
        idx_lower++;
        break;
      default:
        idx_Partition = mIneq;
        mIneq++;
        break;
      }
      i = b_TrialState.workingset_old.size(0);
      if ((idx_Partition < 1) || (idx_Partition > i)) {
        emlrtDynamicBoundsCheckR2012b(idx_Partition, 1, i, &ge_emlrtBCI, &st);
      }
      b_TrialState.workingset_old[idx_Partition - 1] =
          WorkingSet.Wlocalidx[idx - 1];
    }
  }
  st.site = &yi_emlrtRSI;
  if (WorkingSet.nVar >= 1) {
    b_st.site = &ub_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.xstarsqp.data())[0], &incx_t,
          &(b_TrialState.xstar.data())[0], &incy_t);
  }
  b_qpoptions = qpoptions;
  st.site = &yi_emlrtRSI;
  ::coder::optim::coder::qpactiveset::driver(
      st, Hessian, grad, b_TrialState, memspace, WorkingSet, b_QRManager,
      b_CholManager, QPObjective, b_qpoptions, qpoptions.MaxIterations);
  if (WorkingSet.indexEqRemoved.size[0] > 0) {
    boolean_T exitg1;
    exitg1 = false;
    while ((!exitg1) && (WorkingSet.mEqRemoved > 0)) {
      i = WorkingSet.indexEqRemoved.size[0];
      if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > i)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.mEqRemoved, 1, i, &he_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1] >=
          b_TrialState.iNonEq0) {
        i = WorkingSet.indexEqRemoved.size[0];
        if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.mEqRemoved, 1, i,
                                        &he_emlrtBCI, (emlrtConstCTX)&sp);
        }
        st.site = &yi_emlrtRSI;
        qpactiveset::WorkingSet::addAeqConstr(
            st, WorkingSet,
            WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1]);
        WorkingSet.mEqRemoved--;
      } else {
        exitg1 = true;
      }
    }
  }
  st.site = &yi_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < nVar; idx++) {
    i = b_TrialState.socDirection.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    lenSOC = b_TrialState.socDirection[idx];
    i = b_TrialState.xstar.size(0);
    if (idx + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = b_TrialState.socDirection.size(0);
    if (idx + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.socDirection[idx] = b_TrialState.xstar[idx] - lenSOC;
    i = b_TrialState.xstar.size(0);
    if (idx + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.xstar[idx] = lenSOC;
  }
  if (nVar < 1) {
    lenSOC = 0.0;
    lenQPNormal = 0.0;
  } else {
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    lenSOC = dnrm2(&n_t, &(b_TrialState.socDirection.data())[0], &incx_t);
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    lenQPNormal = dnrm2(&n_t, &(b_TrialState.xstar.data())[0], &incx_t);
  }
  success = (lenSOC <= 2.0 * lenQPNormal);
  st.site = &yi_emlrtRSI;
  mIneq = WorkingSet.sizes[2] + 1;
  idx_Aineq = WorkingSet.sizes[3];
  if (WorkingSet.sizes[1] > 0) {
    b_st.site = &bj_emlrtRSI;
    if (WorkingSet.sizes[1] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    i = static_cast<uint8_T>(WorkingSet.sizes[1]);
    i1 = b_TrialState.cEq.size[0];
    for (int32_T idx{0}; idx < i; idx++) {
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &ie_emlrtBCI, &st);
      }
      idx_lower = WorkingSet.beq.size[0];
      if (idx + 1 > idx_lower) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idx_lower, &ie_emlrtBCI, &st);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    b_st.site = &bj_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.sizes[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.beq.data[0], &incx_t,
          &WorkingSet.bwset[WorkingSet.sizes[0]], &incy_t);
  }
  if (WorkingSet.sizes[2] > 0) {
    b_st.site = &bj_emlrtRSI;
    if (WorkingSet.sizes[2] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    i = b_TrialState.cIneq.size(0);
    for (int32_T idx{0}; idx <= mIneq - 2; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ie_emlrtBCI, &st);
      }
      i1 = WorkingSet.bineq.size(0);
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &ie_emlrtBCI, &st);
      }
      WorkingSet.bineq[idx] = -b_TrialState.cIneq[idx];
    }
    if (!success) {
      b_st.site = &bj_emlrtRSI;
      qpactiveset::WorkingSet::removeAllIneqConstr(b_st, WorkingSet);
      b_st.site = &bj_emlrtRSI;
      if (nWIneq_old > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < nWIneq_old; idx++) {
        i = b_TrialState.workingset_old.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ie_emlrtBCI, &st);
        }
        b_st.site = &bj_emlrtRSI;
        qpactiveset::WorkingSet::addAineqConstr(
            b_st, WorkingSet, b_TrialState.workingset_old[idx]);
      }
      b_st.site = &bj_emlrtRSI;
      if (nWLower_old > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < nWLower_old; idx++) {
        b_st.site = &bj_emlrtRSI;
        i = b_TrialState.workingset_old.size(0);
        i1 = idx + mIneq;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ie_emlrtBCI, &b_st);
        }
        c_st.site = &mi_emlrtRSI;
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            c_st, WorkingSet, b_TrialState.workingset_old[i1 - 1]);
      }
      b_st.site = &bj_emlrtRSI;
      if (nWUpper_old > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < nWUpper_old; idx++) {
        b_st.site = &bj_emlrtRSI;
        i = b_TrialState.workingset_old.size(0);
        i1 = (idx + mIneq) + idx_Aineq;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ie_emlrtBCI, &b_st);
        }
        c_st.site = &oi_emlrtRSI;
        qpactiveset::WorkingSet::b_addBoundToActiveSetMatrix_(
            c_st, WorkingSet, b_TrialState.workingset_old[i1 - 1]);
      }
    }
  }
  if (!success) {
    st.site = &yi_emlrtRSI;
    if (mConstrMax >= 1) {
      b_st.site = &ub_emlrtRSI;
      n_t = (ptrdiff_t)mConstrMax;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
            &(b_TrialState.lambda.data())[0], &incy_t);
    }
  } else {
    st.site = &yi_emlrtRSI;
    qpactiveset::parseoutput::sortLambdaQP(
        st, b_TrialState.lambda, WorkingSet.nActiveConstr, WorkingSet.sizes,
        WorkingSet.isActiveIdx, WorkingSet.Wid, WorkingSet.Wlocalidx,
        memspace.workspace_double);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return success;
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (soc.cpp)
