//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// relaxed.cpp
//
// Code generation for function 'relaxed'
//

// Include files
#include "relaxed.h"
#include "assignResidualsToXSlack.h"
#include "computeConstrViolationIneq_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "modifyOverheadRegularized_.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo ui_emlrtRSI{
    1,         // lineNo
    "relaxed", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "relaxed.p" // pathName
};

static emlrtRSInfo wi_emlrtRSI{
    1,                            // lineNo
    "findActiveSlackLowerBounds", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/findActiveSlackLowerBounds.p" // pathName
};

static emlrtRSInfo xi_emlrtRSI{
    1,                              // lineNo
    "removeActiveSlackLowerBounds", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/removeActiveSlackLowerBounds.p" // pathName
};

static emlrtBCInfo ce_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    1,         // lineNo
    1,         // colNo
    "",        // aName
    "relaxed", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "relaxed.p", // pName
    0            // checkKind
};

static emlrtBCInfo de_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    1,                            // lineNo
    1,                            // colNo
    "",                           // aName
    "findActiveSlackLowerBounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/findActiveSlackLowerBounds.p", // pName
    0                                        // checkKind
};

static emlrtBCInfo ee_emlrtBCI{
    -1,                             // iFirst
    -1,                             // iLast
    1,                              // lineNo
    1,                              // colNo
    "",                             // aName
    "removeActiveSlackLowerBounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/removeActiveSlackLowerBounds.p", // pName
    0                                          // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
void b_relaxed(const emlrtStack &sp, const array<real_T, 2U> &Hessian,
               const array<real_T, 1U> &grad, j_struct_T &b_TrialState,
               struct_T &b_MeritFunction, h_struct_T &memspace,
               d_struct_T &WorkingSet, e_struct_T &b_QRManager,
               f_struct_T &b_CholManager, g_struct_T &QPObjective,
               k_struct_T &qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T beta;
  real_T rho;
  int32_T b_mEq;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T idx;
  int32_T idx_max;
  int32_T mEq;
  int32_T mFiniteLB;
  int32_T mIneq;
  int32_T nActiveLBArtificial;
  int32_T nArtificial;
  int32_T nArtificial_tmp_tmp_tmp;
  int32_T nVarOrig;
  boolean_T tf;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nVarOrig = WorkingSet.nVar;
  mIneq = WorkingSet.sizes[2];
  mEq = WorkingSet.sizes[1];
  beta = 0.0;
  st.site = &ui_emlrtRSI;
  if (WorkingSet.nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (idx = 0; idx < nVarOrig; idx++) {
    i = Hessian.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ce_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = Hessian.size(1);
    if (idx + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ce_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    beta += Hessian[idx + Hessian.size(0) * idx];
  }
  beta /= static_cast<real_T>(WorkingSet.nVar);
  if (b_TrialState.sqpIterations <= 1) {
    if (QPObjective.nvar < 1) {
      idx_max = 0;
    } else {
      n_t = (ptrdiff_t)QPObjective.nvar;
      incx_t = (ptrdiff_t)1;
      n_t = idamax(&n_t, &(((array<real_T, 1U> *)&grad)->data())[0], &incx_t);
      idx_max = (int32_T)n_t;
    }
    if ((idx_max < 1) || (idx_max > grad.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, grad.size(0), &ce_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    rho = 100.0 * muDoubleScalarMax(1.0, muDoubleScalarAbs(grad[idx_max - 1]));
  } else {
    if (WorkingSet.mConstr < 1) {
      idx_max = 0;
    } else {
      n_t = (ptrdiff_t)WorkingSet.mConstr;
      incx_t = (ptrdiff_t)1;
      n_t = idamax(&n_t, &(b_TrialState.lambdasqp.data())[0], &incx_t);
      idx_max = (int32_T)n_t;
    }
    i = b_TrialState.lambdasqp.size(0);
    if ((idx_max < 1) || (idx_max > i)) {
      emlrtDynamicBoundsCheckR2012b(idx_max, 1, i, &ce_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    rho = muDoubleScalarAbs(b_TrialState.lambdasqp[idx_max - 1]);
  }
  QPObjective.nvar = WorkingSet.nVar;
  QPObjective.beta = beta;
  QPObjective.rho = rho;
  QPObjective.hasLinear = true;
  QPObjective.objtype = 4;
  st.site = &ui_emlrtRSI;
  WorkingSet.nVar = WorkingSet.nVarMax - 1;
  WorkingSet.mConstr = WorkingSet.mConstrMax - 1;
  for (i = 0; i < 5; i++) {
    WorkingSet.sizes[i] = WorkingSet.sizesRegularized[i];
  }
  if (WorkingSet.probType != 4) {
    b_st.site = &bf_emlrtRSI;
    qpactiveset::WorkingSet::modifyOverheadRegularized_(b_st, WorkingSet);
  }
  for (i = 0; i < 6; i++) {
    WorkingSet.isActiveIdx[i] = WorkingSet.isActiveIdxRegularized[i];
  }
  k_struct_T b_qpoptions;
  WorkingSet.probType = 2;
  st.site = &ui_emlrtRSI;
  relaxed::assignResidualsToXSlack(st, nVarOrig, WorkingSet, b_TrialState,
                                   memspace);
  idx_max = qpoptions.MaxIterations;
  qpoptions.MaxIterations =
      (qpoptions.MaxIterations + WorkingSet.nVar) - nVarOrig;
  b_qpoptions = qpoptions;
  st.site = &ui_emlrtRSI;
  ::coder::optim::coder::qpactiveset::driver(
      st, Hessian, grad, b_TrialState, memspace, WorkingSet, b_QRManager,
      b_CholManager, QPObjective, b_qpoptions, qpoptions.MaxIterations);
  qpoptions.MaxIterations = idx_max;
  st.site = &ui_emlrtRSI;
  idx_max = WorkingSet.sizes[2];
  b_mEq = WorkingSet.sizes[1];
  nArtificial_tmp_tmp_tmp = WorkingSet.sizes[1] << 1;
  nArtificial = (nArtificial_tmp_tmp_tmp + WorkingSet.sizes[2]) - 1;
  mFiniteLB = WorkingSet.sizes[3] - 1;
  nActiveLBArtificial = 0;
  b_st.site = &wi_emlrtRSI;
  if (WorkingSet.sizes[1] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  for (idx = 0; idx < b_mEq; idx++) {
    boolean_T b_tf;
    b_st.site = &wi_emlrtRSI;
    i = WorkingSet.isActiveConstr.size(0);
    i1 = WorkingSet.isActiveIdx[3] + mFiniteLB;
    i2 = ((i1 - (b_mEq << 1)) + idx) + 1;
    if ((i2 < 1) || (i2 > i)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i, &jc_emlrtBCI, &b_st);
    }
    tf = WorkingSet.isActiveConstr[i2 - 1];
    b_st.site = &wi_emlrtRSI;
    i = WorkingSet.isActiveConstr.size(0);
    i1 = ((i1 - b_mEq) + idx) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &jc_emlrtBCI, &b_st);
    }
    b_tf = WorkingSet.isActiveConstr[i1 - 1];
    i = memspace.workspace_int.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &de_emlrtBCI, &st);
    }
    memspace.workspace_int[idx] = tf;
    i = memspace.workspace_int.size(0);
    i1 = (idx + b_mEq) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &de_emlrtBCI, &st);
    }
    memspace.workspace_int[i1 - 1] = b_tf;
    nActiveLBArtificial = (nActiveLBArtificial + tf) + b_tf;
  }
  b_st.site = &wi_emlrtRSI;
  if (WorkingSet.sizes[2] > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  for (idx = 0; idx < idx_max; idx++) {
    b_st.site = &wi_emlrtRSI;
    i = WorkingSet.isActiveConstr.size(0);
    i1 = ((WorkingSet.isActiveIdx[3] + mFiniteLB) - nArtificial) + idx;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &jc_emlrtBCI, &b_st);
    }
    tf = WorkingSet.isActiveConstr[i1 - 1];
    i = memspace.workspace_int.size(0);
    i1 = (idx + nArtificial_tmp_tmp_tmp) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &de_emlrtBCI, &st);
    }
    memspace.workspace_int[i1 - 1] = tf;
    nActiveLBArtificial += tf;
  }
  if (b_TrialState.state != -6) {
    real_T qpfvalLinearExcess;
    real_T qpfvalQuadExcess;
    idx_max = (WorkingSet.nVarMax - nVarOrig) - 1;
    if (idx_max < 1) {
      qpfvalLinearExcess = 0.0;
      qpfvalQuadExcess = 0.0;
    } else {
      n_t = (ptrdiff_t)idx_max;
      incx_t = (ptrdiff_t)1;
      qpfvalLinearExcess = dasum(&n_t, &b_TrialState.xstar[nVarOrig], &incx_t);
      n_t = (ptrdiff_t)idx_max;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      qpfvalQuadExcess = ddot(&n_t, &b_TrialState.xstar[nVarOrig], &incx_t,
                              &b_TrialState.xstar[nVarOrig], &incy_t);
    }
    qpfvalLinearExcess = (b_TrialState.fstar - rho * qpfvalLinearExcess) -
                         beta / 2.0 * qpfvalQuadExcess;
    st.site = &ui_emlrtRSI;
    qpfvalQuadExcess = b_MeritFunction.penaltyParam;
    if (mEq < 1) {
      beta = 0.0;
    } else {
      n_t = (ptrdiff_t)mEq;
      incx_t = (ptrdiff_t)1;
      beta = dasum(&n_t, &b_TrialState.cEq.data[0], &incx_t);
    }
    b_st.site = &ri_emlrtRSI;
    rho = MeritFunction::computeConstrViolationIneq_(b_st, mIneq,
                                                     b_TrialState.cIneq);
    rho += beta;
    beta = b_MeritFunction.linearizedConstrViol;
    if (idx_max < 1) {
      b_MeritFunction.linearizedConstrViol = 0.0;
    } else {
      n_t = (ptrdiff_t)idx_max;
      incx_t = (ptrdiff_t)1;
      b_MeritFunction.linearizedConstrViol =
          dasum(&n_t, &b_TrialState.xstar[nVarOrig], &incx_t);
    }
    beta = (rho + beta) - b_MeritFunction.linearizedConstrViol;
    if ((beta > 2.2204460492503131E-16) && (qpfvalLinearExcess > 0.0)) {
      if (b_TrialState.sqpFval == 0.0) {
        qpfvalQuadExcess = 1.0;
      } else {
        qpfvalQuadExcess = 1.5;
      }
      qpfvalQuadExcess = qpfvalQuadExcess * qpfvalLinearExcess / beta;
    }
    if (qpfvalQuadExcess < b_MeritFunction.penaltyParam) {
      b_MeritFunction.phi = b_TrialState.sqpFval + qpfvalQuadExcess * rho;
      if ((b_MeritFunction.initFval +
           qpfvalQuadExcess * (b_MeritFunction.initConstrViolationEq +
                               b_MeritFunction.initConstrViolationIneq)) -
              b_MeritFunction.phi >
          static_cast<real_T>(b_MeritFunction.nPenaltyDecreases) *
              b_MeritFunction.threshold) {
        b_MeritFunction.nPenaltyDecreases++;
        if ((b_MeritFunction.nPenaltyDecreases << 1) >
            b_TrialState.sqpIterations) {
          b_MeritFunction.threshold *= 10.0;
        }
        b_MeritFunction.penaltyParam =
            muDoubleScalarMax(qpfvalQuadExcess, 1.0E-10);
      } else {
        b_MeritFunction.phi =
            b_TrialState.sqpFval + b_MeritFunction.penaltyParam * rho;
      }
    } else {
      b_MeritFunction.penaltyParam =
          muDoubleScalarMax(qpfvalQuadExcess, 1.0E-10);
      b_MeritFunction.phi =
          b_TrialState.sqpFval + b_MeritFunction.penaltyParam * rho;
    }
    b_MeritFunction.phiPrimePlus = muDoubleScalarMin(
        qpfvalLinearExcess - b_MeritFunction.penaltyParam * rho, 0.0);
    idx_max = WorkingSet.isActiveIdx[1] - 1;
    st.site = &ui_emlrtRSI;
    if (mEq > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (idx = 0; idx < mEq; idx++) {
      i = memspace.workspace_int.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ce_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (memspace.workspace_int[idx] != 0) {
        i = memspace.workspace_int.size(0);
        i1 = (idx + mEq) + 1;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ce_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if (memspace.workspace_int[i1 - 1] != 0) {
          tf = true;
        } else {
          tf = false;
        }
      } else {
        tf = false;
      }
      i = b_TrialState.lambda.size(0);
      i1 = (idx_max + idx) + 1;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ce_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = b_TrialState.lambda.size(0);
      if (i1 > i) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ce_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_TrialState.lambda[i1 - 1] =
          static_cast<real_T>(tf) * b_TrialState.lambda[i1 - 1];
    }
    idx_max = WorkingSet.isActiveIdx[2];
    b_mEq = WorkingSet.nActiveConstr;
    st.site = &ui_emlrtRSI;
    if ((WorkingSet.isActiveIdx[2] <= WorkingSet.nActiveConstr) &&
        (WorkingSet.nActiveConstr > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (idx = idx_max; idx <= b_mEq; idx++) {
      i = WorkingSet.Wlocalidx.size(0);
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ce_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = WorkingSet.Wid.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ce_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (WorkingSet.Wid[idx - 1] == 3) {
        i = memspace.workspace_int.size(0);
        i1 = WorkingSet.Wlocalidx[idx - 1] + (mEq << 1);
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ce_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambda.size(0);
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ce_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambda.size(0);
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ce_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        b_TrialState.lambda[idx - 1] =
            static_cast<real_T>(memspace.workspace_int[i1 - 1]) *
            b_TrialState.lambda[idx - 1];
      }
    }
  }
  st.site = &ui_emlrtRSI;
  nArtificial = WorkingSet.sizes[0];
  mEq = WorkingSet.sizes[1];
  idx_max =
      (WorkingSet.sizes[3] - nArtificial_tmp_tmp_tmp) - WorkingSet.sizes[2];
  idx = WorkingSet.nActiveConstr;
  while ((idx > nArtificial + mEq) && (nActiveLBArtificial > 0)) {
    i = WorkingSet.Wid.size(0);
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ee_emlrtBCI, &st);
    }
    i = WorkingSet.Wid[idx - 1];
    if (i == 4) {
      i = WorkingSet.Wlocalidx.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ee_emlrtBCI, &st);
      }
      i = WorkingSet.Wlocalidx[idx - 1];
      if (i > idx_max) {
        i1 = b_TrialState.lambda.size(0);
        if ((WorkingSet.nActiveConstr < 1) || (WorkingSet.nActiveConstr > i1)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.nActiveConstr, 1, i1,
                                        &ee_emlrtBCI, &st);
        }
        b_mEq = WorkingSet.nActiveConstr - 1;
        beta = b_TrialState.lambda[b_mEq];
        i1 = b_TrialState.lambda.size(0);
        if ((WorkingSet.nActiveConstr < 1) || (WorkingSet.nActiveConstr > i1)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.nActiveConstr, 1, i1,
                                        &ee_emlrtBCI, &st);
        }
        b_TrialState.lambda[b_mEq] = 0.0;
        i1 = b_TrialState.lambda.size(0);
        if (idx > i1) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &ee_emlrtBCI, &st);
        }
        b_TrialState.lambda[idx - 1] = beta;
        b_st.site = &xi_emlrtRSI;
        i1 = WorkingSet.Wid.size(0);
        if (idx > i1) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &kc_emlrtBCI, &b_st);
        }
        i1 = WorkingSet.Wlocalidx.size(0);
        if (idx > i1) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &kc_emlrtBCI, &b_st);
        }
        i1 = WorkingSet.isActiveConstr.size(0);
        i = (WorkingSet.isActiveIdx[3] + i) - 1;
        if ((i < 1) || (i > i1)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, i1, &kc_emlrtBCI, &b_st);
        }
        WorkingSet.isActiveConstr[i - 1] = false;
        c_st.site = &dg_emlrtRSI;
        qpactiveset::WorkingSet::moveConstraint_(c_st, WorkingSet,
                                                 WorkingSet.nActiveConstr, idx);
        WorkingSet.nActiveConstr = b_mEq;
        WorkingSet.nWConstr[3]--;
        nActiveLBArtificial--;
      }
    }
    idx--;
  }
  QPObjective.nvar = nVarOrig;
  QPObjective.hasLinear = true;
  QPObjective.objtype = 3;
  st.site = &ui_emlrtRSI;
  WorkingSet.nVar = WorkingSet.nVarOrig;
  WorkingSet.mConstr = WorkingSet.mConstrOrig;
  if (WorkingSet.nWConstr[4] > 0) {
    idx_max = WorkingSet.sizesNormal[4];
    b_st.site = &bf_emlrtRSI;
    if (WorkingSet.sizesNormal[4] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (idx = 0; idx < idx_max; idx++) {
      i = WorkingSet.isActiveConstr.size(0);
      i1 = WorkingSet.isActiveIdx[4] + idx;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ub_emlrtBCI, &st);
      }
      i = WorkingSet.isActiveConstr.size(0);
      i2 = WorkingSet.isActiveIdxNormal[4] + idx;
      if ((i2 < 1) || (i2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ub_emlrtBCI, &st);
      }
      WorkingSet.isActiveConstr[i2 - 1] = WorkingSet.isActiveConstr[i1 - 1];
    }
  }
  for (i = 0; i < 5; i++) {
    WorkingSet.sizes[i] = WorkingSet.sizesNormal[i];
  }
  for (i = 0; i < 6; i++) {
    WorkingSet.isActiveIdx[i] = WorkingSet.isActiveIdxNormal[i];
  }
  WorkingSet.probType = 3;
  st.site = &ui_emlrtRSI;
  qpactiveset::parseoutput::sortLambdaQP(
      st, b_TrialState.lambda, WorkingSet.nActiveConstr, WorkingSet.sizes,
      WorkingSet.isActiveIdx, WorkingSet.Wid, WorkingSet.Wlocalidx,
      memspace.workspace_double);
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (relaxed.cpp)
