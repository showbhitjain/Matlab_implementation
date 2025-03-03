//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xger.h
//
// Code generation for function 'xger'
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
namespace blas {
void xger(const emlrtStack &sp, int32_T m, int32_T n, real_T alpha1, real_T x,
          real_T y, array<real_T, 2U> &A, int32_T ia0, int32_T lda);

}
} // namespace internal
} // namespace coder

// End of code generation (xger.h)
