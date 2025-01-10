//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// log.h
//
// Code generation for function 'log'
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

// Type Declarations
namespace trajectoryGeneration {
namespace coder {
class quaternion;

}
} // namespace trajectoryGeneration

// Function Declarations
namespace trajectoryGeneration {
void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                      const coder::quaternion *in2, const int8_T in3[2]);

void binary_expand_op_1(real_T in1_data[], int32_T in1_size[2],
                        const coder::quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2]);

void binary_expand_op_2(real_T in1_data[], int32_T in1_size[2],
                        const coder::quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2]);

} // namespace trajectoryGeneration

// End of code generation (log.h)
