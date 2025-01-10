//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// validateTimeScaling.h
//
// Code generation for function 'validateTimeScaling'
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
void validateTimeScaling(const emlrtStack &sp,
                         const ::coder::array<real_T, 2U> &timeScalingMatrix,
                         real_T timeVectorLength,
                         ::coder::array<real_T, 2U> &validatedTimeScaling);

}
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (validateTimeScaling.h)
