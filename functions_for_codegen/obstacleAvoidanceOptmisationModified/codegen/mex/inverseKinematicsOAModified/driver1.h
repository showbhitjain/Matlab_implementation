//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver1.h
//
// Code generation for function 'driver1'
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

struct d_struct_T;

struct e_struct_T;

struct f_struct_T;

struct g_struct_T;

struct k_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void driver(const emlrtStack &sp, const array<real_T, 2U> &H,
            const array<real_T, 1U> &f, j_struct_T &solution,
            h_struct_T &memspace, d_struct_T &workingset, e_struct_T &qrmanager,
            f_struct_T &cholmanager, g_struct_T &objective, k_struct_T &options,
            int32_T runTimeOptions_MaxIterations);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver1.h)
