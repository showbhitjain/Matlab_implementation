//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// abs.h
//
// Code generation for function 'abs'
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
void b_abs(const emlrtStack &sp, const array<real_T, 1U> &x,
           array<real_T, 1U> &y);

}

// End of code generation (abs.h)
