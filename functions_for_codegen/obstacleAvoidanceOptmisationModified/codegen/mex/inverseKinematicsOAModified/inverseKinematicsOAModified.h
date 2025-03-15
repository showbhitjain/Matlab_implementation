//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified.h
//
// Code generation for function 'inverseKinematicsOAModified'
//

#pragma once

// Include files
#include "inverseKinematicsOAModified_types.h"
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
real_T c_inverseKinematicsOAModified_a(
    const emlrtStack &sp, const real_T jacobi_data[],
    const int32_T jacobi_size[2], const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &starting_joint_vel,
    const real_T joint_values_data[], int32_T joint_values_size,
    const real_T jointVelocityWeightMatrix_data[],
    const int32_T jointVelocityWeightMatrix_size[2], const struct0_T &config,
    boolean_T slackIsUsed, const coder::array<real_T, 1U> &q_vel);

void c_inverseKinematicsOAModified_i();

void inverseKinematicsOAModified(
    const emlrtStack *sp, const real_T joint_values_data[],
    const int32_T joint_values_size[1], const real_T jacobi_data[],
    const int32_T jacobi_size[2], const real_T xd_eff_vel[6],
    const real_T jointminvalues_data[], const int32_T jointminvalues_size[1],
    const real_T jointmaxvalues_data[], const int32_T jointmaxvalues_size[1],
    const real_T joint_min_vel_data[], const int32_T joint_min_vel_size[1],
    const real_T joint_max_vel_data[], const int32_T joint_max_vel_size[1],
    const real_T J_g_data[], const int32_T J_g_size[2], const real_T b_g_data[],
    const int32_T b_g_size[1], const real_T jointVelocityWeightMatrix_data[],
    const int32_T jointVelocityWeightMatrix_size[2],
    const struct0_T *configInput,
    coder::array<real_T, 1U> &optimal_joint_velocity, real_T *Exit_Flag);

// End of code generation (inverseKinematicsOAModified.h)
