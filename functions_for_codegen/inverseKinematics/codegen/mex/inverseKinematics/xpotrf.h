//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xpotrf.h
//
// Code generation for function 'xpotrf'
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
namespace internal {
namespace lapack {
int32_T xpotrf(const emlrtStack &sp, int32_T n, array<real_T, 2U> &A,
               int32_T lda);

}
} // namespace internal
} // namespace coder

// End of code generation (xpotrf.h)
