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
                 int32_T mLinIneq, const real_T Aineq_data[],
                 const int32_T Aineq_size[2], int32_T mEq, int32_T mLinEq,
                 const real_T Aeq_data[], const int32_T Aeq_size[2],
                 int32_T mLB, int32_T mUB, int32_T mFixed, int32_T mConstrMax);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (loadProblem.h)
