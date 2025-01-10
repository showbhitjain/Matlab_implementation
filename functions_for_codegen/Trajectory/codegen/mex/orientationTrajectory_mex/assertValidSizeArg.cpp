//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// assertValidSizeArg.cpp
//
// Code generation for function 'assertValidSizeArg'
//

// Include files
#include "assertValidSizeArg.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo y_emlrtRTEI{
    64,                   // lineNo
    15,                   // colNo
    "assertValidSizeArg", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    49,                   // lineNo
    19,                   // colNo
    "assertValidSizeArg", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
namespace internal {
void assertValidSizeArg(const emlrtStack &sp, const real_T varargin_1[3])
{
  int32_T k;
  boolean_T exitg1;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((varargin_1[k] != varargin_1[k]) ||
        muDoubleScalarIsInf(varargin_1[k])) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &db_emlrtRTEI,
          "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
          "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
          MIN_int32_T, 12, MAX_int32_T);
    } else {
      k++;
    }
  }
  if (!(varargin_1[0] * varargin_1[1] * varargin_1[2] <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&sp, &y_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
}

} // namespace internal
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (assertValidSizeArg.cpp)
