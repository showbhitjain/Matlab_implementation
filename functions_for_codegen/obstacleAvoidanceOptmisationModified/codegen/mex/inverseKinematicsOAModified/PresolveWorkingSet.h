//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// PresolveWorkingSet.h
//
// Code generation for function 'PresolveWorkingSet'
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

// Type Declarations
struct j_struct_T;

struct h_struct_T;

struct d_struct_T;

struct e_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void PresolveWorkingSet(const emlrtStack &sp, j_struct_T &solution,
                        h_struct_T &memspace, d_struct_T &workingset,
                        e_struct_T &qrmanager);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (PresolveWorkingSet.h)
