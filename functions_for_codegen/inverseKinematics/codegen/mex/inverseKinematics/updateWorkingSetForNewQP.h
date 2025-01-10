//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// updateWorkingSetForNewQP.h
//
// Code generation for function 'updateWorkingSetForNewQP'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct j_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
void b_updateWorkingSetForNewQP(const emlrtStack &sp,
                                const array<real_T, 1U> &xk,
                                j_struct_T &WorkingSet, int32_T mEq,
                                const real_T cEq_data[], int32_T cEq_size,
                                int32_T mLB, const array<real_T, 1U> &lb,
                                int32_T mUB, const array<real_T, 1U> &ub,
                                int32_T mFixed);

void updateWorkingSetForNewQP(const emlrtStack &sp, const array<real_T, 1U> &xk,
                              j_struct_T &WorkingSet, int32_T mEq,
                              const real_T cEq_data[], int32_T cEq_size,
                              int32_T mLB, const array<real_T, 1U> &lb,
                              int32_T mUB, const array<real_T, 1U> &ub,
                              int32_T mFixed);

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (updateWorkingSetForNewQP.h)
