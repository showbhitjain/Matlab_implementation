//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// step.cpp
//
// Code generation for function 'step'
//

// Include files
#include "step.h"
#include "addAeqConstr.h"
#include "computeConstrViolationIneq_.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "makeBoundFeasible.h"
#include "relaxed.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "soc.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    vf_emlrtRSI{
        1,      // lineNo
        "step", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
        "step.p" // pathName
    };

static emlrtRSInfo wf_emlrtRSI{
    1,        // lineNo
    "normal", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "normal.p" // pathName
};

static emlrtRSInfo cj_emlrtRSI{
    1,                   // lineNo
    "saturateDirection", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "saturateDirection.p" // pathName
};

static emlrtRSInfo dj_emlrtRSI{
    1,           // lineNo
    "BFGSReset", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "BFGSReset.p" // pathName
};

static emlrtBCInfo ec_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    1,           // lineNo
    1,           // colNo
    "",          // aName
    "BFGSReset", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "BFGSReset.p", // pName
    0              // checkKind
};

static emlrtBCInfo fc_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    1,                   // lineNo
    1,                   // colNo
    "",                  // aName
    "saturateDirection", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "saturateDirection.p", // pName
    0                      // checkKind
};

static emlrtBCInfo gc_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    1,        // lineNo
    1,        // colNo
    "",       // aName
    "normal", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "normal.p", // pName
    0           // checkKind
};

static emlrtBCInfo
    hc_emlrtBCI{
        -1,     // iFirst
        -1,     // iLast
        1,      // lineNo
        1,      // colNo
        "",     // aName
        "step", // fName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
        "step.p", // pName
        0         // checkKind
    };

static emlrtRTEInfo
    qd_emlrtRTEI{
        1,      // lineNo
        1,      // colNo
        "step", // fName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
        "step.p" // pName
    };

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
boolean_T b_step(const emlrtStack &sp, int32_T &STEP_TYPE,
                 array<real_T, 2U> &Hessian, const array<real_T, 2U> &lb,
                 const array<real_T, 2U> &ub, j_struct_T &b_TrialState,
                 struct_T &b_MeritFunction, h_struct_T &memspace,
                 d_struct_T &WorkingSet, e_struct_T &b_QRManager,
                 f_struct_T &b_CholManager, g_struct_T &QPObjective,
                 k_struct_T &qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  k_struct_T b_qpoptions;
  real_T constrViolationEq;
  real_T constrViolationIneq;
  int32_T b_nVar;
  int32_T i;
  int32_T iH0;
  int32_T nVar;
  boolean_T checkBoundViolation;
  boolean_T stepSuccess;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  stepSuccess = true;
  checkBoundViolation = true;
  nVar = WorkingSet.nVar;
  if (STEP_TYPE != 3) {
    st.site = &vf_emlrtRSI;
    if (WorkingSet.nVar >= 1) {
      b_st.site = &ub_emlrtRSI;
      n_t = (ptrdiff_t)WorkingSet.nVar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.xstarsqp.data())[0], &incx_t,
            &(b_TrialState.xstar.data())[0], &incy_t);
    }
  } else {
    st.site = &vf_emlrtRSI;
    if (WorkingSet.nVar >= 1) {
      b_st.site = &ub_emlrtRSI;
      n_t = (ptrdiff_t)WorkingSet.nVar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.xstar.data())[0], &incx_t,
            &(b_TrialState.searchDir.data())[0], &incy_t);
    }
  }
  int32_T exitg1;
  boolean_T guard1;
  do {
    exitg1 = 0;
    guard1 = false;
    switch (STEP_TYPE) {
    case 1: {
      boolean_T nonlinEqRemoved;
      st.site = &vf_emlrtRSI;
      r.set_size(&qd_emlrtRTEI, &st, b_TrialState.grad.size(0));
      iH0 = b_TrialState.grad.size(0);
      for (i = 0; i < iH0; i++) {
        r[i] = b_TrialState.grad[i];
      }
      b_qpoptions = qpoptions;
      b_st.site = &wf_emlrtRSI;
      ::coder::optim::coder::qpactiveset::driver(
          b_st, Hessian, r, b_TrialState, memspace, WorkingSet, b_QRManager,
          b_CholManager, QPObjective, b_qpoptions, qpoptions.MaxIterations);
      if (b_TrialState.state > 0) {
        real_T penaltyParamTrial;
        b_st.site = &wf_emlrtRSI;
        penaltyParamTrial = b_MeritFunction.penaltyParam;
        if (WorkingSet.sizes[1] < 1) {
          constrViolationEq = 0.0;
        } else {
          n_t = (ptrdiff_t)WorkingSet.sizes[1];
          incx_t = (ptrdiff_t)1;
          constrViolationEq = dasum(&n_t, &b_TrialState.cEq.data[0], &incx_t);
        }
        c_st.site = &ri_emlrtRSI;
        constrViolationIneq = MeritFunction::computeConstrViolationIneq_(
            c_st, WorkingSet.sizes[2], b_TrialState.cIneq);
        constrViolationIneq += constrViolationEq;
        constrViolationEq = b_MeritFunction.linearizedConstrViol;
        b_MeritFunction.linearizedConstrViol = 0.0;
        constrViolationEq += constrViolationIneq;
        if ((constrViolationEq > 2.2204460492503131E-16) &&
            (b_TrialState.fstar > 0.0)) {
          if (b_TrialState.sqpFval == 0.0) {
            penaltyParamTrial = 1.0;
          } else {
            penaltyParamTrial = 1.5;
          }
          penaltyParamTrial =
              penaltyParamTrial * b_TrialState.fstar / constrViolationEq;
        }
        if (penaltyParamTrial < b_MeritFunction.penaltyParam) {
          b_MeritFunction.phi =
              b_TrialState.sqpFval + penaltyParamTrial * constrViolationIneq;
          if ((b_MeritFunction.initFval +
               penaltyParamTrial * (b_MeritFunction.initConstrViolationEq +
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
                muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
          } else {
            b_MeritFunction.phi =
                b_TrialState.sqpFval +
                b_MeritFunction.penaltyParam * constrViolationIneq;
          }
        } else {
          b_MeritFunction.penaltyParam =
              muDoubleScalarMax(penaltyParamTrial, 1.0E-10);
          b_MeritFunction.phi =
              b_TrialState.sqpFval +
              b_MeritFunction.penaltyParam * constrViolationIneq;
        }
        b_MeritFunction.phiPrimePlus = muDoubleScalarMin(
            b_TrialState.fstar -
                b_MeritFunction.penaltyParam * constrViolationIneq,
            0.0);
      }
      b_st.site = &wf_emlrtRSI;
      qpactiveset::parseoutput::sortLambdaQP(
          b_st, b_TrialState.lambda, WorkingSet.nActiveConstr, WorkingSet.sizes,
          WorkingSet.isActiveIdx, WorkingSet.Wid, WorkingSet.Wlocalidx,
          memspace.workspace_double);
      nonlinEqRemoved = (WorkingSet.mEqRemoved > 0);
      if (WorkingSet.indexEqRemoved.size[0] > 0) {
        boolean_T exitg2;
        exitg2 = false;
        while ((!exitg2) && (WorkingSet.mEqRemoved > 0)) {
          i = WorkingSet.indexEqRemoved.size[0];
          if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.mEqRemoved, 1, i,
                                          &gc_emlrtBCI, &st);
          }
          i = WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1];
          if (i >= b_TrialState.iNonEq0) {
            iH0 = WorkingSet.indexEqRemoved.size[0];
            if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > iH0)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.mEqRemoved, 1, iH0,
                                            &gc_emlrtBCI, &st);
            }
            b_st.site = &wf_emlrtRSI;
            qpactiveset::WorkingSet::addAeqConstr(b_st, WorkingSet, i);
            WorkingSet.mEqRemoved--;
          } else {
            exitg2 = true;
          }
        }
      }
      if (nonlinEqRemoved) {
        b_st.site = &wf_emlrtRSI;
      }
      if ((b_TrialState.state <= 0) && (b_TrialState.state != -6)) {
        STEP_TYPE = 2;
      } else {
        st.site = &vf_emlrtRSI;
        if (nVar >= 1) {
          b_st.site = &ub_emlrtRSI;
          n_t = (ptrdiff_t)nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &(b_TrialState.xstar.data())[0], &incx_t,
                &(b_TrialState.delta_x.data())[0], &incy_t);
        }
        guard1 = true;
      }
    } break;
    case 2:
      st.site = &vf_emlrtRSI;
      qpactiveset::WorkingSet::removeAllIneqConstr(st, WorkingSet);
      st.site = &vf_emlrtRSI;
      step::makeBoundFeasible(st, b_TrialState.xstar, WorkingSet, lb, ub);
      st.site = &vf_emlrtRSI;
      step::b_relaxed(st, Hessian, b_TrialState.grad, b_TrialState,
                      b_MeritFunction, memspace, WorkingSet, b_QRManager,
                      b_CholManager, QPObjective, qpoptions);
      st.site = &vf_emlrtRSI;
      if (nVar >= 1) {
        b_st.site = &ub_emlrtRSI;
        n_t = (ptrdiff_t)nVar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_TrialState.xstar.data())[0], &incx_t,
              &(b_TrialState.delta_x.data())[0], &incy_t);
      }
      guard1 = true;
      break;
    default:
      r.set_size(&qd_emlrtRTEI, &sp, b_TrialState.grad.size(0));
      iH0 = b_TrialState.grad.size(0);
      for (i = 0; i < iH0; i++) {
        r[i] = b_TrialState.grad[i];
      }
      st.site = &vf_emlrtRSI;
      stepSuccess =
          step::soc(st, Hessian, r, b_TrialState, memspace, WorkingSet,
                    b_QRManager, b_CholManager, QPObjective, qpoptions);
      checkBoundViolation = stepSuccess;
      if (stepSuccess && (b_TrialState.state != -6)) {
        st.site = &vf_emlrtRSI;
        if (nVar > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        for (iH0 = 0; iH0 < nVar; iH0++) {
          i = b_TrialState.xstar.size(0);
          if ((iH0 + 1 < 1) || (iH0 + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(iH0 + 1, 1, i, &hc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = b_TrialState.socDirection.size(0);
          if (iH0 + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(iH0 + 1, 1, i, &hc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = b_TrialState.delta_x.size(0);
          if (iH0 + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(iH0 + 1, 1, i, &hc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          b_TrialState.delta_x[iH0] =
              b_TrialState.xstar[iH0] + b_TrialState.socDirection[iH0];
        }
      }
      guard1 = true;
      break;
    }
    if (guard1) {
      if (b_TrialState.state != -6) {
        exitg1 = 1;
      } else {
        st.site = &vf_emlrtRSI;
        b_st.site = &dj_emlrtRSI;
        c_st.site = &fd_emlrtRSI;
        if ((Hessian.size(0) == 0) || (Hessian.size(1) == 0)) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &n_emlrtRTEI,
              "Coder:toolbox:ValidateattributesexpectedNonempty",
              "MATLAB:expectedNonempty", 3, 4, 5, "input");
        }
        b_nVar = Hessian.size(0);
        constrViolationEq = 0.0;
        constrViolationIneq = 1.0;
        b_st.site = &dj_emlrtRSI;
        if (Hessian.size(0) > 2147483646) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        for (iH0 = 0; iH0 < b_nVar; iH0++) {
          i = b_TrialState.grad.size(0);
          if (iH0 + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(iH0 + 1, 1, i, &ec_emlrtBCI, &st);
          }
          constrViolationEq = muDoubleScalarMax(
              constrViolationEq, muDoubleScalarAbs(b_TrialState.grad[iH0]));
          i = b_TrialState.xstar.size(0);
          if (iH0 + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(iH0 + 1, 1, i, &ec_emlrtBCI, &st);
          }
          constrViolationIneq = muDoubleScalarMax(
              constrViolationIneq, muDoubleScalarAbs(b_TrialState.xstar[iH0]));
        }
        constrViolationEq = muDoubleScalarMax(
            2.2204460492503131E-16, constrViolationEq / constrViolationIneq);
        b_st.site = &dj_emlrtRSI;
        if (Hessian.size(0) > 2147483646) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        for (int32_T idx_col{0}; idx_col < b_nVar; idx_col++) {
          iH0 = b_nVar * idx_col + 1;
          b_st.site = &dj_emlrtRSI;
          ::coder::internal::blas::xcopy(b_st, idx_col, Hessian, iH0);
          i = Hessian.size(0);
          if (idx_col + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &ec_emlrtBCI, &st);
          }
          i = Hessian.size(1);
          if (idx_col + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &ec_emlrtBCI, &st);
          }
          Hessian[idx_col + Hessian.size(0) * idx_col] = constrViolationEq;
          iH0 = (iH0 + idx_col) + 1;
          b_st.site = &dj_emlrtRSI;
          ::coder::internal::blas::xcopy(b_st, (b_nVar - idx_col) - 1, Hessian,
                                         iH0);
        }
      }
    }
  } while (exitg1 == 0);
  if (checkBoundViolation) {
    b_nVar = WorkingSet.sizes[3];
    nVar = WorkingSet.sizes[4];
    st.site = &vf_emlrtRSI;
    r.set_size(&qd_emlrtRTEI, &st, b_TrialState.delta_x.size(0));
    iH0 = b_TrialState.delta_x.size(0);
    for (i = 0; i < iH0; i++) {
      r[i] = b_TrialState.delta_x[i];
    }
    if (lb.size(0) != 0) {
      b_st.site = &cj_emlrtRSI;
      if (WorkingSet.sizes[3] > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (iH0 = 0; iH0 < b_nVar; iH0++) {
        i = WorkingSet.indexLB.size(0);
        if ((iH0 + 1 < 1) || (iH0 + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(iH0 + 1, 1, i, &fc_emlrtBCI, &st);
        }
        i = b_TrialState.xstarsqp.size(0);
        if ((WorkingSet.indexLB[iH0] < 1) || (WorkingSet.indexLB[iH0] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[iH0], 1, i,
                                        &fc_emlrtBCI, &st);
        }
        if ((WorkingSet.indexLB[iH0] < 1) ||
            (WorkingSet.indexLB[iH0] > r.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[iH0], 1, r.size(0),
                                        &fc_emlrtBCI, &st);
        }
        if ((WorkingSet.indexLB[iH0] < 1) ||
            (WorkingSet.indexLB[iH0] > lb.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[iH0], 1, lb.size(0),
                                        &fc_emlrtBCI, &st);
        }
        constrViolationEq = r[WorkingSet.indexLB[iH0] - 1];
        constrViolationIneq =
            (b_TrialState.xstarsqp[WorkingSet.indexLB[iH0] - 1] +
             constrViolationEq) -
            lb[WorkingSet.indexLB[iH0] - 1];
        if (constrViolationIneq < 0.0) {
          if ((WorkingSet.indexLB[iH0] < 1) ||
              (WorkingSet.indexLB[iH0] > r.size(0))) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[iH0], 1, r.size(0),
                                          &fc_emlrtBCI, &st);
          }
          if ((WorkingSet.indexLB[iH0] < 1) ||
              (WorkingSet.indexLB[iH0] > r.size(0))) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[iH0], 1, r.size(0),
                                          &fc_emlrtBCI, &st);
          }
          r[WorkingSet.indexLB[iH0] - 1] =
              constrViolationEq - constrViolationIneq;
          i = b_TrialState.xstar.size(0);
          if ((WorkingSet.indexLB[iH0] < 1) || (WorkingSet.indexLB[iH0] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[iH0], 1, i,
                                          &fc_emlrtBCI, &st);
          }
          i = b_TrialState.xstar.size(0);
          if ((WorkingSet.indexLB[iH0] < 1) || (WorkingSet.indexLB[iH0] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[iH0], 1, i,
                                          &fc_emlrtBCI, &st);
          }
          b_TrialState.xstar[WorkingSet.indexLB[iH0] - 1] =
              b_TrialState.xstar[WorkingSet.indexLB[iH0] - 1] -
              constrViolationIneq;
        }
      }
    }
    if (ub.size(0) != 0) {
      b_st.site = &cj_emlrtRSI;
      if (WorkingSet.sizes[4] > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (iH0 = 0; iH0 < nVar; iH0++) {
        i = WorkingSet.indexUB.size(0);
        if ((iH0 + 1 < 1) || (iH0 + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(iH0 + 1, 1, i, &fc_emlrtBCI, &st);
        }
        if ((WorkingSet.indexUB[iH0] < 1) ||
            (WorkingSet.indexUB[iH0] > ub.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[iH0], 1, ub.size(0),
                                        &fc_emlrtBCI, &st);
        }
        i = b_TrialState.xstarsqp.size(0);
        if ((WorkingSet.indexUB[iH0] < 1) || (WorkingSet.indexUB[iH0] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[iH0], 1, i,
                                        &fc_emlrtBCI, &st);
        }
        if ((WorkingSet.indexUB[iH0] < 1) ||
            (WorkingSet.indexUB[iH0] > r.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[iH0], 1, r.size(0),
                                        &fc_emlrtBCI, &st);
        }
        constrViolationEq = r[WorkingSet.indexUB[iH0] - 1];
        constrViolationIneq =
            (ub[WorkingSet.indexUB[iH0] - 1] -
             b_TrialState.xstarsqp[WorkingSet.indexUB[iH0] - 1]) -
            constrViolationEq;
        if (constrViolationIneq < 0.0) {
          if ((WorkingSet.indexUB[iH0] < 1) ||
              (WorkingSet.indexUB[iH0] > r.size(0))) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[iH0], 1, r.size(0),
                                          &fc_emlrtBCI, &st);
          }
          if ((WorkingSet.indexUB[iH0] < 1) ||
              (WorkingSet.indexUB[iH0] > r.size(0))) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[iH0], 1, r.size(0),
                                          &fc_emlrtBCI, &st);
          }
          r[WorkingSet.indexUB[iH0] - 1] =
              constrViolationEq + constrViolationIneq;
          i = b_TrialState.xstar.size(0);
          if ((WorkingSet.indexUB[iH0] < 1) || (WorkingSet.indexUB[iH0] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[iH0], 1, i,
                                          &fc_emlrtBCI, &st);
          }
          i = b_TrialState.xstar.size(0);
          if ((WorkingSet.indexUB[iH0] < 1) || (WorkingSet.indexUB[iH0] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[iH0], 1, i,
                                          &fc_emlrtBCI, &st);
          }
          b_TrialState.xstar[WorkingSet.indexUB[iH0] - 1] =
              b_TrialState.xstar[WorkingSet.indexUB[iH0] - 1] +
              constrViolationIneq;
        }
      }
    }
    b_TrialState.delta_x.set_size(&qd_emlrtRTEI, &sp, r.size(0));
    iH0 = r.size(0);
    for (i = 0; i < iH0; i++) {
      b_TrialState.delta_x[i] = r[i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return stepSuccess;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (step.cpp)
