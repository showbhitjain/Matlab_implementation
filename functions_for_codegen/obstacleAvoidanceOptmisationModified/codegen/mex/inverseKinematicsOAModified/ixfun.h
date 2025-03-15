//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ixfun.h
//
// Code generation for function 'ixfun'
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

// Function Declarations
namespace coder {
namespace internal {
int32_T expand_max(const emlrtStack &sp, const real_T a_data[], int32_T a_size,
                   const real_T b_data[], int32_T b_size, real_T c_data[]);

int32_T expand_min(const emlrtStack &sp, const real_T a_data[], int32_T a_size,
                   const real_T b_data[], int32_T b_size, real_T c_data[]);

} // namespace internal
} // namespace coder

// End of code generation (ixfun.h)
