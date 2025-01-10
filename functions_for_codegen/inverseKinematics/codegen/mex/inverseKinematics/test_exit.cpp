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
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
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
static emlrtRSInfo
    ab_emlrtRSI{
        55,           // lineNo
        "xcopy_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xcopy.m" // pathName
    };

static emlrtRSInfo mf_emlrtRSI{
    1,           // lineNo
    "test_exit", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "test_exit.p" // pathName
};

static emlrtRSInfo tf_emlrtRSI{
    1,                  // lineNo
    "computeLambdaLSQ", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeLambdaLSQ.p" // pathName
};

static emlrtBCInfo mb_emlrtBCI{
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

static emlrtBCInfo vd_emlrtBCI{
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

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(const emlrtStack &sp, b_struct_T &Flags, g_struct_T &memspace,
                 struct_T &b_MeritFunction, const j_struct_T &WorkingSet,
                 i_struct_T &b_TrialState, d_struct_T &b_QRManager,
                 const array<real_T, 1U> &lb, const array<real_T, 1U> &ub,
                 int32_T c_runTimeOptions_MaxFunctionEva)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
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
  nVar = WorkingSet.nVar;
  mLambda_tmp = WorkingSet.sizes[0] + WorkingSet.sizes[1];
  mLambda = (mLambda_tmp + WorkingSet.sizes[3]) + WorkingSet.sizes[4];
  st.site = &mf_emlrtRSI;
  if (mLambda >= 1) {
    b_st.site = &x_emlrtRSI;
    c_st.site = &ab_emlrtRSI;
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.lambdasqp.data())[0], &incx_t,
          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
  }
  st.site = &mf_emlrtRSI;
  stopping::computeGradLag(
      st, b_TrialState.gradLag, WorkingSet.ldA, WorkingSet.nVar,
      b_TrialState.grad, WorkingSet.Aineq.size[0], WorkingSet.sizes[1],
      WorkingSet.Aeq, WorkingSet.indexFixed, WorkingSet.sizes[0],
      WorkingSet.indexLB, WorkingSet.sizes[3], WorkingSet.indexUB,
      WorkingSet.sizes[4], b_TrialState.lambdaStopTest);
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
    emlrtDynamicBoundsCheckR2012b(idx_max, 1, i, &mb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(b_TrialState.grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &mf_emlrtRSI;
  b_MeritFunction.nlpPrimalFeasError = stopping::computePrimalFeasError(
      st, b_TrialState.xstarsqp, WorkingSet.sizes[1], b_TrialState.cEq.data,
      b_TrialState.cEq.size[0], WorkingSet.indexLB, WorkingSet.sizes[3], lb,
      WorkingSet.indexUB, WorkingSet.sizes[4], ub);
  if (b_TrialState.sqpIterations == 0) {
    b_MeritFunction.feasRelativeFactor =
        muDoubleScalarMax(1.0, b_MeritFunction.nlpPrimalFeasError);
  }
  isFeasible = (b_MeritFunction.nlpPrimalFeasError <=
                1.0E-6 * b_MeritFunction.feasRelativeFactor);
  st.site = &mf_emlrtRSI;
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
    st.site = &mf_emlrtRSI;
    b_MeritFunction.nlpComplError = stopping::computeComplError(
        st, b_TrialState.xstarsqp, WorkingSet.indexLB, WorkingSet.sizes[3], lb,
        WorkingSet.indexUB, WorkingSet.sizes[4], ub,
        b_TrialState.lambdaStopTest,
        (WorkingSet.sizes[0] + WorkingSet.sizes[1]) + 1);
    tol = muDoubleScalarMax(b_MeritFunction.nlpDualFeasError,
                            b_MeritFunction.nlpComplError);
    b_MeritFunction.firstOrderOpt = tol;
    if (b_TrialState.sqpIterations > 1) {
      real_T d;
      real_T nlpComplErrorTmp;
      st.site = &mf_emlrtRSI;
      stopping::computeGradLag(
          st, memspace.workspace_double, WorkingSet.ldA, WorkingSet.nVar,
          b_TrialState.grad, WorkingSet.Aineq.size[0], WorkingSet.sizes[1],
          WorkingSet.Aeq, WorkingSet.indexFixed, WorkingSet.sizes[0],
          WorkingSet.indexLB, WorkingSet.sizes[3], WorkingSet.indexUB,
          WorkingSet.sizes[4], b_TrialState.lambdaStopTestPrev);
      st.site = &mf_emlrtRSI;
      stopping::computeDualFeasError(
          st, WorkingSet.nVar, memspace.workspace_double, nlpComplErrorLSQ);
      st.site = &mf_emlrtRSI;
      nlpComplErrorTmp = stopping::computeComplError(
          st, b_TrialState.xstarsqp, WorkingSet.indexLB, WorkingSet.sizes[3],
          lb, WorkingSet.indexUB, WorkingSet.sizes[4], ub,
          b_TrialState.lambdaStopTestPrev,
          (WorkingSet.sizes[0] + WorkingSet.sizes[1]) + 1);
      d = muDoubleScalarMax(nlpComplErrorLSQ, nlpComplErrorTmp);
      if (d < tol) {
        b_MeritFunction.nlpDualFeasError = nlpComplErrorLSQ;
        b_MeritFunction.nlpComplError = nlpComplErrorTmp;
        b_MeritFunction.firstOrderOpt = d;
        st.site = &mf_emlrtRSI;
        if (mLambda >= 1) {
          b_st.site = &x_emlrtRSI;
          c_st.site = &ab_emlrtRSI;
          n_t = (ptrdiff_t)mLambda;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &(b_TrialState.lambdaStopTestPrev.data())[0], &incx_t,
                &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
        }
      } else {
        st.site = &mf_emlrtRSI;
        if (mLambda >= 1) {
          b_st.site = &x_emlrtRSI;
          c_st.site = &ab_emlrtRSI;
          n_t = (ptrdiff_t)mLambda;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
                &(b_TrialState.lambdaStopTestPrev.data())[0], &incy_t);
        }
      }
    } else {
      st.site = &mf_emlrtRSI;
      if (mLambda >= 1) {
        b_st.site = &x_emlrtRSI;
        c_st.site = &ab_emlrtRSI;
        n_t = (ptrdiff_t)mLambda;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
              &(b_TrialState.lambdaStopTestPrev.data())[0], &incy_t);
      }
    }
    if (isFeasible &&
        (b_MeritFunction.nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (b_MeritFunction.nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags.done = true;
      b_TrialState.sqpExitFlag = 1;
    } else {
      Flags.done = false;
      if (isFeasible && (b_TrialState.sqpFval < -1.0E+20)) {
        Flags.done = true;
        b_TrialState.sqpExitFlag = -3;
      } else {
        boolean_T guard1;
        guard1 = false;
        if (b_TrialState.sqpIterations > 0) {
          boolean_T dxTooSmall;
          st.site = &mf_emlrtRSI;
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
              idx_max = WorkingSet.nActiveConstr;
              if (WorkingSet.nActiveConstr > 0) {
                int32_T iQR_diag;
                boolean_T exitg1;
                boolean_T guard2;
                st.site = &mf_emlrtRSI;
                b_st.site = &tf_emlrtRSI;
                ::coder::internal::blas::xcopy(b_st, WorkingSet.nActiveConstr,
                                               b_TrialState.lambda);
                b_st.site = &tf_emlrtRSI;
                i = WorkingSet.nVar * WorkingSet.nActiveConstr;
                guard2 = false;
                if (i > 0) {
                  c_st.site = &hb_emlrtRSI;
                  if (WorkingSet.nActiveConstr > 2147483646) {
                    d_st.site = &f_emlrtRSI;
                    check_forloop_overflow_error(d_st);
                  }
                  for (iQR_diag = 0; iQR_diag < idx_max; iQR_diag++) {
                    c_st.site = &hb_emlrtRSI;
                    if (nVar >= 1) {
                      n_t = (ptrdiff_t)nVar;
                      incx_t = (ptrdiff_t)1;
                      incy_t = (ptrdiff_t)1;
                      dcopy(&n_t,
                            (real_T *)&WorkingSet
                                .ATwset[WorkingSet.ldA * iQR_diag],
                            &incx_t,
                            &b_QRManager.QR[b_QRManager.ldq * iQR_diag],
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
                  c_st.site = &hb_emlrtRSI;
                  ::coder::internal::lapack::xgeqp3(
                      c_st, b_QRManager.QR, WorkingSet.nVar,
                      WorkingSet.nActiveConstr, b_QRManager.jpvt,
                      b_QRManager.tau);
                }
                b_st.site = &tf_emlrtRSI;
                c_st.site = &bc_emlrtRSI;
                QRManager::computeQ_(c_st, b_QRManager, b_QRManager.mrows);
                b_st.site = &tf_emlrtRSI;
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
                nVar = 0;
                iQR_diag = 1;
                exitg1 = false;
                while ((!exitg1) && (nVar < idx_max)) {
                  i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
                  if ((iQR_diag < 1) || (iQR_diag > i)) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, i, &vd_emlrtBCI,
                                                  &st);
                  }
                  if (muDoubleScalarAbs(b_QRManager.QR[iQR_diag - 1]) > tol) {
                    nVar++;
                    iQR_diag = (iQR_diag + b_QRManager.ldq) + 1;
                  } else {
                    exitg1 = true;
                  }
                }
                b_st.site = &tf_emlrtRSI;
                ::coder::internal::blas::xtrsv(nVar, b_QRManager.QR,
                                               b_QRManager.ldq,
                                               memspace.workspace_double);
                idx_max =
                    muIntScalarMin_sint32(WorkingSet.nActiveConstr, idx_max);
                b_st.site = &tf_emlrtRSI;
                if (idx_max > 2147483646) {
                  c_st.site = &f_emlrtRSI;
                  check_forloop_overflow_error(c_st);
                }
                for (iQR_diag = 0; iQR_diag < idx_max; iQR_diag++) {
                  i = b_QRManager.jpvt.size(0);
                  if ((iQR_diag + 1 < 1) || (iQR_diag + 1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag + 1, 1, i,
                                                  &vd_emlrtBCI, &st);
                  }
                  i = memspace.workspace_double.size(0) *
                      memspace.workspace_double.size(1);
                  if ((iQR_diag + 1 < 1) || (iQR_diag + 1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag + 1, 1, i,
                                                  &vd_emlrtBCI, &st);
                  }
                  i = b_TrialState.lambda.size(0);
                  nVar = b_QRManager.jpvt[iQR_diag];
                  if ((nVar < 1) || (nVar > i)) {
                    emlrtDynamicBoundsCheckR2012b(nVar, 1, i, &vd_emlrtBCI,
                                                  &st);
                  }
                  b_TrialState.lambda[nVar - 1] =
                      memspace.workspace_double[iQR_diag];
                }
                idx_max = WorkingSet.sizes[0] + 1;
                st.site = &mf_emlrtRSI;
                if ((WorkingSet.sizes[0] + 1 <= mLambda_tmp) &&
                    (mLambda_tmp > 2147483646)) {
                  b_st.site = &f_emlrtRSI;
                  check_forloop_overflow_error(b_st);
                }
                for (iQR_diag = idx_max; iQR_diag <= mLambda_tmp; iQR_diag++) {
                  i = b_TrialState.lambda.size(0);
                  if ((iQR_diag < 1) || (iQR_diag > i)) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, i, &mb_emlrtBCI,
                                                  (emlrtConstCTX)&sp);
                  }
                  i = b_TrialState.lambda.size(0);
                  if (iQR_diag > i) {
                    emlrtDynamicBoundsCheckR2012b(iQR_diag, 1, i, &mb_emlrtBCI,
                                                  (emlrtConstCTX)&sp);
                  }
                  b_TrialState.lambda[iQR_diag - 1] =
                      -b_TrialState.lambda[iQR_diag - 1];
                }
                st.site = &mf_emlrtRSI;
                qpactiveset::parseoutput::sortLambdaQP(
                    st, b_TrialState.lambda, WorkingSet.nActiveConstr,
                    WorkingSet.sizes, WorkingSet.isActiveIdx, WorkingSet.Wid,
                    WorkingSet.Wlocalidx, memspace.workspace_double);
                st.site = &mf_emlrtRSI;
                stopping::computeGradLag(
                    st, memspace.workspace_double, WorkingSet.ldA,
                    WorkingSet.nVar, b_TrialState.grad,
                    WorkingSet.Aineq.size[0], WorkingSet.sizes[1],
                    WorkingSet.Aeq, WorkingSet.indexFixed, WorkingSet.sizes[0],
                    WorkingSet.indexLB, WorkingSet.sizes[3], WorkingSet.indexUB,
                    WorkingSet.sizes[4], b_TrialState.lambda);
                st.site = &mf_emlrtRSI;
                stopping::computeDualFeasError(st, WorkingSet.nVar,
                                               memspace.workspace_double, tol);
                st.site = &mf_emlrtRSI;
                nlpComplErrorLSQ = stopping::computeComplError(
                    st, b_TrialState.xstarsqp, WorkingSet.indexLB,
                    WorkingSet.sizes[3], lb, WorkingSet.indexUB,
                    WorkingSet.sizes[4], ub, b_TrialState.lambda,
                    WorkingSet.sizes[0] + 1);
                if ((tol <= 1.0E-6 * optimRelativeFactor) &&
                    (nlpComplErrorLSQ <= 1.0E-6 * optimRelativeFactor)) {
                  b_MeritFunction.nlpDualFeasError = tol;
                  b_MeritFunction.nlpComplError = nlpComplErrorLSQ;
                  b_MeritFunction.firstOrderOpt =
                      muDoubleScalarMax(tol, nlpComplErrorLSQ);
                  st.site = &mf_emlrtRSI;
                  if (mLambda >= 1) {
                    b_st.site = &x_emlrtRSI;
                    c_st.site = &ab_emlrtRSI;
                    n_t = (ptrdiff_t)mLambda;
                    incx_t = (ptrdiff_t)1;
                    incy_t = (ptrdiff_t)1;
                    dcopy(&n_t, &(b_TrialState.lambda.data())[0], &incx_t,
                          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
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
          if (b_TrialState.sqpIterations >= 1000) {
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
}

boolean_T test_exit(const emlrtStack &sp, struct_T &b_MeritFunction,
                    const j_struct_T &WorkingSet, i_struct_T &b_TrialState,
                    const array<real_T, 1U> &lb, const array<real_T, 1U> &ub,
                    int32_T c_runTimeOptions_MaxFunctionEva,
                    boolean_T &Flags_fevalOK, boolean_T &Flags_done,
                    boolean_T &Flags_stepAccepted,
                    boolean_T &Flags_failedLineSearch, int32_T &Flags_stepType)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack st;
  real_T optimRelativeFactor;
  int32_T i;
  int32_T idx_max;
  int32_T mLambda;
  boolean_T Flags_gradOK;
  boolean_T isFeasible;
  st.prev = &sp;
  st.tls = sp.tls;
  Flags_fevalOK = true;
  Flags_done = false;
  Flags_stepAccepted = false;
  Flags_failedLineSearch = false;
  Flags_stepType = 1;
  mLambda =
      ((WorkingSet.sizes[0] + WorkingSet.sizes[1]) + WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  if (mLambda >= 1) {
    n_t = (ptrdiff_t)mLambda;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.lambdasqp.data())[0], &incx_t,
          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
  }
  st.site = &mf_emlrtRSI;
  stopping::computeGradLag(
      st, b_TrialState.gradLag, WorkingSet.ldA, WorkingSet.nVar,
      b_TrialState.grad, WorkingSet.Aineq.size[0], WorkingSet.sizes[1],
      WorkingSet.Aeq, WorkingSet.indexFixed, WorkingSet.sizes[0],
      WorkingSet.indexLB, WorkingSet.sizes[3], WorkingSet.indexUB,
      WorkingSet.sizes[4], b_TrialState.lambdaStopTest);
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
    emlrtDynamicBoundsCheckR2012b(idx_max, 1, i, &mb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  optimRelativeFactor =
      muDoubleScalarMax(1.0, muDoubleScalarAbs(b_TrialState.grad[idx_max - 1]));
  if (muDoubleScalarIsInf(optimRelativeFactor)) {
    optimRelativeFactor = 1.0;
  }
  st.site = &mf_emlrtRSI;
  b_MeritFunction.nlpPrimalFeasError = stopping::computePrimalFeasError(
      st, b_TrialState.xstarsqp, WorkingSet.sizes[1], b_TrialState.cEq.data,
      b_TrialState.cEq.size[0], WorkingSet.indexLB, WorkingSet.sizes[3], lb,
      WorkingSet.indexUB, WorkingSet.sizes[4], ub);
  b_MeritFunction.feasRelativeFactor =
      muDoubleScalarMax(1.0, b_MeritFunction.nlpPrimalFeasError);
  isFeasible = (b_MeritFunction.nlpPrimalFeasError <=
                1.0E-6 * b_MeritFunction.feasRelativeFactor);
  st.site = &mf_emlrtRSI;
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
    st.site = &mf_emlrtRSI;
    b_MeritFunction.nlpComplError = stopping::computeComplError(
        st, b_TrialState.xstarsqp, WorkingSet.indexLB, WorkingSet.sizes[3], lb,
        WorkingSet.indexUB, WorkingSet.sizes[4], ub,
        b_TrialState.lambdaStopTest,
        (WorkingSet.sizes[0] + WorkingSet.sizes[1]) + 1);
    b_MeritFunction.firstOrderOpt = muDoubleScalarMax(
        b_MeritFunction.nlpDualFeasError, b_MeritFunction.nlpComplError);
    if (mLambda >= 1) {
      n_t = (ptrdiff_t)mLambda;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
            &(b_TrialState.lambdaStopTestPrev.data())[0], &incy_t);
    }
    if (isFeasible &&
        (b_MeritFunction.nlpDualFeasError <= 1.0E-6 * optimRelativeFactor) &&
        (b_MeritFunction.nlpComplError <= 1.0E-6 * optimRelativeFactor)) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = 1;
    } else if (isFeasible && (b_TrialState.sqpFval < -1.0E+20)) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = -3;
    } else if (b_TrialState.FunctionEvaluations >=
               c_runTimeOptions_MaxFunctionEva) {
      Flags_done = true;
      b_TrialState.sqpExitFlag = 0;
    }
  }
  return Flags_gradOK;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (test_exit.cpp)
