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
#include "computeFiniteDifferences.h"
#include "driver.h"
#include "eml_int_forloop_overflow_check.h"
#include "evalObjAndConstrAndDerivatives.h"
#include "eye.h"
#include "factoryConstruct.h"
#include "factoryConstruct1.h"
#include "factoryConstruct2.h"
#include "initActiveSet.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "loadProblem.h"
#include "removeDependentLinearEq.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "updateWorkingSetForNewQP.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo h_emlrtRSI{
    1,                                                     // lineNo
    "fmincon",                                             // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/eml/fmincon.p" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    1,                                // lineNo
    "convertFminconOptionsForSolver", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+options/"
    "convertFminconOptionsForSolver.p" // pathName
};

static emlrtRTEInfo p_emlrtRTEI{
    1,                                                     // lineNo
    1,                                                     // colNo
    "fmincon",                                             // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/eml/fmincon.p" // pName
};

static emlrtBCInfo u_emlrtBCI{
    -1,                                                     // iFirst
    -1,                                                     // iLast
    1,                                                      // lineNo
    1,                                                      // colNo
    "",                                                     // aName
    "fmincon",                                              // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/eml/fmincon.p", // pName
    0                                                       // checkKind
};

static emlrtBCInfo v_emlrtBCI{
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

static emlrtRTEInfo nb_emlrtRTEI{
    1,                                // lineNo
    1,                                // colNo
    "convertFminconOptionsForSolver", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+options/"
    "convertFminconOptionsForSolver.p" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "factoryConstruct.p" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+CholManager/"
    "factoryConstruct.p" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/factoryConstruct.p" // pName
};

// Function Definitions
namespace coder {
real_T fmincon(const emlrtStack &sp, const anonymous_function &fun,
               array<real_T, 1U> &x0, const array<real_T, 2U> &Aeq,
               const real_T beq_data[], int32_T beq_size,
               const array<real_T, 1U> &lb, const array<real_T, 1U> &ub,
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
  d_struct_T QRManager;
  e_struct_T CholManager;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  f_struct_T QPObjective;
  g_struct_T memspace;
  h_struct_T expl_temp;
  i_struct_T TrialState;
  j_struct_T WorkingSet;
  l_struct_T FiniteDifferences;
  struct_T obj;
  real_T beqFiltered_data[6];
  real_T fval;
  int32_T loop_ub;
  int32_T mConstrMax;
  int32_T mFixed;
  int32_T mUB;
  int32_T maxDims;
  int32_T nVar;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &h_emlrtRSI;
  optim::coder::validate::checkX0(st, x0);
  nVar = x0.size(0);
  st.site = &h_emlrtRSI;
  *exitflag = optim::coder::validate::checkLinearInputs(
      st, x0.size(0), Aeq, beq_data, beq_size, lb, ub);
  st.site = &h_emlrtRSI;
  expl_temp.FiniteDifferenceStepSize.set_size(&nb_emlrtRTEI, &st, x0.size(0));
  expl_temp.TypicalX.set_size(&p_emlrtRTEI, &st, x0.size(0));
  loop_ub = x0.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    expl_temp.TypicalX[i] = 1.0;
  }
  b_st.site = &t_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  if (x0.size(0) > 2147483646) {
    c_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  for (mConstrMax = 0; mConstrMax < nVar; mConstrMax++) {
    if (mConstrMax + 1 > expl_temp.FiniteDifferenceStepSize.size(0)) {
      emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                    expl_temp.FiniteDifferenceStepSize.size(0),
                                    &v_emlrtBCI, &st);
    }
    expl_temp.FiniteDifferenceStepSize[mConstrMax] = 1.4901161193847656E-8;
  }
  nVar = (beq_size << 1) + 1;
  mConstrMax = ((beq_size + lb.size(0)) + ub.size(0)) + nVar;
  nVar += x0.size(0);
  maxDims = muIntScalarMax_sint32(nVar, mConstrMax);
  st.site = &h_emlrtRSI;
  eye(st, x0.size(0), Hessian);
  if (*exitflag == -2.0) {
    st.site = &h_emlrtRSI;
    b_st.site = &h_emlrtRSI;
    eye(b_st, x0.size(0), oj_emlrtRSI);
    fval = rtInf;
  } else {
    int32_T mLB;
    st.site = &h_emlrtRSI;
    optim::coder::fminconsqp::TrialState::factoryConstruct(
        st, nVar, mConstrMax, beq_size, x0, TrialState);
    st.site = &h_emlrtRSI;
    if (x0.size(0) >= 1) {
      b_st.site = &x_emlrtRSI;
      n_t = (ptrdiff_t)x0.size(0);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(x0.data())[0], &incx_t, &(TrialState.xstarsqp.data())[0],
            &incy_t);
    }
    FcnEvaluator.next.next.next.next.next.next.next.next.value = fun;
    st.site = &h_emlrtRSI;
    optim::coder::utils::FiniteDifferences::factoryConstruct(
        st, fun, x0.size(0), lb, ub, FiniteDifferences);
    QRManager.ldq = maxDims;
    QRManager.QR.set_size(&ob_emlrtRTEI, &sp, maxDims, maxDims);
    QRManager.Q.set_size(&ob_emlrtRTEI, &sp, maxDims, maxDims);
    loop_ub = maxDims * maxDims;
    for (int32_T i{0}; i < loop_ub; i++) {
      QRManager.Q[i] = 0.0;
    }
    QRManager.jpvt.set_size(&p_emlrtRTEI, &sp, maxDims);
    for (int32_T i{0}; i < maxDims; i++) {
      QRManager.jpvt[i] = 0;
    }
    QRManager.mrows = 0;
    QRManager.ncols = 0;
    QRManager.tau.set_size(&ob_emlrtRTEI, &sp,
                           muIntScalarMin_sint32(maxDims, maxDims));
    QRManager.minRowCol = 0;
    QRManager.usedPivoting = false;
    CholManager.FMat.set_size(&pb_emlrtRTEI, &sp, maxDims, maxDims);
    CholManager.ldm = maxDims;
    CholManager.ndims = 0;
    CholManager.info = 0;
    CholManager.scaleFactor = 0.0;
    CholManager.ConvexCheck = true;
    CholManager.regTol_ = rtInf;
    CholManager.workspace_ = rtInf;
    CholManager.workspace2_ = rtInf;
    QPObjective.grad.set_size(&qb_emlrtRTEI, &sp, nVar);
    QPObjective.Hx.set_size(&qb_emlrtRTEI, &sp, nVar - 1);
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
    memspace.workspace_double.set_size(&p_emlrtRTEI, &sp, maxDims,
                                       muIntScalarMax_sint32(nVar, 2));
    memspace.workspace_int.set_size(&p_emlrtRTEI, &sp, maxDims);
    memspace.workspace_sort.set_size(&p_emlrtRTEI, &sp, maxDims);
    st.site = &h_emlrtRSI;
    optim::coder::qpactiveset::WorkingSet::factoryConstruct(
        st, beq_size, x0.size(0), nVar, mConstrMax, WorkingSet);
    st.site = &h_emlrtRSI;
    mLB = optim::coder::qpactiveset::initialize::compressBounds(
        st, x0.size(0), WorkingSet.indexLB, WorkingSet.indexUB,
        WorkingSet.indexFixed, lb, ub, mUB, mFixed);
    st.site = &h_emlrtRSI;
    optim::coder::qpactiveset::WorkingSet::loadProblem(
        st, WorkingSet, beq_size, beq_size, Aeq, mLB, mUB, mFixed, mConstrMax);
    st.site = &h_emlrtRSI;
    y.set_size(&p_emlrtRTEI, &st, beq_size);
    for (int32_T i{0}; i < beq_size; i++) {
      y[i] = beqFiltered_data[i];
    }
    if (beq_size >= 1) {
      b_st.site = &x_emlrtRSI;
      n_t = (ptrdiff_t)beq_size;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, (real_T *)&beq_data[0], &incx_t, &(y.data())[0], &incy_t);
    }
    idxDepEq.set_size(&p_emlrtRTEI, &sp, x0.size(0) + beq_size);
    nVar = y.size(0);
    loop_ub = y.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      beqFiltered_data[i] = y[i];
    }
    st.site = &h_emlrtRSI;
    nVar = optim::coder::fminconsqp::internal::removeDependentLinearEq(
        st, Aeq, beqFiltered_data, nVar, ub, idxDepEq, memspace, TrialState,
        WorkingSet, QRManager, QPObjective);
    if (nVar < 0) {
      nVar = 0;
    }
    maxDims = beq_size - nVar;
    if (lb.size(0) != 0) {
      st.site = &h_emlrtRSI;
      if (mLB > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (mConstrMax = 0; mConstrMax < mLB; mConstrMax++) {
        if ((mConstrMax + 1 < 1) ||
            (mConstrMax + 1 > WorkingSet.indexLB.size(0))) {
          emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                        WorkingSet.indexLB.size(0), &u_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        nVar = WorkingSet.indexLB[mConstrMax] - 1;
        if ((WorkingSet.indexLB[mConstrMax] < 1) ||
            (WorkingSet.indexLB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &u_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexLB[mConstrMax] < 1) ||
            (WorkingSet.indexLB[mConstrMax] > lb.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[mConstrMax], 1,
                                        lb.size(0), &u_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexLB[mConstrMax] < 1) ||
            (WorkingSet.indexLB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &u_emlrtBCI, (emlrtConstCTX)&sp);
        }
        TrialState.xstarsqp[WorkingSet.indexLB[mConstrMax] - 1] =
            muDoubleScalarMax(TrialState.xstarsqp[nVar], lb[nVar]);
      }
    }
    if (ub.size(0) != 0) {
      st.site = &h_emlrtRSI;
      if (mUB > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (mConstrMax = 0; mConstrMax < mUB; mConstrMax++) {
        if ((mConstrMax + 1 < 1) ||
            (mConstrMax + 1 > WorkingSet.indexUB.size(0))) {
          emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                        WorkingSet.indexUB.size(0), &u_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        nVar = WorkingSet.indexUB[mConstrMax] - 1;
        if ((WorkingSet.indexUB[mConstrMax] < 1) ||
            (WorkingSet.indexUB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &u_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexUB[mConstrMax] < 1) ||
            (WorkingSet.indexUB[mConstrMax] > ub.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[mConstrMax], 1,
                                        ub.size(0), &u_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexUB[mConstrMax] < 1) ||
            (WorkingSet.indexUB[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &u_emlrtBCI, (emlrtConstCTX)&sp);
        }
        TrialState.xstarsqp[WorkingSet.indexUB[mConstrMax] - 1] =
            muDoubleScalarMin(TrialState.xstarsqp[nVar], ub[nVar]);
      }
      st.site = &h_emlrtRSI;
      if (mFixed > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (mConstrMax = 0; mConstrMax < mFixed; mConstrMax++) {
        if ((mConstrMax + 1 < 1) ||
            (mConstrMax + 1 > WorkingSet.indexFixed.size(0))) {
          emlrtDynamicBoundsCheckR2012b(mConstrMax + 1, 1,
                                        WorkingSet.indexFixed.size(0),
                                        &u_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexFixed[mConstrMax] < 1) ||
            (WorkingSet.indexFixed[mConstrMax] > ub.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[mConstrMax], 1,
                                        ub.size(0), &u_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((WorkingSet.indexFixed[mConstrMax] < 1) ||
            (WorkingSet.indexFixed[mConstrMax] > TrialState.xstarsqp.size(0))) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[mConstrMax], 1,
                                        TrialState.xstarsqp.size(0),
                                        &u_emlrtBCI, (emlrtConstCTX)&sp);
        }
        TrialState.xstarsqp[WorkingSet.indexFixed[mConstrMax] - 1] =
            ub[WorkingSet.indexFixed[mConstrMax] - 1];
      }
    }
    st.site = &h_emlrtRSI;
    TrialState.sqpFval =
        optim::coder::utils::ObjNonlinEvaluator::evalObjAndConstrAndDerivatives(
            st, FcnEvaluator, TrialState.xstarsqp, nVar);
    if (nVar != 1) {
      emlrtErrorWithMessageIdR2018a(&sp, &p_emlrtRTEI,
                                    "optim_codegen:fmincon:UndefAtX0",
                                    "optim_codegen:fmincon:UndefAtX0", 0);
    }
    st.site = &h_emlrtRSI;
    optim::coder::utils::FiniteDifferences::computeFiniteDifferences(
        st, FiniteDifferences, TrialState.sqpFval, TrialState.xstarsqp,
        TrialState.grad, lb, ub, expl_temp.FiniteDifferenceStepSize,
        expl_temp.TypicalX);
    TrialState.FunctionEvaluations = FiniteDifferences.numEvals + 1;
    st.site = &h_emlrtRSI;
    if (maxDims > 0) {
      b_st.site = &ff_emlrtRSI;
      y.set_size(&rb_emlrtRTEI, &b_st, TrialState.cEq.size[0]);
      loop_ub = TrialState.cEq.size[0];
      for (int32_T i{0}; i < loop_ub; i++) {
        y[i] = TrialState.cEq.data[i];
      }
      n_t = (ptrdiff_t)maxDims;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &beqFiltered_data[0], &incx_t, &(y.data())[0], &incy_t);
      b_st.site = &ff_emlrtRSI;
      internal::blas::xgemv(x0.size(0), maxDims, WorkingSet.Aeq, WorkingSet.ldA,
                            TrialState.xstarsqp, y);
      TrialState.cEq.size[0] = y.size(0);
      loop_ub = y.size(0);
      for (int32_T i{0}; i < loop_ub; i++) {
        TrialState.cEq.data[i] = y[i];
      }
    }
    st.site = &h_emlrtRSI;
    optim::coder::fminconsqp::internal::updateWorkingSetForNewQP(
        st, x0, WorkingSet, maxDims, TrialState.cEq.data,
        TrialState.cEq.size[0], mLB, lb, mUB, ub, mFixed);
    st.site = &h_emlrtRSI;
    optim::coder::qpactiveset::WorkingSet::initActiveSet(st, WorkingSet);
    obj.penaltyParam = 1.0;
    obj.threshold = 0.0001;
    obj.nPenaltyDecreases = 0;
    obj.linearizedConstrViol = 0.0;
    obj.initFval = TrialState.sqpFval;
    if (maxDims < 1) {
      obj.initConstrViolationEq = 0.0;
    } else {
      n_t = (ptrdiff_t)maxDims;
      incx_t = (ptrdiff_t)1;
      obj.initConstrViolationEq = dasum(&n_t, &TrialState.cEq.data[0], &incx_t);
    }
    obj.initConstrViolationIneq = 0.0;
    obj.phi = 0.0;
    obj.phiPrimePlus = 0.0;
    obj.phiFullStep = 0.0;
    obj.feasRelativeFactor = 0.0;
    obj.nlpPrimalFeasError = 0.0;
    obj.nlpDualFeasError = 0.0;
    obj.nlpComplError = 0.0;
    obj.firstOrderOpt = 0.0;
    obj.hasObjective = true;
    expl_temp.ConstrRelTolFactor = 1.0;
    expl_temp.MaxFunctionEvaluations = 100 * x0.size(0);
    expl_temp.MaxIterations = 1000;
    st.site = &h_emlrtRSI;
    optim::coder::fminconsqp::driver(
        st, Hessian, beqFiltered_data, lb, ub, TrialState, obj, FcnEvaluator,
        FiniteDifferences, memspace, WorkingSet, QRManager, CholManager,
        QPObjective, expl_temp);
    x0.set_size(&p_emlrtRTEI, &sp, TrialState.xstarsqp.size(0));
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
