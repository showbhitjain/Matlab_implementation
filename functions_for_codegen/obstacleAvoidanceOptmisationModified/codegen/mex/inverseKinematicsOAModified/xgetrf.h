//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgetrf.h
//
// Code generation for function 'xgetrf'
//

#pragma once

// Include files
#include "rtwtypes.h"
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
void xgetrf(const emlrtStack &sp, real_T A[36], int32_T ipiv[6]);

}
} // namespace internal
} // namespace coder

// End of code generation (xgetrf.h)
