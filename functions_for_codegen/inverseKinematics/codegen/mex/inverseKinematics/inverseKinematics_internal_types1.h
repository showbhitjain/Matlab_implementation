//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematics_internal_types1.h
//
// Code generation for function 'inverseKinematics_internal_types1'
//

#pragma once

// Include files
#include "inverseKinematics_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
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
  coder::bounded_array<real_T, 6U, 1U> xd_eff_vel;
  coder::array<real_T, 1U> starting_joint_vel;
  coder::array<real_T, 1U> joint_values;
  struct0_T config;
};

// End of code generation (inverseKinematics_internal_types1.h)
