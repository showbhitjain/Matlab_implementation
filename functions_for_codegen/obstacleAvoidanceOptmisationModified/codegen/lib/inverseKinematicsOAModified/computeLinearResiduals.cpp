//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeLinearResiduals.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 15:44:26
//

// Include Files
#include "computeLinearResiduals.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const array<double, 1U> &x
//                int nVar
//                array<double, 1U> &workspaceIneq
//                int mLinIneq
//                const array<double, 1U> &AineqT
//                const array<double, 2U> &bineq
//                int ldAi
//                double workspaceEq_data[]
//                int &workspaceEq_size
//                int mLinEq
//                const array<double, 1U> &AeqT
//                const double beq_data[]
//                int ldAe
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
void computeLinearResiduals(const array<double, 1U> &x, int nVar,
                            array<double, 1U> &workspaceIneq, int mLinIneq,
                            const array<double, 1U> &AineqT,
                            const array<double, 2U> &bineq, int ldAi,
                            double workspaceEq_data[], int &workspaceEq_size,
                            int mLinEq, const array<double, 1U> &AeqT,
                            const double beq_data[], int ldAe)
{
  array<double, 1U> y;
  if (mLinIneq > 0) {
    if (mLinIneq > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mLinIneq < 400)) {
      for (int k{0}; k < mLinIneq; k++) {
        workspaceIneq[k] = bineq[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

      for (int k = 0; k < mLinIneq; k++) {
        workspaceIneq[k] = bineq[k];
      }
    }
    ::coder::internal::blas::xgemv(nVar, mLinIneq, AineqT, ldAi, x,
                                   workspaceIneq);
  }
  if (mLinEq > 0) {
    int loop_ub;
    y.set_size(workspaceEq_size);
    for (loop_ub = 0; loop_ub < workspaceEq_size; loop_ub++) {
      y[loop_ub] = workspaceEq_data[loop_ub];
    }
    if (mLinEq > 2147483646) {
      check_forloop_overflow_error();
    }
    if (static_cast<int>(mLinEq < 400)) {
      for (int k{0}; k < mLinEq; k++) {
        y[k] = beq_data[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

      for (int k = 0; k < mLinEq; k++) {
        y[k] = beq_data[k];
      }
    }
    ::coder::internal::blas::xgemv(nVar, mLinEq, AeqT, ldAe, x, y);
    workspaceEq_size = y.size(0);
    loop_ub = y.size(0);
    if (static_cast<int>(y.size(0) < 400)) {
      for (int k{0}; k < loop_ub; k++) {
        workspaceEq_data[k] = y[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

      for (int k = 0; k < loop_ub; k++) {
        workspaceEq_data[k] = y[k];
      }
    }
  }
}

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeLinearResiduals.cpp
//
// [EOF]
//
