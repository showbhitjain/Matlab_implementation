//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkLinearInputs.h
//
// Code generation for function 'checkLinearInputs'
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
namespace validate {
real_T checkLinearInputs(const emlrtStack &sp, int32_T nVar,
                         const array<real_T, 2U> &Aineq,
                         const array<real_T, 2U> &bineq,
                         const array<real_T, 2U> &Aeq, const real_T beq_data[],
                         const int32_T beq_size[2], const array<real_T, 2U> &lb,
                         const array<real_T, 2U> &ub);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkLinearInputs.h)
