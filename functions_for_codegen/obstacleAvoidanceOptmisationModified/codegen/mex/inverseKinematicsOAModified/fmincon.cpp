//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fmincon.cpp
//
// Code generation for function 'fmincon'
//

// Include files
#include "fmincon.h"
#include "anonymous_function.h"
#include "checkLinearInputs.h"
#include "checkX0.h"
#include "compressBounds.h"
#include "computeConstrViolationIneq_.h"
#include "computeFiniteDifferences.h"
#include "computeLinearResiduals.h"
#include "computeObjective_.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "eye.h"
#include "factoryConstruct.h"
#include "factoryConstruct1.h"
#include "factoryConstruct2.h"
#include "initActiveSet.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "loadProblem.h"
#include "removeDependentLinearEq.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "updateWorkingSetForNewQP.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo eb_emlrtRSI{
    1,                                                     // lineNo
    "fmincon",                                             // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/eml/fmincon.p" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    1,                                // lineNo
    "convertFminconOptionsForSolver", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+options/"
    "convertFminconOptionsForSolver.p" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    1,                                // lineNo
    "evalObjAndConstrAndDerivatives", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
    "+ObjNonlinEvaluator/evalObjAndConstrAndDerivatives.p" // pathName
};

static emlrtRSInfo ef_emlrtRSI{
    1,                  // lineNo
    "factoryConstruct", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+MeritFunction/factoryConstruct.p" // pathName
};

static emlrtBCInfo jb_emlrtBCI{
    -1,                                                     // iFirst
    -1,                                                     // iLast
    1,                                                      // lineNo
    1,                                                      // colNo
    "",                                                     // aName
    "fmincon",                                              // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/eml/fmincon.p", // pName
    0                                                       // checkKind
};

static emlrtRTEInfo m_emlrtRTEI{
    1,                                                     // lineNo
    1,                                                     // colNo
    "fmincon",                                             // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/eml/fmincon.p" // pName
};

static emlrtBCInfo kb_emlrtBCI{
    -1,                               // iFirst
    -1,                               // iLast
    1,                                // lineNo
    1,                                // colNo
    "",                               // aName
    "convertFminconOptionsForSolver", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+options/"
    "convertFminconOptionsForSolver.p", // pName
    0                                   // checkKind
};

static emlrtRTEInfo ib_emlrtRTEI{
    1,                                // lineNo
    1,                                // colNo
    "convertFminconOptionsForSolver", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+options/"
    "convertFminconOptionsForSolver.p" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "factoryConstruct.p" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+CholManager/"
    "factoryConstruct.p" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/factoryConstruct.p" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    1,                                // lineNo
    1,                                // colNo
    "evalObjAndConstrAndDerivatives", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
    "+ObjNonlinEvaluator/evalObjAndConstrAndDerivatives.p" // pName
};

// Function Definitions
namespace coder {
real_T fmincon(const emlrtStack &sp, const anonymous_function &fun,
               array<real_T, 1U> &x0, const real_T Aineq_data[],
               const int32_T Aineq_size[2], const real_T bineq_data[],
               const int32_T bineq_size[2], const real_T Aeq_data[],
               const int32_T Aeq_size[2], const real_T beq_data[],
               const int32_T beq_size[2], const real_T lb_data[],
               int32_T lb_size, const real_T ub_data[], int32_T ub_size,
               real_T *exitflag)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  internal::i_stickyStruct FcnEvaluator;
  array<real_T, 2U> Hessian;
  array<real_T, 2U> oj_emlrtRSI;
  array<real_T, 1U> y;
  array<int32_T, 1U> idxDepEq;
  d_struct_T WorkingSet;
  e_struct_T QRManager;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  f_struct_T CholManager;
  g_struct_T QPObjective;
  h_struct_T memspace;
  i_struct_T expl_temp;
  j_struct_T TrialState;
  l_struct_T FiniteDifferences;
  struct_T MeritFunction;
  real_T beqFiltered_data[6];
  real_T fval;
  int32_T loop_ub;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mLinEq_tmp;
  int32_T mLinIneq;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVar;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &eb_emlrtRSI;
  optim::coder::validate::checkX0(st, x0);
  nVar = x0.size(0);
  st.site = &eb_emlrtRSI;
  *exitflag = optim::coder::validate::checkLinearInputs(
      st, x0.size(0), Aineq_data, Aineq_size, bineq_data, bineq_size, Aeq_data,
      Aeq_size, beq_data, beq_size, lb_data, lb_size, ub_data, ub_size);
  st.site = &eb_emlrtRSI;
  expl_temp.FiniteDifferenceStepSize.set_size(&ib_emlrtRTEI, &st, x0.size(0));
  expl_temp.TypicalX.set_size(&m_emlrtRTEI, &st, x0.size(0));
  loop_ub = x0.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    expl_temp.TypicalX[i] = 1.0;
  }
  b_st.site = &qb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  if (x0.size(0) > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  for (mConstrMax = 0; mConstrMax < nVar; mConstrMax++) {
    if (mConstrMax + 1 > expl_temp.FiniteDifferenceStepSize.size(0)) {
      emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                    expl_temp.FiniteDifferenceStepSize.size(0),
                                    &kb_emlrtBCI, &st);
    }
    expl_temp.FiniteDifferenceStepSize[mConstrMax] = 1.4901161193847656E-8;
  }
  mLinEq_tmp = beq_size[0] * beq_size[1];
  mLinIneq = bineq_size[0] * bineq_size[1];
  nVar = (mLinEq_tmp << 1) + 1;
  mConstrMax =
      ((((mLinIneq + mLinEq_tmp) + lb_size) + ub_size) + nVar) + mLinIneq;
  nVar = (x0.size(0) + nVar) + mLinIneq;
  maxDims = muIntScalarMax_sint32(nVar, mConstrMax);
  st.site = &eb_emlrtRSI;
  eye(st, x0.size(0), Hessian);
  if (*exitflag == -2.0) {
    st.site = &eb_emlrtRSI;
    b_st.site = &eb_emlrtRSI;
    eye(b_st, x0.size(0), oj_emlrtRSI);
    fval = rtInf;
  } else {
    int32_T mLB;
    st.site = &eb_emlrtRSI;
    optim::coder::fminconsqp::TrialState::factoryConstruct(
        st, nVar, mConstrMax, mLinIneq, mLinEq_tmp, x0, TrialState);
    st.site = &eb_emlrtRSI;
    if (x0.size(0) >= 1) {
      b_st.site = &ub_emlrtRSI;
      c_st.site = &wb_emlrtRSI;
      n_t = (ptrdiff_t)x0.size(0);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(x0.data())[0], &incx_t, &(TrialState.xstarsqp.data())[0],
            &incy_t);
    }
    FcnEvaluator.next.next.next.next.next.next.next.next.value = fun;
    st.site = &eb_emlrtRSI;
    optim::coder::utils::FiniteDifferences::factoryConstruct(
        st, fun, x0.size(0), lb_data, lb_size, ub_data, ub_size,
        FiniteDifferences);
    QRManager.ldq = maxDims;
    QRManager.QR.set_size(&jb_emlrtRTEI, &sp, maxDims, maxDims);
    QRManager.Q.set_size(&jb_emlrtRTEI, &sp, maxDims, maxDims);
    loop_ub = maxDims * maxDims;
    for (int32_T i{0}; i < loop_ub; i++) {
      QRManager.Q[i] = 0.0;
    }
    QRManager.jpvt.set_size(&m_emlrtRTEI, &sp, maxDims);
    for (int32_T i{0}; i < maxDims; i++) {
      QRManager.jpvt[i] = 0;
    }
    QRManager.mrows = 0;
    QRManager.ncols = 0;
    QRManager.tau.set_size(&jb_emlrtRTEI, &sp,
                           muIntScalarMin_sint32(maxDims, maxDims));
    QRManager.minRowCol = 0;
    QRManager.usedPivoting = false;
    CholManager.FMat.set_size(&kb_emlrtRTEI, &sp, maxDims, maxDims);
    CholManager.ldm = maxDims;
    CholManager.ndims = 0;
    CholManager.info = 0;
    CholManager.scaleFactor = 0.0;
    CholManager.ConvexCheck = true;
    CholManager.regTol_ = rtInf;
    CholManager.workspace_ = rtInf;
    CholManager.workspace2_ = rtInf;
    QPObjective.grad.set_size(&lb_emlrtRTEI, &sp, nVar);
    QPObjective.Hx.set_size(&lb_emlrtRTEI, &sp, nVar - 1);
    QPObjective.maxVar = nVar;
    QPObjective.beta = 0.0;
    QPObjective.rho = 0.0;
    QPObjective.prev_objtype = 3;
    QPObjective.prev_nvar = 0;
    QPObjective.prev_hasLinear = false;
    QPObjective.gammaScalar = 0.0;
    QPObjective.nvar = x0.size(0);
    QPObjective.hasLinear = true;
    QPObjective.objtype = 3;
    memspace.workspace_double.set_size(&m_emlrtRTEI, &sp, maxDims,
                                       muIntScalarMax_sint32(nVar, 2));
    memspace.workspace_int.set_size(&m_emlrtRTEI, &sp, maxDims);
    memspace.workspace_sort.set_size(&m_emlrtRTEI, &sp, maxDims);
    st.site = &eb_emlrtRSI;
    optim::coder::qpactiveset::WorkingSet::factoryConstruct(
        st, mLinIneq, mLinEq_tmp, x0.size(0), nVar, mConstrMax, WorkingSet);
    st.site = &eb_emlrtRSI;
    mLB = optim::coder::qpactiveset::initialize::compressBounds(
        st, x0.size(0), WorkingSet.indexLB, WorkingSet.indexUB,
        WorkingSet.indexFixed, lb_data, lb_size, ub_data, ub_size, mUB, mFixed);
    st.site = &eb_emlrtRSI;
    optim::coder::qpactiveset::WorkingSet::loadProblem(
        st, WorkingSet, mLinIneq, mLinIneq, Aineq_data, Aineq_size, mLinEq_tmp,
        mLinEq_tmp, Aeq_data, Aeq_size, mLB, mUB, mFixed, mConstrMax);
    st.site = &eb_emlrtRSI;
    y.set_size(&m_emlrtRTEI, &st, mLinEq_tmp);
    for (int32_T i{0}; i < mLinEq_tmp; i++) {
      y[i] = beqFiltered_data[i];
    }
    if (mLinEq_tmp >= 1) {
      b_st.site = &ub_emlrtRSI;
      c_st.site = &wb_emlrtRSI;
      n_t = (ptrdiff_t)mLinEq_tmp;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&beq_data[0], &incx_t, &(y.data())[0], &incy_t);
    }
    idxDepEq.set_size(&m_emlrtRTEI, &sp, x0.size(0) + mLinEq_tmp);
    nVar = y.size(0);
    loop_ub = y.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      beqFiltered_data[i] = y[i];
    }
    st.site = &eb_emlrtRSI;
    nVar = optim::coder::fminconsqp::internal::removeDependentLinearEq(
        st, Aeq_data, beqFiltered_data, nVar, ub_data, ub_size, idxDepEq,
        memspace, TrialState, WorkingSet, QRManager, QPObjective);
    if (nVar < 0) {
      nVar = 0;
    }
    maxDims = mLinEq_tmp - nVar;
    if (lb_size != 0) {
      st.site = &eb_emlrtRSI;
      if (mLB > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (mConstrMax = 0; mConstrMax < mLB; mConstrMax++) {
        if ((mConstrMax + 1 < 1) ||
            (mConstrMax + 1 > WorkingSet.indexLB.size(0))) {
          emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                        WorkingSet.indexLB.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        nVar = WorkingSet.indexLB[mConstrMax] - 1;
        if ((WorkingSet.indexLB[mConstrMax] < 1) ||
            (WorkingSet.indexLB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexLB[mConstrMax] < 1) ||
            (WorkingSet.indexLB[mConstrMax] > lb_size)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[mConstrMax], 1,
                                        lb_size, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexLB[mConstrMax] < 1) ||
            (WorkingSet.indexLB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        TrialState.xstarsqp[WorkingSet.indexLB[mConstrMax] - 1] =
            muDoubleScalarMax(TrialState.xstarsqp[nVar], lb_data[nVar]);
      }
    }
    if (ub_size != 0) {
      st.site = &eb_emlrtRSI;
      if (mUB > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (mConstrMax = 0; mConstrMax < mUB; mConstrMax++) {
        if ((mConstrMax + 1 < 1) ||
            (mConstrMax + 1 > WorkingSet.indexUB.size(0))) {
          emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                        WorkingSet.indexUB.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        nVar = WorkingSet.indexUB[mConstrMax] - 1;
        if ((WorkingSet.indexUB[mConstrMax] < 1) ||
            (WorkingSet.indexUB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexUB[mConstrMax] < 1) ||
            (WorkingSet.indexUB[mConstrMax] > ub_size)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[mConstrMax], 1,
                                        ub_size, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexUB[mConstrMax] < 1) ||
            (WorkingSet.indexUB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        TrialState.xstarsqp[WorkingSet.indexUB[mConstrMax] - 1] =
            muDoubleScalarMin(TrialState.xstarsqp[nVar], ub_data[nVar]);
      }
      st.site = &eb_emlrtRSI;
      if (mFixed > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (mConstrMax = 0; mConstrMax < mFixed; mConstrMax++) {
        if ((mConstrMax + 1 < 1) ||
            (mConstrMax + 1 > WorkingSet.indexFixed.size(0))) {
          emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                        WorkingSet.indexFixed.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexFixed[mConstrMax] < 1) ||
            (WorkingSet.indexFixed[mConstrMax] > ub_size)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[mConstrMax], 1,
                                        ub_size, &jb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexFixed[mConstrMax] < 1) ||
            (WorkingSet.indexFixed[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &jb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        TrialState.xstarsqp[WorkingSet.indexFixed[mConstrMax] - 1] =
            ub_data[WorkingSet.indexFixed[mConstrMax] - 1];
      }
    }
    st.site = &eb_emlrtRSI;
    b_st.site = &fd_emlrtRSI;
    c_st.site = &gd_emlrtRSI;
    if (TrialState.xstarsqp.size(0) == 0) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &n_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedNonempty",
          "MATLAB:expectedNonempty", 3, 4, 5, "input");
    }
    y.set_size(&mb_emlrtRTEI, &st, TrialState.xstarsqp.size(0));
    loop_ub = TrialState.xstarsqp.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      y[i] = TrialState.xstarsqp[i];
    }
    b_st.site = &fd_emlrtRSI;
    fval = optim::coder::utils::ObjNonlinEvaluator::computeObjective_(
        b_st, FcnEvaluator, y, nVar);
    if (nVar == 1) {
      b_st.site = &fd_emlrtRSI;
      c_st.site = &se_emlrtRSI;
      d_st.site = &gd_emlrtRSI;
      if (y.size(0) == 0) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &n_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedNonempty",
            "MATLAB:expectedNonempty", 3, 4, 5, "input");
      }
      nVar = 1;
    }
    TrialState.sqpFval = fval;
    if (nVar != 1) {
      emlrtErrorWithMessageIdR2018a(&sp, &m_emlrtRTEI,
                                    "optim_codegen:fmincon:UndefAtX0",
                                    "optim_codegen:fmincon:UndefAtX0", 0);
    }
    TrialState.xstarsqp.set_size(&m_emlrtRTEI, &sp, y.size(0));
    loop_ub = y.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      TrialState.xstarsqp[i] = y[i];
    }
    st.site = &eb_emlrtRSI;
    optim::coder::utils::FiniteDifferences::computeFiniteDifferences(
        st, FiniteDifferences, fval, TrialState.xstarsqp, TrialState.grad,
        lb_data, lb_size, ub_data, ub_size, expl_temp.FiniteDifferenceStepSize,
        expl_temp.TypicalX);
    TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
    st.site = &eb_emlrtRSI;
    optim::coder::fminconsqp::internal::computeLinearResiduals(
        st, TrialState.xstarsqp, x0.size(0), TrialState.cIneq.data,
        TrialState.cIneq.size[0], mLinIneq, WorkingSet.Aineq, bineq_data,
        WorkingSet.ldA, TrialState.cEq.data, TrialState.cEq.size[0], maxDims,
        WorkingSet.Aeq, beqFiltered_data, WorkingSet.ldA);
    st.site = &eb_emlrtRSI;
    optim::coder::fminconsqp::internal::updateWorkingSetForNewQP(
        st, x0, WorkingSet, mLinIneq, TrialState.cIneq.data,
        TrialState.cIneq.size[0], maxDims, TrialState.cEq.data,
        TrialState.cEq.size[0], mLB, lb_data, lb_size, mUB, ub_data, ub_size,
        mFixed);
    st.site = &eb_emlrtRSI;
    optim::coder::qpactiveset::WorkingSet::initActiveSet(st, WorkingSet);
    st.site = &eb_emlrtRSI;
    MeritFunction.penaltyParam = 1.0;
    MeritFunction.threshold = 0.0001;
    MeritFunction.nPenaltyDecreases = 0;
    MeritFunction.linearizedConstrViol = 0.0;
    MeritFunction.initFval = fval;
    if (maxDims < 1) {
      MeritFunction.initConstrViolationEq = 0.0;
    } else {
      n_t = (ptrdiff_t)maxDims;
      incx_t = (ptrdiff_t)1;
      MeritFunction.initConstrViolationEq =
          dasum(&n_t, &TrialState.cEq.data[0], &incx_t);
    }
    b_st.site = &ef_emlrtRSI;
    MeritFunction.initConstrViolationIneq =
        optim::coder::fminconsqp::MeritFunction::computeConstrViolationIneq_(
            b_st, mLinIneq, TrialState.cIneq.data, TrialState.cIneq.size[0]);
    MeritFunction.phi = 0.0;
    MeritFunction.phiPrimePlus = 0.0;
    MeritFunction.phiFullStep = 0.0;
    MeritFunction.feasRelativeFactor = 0.0;
    MeritFunction.nlpPrimalFeasError = 0.0;
    MeritFunction.nlpDualFeasError = 0.0;
    MeritFunction.nlpComplError = 0.0;
    MeritFunction.firstOrderOpt = 0.0;
    MeritFunction.hasObjective = true;
    expl_temp.ConstrRelTolFactor = 1.0;
    expl_temp.MaxFunctionEvaluations = 100 * x0.size(0);
    expl_temp.MaxIterations = 550;
    st.site = &eb_emlrtRSI;
    optim::coder::fminconsqp::driver(
        st, Hessian, bineq_data, beqFiltered_data, lb_data, lb_size, ub_data,
        ub_size, TrialState, MeritFunction, FcnEvaluator, FiniteDifferences,
        memspace, WorkingSet, QRManager, CholManager, QPObjective, mLinIneq,
        expl_temp);
    x0.set_size(&m_emlrtRTEI, &sp, TrialState.xstarsqp.size(0));
    loop_ub = TrialState.xstarsqp.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      x0[i] = TrialState.xstarsqp[i];
    }
    fval = TrialState.sqpFval;
    *exitflag = TrialState.sqpExitFlag;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return fval;
}

} // namespace coder

// End of code generation (fmincon.cpp)
