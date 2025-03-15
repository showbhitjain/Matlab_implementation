//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeDualFeasError.h
//
// Code generation for function 'computeDualFeasError'
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
boolean_T computeDualFeasError(const emlrtStack &sp, int32_T nVar,
                               const array<real_T, 1U> &gradLag, real_T &val);

boolean_T computeDualFeasError(const emlrtStack &sp, int32_T nVar,
                               const array<real_T, 2U> &gradLag, real_T &val);

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeDualFeasError.h)
