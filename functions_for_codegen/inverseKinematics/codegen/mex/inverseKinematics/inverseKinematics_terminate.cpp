//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematics_terminate.cpp
//
// Code generation for function 'inverseKinematics_terminate'
//

// Include files
#include "inverseKinematics_terminate.h"
#include "_coder_inverseKinematics_mex.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
void inverseKinematics_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void inverseKinematics_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (inverseKinematics_terminate.cpp)
