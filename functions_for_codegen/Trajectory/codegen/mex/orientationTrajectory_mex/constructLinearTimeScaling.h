//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// constructLinearTimeScaling.h
//
// Code generation for function 'constructLinearTimeScaling'
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
void constructLinearTimeScaling(const emlrtStack &sp,
                                const real_T timeInterval[2],
                                const ::coder::array<real_T, 2U> &b_time,
                                ::coder::array<real_T, 2U> &scaling);

}
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (constructLinearTimeScaling.h)
