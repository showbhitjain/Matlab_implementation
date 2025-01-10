//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// changeEndSegBreaks.h
//
// Code generation for function 'changeEndSegBreaks'
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
namespace trajectoryGeneration {
namespace coder {
namespace robotics {
namespace core {
namespace internal {
void changeEndSegBreaks(const emlrtStack &sp, real_T oldBreaks[4],
                        const ::coder::array<real_T, 2U> &evalTime);

void changeEndSegBreaks(const emlrtStack &sp,
                        ::coder::array<real_T, 2U> &oldBreaks,
                        const ::coder::array<real_T, 2U> &evalTime);

} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (changeEndSegBreaks.h)
