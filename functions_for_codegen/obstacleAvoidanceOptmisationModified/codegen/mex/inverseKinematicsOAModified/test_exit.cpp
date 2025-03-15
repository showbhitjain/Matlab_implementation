//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// test_exit.cpp
//
// Code generation for function 'test_exit'
//

// Include files
#include "test_exit.h"
#include "computeComplError.h"
#include "computeDualFeasError.h"
#include "computeGradLag.h"
#include "computePrimalFeasError.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "isDeltaXTooSmall.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xgeqp3.h"
#include "xtrsv.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo hf_emlrtRSI{
    1,           // lineNo
    "test_exit", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "test_exit.p" // pathName
};

static emlrtRSInfo pf_emlrtRSI{
    1,                  // lineNo
    "computeLambdaLSQ", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeLambdaLSQ.p" // pathName
};

static emlrtBCInfo ac_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    1,           // lineNo
    1,           // colNo
    "",          // aName
    "test_exit", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "test_exit.p", // pName
    0              // checkKind
};

static emlrtBCInfo ke_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    1,                  // lineNo
    1,                  // colNo
    "",                 // aName
    "computeLambdaLSQ", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeLambdaLSQ.p", // pName
    0                               // checkKind
};

static emlrtRTEInfo sb_emlrtRTEI{
    1,           // lineNo
    1,           // colNo
    "test_exit", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "test_exit.p" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "computeLambdaLSQ", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeLambdaLSQ.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(const emlrtStack &sp, b_struct_T &Flags, h_struct_T &memspace,
                 struct_T &b_MeritFunction,
                 int32_T fscales_lineq_constraint_size,
                 const d_struct_T &WorkingSet, j_struct_T &b_TrialState,
                 e_struct_T &b_QRManager, const real_T lb_data[],
                 int32_T lb_size, const real_T ub_data[], int32_T ub_size,
                 int32_T c_runTimeOptions_MaxFunctionEva)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> b_y;
  array<real_T, 1U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T nlpComplErrorLSQ;
  real_T optimRelativeFactor;
  int32_T i;
  int32_T idx_max;
  int32_T mLambda;
  int32_T mLambda_tmp;
  int32_T nVar;
  boolean_T isFeasible;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  nVar = WorkingSet.nVar;
  mLambda_tmp = WorkingSet.sizes[0] + WorkingSet.sizes[1];
  mLambda = ((mLambda_tmp + WorkingSet.sizes[2]) + WorkingSet.sizes[3]) +
            WorkingSet.sizes[4];
  st.site = &hf_emlrtRSI;
  y.set_size(&sb_emlrtRTEI, &st, b_TrialState.lambdaStopTest.size[0]);
  idx_max = b_TrialState.lambdaStopTest.size[0];
  for (i = 0; i < idx_max; i++) {
    y[i] = b_TrialState.lambdaStopTest.data[i];
  }
  if (mLambda >= 1) {
    b_st.site = &ub_emlrtRSI;
    c_st.site = &wb_emlrtRSI;
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &b_TrialState.lambdasqp.data[0], &incx_t, &(y.data())[0],
          &incy_t);
  }
  b_TrialState.lambdaStopTest.size[0] = y.size(0);
  idx_max = y.size(0);
  for (i = 0; i < idx_max; i++) {
    b_TrialState.lambdaStopTest.data[i] = y[i];
  }
  st.site = &hf_emlrtRSI;
  stopping::computeGradLag(
      st, b_TrialState.gradLag, WorkingSet.ldA, WorkingSet.nVar,
      b_TrialState.grad, WorkingSet.sizes[2], WorkingSet.Aineq,
      WorkingSet.sizes[1], WorkingSet.Aeq, WorkingSet.indexFixed,
      WorkingSet.sizes[0], WorkingSet.indexLB, WorkingSet.sizes[3],
      WorkingSet.indexUB, WorkingSet.sizes[4], (const real_T *)y.data(),
      (*(int32_T(*)[1])y.size())[0]);
  if (WorkingSet.nVar < 1) {
    idx_max = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &(b_TrialState.grad.data())[0], &incx_t);
    idx_max = (int32_T)n_t;
  }
  i = b_TrialState.grad.size(0);
  if ((idx_max < 1) || (idx_max > i)) {
    emlrtDynamicBoundsCheckR2012b(idx_max, 1, i, &ac_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(b_TrialState.grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &hf_emlrtRSI;
  b_MeritFunction.nlpPrimalFeasError = stopping::computePrimalFeasError(
      st, b_TrialState.xstarsqp, WorkingSet.sizes[2], b_TrialState.cIneq.data,
      b_TrialState.cIneq.size[0], WorkingSet.sizes[1], b_TrialState.cEq.data,
      b_TrialState.cEq.size[0], WorkingSet.indexLB, WorkingSet.sizes[3],
      lb_data, lb_size, WorkingSet.indexUB, WorkingSet.sizes[4], ub_data,
      ub_size);
  if (b_TrialState.sqpIterations == 0) {
    b_MeritFunction.feasRelativeFactor =
        muDoubleScalarMax(1.0, b_MeritFunction.nlpPrimalFeasError);
  }
  isFeasible = (b_MeritFunction.nlpPrimalFeasError <=
                1.8967E-5 * b_MeritFunction.feasRelativeFactor);
  st.site = &hf_emlrtRSI;
  Flags.gradOK =
      stopping::computeDualFeasError(st, WorkingSet.nVar, b_TrialState.gradLag,
                                     b_MeritFunction.nlpDualFeasError);
  if (!Flags.gradOK) {
    Flags.done = true;
    if (isFeasible) {
      b_TrialState.sqpExitFlag = 2;
    } else {
      b_TrialState.sqpExitFlag = -2;
    }
  } else {
    real_T tol;
    st.site = &hf_emlrtRSI;
    b_MeritFunction.nlpComplError = stopping::computeComplError(
        st, fscales_lineq_constraint_size, b_TrialState.xstarsqp,
        WorkingSet.sizes[2], b_TrialState.cIneq.data,
        b_TrialState.cIneq.size[0], WorkingSet.indexLB, WorkingSet.sizes[3],
        lb_data, lb_size, WorkingSet.indexUB, WorkingSet.sizes[4], ub_data,
        ub_size, (const real_T *)y.data(), (*(int32_T(*)[1])y.size())[0],
        (WorkingSet.sizes[0] + WorkingSet.sizes[1]) + 1);
    tol = muDoubleScalarMax(b_MeritFunction.nlpDualFeasError,
                            b_MeritFunction.nlpComplError);
    b_MeritFunction.firstOrderOpt = tol;
    if (b_TrialState.sqpIterations > 1) {
      real_T d;
      real_T nlpComplErrorTmp;
      st.site = &hf_emlrtRSI;
      stopping::computeGradLag(
          st, memspace.workspace_double, WorkingSet.ldA, WorkingSet.nVar,
          b_TrialState.grad, WorkingSet.sizes[2], WorkingSet.Aineq,
          WorkingSet.sizes[1], WorkingSet.Aeq, WorkingSet.indexFixed,
          WorkingSet.sizes[0], WorkingSet.indexLB, WorkingSet.sizes[3],
          WorkingSet.indexUB, WorkingSet.sizes[4],
          b_TrialState.lambdaStopTestPrev.data,
          b_TrialState.lambdaStopTestPrev.size[0]);
      st.site = &hf_emlrtRSI;
      stopping::computeDualFeasError(
          st, WorkingSet.nVar, memspace.workspace_double, nlpComplErrorLSQ);
      st.site = &hf_emlrtRSI;
      nlpComplErrorTmp = stopping::computeComplError(
          st, fscales_lineq_constraint_size, b_TrialState.xstarsqp,
          WorkingSet.sizes[2], b_TrialState.cIneq.data,
          b_TrialState.cIneq.size[0], WorkingSet.indexLB, WorkingSet.sizes[3],
          lb_data, lb_size, WorkingSet.indexUB, WorkingSet.sizes[4], ub_data,
          ub_size, b_TrialState.lambdaStopTestPrev.data,
          b_TrialState.lambdaStopTestPrev.size[0],
          (WorkingSet.sizes[0] + WorkingSet.sizes[1]) + 1);
      d = muDoubleScalarMax(nlpComplErrorLSQ, nlpComplErrorTmp);
      if (d < tol) {
        b_MeritFunction.nlpDualFeasError = nlpComplErrorLSQ;
        b_MeritFunction.nlpComplError = nlpComplErrorTmp;
        b_MeritFunction.firstOrderOpt = d;
        st.site = &hf_emlrtRSI;
        if (mLambda >= 1) {
          b_st.site = &ub_emlrtRSI;
          c_st.site = &wb_emlrtRSI;
          n_t = (ptrdiff_t)mLambda;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &b_TrialState.lambdaStopTestPrev.data[0], &incx_t,
                &(y.data())[0], &incy_t);
        }
        b_TrialState.lambdaStopTest.size[0] = y.size(0);
        idx_max = y.size(0);
        for (i = 0; i < idx_max; i++) {
          b_TrialState.lambdaStopTest.data[i] = y[i];
        }
      } else {
        st.site = &hf_emlrtRSI;
        b_y.set_size(&sb_emlrtRTEI, &st,
                     b_TrialState.lambdaStopTestPrev.size[0]);
        idx_max = b_TrialState.lambdaStopTestPrev.size[0];
        for (i = 0; i < idx_max; i++) {
          b_y[i] = b_TrialState.lambdaStopTestPrev.data[i];
        }
        if (mLambda >= 1) {
          b_st.site = &ub_emlrtRSI;
          c_st.site = &wb_emlrtRSI;
          n_t = (ptrdiff_t)mLambda;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &(y.data())[0], &incx_t, &(b_y.data())[0], &incy_t);
        }
        b_TrialState.lambdaStopTestPrev.size[0] = b_y.size(0);
        idx_max = b_y.size(0);
        for (i = 0; i < idx_max; i++) {
          b_TrialState.lambdaStopTestPrev.data[i] = b_y[i];
        }
      }
    } else {
      st.site = &hf_emlrtRSI;
      b_y.set_size(&sb_emlrtRTEI, &st, b_TrialState.lambdaStopTestPrev.size[0]);
      idx_max = b_TrialState.lambdaStopTestPrev.size[0];
      for (i = 0; i < idx_max; i++) {
        b_y[i] = b_TrialState.lambdaStopTestPrev.data[i];
      }
      if (mLambda >= 1) {
        b_st.site = &ub_emlrtRSI;
        c_st.site = &wb_emlrtRSI;
        n_t = (ptrdiff_t)mLambda;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(y.data())[0], &incx_t, &(b_y.data())[0], &incy_t);
      }
      b_TrialState.lambdaStopTestPrev.size[0] = b_y.size(0);
      idx_max = b_y.size(0);
      for (i = 0; i < idx_max; i++) {
        b_TrialState.lambdaStopTestPrev.data[i] = b_y[i];
      }
    }
    if (isFeasible &&
        (b_MeritFunction.nlpDualFeasError <= 0.001254 * optimRelativeFactor) &&
        (b_MeritFunction.nlpComplError <= 0.001254 * optimRelativeFactor)) {
      Flags.done = true;
      b_TrialState.sqpExitFlag = 1;
    } else {
      Flags.done = false;
      if (isFeasible && (b_TrialState.sqpFval < -1.0E+6)) {
        Flags.done = true;
        b_TrialState.sqpExitFlag = -3;
      } else {
        boolean_T guard1;
        guard1 = false;
        if (b_TrialState.sqpIterations > 0) {
          boolean_T dxTooSmall;
          st.site = &hf_emlrtRSI;
          dxTooSmall = stopping::isDeltaXTooSmall(
              st, b_TrialState.xstarsqp, b_TrialState.delta_x, WorkingSet.nVar);
          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags.stepType != 2) {
                Flags.stepType = 2;
                Flags.failedLineSearch = false;
                Flags.stepAccepted = false;
                guard1 = true;
              } else {
                Flags.done = true;
                b_TrialState.sqpExitFlag = -2;
              }
            } else {
              int32_T nActiveConstr;
              nActiveConstr = WorkingSet.nActiveConstr;
              if (WorkingSet.nActiveConstr > 0) {
                boolean_T exitg1;
                boolean_T guard2;
                st.site = &hf_emlrtRSI;
                y.set_size(&fc_emlrtRTEI, &st, b_TrialState.lambda.size[0]);
                idx_max = b_TrialState.lambda.size[0];
                for (i = 0; i < idx_max; i++) {
                  y[i] = b_TrialState.lambda.data[i];
                }
                b_st.site = &pf_emlrtRSI;
                ::coder::internal::blas::xcopy(b_st, WorkingSet.nActiveConstr,
                                               y);
                b_st.site = &pf_emlrtRSI;
                i = WorkingSet.nVar * WorkingSet.nActiveConstr;
                guard2 = false;
                if (i > 0) {
                  c_st.site = &ec_emlrtRSI;
                  if (WorkingSet.nActiveConstr > 2147483646) {
                    d_st.site = &o_emlrtRSI;
                    check_forloop_overflow_error(d_st);
                  }
                  for (int32_T idx{0}; idx < nActiveConstr; idx++) {
                    c_st.site = &ec_emlrtRSI;
                    if (nVar >= 1) {
                      n_t = (ptrdiff_t)nVar;
                      incx_t = (ptrdiff_t)1;
                      incy_t = (ptrdiff_t)1;
                      dcopy(&n_t,
                            (real_T *)&WorkingSet.ATwset[WorkingSet.ldA * idx],
                            &incx_t, &b_QRManager.QR[b_QRManager.ldq * idx],
                            &incy_t);
                    }
                  }
                  guard2 = true;
                } else if (i == 0) {
                  b_QRManager.mrows = WorkingSet.nVar;
                  b_QRManager.ncols = WorkingSet.nActiveConstr;
                  b_QRManager.minRowCol = 0;
                } else {
                  guard2 = true;
                }
                if (guard2) {
                  b_QRManager.usedPivoting = true;
                  b_QRManager.mrows = WorkingSet.nVar;
                  b_QRManager.ncols = WorkingSet.nActiveConstr;
                  b_QRManager.minRowCol = muIntScalarMin_sint32(
                      WorkingSet.nVar, WorkingSet.nActiveConstr);
                  c_st.site = &ec_emlrtRSI;
                  ::coder::internal::lapack::xgeqp3(
                      c_st, b_QRManager.QR, WorkingSet.nVar,
                      WorkingSet.nActiveConstr, b_QRManager.jpvt,
                      b_QRManager.tau);
                }
                b_st.site = &pf_emlrtRSI;
                c_st.site = &yc_emlrtRSI;
                QRManager::computeQ_(c_st, b_QRManager, b_QRManager.mrows);
                b_st.site = &pf_emlrtRSI;
                ::coder::internal::blas::xgemv(WorkingSet.nVar, WorkingSet.nVar,
                                               b_QRManager.Q, b_QRManager.ldq,
                                               b_TrialState.grad,
                                               memspace.workspace_double);
                tol = muDoubleScalarAbs(b_QRManager.QR[0]) *
                      muDoubleScalarMin(
                          1.4901161193847656E-8,
                          static_cast<real_T>(muIntScalarMax_sint32(
                              WorkingSet.nVar, WorkingSet.nActiveConstr)) *
                              2.2204460492503131E-16);
                idx_max = muIntScalarMin_sint32(WorkingSet.nVar,
                                                WorkingSet.nActiveConstr);
                nActiveConstr = 0;
                nVar = 1;
                exitg1 = false;
                while ((!exitg1) && (nActiveConstr < idx_max)) {
                  i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
                  if ((nVar < 1) || (nVar > i)) {
                    emlrtDynamicBoundsCheckR2012b(nVar, 1, i, &ke_emlrtBCI,
                                                  &st);
                  }
                  if (muDoubleScalarAbs(b_QRManager.QR[nVar - 1]) > tol) {
                    nActiveConstr++;
                    nVar = (nVar + b_QRManager.ldq) + 1;
                  } else {
                    exitg1 = true;
                  }
                }
                b_st.site = &pf_emlrtRSI;
                ::coder::internal::blas::xtrsv(nActiveConstr, b_QRManager.QR,
                                               b_QRManager.ldq,
                                               memspace.workspace_double);
                idx_max =
                    muIntScalarMin_sint32(WorkingSet.nActiveConstr, idx_max);
                b_st.site = &pf_emlrtRSI;
                if (idx_max > 2147483646) {
                  c_st.site = &o_emlrtRSI;
                  check_forloop_overflow_error(c_st);
                }
                for (int32_T idx{0}; idx < idx_max; idx++) {
                  i = b_QRManager.jpvt.size(0);
                  if ((idx + 1 < 1) || (idx + 1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ke_emlrtBCI,
                                                  &st);
                  }
                  i = memspace.workspace_double.size(0) *
                      memspace.workspace_double.size(1);
                  if ((idx + 1 < 1) || (idx + 1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ke_emlrtBCI,
                                                  &st);
                  }
                  i = b_QRManager.jpvt[idx];
                  if ((i < 1) || (i > y.size(0))) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, y.size(0), &ke_emlrtBCI,
                                                  &st);
                  }
                  y[i - 1] = memspace.workspace_double[idx];
                }
                b_TrialState.lambda.size[0] = y.size(0);
                idx_max = y.size(0);
                for (i = 0; i < idx_max; i++) {
                  b_TrialState.lambda.data[i] = y[i];
                }
                idx_max = WorkingSet.sizes[0] + 1;
                st.site = &hf_emlrtRSI;
                if ((WorkingSet.sizes[0] + 1 <= mLambda_tmp) &&
                    (mLambda_tmp > 2147483646)) {
                  b_st.site = &o_emlrtRSI;
                  check_forloop_overflow_error(b_st);
                }
                for (int32_T idx{idx_max}; idx <= mLambda_tmp; idx++) {
                  i = b_TrialState.lambda.size[0];
                  if ((idx < 1) || (idx > i)) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ac_emlrtBCI,
                                                  (emlrtConstCTX)&sp);
                  }
                  if (idx > i) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ac_emlrtBCI,
                                                  (emlrtConstCTX)&sp);
                  }
                  b_TrialState.lambda.data[idx - 1] =
                      -b_TrialState.lambda.data[idx - 1];
                }
                st.site = &hf_emlrtRSI;
                qpactiveset::parseoutput::sortLambdaQP(
                    st, b_TrialState.lambda.data, b_TrialState.lambda.size[0],
                    WorkingSet.nActiveConstr, WorkingSet.sizes,
                    WorkingSet.isActiveIdx, WorkingSet.Wid.data,
                    WorkingSet.Wid.size[0], WorkingSet.Wlocalidx.data,
                    WorkingSet.Wlocalidx.size[0], memspace.workspace_double);
                st.site = &hf_emlrtRSI;
                stopping::computeGradLag(
                    st, memspace.workspace_double, WorkingSet.ldA,
                    WorkingSet.nVar, b_TrialState.grad, WorkingSet.sizes[2],
                    WorkingSet.Aineq, WorkingSet.sizes[1], WorkingSet.Aeq,
                    WorkingSet.indexFixed, WorkingSet.sizes[0],
                    WorkingSet.indexLB, WorkingSet.sizes[3], WorkingSet.indexUB,
                    WorkingSet.sizes[4], b_TrialState.lambda.data,
                    b_TrialState.lambda.size[0]);
                st.site = &hf_emlrtRSI;
                stopping::computeDualFeasError(st, WorkingSet.nVar,
                                               memspace.workspace_double, tol);
                st.site = &hf_emlrtRSI;
                nlpComplErrorLSQ = stopping::computeComplError(
                    st, fscales_lineq_constraint_size, b_TrialState.xstarsqp,
                    WorkingSet.sizes[2], b_TrialState.cIneq.data,
                    b_TrialState.cIneq.size[0], WorkingSet.indexLB,
                    WorkingSet.sizes[3], lb_data, lb_size, WorkingSet.indexUB,
                    WorkingSet.sizes[4], ub_data, ub_size,
                    b_TrialState.lambda.data, b_TrialState.lambda.size[0],
                    WorkingSet.sizes[0] + 1);
                if ((tol <= 0.001254 * optimRelativeFactor) &&
                    (nlpComplErrorLSQ <= 0.001254 * optimRelativeFactor)) {
                  b_MeritFunction.nlpDualFeasError = tol;
                  b_MeritFunction.nlpComplError = nlpComplErrorLSQ;
                  b_MeritFunction.firstOrderOpt =
                      muDoubleScalarMax(tol, nlpComplErrorLSQ);
                  st.site = &hf_emlrtRSI;
                  y.set_size(&sb_emlrtRTEI, &st,
                             b_TrialState.lambdaStopTest.size[0]);
                  idx_max = b_TrialState.lambdaStopTest.size[0];
                  for (i = 0; i < idx_max; i++) {
                    y[i] = b_TrialState.lambdaStopTest.data[i];
                  }
                  if (mLambda >= 1) {
                    b_st.site = &ub_emlrtRSI;
                    c_st.site = &wb_emlrtRSI;
                    n_t = (ptrdiff_t)mLambda;
                    incx_t = (ptrdiff_t)1;
                    incy_t = (ptrdiff_t)1;
                    dcopy(&n_t, &b_TrialState.lambda.data[0], &incx_t,
                          &(y.data())[0], &incy_t);
                  }
                  b_TrialState.lambdaStopTest.size[0] = y.size(0);
                  idx_max = y.size(0);
                  for (i = 0; i < idx_max; i++) {
                    b_TrialState.lambdaStopTest.data[i] = y[i];
                  }
                  Flags.done = true;
                  b_TrialState.sqpExitFlag = 1;
                } else {
                  Flags.done = true;
                  b_TrialState.sqpExitFlag = 2;
                }
              } else {
                Flags.done = true;
                b_TrialState.sqpExitFlag = 2;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          if (b_TrialState.sqpIterations >= 550) {
            Flags.done = true;
            b_TrialState.sqpExitFlag = 0;
          } else if (b_TrialState.FunctionEvaluations >=
                     c_runTimeOptions_MaxFunctionEva) {
            Flags.done = true;
            b_TrialState.sqpExitFlag = 0;
          }
        }
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

boolean_T test_exit(const emlrtStack &sp, struct_T &b_MeritFunction,
                    int32_T fscales_lineq_constraint_size,
                    const d_struct_T &WorkingSet, j_struct_T &b_TrialState,
                    const real_T lb_data[], int32_T lb_size,
                    const real_T ub_data[], int32_T ub_size,
                    int32_T c_runTimeOptions_MaxFunctionEva,
                    boolean_T &Flags_fevalOK, boolean_T &Flags_done,
                    boolean_T &Flags_stepAccepted,
                    boolean_T &Flags_failedLineSearch, int32_T &Flags_stepType)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> b_y;
  array<real_T, 1U> y;
  emlrtStack st;
  real_T optimRelativeFactor;
  int32_T i;
  int32_T idx_max;
  int32_T mLambda;
  boolean_T Flags_gradOK;
  boolean_T isFeasible;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  Flags_fevalOK = true;
  Flags_done = false;
  Flags_stepAccepted = false;
  Flags_failedLineSearch = false;
  Flags_stepType = 1;
  mLambda =
      (((WorkingSet.sizes[0] + WorkingSet.sizes[1]) + WorkingSet.sizes[2]) +
       WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  st.site = &hf_emlrtRSI;
  y.set_size(&sb_emlrtRTEI, &st, b_TrialState.lambdaStopTest.size[0]);
  idx_max = b_TrialState.lambdaStopTest.size[0];
  for (i = 0; i < idx_max; i++) {
    y[i] = b_TrialState.lambdaStopTest.data[i];
  }
  if (mLambda >= 1) {
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &b_TrialState.lambdasqp.data[0], &incx_t, &(y.data())[0],
          &incy_t);
  }
  b_TrialState.lambdaStopTest.size[0] = y.size(0);
  idx_max = y.size(0);
  for (i = 0; i < idx_max; i++) {
    b_TrialState.lambdaStopTest.data[i] = y[i];
  }
  st.site = &hf_emlrtRSI;
  stopping::computeGradLag(
      st, b_TrialState.gradLag, WorkingSet.ldA, WorkingSet.nVar,
      b_TrialState.grad, WorkingSet.sizes[2], WorkingSet.Aineq,
      WorkingSet.sizes[1], WorkingSet.Aeq, WorkingSet.indexFixed,
      WorkingSet.sizes[0], WorkingSet.indexLB, WorkingSet.sizes[3],
      WorkingSet.indexUB, WorkingSet.sizes[4], (const real_T *)y.data(),
      (*(int32_T(*)[1])y.size())[0]);
  if (WorkingSet.nVar < 1) {
    idx_max = 0;
  } else {
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    n_t = idamax(&n_t, &(b_TrialState.grad.data())[0], &incx_t);
    idx_max = (int32_T)n_t;
  }
  i = b_TrialState.grad.size(0);
  if ((idx_max < 1) || (idx_max > i)) {
    emlrtDynamicBoundsCheckR2012b(idx_max, 1, i, &ac_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(b_TrialState.grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &hf_emlrtRSI;
  b_MeritFunction.nlpPrimalFeasError = stopping::computePrimalFeasError(
      st, b_TrialState.xstarsqp, WorkingSet.sizes[2], b_TrialState.cIneq.data,
      b_TrialState.cIneq.size[0], WorkingSet.sizes[1], b_TrialState.cEq.data,
      b_TrialState.cEq.size[0], WorkingSet.indexLB, WorkingSet.sizes[3],
      lb_data, lb_size, WorkingSet.indexUB, WorkingSet.sizes[4], ub_data,
      ub_size);
  b_MeritFunction.feasRelativeFactor =
      muDoubleScalarMax(1.0, b_MeritFunction.nlpPrimalFeasError);
  isFeasible = (b_MeritFunction.nlpPrimalFeasError <=
                1.8967E-5 * b_MeritFunction.feasRelativeFactor);
  st.site = &hf_emlrtRSI;
  Flags_gradOK =
      stopping::computeDualFeasError(st, WorkingSet.nVar, b_TrialState.gradLag,
                                     b_MeritFunction.nlpDualFeasError);
  if (!Flags_gradOK) {
    Flags_done = true;
    if (isFeasible) {
      b_TrialState.sqpExitFlag = 2;
    } else {
      b_TrialState.sqpExitFlag = -2;
    }
  } else {
    st.site = &hf_emlrtRSI;
    b_MeritFunction.nlpComplError = stopping::computeComplError(
        st, fscales_lineq_constraint_size, b_TrialState.xstarsqp,
        WorkingSet.sizes[2], b_TrialState.cIneq.data,
        b_TrialState.cIneq.size[0], WorkingSet.indexLB, WorkingSet.sizes[3],
        lb_data, lb_size, WorkingSet.indexUB, WorkingSet.sizes[4], ub_data,
        ub_size, (const real_T *)y.data(), (*(int32_T(*)[1])y.size())[0],
        (WorkingSet.sizes[0] + WorkingSet.sizes[1]) + 1);
    b_MeritFunction.firstOrderOpt = muDoubleScalarMax(
        b_MeritFunction.nlpDualFeasError, b_MeritFunction.nlpComplError);
    st.site = &hf_emlrtRSI;
    b_y.set_size(&sb_emlrtRTEI, &st, b_TrialState.lambdaStopTestPrev.size[0]);
    idx_max = b_TrialState.lambdaStopTestPrev.size[0];
    for (i = 0; i < idx_max; i++) {
      b_y[i] = b_TrialState.lambdaStopTestPrev.data[i];
    }
    if (mLambda >= 1) {
      n_t = (ptrdiff_t)mLambda;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(y.data())[0], &incx_t, &(b_y.data())[0], &incy_t);
    }
    b_TrialState.lambdaStopTestPrev.size[0] = b_y.size(0);
    idx_max = b_y.size(0);
    for (i = 0; i < idx_max; i++) {
      b_TrialState.lambdaStopTestPrev.data[i] = b_y[i];
    }
    if (isFeasible &&
        (b_MeritFunction.nlpDualFeasError <= 0.001254 * optimRelativeFactor) &&
        (b_MeritFunction.nlpComplError <= 0.001254 * optimRelativeFactor)) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = 1;
    } else if (isFeasible && (b_TrialState.sqpFval < -1.0E+6)) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = -3;
    } else if (b_TrialState.FunctionEvaluations >=
               c_runTimeOptions_MaxFunctionEva) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = 0;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return Flags_gradOK;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (test_exit.cpp)
