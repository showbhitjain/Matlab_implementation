//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compressBounds.h
//
// Code generation for function 'compressBounds'
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
namespace initialize {
int32_T compressBounds(const emlrtStack &sp, int32_T nVar,
                       array<int32_T, 1U> &indexLB, array<int32_T, 1U> &indexUB,
                       array<int32_T, 1U> &indexFixed,
                       const array<real_T, 1U> &lb, const array<real_T, 1U> &ub,
                       int32_T &mUB, int32_T &mFixed);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compressBounds.h)
