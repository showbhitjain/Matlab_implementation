//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkStoppingAndUpdateFval.h
//
// Code generation for function 'checkStoppingAndUpdateFval'
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

struct h_struct_T;

struct g_struct_T;

struct d_struct_T;

struct e_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkStoppingAndUpdateFval(
    const emlrtStack &sp, int32_T &activeSetChangeID,
    const array<real_T, 1U> &f, j_struct_T &solution, h_struct_T &memspace,
    const g_struct_T &objective, d_struct_T &workingset, e_struct_T &qrmanager,
    real_T options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations,
    boolean_T updateFval);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkStoppingAndUpdateFval.h)
