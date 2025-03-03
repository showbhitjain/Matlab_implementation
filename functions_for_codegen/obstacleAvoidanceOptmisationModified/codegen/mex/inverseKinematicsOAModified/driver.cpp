//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver.cpp
//
// Code generation for function 'driver'
//

// Include files
#include "driver.h"
#include "BFGSUpdate.h"
#include "computeConstrViolationIneq_.h"
#include "computeFiniteDifferences.h"
#include "computeLinearResiduals.h"
#include "eml_int_forloop_overflow_check.h"
#include "evalObjAndConstr.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "linesearch.h"
#include "rt_nonfinite.h"
#include "saveJacobian.h"
#include "saveState.h"
#include "step.h"
#include "stickyStruct.h"
#include "test_exit.h"
#include "updateWorkingSetForNewQP.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    gf_emlrtRSI{
        1,        // lineNo
        "driver", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
        "driver.p" // pathName
    };

static emlrtRSInfo hj_emlrtRSI{
    1,                // lineNo
    "revertSolution", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/revertSolution.p" // pathName
};

static emlrtRSInfo ij_emlrtRSI{
    1,                 // lineNo
    "computeDeltaLag", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeDeltaLag.p" // pathName
};

static emlrtBCInfo
    xb_emlrtBCI{
        -1,       // iFirst
        -1,       // iLast
        1,        // lineNo
        1,        // colNo
        "",       // aName
        "driver", // fName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
        "driver.p", // pName
        0           // checkKind
    };

static emlrtBCInfo yb_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "computeDeltaLag", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeDeltaLag.p", // pName
    0                              // checkKind
};

static emlrtRTEInfo od_emlrtRTEI{
    1,                // lineNo
    1,                // colNo
    "revertSolution", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/revertSolution.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void driver(const emlrtStack &sp, array<real_T, 2U> &Hessian,
            const array<real_T, 2U> &bineq, const real_T beq_data[],
            const array<real_T, 2U> &lb, const array<real_T, 2U> &ub,
            j_struct_T &b_TrialState, struct_T &b_MeritFunction,
            const ::coder::internal::i_stickyStruct &FcnEvaluator,
            l_struct_T &FiniteDifferences, h_struct_T &memspace,
            d_struct_T &WorkingSet, e_struct_T &b_QRManager,
            f_struct_T &b_CholManager, g_struct_T &QPObjective,
            const array<real_T, 1U> &fscales_lineq_constraint,
            const i_struct_T &runTimeOptions)
{
  static const char_T qpoptions_SolverName[7]{'f', 'm', 'i', 'n',
                                              'c', 'o', 'n'};
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> b_y;
  b_struct_T Flags;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  k_struct_T b_expl_temp;
  k_struct_T expl_temp;
  real_T constrViolationEq;
  int32_T mConstr;
  int32_T mEq;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mUB;
  int32_T nVar;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  nVar = WorkingSet.nVar;
  mFixed = WorkingSet.sizes[0];
  mEq = WorkingSet.sizes[1];
  mIneq = WorkingSet.sizes[2];
  mLB = WorkingSet.sizes[3];
  mUB = WorkingSet.sizes[4];
  mConstr =
      (((WorkingSet.sizes[0] + WorkingSet.sizes[1]) + WorkingSet.sizes[2]) +
       WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  y = ((WorkingSet.sizes[2] + WorkingSet.sizes[3]) + WorkingSet.sizes[4]) +
      (WorkingSet.sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet.nVar, y);
  b_TrialState.steplength = 1.0;
  st.site = &gf_emlrtRSI;
  Flags.gradOK = test_exit(
      st, b_MeritFunction, fscales_lineq_constraint, WorkingSet, b_TrialState,
      lb, ub, runTimeOptions.MaxFunctionEvaluations, Flags.fevalOK, Flags.done,
      Flags.stepAccepted, Flags.failedLineSearch, Flags.stepType);
  st.site = &gf_emlrtRSI;
  TrialState::saveJacobian(st, mIneq, b_TrialState.iNonIneq0, mEq,
                           b_TrialState.iNonEq0);
  st.site = &gf_emlrtRSI;
  TrialState::saveState(st, b_TrialState);
  if (!Flags.done) {
    b_TrialState.sqpIterations = 1;
  }
  while (!Flags.done) {
    int32_T i;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      if (Flags.stepType != 3) {
        st.site = &gf_emlrtRSI;
        internal::updateWorkingSetForNewQP(
            st, b_TrialState.xstarsqp, WorkingSet, mIneq, b_TrialState.cIneq,
            mEq, b_TrialState.cEq.data, b_TrialState.cEq.size[0], mLB, lb, mUB,
            ub, mFixed);
      }
      expl_temp.ObjectiveLimit = rtMinusInf;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      b_expl_temp = expl_temp;
      st.site = &gf_emlrtRSI;
      Flags.stepAccepted =
          b_step(st, Flags.stepType, Hessian, lb, ub, b_TrialState,
                 b_MeritFunction, memspace, WorkingSet, b_QRManager,
                 b_CholManager, QPObjective, b_expl_temp);
      if (Flags.stepAccepted) {
        st.site = &gf_emlrtRSI;
        if (nVar > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        for (y = 0; y < nVar; y++) {
          i = b_TrialState.xstarsqp.size(0);
          if ((y + 1 < 1) || (y + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = b_TrialState.delta_x.size(0);
          if (y + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = b_TrialState.xstarsqp.size(0);
          if (y + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          b_TrialState.xstarsqp[y] =
              b_TrialState.xstarsqp[y] + b_TrialState.delta_x[y];
        }
        st.site = &gf_emlrtRSI;
        b_TrialState.sqpFval = utils::ObjNonlinEvaluator::evalObjAndConstr(
            st, FcnEvaluator, b_TrialState.xstarsqp, y);
        Flags.fevalOK = (y == 1);
        b_TrialState.FunctionEvaluations++;
        st.site = &gf_emlrtRSI;
        internal::computeLinearResiduals(
            st, b_TrialState.xstarsqp, nVar, b_TrialState.cIneq, mIneq,
            WorkingSet.Aineq, bineq, WorkingSet.ldA, b_TrialState.cEq.data,
            b_TrialState.cEq.size[0], mEq, WorkingSet.Aeq, beq_data,
            WorkingSet.ldA);
        st.site = &gf_emlrtRSI;
        if (Flags.fevalOK) {
          real_T constrViolationIneq;
          if (mEq < 1) {
            constrViolationEq = 0.0;
          } else {
            n_t = (ptrdiff_t)mEq;
            incx_t = (ptrdiff_t)1;
            constrViolationEq = dasum(&n_t, &b_TrialState.cEq.data[0], &incx_t);
          }
          b_st.site = &fj_emlrtRSI;
          constrViolationIneq = MeritFunction::computeConstrViolationIneq_(
              b_st, mIneq, b_TrialState.cIneq);
          b_MeritFunction.phiFullStep =
              b_TrialState.sqpFval +
              b_MeritFunction.penaltyParam *
                  (constrViolationEq + constrViolationIneq);
        } else {
          b_MeritFunction.phiFullStep = rtInf;
        }
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (b_MeritFunction.phi < b_MeritFunction.phiFullStep) &&
          (b_TrialState.sqpFval < b_TrialState.sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        boolean_T socTaken;
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        st.site = &gf_emlrtRSI;
        constrViolationEq = linesearch(
            st, Flags.fevalOK, bineq, beq_data, WorkingSet.nVar, WorkingSet.ldA,
            WorkingSet.Aineq, WorkingSet.Aeq, b_TrialState,
            b_MeritFunction.penaltyParam, b_MeritFunction.phi,
            b_MeritFunction.phiPrimePlus, b_MeritFunction.phiFullStep,
            FcnEvaluator, socTaken, runTimeOptions.MaxFunctionEvaluations, y);
        b_TrialState.steplength = constrViolationEq;
        if (y > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      st.site = &gf_emlrtRSI;
      if (nVar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (y = 0; y < nVar; y++) {
        i = b_TrialState.xstarsqp_old.size(0);
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.delta_x.size(0);
        if (y + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.xstarsqp.size(0);
        if (y + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        b_TrialState.xstarsqp[y] =
            b_TrialState.xstarsqp_old[y] + b_TrialState.delta_x[y];
      }
      st.site = &gf_emlrtRSI;
      if (mConstr > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (y = 0; y < mConstr; y++) {
        i = b_TrialState.lambdasqp.size(0);
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambda.size(0);
        if (y + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambdasqp.size(0);
        if (y + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambdasqp.size(0);
        if (y + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        constrViolationEq = b_TrialState.lambdasqp[y];
        b_TrialState.lambdasqp[y] =
            constrViolationEq +
            b_TrialState.steplength *
                (b_TrialState.lambda[y] - constrViolationEq);
      }
      st.site = &gf_emlrtRSI;
      TrialState::saveState(st, b_TrialState);
      st.site = &gf_emlrtRSI;
      Flags.gradOK = utils::FiniteDifferences::computeFiniteDifferences(
          st, FiniteDifferences, b_TrialState.sqpFval, b_TrialState.xstarsqp,
          b_TrialState.grad, lb, ub, runTimeOptions.FiniteDifferenceStepSize,
          runTimeOptions.TypicalX);
      b_TrialState.FunctionEvaluations += FiniteDifferences.numEvals;
    } else {
      st.site = &gf_emlrtRSI;
      b_TrialState.sqpFval = b_TrialState.sqpFval_old;
      b_st.site = &hj_emlrtRSI;
      if (b_TrialState.xstarsqp.size(0) >= 1) {
        n_t = (ptrdiff_t)b_TrialState.xstarsqp.size(0);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_TrialState.xstarsqp_old.data())[0], &incx_t,
              &(b_TrialState.xstarsqp.data())[0], &incy_t);
      }
      b_st.site = &hj_emlrtRSI;
      if (b_TrialState.mIneq >= 1) {
        n_t = (ptrdiff_t)b_TrialState.mIneq;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_TrialState.cIneq_old.data())[0], &incx_t,
              &(b_TrialState.cIneq.data())[0], &incy_t);
      }
      b_st.site = &hj_emlrtRSI;
      b_y.set_size(&od_emlrtRTEI, &b_st, b_TrialState.cEq.size[0]);
      y = b_TrialState.cEq.size[0];
      for (i = 0; i < y; i++) {
        b_y[i] = b_TrialState.cEq.data[i];
      }
      if (b_TrialState.mEq >= 1) {
        n_t = (ptrdiff_t)b_TrialState.mEq;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &b_TrialState.cEq_old.data[0], &incx_t, &(b_y.data())[0],
              &incy_t);
      }
      b_TrialState.cEq.size[0] = b_y.size(0);
      y = b_y.size(0);
      for (i = 0; i < y; i++) {
        b_TrialState.cEq.data[i] = b_y[i];
      }
    }
    st.site = &gf_emlrtRSI;
    b_test_exit(st, Flags, memspace, b_MeritFunction, fscales_lineq_constraint,
                WorkingSet, b_TrialState, b_QRManager, lb, ub,
                runTimeOptions.MaxFunctionEvaluations);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      st.site = &gf_emlrtRSI;
      b_st.site = &ij_emlrtRSI;
      if (nVar > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (y = 0; y < nVar; y++) {
        i = b_TrialState.grad.size(0);
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &yb_emlrtBCI, &st);
        }
        i = b_TrialState.delta_gradLag.size(0);
        if (y + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &yb_emlrtBCI, &st);
        }
        b_TrialState.delta_gradLag[y] = b_TrialState.grad[y];
      }
      b_st.site = &ij_emlrtRSI;
      if (nVar >= 1) {
        constrViolationEq = -1.0;
        n_t = (ptrdiff_t)nVar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &constrViolationEq, &(b_TrialState.grad_old.data())[0],
              &incx_t, &(b_TrialState.delta_gradLag.data())[0], &incy_t);
      }
      st.site = &gf_emlrtRSI;
      TrialState::saveJacobian(st, mIneq, b_TrialState.iNonIneq0, mEq,
                               b_TrialState.iNonEq0);
      st.site = &gf_emlrtRSI;
      BFGSUpdate(nVar, Hessian, b_TrialState.delta_x,
                 b_TrialState.delta_gradLag, memspace.workspace_double);
      b_TrialState.sqpIterations++;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver.cpp)
