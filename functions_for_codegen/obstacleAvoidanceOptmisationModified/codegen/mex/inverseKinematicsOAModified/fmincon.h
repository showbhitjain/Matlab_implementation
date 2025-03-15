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
               array<real_T, 1U> &x0, const real_T Aineq_data[],
               const int32_T Aineq_size[2], const real_T bineq_data[],
               const int32_T bineq_size[2], const real_T Aeq_data[],
               const int32_T Aeq_size[2], const real_T beq_data[],
               const int32_T beq_size[2], const real_T lb_data[],
               int32_T lb_size, const real_T ub_data[], int32_T ub_size,
               real_T *exitflag);

}

// End of code generation (fmincon.h)
