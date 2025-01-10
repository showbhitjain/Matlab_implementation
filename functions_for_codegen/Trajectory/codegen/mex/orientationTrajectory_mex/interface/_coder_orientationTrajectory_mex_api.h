//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_orientationTrajectory_mex_api.h
//
// Code generation for function '_coder_orientationTrajectory_mex_api'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace trajectoryGeneration {
void orientationTrajectory_api(const mxArray *const prhs[4], int32_T nlhs,
                               const mxArray *plhs[3]);

void positionTrajectory_api(const mxArray *const prhs[6], int32_T nlhs,
                            const mxArray *plhs[3]);

} // namespace trajectoryGeneration

// End of code generation (_coder_orientationTrajectory_mex_api.h)
