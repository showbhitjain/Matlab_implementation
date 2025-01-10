//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// positionTrajectory.h
//
// Code generation for function 'positionTrajectory'
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

// Function Declarations
namespace trajectoryGeneration {
void positionTrajectory(const emlrtStack *sp,
                        const ::coder::array<real_T, 2U> &waypoints,
                        const ::coder::array<real_T, 2U> &waypointTimes,
                        real_T ts, const ::coder::array<char_T, 2U> &trajType,
                        ::coder::array<real_T, 2U> &waypointVels,
                        ::coder::array<real_T, 2U> &waypointAccels,
                        ::coder::array<real_T, 2U> &xd,
                        ::coder::array<real_T, 2U> &xd_vel,
                        ::coder::array<real_T, 2U> &xdd);

}

// End of code generation (positionTrajectory.h)
