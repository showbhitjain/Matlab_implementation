//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_inverseKinematics_api.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 10-Nov-2024 04:04:05
//

#ifndef _CODER_INVERSEKINEMATICS_API_H
#define _CODER_INVERSEKINEMATICS_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
struct struct0_T {
  boolean_T useObjective1;
  real_T weight1;
  boolean_T useObjective2;
  real_T weight2;
  boolean_T useObjective3;
  real_T weight3;
  boolean_T useObjective4;
  real_T weight4;
  boolean_T useObjective5;
  real_T weight5;
  boolean_T useObjective6;
  real_T weight6;
};

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void inverseKinematics(coder::array<real_T, 1U> *joint_values,
                       coder::array<real_T, 2U> *jacobi,
                       real_T xd_eff_vel_data[], int32_T xd_eff_vel_size[1],
                       coder::array<real_T, 1U> *jointminvalues,
                       coder::array<real_T, 1U> *jointmaxvalues,
                       coder::array<real_T, 1U> *joint_min_vel,
                       coder::array<real_T, 1U> *joint_max_vel,
                       struct0_T *config,
                       coder::array<real_T, 1U> *optimal_joint_velocity,
                       real_T *Exit_Flag);

void inverseKinematics_api(const mxArray *const prhs[8], int32_T nlhs,
                           const mxArray *plhs[2]);

void inverseKinematics_atexit();

void inverseKinematics_initialize();

void inverseKinematics_terminate();

void inverseKinematics_xil_shutdown();

void inverseKinematics_xil_terminate();

#endif
//
// File trailer for _coder_inverseKinematics_api.h
//
// [EOF]
//
