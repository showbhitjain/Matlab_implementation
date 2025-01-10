//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematics.h
//
// Code generation for function 'inverseKinematics'
//

#pragma once

// Include files
#include "inverseKinematics_types.h"
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
void inverseKinematics(
    const emlrtStack *sp, const coder::array<real_T, 1U> &joint_values,
    const coder::array<real_T, 2U> &jacobi, const real_T xd_eff_vel_data[],
    const int32_T xd_eff_vel_size[1],
    const coder::array<real_T, 1U> &jointminvalues,
    const coder::array<real_T, 1U> &jointmaxvalues,
    const coder::array<real_T, 1U> &joint_min_vel,
    const coder::array<real_T, 1U> &joint_max_vel, const struct0_T *config,
    coder::array<real_T, 1U> &optimal_joint_velocity, real_T *Exit_Flag);

real_T inverseKinematics_anonFcn1(
    const emlrtStack &sp, const coder::array<real_T, 2U> &jacobi,
    const real_T xd_eff_vel_data[], int32_T xd_eff_vel_size,
    const coder::array<real_T, 1U> &starting_joint_vel,
    const coder::array<real_T, 1U> &joint_values, const struct0_T &config,
    const coder::array<real_T, 1U> &q_vel);

void inverseKinematics_init();

// End of code generation (inverseKinematics.h)
