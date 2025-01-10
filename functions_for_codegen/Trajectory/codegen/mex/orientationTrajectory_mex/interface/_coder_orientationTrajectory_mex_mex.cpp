//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_orientationTrajectory_mex_mex.cpp
//
// Code generation for function '_coder_orientationTrajectory_mex_mex'
//

// Include files
#include "_coder_orientationTrajectory_mex_mex.h"
#include "_coder_orientationTrajectory_mex_api.h"
#include "orientationTrajectory.h"
#include "orientationTrajectory_mex_data.h"
#include "orientationTrajectory_mex_initialize.h"
#include "orientationTrajectory_mex_terminate.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static const char_T *emlrtEntryPoints[2]{"orientationTrajectory",
                                           "positionTrajectory"};
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexAtExit(&orientationTrajectory_mex_atexit);
  emlrtLoadMATLABLibrary("sys/os/glnxa64/libiomp5.so");
  // Initialize the memory manager.
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&orientationTrajectory_nestLockGlobal);
  // Module initialization.
  trajectoryGeneration::orientationTrajectory_mex_initialize();
  st.tls = emlrtRootTLSGlobal;
  try {
    // Dispatch the entry-point.
    switch (emlrtGetEntryPointIndexR2016a(
        &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 2)) {
    case 0:
      orientationTrajectory_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    case 1:
      positionTrajectory_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
      break;
    }
    // Module termination.
    trajectoryGeneration::orientationTrajectory_mex_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&orientationTrajectory_nestLockGlobal);
  } catch (...) {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&orientationTrajectory_nestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

void orientationTrajectory_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                       int32_T nrhs, const mxArray *prhs[4])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        21, "orientationTrajectory");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 21,
                        "orientationTrajectory");
  }
  // Call the function.
  trajectoryGeneration::orientationTrajectory_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void positionTrajectory_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                    int32_T nrhs, const mxArray *prhs[6])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        18, "positionTrajectory");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "positionTrajectory");
  }
  // Call the function.
  trajectoryGeneration::positionTrajectory_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

namespace trajectoryGeneration {
emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                           &emlrtLockerFunction, omp_get_num_procs(),
                           (void *)&emlrtExceptionBridge, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

} // namespace trajectoryGeneration

// End of code generation (_coder_orientationTrajectory_mex_mex.cpp)
