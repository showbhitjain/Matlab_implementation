//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// iterate.cpp
//
// Code generation for function 'iterate'
//

// Include files
#include "iterate.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "compute_lambda.h"
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xcopy.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    ud_emlrtRSI{
        65,           // lineNo
        "xaxpy_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xaxpy.m" // pathName
    };

static emlrtRSInfo ih_emlrtRSI{
    1,         // lineNo
    "iterate", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "iterate.p" // pathName
};

static emlrtRSInfo ki_emlrtRSI{
    1,                 // lineNo
    "find_neg_lambda", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "find_neg_lambda.p" // pathName
};

static emlrtRSInfo mi_emlrtRSI{
    1,                // lineNo
    "addAineqConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p" // pathName
};

static emlrtRSInfo pi_emlrtRSI{
    1,             // lineNo
    "addUBConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addUBConstr.p" // pathName
};

static emlrtRSInfo qi_emlrtRSI{
    1,                          // lineNo
    "checkUnboundedOrIllPosed", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkUnboundedOrIllPosed.p" // pathName
};

static emlrtBCInfo rc_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    1,         // lineNo
    1,         // colNo
    "",        // aName
    "iterate", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "iterate.p", // pName
    0            // checkKind
};

static emlrtBCInfo tc_emlrtBCI{
    1,                // iFirst
    0,                // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "addAineqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p", // pName
    0                               // checkKind
};

static emlrtBCInfo uc_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "addAineqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p", // pName
    0                               // checkKind
};

static emlrtBCInfo vc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "find_neg_lambda", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "find_neg_lambda.p", // pName
    0                    // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void iterate(const emlrtStack &sp, const array<real_T, 2U> &H,
             const array<real_T, 1U> &f, i_struct_T &solution,
             g_struct_T &memspace, j_struct_T &workingset,
             d_struct_T &qrmanager, e_struct_T &cholmanager,
             f_struct_T &objective, const char_T options_SolverName[7],
             real_T options_StepTolerance, real_T options_ObjectiveLimit,
             int32_T runTimeOptions_MaxIterations)
{
  static const char_T b[7]{'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T a;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T idxMinLambda;
  int32_T nVar_tmp;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective.objtype;
  nVar_tmp = workingset.nVar;
  globalActiveConstrIdx = 0;
  st.site = &ih_emlrtRSI;
  Objective::computeGrad_StoreHx(st, objective, H, f, solution.xstar);
  st.site = &ih_emlrtRSI;
  solution.fstar = Objective::computeFval_ReuseHx(
      st, objective, memspace.workspace_double, f, solution.xstar);
  if (solution.iterations < runTimeOptions_MaxIterations) {
    solution.state = -5;
  } else {
    solution.state = 0;
  }
  st.site = &ih_emlrtRSI;
  internal::blas::xcopy(st, workingset.mConstrMax, solution.lambda);
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      real_T normDelta;
      int32_T colOffset;
      int32_T i1;
      int32_T iAineq0;
      boolean_T guard1;
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          st.site = &ih_emlrtRSI;
          QRManager::squareQ_appendCol(
              st, qrmanager, workingset.ATwset,
              workingset.ldA * (workingset.nActiveConstr - 1) + 1);
          break;
        case -1:
          st.site = &ih_emlrtRSI;
          QRManager::deleteColMoveEnd(st, qrmanager, globalActiveConstrIdx);
          break;
        default:
          st.site = &ih_emlrtRSI;
          QRManager::factorQR(st, qrmanager, workingset.ATwset, nVar_tmp,
                              workingset.nActiveConstr, workingset.ldA);
          st.site = &ih_emlrtRSI;
          b_st.site = &bc_emlrtRSI;
          QRManager::computeQ_(b_st, qrmanager, qrmanager.mrows);
          break;
        }
        st.site = &ih_emlrtRSI;
        compute_deltax(st, H, solution, memspace, qrmanager, cholmanager,
                       objective,
                       std::memcmp((char_T *)&options_SolverName[0],
                                   (char_T *)&b[0], 7) == 0);
        if (solution.state != -5) {
          exitg1 = 1;
        } else {
          if (nVar_tmp < 1) {
            normDelta = 0.0;
          } else {
            n_t = (ptrdiff_t)nVar_tmp;
            incx_t = (ptrdiff_t)1;
            normDelta = dnrm2(&n_t, &(solution.searchDir.data())[0], &incx_t);
          }
          if ((normDelta < options_StepTolerance) ||
              (workingset.nActiveConstr >= nVar_tmp)) {
            guard1 = true;
          } else {
            st.site = &ih_emlrtRSI;
            a = feasibleratiotest(
                st, solution.xstar, solution.searchDir,
                memspace.workspace_double, workingset.nVar, workingset.ldA,
                workingset.Aineq.size[0], workingset.lb, workingset.ub,
                workingset.indexLB, workingset.indexUB, workingset.sizes,
                workingset.isActiveIdx, workingset.isActiveConstr,
                workingset.nWConstr, TYPE == 5, updateFval, i, idxMinLambda);
            if (updateFval) {
              switch (i) {
              case 3:
                st.site = &ih_emlrtRSI;
                b_st.site = &mi_emlrtRSI;
                workingset.nWConstr[2]++;
                i = workingset.isActiveConstr.size(0);
                i1 = (workingset.isActiveIdx[2] + idxMinLambda) - 1;
                if ((i1 < 1) || (i1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sc_emlrtBCI, &b_st);
                }
                workingset.isActiveConstr[i1 - 1] = true;
                workingset.nActiveConstr++;
                i = workingset.Wid.size(0);
                if ((workingset.nActiveConstr < 1) ||
                    (workingset.nActiveConstr > i)) {
                  emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                                &sc_emlrtBCI, &b_st);
                }
                i = workingset.nActiveConstr - 1;
                workingset.Wid[i] = 3;
                i1 = workingset.Wlocalidx.size(0);
                if ((workingset.nActiveConstr < 1) ||
                    (workingset.nActiveConstr > i1)) {
                  emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i1,
                                                &sc_emlrtBCI, &b_st);
                }
                workingset.Wlocalidx[i] = idxMinLambda;
                iAineq0 = workingset.ldA * (idxMinLambda - 1) + 1;
                colOffset = workingset.ldA * i + 1;
                i = workingset.nVar - 1;
                for (int32_T idx{0}; idx <= i; idx++) {
                  i1 = iAineq0 + idx;
                  if ((i1 < 1) || (i1 > 0)) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, 0, &uc_emlrtBCI, &st);
                  }
                  i1 = workingset.ATwset.size(0);
                  activeSetChangeID = colOffset + idx;
                  if ((activeSetChangeID < 1) || (activeSetChangeID > i1)) {
                    emlrtDynamicBoundsCheckR2012b(activeSetChangeID, 1, i1,
                                                  &uc_emlrtBCI, &st);
                  }
                }
                emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, 0, &tc_emlrtBCI,
                                              &st);
                break;
              case 4:
                st.site = &ih_emlrtRSI;
                b_st.site = &ni_emlrtRSI;
                WorkingSet::addBoundToActiveSetMatrix_(b_st, workingset,
                                                       idxMinLambda);
                break;
              default:
                st.site = &ih_emlrtRSI;
                b_st.site = &pi_emlrtRSI;
                c_st.site = &oi_emlrtRSI;
                workingset.nWConstr[4]++;
                i = workingset.isActiveConstr.size(0);
                i1 = (workingset.isActiveIdx[4] + idxMinLambda) - 1;
                if ((i1 < 1) || (i1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sc_emlrtBCI, &c_st);
                }
                workingset.isActiveConstr[i1 - 1] = true;
                workingset.nActiveConstr++;
                i = workingset.Wid.size(0);
                if ((workingset.nActiveConstr < 1) ||
                    (workingset.nActiveConstr > i)) {
                  emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                                &sc_emlrtBCI, &c_st);
                }
                i = workingset.nActiveConstr - 1;
                workingset.Wid[i] = 5;
                i1 = workingset.Wlocalidx.size(0);
                if ((workingset.nActiveConstr < 1) ||
                    (workingset.nActiveConstr > i1)) {
                  emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i1,
                                                &sc_emlrtBCI, &c_st);
                }
                workingset.Wlocalidx[i] = idxMinLambda;
                colOffset = workingset.ldA * i;
                i1 = workingset.indexUB.size(0);
                if ((idxMinLambda < 1) || (idxMinLambda > i1)) {
                  emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i1,
                                                &qc_emlrtBCI, &b_st);
                }
                i1 = workingset.ub.size(0);
                activeSetChangeID = workingset.indexUB[idxMinLambda - 1];
                if ((activeSetChangeID < 1) || (activeSetChangeID > i1)) {
                  emlrtDynamicBoundsCheckR2012b(
                      workingset.indexUB[idxMinLambda - 1], 1, i1, &qc_emlrtBCI,
                      &b_st);
                }
                i1 = workingset.bwset.size(0);
                if ((workingset.nActiveConstr < 1) ||
                    (workingset.nActiveConstr > i1)) {
                  emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i1,
                                                &qc_emlrtBCI, &b_st);
                }
                workingset.bwset[i] = workingset.ub[activeSetChangeID - 1];
                c_st.site = &oi_emlrtRSI;
                for (int32_T idx{0}; idx <= activeSetChangeID - 2; idx++) {
                  i = workingset.ATwset.size(0);
                  i1 = (idx + colOffset) + 1;
                  if ((i1 < 1) || (i1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &qc_emlrtBCI,
                                                  &b_st);
                  }
                  workingset.ATwset[i1 - 1] = 0.0;
                }
                i = workingset.ATwset.size(0);
                i1 = activeSetChangeID + colOffset;
                if ((i1 < 1) || (i1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(i1, 1, i, &qc_emlrtBCI, &b_st);
                }
                workingset.ATwset[i1 - 1] = 1.0;
                iAineq0 = activeSetChangeID + 1;
                c_st.site = &oi_emlrtRSI;
                if ((activeSetChangeID + 1 <= workingset.nVar) &&
                    (workingset.nVar > 2147483646)) {
                  d_st.site = &f_emlrtRSI;
                  check_forloop_overflow_error(d_st);
                }
                for (int32_T idx{iAineq0}; idx <= nVar_tmp; idx++) {
                  i = workingset.ATwset.size(0);
                  i1 = idx + colOffset;
                  if ((i1 < 1) || (i1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &qc_emlrtBCI,
                                                  &b_st);
                  }
                  workingset.ATwset[i1 - 1] = 0.0;
                }
                switch (workingset.probType) {
                case 3:
                case 2:
                  break;
                default:
                  i = workingset.ATwset.size(0);
                  i1 = workingset.nVar + colOffset;
                  if ((i1 < 1) || (i1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &qc_emlrtBCI,
                                                  &b_st);
                  }
                  workingset.ATwset[i1 - 1] = -1.0;
                  break;
                }
                break;
              }
              activeSetChangeID = 1;
            } else {
              st.site = &ih_emlrtRSI;
              if (objective.objtype == 5) {
                if (objective.nvar < 1) {
                  normDelta = 0.0;
                } else {
                  n_t = (ptrdiff_t)objective.nvar;
                  incx_t = (ptrdiff_t)1;
                  normDelta =
                      dnrm2(&n_t, &(solution.searchDir.data())[0], &incx_t);
                }
                b_st.site = &qi_emlrtRSI;
                if (normDelta > 100.0 * static_cast<real_T>(objective.nvar) *
                                    1.4901161193847656E-8) {
                  solution.state = 3;
                } else {
                  solution.state = 4;
                }
              }
              subProblemChanged = false;
              if (workingset.nActiveConstr == 0) {
                solution.state = 1;
              }
            }
            st.site = &ih_emlrtRSI;
            if (nVar_tmp >= 1) {
              b_st.site = &td_emlrtRSI;
              c_st.site = &ud_emlrtRSI;
              n_t = (ptrdiff_t)nVar_tmp;
              incx_t = (ptrdiff_t)1;
              incy_t = (ptrdiff_t)1;
              daxpy(&n_t, &a, &(solution.searchDir.data())[0], &incx_t,
                    &(solution.xstar.data())[0], &incy_t);
            }
            st.site = &ih_emlrtRSI;
            Objective::computeGrad_StoreHx(st, objective, H, f, solution.xstar);
            updateFval = true;
            st.site = &ih_emlrtRSI;
            stopping::checkStoppingAndUpdateFval(
                st, activeSetChangeID, f, solution, memspace, objective,
                workingset, qrmanager, options_ObjectiveLimit,
                runTimeOptions_MaxIterations, updateFval);
          }
        }
      } else {
        st.site = &ih_emlrtRSI;
        internal::blas::xcopy(st, nVar_tmp, solution.searchDir);
        guard1 = true;
      }
      if (guard1) {
        st.site = &ih_emlrtRSI;
        compute_lambda(st, memspace.workspace_double, solution, objective,
                       qrmanager);
        if ((solution.state != -7) || (workingset.nActiveConstr > nVar_tmp)) {
          st.site = &ih_emlrtRSI;
          idxMinLambda = 0;
          normDelta = 0.0;
          iAineq0 = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          colOffset = workingset.nActiveConstr;
          b_st.site = &ki_emlrtRSI;
          if ((iAineq0 <= workingset.nActiveConstr) &&
              (workingset.nActiveConstr > 2147483646)) {
            c_st.site = &f_emlrtRSI;
            check_forloop_overflow_error(c_st);
          }
          for (int32_T idx{iAineq0}; idx <= colOffset; idx++) {
            i = solution.lambda.size(0);
            if ((idx < 1) || (idx > i)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, i, &vc_emlrtBCI, &st);
            }
            a = solution.lambda[idx - 1];
            if (a < normDelta) {
              i = solution.lambda.size(0);
              if (idx > i) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, i, &vc_emlrtBCI, &st);
              }
              normDelta = a;
              idxMinLambda = idx;
            }
          }
          if (idxMinLambda == 0) {
            solution.state = 1;
          } else {
            activeSetChangeID = -1;
            globalActiveConstrIdx = idxMinLambda;
            subProblemChanged = true;
            i = workingset.Wid.size(0);
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &rc_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            i = workingset.Wlocalidx.size(0);
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &rc_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            st.site = &ih_emlrtRSI;
            i = workingset.Wid.size(0);
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &vb_emlrtBCI,
                                            &st);
            }
            iAineq0 = workingset.Wid[idxMinLambda - 1];
            i = workingset.Wlocalidx.size(0);
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &vb_emlrtBCI,
                                            &st);
            }
            if ((iAineq0 < 1) || (iAineq0 > 6)) {
              emlrtDynamicBoundsCheckR2012b(workingset.Wid[idxMinLambda - 1], 1,
                                            6, &wb_emlrtBCI, &st);
            }
            i = workingset.isActiveConstr.size(0);
            i1 = (workingset.isActiveIdx[iAineq0 - 1] +
                  workingset.Wlocalidx[idxMinLambda - 1]) -
                 1;
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI, &st);
            }
            workingset.isActiveConstr[i1 - 1] = false;
            b_st.site = &ig_emlrtRSI;
            WorkingSet::moveConstraint_(b_st, workingset,
                                        workingset.nActiveConstr, idxMinLambda);
            workingset.nActiveConstr--;
            if (iAineq0 > 5) {
              emlrtDynamicBoundsCheckR2012b(6, 1, 5, &yb_emlrtBCI, &st);
            }
            workingset.nWConstr[iAineq0 - 1]--;
            i = solution.lambda.size(0);
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &rc_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            solution.lambda[idxMinLambda - 1] = 0.0;
          }
        } else {
          idxMinLambda = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          i = workingset.Wid.size(0);
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &rc_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i = workingset.Wlocalidx.size(0);
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &rc_emlrtBCI, (emlrtConstCTX)&sp);
          }
          st.site = &ih_emlrtRSI;
          i = workingset.Wid.size(0);
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &vb_emlrtBCI, &st);
          }
          iAineq0 = workingset.nActiveConstr - 1;
          colOffset = workingset.Wid[iAineq0];
          i = workingset.Wlocalidx.size(0);
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &vb_emlrtBCI, &st);
          }
          if ((colOffset < 1) || (colOffset > 6)) {
            emlrtDynamicBoundsCheckR2012b(
                workingset.Wid[workingset.nActiveConstr - 1], 1, 6,
                &wb_emlrtBCI, &st);
          }
          i = workingset.isActiveConstr.size(0);
          i1 = (workingset.isActiveIdx[colOffset - 1] +
                workingset.Wlocalidx[iAineq0]) -
               1;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI, &st);
          }
          workingset.isActiveConstr[i1 - 1] = false;
          b_st.site = &ig_emlrtRSI;
          WorkingSet::moveConstraint_(b_st, workingset,
                                      workingset.nActiveConstr,
                                      workingset.nActiveConstr);
          workingset.nActiveConstr = iAineq0;
          if (colOffset > 5) {
            emlrtDynamicBoundsCheckR2012b(6, 1, 5, &yb_emlrtBCI, &st);
          }
          workingset.nWConstr[colOffset - 1]--;
          i = solution.lambda.size(0);
          if ((idxMinLambda < 1) || (idxMinLambda > i)) {
            emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &rc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          solution.lambda[idxMinLambda - 1] = 0.0;
        }
        updateFval = false;
        st.site = &ih_emlrtRSI;
        stopping::checkStoppingAndUpdateFval(
            st, activeSetChangeID, f, solution, memspace, objective, workingset,
            qrmanager, options_ObjectiveLimit, runTimeOptions_MaxIterations,
            updateFval);
      }
    } else {
      if (!updateFval) {
        st.site = &ih_emlrtRSI;
        solution.fstar = Objective::computeFval_ReuseHx(
            st, objective, memspace.workspace_double, f, solution.xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (iterate.cpp)
