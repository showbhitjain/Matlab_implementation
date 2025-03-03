//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// isDeltaXTooSmall.h
//
// Code generation for function 'isDeltaXTooSmall'
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
namespace fminconsqp {
namespace stopping {
boolean_T isDeltaXTooSmall(const emlrtStack &sp,
                           const array<real_T, 1U> &xCurrent,
                           const array<real_T, 1U> &delta_x, int32_T nVar);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (isDeltaXTooSmall.h)
