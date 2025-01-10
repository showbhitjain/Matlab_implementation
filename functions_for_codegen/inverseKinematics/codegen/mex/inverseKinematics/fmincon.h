//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fmincon.h
//
// Code generation for function 'fmincon'
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
namespace coder {
class anonymous_function;

}

// Function Declarations
namespace coder {
real_T fmincon(const emlrtStack &sp, const anonymous_function &fun,
               array<real_T, 1U> &x0, const array<real_T, 2U> &Aeq,
               const real_T beq_data[], int32_T beq_size,
               const array<real_T, 1U> &lb, const array<real_T, 1U> &ub,
               real_T *exitflag);

}

// End of code generation (fmincon.h)
