//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// log.cpp
//
// Code generation for function 'log'
//

// Include files
#include "log.h"
#include "orientationTrajectory_mex_data.h"
#include "quaternion.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace trajectoryGeneration {
void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                      const coder::quaternion *in2, const int8_T in3[2])
{
  real_T in2_data;
  int32_T loop_ub;
  int32_T stride_1_1;
  if (in1_size[1] == 1) {
    loop_ub = in3[1];
  } else {
    loop_ub = in1_size[1];
  }
  stride_1_1 = (in1_size[1] != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in2_data = in2->d * in1_data[i * stride_1_1];
  }
  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[0] = in2_data;
  }
}

void binary_expand_op_1(real_T in1_data[], int32_T in1_size[2],
                        const coder::quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2])
{
  int32_T loop_ub;
  int32_T stride_1_1;
  in1_size[0] = 1;
  if (in4_size[1] == 1) {
    loop_ub = in3[1];
  } else {
    loop_ub = in4_size[1];
  }
  in1_size[1] = loop_ub;
  stride_1_1 = (in4_size[1] != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2->c * in4_data[i * stride_1_1];
  }
}

void binary_expand_op_2(real_T in1_data[], int32_T in1_size[2],
                        const coder::quaternion *in2, const int8_T in3[2],
                        const real_T in4_data[], const int32_T in4_size[2])
{
  int32_T loop_ub;
  int32_T stride_1_1;
  in1_size[0] = 1;
  if (in4_size[1] == 1) {
    loop_ub = in3[1];
  } else {
    loop_ub = in4_size[1];
  }
  in1_size[1] = loop_ub;
  stride_1_1 = (in4_size[1] != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1_data[i] = in2->b * in4_data[i * stride_1_1];
  }
}

} // namespace trajectoryGeneration

// End of code generation (log.cpp)
