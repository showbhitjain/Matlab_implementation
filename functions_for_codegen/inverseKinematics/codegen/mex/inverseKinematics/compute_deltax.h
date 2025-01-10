//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compute_deltax.h
//
// Code generation for function 'compute_deltax'
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
struct i_struct_T;

struct g_struct_T;

struct d_struct_T;

struct e_struct_T;

struct f_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_deltax(const emlrtStack &sp, const array<real_T, 2U> &H,
                    i_struct_T &solution, g_struct_T &memspace,
                    const d_struct_T &qrmanager, e_struct_T &cholmanager,
                    const f_struct_T &objective, boolean_T alwaysPositiveDef);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compute_deltax.h)
