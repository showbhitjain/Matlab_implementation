//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: saveState.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 15:44:26
//

// Include Files
#include "saveState.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "omp.h"
#include <cstring>

// Function Definitions
//
// Arguments    : j_struct_T &obj
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void saveState(j_struct_T &obj)
{
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,          // iFirst
      -1,          // iLast
      1,           // lineNo
      1,           // colNo
      "",          // aName
      "saveState", // fName
      "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
      "+TrialState/saveState.p", // pName
      0                          // checkKind
  };
  array<double, 1U> y;
  int b_i;
  int i;
  int nVar;
  obj.sqpFval_old = obj.sqpFval;
  nVar = obj.xstarsqp.size(0) - 1;
  if (obj.xstarsqp.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  if (static_cast<int>(nVar + 1 < 400)) {
    for (int k{0}; k <= nVar; k++) {
      obj.xstarsqp_old[k] = obj.xstarsqp[k];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

    for (int k = 0; k <= nVar; k++) {
      obj.xstarsqp_old[k] = obj.xstarsqp[k];
    }
  }
  if (obj.xstarsqp.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i <= nVar; i++) {
    b_i = obj.grad.size(0);
    if (i + 1 > b_i) {
      rtDynamicBoundsError(i + 1, 1, b_i, w_emlrtBCI);
    }
    b_i = obj.grad_old.size(0);
    if (i + 1 > b_i) {
      rtDynamicBoundsError(i + 1, 1, b_i, w_emlrtBCI);
    }
    obj.grad_old[i] = obj.grad[i];
  }
  i = obj.mIneq;
  if (obj.mIneq > 2147483646) {
    check_forloop_overflow_error();
  }
  if (static_cast<int>(i < 400)) {
    for (int k{0}; k < i; k++) {
      obj.cIneq_old[k] = obj.cIneq[k];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

    for (int k = 0; k < i; k++) {
      obj.cIneq_old[k] = obj.cIneq[k];
    }
  }
  i = obj.mEq;
  y.set_size(obj.cEq_old.size[0]);
  nVar = obj.cEq_old.size[0];
  for (b_i = 0; b_i < nVar; b_i++) {
    y[b_i] = obj.cEq_old.data[b_i];
  }
  if (obj.mEq > 2147483646) {
    check_forloop_overflow_error();
  }
  if (static_cast<int>(i < 400)) {
    for (int k{0}; k < i; k++) {
      y[k] = obj.cEq.data[k];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    4 > omp_get_max_threads() ? omp_get_max_threads() : 4)

    for (int k = 0; k < i; k++) {
      y[k] = obj.cEq.data[k];
    }
  }
  obj.cEq_old.size[0] = y.size(0);
  nVar = y.size(0);
  for (b_i = 0; b_i < nVar; b_i++) {
    obj.cEq_old.data[b_i] = y[b_i];
  }
}

} // namespace TrialState
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for saveState.cpp
//
// [EOF]
//
