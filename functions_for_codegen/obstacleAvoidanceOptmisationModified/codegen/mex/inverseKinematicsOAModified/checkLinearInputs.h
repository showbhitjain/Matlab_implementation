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
                         const real_T Aineq_data[], const int32_T Aineq_size[2],
                         const real_T bineq_data[], const int32_T bineq_size[2],
                         const real_T Aeq_data[], const int32_T Aeq_size[2],
                         const real_T beq_data[], const int32_T beq_size[2],
                         const real_T lb_data[], int32_T lb_size,
                         const real_T ub_data[], int32_T ub_size);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkLinearInputs.h)
