//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// quinticpolytraj.h
//
// Code generation for function 'quinticpolytraj'
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
namespace coder {
void quinticpolytraj(const emlrtStack &sp, const real_T timePoints[2],
                     const ::coder::array<real_T, 2U> &t,
                     ::coder::array<real_T, 2U> &q,
                     ::coder::array<real_T, 2U> &qd,
                     ::coder::array<real_T, 2U> &qdd);

void quinticpolytraj(
    const emlrtStack &sp, const ::coder::array<real_T, 2U> &wayPoints,
    ::coder::array<real_T, 2U> &timePoints, const ::coder::array<real_T, 2U> &t,
    const ::coder::array<real_T, 2U> &varargin_2,
    const ::coder::array<real_T, 2U> &varargin_4, ::coder::array<real_T, 2U> &q,
    ::coder::array<real_T, 2U> &qd, ::coder::array<real_T, 2U> &qdd);

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (quinticpolytraj.h)
