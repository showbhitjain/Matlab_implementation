//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver1.cpp
//
// Code generation for function 'driver1'
//

// Include files
#include "driver1.h"
#include "PresolveWorkingSet.h"
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "iterate.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "setProblemType.h"
#include "xcopy.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    dg_emlrtRSI{
        1,        // lineNo
        "driver", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
        "driver.p" // pathName
    };

static emlrtRSInfo eg_emlrtRSI{
    1,             // lineNo
    "snap_bounds", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "snap_bounds.p" // pathName
};

static emlrtRSInfo dh_emlrtRSI{
    1,          // lineNo
    "phaseone", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "phaseone.p" // pathName
};

static emlrtBCInfo tb_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    1,             // lineNo
    1,             // colNo
    "",            // aName
    "snap_bounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "snap_bounds.p", // pName
    0                // checkKind
};

static emlrtRTEInfo r_emlrtRTEI{
    13,               // lineNo
    37,               // colNo
    "validatesquare", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatesquare.m" // pName
};

static emlrtBCInfo xb_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    1,          // lineNo
    1,          // colNo
    "",         // aName
    "phaseone", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "phaseone.p", // pName
    0             // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const emlrtStack &sp, const array<real_T, 2U> &H,
            const array<real_T, 1U> &f, i_struct_T &solution,
            g_struct_T &memspace, j_struct_T &workingset, d_struct_T &qrmanager,
            e_struct_T &cholmanager, f_struct_T &objective, k_struct_T &options,
            int32_T runTimeOptions_MaxIterations)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T mEqFixed;
  int32_T nVar_tmp;
  int32_T startIdx;
  boolean_T guard1;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &dg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ic_emlrtRSI;
  if (H.size(0) != H.size(1)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &r_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedSquare",
        "MATLAB:expectedSquare", 3, 4, 5, "input");
  }
  b_st.site = &ic_emlrtRSI;
  if ((H.size(0) == 0) || (H.size(1) == 0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &q_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:expectedNonempty", 3, 4, 5, "input");
  }
  solution.iterations = 0;
  nVar_tmp = workingset.nVar;
  guard1 = false;
  if (workingset.probType == 3) {
    st.site = &dg_emlrtRSI;
    startIdx = workingset.sizes[0];
    b_st.site = &eg_emlrtRSI;
    if (workingset.sizes[0] > 2147483646) {
      c_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (mEqFixed = 0; mEqFixed < startIdx; mEqFixed++) {
      i = workingset.indexFixed.size(0);
      if ((mEqFixed + 1 < 1) || (mEqFixed + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(mEqFixed + 1, 1, i, &tb_emlrtBCI, &st);
      }
      i = workingset.ub.size(0);
      if ((workingset.indexFixed[mEqFixed] < 1) ||
          (workingset.indexFixed[mEqFixed] > i)) {
        emlrtDynamicBoundsCheckR2012b(workingset.indexFixed[mEqFixed], 1, i,
                                      &tb_emlrtBCI, &st);
      }
      i = solution.xstar.size(0);
      if ((workingset.indexFixed[mEqFixed] < 1) ||
          (workingset.indexFixed[mEqFixed] > i)) {
        emlrtDynamicBoundsCheckR2012b(workingset.indexFixed[mEqFixed], 1, i,
                                      &tb_emlrtBCI, &st);
      }
      solution.xstar[workingset.indexFixed[mEqFixed] - 1] =
          workingset.ub[workingset.indexFixed[mEqFixed] - 1];
    }
    startIdx = workingset.sizes[3];
    b_st.site = &eg_emlrtRSI;
    if (workingset.sizes[3] > 2147483646) {
      c_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (mEqFixed = 0; mEqFixed < startIdx; mEqFixed++) {
      i = workingset.isActiveConstr.size(0);
      i1 = workingset.isActiveIdx[3] + mEqFixed;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &tb_emlrtBCI, &st);
      }
      if (workingset.isActiveConstr[i1 - 1]) {
        i = workingset.indexLB.size(0);
        if ((mEqFixed + 1 < 1) || (mEqFixed + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(mEqFixed + 1, 1, i, &tb_emlrtBCI, &st);
        }
        i = workingset.lb.size(0);
        if ((workingset.indexLB[mEqFixed] < 1) ||
            (workingset.indexLB[mEqFixed] > i)) {
          emlrtDynamicBoundsCheckR2012b(workingset.indexLB[mEqFixed], 1, i,
                                        &tb_emlrtBCI, &st);
        }
        i = solution.xstar.size(0);
        if ((workingset.indexLB[mEqFixed] < 1) ||
            (workingset.indexLB[mEqFixed] > i)) {
          emlrtDynamicBoundsCheckR2012b(workingset.indexLB[mEqFixed], 1, i,
                                        &tb_emlrtBCI, &st);
        }
        solution.xstar[workingset.indexLB[mEqFixed] - 1] =
            -workingset.lb[workingset.indexLB[mEqFixed] - 1];
      }
    }
    startIdx = workingset.sizes[4];
    b_st.site = &eg_emlrtRSI;
    if (workingset.sizes[4] > 2147483646) {
      c_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (mEqFixed = 0; mEqFixed < startIdx; mEqFixed++) {
      i = workingset.isActiveConstr.size(0);
      i1 = workingset.isActiveIdx[4] + mEqFixed;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &tb_emlrtBCI, &st);
      }
      if (workingset.isActiveConstr[i1 - 1]) {
        i = workingset.indexUB.size(0);
        if ((mEqFixed + 1 < 1) || (mEqFixed + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(mEqFixed + 1, 1, i, &tb_emlrtBCI, &st);
        }
        i = workingset.ub.size(0);
        if ((workingset.indexUB[mEqFixed] < 1) ||
            (workingset.indexUB[mEqFixed] > i)) {
          emlrtDynamicBoundsCheckR2012b(workingset.indexUB[mEqFixed], 1, i,
                                        &tb_emlrtBCI, &st);
        }
        i = solution.xstar.size(0);
        if ((workingset.indexUB[mEqFixed] < 1) ||
            (workingset.indexUB[mEqFixed] > i)) {
          emlrtDynamicBoundsCheckR2012b(workingset.indexUB[mEqFixed], 1, i,
                                        &tb_emlrtBCI, &st);
        }
        solution.xstar[workingset.indexUB[mEqFixed] - 1] =
            workingset.ub[workingset.indexUB[mEqFixed] - 1];
      }
    }
    st.site = &dg_emlrtRSI;
    initialize::PresolveWorkingSet(st, solution, memspace, workingset,
                                   qrmanager);
    if (solution.state >= 0) {
      guard1 = true;
    }
  } else {
    solution.state = 82;
    guard1 = true;
  }
  if (guard1) {
    solution.iterations = 0;
    st.site = &dg_emlrtRSI;
    solution.maxConstr =
        WorkingSet::maxConstraintViolation(st, workingset, solution.xstar);
    if (solution.maxConstr > 1.0E-6) {
      int32_T PROBTYPE_ORIG;
      int32_T nVarP1_tmp;
      st.site = &dg_emlrtRSI;
      PROBTYPE_ORIG = workingset.probType;
      nVarP1_tmp = workingset.nVar + 1;
      i = solution.xstar.size(0);
      if ((nVarP1_tmp < 1) || (nVarP1_tmp > i)) {
        emlrtDynamicBoundsCheckR2012b(nVarP1_tmp, 1, i, &xb_emlrtBCI, &st);
      }
      solution.xstar[nVarP1_tmp - 1] = solution.maxConstr + 1.0;
      if (workingset.probType == 3) {
        i = 1;
      } else {
        i = 4;
      }
      b_st.site = &dh_emlrtRSI;
      WorkingSet::setProblemType(b_st, workingset, i);
      b_st.site = &dh_emlrtRSI;
      WorkingSet::removeAllIneqConstr(b_st, workingset);
      objective.prev_objtype = objective.objtype;
      objective.prev_nvar = objective.nvar;
      objective.prev_hasLinear = objective.hasLinear;
      objective.objtype = 5;
      objective.nvar = nVarP1_tmp;
      objective.gammaScalar = 1.0;
      objective.hasLinear = true;
      b_st.site = &dh_emlrtRSI;
      solution.fstar = Objective::computeFval(
          b_st, objective, memspace.workspace_double, H, f, solution.xstar);
      solution.state = 5;
      b_st.site = &dh_emlrtRSI;
      iterate(b_st, H, f, solution, memspace, workingset, qrmanager,
              cholmanager, objective, options.SolverName,
              1.4901161193847657E-10, 1.0E-6, runTimeOptions_MaxIterations);
      startIdx = (workingset.sizes[0] + workingset.sizes[1]) + 1;
      b_st.site = &dh_emlrtRSI;
      i = workingset.isActiveConstr.size(0);
      i1 = workingset.isActiveIdx[3] + workingset.sizes[3];
      if ((i1 - 1 < 1) || (i1 - 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1 - 1, 1, i, &ub_emlrtBCI, &b_st);
      }
      if (workingset.isActiveConstr[i1 - 2]) {
        boolean_T exitg1;
        b_st.site = &dh_emlrtRSI;
        if ((startIdx <= workingset.nActiveConstr) &&
            (workingset.nActiveConstr > 2147483646)) {
          c_st.site = &f_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        exitg1 = false;
        while ((!exitg1) && (startIdx <= workingset.nActiveConstr)) {
          i = workingset.Wid.size(0);
          if ((startIdx < 1) || (startIdx > i)) {
            emlrtDynamicBoundsCheckR2012b(startIdx, 1, i, &xb_emlrtBCI, &st);
          }
          i = workingset.Wid[startIdx - 1];
          if (i == 4) {
            i = workingset.Wlocalidx.size(0);
            if (startIdx > i) {
              emlrtDynamicBoundsCheckR2012b(startIdx, 1, i, &xb_emlrtBCI, &st);
            }
            i = workingset.Wlocalidx[startIdx - 1];
            if (i == workingset.sizes[3]) {
              b_st.site = &dh_emlrtRSI;
              i1 = workingset.Wid.size(0);
              if (startIdx > i1) {
                emlrtDynamicBoundsCheckR2012b(startIdx, 1, i1, &vb_emlrtBCI,
                                              &b_st);
              }
              i1 = workingset.Wlocalidx.size(0);
              if (startIdx > i1) {
                emlrtDynamicBoundsCheckR2012b(startIdx, 1, i1, &vb_emlrtBCI,
                                              &b_st);
              }
              i1 = workingset.isActiveConstr.size(0);
              i = (workingset.isActiveIdx[3] + i) - 1;
              if ((i < 1) || (i > i1)) {
                emlrtDynamicBoundsCheckR2012b(i, 1, i1, &vb_emlrtBCI, &b_st);
              }
              workingset.isActiveConstr[i - 1] = false;
              c_st.site = &ig_emlrtRSI;
              WorkingSet::moveConstraint_(c_st, workingset,
                                          workingset.nActiveConstr, startIdx);
              workingset.nActiveConstr--;
              workingset.nWConstr[3]--;
              exitg1 = true;
            } else {
              startIdx++;
            }
          } else {
            startIdx++;
          }
        }
      }
      startIdx = workingset.nActiveConstr;
      mEqFixed = workingset.sizes[0] + workingset.sizes[1];
      while ((startIdx > mEqFixed) && (startIdx > nVar_tmp)) {
        int32_T TYPE_tmp;
        b_st.site = &dh_emlrtRSI;
        i = workingset.Wid.size(0);
        if ((startIdx < 1) || (startIdx > i)) {
          emlrtDynamicBoundsCheckR2012b(startIdx, 1, i, &vb_emlrtBCI, &b_st);
        }
        TYPE_tmp = workingset.Wid[startIdx - 1];
        i = workingset.Wlocalidx.size(0);
        if (startIdx > i) {
          emlrtDynamicBoundsCheckR2012b(startIdx, 1, i, &vb_emlrtBCI, &b_st);
        }
        if ((TYPE_tmp < 1) || (TYPE_tmp > 6)) {
          emlrtDynamicBoundsCheckR2012b(workingset.Wid[startIdx - 1], 1, 6,
                                        &wb_emlrtBCI, &b_st);
        }
        i = workingset.isActiveConstr.size(0);
        i1 = (workingset.isActiveIdx[TYPE_tmp - 1] +
              workingset.Wlocalidx[startIdx - 1]) -
             1;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI, &b_st);
        }
        workingset.isActiveConstr[i1 - 1] = false;
        c_st.site = &ig_emlrtRSI;
        WorkingSet::moveConstraint_(c_st, workingset, workingset.nActiveConstr,
                                    startIdx);
        workingset.nActiveConstr--;
        if (TYPE_tmp > 5) {
          emlrtDynamicBoundsCheckR2012b(6, 1, 5, &yb_emlrtBCI, &b_st);
        }
        workingset.nWConstr[TYPE_tmp - 1]--;
        startIdx--;
      }
      i = solution.xstar.size(0);
      if (nVarP1_tmp > i) {
        emlrtDynamicBoundsCheckR2012b(nVarP1_tmp, 1, i, &xb_emlrtBCI, &st);
      }
      solution.maxConstr = solution.xstar[nVarP1_tmp - 1];
      b_st.site = &dh_emlrtRSI;
      WorkingSet::setProblemType(b_st, workingset, PROBTYPE_ORIG);
      objective.objtype = objective.prev_objtype;
      objective.nvar = objective.prev_nvar;
      objective.hasLinear = objective.prev_hasLinear;
      options.ObjectiveLimit = rtMinusInf;
      options.StepTolerance = 1.0E-6;
      if (solution.state != 0) {
        st.site = &dg_emlrtRSI;
        solution.maxConstr =
            WorkingSet::maxConstraintViolation(st, workingset, solution.xstar);
        if (solution.maxConstr > 1.0E-6) {
          st.site = &dg_emlrtRSI;
          internal::blas::xcopy(st, workingset.mConstrMax, solution.lambda);
          st.site = &dg_emlrtRSI;
          solution.fstar = Objective::computeFval(
              st, objective, memspace.workspace_double, H, f, solution.xstar);
          solution.state = -2;
        } else {
          if (solution.maxConstr > 0.0) {
            real_T maxConstr_new;
            st.site = &dg_emlrtRSI;
            if (nVar_tmp >= 1) {
              b_st.site = &x_emlrtRSI;
              n_t = (ptrdiff_t)nVar_tmp;
              incx_t = (ptrdiff_t)1;
              incy_t = (ptrdiff_t)1;
              dcopy(&n_t, &(solution.xstar.data())[0], &incx_t,
                    &(solution.searchDir.data())[0], &incy_t);
            }
            st.site = &dg_emlrtRSI;
            initialize::PresolveWorkingSet(st, solution, memspace, workingset,
                                           qrmanager);
            st.site = &dg_emlrtRSI;
            maxConstr_new = WorkingSet::maxConstraintViolation(st, workingset,
                                                               solution.xstar);
            if (maxConstr_new >= solution.maxConstr) {
              solution.maxConstr = maxConstr_new;
              st.site = &dg_emlrtRSI;
              if (nVar_tmp >= 1) {
                b_st.site = &x_emlrtRSI;
                n_t = (ptrdiff_t)nVar_tmp;
                incx_t = (ptrdiff_t)1;
                incy_t = (ptrdiff_t)1;
                dcopy(&n_t, &(solution.searchDir.data())[0], &incx_t,
                      &(solution.xstar.data())[0], &incy_t);
              }
            }
          }
          st.site = &dg_emlrtRSI;
          iterate(st, H, f, solution, memspace, workingset, qrmanager,
                  cholmanager, objective, options.SolverName,
                  options.StepTolerance, options.ObjectiveLimit,
                  runTimeOptions_MaxIterations);
        }
      }
    } else {
      st.site = &dg_emlrtRSI;
      iterate(st, H, f, solution, memspace, workingset, qrmanager, cholmanager,
              objective, options.SolverName, options.StepTolerance,
              options.ObjectiveLimit, runTimeOptions_MaxIterations);
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver1.cpp)
