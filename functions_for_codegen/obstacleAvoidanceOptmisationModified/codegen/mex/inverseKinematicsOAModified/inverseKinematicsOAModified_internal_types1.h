//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified_internal_types1.h
//
// Code generation for function 'inverseKinematicsOAModified_internal_types1'
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

// Type Definitions
struct c_struct_T {
  coder::array<real_T, 2U> jacobi;
  real_T xd_eff_vel[6];
  coder::array<real_T, 1U> starting_joint_vel;
  coder::array<real_T, 1U> joint_values;
  coder::array<real_T, 2U> jointVelocityWeightMatrix;
  struct0_T config;
  boolean_T slackIsUsed;
};

// End of code generation (inverseKinematicsOAModified_internal_types1.h)
