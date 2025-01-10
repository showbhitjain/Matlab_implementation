//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// addFlatSegmentsToPPFormParts.h
//
// Code generation for function 'addFlatSegmentsToPPFormParts'
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
namespace robotics {
namespace core {
namespace internal {
void addFlatSegmentsToPPFormParts(const emlrtStack &sp,
                                  const ::coder::array<real_T, 2U> &oldbreaks,
                                  const ::coder::array<real_T, 2U> &oldCoeffs,
                                  real_T dim,
                                  ::coder::array<real_T, 2U> &newBreaks,
                                  ::coder::array<real_T, 2U> &newCoefs);

void addFlatSegmentsToPPFormParts(const emlrtStack &sp,
                                  const ::coder::array<real_T, 2U> &oldbreaks,
                                  const ::coder::array<real_T, 2U> &oldCoeffs,
                                  ::coder::array<real_T, 2U> &newBreaks,
                                  ::coder::array<real_T, 2U> &newCoefs);

void b_addFlatSegmentsToPPFormParts(const emlrtStack &sp,
                                    const ::coder::array<real_T, 2U> &oldbreaks,
                                    const ::coder::array<real_T, 2U> &oldCoeffs,
                                    ::coder::array<real_T, 2U> &newBreaks,
                                    ::coder::array<real_T, 2U> &newCoefs);

} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (addFlatSegmentsToPPFormParts.h)
