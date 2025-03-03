//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// solve.h
//
// Code generation for function 'solve'
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
struct f_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace CholManager {
void solve(const f_struct_T &obj, array<real_T, 1U> &rhs);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (solve.h)
