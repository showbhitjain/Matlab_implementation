//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// orientationTrajectory_mex_mexutil.cpp
//
// Code generation for function 'orientationTrajectory_mex_mexutil'
//

// Include files
#include "orientationTrajectory_mex_mexutil.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace trajectoryGeneration {
void b_error(const emlrtStack &sp, const mxArray *m, emlrtMCInfo &location)
{
  const mxArray *pArray;
  pArray = m;
  emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 0, nullptr, 1, &pArray, "error",
                        true, &location);
}

} // namespace trajectoryGeneration

// End of code generation (orientationTrajectory_mex_mexutil.cpp)
