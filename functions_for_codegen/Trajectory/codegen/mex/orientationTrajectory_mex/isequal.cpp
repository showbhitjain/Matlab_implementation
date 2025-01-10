//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// isequal.cpp
//
// Code generation for function 'isequal'
//

// Include files
#include "isequal.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
boolean_T isequal(const real_T varargin_1[2], const real_T varargin_2[2],
                  const real_T varargin_3[2], const real_T varargin_4[2])
{
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (b_p) {
    b_p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!(varargin_1[k] == varargin_3[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (b_p) {
      b_p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (!(varargin_1[k] == varargin_4[k])) {
          b_p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (b_p) {
        p = true;
      }
    }
  }
  return p;
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (isequal.cpp)
