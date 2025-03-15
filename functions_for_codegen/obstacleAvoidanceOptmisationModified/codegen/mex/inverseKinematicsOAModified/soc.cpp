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
#include <algorithm>
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo bj_emlrtRSI{
    1,     // lineNo
    "soc", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "soc.p" // pathName
};

static emlrtRSInfo cj_emlrtRSI{
    1,                  // lineNo
    "updateWorkingSet", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p" // pathName
};

static emlrtRSInfo dj_emlrtRSI{
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

static emlrtRTEInfo ec_emlrtRTEI{
    1,     // lineNo
    1,     // colNo
    "soc", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "soc.p" // pName
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
  array<real_T, 1U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  k_struct_T b_qpoptions;
  real_T tmp_data[112];
  real_T lenQPNormal;
  real_T lenSOC;
  int32_T i;
  int32_T i1;
  int32_T idxIneqOffset;
  int32_T idx_Aineq;
  int32_T idx_lower;
  int32_T idx_upper;
  int32_T mConstrMax;
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
  st.site = &bj_emlrtRSI;
  if (WorkingSet.nVar >= 1) {
    b_st.site = &ub_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.xstarsqp_old.data())[0], &incx_t,
          &(b_TrialState.xstarsqp.data())[0], &incy_t);
  }
  st.site = &bj_emlrtRSI;
  if (WorkingSet.nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (idx_Aineq = 0; idx_Aineq < nVar; idx_Aineq++) {
    i = b_TrialState.xstar.size(0);
    if ((idx_Aineq + 1 < 1) || (idx_Aineq + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx_Aineq + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = b_TrialState.socDirection.size(0);
    if (idx_Aineq + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(idx_Aineq + 1, 1, i, &he_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.socDirection[idx_Aineq] = b_TrialState.xstar[idx_Aineq];
  }
  st.site = &bj_emlrtRSI;
  y.set_size(&ec_emlrtRTEI, &st, b_TrialState.lambdaStopTest.size[0]);
  idx_lower = b_TrialState.lambdaStopTest.size[0];
  for (i = 0; i < idx_lower; i++) {
    y[i] = b_TrialState.lambdaStopTest.data[i];
  }
  if (WorkingSet.mConstrMax >= 1) {
    b_st.site = &ub_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.mConstrMax;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &b_TrialState.lambda.data[0], &incx_t, &(y.data())[0], &incy_t);
  }
  b_TrialState.lambdaStopTest.size[0] = y.size(0);
  idx_lower = y.size(0);
  for (i = 0; i < idx_lower; i++) {
    b_TrialState.lambdaStopTest.data[i] = y[i];
  }
  st.site = &bj_emlrtRSI;
  idxIneqOffset = WorkingSet.isActiveIdx[2];
  if (WorkingSet.sizes[1] > 0) {
    b_st.site = &cj_emlrtRSI;
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
      idx_upper = WorkingSet.beq.size[0];
      if (idx + 1 > idx_upper) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idx_upper, &ge_emlrtBCI, &st);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    idx_Aineq = WorkingSet.beq.size[0];
    idx_lower = WorkingSet.beq.size[0];
    if (idx_lower - 1 >= 0) {
      std::copy(&WorkingSet.beq.data[0], &WorkingSet.beq.data[idx_lower],
                &tmp_data[0]);
    }
    b_st.site = &cj_emlrtRSI;
    ::coder::internal::blas::xgemv(WorkingSet.nVar, WorkingSet.sizes[1],
                                   WorkingSet.Aeq, WorkingSet.ldA,
                                   b_TrialState.searchDir, tmp_data, idx_Aineq);
    WorkingSet.beq.size[0] = idx_Aineq;
    if (idx_Aineq - 1 >= 0) {
      std::copy(&tmp_data[0], &tmp_data[idx_Aineq], &WorkingSet.beq.data[0]);
    }
    b_st.site = &cj_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.sizes[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.beq.data[0], &incx_t,
          &WorkingSet.bwset.data[WorkingSet.sizes[0]], &incy_t);
  }
  if (WorkingSet.sizes[2] > 0) {
    int32_T b;
    b_st.site = &cj_emlrtRSI;
    if (WorkingSet.sizes[2] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    i = static_cast<uint8_T>(WorkingSet.sizes[2]);
    i1 = b_TrialState.cIneq.size[0];
    for (int32_T idx{0}; idx < i; idx++) {
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &ge_emlrtBCI, &st);
      }
      idx_upper = WorkingSet.bineq.size[0];
      if (idx + 1 > idx_upper) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idx_upper, &ge_emlrtBCI, &st);
      }
      WorkingSet.bineq.data[idx] = -b_TrialState.cIneq.data[idx];
    }
    b_st.site = &cj_emlrtRSI;
    ::coder::internal::blas::xgemv(
        WorkingSet.nVar, WorkingSet.sizes[2], WorkingSet.Aineq, WorkingSet.ldA,
        b_TrialState.searchDir, WorkingSet.bineq.data,
        WorkingSet.bineq.size[0]);
    idx_Aineq = 1;
    idx_lower = WorkingSet.sizes[2] + 1;
    idx_upper = (WorkingSet.sizes[2] + WorkingSet.sizes[3]) + 1;
    b = WorkingSet.nActiveConstr;
    b_st.site = &cj_emlrtRSI;
    if ((WorkingSet.isActiveIdx[2] <= WorkingSet.nActiveConstr) &&
        (WorkingSet.nActiveConstr > 2147483646)) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (int32_T idx{idxIneqOffset}; idx <= b; idx++) {
      int32_T idx_Partition;
      i = WorkingSet.Wid.size[0];
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ge_emlrtBCI, &st);
      }
      i = WorkingSet.Wlocalidx.size[0];
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ge_emlrtBCI, &st);
      }
      switch (WorkingSet.Wid.data[idx - 1]) {
      case 3:
        idx_Partition = idx_Aineq;
        idx_Aineq++;
        i = WorkingSet.bineq.size[0];
        i1 = WorkingSet.Wlocalidx.data[idx - 1];
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.Wlocalidx.data[idx - 1], 1,
                                        i, &ge_emlrtBCI, &st);
        }
        i = WorkingSet.bwset.size[0];
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ge_emlrtBCI, &st);
        }
        WorkingSet.bwset.data[idx - 1] = WorkingSet.bineq.data[i1 - 1];
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
      i = b_TrialState.workingset_old.size[0];
      if ((idx_Partition < 1) || (idx_Partition > i)) {
        emlrtDynamicBoundsCheckR2012b(idx_Partition, 1, i, &ge_emlrtBCI, &st);
      }
      b_TrialState.workingset_old.data[idx_Partition - 1] =
          WorkingSet.Wlocalidx.data[idx - 1];
    }
  }
  st.site = &bj_emlrtRSI;
  if (WorkingSet.nVar >= 1) {
    b_st.site = &ub_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.xstarsqp.data())[0], &incx_t,
          &(b_TrialState.xstar.data())[0], &incy_t);
  }
  b_qpoptions = qpoptions;
  st.site = &bj_emlrtRSI;
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
        st.site = &bj_emlrtRSI;
        qpactiveset::WorkingSet::addAeqConstr(
            st, WorkingSet,
            WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1]);
        WorkingSet.mEqRemoved--;
      } else {
        exitg1 = true;
      }
    }
  }
  st.site = &bj_emlrtRSI;
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
  st.site = &bj_emlrtRSI;
  idx_Aineq = WorkingSet.sizes[2] + 1;
  idx_lower = WorkingSet.sizes[3];
  if (WorkingSet.sizes[1] > 0) {
    b_st.site = &dj_emlrtRSI;
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
      idx_upper = WorkingSet.beq.size[0];
      if (idx + 1 > idx_upper) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idx_upper, &ie_emlrtBCI, &st);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    b_st.site = &dj_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.sizes[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.beq.data[0], &incx_t,
          &WorkingSet.bwset.data[WorkingSet.sizes[0]], &incy_t);
  }
  if (WorkingSet.sizes[2] > 0) {
    b_st.site = &dj_emlrtRSI;
    if (WorkingSet.sizes[2] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    i = static_cast<uint8_T>(WorkingSet.sizes[2]);
    i1 = b_TrialState.cIneq.size[0];
    for (int32_T idx{0}; idx < i; idx++) {
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &ie_emlrtBCI, &st);
      }
      idx_upper = WorkingSet.bineq.size[0];
      if (idx + 1 > idx_upper) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idx_upper, &ie_emlrtBCI, &st);
      }
      WorkingSet.bineq.data[idx] = -b_TrialState.cIneq.data[idx];
    }
    if (!success) {
      b_st.site = &dj_emlrtRSI;
      qpactiveset::WorkingSet::removeAllIneqConstr(b_st, WorkingSet);
      b_st.site = &dj_emlrtRSI;
      if (nWIneq_old > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < nWIneq_old; idx++) {
        i = b_TrialState.workingset_old.size[0];
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ie_emlrtBCI, &st);
        }
        b_st.site = &dj_emlrtRSI;
        qpactiveset::WorkingSet::addAineqConstr(
            b_st, WorkingSet, b_TrialState.workingset_old.data[idx]);
      }
      b_st.site = &dj_emlrtRSI;
      if (nWLower_old > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < nWLower_old; idx++) {
        b_st.site = &dj_emlrtRSI;
        i = b_TrialState.workingset_old.size[0];
        i1 = idx + idx_Aineq;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ie_emlrtBCI, &b_st);
        }
        c_st.site = &oi_emlrtRSI;
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            c_st, WorkingSet, b_TrialState.workingset_old.data[i1 - 1]);
      }
      b_st.site = &dj_emlrtRSI;
      if (nWUpper_old > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < nWUpper_old; idx++) {
        b_st.site = &dj_emlrtRSI;
        i = b_TrialState.workingset_old.size[0];
        i1 = (idx + idx_Aineq) + idx_lower;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ie_emlrtBCI, &b_st);
        }
        c_st.site = &qi_emlrtRSI;
        qpactiveset::WorkingSet::b_addBoundToActiveSetMatrix_(
            c_st, WorkingSet, b_TrialState.workingset_old.data[i1 - 1]);
      }
    }
  }
  if (!success) {
    st.site = &bj_emlrtRSI;
    y.set_size(&ec_emlrtRTEI, &st, b_TrialState.lambda.size[0]);
    idx_lower = b_TrialState.lambda.size[0];
    for (i = 0; i < idx_lower; i++) {
      y[i] = b_TrialState.lambda.data[i];
    }
    if (mConstrMax >= 1) {
      b_st.site = &ub_emlrtRSI;
      n_t = (ptrdiff_t)mConstrMax;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &b_TrialState.lambdaStopTest.data[0], &incx_t, &(y.data())[0],
            &incy_t);
    }
    b_TrialState.lambda.size[0] = y.size(0);
    idx_lower = y.size(0);
    for (i = 0; i < idx_lower; i++) {
      b_TrialState.lambda.data[i] = y[i];
    }
  } else {
    st.site = &bj_emlrtRSI;
    qpactiveset::parseoutput::sortLambdaQP(
        st, b_TrialState.lambda.data, b_TrialState.lambda.size[0],
        WorkingSet.nActiveConstr, WorkingSet.sizes, WorkingSet.isActiveIdx,
        WorkingSet.Wid.data, WorkingSet.Wid.size[0], WorkingSet.Wlocalidx.data,
        WorkingSet.Wlocalidx.size[0], memspace.workspace_double);
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
