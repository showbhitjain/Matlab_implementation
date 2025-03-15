//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// removeDependentLinearEq.cpp
//
// Code generation for function 'removeDependentLinearEq'
//

// Include files
#include "removeDependentLinearEq.h"
#include "ComputeNumDependentEq_.h"
#include "IndexOfDependentEq_.h"
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo cc_emlrtRSI{
    1,                         // lineNo
    "removeDependentLinearEq", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/removeDependentLinearEq.p" // pathName
};

static emlrtBCInfo nb_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    1,                         // lineNo
    1,                         // colNo
    "",                        // aName
    "removeDependentLinearEq", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/removeDependentLinearEq.p", // pName
    0                                      // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
int32_T removeDependentLinearEq(const emlrtStack &sp, const real_T Aeq_data[],
                                real_T beq_data[], const int32_T &beq_size,
                                const real_T bnd_data[], int32_T bnd_size,
                                array<int32_T, 1U> &idxArray,
                                h_struct_T &memspace, j_struct_T &b_TrialState,
                                d_struct_T &WorkingSet, e_struct_T &b_QRManager,
                                g_struct_T &QPObjective)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T mFixed;
  int32_T mLinEq;
  int32_T mTotalLinEq;
  int32_T nDepInd;
  int32_T nVar;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nVar = WorkingSet.nVar;
  mFixed = WorkingSet.sizes[0];
  mLinEq = beq_size;
  mTotalLinEq = beq_size + WorkingSet.sizes[0];
  nDepInd = 0;
  if (beq_size > 0) {
    int32_T colOffsetEqWrite;
    int32_T i;
    int32_T i1;
    int32_T idx;
    int32_T idxQR;
    st.site = &cc_emlrtRSI;
    if (WorkingSet.sizes[0] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (colOffsetEqWrite = 0; colOffsetEqWrite < mFixed; colOffsetEqWrite++) {
      i = WorkingSet.indexFixed.size(0);
      if ((colOffsetEqWrite + 1 < 1) || (colOffsetEqWrite + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(colOffsetEqWrite + 1, 1, i, &nb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idx = 1;
      idxQR = colOffsetEqWrite + 1;
      while (idx < WorkingSet.indexFixed[colOffsetEqWrite]) {
        i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
        if ((idxQR < 1) || (idxQR > i)) {
          emlrtDynamicBoundsCheckR2012b(idxQR, 1, i, &nb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        b_QRManager.QR[idxQR - 1] = 0.0;
        idx++;
        idxQR += b_QRManager.ldq;
      }
      i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
      if ((idxQR < 1) || (idxQR > i)) {
        emlrtDynamicBoundsCheckR2012b(idxQR, 1, i, &nb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_QRManager.QR[idxQR - 1] = 1.0;
      while (idx + 1 <= nVar) {
        idxQR += b_QRManager.ldq;
        i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
        if ((idxQR < 1) || (idxQR > i)) {
          emlrtDynamicBoundsCheckR2012b(idxQR, 1, i, &nb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        b_QRManager.QR[idxQR - 1] = 0.0;
        idx++;
      }
      i = WorkingSet.indexFixed[colOffsetEqWrite];
      if ((i < 1) || (i > bnd_size)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, bnd_size, &nb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i1 = WorkingSet.bwset.size[0];
      if ((colOffsetEqWrite + 1 < 1) || (colOffsetEqWrite + 1 > i1)) {
        emlrtDynamicBoundsCheckR2012b(colOffsetEqWrite + 1, 1, i1, &nb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      WorkingSet.bwset.data[colOffsetEqWrite] = bnd_data[i - 1];
    }
    st.site = &cc_emlrtRSI;
    i = beq_size;
    for (colOffsetEqWrite = 0; colOffsetEqWrite < mLinEq; colOffsetEqWrite++) {
      idxQR = (mFixed + colOffsetEqWrite) + 1;
      st.site = &cc_emlrtRSI;
      if (WorkingSet.nVar >= 1) {
        n_t = (ptrdiff_t)WorkingSet.nVar;
        incx_t = (ptrdiff_t)mLinEq;
        incy_t = (ptrdiff_t)b_QRManager.ldq;
        dcopy(&n_t, (real_T *)&Aeq_data[colOffsetEqWrite], &incx_t,
              &b_QRManager.QR[idxQR - 1], &incy_t);
      }
      if (colOffsetEqWrite + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(colOffsetEqWrite + 1, 1, i, &nb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i1 = WorkingSet.bwset.size[0];
      if ((idxQR < 1) || (idxQR > i1)) {
        emlrtDynamicBoundsCheckR2012b(idxQR, 1, i1, &nb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      WorkingSet.bwset.data[idxQR - 1] = beq_data[colOffsetEqWrite];
    }
    st.site = &cc_emlrtRSI;
    nDepInd = qpactiveset::initialize::ComputeNumDependentEq_(
        st, b_QRManager, WorkingSet.bwset.data, mTotalLinEq, WorkingSet.nVar);
    if (nDepInd > 0) {
      int32_T colOffsetEqRead;
      int32_T k;
      st.site = &cc_emlrtRSI;
      if (WorkingSet.sizes[0] > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (colOffsetEqWrite = 0; colOffsetEqWrite < mFixed;
           colOffsetEqWrite++) {
        i = WorkingSet.indexFixed.size(0);
        if ((colOffsetEqWrite + 1 < 1) || (colOffsetEqWrite + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(colOffsetEqWrite + 1, 1, i,
                                        &nb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        idx = 1;
        idxQR = b_QRManager.ldq * colOffsetEqWrite;
        while (idx < WorkingSet.indexFixed[colOffsetEqWrite]) {
          i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
          i1 = idx + idxQR;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &nb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          b_QRManager.QR[i1 - 1] = 0.0;
          idx++;
        }
        i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
        i1 = idx + idxQR;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &nb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        b_QRManager.QR[i1 - 1] = 1.0;
        for (idx++; idx <= nVar; idx++) {
          i = b_QRManager.QR.size(0) * b_QRManager.QR.size(1);
          i1 = idx + idxQR;
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &nb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          b_QRManager.QR[i1 - 1] = 0.0;
        }
      }
      st.site = &cc_emlrtRSI;
      for (colOffsetEqWrite = 0; colOffsetEqWrite < mLinEq;
           colOffsetEqWrite++) {
        st.site = &cc_emlrtRSI;
        if (nVar >= 1) {
          n_t = (ptrdiff_t)nVar;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &WorkingSet.Aeq[WorkingSet.ldA * colOffsetEqWrite],
                &incx_t,
                &b_QRManager.QR[b_QRManager.ldq * (mFixed + colOffsetEqWrite)],
                &incy_t);
        }
      }
      st.site = &cc_emlrtRSI;
      qpactiveset::initialize::IndexOfDependentEq_(
          st, idxArray, WorkingSet.sizes[0], nDepInd, b_QRManager,
          WorkingSet.nVar, mTotalLinEq);
      st.site = &cc_emlrtRSI;
      utils::countsort(st, idxArray, nDepInd, memspace.workspace_sort,
                       mTotalLinEq);
      i = idxArray.size(0);
      for (idx = nDepInd; idx >= 1; idx--) {
        if (idx > i) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &nb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i1 = idxArray[idx - 1];
        idxQR = (mLinEq + idx) - nDepInd;
        if (i1 < idxQR) {
          colOffsetEqWrite = WorkingSet.ldA * (i1 - 1);
          colOffsetEqRead = WorkingSet.ldA * (idxQR - 1);
          st.site = &cc_emlrtRSI;
          if (nVar > 2147483646) {
            b_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(b_st);
          }
          for (int32_T row{0}; row < nVar; row++) {
            int32_T i2;
            mTotalLinEq = WorkingSet.Aeq.size(0);
            k = (row + colOffsetEqRead) + 1;
            if ((k < 1) || (k > mTotalLinEq)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, mTotalLinEq, &nb_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            mTotalLinEq = WorkingSet.Aeq.size(0);
            i2 = (row + colOffsetEqWrite) + 1;
            if ((i2 < 1) || (i2 > mTotalLinEq)) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, mTotalLinEq, &nb_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            WorkingSet.Aeq[i2 - 1] = WorkingSet.Aeq[k - 1];
          }
          mTotalLinEq = beq_size;
          if ((idxQR < 1) || (idxQR > mTotalLinEq)) {
            emlrtDynamicBoundsCheckR2012b(idxQR, 1, mTotalLinEq, &nb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if ((i1 < 1) || (i1 > mTotalLinEq)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, mTotalLinEq, &nb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          beq_data[i1 - 1] = beq_data[idxQR - 1];
        }
      }
      idxQR = WorkingSet.sizes[1] - nDepInd;
      mTotalLinEq = WorkingSet.sizes[2];
      colOffsetEqWrite = WorkingSet.sizes[3];
      colOffsetEqRead = WorkingSet.sizes[4];
      WorkingSet.sizes[1] = idxQR;
      WorkingSet.sizesPhaseOne[0] = mFixed;
      WorkingSet.sizesPhaseOne[1] = idxQR;
      WorkingSet.sizesPhaseOne[2] = mTotalLinEq;
      WorkingSet.sizesPhaseOne[3] = colOffsetEqWrite + 1;
      WorkingSet.sizesPhaseOne[4] = colOffsetEqRead;
      WorkingSet.sizesRegularized[0] = mFixed;
      WorkingSet.sizesRegularized[1] = idxQR;
      WorkingSet.sizesRegularized[2] = mTotalLinEq;
      i = (colOffsetEqWrite + mTotalLinEq) + (idxQR << 1);
      WorkingSet.sizesRegularized[3] = i;
      WorkingSet.sizesRegularized[4] = colOffsetEqRead;
      WorkingSet.sizesRegPhaseOne[0] = mFixed;
      WorkingSet.sizesRegPhaseOne[1] = idxQR;
      WorkingSet.sizesRegPhaseOne[2] = mTotalLinEq;
      WorkingSet.sizesRegPhaseOne[3] = i + 1;
      WorkingSet.sizesRegPhaseOne[4] = colOffsetEqRead;
      WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
      WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
      WorkingSet.isActiveIdxRegPhaseOne[2] = idxQR;
      WorkingSet.isActiveIdxRegPhaseOne[3] = mTotalLinEq;
      WorkingSet.isActiveIdxRegPhaseOne[4] = colOffsetEqWrite;
      WorkingSet.isActiveIdxRegPhaseOne[5] = colOffsetEqRead;
      for (k = 0; k < 5; k++) {
        WorkingSet.sizesNormal[k] = WorkingSet.sizes[k];
        WorkingSet.isActiveIdxRegPhaseOne[k + 1] +=
            WorkingSet.isActiveIdxRegPhaseOne[k];
      }
      for (i1 = 0; i1 < 6; i1++) {
        WorkingSet.isActiveIdx[i1] = WorkingSet.isActiveIdxRegPhaseOne[i1];
        WorkingSet.isActiveIdxNormal[i1] =
            WorkingSet.isActiveIdxRegPhaseOne[i1];
      }
      WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
      WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
      WorkingSet.isActiveIdxRegPhaseOne[2] = idxQR;
      WorkingSet.isActiveIdxRegPhaseOne[3] = mTotalLinEq;
      WorkingSet.isActiveIdxRegPhaseOne[4] = colOffsetEqWrite + 1;
      WorkingSet.isActiveIdxRegPhaseOne[5] = colOffsetEqRead;
      for (k = 0; k < 5; k++) {
        WorkingSet.isActiveIdxRegPhaseOne[k + 1] +=
            WorkingSet.isActiveIdxRegPhaseOne[k];
      }
      for (i1 = 0; i1 < 6; i1++) {
        WorkingSet.isActiveIdxPhaseOne[i1] =
            WorkingSet.isActiveIdxRegPhaseOne[i1];
      }
      WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
      WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
      WorkingSet.isActiveIdxRegPhaseOne[2] = idxQR;
      WorkingSet.isActiveIdxRegPhaseOne[3] = mTotalLinEq;
      WorkingSet.isActiveIdxRegPhaseOne[4] = i;
      WorkingSet.isActiveIdxRegPhaseOne[5] = colOffsetEqRead;
      for (k = 0; k < 5; k++) {
        WorkingSet.isActiveIdxRegPhaseOne[k + 1] +=
            WorkingSet.isActiveIdxRegPhaseOne[k];
      }
      for (i1 = 0; i1 < 6; i1++) {
        WorkingSet.isActiveIdxRegularized[i1] =
            WorkingSet.isActiveIdxRegPhaseOne[i1];
      }
      WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
      WorkingSet.isActiveIdxRegPhaseOne[1] = mFixed;
      WorkingSet.isActiveIdxRegPhaseOne[2] = idxQR;
      WorkingSet.isActiveIdxRegPhaseOne[3] = mTotalLinEq;
      WorkingSet.isActiveIdxRegPhaseOne[4] = i + 1;
      WorkingSet.isActiveIdxRegPhaseOne[5] = colOffsetEqRead;
      for (k = 0; k < 5; k++) {
        WorkingSet.isActiveIdxRegPhaseOne[k + 1] +=
            WorkingSet.isActiveIdxRegPhaseOne[k];
      }
      idxQR = nDepInd << 1;
      WorkingSet.nVarMax -= idxQR;
      WorkingSet.mConstr -= nDepInd;
      WorkingSet.mConstrMax -= 3 * nDepInd;
      WorkingSet.mConstrOrig -= nDepInd;
      QPObjective.maxVar -= idxQR;
      b_TrialState.nVarMax -= idxQR;
      b_TrialState.mEq -= nDepInd;
      b_TrialState.iNonEq0 -= nDepInd;
    }
  }
  return nDepInd;
}

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (removeDependentLinearEq.cpp)
