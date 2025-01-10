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
#include "computeFiniteDifferences.h"
#include "computeLinearResiduals.h"
#include "computeMeritFcn.h"
#include "eml_int_forloop_overflow_check.h"
#include "evalObjAndConstr.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "isDeltaXTooSmall.h"
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
    lf_emlrtRSI{
        1,        // lineNo
        "driver", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
        "driver.p" // pathName
    };

static emlrtRSInfo ij_emlrtRSI{
    1,            // lineNo
    "linesearch", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "linesearch.p" // pathName
};

static emlrtRSInfo jj_emlrtRSI{
    1,                // lineNo
    "revertSolution", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/revertSolution.p" // pathName
};

static emlrtRSInfo kj_emlrtRSI{
    1,                 // lineNo
    "computeDeltaLag", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeDeltaLag.p" // pathName
};

static emlrtBCInfo
    jb_emlrtBCI{
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

static emlrtBCInfo kb_emlrtBCI{
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

static emlrtBCInfo lb_emlrtBCI{
    -1,           // iFirst
    -1,           // iLast
    1,            // lineNo
    1,            // colNo
    "",           // aName
    "linesearch", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "linesearch.p", // pName
    0               // checkKind
};

static emlrtRTEInfo vb_emlrtRTEI{
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
            const real_T beq_data[], const array<real_T, 1U> &lb,
            const array<real_T, 1U> &ub, i_struct_T &b_TrialState,
            struct_T &b_MeritFunction,
            const ::coder::internal::i_stickyStruct &FcnEvaluator,
            l_struct_T &FiniteDifferences, g_struct_T &memspace,
            j_struct_T &WorkingSet, d_struct_T &b_QRManager,
            e_struct_T &b_CholManager, f_struct_T &QPObjective,
            const h_struct_T &runTimeOptions)
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
  real_T phi_alpha;
  int32_T mConstr;
  int32_T mEq;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  int32_T nVar_tmp_tmp;
  int32_T qpoptions_MaxIterations;
  int32_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  nVar_tmp_tmp = WorkingSet.nVar;
  mFixed = WorkingSet.sizes[0];
  mEq = WorkingSet.sizes[1];
  mLB = WorkingSet.sizes[3];
  mUB = WorkingSet.sizes[4];
  mConstr =
      ((WorkingSet.sizes[0] + WorkingSet.sizes[1]) + WorkingSet.sizes[3]) +
      WorkingSet.sizes[4];
  y = (WorkingSet.sizes[3] + WorkingSet.sizes[4]) + (WorkingSet.sizes[0] << 1);
  qpoptions_MaxIterations = 10 * muIntScalarMax_sint32(WorkingSet.nVar, y);
  b_TrialState.steplength = 1.0;
  st.site = &lf_emlrtRSI;
  Flags.gradOK = test_exit(st, b_MeritFunction, WorkingSet, b_TrialState, lb,
                           ub, runTimeOptions.MaxFunctionEvaluations,
                           Flags.fevalOK, Flags.done, Flags.stepAccepted,
                           Flags.failedLineSearch, Flags.stepType);
  st.site = &lf_emlrtRSI;
  TrialState::saveJacobian(st, mEq, b_TrialState.iNonEq0);
  st.site = &lf_emlrtRSI;
  TrialState::saveState(st, b_TrialState);
  if (!Flags.done) {
    b_TrialState.sqpIterations = 1;
  }
  while (!Flags.done) {
    int32_T i;
    while (!(Flags.stepAccepted || Flags.failedLineSearch)) {
      if (Flags.stepType != 3) {
        st.site = &lf_emlrtRSI;
        internal::b_updateWorkingSetForNewQP(
            st, b_TrialState.xstarsqp, WorkingSet, mEq, b_TrialState.cEq.data,
            b_TrialState.cEq.size[0], mLB, lb, mUB, ub, mFixed);
      }
      expl_temp.ObjectiveLimit = rtMinusInf;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (i = 0; i < 7; i++) {
        expl_temp.SolverName[i] = qpoptions_SolverName[i];
      }
      b_expl_temp = expl_temp;
      st.site = &lf_emlrtRSI;
      Flags.stepAccepted =
          b_step(st, Flags.stepType, Hessian, lb, ub, b_TrialState,
                 b_MeritFunction, memspace, WorkingSet, b_QRManager,
                 b_CholManager, QPObjective, b_expl_temp);
      if (Flags.stepAccepted) {
        st.site = &lf_emlrtRSI;
        if (nVar_tmp_tmp > 2147483646) {
          b_st.site = &f_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        for (y = 0; y < nVar_tmp_tmp; y++) {
          i = b_TrialState.xstarsqp.size(0);
          if ((y + 1 < 1) || (y + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &jb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = b_TrialState.delta_x.size(0);
          if (y + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &jb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = b_TrialState.xstarsqp.size(0);
          if (y + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &jb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          b_TrialState.xstarsqp[y] =
              b_TrialState.xstarsqp[y] + b_TrialState.delta_x[y];
        }
        st.site = &lf_emlrtRSI;
        b_TrialState.sqpFval = utils::ObjNonlinEvaluator::evalObjAndConstr(
            st, FcnEvaluator, b_TrialState.xstarsqp, y);
        Flags.fevalOK = (y == 1);
        b_TrialState.FunctionEvaluations++;
        st.site = &lf_emlrtRSI;
        internal::computeLinearResiduals(
            st, b_TrialState.xstarsqp, nVar_tmp_tmp, b_TrialState.cEq.data,
            b_TrialState.cEq.size[0], mEq, WorkingSet.Aeq, beq_data,
            WorkingSet.ldA);
        st.site = &lf_emlrtRSI;
        b_MeritFunction.phiFullStep = MeritFunction::computeMeritFcn(
            b_MeritFunction.penaltyParam, b_TrialState.sqpFval,
            b_TrialState.cEq.data, mEq, Flags.fevalOK);
      }
      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (b_MeritFunction.phi < b_MeritFunction.phiFullStep) &&
          (b_TrialState.sqpFval < b_TrialState.sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        real_T alpha;
        int32_T b_mEq;
        int32_T exitflagLnSrch;
        boolean_T b;
        boolean_T socTaken;
        if ((Flags.stepType == 3) && Flags.stepAccepted) {
          socTaken = true;
        } else {
          socTaken = false;
        }
        st.site = &lf_emlrtRSI;
        b = Flags.fevalOK;
        i = WorkingSet.nVar;
        b_mEq = b_TrialState.mEq;
        alpha = 1.0;
        exitflagLnSrch = 1;
        phi_alpha = b_MeritFunction.phiFullStep;
        b_st.site = &ij_emlrtRSI;
        if (WorkingSet.nVar >= 1) {
          n_t = (ptrdiff_t)WorkingSet.nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &(b_TrialState.delta_x.data())[0], &incx_t,
                &(b_TrialState.searchDir.data())[0], &incy_t);
        }
        int32_T exitg1;
        do {
          exitg1 = 0;
          if (b_TrialState.FunctionEvaluations <
              runTimeOptions.MaxFunctionEvaluations) {
            if (b && (phi_alpha <=
                      b_MeritFunction.phi +
                          alpha * 0.0001 * b_MeritFunction.phiPrimePlus)) {
              exitg1 = 1;
            } else {
              boolean_T tooSmallX;
              alpha *= 0.7;
              b_st.site = &ij_emlrtRSI;
              if (i > 2147483646) {
                c_st.site = &f_emlrtRSI;
                check_forloop_overflow_error(c_st);
              }
              for (int32_T idx{0}; idx < i; idx++) {
                y = b_TrialState.xstar.size(0);
                if ((idx + 1 < 1) || (idx + 1 > y)) {
                  emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &lb_emlrtBCI,
                                                &st);
                }
                y = b_TrialState.delta_x.size(0);
                if (idx + 1 > y) {
                  emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &lb_emlrtBCI,
                                                &st);
                }
                b_TrialState.delta_x[idx] = alpha * b_TrialState.xstar[idx];
              }
              if (socTaken) {
                phi_alpha = alpha * alpha;
                b_st.site = &ij_emlrtRSI;
                if (i >= 1) {
                  n_t = (ptrdiff_t)i;
                  incx_t = (ptrdiff_t)1;
                  incy_t = (ptrdiff_t)1;
                  daxpy(&n_t, &phi_alpha,
                        &(b_TrialState.socDirection.data())[0], &incx_t,
                        &(b_TrialState.delta_x.data())[0], &incy_t);
                }
              }
              b_st.site = &ij_emlrtRSI;
              tooSmallX = stopping::isDeltaXTooSmall(
                  b_st, b_TrialState.xstarsqp, b_TrialState.delta_x, i);
              if (tooSmallX) {
                exitflagLnSrch = -2;
                exitg1 = 1;
              } else {
                b_st.site = &ij_emlrtRSI;
                for (int32_T idx{0}; idx < i; idx++) {
                  y = b_TrialState.xstarsqp_old.size(0);
                  if ((idx + 1 < 1) || (idx + 1 > y)) {
                    emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &lb_emlrtBCI,
                                                  &st);
                  }
                  y = b_TrialState.delta_x.size(0);
                  if (idx + 1 > y) {
                    emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &lb_emlrtBCI,
                                                  &st);
                  }
                  y = b_TrialState.xstarsqp.size(0);
                  if (idx + 1 > y) {
                    emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &lb_emlrtBCI,
                                                  &st);
                  }
                  b_TrialState.xstarsqp[idx] = b_TrialState.xstarsqp_old[idx] +
                                               b_TrialState.delta_x[idx];
                }
                b_st.site = &ij_emlrtRSI;
                b_TrialState.sqpFval =
                    utils::ObjNonlinEvaluator::evalObjAndConstr(
                        b_st, FcnEvaluator, b_TrialState.xstarsqp, y);
                b_st.site = &ij_emlrtRSI;
                internal::computeLinearResiduals(
                    b_st, b_TrialState.xstarsqp, i, b_TrialState.cEq.data,
                    b_TrialState.cEq.size[0], b_mEq, WorkingSet.Aeq, beq_data,
                    WorkingSet.ldA);
                b_TrialState.FunctionEvaluations++;
                b = (y == 1);
                b_st.site = &ij_emlrtRSI;
                phi_alpha = MeritFunction::computeMeritFcn(
                    b_MeritFunction.penaltyParam, b_TrialState.sqpFval,
                    b_TrialState.cEq.data, b_mEq, b);
              }
            }
          } else {
            exitflagLnSrch = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
        Flags.fevalOK = b;
        b_TrialState.steplength = alpha;
        if (exitflagLnSrch > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }
    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      st.site = &lf_emlrtRSI;
      if (nVar_tmp_tmp > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx < nVar_tmp_tmp; idx++) {
        i = b_TrialState.xstarsqp_old.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.delta_x.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.xstarsqp.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        b_TrialState.xstarsqp[idx] =
            b_TrialState.xstarsqp_old[idx] + b_TrialState.delta_x[idx];
      }
      st.site = &lf_emlrtRSI;
      if (mConstr > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx < mConstr; idx++) {
        i = b_TrialState.lambdasqp.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambda.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambdasqp.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = b_TrialState.lambdasqp.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        phi_alpha = b_TrialState.lambdasqp[idx];
        b_TrialState.lambdasqp[idx] =
            phi_alpha +
            b_TrialState.steplength * (b_TrialState.lambda[idx] - phi_alpha);
      }
      st.site = &lf_emlrtRSI;
      TrialState::saveState(st, b_TrialState);
      st.site = &lf_emlrtRSI;
      Flags.gradOK = utils::FiniteDifferences::computeFiniteDifferences(
          st, FiniteDifferences, b_TrialState.sqpFval, b_TrialState.xstarsqp,
          b_TrialState.grad, lb, ub, runTimeOptions.FiniteDifferenceStepSize,
          runTimeOptions.TypicalX);
      b_TrialState.FunctionEvaluations += FiniteDifferences.numEvals;
    } else {
      st.site = &lf_emlrtRSI;
      b_TrialState.sqpFval = b_TrialState.sqpFval_old;
      b_st.site = &jj_emlrtRSI;
      if (b_TrialState.xstarsqp.size(0) >= 1) {
        n_t = (ptrdiff_t)b_TrialState.xstarsqp.size(0);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(b_TrialState.xstarsqp_old.data())[0], &incx_t,
              &(b_TrialState.xstarsqp.data())[0], &incy_t);
      }
      b_st.site = &jj_emlrtRSI;
      b_y.set_size(&vb_emlrtRTEI, &b_st, b_TrialState.cEq.size[0]);
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
    st.site = &lf_emlrtRSI;
    b_test_exit(st, Flags, memspace, b_MeritFunction, WorkingSet, b_TrialState,
                b_QRManager, lb, ub, runTimeOptions.MaxFunctionEvaluations);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      st.site = &lf_emlrtRSI;
      b_st.site = &kj_emlrtRSI;
      if (nVar_tmp_tmp > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (y = 0; y < nVar_tmp_tmp; y++) {
        i = b_TrialState.grad.size(0);
        if ((y + 1 < 1) || (y + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &kb_emlrtBCI, &st);
        }
        i = b_TrialState.delta_gradLag.size(0);
        if (y + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, i, &kb_emlrtBCI, &st);
        }
        b_TrialState.delta_gradLag[y] = b_TrialState.grad[y];
      }
      b_st.site = &kj_emlrtRSI;
      if (nVar_tmp_tmp >= 1) {
        phi_alpha = -1.0;
        n_t = (ptrdiff_t)nVar_tmp_tmp;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &phi_alpha, &(b_TrialState.grad_old.data())[0], &incx_t,
              &(b_TrialState.delta_gradLag.data())[0], &incy_t);
      }
      st.site = &lf_emlrtRSI;
      TrialState::saveJacobian(st, mEq, b_TrialState.iNonEq0);
      st.site = &lf_emlrtRSI;
      BFGSUpdate(nVar_tmp_tmp, Hessian, b_TrialState.delta_x,
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
