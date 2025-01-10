//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computePrimalFeasError.h
//
// Code generation for function 'computePrimalFeasError'
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
real_T computePrimalFeasError(const emlrtStack &sp, const array<real_T, 1U> &x,
                              int32_T mLinEq, const real_T cEq_data[],
                              int32_T cEq_size,
                              const array<int32_T, 1U> &finiteLB, int32_T mLB,
                              const array<real_T, 1U> &lb,
                              const array<int32_T, 1U> &finiteUB, int32_T mUB,
                              const array<real_T, 1U> &ub);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computePrimalFeasError.h)
