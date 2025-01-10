//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// configurableObjective.h
//
// Code generation for function 'configurableObjective'
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
struct struct0_T;

// Function Declarations
real_T binary_expand_op(const emlrtStack &sp, real_T in1, const struct0_T &in2,
                        const emlrtRSInfo in3,
                        const coder::array<real_T, 1U> &in5, int32_T in6,
                        const coder::array<real_T, 1U> &in7);

void binary_expand_op_1(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                        const real_T in2_data[], const int32_T &in2_size,
                        const real_T in3_data[], const int32_T &in3_size);

// End of code generation (configurableObjective.h)
