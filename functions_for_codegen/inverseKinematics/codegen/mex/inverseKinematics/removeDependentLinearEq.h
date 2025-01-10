//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// removeDependentLinearEq.h
//
// Code generation for function 'removeDependentLinearEq'
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
struct g_struct_T;

struct i_struct_T;

struct j_struct_T;

struct d_struct_T;

struct f_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
int32_T removeDependentLinearEq(const emlrtStack &sp,
                                const array<real_T, 2U> &Aeq, real_T beq_data[],
                                const int32_T &beq_size,
                                const array<real_T, 1U> &bnd,
                                array<int32_T, 1U> &idxArray,
                                g_struct_T &memspace, i_struct_T &b_TrialState,
                                j_struct_T &WorkingSet, d_struct_T &b_QRManager,
                                f_struct_T &QPObjective);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (removeDependentLinearEq.h)
