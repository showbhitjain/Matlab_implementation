//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeGrad_StoreHx.h
//
// Code generation for function 'computeGrad_StoreHx'
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
struct g_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void computeGrad_StoreHx(const emlrtStack &sp, g_struct_T &obj,
                         const array<real_T, 2U> &H, const array<real_T, 1U> &f,
                         const array<real_T, 1U> &x);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeGrad_StoreHx.h)
