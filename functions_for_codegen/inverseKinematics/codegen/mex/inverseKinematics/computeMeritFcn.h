//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeMeritFcn.h
//
// Code generation for function 'computeMeritFcn'
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
namespace fminconsqp {
namespace MeritFunction {
real_T computeMeritFcn(real_T obj_penaltyParam, real_T fval,
                       const real_T Ceq_workspace_data[], int32_T mEq,
                       boolean_T evalWellDefined);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeMeritFcn.h)
