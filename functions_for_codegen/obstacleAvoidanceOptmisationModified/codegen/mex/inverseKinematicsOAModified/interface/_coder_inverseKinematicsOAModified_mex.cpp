//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inverseKinematicsOAModified_mex.cpp
//
// Code generation for function '_coder_inverseKinematicsOAModified_mex'
//

// Include files
#include "_coder_inverseKinematicsOAModified_mex.h"
#include "_coder_inverseKinematicsOAModified_api.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_initialize.h"
#include "inverseKinematicsOAModified_terminate.h"
#include "rt_nonfinite.h"
#include <cstring>
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void inverseKinematicsOAModified_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                             int32_T nrhs,
                                             const mxArray *prhs[11])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 11) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 11, 4,
                        27, "inverseKinematicsOAModified");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 27,
                        "inverseKinematicsOAModified");
  }
  // Call the function.
  inverseKinematicsOAModified_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&inverseKinematicsOAModified_atexit);
  // Module initialization.
  inverseKinematicsOAModified_initialize();
  try {
    // Dispatch the entry-point.
    inverseKinematicsOAModified_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    inverseKinematicsOAModified_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_inverseKinematicsOAModified_mex.cpp)
