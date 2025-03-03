//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleratiotest.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "feasibleratiotest.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xnrm2.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const array<double, 1U> &solution_xstar
//                const array<double, 1U> &solution_searchDir
//                array<double, 2U> &workspace
//                int workingset_nVar
//                int workingset_ldA
//                const array<double, 1U> &workingset_Aineq
//                const array<double, 1U> &workingset_bineq
//                const array<double, 1U> &workingset_lb
//                const array<double, 1U> &workingset_ub
//                const array<int, 1U> &workingset_indexLB
//                const array<int, 1U> &workingset_indexUB
//                const int workingset_sizes[5]
//                const int workingset_isActiveIdx[6]
//                const array<boolean_T, 1U> &workingset_isActiveConstr
//                const int workingset_nWConstr[5]
//                boolean_T isPhaseOne
//                boolean_T &newBlocking
//                int &constrType
//                int &constrIdx
// Return Type  : double
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
double feasibleratiotest(const array<double, 1U> &solution_xstar,
                         const array<double, 1U> &solution_searchDir,
                         array<double, 2U> &workspace, int workingset_nVar,
                         int workingset_ldA,
                         const array<double, 1U> &workingset_Aineq,
                         const array<double, 1U> &workingset_bineq,
                         const array<double, 1U> &workingset_lb,
                         const array<double, 1U> &workingset_ub,
                         const array<int, 1U> &workingset_indexLB,
                         const array<int, 1U> &workingset_indexUB,
                         const int workingset_sizes[5],
                         const int workingset_isActiveIdx[6],
                         const array<boolean_T, 1U> &workingset_isActiveConstr,
                         const int workingset_nWConstr[5], boolean_T isPhaseOne,
                         boolean_T &newBlocking, int &constrType,
                         int &constrIdx)
{
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,                  // iFirst
      -1,                  // iLast
      1,                   // lineNo
      1,                   // colNo
      "",                  // aName
      "feasibleratiotest", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
      "feasibleratiotest.p", // pName
      0                      // checkKind
  };
  double alpha;
  double c;
  double denomTol;
  double phaseOneCorrectionP;
  double phaseOneCorrectionX;
  double ratio;
  int b;
  int iy;
  int iyend;
  int totalIneq;
  int totalUB;
  boolean_T overflow;
  totalIneq = workingset_sizes[2] - 1;
  totalUB = workingset_sizes[4];
  alpha = 1.0E+30;
  newBlocking = false;
  constrType = 0;
  constrIdx = 0;
  denomTol = 2.2204460492503131E-13 *
             internal::blas::xnrm2(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    int ldw;
    if (workingset_sizes[2] > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(workingset_sizes[2] < 1600)) {
      for (int k{0}; k <= totalIneq; k++) {
        workspace[k] = workingset_bineq[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k <= totalIneq; k++) {
        workspace[k] = workingset_bineq[k];
      }
    }
    internal::blas::xgemv(workingset_nVar, workingset_sizes[2],
                          workingset_Aineq, workingset_ldA, solution_xstar,
                          workspace);
    ldw = workspace.size(0);
    iy = workspace.size(0) + 1;
    if ((workingset_nVar != 0) && (workingset_sizes[2] != 0)) {
      iyend = workspace.size(0) + workingset_sizes[2];
      if ((workspace.size(0) + 1 <= iyend) && (iyend > 2147483646)) {
        check_forloop_overflow_error();
      }
      if (static_cast<int>((iyend - iy) + 1 < 1600)) {
        for (int k{iy}; k <= iyend; k++) {
          workspace[k - 1] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = iy; k <= iyend; k++) {
          workspace[k - 1] = 0.0;
        }
      }
      iy = workspace.size(0);
      iyend = workingset_ldA * (workingset_sizes[2] - 1) + 1;
      if ((workingset_ldA == 0) || ((workingset_ldA > 0) && (iyend < 1)) ||
          ((workingset_ldA < 0) && (iyend > 1))) {
        overflow = false;
      } else if (workingset_ldA > 0) {
        overflow = (iyend > MAX_int32_T - workingset_ldA);
      } else {
        overflow = (iyend < MIN_int32_T - workingset_ldA);
      }
      if (workingset_ldA == 0) {
        m_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
      }
      if (overflow) {
        check_forloop_overflow_error();
      }
      for (int iac{1}; workingset_ldA < 0 ? iac >= iyend : iac <= iyend;
           iac += workingset_ldA) {
        c = 0.0;
        b = (iac + workingset_nVar) - 1;
        if ((iac <= b) && (b > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int ia{iac}; ia <= b; ia++) {
          c += workingset_Aineq[ia - 1] * solution_searchDir[ia - iac];
        }
        workspace[iy] = workspace[iy] + c;
        iy++;
      }
    }
    for (b = 0; b <= totalIneq; b++) {
      iy = workspace.size(0) * workspace.size(1);
      iyend = (ldw + b) + 1;
      if ((iyend < 1) || (iyend > iy)) {
        rtDynamicBoundsError(iyend, 1, iy, w_emlrtBCI);
      }
      phaseOneCorrectionX = workspace[iyend - 1];
      if (phaseOneCorrectionX > denomTol) {
        iyend = (workingset_isActiveIdx[2] + b) + 1;
        if ((iyend - 1 < 1) ||
            (iyend - 1 > workingset_isActiveConstr.size(0))) {
          rtDynamicBoundsError(iyend - 1, 1, workingset_isActiveConstr.size(0),
                               g_emlrtBCI);
        }
        if (!workingset_isActiveConstr[iyend - 2]) {
          if ((b + 1 < 1) || (b + 1 > iy)) {
            rtDynamicBoundsError(b + 1, 1, iy, w_emlrtBCI);
          }
          if (b + 1 > iy) {
            rtDynamicBoundsError(b + 1, 1, iy, w_emlrtBCI);
          }
          c = workspace[b];
          c = std::fmin(std::abs(c), 1.0E-6 - c) / phaseOneCorrectionX;
          if (c < alpha) {
            alpha = c;
            constrType = 3;
            constrIdx = b + 1;
            newBlocking = true;
          }
        }
      }
    }
  }
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    if ((workingset_nVar < 1) || (workingset_nVar > solution_xstar.size(0))) {
      rtDynamicBoundsError(workingset_nVar, 1, solution_xstar.size(0),
                           w_emlrtBCI);
    }
    phaseOneCorrectionX =
        static_cast<double>(isPhaseOne) * solution_xstar[workingset_nVar - 1];
    if (workingset_nVar > solution_searchDir.size(0)) {
      rtDynamicBoundsError(workingset_nVar, 1, solution_searchDir.size(0),
                           w_emlrtBCI);
    }
    phaseOneCorrectionP = static_cast<double>(isPhaseOne) *
                          solution_searchDir[workingset_nVar - 1];
    iy = workingset_sizes[3];
    for (b = 0; b <= iy - 2; b++) {
      if ((b + 1 < 1) || (b + 1 > workingset_indexLB.size(0))) {
        rtDynamicBoundsError(b + 1, 1, workingset_indexLB.size(0), w_emlrtBCI);
      }
      if ((workingset_indexLB[b] < 1) ||
          (workingset_indexLB[b] > solution_searchDir.size(0))) {
        rtDynamicBoundsError(workingset_indexLB[b], 1,
                             solution_searchDir.size(0), w_emlrtBCI);
      }
      c = -solution_searchDir[workingset_indexLB[b] - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        iyend = workingset_isActiveIdx[3] + b;
        if ((iyend < 1) || (iyend > workingset_isActiveConstr.size(0))) {
          rtDynamicBoundsError(iyend, 1, workingset_isActiveConstr.size(0),
                               g_emlrtBCI);
        }
        if (!workingset_isActiveConstr[iyend - 1]) {
          if ((workingset_indexLB[b] < 1) ||
              (workingset_indexLB[b] > solution_xstar.size(0))) {
            rtDynamicBoundsError(workingset_indexLB[b], 1,
                                 solution_xstar.size(0), w_emlrtBCI);
          }
          if ((workingset_indexLB[b] < 1) ||
              (workingset_indexLB[b] > workingset_lb.size(0))) {
            rtDynamicBoundsError(workingset_indexLB[b], 1,
                                 workingset_lb.size(0), w_emlrtBCI);
          }
          ratio = (-solution_xstar[workingset_indexLB[b] - 1] -
                   workingset_lb[workingset_indexLB[b] - 1]) -
                  phaseOneCorrectionX;
          c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / c;
          if (c < alpha) {
            alpha = c;
            constrType = 4;
            constrIdx = b + 1;
            newBlocking = true;
          }
        }
      }
    }
    if ((workingset_sizes[3] < 1) ||
        (workingset_sizes[3] > workingset_indexLB.size(0))) {
      rtDynamicBoundsError(workingset_sizes[3], 1, workingset_indexLB.size(0),
                           w_emlrtBCI);
    }
    iy = workingset_indexLB[workingset_sizes[3] - 1];
    overflow = ((iy < 1) || (iy > solution_searchDir.size(0)));
    if (overflow) {
      rtDynamicBoundsError(iy, 1, solution_searchDir.size(0), w_emlrtBCI);
    }
    phaseOneCorrectionX = -solution_searchDir[iy - 1];
    if (phaseOneCorrectionX > denomTol) {
      iyend = workingset_isActiveIdx[3] + workingset_sizes[3];
      if ((iyend - 1 < 1) || (iyend - 1 > workingset_isActiveConstr.size(0))) {
        rtDynamicBoundsError(iyend - 1, 1, workingset_isActiveConstr.size(0),
                             g_emlrtBCI);
      }
      if (!workingset_isActiveConstr[iyend - 2]) {
        if ((iy < 1) || (iy > solution_xstar.size(0))) {
          rtDynamicBoundsError(iy, 1, solution_xstar.size(0), w_emlrtBCI);
        }
        if (iy > workingset_lb.size(0)) {
          rtDynamicBoundsError(iy, 1, workingset_lb.size(0), w_emlrtBCI);
        }
        ratio = -solution_xstar[iy - 1] - workingset_lb[iy - 1];
        c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / phaseOneCorrectionX;
        if (c < alpha) {
          alpha = c;
          constrType = 4;
          constrIdx = workingset_sizes[3];
          newBlocking = true;
        }
      }
    }
  }
  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    if ((workingset_nVar < 1) || (workingset_nVar > solution_xstar.size(0))) {
      rtDynamicBoundsError(workingset_nVar, 1, solution_xstar.size(0),
                           w_emlrtBCI);
    }
    phaseOneCorrectionX =
        static_cast<double>(isPhaseOne) * solution_xstar[workingset_nVar - 1];
    if (workingset_nVar > solution_searchDir.size(0)) {
      rtDynamicBoundsError(workingset_nVar, 1, solution_searchDir.size(0),
                           w_emlrtBCI);
    }
    phaseOneCorrectionP = static_cast<double>(isPhaseOne) *
                          solution_searchDir[workingset_nVar - 1];
    if (workingset_sizes[4] > 2147483646) {
      check_forloop_overflow_error();
    }
    for (b = 0; b < totalUB; b++) {
      if ((b + 1 < 1) || (b + 1 > workingset_indexUB.size(0))) {
        rtDynamicBoundsError(b + 1, 1, workingset_indexUB.size(0), w_emlrtBCI);
      }
      if ((workingset_indexUB[b] < 1) ||
          (workingset_indexUB[b] > solution_searchDir.size(0))) {
        rtDynamicBoundsError(workingset_indexUB[b], 1,
                             solution_searchDir.size(0), w_emlrtBCI);
      }
      c = solution_searchDir[workingset_indexUB[b] - 1] - phaseOneCorrectionP;
      if (c > denomTol) {
        iy = workingset_isActiveIdx[4] + b;
        if ((iy < 1) || (iy > workingset_isActiveConstr.size(0))) {
          rtDynamicBoundsError(iy, 1, workingset_isActiveConstr.size(0),
                               g_emlrtBCI);
        }
        if (!workingset_isActiveConstr[iy - 1]) {
          if ((workingset_indexUB[b] < 1) ||
              (workingset_indexUB[b] > solution_xstar.size(0))) {
            rtDynamicBoundsError(workingset_indexUB[b], 1,
                                 solution_xstar.size(0), w_emlrtBCI);
          }
          if ((workingset_indexUB[b] < 1) ||
              (workingset_indexUB[b] > workingset_ub.size(0))) {
            rtDynamicBoundsError(workingset_indexUB[b], 1,
                                 workingset_ub.size(0), w_emlrtBCI);
          }
          ratio = (solution_xstar[workingset_indexUB[b] - 1] -
                   workingset_ub[workingset_indexUB[b] - 1]) -
                  phaseOneCorrectionX;
          c = std::fmin(std::abs(ratio), 1.0E-6 - ratio) / c;
          if (c < alpha) {
            alpha = c;
            constrType = 5;
            constrIdx = b + 1;
            newBlocking = true;
          }
        }
      }
    }
  }
  if (!isPhaseOne) {
    if (newBlocking && (alpha > 1.0)) {
      newBlocking = false;
    }
    alpha = std::fmin(alpha, 1.0);
  }
  return alpha;
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for feasibleratiotest.cpp
//
// [EOF]
//
