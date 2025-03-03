//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeLinearResiduals.h
//
// Code generation for function 'computeLinearResiduals'
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
namespace internal {
void computeLinearResiduals(const emlrtStack &sp, const array<real_T, 1U> &x,
                            int32_T nVar, array<real_T, 1U> &workspaceIneq,
                            int32_T mLinIneq, const array<real_T, 1U> &AineqT,
                            const array<real_T, 2U> &bineq, int32_T ldAi,
                            real_T workspaceEq_data[],
                            int32_T &workspaceEq_size, int32_T mLinEq,
                            const array<real_T, 1U> &AeqT,
                            const real_T beq_data[], int32_T ldAe);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeLinearResiduals.h)
