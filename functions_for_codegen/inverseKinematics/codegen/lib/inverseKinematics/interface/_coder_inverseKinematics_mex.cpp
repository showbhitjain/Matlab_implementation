//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_inverseKinematics_mex.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 10-Nov-2024 04:04:05
//

// Include Files
#include "_coder_inverseKinematics_mex.h"
#include "_coder_inverseKinematics_api.h"

// Function Definitions
//
// Arguments    : int32_T nlhs
//                mxArray *plhs[]
//                int32_T nrhs
//                const mxArray *prhs[]
// Return Type  : void
//
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&inverseKinematics_atexit);
  // Module initialization.
  inverseKinematics_initialize();
  // Dispatch the entry-point.
  unsafe_inverseKinematics_mexFunction(nlhs, plhs, nrhs, prhs);
  // Module termination.
  inverseKinematics_terminate();
}

//
// Arguments    : void
// Return Type  : emlrtCTX
//
emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

//
// Arguments    : int32_T nlhs
//                mxArray *plhs[2]
//                int32_T nrhs
//                const mxArray *prhs[8]
// Return Type  : void
//
void unsafe_inverseKinematics_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                          int32_T nrhs, const mxArray *prhs[8])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *b_prhs[8];
  const mxArray *outputs[2];
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        17, "inverseKinematics");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "inverseKinematics");
  }
  // Call the function.
  for (int32_T i{0}; i < 8; i++) {
    b_prhs[i] = prhs[i];
  }
  inverseKinematics_api(b_prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

//
// File trailer for _coder_inverseKinematics_mex.cpp
//
// [EOF]
//
