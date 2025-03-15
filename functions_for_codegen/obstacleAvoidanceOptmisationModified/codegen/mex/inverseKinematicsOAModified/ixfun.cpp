//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ixfun.cpp
//
// Code generation for function 'ixfun'
//

// Include files
#include "ixfun.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRTEInfo b_emlrtRTEI{
    225,          // lineNo
    23,           // colNo
    "expand_min", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/ixfun.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    225,          // lineNo
    23,           // colNo
    "expand_max", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/ixfun.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
int32_T expand_max(const emlrtStack &sp, const real_T a_data[], int32_T a_size,
                   const real_T b_data[], int32_T b_size, real_T c_data[])
{
  int32_T c_size;
  int8_T csz_idx_0;
  if (b_size == 1) {
    csz_idx_0 = static_cast<int8_T>(a_size);
  } else if (a_size == 1) {
    csz_idx_0 = static_cast<int8_T>(b_size);
  } else {
    csz_idx_0 = static_cast<int8_T>(muIntScalarMin_sint32(a_size, b_size));
    if (a_size != b_size) {
      emlrtErrorWithMessageIdR2018a(&sp, &c_emlrtRTEI,
                                    "MATLAB:sizeDimensionsMustMatch",
                                    "MATLAB:sizeDimensionsMustMatch", 0);
    }
  }
  c_size = csz_idx_0;
  if (csz_idx_0 != 0) {
    int32_T i;
    boolean_T b;
    boolean_T b1;
    b = (a_size != 1);
    b1 = (b_size != 1);
    i = csz_idx_0 - 1;
    for (int32_T k{0}; k <= i; k++) {
      c_data[k] = muDoubleScalarMax(a_data[b * k], b_data[b1 * k]);
    }
  }
  return c_size;
}

int32_T expand_min(const emlrtStack &sp, const real_T a_data[], int32_T a_size,
                   const real_T b_data[], int32_T b_size, real_T c_data[])
{
  int32_T c_size;
  int8_T csz_idx_0;
  if (b_size == 1) {
    csz_idx_0 = static_cast<int8_T>(a_size);
  } else if (a_size == 1) {
    csz_idx_0 = static_cast<int8_T>(b_size);
  } else {
    csz_idx_0 = static_cast<int8_T>(muIntScalarMin_sint32(a_size, b_size));
    if (a_size != b_size) {
      emlrtErrorWithMessageIdR2018a(&sp, &b_emlrtRTEI,
                                    "MATLAB:sizeDimensionsMustMatch",
                                    "MATLAB:sizeDimensionsMustMatch", 0);
    }
  }
  c_size = csz_idx_0;
  if (csz_idx_0 != 0) {
    int32_T i;
    boolean_T b;
    boolean_T b1;
    b = (a_size != 1);
    b1 = (b_size != 1);
    i = csz_idx_0 - 1;
    for (int32_T k{0}; k <= i; k++) {
      c_data[k] = muDoubleScalarMin(a_data[b * k], b_data[b1 * k]);
    }
  }
  return c_size;
}

} // namespace internal
} // namespace coder

// End of code generation (ixfun.cpp)
