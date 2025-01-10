//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rottraj.h
//
// Code generation for function 'rottraj'
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
namespace trajectoryGeneration {
namespace coder {
class quaternion;

class b_quaternion;

} // namespace coder
} // namespace trajectoryGeneration

// Function Declarations
namespace trajectoryGeneration {
namespace coder {
void rottraj(const emlrtStack &sp, const quaternion R0, const quaternion RF,
             const real_T timeInterval[2], const ::coder::array<real_T, 2U> &t,
             const ::coder::array<real_T, 2U> &varargin_2, b_quaternion &R,
             ::coder::array<real_T, 2U> &omega,
             ::coder::array<real_T, 2U> &alpha);

}
} // namespace trajectoryGeneration

// End of code generation (rottraj.h)
