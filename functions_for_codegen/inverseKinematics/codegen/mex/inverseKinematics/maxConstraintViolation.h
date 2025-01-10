//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// maxConstraintViolation.h
//
// Code generation for function 'maxConstraintViolation'
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
namespace qpactiveset {
namespace WorkingSet {
real_T maxConstraintViolation(const emlrtStack &sp, j_struct_T &obj,
                              const array<real_T, 2U> &x);

real_T maxConstraintViolation(const emlrtStack &sp, j_struct_T &obj,
                              const array<real_T, 2U> &x, int32_T ix0);

real_T maxConstraintViolation(const emlrtStack &sp, j_struct_T &obj,
                              const array<real_T, 1U> &x);

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (maxConstraintViolation.h)
