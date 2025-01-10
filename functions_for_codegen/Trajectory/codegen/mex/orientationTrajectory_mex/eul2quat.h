//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eul2quat.h
//
// Code generation for function 'eul2quat'
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
namespace trajectoryGeneration {
namespace coder {
void eul2quat(const real_T eul_data[], real_T q[4]);

}
} // namespace trajectoryGeneration

// End of code generation (eul2quat.h)
