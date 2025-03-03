//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeComplError.h
//
// Code generation for function 'computeComplError'
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
real_T computeComplError(const emlrtStack &sp,
                         const array<real_T, 1U> &fscales_lineq_constraint,
                         const array<real_T, 1U> &xCurrent, int32_T mIneq,
                         const array<real_T, 1U> &cIneq,
                         const array<int32_T, 1U> &finiteLB, int32_T mLB,
                         const array<real_T, 2U> &lb,
                         const array<int32_T, 1U> &finiteUB, int32_T mUB,
                         const array<real_T, 2U> &ub,
                         const array<real_T, 1U> &lambda, int32_T iL0);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeComplError.h)
