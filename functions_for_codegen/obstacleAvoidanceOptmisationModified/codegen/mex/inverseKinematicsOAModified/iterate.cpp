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
#include "addAineqConstr.h"
#include "addBoundToActiveSetMatrix_.h"
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "computeGrad_StoreHx.h"
#include "computeQ_.h"
#include "compute_deltax.h"
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "feasibleratiotest.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include "squareQ_appendCol.h"
#include "xcopy.h"
#include "xgemv.h"
#include "xtrsv.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo fh_emlrtRSI{
    1,         // lineNo
    "iterate", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "iterate.p" // pathName
};

static emlrtRSInfo ki_emlrtRSI{
    1,                // lineNo
    "compute_lambda", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_lambda.p" // pathName
};

static emlrtRSInfo li_emlrtRSI{
    1,                 // lineNo
    "find_neg_lambda", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "find_neg_lambda.p" // pathName
};

static emlrtRSInfo ri_emlrtRSI{
    1,                          // lineNo
    "checkUnboundedOrIllPosed", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkUnboundedOrIllPosed.p" // pathName
};

static emlrtBCInfo fd_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "isNonDegenerate", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "isNonDegenerate.p", // pName
    0                    // checkKind
};

static emlrtBCInfo gd_emlrtBCI{
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

static emlrtBCInfo hd_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "compute_lambda", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_lambda.p", // pName
    0                   // checkKind
};

static emlrtBCInfo id_emlrtBCI{
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

static emlrtRTEInfo dc_emlrtRTEI{
    1,         // lineNo
    1,         // colNo
    "iterate", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "iterate.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void iterate(const emlrtStack &sp, const array<real_T, 2U> &H,
             const array<real_T, 1U> &f, j_struct_T &solution,
             h_struct_T &memspace, d_struct_T &workingset,
             e_struct_T &qrmanager, f_struct_T &cholmanager,
             g_struct_T &objective, const char_T options_SolverName[7],
             real_T options_StepTolerance, real_T options_ObjectiveLimit,
             int32_T runTimeOptions_MaxIterations)
{
  static const char_T b[7]{'f', 'm', 'i', 'n', 'c', 'o', 'n'};
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T a;
  int32_T TYPE;
  int32_T activeSetChangeID;
  int32_T globalActiveConstrIdx;
  int32_T i;
  int32_T idxQR;
  int32_T nVar;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective.objtype;
  nVar = workingset.nVar;
  globalActiveConstrIdx = 0;
  st.site = &fh_emlrtRSI;
  Objective::computeGrad_StoreHx(st, objective, H, f, solution.xstar);
  st.site = &fh_emlrtRSI;
  solution.fstar = Objective::computeFval_ReuseHx(
      st, objective, memspace.workspace_double, f, solution.xstar);
  if (solution.iterations < runTimeOptions_MaxIterations) {
    solution.state = -5;
  } else {
    solution.state = 0;
  }
  r.set_size(&dc_emlrtRTEI, &sp, solution.lambda.size[0]);
  idxQR = solution.lambda.size[0];
  for (i = 0; i < idxQR; i++) {
    r[i] = solution.lambda.data[i];
  }
  st.site = &fh_emlrtRSI;
  internal::blas::xcopy(st, workingset.mConstrMax, r);
  solution.lambda.size[0] = r.size(0);
  idxQR = r.size(0);
  for (i = 0; i < idxQR; i++) {
    solution.lambda.data[i] = r[i];
  }
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (solution.state == -5) {
      real_T normDelta;
      boolean_T guard1;
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
        case 1:
          st.site = &fh_emlrtRSI;
          QRManager::squareQ_appendCol(
              st, qrmanager, workingset.ATwset,
              workingset.ldA * (workingset.nActiveConstr - 1) + 1);
          break;
        case -1:
          st.site = &fh_emlrtRSI;
          QRManager::deleteColMoveEnd(st, qrmanager, globalActiveConstrIdx);
          break;
        default:
          st.site = &fh_emlrtRSI;
          QRManager::factorQR(st, qrmanager, workingset.ATwset, nVar,
                              workingset.nActiveConstr, workingset.ldA);
          st.site = &fh_emlrtRSI;
          b_st.site = &yc_emlrtRSI;
          QRManager::computeQ_(b_st, qrmanager, qrmanager.mrows);
          break;
        }
        st.site = &fh_emlrtRSI;
        compute_deltax(st, H, solution, memspace, qrmanager, cholmanager,
                       objective,
                       std::memcmp((char_T *)&options_SolverName[0],
                                   (char_T *)&b[0], 7) == 0);
        if (solution.state != -5) {
          exitg1 = 1;
        } else {
          if (nVar < 1) {
            normDelta = 0.0;
          } else {
            n_t = (ptrdiff_t)nVar;
            incx_t = (ptrdiff_t)1;
            normDelta = dnrm2(&n_t, &(solution.searchDir.data())[0], &incx_t);
          }
          if ((normDelta < options_StepTolerance) ||
              (workingset.nActiveConstr >= nVar)) {
            guard1 = true;
          } else {
            st.site = &fh_emlrtRSI;
            a = feasibleratiotest(
                st, solution.xstar, solution.searchDir,
                memspace.workspace_double, workingset.nVar, workingset.ldA,
                workingset.Aineq, workingset.bineq.data, workingset.lb,
                workingset.ub, workingset.indexLB, workingset.indexUB,
                workingset.sizes, workingset.isActiveIdx,
                workingset.isActiveConstr.data,
                workingset.isActiveConstr.size[0], workingset.nWConstr,
                TYPE == 5, updateFval, i, idxQR);
            if (updateFval) {
              switch (i) {
              case 3:
                st.site = &fh_emlrtRSI;
                WorkingSet::addAineqConstr(st, workingset, idxQR);
                break;
              case 4:
                st.site = &fh_emlrtRSI;
                b_st.site = &oi_emlrtRSI;
                WorkingSet::addBoundToActiveSetMatrix_(b_st, workingset, idxQR);
                break;
              default:
                st.site = &fh_emlrtRSI;
                b_st.site = &qi_emlrtRSI;
                WorkingSet::b_addBoundToActiveSetMatrix_(b_st, workingset,
                                                         idxQR);
                break;
              }
              activeSetChangeID = 1;
            } else {
              st.site = &fh_emlrtRSI;
              if (objective.objtype == 5) {
                if (objective.nvar < 1) {
                  normDelta = 0.0;
                } else {
                  n_t = (ptrdiff_t)objective.nvar;
                  incx_t = (ptrdiff_t)1;
                  normDelta =
                      dnrm2(&n_t, &(solution.searchDir.data())[0], &incx_t);
                }
                b_st.site = &ri_emlrtRSI;
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
            st.site = &fh_emlrtRSI;
            if (nVar >= 1) {
              b_st.site = &ug_emlrtRSI;
              n_t = (ptrdiff_t)nVar;
              incx_t = (ptrdiff_t)1;
              incy_t = (ptrdiff_t)1;
              daxpy(&n_t, &a, &(solution.searchDir.data())[0], &incx_t,
                    &(solution.xstar.data())[0], &incy_t);
            }
            st.site = &fh_emlrtRSI;
            Objective::computeGrad_StoreHx(st, objective, H, f, solution.xstar);
            updateFval = true;
            st.site = &fh_emlrtRSI;
            stopping::checkStoppingAndUpdateFval(
                st, activeSetChangeID, f, solution, memspace, objective,
                workingset, qrmanager, options_ObjectiveLimit,
                runTimeOptions_MaxIterations, updateFval);
          }
        }
      } else {
        st.site = &fh_emlrtRSI;
        internal::blas::xcopy(st, nVar, solution.searchDir);
        guard1 = true;
      }
      if (guard1) {
        int32_T i1;
        int32_T idx;
        int32_T nActiveConstr_tmp;
        st.site = &fh_emlrtRSI;
        nActiveConstr_tmp = qrmanager.ncols;
        if (qrmanager.ncols > 0) {
          boolean_T b_guard1;
          b_guard1 = false;
          if (objective.objtype != 4) {
            normDelta = 100.0 * static_cast<real_T>(qrmanager.mrows) *
                        2.2204460492503131E-16;
            b_st.site = &ki_emlrtRSI;
            if ((qrmanager.mrows > 0) && (qrmanager.ncols > 0)) {
              updateFval = true;
            } else {
              updateFval = false;
            }
            if (updateFval) {
              boolean_T exitg2;
              boolean_T guard2;
              idx = nActiveConstr_tmp;
              guard2 = false;
              if (qrmanager.mrows < qrmanager.ncols) {
                idxQR = qrmanager.mrows + qrmanager.ldq * (qrmanager.ncols - 1);
                exitg2 = false;
                while ((!exitg2) && (idx > qrmanager.mrows)) {
                  i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
                  if ((idxQR < 1) || (idxQR > i)) {
                    emlrtDynamicBoundsCheckR2012b(idxQR, 1, i, &fd_emlrtBCI,
                                                  &b_st);
                  }
                  if (muDoubleScalarAbs(qrmanager.QR[idxQR - 1]) >= normDelta) {
                    idx--;
                    idxQR -= qrmanager.ldq;
                  } else {
                    exitg2 = true;
                  }
                }
                updateFval = (idx == qrmanager.mrows);
                if (updateFval) {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }
              if (guard2) {
                idxQR = idx + qrmanager.ldq * (idx - 1);
                exitg2 = false;
                while ((!exitg2) && (idx >= 1)) {
                  i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
                  if ((idxQR < 1) || (idxQR > i)) {
                    emlrtDynamicBoundsCheckR2012b(idxQR, 1, i, &fd_emlrtBCI,
                                                  &b_st);
                  }
                  if (muDoubleScalarAbs(qrmanager.QR[idxQR - 1]) >= normDelta) {
                    idx--;
                    idxQR = (idxQR - qrmanager.ldq) - 1;
                  } else {
                    exitg2 = true;
                  }
                }
                updateFval = (idx == 0);
              }
            }
            if (!updateFval) {
              solution.state = -7;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }
          if (b_guard1) {
            b_st.site = &ki_emlrtRSI;
            internal::blas::xgemv(qrmanager.mrows, qrmanager.ncols, qrmanager.Q,
                                  qrmanager.ldq, objective.grad,
                                  memspace.workspace_double);
            b_st.site = &ki_emlrtRSI;
            internal::blas::xtrsv(qrmanager.ncols, qrmanager.QR, qrmanager.ldq,
                                  memspace.workspace_double);
            b_st.site = &ki_emlrtRSI;
            if (qrmanager.ncols > 2147483646) {
              c_st.site = &o_emlrtRSI;
              check_forloop_overflow_error(c_st);
            }
            i = memspace.workspace_double.size(0) *
                memspace.workspace_double.size(1);
            for (idx = 0; idx < nActiveConstr_tmp; idx++) {
              if ((idx + 1 < 1) || (idx + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &hd_emlrtBCI, &st);
              }
              i1 = solution.lambda.size[0];
              if (idx + 1 > i1) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &hd_emlrtBCI,
                                              &st);
              }
              solution.lambda.data[idx] = -memspace.workspace_double[idx];
            }
          }
        }
        if ((solution.state != -7) || (workingset.nActiveConstr > nVar)) {
          int32_T idxMinLambda;
          st.site = &fh_emlrtRSI;
          idxMinLambda = 0;
          normDelta = 0.0;
          idxQR = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
          nActiveConstr_tmp = workingset.nActiveConstr;
          b_st.site = &li_emlrtRSI;
          if ((idxQR <= workingset.nActiveConstr) &&
              (workingset.nActiveConstr > 2147483646)) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(c_st);
          }
          for (idx = idxQR; idx <= nActiveConstr_tmp; idx++) {
            i = solution.lambda.size[0];
            if ((idx < 1) || (idx > i)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, i, &id_emlrtBCI, &st);
            }
            a = solution.lambda.data[idx - 1];
            if (a < normDelta) {
              i = solution.lambda.size[0];
              if (idx > i) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, i, &id_emlrtBCI, &st);
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
            i = workingset.Wid.size[0];
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &gd_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            i = workingset.Wlocalidx.size[0];
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &gd_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            st.site = &fh_emlrtRSI;
            i = workingset.Wid.size[0];
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &kc_emlrtBCI,
                                            &st);
            }
            idxQR = workingset.Wid.data[idxMinLambda - 1];
            i = workingset.Wlocalidx.size[0];
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &kc_emlrtBCI,
                                            &st);
            }
            if ((idxQR < 1) || (idxQR > 6)) {
              emlrtDynamicBoundsCheckR2012b(
                  workingset.Wid.data[idxMinLambda - 1], 1, 6, &lc_emlrtBCI,
                  &st);
            }
            i = workingset.isActiveConstr.size[0];
            i1 = (workingset.isActiveIdx[idxQR - 1] +
                  workingset.Wlocalidx.data[idxMinLambda - 1]) -
                 1;
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &kc_emlrtBCI, &st);
            }
            workingset.isActiveConstr.data[i1 - 1] = false;
            b_st.site = &eg_emlrtRSI;
            WorkingSet::moveConstraint_(b_st, workingset,
                                        workingset.nActiveConstr, idxMinLambda);
            workingset.nActiveConstr--;
            if (idxQR > 5) {
              emlrtDynamicBoundsCheckR2012b(6, 1, 5, &nc_emlrtBCI, &st);
            }
            workingset.nWConstr[idxQR - 1]--;
            i = solution.lambda.size[0];
            if (idxMinLambda > i) {
              emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &gd_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            solution.lambda.data[idxMinLambda - 1] = 0.0;
          }
        } else {
          int32_T idxMinLambda;
          idxMinLambda = workingset.nActiveConstr;
          activeSetChangeID = 0;
          globalActiveConstrIdx = workingset.nActiveConstr;
          subProblemChanged = true;
          i = workingset.Wid.size[0];
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &gd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i = workingset.Wlocalidx.size[0];
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &gd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          st.site = &fh_emlrtRSI;
          i = workingset.Wid.size[0];
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &kc_emlrtBCI, &st);
          }
          idxQR = workingset.nActiveConstr - 1;
          nActiveConstr_tmp = workingset.Wid.data[idxQR];
          i = workingset.Wlocalidx.size[0];
          if ((workingset.nActiveConstr < 1) ||
              (workingset.nActiveConstr > i)) {
            emlrtDynamicBoundsCheckR2012b(workingset.nActiveConstr, 1, i,
                                          &kc_emlrtBCI, &st);
          }
          if ((nActiveConstr_tmp < 1) || (nActiveConstr_tmp > 6)) {
            emlrtDynamicBoundsCheckR2012b(
                workingset.Wid.data[workingset.nActiveConstr - 1], 1, 6,
                &lc_emlrtBCI, &st);
          }
          i = workingset.isActiveConstr.size[0];
          i1 = (workingset.isActiveIdx[nActiveConstr_tmp - 1] +
                workingset.Wlocalidx.data[idxQR]) -
               1;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &kc_emlrtBCI, &st);
          }
          workingset.isActiveConstr.data[i1 - 1] = false;
          b_st.site = &eg_emlrtRSI;
          WorkingSet::moveConstraint_(b_st, workingset,
                                      workingset.nActiveConstr,
                                      workingset.nActiveConstr);
          workingset.nActiveConstr = idxQR;
          if (nActiveConstr_tmp > 5) {
            emlrtDynamicBoundsCheckR2012b(6, 1, 5, &nc_emlrtBCI, &st);
          }
          workingset.nWConstr[nActiveConstr_tmp - 1]--;
          i = solution.lambda.size[0];
          if ((idxMinLambda < 1) || (idxMinLambda > i)) {
            emlrtDynamicBoundsCheckR2012b(idxMinLambda, 1, i, &gd_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          solution.lambda.data[idxMinLambda - 1] = 0.0;
        }
        updateFval = false;
        st.site = &fh_emlrtRSI;
        stopping::checkStoppingAndUpdateFval(
            st, activeSetChangeID, f, solution, memspace, objective, workingset,
            qrmanager, options_ObjectiveLimit, runTimeOptions_MaxIterations,
            updateFval);
      }
    } else {
      if (!updateFval) {
        st.site = &fh_emlrtRSI;
        solution.fstar = Objective::computeFval_ReuseHx(
            st, objective, memspace.workspace_double, f, solution.xstar);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (iterate.cpp)
