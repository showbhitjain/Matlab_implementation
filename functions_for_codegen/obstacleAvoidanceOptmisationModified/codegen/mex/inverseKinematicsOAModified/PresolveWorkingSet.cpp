//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// PresolveWorkingSet.cpp
//
// Code generation for function 'PresolveWorkingSet'
//

// Include files
#include "PresolveWorkingSet.h"
#include "ComputeNumDependentEq_.h"
#include "IndexOfDependentEq_.h"
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "maxConstraintViolation.h"
#include "moveConstraint_.h"
#include "removeAllIneqConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo ag_emlrtRSI{
    1,                    // lineNo
    "PresolveWorkingSet", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/PresolveWorkingSet.p" // pathName
};

static emlrtRSInfo bg_emlrtRSI{
    1,                    // lineNo
    "RemoveDependentEq_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentEq_.p" // pathName
};

static emlrtRSInfo cg_emlrtRSI{
    1,                // lineNo
    "removeEqConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeEqConstr.p" // pathName
};

static emlrtBCInfo oc_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    1,                    // lineNo
    1,                    // colNo
    "",                   // aName
    "RemoveDependentEq_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentEq_.p", // pName
    0                                   // checkKind
};

static emlrtBCInfo qc_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "removeEqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeEqConstr.p", // pName
    0                               // checkKind
};

static emlrtBCInfo rc_emlrtBCI{
    1,                // iFirst
    6,                // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "removeEqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeEqConstr.p", // pName
    0                               // checkKind
};

static emlrtBCInfo sc_emlrtBCI{
    1,                // iFirst
    5,                // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "removeEqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeEqConstr.p", // pName
    3                               // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void PresolveWorkingSet(const emlrtStack &sp, j_struct_T &solution,
                        h_struct_T &memspace, d_struct_T &workingset,
                        e_struct_T &qrmanager)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T TYPE;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T idx;
  int32_T nActiveConstr;
  int32_T nDepInd;
  int32_T nDepIneq;
  int32_T nVar_tmp;
  boolean_T overflow;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  solution.state = 82;
  st.site = &ag_emlrtRSI;
  nVar_tmp = workingset.nVar;
  nActiveConstr = workingset.nWConstr[0] + workingset.nWConstr[1];
  nDepInd = 0;
  if (nActiveConstr > 0) {
    b_st.site = &bg_emlrtRSI;
    if (nActiveConstr > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    overflow = (nVar_tmp > 2147483646);
    for (nDepIneq = 0; nDepIneq < nActiveConstr; nDepIneq++) {
      b_st.site = &bg_emlrtRSI;
      if (overflow) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (TYPE = 0; TYPE < nVar_tmp; TYPE++) {
        i = workingset.ATwset.size(0);
        i1 = (TYPE + workingset.ldA * nDepIneq) + 1;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &oc_emlrtBCI, &st);
        }
        i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
        i2 = (nDepIneq + qrmanager.ldq * TYPE) + 1;
        if ((i2 < 1) || (i2 > i)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &oc_emlrtBCI, &st);
        }
        qrmanager.QR[i2 - 1] = workingset.ATwset[i1 - 1];
      }
    }
    b_st.site = &bg_emlrtRSI;
    nDepInd = ComputeNumDependentEq_(b_st, qrmanager, workingset.bwset,
                                     nActiveConstr, workingset.nVar);
    if (nDepInd > 0) {
      b_st.site = &bg_emlrtRSI;
      for (TYPE = 0; TYPE < nActiveConstr; TYPE++) {
        b_st.site = &bg_emlrtRSI;
        if (nVar_tmp >= 1) {
          c_st.site = &ub_emlrtRSI;
          n_t = (ptrdiff_t)nVar_tmp;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &workingset.ATwset[workingset.ldA * TYPE], &incx_t,
                &qrmanager.QR[qrmanager.ldq * TYPE], &incy_t);
        }
      }
      b_st.site = &bg_emlrtRSI;
      IndexOfDependentEq_(b_st, memspace.workspace_int, workingset.nWConstr[0],
                          nDepInd, qrmanager, workingset.nVar, nActiveConstr);
      b_st.site = &bg_emlrtRSI;
      utils::countsort(b_st, memspace.workspace_int, nDepInd,
                       memspace.workspace_sort, nActiveConstr);
      i = memspace.workspace_int.size(0);
      for (idx = nDepInd; idx >= 1; idx--) {
        b_st.site = &bg_emlrtRSI;
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &oc_emlrtBCI, &b_st);
        }
        i1 = workingset.nWConstr[0] + workingset.nWConstr[1];
        if (i1 != 0) {
          i2 = memspace.workspace_int[idx - 1];
          if (i2 <= i1) {
            if ((workingset.nActiveConstr == i1) || (i2 == i1)) {
              workingset.mEqRemoved++;
              i1 = workingset.Wlocalidx.size(0);
              if ((i2 < 1) || (i2 > i1)) {
                emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &qc_emlrtBCI, &b_st);
              }
              i1 = workingset.indexEqRemoved.size[0];
              if ((workingset.mEqRemoved < 1) || (workingset.mEqRemoved > i1)) {
                emlrtDynamicBoundsCheckR2012b(workingset.mEqRemoved, 1, i1,
                                              &qc_emlrtBCI, &b_st);
              }
              workingset.indexEqRemoved.data[workingset.mEqRemoved - 1] =
                  workingset.Wlocalidx[i2 - 1];
              c_st.site = &cg_emlrtRSI;
              i1 = workingset.Wid.size(0);
              if (i2 > i1) {
                emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &kc_emlrtBCI, &c_st);
              }
              TYPE = workingset.Wid[i2 - 1];
              i1 = workingset.Wlocalidx.size(0);
              if (i2 > i1) {
                emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &kc_emlrtBCI, &c_st);
              }
              i1 = workingset.Wid[i2 - 1];
              if ((i1 < 1) || (i1 > 6)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, 6, &lc_emlrtBCI, &c_st);
              }
              i1 = workingset.isActiveConstr.size(0);
              nActiveConstr =
                  (workingset.isActiveIdx[workingset.Wid[i2 - 1] - 1] +
                   workingset.Wlocalidx[i2 - 1]) -
                  1;
              if ((nActiveConstr < 1) || (nActiveConstr > i1)) {
                emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, i1,
                                              &kc_emlrtBCI, &c_st);
              }
              workingset.isActiveConstr[nActiveConstr - 1] = false;
              d_st.site = &dg_emlrtRSI;
              WorkingSet::moveConstraint_(d_st, workingset,
                                          workingset.nActiveConstr, i2);
              workingset.nActiveConstr--;
              if ((TYPE < 1) || (TYPE > 5)) {
                emlrtDynamicBoundsCheckR2012b(TYPE, 1, 5, &nc_emlrtBCI, &c_st);
              }
              workingset.nWConstr[TYPE - 1]--;
            } else {
              workingset.mEqRemoved++;
              nActiveConstr = workingset.Wid.size(0);
              if ((i2 < 1) || (i2 > nActiveConstr)) {
                emlrtDynamicBoundsCheckR2012b(i2, 1, nActiveConstr,
                                              &qc_emlrtBCI, &b_st);
              }
              TYPE = workingset.Wid[i2 - 1];
              nActiveConstr = workingset.Wlocalidx.size(0);
              if (i2 > nActiveConstr) {
                emlrtDynamicBoundsCheckR2012b(i2, 1, nActiveConstr,
                                              &qc_emlrtBCI, &b_st);
              }
              nActiveConstr = workingset.indexEqRemoved.size[0];
              if ((workingset.mEqRemoved < 1) ||
                  (workingset.mEqRemoved > nActiveConstr)) {
                emlrtDynamicBoundsCheckR2012b(workingset.mEqRemoved, 1,
                                              nActiveConstr, &qc_emlrtBCI,
                                              &b_st);
              }
              workingset.indexEqRemoved.data[workingset.mEqRemoved - 1] =
                  workingset.Wlocalidx[i2 - 1];
              nActiveConstr = workingset.Wid[i2 - 1];
              if ((nActiveConstr < 1) || (nActiveConstr > 6)) {
                emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, 6, &rc_emlrtBCI,
                                              &b_st);
              }
              nActiveConstr = workingset.isActiveConstr.size(0);
              nDepIneq = (workingset.isActiveIdx[workingset.Wid[i2 - 1] - 1] +
                          workingset.Wlocalidx[i2 - 1]) -
                         1;
              if ((nDepIneq < 1) || (nDepIneq > nActiveConstr)) {
                emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, nActiveConstr,
                                              &qc_emlrtBCI, &b_st);
              }
              workingset.isActiveConstr[nDepIneq - 1] = false;
              c_st.site = &cg_emlrtRSI;
              WorkingSet::moveConstraint_(c_st, workingset, i1, i2);
              c_st.site = &cg_emlrtRSI;
              WorkingSet::moveConstraint_(c_st, workingset,
                                          workingset.nActiveConstr, i1);
              workingset.nActiveConstr--;
              if ((TYPE < 1) || (TYPE > 5)) {
                emlrtDynamicBoundsCheckR2012b(TYPE, 1, 5, &sc_emlrtBCI, &b_st);
              }
              workingset.nWConstr[TYPE - 1]--;
            }
          }
        }
      }
    }
  }
  if ((nDepInd != -1) && (workingset.nActiveConstr <= qrmanager.ldq)) {
    real_T tol;
    boolean_T guard1;
    st.site = &ag_emlrtRSI;
    nActiveConstr = workingset.nActiveConstr;
    i = workingset.nWConstr[0] + workingset.nWConstr[1];
    if ((workingset.nWConstr[2] + workingset.nWConstr[3]) +
            workingset.nWConstr[4] >
        0) {
      tol =
          100.0 * static_cast<real_T>(workingset.nVar) * 2.2204460492503131E-16;
      b_st.site = &fg_emlrtRSI;
      if (i > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (idx = 0; idx < i; idx++) {
        i1 = qrmanager.jpvt.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &pc_emlrtBCI, &st);
        }
        qrmanager.jpvt[idx] = 1;
      }
      nDepIneq = i + 1;
      b_st.site = &fg_emlrtRSI;
      if ((i + 1 <= workingset.nActiveConstr) &&
          (workingset.nActiveConstr > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (idx = nDepIneq; idx <= nActiveConstr; idx++) {
        i1 = qrmanager.jpvt.size(0);
        if ((idx < 1) || (idx > i1)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &pc_emlrtBCI, &st);
        }
        qrmanager.jpvt[idx - 1] = 0;
      }
      nActiveConstr = workingset.nActiveConstr;
      b_st.site = &fg_emlrtRSI;
      if (workingset.nActiveConstr > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (TYPE = 0; TYPE < nActiveConstr; TYPE++) {
        b_st.site = &fg_emlrtRSI;
        if (nVar_tmp >= 1) {
          c_st.site = &ub_emlrtRSI;
          n_t = (ptrdiff_t)nVar_tmp;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &workingset.ATwset[workingset.ldA * TYPE], &incx_t,
                &qrmanager.QR[qrmanager.ldq * TYPE], &incy_t);
        }
      }
      b_st.site = &fg_emlrtRSI;
      if (workingset.nVar * workingset.nActiveConstr == 0) {
        qrmanager.mrows = workingset.nVar;
        qrmanager.ncols = workingset.nActiveConstr;
        qrmanager.minRowCol = 0;
      } else {
        qrmanager.usedPivoting = true;
        qrmanager.mrows = workingset.nVar;
        qrmanager.ncols = workingset.nActiveConstr;
        qrmanager.minRowCol =
            muIntScalarMin_sint32(workingset.nVar, workingset.nActiveConstr);
        c_st.site = &ec_emlrtRSI;
        internal::lapack::xgeqp3(c_st, qrmanager.QR, workingset.nVar,
                                 workingset.nActiveConstr, qrmanager.jpvt,
                                 qrmanager.tau);
      }
      nDepIneq = 0;
      for (idx = workingset.nActiveConstr; idx > nVar_tmp; idx--) {
        nDepIneq++;
        i1 = qrmanager.jpvt.size(0);
        if ((idx < 1) || (idx > i1)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &pc_emlrtBCI, &st);
        }
        i1 = memspace.workspace_int.size(0);
        if ((nDepIneq < 1) || (nDepIneq > i1)) {
          emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, i1, &pc_emlrtBCI, &st);
        }
        memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx - 1];
      }
      if (idx <= workingset.nVar) {
        boolean_T exitg1;
        nActiveConstr = idx + qrmanager.ldq * (idx - 1);
        exitg1 = false;
        while ((!exitg1) && (idx > i)) {
          i1 = qrmanager.QR.size(0) * qrmanager.QR.size(1);
          if ((nActiveConstr < 1) || (nActiveConstr > i1)) {
            emlrtDynamicBoundsCheckR2012b(nActiveConstr, 1, i1, &pc_emlrtBCI,
                                          &st);
          }
          if (muDoubleScalarAbs(qrmanager.QR[nActiveConstr - 1]) < tol) {
            nDepIneq++;
            i1 = qrmanager.jpvt.size(0);
            if ((idx < 1) || (idx > i1)) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &pc_emlrtBCI, &st);
            }
            i1 = memspace.workspace_int.size(0);
            if ((nDepIneq < 1) || (nDepIneq > i1)) {
              emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, i1, &pc_emlrtBCI, &st);
            }
            memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx - 1];
            idx--;
            nActiveConstr = (nActiveConstr - qrmanager.ldq) - 1;
          } else {
            exitg1 = true;
          }
        }
      }
      b_st.site = &fg_emlrtRSI;
      utils::countsort(b_st, memspace.workspace_int, nDepIneq,
                       memspace.workspace_sort, i + 1,
                       workingset.nActiveConstr);
      for (idx = nDepIneq; idx >= 1; idx--) {
        b_st.site = &fg_emlrtRSI;
        i = memspace.workspace_int.size(0);
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &pc_emlrtBCI, &b_st);
        }
        i = workingset.Wid.size(0);
        i1 = memspace.workspace_int[idx - 1];
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &kc_emlrtBCI, &b_st);
        }
        TYPE = workingset.Wid[i1 - 1];
        i = workingset.Wlocalidx.size(0);
        if (i1 > i) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &kc_emlrtBCI, &b_st);
        }
        i = workingset.Wid[i1 - 1];
        if ((i < 1) || (i > 6)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 6, &lc_emlrtBCI, &b_st);
        }
        i = workingset.isActiveConstr.size(0);
        i2 = (workingset.isActiveIdx[workingset.Wid[i1 - 1] - 1] +
              workingset.Wlocalidx[i1 - 1]) -
             1;
        if ((i2 < 1) || (i2 > i)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &kc_emlrtBCI, &b_st);
        }
        workingset.isActiveConstr[i2 - 1] = false;
        c_st.site = &dg_emlrtRSI;
        WorkingSet::moveConstraint_(c_st, workingset, workingset.nActiveConstr,
                                    i1);
        workingset.nActiveConstr--;
        if ((TYPE < 1) || (TYPE > 5)) {
          emlrtDynamicBoundsCheckR2012b(TYPE, 1, 5, &nc_emlrtBCI, &b_st);
        }
        workingset.nWConstr[TYPE - 1]--;
      }
    }
    st.site = &ag_emlrtRSI;
    overflow = feasibleX0ForWorkingSet(st, memspace.workspace_double,
                                       solution.xstar, workingset, qrmanager);
    guard1 = false;
    if (!overflow) {
      st.site = &ag_emlrtRSI;
      RemoveDependentIneq_(st, workingset, qrmanager, memspace);
      st.site = &ag_emlrtRSI;
      overflow = feasibleX0ForWorkingSet(st, memspace.workspace_double,
                                         solution.xstar, workingset, qrmanager);
      if (!overflow) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 &&
        (workingset.nWConstr[0] + workingset.nWConstr[1] == workingset.nVar)) {
      st.site = &ag_emlrtRSI;
      tol = WorkingSet::maxConstraintViolation(st, workingset, solution.xstar);
      if (tol > 1.0E-6) {
        solution.state = -2;
      }
    }
  } else {
    solution.state = -3;
    st.site = &ag_emlrtRSI;
    WorkingSet::removeAllIneqConstr(st, workingset);
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (PresolveWorkingSet.cpp)
