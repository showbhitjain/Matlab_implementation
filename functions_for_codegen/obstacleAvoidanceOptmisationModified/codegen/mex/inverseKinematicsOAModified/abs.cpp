//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// abs.cpp
//
// Code generation for function 'abs'
//

// Include files
#include "abs.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace coder {
int32_T b_abs(const real_T x_data[], int32_T x_size, real_T y_data[])
{
  int32_T y_size;
  y_size = x_size;
  for (int32_T k{0}; k < x_size; k++) {
    y_data[k] = muDoubleScalarAbs(x_data[k]);
  }
  return y_size;
}

} // namespace coder

// End of code generation (abs.cpp)
