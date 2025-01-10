//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// validateattributes.cpp
//
// Code generation for function 'validateattributes'
//

// Include files
#include "validateattributes.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void validateattributes(const emlrtStack &sp, const real_T a[2])
{
  emlrtStack st;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(a[k])) && (!muDoubleScalarIsNaN(a[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rottraj:expectedFinite", 3, 4, 12, "timeInterval");
  }
  st.site = &ib_emlrtRSI;
  if (!(a[0] < a[1])) {
    emlrtErrorWithMessageIdR2018a(
        &st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:rottraj:expectedIncreasing", 3, 4, 12, "timeInterval");
  }
  st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(a[k] < 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:rottraj:expectedNonnegative", 3, 4, 12, "timeInterval");
  }
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (validateattributes.cpp)
