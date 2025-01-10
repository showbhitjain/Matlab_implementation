//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_inverseKinematics_mex.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 10-Nov-2024 04:04:05
//

#ifndef _CODER_INVERSEKINEMATICS_MEX_H
#define _CODER_INVERSEKINEMATICS_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_inverseKinematics_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                          int32_T nrhs, const mxArray *prhs[8]);

#endif
//
// File trailer for _coder_inverseKinematics_mex.h
//
// [EOF]
//
