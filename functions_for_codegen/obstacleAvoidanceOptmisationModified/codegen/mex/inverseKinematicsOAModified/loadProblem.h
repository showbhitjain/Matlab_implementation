//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// loadProblem.h
//
// Code generation for function 'loadProblem'
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
struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void loadProblem(const emlrtStack &sp, d_struct_T &obj, int32_T mIneq,
                 int32_T mLinIneq, const array<real_T, 2U> &Aineq, int32_T mEq,
                 int32_T mLinEq, const array<real_T, 2U> &Aeq, int32_T mLB,
                 int32_T mUB, int32_T mFixed, int32_T mConstrMax);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (loadProblem.h)
