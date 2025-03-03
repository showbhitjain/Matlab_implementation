//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct1.h
//
// Code generation for function 'factoryConstruct1'
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
namespace coder {
class anonymous_function;

}
struct l_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const emlrtStack &sp, const anonymous_function &objfun,
                      int32_T nVar, const array<real_T, 2U> &lb,
                      const array<real_T, 2U> &ub, l_struct_T &obj);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct1.h)
