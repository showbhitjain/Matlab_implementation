//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// BFGSUpdate.h
//
// Code generation for function 'BFGSUpdate'
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
boolean_T BFGSUpdate(int32_T nvar, array<real_T, 2U> &Bk,
                     const array<real_T, 1U> &sk, array<real_T, 1U> &yk,
                     array<real_T, 2U> &workspace);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (BFGSUpdate.h)
