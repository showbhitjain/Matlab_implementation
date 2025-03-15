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
real_T configurableObjective(
    const emlrtStack &sp, const real_T current_joint_velocity_data[],
    int32_T current_joint_velocity_size, const real_T jacobi_data[],
    const int32_T jacobi_size[2], const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &starting_joint_vel,
    const real_T joint_values_data[], int32_T joint_values_size,
    const real_T WeightMatrix_data[], const int32_T WeightMatrix_size[2],
    const struct0_T &config);

// End of code generation (configurableObjective.h)
