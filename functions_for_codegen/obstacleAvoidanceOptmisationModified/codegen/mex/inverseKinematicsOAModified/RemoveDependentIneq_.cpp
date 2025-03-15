//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// RemoveDependentIneq_.cpp
//
// Code generation for function 'RemoveDependentIneq_'
//

// Include files
#include "RemoveDependentIneq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void RemoveDependentIneq_(const emlrtStack &sp, d_struct_T &workingset,
                          e_struct_T &qrmanager, h_struct_T &memspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T nActiveConstr_tmp;
  int32_T nFixedConstr;
  int32_T nVar;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nActiveConstr_tmp = workingset.nActiveConstr;
  nFixedConstr = workingset.nWConstr[0] + workingset.nWConstr[1];
  nVar = workingset.nVar;
  if ((workingset.nWConstr[2] + workingset.nWConstr[3]) +
          workingset.nWConstr[4] >
      0) {
    real_T tol;
    int32_T i;
    int32_T idx;
    int32_T idxDiag;
    int32_T nDepIneq;
    tol =
        1000.0 * static_cast<real_T>(workingset.nVar) * 2.2204460492503131E-16;
    st.site = &gg_emlrtRSI;
    if (nFixedConstr > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (idx = 0; idx < nFixedConstr; idx++) {
      i = qrmanager.jpvt.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &pc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      qrmanager.jpvt[idx] = 1;
    }
    idxDiag = nFixedConstr + 1;
    st.site = &gg_emlrtRSI;
    if ((nFixedConstr + 1 <= workingset.nActiveConstr) &&
        (workingset.nActiveConstr > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (idx = idxDiag; idx <= nActiveConstr_tmp; idx++) {
      i = qrmanager.jpvt.size(0);
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &pc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      qrmanager.jpvt[idx - 1] = 0;
    }
    st.site = &gg_emlrtRSI;
    if (workingset.nActiveConstr > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (idxDiag = 0; idxDiag < nActiveConstr_tmp; idxDiag++) {
      st.site = &gg_emlrtRSI;
      if (nVar >= 1) {
        n_t = (ptrdiff_t)nVar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &workingset.ATwset[workingset.ldA * idxDiag], &incx_t,
              &qrmanager.QR[qrmanager.ldq * idxDiag], &incy_t);
      }
    }
    st.site = &gg_emlrtRSI;
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
      b_st.site = &ec_emlrtRSI;
      internal::lapack::xgeqp3(b_st, qrmanager.QR, workingset.nVar,
                               workingset.nActiveConstr, qrmanager.jpvt,
                               qrmanager.tau);
    }
    nDepIneq = 0;
    for (idx = workingset.nActiveConstr; idx > nVar; idx--) {
      nDepIneq++;
      i = qrmanager.jpvt.size(0);
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &pc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = memspace.workspace_int.size(0);
      if ((nDepIneq < 1) || (nDepIneq > i)) {
        emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, i, &pc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx - 1];
    }
    if (idx <= workingset.nVar) {
      boolean_T exitg1;
      idxDiag = idx + qrmanager.ldq * (idx - 1);
      exitg1 = false;
      while ((!exitg1) && (idx > nFixedConstr)) {
        i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
        if ((idxDiag < 1) || (idxDiag > i)) {
          emlrtDynamicBoundsCheckR2012b(idxDiag, 1, i, &pc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if (muDoubleScalarAbs(qrmanager.QR[idxDiag - 1]) < tol) {
          nDepIneq++;
          i = qrmanager.jpvt.size(0);
          if ((idx < 1) || (idx > i)) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, i, &pc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = memspace.workspace_int.size(0);
          if ((nDepIneq < 1) || (nDepIneq > i)) {
            emlrtDynamicBoundsCheckR2012b(nDepIneq, 1, i, &pc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          memspace.workspace_int[nDepIneq - 1] = qrmanager.jpvt[idx - 1];
          idx--;
          idxDiag = (idxDiag - qrmanager.ldq) - 1;
        } else {
          exitg1 = true;
        }
      }
    }
    st.site = &gg_emlrtRSI;
    utils::countsort(st, memspace.workspace_int, nDepIneq,
                     memspace.workspace_sort, nFixedConstr + 1,
                     workingset.nActiveConstr);
    for (idx = nDepIneq; idx >= 1; idx--) {
      st.site = &gg_emlrtRSI;
      i = memspace.workspace_int.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &pc_emlrtBCI, &st);
      }
      i = workingset.Wid.size[0];
      idxDiag = memspace.workspace_int[idx - 1];
      if ((idxDiag < 1) || (idxDiag > i)) {
        emlrtDynamicBoundsCheckR2012b(idxDiag, 1, i, &kc_emlrtBCI, &st);
      }
      nActiveConstr_tmp = workingset.Wid.data[idxDiag - 1];
      i = workingset.Wlocalidx.size[0];
      if (idxDiag > i) {
        emlrtDynamicBoundsCheckR2012b(idxDiag, 1, i, &kc_emlrtBCI, &st);
      }
      if ((nActiveConstr_tmp < 1) || (nActiveConstr_tmp > 6)) {
        emlrtDynamicBoundsCheckR2012b(nActiveConstr_tmp, 1, 6, &lc_emlrtBCI,
                                      &st);
      }
      i = workingset.isActiveConstr.size[0];
      nVar = (workingset.isActiveIdx[nActiveConstr_tmp - 1] +
              workingset.Wlocalidx.data[idxDiag - 1]) -
             1;
      if ((nVar < 1) || (nVar > i)) {
        emlrtDynamicBoundsCheckR2012b(nVar, 1, i, &kc_emlrtBCI, &st);
      }
      workingset.isActiveConstr.data[nVar - 1] = false;
      b_st.site = &eg_emlrtRSI;
      WorkingSet::moveConstraint_(b_st, workingset, workingset.nActiveConstr,
                                  idxDiag);
      workingset.nActiveConstr--;
      if ((nActiveConstr_tmp < 1) || (nActiveConstr_tmp > 5)) {
        emlrtDynamicBoundsCheckR2012b(nActiveConstr_tmp, 1, 5, &nc_emlrtBCI,
                                      &st);
      }
      workingset.nWConstr[nActiveConstr_tmp - 1]--;
    }
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (RemoveDependentIneq_.cpp)
