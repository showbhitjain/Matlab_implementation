//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// orientationTrajectory_mex_terminate.cpp
//
// Code generation for function 'orientationTrajectory_mex_terminate'
//

// Include files
#include "orientationTrajectory_mex_terminate.h"
#include "_coder_orientationTrajectory_mex_mex.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void orientationTrajectory_mex_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  trajectoryGeneration::mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

namespace trajectoryGeneration {
void orientationTrajectory_mex_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

} // namespace trajectoryGeneration

// End of code generation (orientationTrajectory_mex_terminate.cpp)
