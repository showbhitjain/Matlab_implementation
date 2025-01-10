//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_trajectory_generator_mex.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 26-Oct-2024 20:50:12
//

#ifndef _CODER_TRAJECTORY_GENERATOR_MEX_H
#define _CODER_TRAJECTORY_GENERATOR_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_orientationTrajectory_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                              int32_T nrhs,
                                              const mxArray *prhs[4]);

void unsafe_positionTrajectory_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                           int32_T nrhs,
                                           const mxArray *prhs[6]);

#endif
//
// File trailer for _coder_trajectory_generator_mex.h
//
// [EOF]
//
