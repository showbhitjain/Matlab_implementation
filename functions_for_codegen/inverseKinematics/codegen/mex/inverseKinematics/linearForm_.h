//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linearForm_.h
//
// Code generation for function 'linearForm_'
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

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void linearForm_(const emlrtStack &sp, boolean_T obj_hasLinear,
                 int32_T obj_nvar, array<real_T, 2U> &workspace,
                 const array<real_T, 2U> &H, const array<real_T, 1U> &f,
                 const array<real_T, 1U> &x);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (linearForm_.h)
