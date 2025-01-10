//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_utilsMatlab_api.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 14-Nov-2024 02:49:51
//

#ifndef _CODER_UTILSMATLAB_API_H
#define _CODER_UTILSMATLAB_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void add_noise(coder::array<real_T, 1U> *joint_vector, real_T noise_min,
               real_T noise_max, coder::array<real_T, 1U> *noisy_joint_vector);

void add_noise_api(const mxArray *const prhs[3], const mxArray **plhs);

void integrateRungeKutta(
    coder::array<real_T, 1U> *desired_joint_velocity_current, real_T tspan[2],
    coder::array<real_T, 1U> *start_joint_Velocity,
    coder::array<real_T, 1U> *desired_joint_vector);

void integrateRungeKutta_api(const mxArray *const prhs[3],
                             const mxArray **plhs);

void utilsMatlab_atexit();

void utilsMatlab_initialize();

void utilsMatlab_terminate();

void utilsMatlab_xil_shutdown();

void utilsMatlab_xil_terminate();

#endif
//
// File trailer for _coder_utilsMatlab_api.h
//
// [EOF]
//
