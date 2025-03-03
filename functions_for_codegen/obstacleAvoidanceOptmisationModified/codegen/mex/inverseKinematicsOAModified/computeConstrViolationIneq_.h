//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeConstrViolationIneq_.h
//
// Code generation for function 'computeConstrViolationIneq_'
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

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace MeritFunction {
real_T computeConstrViolationIneq_(const emlrtStack &sp, int32_T mIneq,
                                   const array<real_T, 1U> &ineq_workspace);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeConstrViolationIneq_.h)
