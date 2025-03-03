//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct2.h
//
// Code generation for function 'factoryConstruct2'
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
struct d_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void factoryConstruct(const emlrtStack &sp, int32_T mIneqMax, int32_T mEqMax,
                      int32_T nVar, int32_T nVarMax, int32_T mConstrMax,
                      d_struct_T &obj);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct2.h)
