//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// makeBoundFeasible.h
//
// Code generation for function 'makeBoundFeasible'
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
struct j_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
void makeBoundFeasible(const emlrtStack &sp, array<real_T, 1U> &xk,
                       const j_struct_T &WorkingSet,
                       const array<real_T, 1U> &lb,
                       const array<real_T, 1U> &ub);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (makeBoundFeasible.h)
