//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// orientationTrajectory.h
//
// Code generation for function 'orientationTrajectory'
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
emlrtCTX emlrtGetRootTLSGlobal();

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void orientationTrajectory(const emlrtStack *sp,
                           const ::coder::array<real_T, 2U> &orientations,
                           const ::coder::array<real_T, 2U> &waypointTimes,
                           real_T ts,
                           const ::coder::array<char_T, 2U> &trajType,
                           ::coder::array<real_T, 2U> &desired_quaternions,
                           ::coder::array<real_T, 2U> &desired_angular_velocity,
                           ::coder::array<real_T, 2U> &desired_angular_accel);

} // namespace trajectoryGeneration

// End of code generation (orientationTrajectory.h)
