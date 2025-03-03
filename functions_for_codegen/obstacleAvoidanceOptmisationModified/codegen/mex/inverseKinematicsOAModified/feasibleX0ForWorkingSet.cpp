//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// feasibleX0ForWorkingSet.cpp
//
// Code generation for function 'feasibleX0ForWorkingSet'
//

// Include files
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xgeqrf.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo gg_emlrtRSI{
    1,                         // lineNo
    "feasibleX0ForWorkingSet", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/feasibleX0ForWorkingSet.p" // pathName
};

static emlrtRSInfo
    og_emlrtRSI{
        75,      // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    pg_emlrtRSI{
        92,           // lineNo
        "xgemm_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    qg_emlrtRSI{
        67,      // lineNo
        "xtrsm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xtrsm.m" // pathName
    };

static emlrtRSInfo sg_emlrtRSI{
    1,              // lineNo
    "computeTallQ", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "computeTallQ.p" // pathName
};

static emlrtBCInfo uc_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    1,                         // lineNo
    1,                         // colNo
    "",                        // aName
    "feasibleX0ForWorkingSet", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/feasibleX0ForWorkingSet.p", // pName
    0                                        // checkKind
};

static emlrtRTEInfo
    rd_emlrtRTEI{
        97,      // lineNo
        9,       // colNo
        "xgemm", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemm.m" // pName
    };

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
boolean_T feasibleX0ForWorkingSet(const emlrtStack &sp,
                                  array<real_T, 2U> &workspace,
                                  array<real_T, 1U> &xCurrent,
                                  d_struct_T &workingset, e_struct_T &qrmanager)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  array<real_T, 2U> B;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  int32_T mWConstr;
  int32_T nVar;
  char_T SIDE1;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  boolean_T nonDegenerateWset;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  mWConstr = workingset.nActiveConstr;
  nVar = workingset.nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    int32_T i;
    int32_T offsetQR;
    st.site = &gg_emlrtRSI;
    if (mWConstr > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (offsetQR = 0; offsetQR < mWConstr; offsetQR++) {
      i = workingset.bwset.size(0);
      if ((offsetQR + 1 < 1) || (offsetQR + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, i, &uc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = workspace.size(0);
      if (offsetQR + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, i, &uc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      alpha1 = workingset.bwset[offsetQR];
      workspace[offsetQR] = alpha1;
      i = workspace.size(1);
      if (i < 2) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &uc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = workingset.bwset.size(0);
      if (offsetQR + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, i, &uc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = workspace.size(0);
      if (offsetQR + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, i, &uc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[offsetQR + workspace.size(0)] = alpha1;
    }
    st.site = &gg_emlrtRSI;
    if ((nVar >= 1) && (mWConstr >= 1)) {
      b_st.site = &qc_emlrtRSI;
      alpha1 = -1.0;
      beta1 = 1.0;
      TRANSA = 'T';
      m_t = (ptrdiff_t)nVar;
      n_t = (ptrdiff_t)mWConstr;
      lda_t = (ptrdiff_t)workingset.ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alpha1, &(workingset.ATwset.data())[0],
            &lda_t, &(xCurrent.data())[0], &incx_t, &beta1,
            &(workspace.data())[0], &incy_t);
    }
    if (mWConstr >= nVar) {
      st.site = &gg_emlrtRSI;
      for (int32_T idx_col{0}; idx_col < nVar; idx_col++) {
        offsetQR = qrmanager.ldq * idx_col + 1;
        st.site = &gg_emlrtRSI;
        for (int32_T idx_row{0}; idx_row < mWConstr; idx_row++) {
          int32_T i1;
          int32_T i2;
          i = workingset.ATwset.size(0);
          i1 = (idx_col + workingset.ldA * idx_row) + 1;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &uc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
          i2 = idx_row + offsetQR;
          if ((i2 < 1) || (i2 > i)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, i, &uc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          qrmanager.QR[i2 - 1] = workingset.ATwset[i1 - 1];
        }
      }
      st.site = &gg_emlrtRSI;
      if (mWConstr * nVar == 0) {
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        qrmanager.minRowCol = 0;
      } else {
        qrmanager.usedPivoting = false;
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        b_st.site = &hg_emlrtRSI;
        for (offsetQR = 0; offsetQR < nVar; offsetQR++) {
          i = qrmanager.jpvt.size(0);
          if ((offsetQR + 1 < 1) || (offsetQR + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, i, &vc_emlrtBCI,
                                          &st);
          }
          qrmanager.jpvt[offsetQR] = offsetQR + 1;
        }
        qrmanager.minRowCol = muIntScalarMin_sint32(mWConstr, nVar);
        b_st.site = &hg_emlrtRSI;
        internal::lapack::xgeqrf(b_st, qrmanager.QR, mWConstr, nVar,
                                 qrmanager.tau);
      }
      st.site = &gg_emlrtRSI;
      b_st.site = &xc_emlrtRSI;
      QRManager::computeQ_(b_st, qrmanager, qrmanager.mrows);
      st.site = &gg_emlrtRSI;
      if ((nVar >= 1) && (mWConstr >= 1)) {
        b_st.site = &og_emlrtRSI;
        c_st.site = &pg_emlrtRSI;
        alpha1 = 1.0;
        B.set_size(&rd_emlrtRTEI, &c_st, workspace.size(0), workspace.size(1));
        offsetQR = workspace.size(0) * workspace.size(1);
        for (i = 0; i < offsetQR; i++) {
          B[i] = workspace[i];
        }
        beta1 = 0.0;
        TRANSA = 'N';
        TRANSA1 = 'T';
        m_t = (ptrdiff_t)nVar;
        n_t = (ptrdiff_t)2;
        incy_t = (ptrdiff_t)mWConstr;
        lda_t = (ptrdiff_t)qrmanager.ldq;
        incx_t = (ptrdiff_t)workspace.size(0);
        ldc_t = (ptrdiff_t)workspace.size(0);
        dgemm(&TRANSA1, &TRANSA, &m_t, &n_t, &incy_t, &alpha1,
              &(qrmanager.Q.data())[0], &lda_t, &(B.data())[0], &incx_t, &beta1,
              &(workspace.data())[0], &ldc_t);
      }
      st.site = &gg_emlrtRSI;
      if (nVar >= 1) {
        b_st.site = &qg_emlrtRSI;
        alpha1 = 1.0;
        TRANSA = 'N';
        TRANSA1 = 'N';
        UPLO1 = 'U';
        SIDE1 = 'L';
        m_t = (ptrdiff_t)nVar;
        n_t = (ptrdiff_t)2;
        lda_t = (ptrdiff_t)qrmanager.ldq;
        incx_t = (ptrdiff_t)workspace.size(0);
        dtrsm(&SIDE1, &UPLO1, &TRANSA1, &TRANSA, &m_t, &n_t, &alpha1,
              &(qrmanager.QR.data())[0], &lda_t, &(workspace.data())[0],
              &incx_t);
      }
    } else {
      st.site = &gg_emlrtRSI;
      QRManager::factorQR(st, qrmanager, workingset.ATwset, nVar, mWConstr,
                          workingset.ldA);
      st.site = &gg_emlrtRSI;
      b_st.site = &sg_emlrtRSI;
      QRManager::computeQ_(b_st, qrmanager, qrmanager.minRowCol);
      st.site = &gg_emlrtRSI;
      if (mWConstr >= 1) {
        b_st.site = &qg_emlrtRSI;
        alpha1 = 1.0;
        TRANSA = 'N';
        TRANSA1 = 'T';
        UPLO1 = 'U';
        SIDE1 = 'L';
        m_t = (ptrdiff_t)mWConstr;
        n_t = (ptrdiff_t)2;
        lda_t = (ptrdiff_t)qrmanager.ldq;
        incx_t = (ptrdiff_t)workspace.size(0);
        dtrsm(&SIDE1, &UPLO1, &TRANSA1, &TRANSA, &m_t, &n_t, &alpha1,
              &(qrmanager.QR.data())[0], &lda_t, &(workspace.data())[0],
              &incx_t);
      }
      st.site = &gg_emlrtRSI;
      if ((nVar >= 1) && (mWConstr >= 1)) {
        b_st.site = &og_emlrtRSI;
        c_st.site = &pg_emlrtRSI;
        alpha1 = 1.0;
        B.set_size(&rd_emlrtRTEI, &c_st, workspace.size(0), workspace.size(1));
        offsetQR = workspace.size(0) * workspace.size(1);
        for (i = 0; i < offsetQR; i++) {
          B[i] = workspace[i];
        }
        beta1 = 0.0;
        TRANSA = 'N';
        TRANSA1 = 'N';
        m_t = (ptrdiff_t)nVar;
        n_t = (ptrdiff_t)2;
        incy_t = (ptrdiff_t)mWConstr;
        lda_t = (ptrdiff_t)qrmanager.ldq;
        incx_t = (ptrdiff_t)workspace.size(0);
        ldc_t = (ptrdiff_t)workspace.size(0);
        dgemm(&TRANSA1, &TRANSA, &m_t, &n_t, &incy_t, &alpha1,
              &(qrmanager.Q.data())[0], &lda_t, &(B.data())[0], &incx_t, &beta1,
              &(workspace.data())[0], &ldc_t);
      }
    }
    st.site = &gg_emlrtRSI;
    if (nVar > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    offsetQR = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (offsetQR <= nVar - 1) {
        i = workspace.size(0);
        if ((offsetQR + 1 < 1) || (offsetQR + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, i, &uc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        alpha1 = workspace[offsetQR];
        if (muDoubleScalarIsInf(alpha1) || muDoubleScalarIsNaN(alpha1)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          i = workspace.size(1);
          if (i < 2) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i, &uc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = workspace.size(0);
          if ((offsetQR + 1 < 1) || (offsetQR + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(offsetQR + 1, 1, i, &uc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          alpha1 = workspace[offsetQR + workspace.size(0)];
          if (muDoubleScalarIsInf(alpha1) || muDoubleScalarIsNaN(alpha1)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            offsetQR++;
          }
        }
      } else {
        st.site = &gg_emlrtRSI;
        if (nVar >= 1) {
          b_st.site = &tg_emlrtRSI;
          alpha1 = 1.0;
          n_t = (ptrdiff_t)nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          daxpy(&n_t, &alpha1, &(xCurrent.data())[0], &incx_t,
                &(workspace.data())[0], &incy_t);
        }
        st.site = &gg_emlrtRSI;
        alpha1 = WorkingSet::maxConstraintViolation(st, workingset, workspace);
        st.site = &gg_emlrtRSI;
        beta1 = WorkingSet::maxConstraintViolation(st, workingset, workspace,
                                                   workspace.size(0) + 1);
        if ((alpha1 <= 2.2204460492503131E-16) || (alpha1 < beta1)) {
          st.site = &gg_emlrtRSI;
          if (nVar >= 1) {
            b_st.site = &ub_emlrtRSI;
            n_t = (ptrdiff_t)nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dcopy(&n_t, &(workspace.data())[0], &incx_t, &(xCurrent.data())[0],
                  &incy_t);
          }
        } else {
          st.site = &gg_emlrtRSI;
          if (nVar >= 1) {
            b_st.site = &ub_emlrtRSI;
            n_t = (ptrdiff_t)nVar;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dcopy(&n_t, &workspace[workspace.size(0)], &incx_t,
                  &(xCurrent.data())[0], &incy_t);
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return nonDegenerateWset;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (feasibleX0ForWorkingSet.cpp)
