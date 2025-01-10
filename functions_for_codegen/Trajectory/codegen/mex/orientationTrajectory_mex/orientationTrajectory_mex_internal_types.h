//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// orientationTrajectory_mex_internal_types.h
//
// Code generation for function 'orientationTrajectory'
//

#pragma once

// Include files
#include "orientationTrajectory_mex_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
namespace trajectoryGeneration {
struct struct_T {
  real_T breaks[6];
  real_T coefs[15];
};

struct b_struct_T {
  real_T breaks[4];
  real_T coefs[12];
};

struct c_struct_T {
  real_T breaks[4];
  real_T coefs[18];
};

struct d_struct_T {
  ::coder::array<real_T, 2U> breaks;
  ::coder::array<real_T, 3U> coefs;
};

struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtRunTimeErrorInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

} // namespace trajectoryGeneration

// End of code generation (orientationTrajectory_mex_internal_types.h)
