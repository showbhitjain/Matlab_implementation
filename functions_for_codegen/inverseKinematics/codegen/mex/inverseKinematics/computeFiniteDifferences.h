//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFiniteDifferences.h
//
// Code generation for function 'computeFiniteDifferences'
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
struct l_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
boolean_T computeFiniteDifferences(
    const emlrtStack &sp, l_struct_T &obj, real_T fCurrent,
    array<real_T, 1U> &xk, array<real_T, 1U> &gradf,
    const array<real_T, 1U> &lb, const array<real_T, 1U> &ub,
    const array<real_T, 1U> &c_runTimeOptions_FiniteDifferen,
    const array<real_T, 1U> &runTimeOptions_TypicalX);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeFiniteDifferences.h)
