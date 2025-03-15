//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// IndexOfDependentEq_.h
//
// Code generation for function 'IndexOfDependentEq_'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
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
void IndexOfDependentEq_(const emlrtStack &sp, array<int32_T, 1U> &depIdx,
                         int32_T mFixed, int32_T nDep, e_struct_T &qrmanager,
                         int32_T mRows, int32_T nCols);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (IndexOfDependentEq_.h)
