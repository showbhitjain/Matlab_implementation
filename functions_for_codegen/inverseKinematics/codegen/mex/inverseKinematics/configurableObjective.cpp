//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// configurableObjective.cpp
//
// Code generation for function 'configurableObjective'
//

// Include files
#include "configurableObjective.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_types.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRTEInfo dc_emlrtRTEI{
    17,                      // lineNo
    49,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pName
};

// Function Definitions
real_T binary_expand_op(const emlrtStack &sp, real_T in1, const struct0_T &in2,
                        const emlrtRSInfo in3,
                        const coder::array<real_T, 1U> &in5, int32_T in6,
                        const coder::array<real_T, 1U> &in7)
{
  coder::array<real_T, 1U> b_in5;
  emlrtStack st;
  real_T out1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in7.size(0) == 1) {
    loop_ub = in6;
  } else {
    loop_ub = in7.size(0);
  }
  b_in5.set_size(&dc_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in6 != 1);
  stride_1_0 = (in7.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in5[i] = in5[i * stride_0_0] - in7[i * stride_1_0];
  }
  loop_ub = b_in5.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = b_in5[i];
    b_in5[i] = varargin_1 * varargin_1;
  }
  st.site = const_cast<emlrtRSInfo *>(&in3);
  in1 += in2.weight4 * coder::sum(st, b_in5);
  out1 = in1;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return out1;
}

void binary_expand_op_1(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                        const real_T in2_data[], const int32_T &in2_size,
                        const real_T in3_data[], const int32_T &in3_size)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3_size == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3_size;
  }
  in1.set_size(&jb_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2_size != 1);
  stride_1_0 = (in3_size != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = in2_data[i * stride_0_0] - in3_data[i * stride_1_0];
  }
}

// End of code generation (configurableObjective.cpp)
