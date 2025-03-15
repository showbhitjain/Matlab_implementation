//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeNumDependentEq_.h
//
// Code generation for function 'ComputeNumDependentEq_'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct e_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int32_T ComputeNumDependentEq_(const emlrtStack &sp, e_struct_T &qrmanager,
                               const real_T beqf_data[], int32_T mConstr,
                               int32_T nVar);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (ComputeNumDependentEq_.h)
