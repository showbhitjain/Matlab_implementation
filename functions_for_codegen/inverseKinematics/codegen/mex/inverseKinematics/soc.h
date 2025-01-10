//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// soc.h
//
// Code generation for function 'soc'
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

struct j_struct_T;

struct d_struct_T;

struct e_struct_T;

struct f_struct_T;

struct k_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
boolean_T soc(const emlrtStack &sp, const array<real_T, 2U> &Hessian,
              const array<real_T, 1U> &grad, i_struct_T &b_TrialState,
              g_struct_T &memspace, j_struct_T &WorkingSet,
              d_struct_T &b_QRManager, e_struct_T &b_CholManager,
              f_struct_T &QPObjective, const k_struct_T &qpoptions);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (soc.h)
