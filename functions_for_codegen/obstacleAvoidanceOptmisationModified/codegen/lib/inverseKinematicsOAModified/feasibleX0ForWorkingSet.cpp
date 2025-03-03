//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleX0ForWorkingSet.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 15:44:26
//

// Include Files
#include "feasibleX0ForWorkingSet.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "factorQR.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xgemm.h"
#include "xzgeqp3.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : array<double, 2U> &workspace
//                array<double, 1U> &xCurrent
//                d_struct_T &workingset
//                e_struct_T &qrmanager
// Return Type  : boolean_T
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
boolean_T feasibleX0ForWorkingSet(array<double, 2U> &workspace,
                                  array<double, 1U> &xCurrent,
                                  d_struct_T &workingset, e_struct_T &qrmanager)
{
  static rtBoundsCheckInfo w_emlrtBCI{
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
  array<double, 2U> A;
  int mWConstr;
  int nVar;
  boolean_T nonDegenerateWset;
  mWConstr = workingset.nActiveConstr;
  nVar = workingset.nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    double c;
    int b;
    int iAcol;
    int ia;
    int iy;
    int jBcol;
    int offsetQR;
    int w;
    if (mWConstr > 2147483646) {
      check_forloop_overflow_error();
    }
    for (iAcol = 0; iAcol < mWConstr; iAcol++) {
      w = workingset.bwset.size(0);
      if ((iAcol + 1 < 1) || (iAcol + 1 > w)) {
        rtDynamicBoundsError(iAcol + 1, 1, w, w_emlrtBCI);
      }
      w = workspace.size(0);
      if (iAcol + 1 > w) {
        rtDynamicBoundsError(iAcol + 1, 1, w, w_emlrtBCI);
      }
      c = workingset.bwset[iAcol];
      workspace[iAcol] = c;
      w = workspace.size(1);
      if (w < 2) {
        rtDynamicBoundsError(2, 1, w, w_emlrtBCI);
      }
      w = workingset.bwset.size(0);
      if (iAcol + 1 > w) {
        rtDynamicBoundsError(iAcol + 1, 1, w, w_emlrtBCI);
      }
      w = workspace.size(0);
      if (iAcol + 1 > w) {
        rtDynamicBoundsError(iAcol + 1, 1, w, w_emlrtBCI);
      }
      workspace[iAcol + workspace.size(0)] = c;
    }
    iAcol = workingset.ldA;
    if ((nVar != 0) && (mWConstr != 0)) {
      boolean_T overflow;
      iy = 0;
      offsetQR = workingset.ldA * (mWConstr - 1) + 1;
      if ((workingset.ldA == 0) || ((workingset.ldA > 0) && (offsetQR < 1)) ||
          ((workingset.ldA < 0) && (offsetQR > 1))) {
        overflow = false;
      } else if (workingset.ldA > 0) {
        overflow = (offsetQR > MAX_int32_T - workingset.ldA);
      } else {
        overflow = (offsetQR < MIN_int32_T - workingset.ldA);
      }
      if (workingset.ldA == 0) {
        m_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
      }
      if (overflow) {
        check_forloop_overflow_error();
      }
      for (jBcol = 1; iAcol < 0 ? jBcol >= offsetQR : jBcol <= offsetQR;
           jBcol += iAcol) {
        c = 0.0;
        b = (jBcol + nVar) - 1;
        if ((jBcol <= b) && (b > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (ia = jBcol; ia <= b; ia++) {
          c += workingset.ATwset[ia - 1] * xCurrent[ia - jBcol];
        }
        workspace[iy] = workspace[iy] - c;
        iy++;
      }
    }
    if (mWConstr >= nVar) {
      int ldq;
      int ldw;
      for (iAcol = 0; iAcol < nVar; iAcol++) {
        offsetQR = qrmanager.ldq * iAcol + 1;
        for (jBcol = 0; jBcol < mWConstr; jBcol++) {
          w = workingset.ATwset.size(0);
          ia = (iAcol + workingset.ldA * jBcol) + 1;
          if ((ia < 1) || (ia > w)) {
            rtDynamicBoundsError(ia, 1, w, w_emlrtBCI);
          }
          w = qrmanager.QR.size(0) * qrmanager.QR.size(1);
          iy = jBcol + offsetQR;
          if ((iy < 1) || (iy > w)) {
            rtDynamicBoundsError(iy, 1, w, w_emlrtBCI);
          }
          qrmanager.QR[iy - 1] = workingset.ATwset[ia - 1];
        }
      }
      if (mWConstr * nVar == 0) {
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        qrmanager.minRowCol = 0;
      } else {
        qrmanager.usedPivoting = false;
        qrmanager.mrows = mWConstr;
        qrmanager.ncols = nVar;
        for (iAcol = 0; iAcol < nVar; iAcol++) {
          w = qrmanager.jpvt.size(0);
          if ((iAcol + 1 < 1) || (iAcol + 1 > w)) {
            rtDynamicBoundsError(iAcol + 1, 1, w, m_emlrtBCI);
          }
          qrmanager.jpvt[iAcol] = iAcol + 1;
        }
        if (mWConstr <= nVar) {
          offsetQR = mWConstr;
        } else {
          offsetQR = nVar;
        }
        qrmanager.minRowCol = offsetQR;
        A.set_size(qrmanager.QR.size(0), qrmanager.QR.size(1));
        iAcol = qrmanager.QR.size(0) * qrmanager.QR.size(1);
        if (static_cast<int>(iAcol < 400)) {
          for (int b_workspace{0}; b_workspace < iAcol; b_workspace++) {
            A[b_workspace] = qrmanager.QR[b_workspace];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

          for (int b_workspace = 0; b_workspace < iAcol; b_workspace++) {
            A[b_workspace] = qrmanager.QR[b_workspace];
          }
        }
        iAcol = qrmanager.QR.size(0);
        iy = qrmanager.QR.size(1);
        if (iAcol <= iy) {
          iy = iAcol;
        }
        qrmanager.tau.set_size(iy);
        if (static_cast<int>(iy < 400)) {
          for (int b_workspace{0}; b_workspace < iy; b_workspace++) {
            qrmanager.tau[b_workspace] = 0.0;
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

          for (int b_workspace = 0; b_workspace < iy; b_workspace++) {
            qrmanager.tau[b_workspace] = 0.0;
          }
        }
        if (offsetQR >= 1) {
          internal::reflapack::qrf(A, mWConstr, nVar, offsetQR, qrmanager.tau);
        }
        qrmanager.QR.set_size(A.size(0), A.size(1));
        iAcol = A.size(0) * A.size(1);
        if (static_cast<int>(iAcol < 400)) {
          for (int b_workspace{0}; b_workspace < iAcol; b_workspace++) {
            qrmanager.QR[b_workspace] = A[b_workspace];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

          for (int b_workspace = 0; b_workspace < iAcol; b_workspace++) {
            qrmanager.QR[b_workspace] = A[b_workspace];
          }
        }
      }
      QRManager::computeQ_(qrmanager, qrmanager.mrows);
      ldq = qrmanager.ldq;
      ldw = workspace.size(0);
      A.set_size(workspace.size(0), workspace.size(1));
      iAcol = workspace.size(0) * workspace.size(1);
      if (static_cast<int>(iAcol < 400)) {
        for (int b_workspace{0}; b_workspace < iAcol; b_workspace++) {
          A[b_workspace] = workspace[b_workspace];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

        for (int b_workspace = 0; b_workspace < iAcol; b_workspace++) {
          A[b_workspace] = workspace[b_workspace];
        }
      }
      if (nVar != 0) {
        if (workspace.size(0) > MAX_int32_T - workspace.size(0)) {
          check_forloop_overflow_error();
        }
        for (ia = 0; ldw < 0 ? ia >= ldw : ia <= ldw; ia += ldw) {
          iy = ia + 1;
          b = ia + nVar;
          if ((ia + 1 <= b) && (b > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (jBcol = iy; jBcol <= b; jBcol++) {
            workspace[jBcol - 1] = 0.0;
          }
        }
        iAcol = -1;
        if (workspace.size(0) > MAX_int32_T - workspace.size(0)) {
          check_forloop_overflow_error();
        }
        for (ia = 0; ldw < 0 ? ia >= ldw : ia <= ldw; ia += ldw) {
          offsetQR = -1;
          iy = ia + 1;
          b = ia + nVar;
          if ((ia + 1 <= b) && (b > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (jBcol = iy; jBcol <= b; jBcol++) {
            c = 0.0;
            for (w = 0; w < mWConstr; w++) {
              c += qrmanager.Q[(w + offsetQR) + 1] * A[(w + iAcol) + 1];
            }
            workspace[jBcol - 1] = workspace[jBcol - 1] + c;
            offsetQR += ldq;
          }
          iAcol += ldw;
        }
      }
      for (b = 0; b < 2; b++) {
        jBcol = ldw * b - 1;
        for (int k{nVar}; k >= 1; k--) {
          iy = ldq * (k - 1) - 1;
          w = k + jBcol;
          c = workspace[w];
          if (c != 0.0) {
            workspace[w] = c / qrmanager.QR[k + iy];
            for (int i{0}; i <= k - 2; i++) {
              ia = (i + jBcol) + 1;
              workspace[ia] =
                  workspace[ia] - workspace[w] * qrmanager.QR[(i + iy) + 1];
            }
          }
        }
      }
    } else {
      QRManager::factorQR(qrmanager, workingset.ATwset, nVar, mWConstr,
                          workingset.ldA);
      QRManager::computeQ_(qrmanager, qrmanager.minRowCol);
      for (b = 0; b < 2; b++) {
        jBcol = workspace.size(0) * b;
        for (int i{0}; i < mWConstr; i++) {
          iAcol = qrmanager.ldq * i;
          offsetQR = i + jBcol;
          c = workspace[offsetQR];
          if (i > 2147483646) {
            check_forloop_overflow_error();
          }
          for (int k{0}; k < i; k++) {
            c -= qrmanager.QR[k + iAcol] * workspace[k + jBcol];
          }
          workspace[offsetQR] = c / qrmanager.QR[i + iAcol];
        }
      }
      A.set_size(workspace.size(0), workspace.size(1));
      iAcol = workspace.size(0) * workspace.size(1);
      if (static_cast<int>(iAcol < 400)) {
        for (int b_workspace{0}; b_workspace < iAcol; b_workspace++) {
          A[b_workspace] = workspace[b_workspace];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

        for (int b_workspace = 0; b_workspace < iAcol; b_workspace++) {
          A[b_workspace] = workspace[b_workspace];
        }
      }
      internal::blas::xgemm(nVar, mWConstr, qrmanager.Q, qrmanager.ldq, A,
                            workspace.size(0), workspace, workspace.size(0));
    }
    if (nVar > 2147483646) {
      check_forloop_overflow_error();
    }
    iAcol = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (iAcol <= nVar - 1) {
        w = workspace.size(0);
        if ((iAcol + 1 < 1) || (iAcol + 1 > w)) {
          rtDynamicBoundsError(iAcol + 1, 1, w, w_emlrtBCI);
        }
        c = workspace[iAcol];
        if (std::isinf(c) || std::isnan(c)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          w = workspace.size(1);
          if (w < 2) {
            rtDynamicBoundsError(2, 1, w, w_emlrtBCI);
          }
          c = workspace[iAcol + workspace.size(0)];
          if (std::isinf(c) || std::isnan(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            iAcol++;
          }
        }
      } else {
        double constrViolation_basicX;
        if (nVar >= 1) {
          iAcol = nVar - 1;
          if (static_cast<int>(nVar < 400)) {
            for (int b_workspace{0}; b_workspace <= iAcol; b_workspace++) {
              workspace[b_workspace] =
                  workspace[b_workspace] + xCurrent[b_workspace];
            }
          } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

            for (int b_workspace = 0; b_workspace <= iAcol; b_workspace++) {
              workspace[b_workspace] =
                  workspace[b_workspace] + xCurrent[b_workspace];
            }
          }
        }
        c = WorkingSet::maxConstraintViolation(workingset, workspace);
        constrViolation_basicX = WorkingSet::maxConstraintViolation(
            workingset, workspace, workspace.size(0) + 1);
        if ((c <= 2.2204460492503131E-16) || (c < constrViolation_basicX)) {
          if (static_cast<int>(nVar < 400)) {
            for (int b_workspace{0}; b_workspace < nVar; b_workspace++) {
              xCurrent[b_workspace] = workspace[b_workspace];
            }
          } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

            for (int b_workspace = 0; b_workspace < nVar; b_workspace++) {
              xCurrent[b_workspace] = workspace[b_workspace];
            }
          }
        } else if (static_cast<int>(nVar < 400)) {
          for (int b_workspace{0}; b_workspace < nVar; b_workspace++) {
            xCurrent[b_workspace] = workspace[workspace.size(0) + b_workspace];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

          for (int b_workspace = 0; b_workspace < nVar; b_workspace++) {
            xCurrent[b_workspace] = workspace[workspace.size(0) + b_workspace];
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return nonDegenerateWset;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for feasibleX0ForWorkingSet.cpp
//
// [EOF]
//
