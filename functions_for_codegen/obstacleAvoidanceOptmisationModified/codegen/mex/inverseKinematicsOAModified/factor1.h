//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factor1.h
//
// Code generation for function 'factor1'
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
struct f_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void factor(const emlrtStack &sp, f_struct_T &obj, const array<real_T, 2U> &A,
            int32_T ndims, int32_T ldA);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factor1.h)
