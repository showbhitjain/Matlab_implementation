//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// evalObjAndConstrAndDerivatives.h
//
// Code generation for function 'evalObjAndConstrAndDerivatives'
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
namespace internal {
class i_stickyStruct;

}
} // namespace coder

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace ObjNonlinEvaluator {
real_T
evalObjAndConstrAndDerivatives(const emlrtStack &sp,
                               const ::coder::internal::i_stickyStruct &obj,
                               const array<real_T, 1U> &x, int32_T &status);

}
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (evalObjAndConstrAndDerivatives.h)
