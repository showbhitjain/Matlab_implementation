//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: compute_deltax.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 15:44:26
//

// Include Files
#include "compute_deltax.h"
#include "eml_int_forloop_overflow_check.h"
#include "factor.h"
#include "factor1.h"
#include "fullColLDL2_.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "partialColLDL3_.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "solve1.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xpotrf.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const array<double, 2U> &H
//                j_struct_T &solution
//                h_struct_T &memspace
//                const e_struct_T &qrmanager
//                f_struct_T &cholmanager
//                const g_struct_T &objective
//                boolean_T alwaysPositiveDef
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_deltax(const array<double, 2U> &H, j_struct_T &solution,
                    h_struct_T &memspace, const e_struct_T &qrmanager,
                    f_struct_T &cholmanager, const g_struct_T &objective,
                    boolean_T alwaysPositiveDef)
{
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,               // iFirst
      -1,               // iLast
      1,                // lineNo
      1,                // colNo
      "",               // aName
      "compute_deltax", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
      "compute_deltax.p", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo x_emlrtBCI{
      -1,                                    // iFirst
      -1,                                    // iLast
      1,                                     // lineNo
      1,                                     // colNo
      "",                                    // aName
      "computeProjectedHessian_regularized", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
      "+relaxed/computeProjectedHessian_regularized.p", // pName
      0                                                 // checkKind
  };
  int mNull;
  int nVar;
  nVar = qrmanager.mrows - 1;
  mNull = qrmanager.mrows - qrmanager.ncols;
  if (mNull <= 0) {
    if (qrmanager.mrows > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int nVars{0}; nVars <= nVar; nVars++) {
      int i;
      i = solution.searchDir.size(0);
      if ((nVars + 1 < 1) || (nVars + 1 > i)) {
        rtDynamicBoundsError(nVars + 1, 1, i, w_emlrtBCI);
      }
      solution.searchDir[nVars] = 0.0;
    }
  } else {
    int i;
    int nVars;
    if (qrmanager.mrows > 2147483646) {
      check_forloop_overflow_error();
    }
    for (nVars = 0; nVars <= nVar; nVars++) {
      i = objective.grad.size(0);
      if ((nVars + 1 < 1) || (nVars + 1 > i)) {
        rtDynamicBoundsError(nVars + 1, 1, i, w_emlrtBCI);
      }
      i = solution.searchDir.size(0);
      if (nVars + 1 > i) {
        rtDynamicBoundsError(nVars + 1, 1, i, w_emlrtBCI);
      }
      solution.searchDir[nVars] = -objective.grad[nVars];
    }
    if (qrmanager.ncols <= 0) {
      switch (objective.objtype) {
      case 5:
        break;
      case 3:
        if (alwaysPositiveDef) {
          CholManager::factor(cholmanager, H, qrmanager.mrows, qrmanager.mrows);
        } else {
          DynamicRegCholManager::factor(cholmanager, H, qrmanager.mrows,
                                        qrmanager.mrows);
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else if (alwaysPositiveDef) {
          CholManager::solve(cholmanager, solution.searchDir);
        } else {
          DynamicRegCholManager::solve(cholmanager, solution.searchDir);
        }
        break;
      default: {
        if (alwaysPositiveDef) {
          CholManager::factor(cholmanager, H, objective.nvar, objective.nvar);
          if (cholmanager.info != 0) {
            solution.state = -6;
          } else {
            double smax;
            int LD_diagOffset;
            int b;
            CholManager::solve(cholmanager, solution.searchDir);
            smax = 1.0 / objective.beta;
            LD_diagOffset = objective.nvar + 1;
            b = qrmanager.mrows;
            if ((LD_diagOffset <= b) && (b > 2147483646)) {
              check_forloop_overflow_error();
            }
            if (static_cast<int>((b - LD_diagOffset) + 1 < 400)) {
              for (int iy{LD_diagOffset}; iy <= b; iy++) {
                solution.searchDir[iy - 1] = smax * solution.searchDir[iy - 1];
              }
            } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

              for (int iy = LD_diagOffset; iy <= b; iy++) {
                solution.searchDir[iy - 1] = smax * solution.searchDir[iy - 1];
              }
            }
          }
        }
      } break;
      }
    } else {
      int nullStartIdx;
      nullStartIdx = qrmanager.ldq * qrmanager.ncols + 1;
      if (objective.objtype == 5) {
        if (mNull > 2147483646) {
          check_forloop_overflow_error();
        }
        i = qrmanager.Q.size(0) * qrmanager.Q.size(1);
        for (nVars = 0; nVars < mNull; nVars++) {
          int LD_diagOffset;
          int k;
          k = (nVar + qrmanager.ldq * (qrmanager.ncols + nVars)) + 1;
          if ((k < 1) || (k > i)) {
            rtDynamicBoundsError(k, 1, i, w_emlrtBCI);
          }
          LD_diagOffset = memspace.workspace_double.size(0) *
                          memspace.workspace_double.size(1);
          if (nVars + 1 > LD_diagOffset) {
            rtDynamicBoundsError(nVars + 1, 1, LD_diagOffset, w_emlrtBCI);
          }
          memspace.workspace_double[nVars] = -qrmanager.Q[k - 1];
        }
        internal::blas::xgemv(qrmanager.mrows, mNull, qrmanager.Q, nullStartIdx,
                              qrmanager.ldq, memspace.workspace_double,
                              solution.searchDir);
      } else {
        double smax;
        int LD_diagOffset;
        int LDimSizeP1;
        int k;
        if (objective.objtype == 3) {
          internal::blas::xgemm(qrmanager.mrows, mNull, qrmanager.mrows, H,
                                qrmanager.mrows, qrmanager.Q, nullStartIdx,
                                qrmanager.ldq, memspace.workspace_double,
                                memspace.workspace_double.size(0));
          internal::blas::xgemm(mNull, mNull, qrmanager.mrows, qrmanager.Q,
                                nullStartIdx, qrmanager.ldq,
                                memspace.workspace_double,
                                memspace.workspace_double.size(0),
                                cholmanager.FMat, cholmanager.ldm);
        } else if (alwaysPositiveDef) {
          LD_diagOffset = objective.nvar + 1;
          nVars = qrmanager.mrows;
          internal::blas::xgemm(objective.nvar, mNull, objective.nvar, H,
                                objective.nvar, qrmanager.Q, nullStartIdx,
                                qrmanager.ldq, memspace.workspace_double,
                                memspace.workspace_double.size(0));
          if (mNull > 2147483646) {
            check_forloop_overflow_error();
          }
          for (LDimSizeP1 = 0; LDimSizeP1 < mNull; LDimSizeP1++) {
            if ((LD_diagOffset <= nVars) && (nVars > 2147483646)) {
              check_forloop_overflow_error();
            }
            for (int idx_row{LD_diagOffset}; idx_row <= nVars; idx_row++) {
              i = qrmanager.Q.size(0);
              if ((idx_row < 1) || (idx_row > i)) {
                rtDynamicBoundsError(idx_row, 1, i, x_emlrtBCI);
              }
              i = qrmanager.Q.size(1);
              k = (LDimSizeP1 + qrmanager.ncols) + 1;
              if ((k < 1) || (k > i)) {
                rtDynamicBoundsError(k, 1, i, x_emlrtBCI);
              }
              i = memspace.workspace_double.size(0);
              if (idx_row > i) {
                rtDynamicBoundsError(idx_row, 1, i, x_emlrtBCI);
              }
              i = memspace.workspace_double.size(1);
              if (LDimSizeP1 + 1 > i) {
                rtDynamicBoundsError(LDimSizeP1 + 1, 1, i, x_emlrtBCI);
              }
              memspace.workspace_double
                  [(idx_row + memspace.workspace_double.size(0) * LDimSizeP1) -
                   1] =
                  objective.beta *
                  qrmanager.Q[(idx_row + qrmanager.Q.size(0) * (k - 1)) - 1];
            }
          }
          internal::blas::xgemm(mNull, mNull, qrmanager.mrows, qrmanager.Q,
                                nullStartIdx, qrmanager.ldq,
                                memspace.workspace_double,
                                memspace.workspace_double.size(0),
                                cholmanager.FMat, cholmanager.ldm);
        }
        if (alwaysPositiveDef) {
          cholmanager.ndims = mNull;
          cholmanager.info = internal::lapack::xpotrf(mNull, cholmanager.FMat,
                                                      cholmanager.ldm);
        } else {
          LDimSizeP1 = cholmanager.ldm + 1;
          cholmanager.ndims = mNull;
          LD_diagOffset = cholmanager.ldm + 1;
          nVars = 1;
          if (mNull > 1) {
            smax = std::abs(cholmanager.FMat[0]);
            if (mNull > 2147483646) {
              check_forloop_overflow_error();
            }
            for (k = 2; k <= mNull; k++) {
              double s;
              s = std::abs(cholmanager.FMat[(k - 1) * LD_diagOffset]);
              if (s > smax) {
                nVars = k;
                smax = s;
              }
            }
          }
          i = cholmanager.FMat.size(0) * cholmanager.FMat.size(1);
          k = (nVars + cholmanager.ldm * (nVars - 1)) - 1;
          if ((k + 1 < 1) || (k + 1 > i)) {
            rtDynamicBoundsError(k + 1, 1, i, s_emlrtBCI);
          }
          cholmanager.regTol_ = std::fmax(
              std::abs(cholmanager.FMat[k]) * 2.2204460492503131E-16, 0.0);
          if ((cholmanager.FMat.size(0) * cholmanager.FMat.size(1) > 16384) &&
              (mNull > 128)) {
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < mNull)) {
              LD_diagOffset = LDimSizeP1 * k + 1;
              nVars = mNull - k;
              if (k + 48 <= mNull) {
                DynamicRegCholManager::partialColLDL3_(cholmanager,
                                                       LD_diagOffset, nVars);
                k += 48;
              } else {
                DynamicRegCholManager::fullColLDL2_(cholmanager, LD_diagOffset,
                                                    nVars);
                exitg1 = true;
              }
            }
          } else {
            DynamicRegCholManager::fullColLDL2_(cholmanager, mNull);
          }
          if (cholmanager.ConvexCheck) {
            nVars = 0;
            int exitg2;
            do {
              exitg2 = 0;
              if (nVars <= mNull - 1) {
                i = cholmanager.FMat.size(0) * cholmanager.FMat.size(1);
                k = (nVars + cholmanager.ldm * nVars) + 1;
                if ((k < 1) || (k > i)) {
                  rtDynamicBoundsError(k, 1, i, s_emlrtBCI);
                }
                if (cholmanager.FMat[k - 1] <= 0.0) {
                  cholmanager.info = -(nVars + 1);
                  exitg2 = 1;
                } else {
                  nVars++;
                }
              } else {
                cholmanager.ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else {
          int b;
          LDimSizeP1 = qrmanager.ldq;
          if (qrmanager.mrows != 0) {
            if (mNull > 2147483646) {
              check_forloop_overflow_error();
            }
            if (static_cast<int>(mNull < 400)) {
              for (int iy{0}; iy < mNull; iy++) {
                memspace.workspace_double[iy] = 0.0;
              }
            } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

              for (int iy = 0; iy < mNull; iy++) {
                memspace.workspace_double[iy] = 0.0;
              }
            }
            LD_diagOffset = 0;
            b = nullStartIdx + qrmanager.ldq * (mNull - 1);
            if ((nullStartIdx <= b) && (b > MAX_int32_T - qrmanager.ldq)) {
              check_forloop_overflow_error();
            }
            for (int idx_row{nullStartIdx};
                 LDimSizeP1 < 0 ? idx_row >= b : idx_row <= b;
                 idx_row += LDimSizeP1) {
              smax = 0.0;
              nVars = idx_row + nVar;
              if ((idx_row <= nVars) && (nVars > 2147483646)) {
                check_forloop_overflow_error();
              }
              for (k = idx_row; k <= nVars; k++) {
                smax += qrmanager.Q[k - 1] * objective.grad[k - idx_row];
              }
              memspace.workspace_double[LD_diagOffset] =
                  memspace.workspace_double[LD_diagOffset] - smax;
              LD_diagOffset++;
            }
          }
          if (alwaysPositiveDef) {
            LDimSizeP1 = cholmanager.ndims;
            if (cholmanager.ndims != 0) {
              if (cholmanager.ndims > 2147483646) {
                check_forloop_overflow_error();
              }
              for (int idx_row{0}; idx_row < LDimSizeP1; idx_row++) {
                LD_diagOffset = idx_row * cholmanager.ldm;
                smax = memspace.workspace_double[idx_row];
                if (idx_row > 2147483646) {
                  check_forloop_overflow_error();
                }
                for (k = 0; k < idx_row; k++) {
                  smax -= cholmanager.FMat[LD_diagOffset + k] *
                          memspace.workspace_double[k];
                }
                memspace.workspace_double[idx_row] =
                    smax / cholmanager.FMat[LD_diagOffset + idx_row];
              }
            }
            LDimSizeP1 = cholmanager.ndims;
            if (cholmanager.ndims != 0) {
              for (int idx_row{LDimSizeP1}; idx_row >= 1; idx_row--) {
                LD_diagOffset = (idx_row + (idx_row - 1) * cholmanager.ldm) - 1;
                memspace.workspace_double[idx_row - 1] =
                    memspace.workspace_double[idx_row - 1] /
                    cholmanager.FMat[LD_diagOffset];
                for (k = 0; k <= idx_row - 2; k++) {
                  nVars = (idx_row - k) - 2;
                  memspace.workspace_double[nVars] =
                      memspace.workspace_double[nVars] -
                      memspace.workspace_double[idx_row - 1] *
                          cholmanager.FMat[(LD_diagOffset - k) - 1];
                }
              }
            }
          } else {
            LDimSizeP1 = cholmanager.ndims - 1;
            if (cholmanager.ndims != 0) {
              if (cholmanager.ndims > 2147483646) {
                check_forloop_overflow_error();
              }
              for (int idx_row{0}; idx_row <= LDimSizeP1; idx_row++) {
                LD_diagOffset = idx_row + idx_row * cholmanager.ldm;
                b = LDimSizeP1 - idx_row;
                if (b > 2147483646) {
                  check_forloop_overflow_error();
                }
                for (k = 0; k < b; k++) {
                  nVars = (idx_row + k) + 1;
                  memspace.workspace_double[nVars] =
                      memspace.workspace_double[nVars] -
                      memspace.workspace_double[idx_row] *
                          cholmanager.FMat[(LD_diagOffset + k) + 1];
                }
              }
            }
            b = cholmanager.ndims;
            if (cholmanager.ndims > 2147483646) {
              check_forloop_overflow_error();
            }
            for (nVars = 0; nVars < b; nVars++) {
              i = memspace.workspace_double.size(0) *
                  memspace.workspace_double.size(1);
              if ((nVars + 1 < 1) || (nVars + 1 > i)) {
                rtDynamicBoundsError(nVars + 1, 1, i, t_emlrtBCI);
              }
              k = cholmanager.FMat.size(0) * cholmanager.FMat.size(1);
              LD_diagOffset = (nVars + cholmanager.ldm * nVars) + 1;
              if ((LD_diagOffset < 1) || (LD_diagOffset > k)) {
                rtDynamicBoundsError(LD_diagOffset, 1, k, t_emlrtBCI);
              }
              if (nVars + 1 > i) {
                rtDynamicBoundsError(nVars + 1, 1, i, t_emlrtBCI);
              }
              memspace.workspace_double[nVars] =
                  memspace.workspace_double[nVars] /
                  cholmanager.FMat[LD_diagOffset - 1];
            }
            LDimSizeP1 = cholmanager.ndims;
            if (cholmanager.ndims != 0) {
              for (int idx_row{LDimSizeP1}; idx_row >= 1; idx_row--) {
                LD_diagOffset = (idx_row - 1) * cholmanager.ldm;
                smax = memspace.workspace_double[idx_row - 1];
                i = idx_row + 1;
                for (k = LDimSizeP1; k >= i; k--) {
                  smax -= cholmanager.FMat[(LD_diagOffset + k) - 1] *
                          memspace.workspace_double[k - 1];
                }
                memspace.workspace_double[idx_row - 1] = smax;
              }
            }
          }
          internal::blas::xgemv(qrmanager.mrows, mNull, qrmanager.Q,
                                nullStartIdx, qrmanager.ldq,
                                memspace.workspace_double, solution.searchDir);
        }
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for compute_deltax.cpp
//
// [EOF]
//
