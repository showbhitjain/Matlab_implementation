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
    const emlrtStack &sp, const coder::array<real_T, 2U> &jacobi,
    const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &starting_joint_vel,
    const coder::array<real_T, 1U> &joint_values,
    const coder::array<real_T, 2U> &jointVelocityWeightMatrix,
    const struct0_T &config, boolean_T slackIsUsed,
    const coder::array<real_T, 1U> &q_vel);

void c_inverseKinematicsOAModified_i();

void inverseKinematicsOAModified(
    const emlrtStack *sp, const coder::array<real_T, 1U> &joint_values,
    const coder::array<real_T, 2U> &jacobi, const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &jointminvalues,
    const coder::array<real_T, 1U> &jointmaxvalues,
    const coder::array<real_T, 1U> &joint_min_vel,
    const coder::array<real_T, 1U> &joint_max_vel,
    const coder::array<real_T, 2U> &J_g, const coder::array<real_T, 1U> &b_g,
    const coder::array<real_T, 2U> &jointVelocityWeightMatrix,
    const struct0_T *configInput,
    coder::array<real_T, 1U> &optimal_joint_velocity, real_T *Exit_Flag);

// End of code generation (inverseKinematicsOAModified.h)
