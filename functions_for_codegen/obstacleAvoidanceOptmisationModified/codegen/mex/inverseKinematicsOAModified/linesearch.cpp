//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linesearch.cpp
//
// Code generation for function 'linesearch'
//

// Include files
#include "linesearch.h"
#include "computeConstrViolationIneq_.h"
#include "computeLinearResiduals.h"
#include "eml_int_forloop_overflow_check.h"
#include "evalObjAndConstr.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "isDeltaXTooSmall.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo gj_emlrtRSI{
    1,            // lineNo
    "linesearch", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "linesearch.p" // pathName
};

static emlrtBCInfo je_emlrtBCI{
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

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
real_T linesearch(const emlrtStack &sp, boolean_T &evalWellDefined,
                  const array<real_T, 2U> &bineq, const real_T beq_data[],
                  int32_T WorkingSet_nVar, int32_T WorkingSet_ldA,
                  const array<real_T, 1U> &WorkingSet_Aineq,
                  const array<real_T, 1U> &WorkingSet_Aeq,
                  j_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                  real_T MeritFunction_phiFullStep,
                  const ::coder::internal::i_stickyStruct &FcnEvaluator,
                  boolean_T socTaken, int32_T c_runTimeOptions_MaxFunctionEva,
                  int32_T &exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha;
  real_T phi_alpha;
  int32_T evalStatus;
  int32_T mEq;
  int32_T mIneq;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mEq = b_TrialState.mEq;
  mIneq = b_TrialState.mIneq;
  alpha = 1.0;
  exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  st.site = &gj_emlrtRSI;
  if (WorkingSet_nVar >= 1) {
    n_t = (ptrdiff_t)WorkingSet_nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.delta_x.data())[0], &incx_t,
          &(b_TrialState.searchDir.data())[0], &incy_t);
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (b_TrialState.FunctionEvaluations < c_runTimeOptions_MaxFunctionEva) {
      if (evalWellDefined &&
          (phi_alpha <=
           MeritFunction_phi + alpha * 0.0001 * MeritFunction_phiPrimePlus)) {
        exitg1 = 1;
      } else {
        boolean_T tooSmallX;
        alpha *= 0.7;
        st.site = &gj_emlrtRSI;
        if (WorkingSet_nVar > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        for (int32_T idx{0}; idx < WorkingSet_nVar; idx++) {
          evalStatus = b_TrialState.xstar.size(0);
          if ((idx + 1 < 1) || (idx + 1 > evalStatus)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, evalStatus, &je_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          evalStatus = b_TrialState.delta_x.size(0);
          if (idx + 1 > evalStatus) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, evalStatus, &je_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          b_TrialState.delta_x[idx] = alpha * b_TrialState.xstar[idx];
        }
        if (socTaken) {
          phi_alpha = alpha * alpha;
          st.site = &gj_emlrtRSI;
          if (WorkingSet_nVar >= 1) {
            n_t = (ptrdiff_t)WorkingSet_nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            daxpy(&n_t, &phi_alpha, &(b_TrialState.socDirection.data())[0],
                  &incx_t, &(b_TrialState.delta_x.data())[0], &incy_t);
          }
        }
        st.site = &gj_emlrtRSI;
        tooSmallX = stopping::isDeltaXTooSmall(
            st, b_TrialState.xstarsqp, b_TrialState.delta_x, WorkingSet_nVar);
        if (tooSmallX) {
          exitflag = -2;
          exitg1 = 1;
        } else {
          st.site = &gj_emlrtRSI;
          for (int32_T idx{0}; idx < WorkingSet_nVar; idx++) {
            evalStatus = b_TrialState.xstarsqp_old.size(0);
            if ((idx + 1 < 1) || (idx + 1 > evalStatus)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, evalStatus,
                                            &je_emlrtBCI, (emlrtConstCTX)&sp);
            }
            evalStatus = b_TrialState.delta_x.size(0);
            if (idx + 1 > evalStatus) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, evalStatus,
                                            &je_emlrtBCI, (emlrtConstCTX)&sp);
            }
            evalStatus = b_TrialState.xstarsqp.size(0);
            if (idx + 1 > evalStatus) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, evalStatus,
                                            &je_emlrtBCI, (emlrtConstCTX)&sp);
            }
            b_TrialState.xstarsqp[idx] =
                b_TrialState.xstarsqp_old[idx] + b_TrialState.delta_x[idx];
          }
          st.site = &gj_emlrtRSI;
          b_TrialState.sqpFval = utils::ObjNonlinEvaluator::evalObjAndConstr(
              st, FcnEvaluator, b_TrialState.xstarsqp, evalStatus);
          st.site = &gj_emlrtRSI;
          internal::computeLinearResiduals(
              st, b_TrialState.xstarsqp, WorkingSet_nVar, b_TrialState.cIneq,
              mIneq, WorkingSet_Aineq, bineq, WorkingSet_ldA,
              b_TrialState.cEq.data, b_TrialState.cEq.size[0], mEq,
              WorkingSet_Aeq, beq_data, WorkingSet_ldA);
          b_TrialState.FunctionEvaluations++;
          evalWellDefined = (evalStatus == 1);
          st.site = &gj_emlrtRSI;
          if (evalWellDefined) {
            real_T constrViolationIneq;
            if (mEq < 1) {
              phi_alpha = 0.0;
            } else {
              n_t = (ptrdiff_t)mEq;
              incx_t = (ptrdiff_t)1;
              phi_alpha = dasum(&n_t, &b_TrialState.cEq.data[0], &incx_t);
            }
            b_st.site = &fj_emlrtRSI;
            constrViolationIneq = MeritFunction::computeConstrViolationIneq_(
                b_st, mIneq, b_TrialState.cIneq);
            phi_alpha =
                b_TrialState.sqpFval +
                MeritFunction_penaltyParam * (phi_alpha + constrViolationIneq);
          } else {
            phi_alpha = rtInf;
          }
        }
      }
    } else {
      exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return alpha;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (linesearch.cpp)
