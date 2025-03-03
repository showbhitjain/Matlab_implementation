//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified_terminate.cpp
//
// Code generation for function 'inverseKinematicsOAModified_terminate'
//

// Include files
#include "inverseKinematicsOAModified_terminate.h"
#include "_coder_inverseKinematicsOAModified_mex.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
void inverseKinematicsOAModified_atexit()
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
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void inverseKinematicsOAModified_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (inverseKinematicsOAModified_terminate.cpp)
