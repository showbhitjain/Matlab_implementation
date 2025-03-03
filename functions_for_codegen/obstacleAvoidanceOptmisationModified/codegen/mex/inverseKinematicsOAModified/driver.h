//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver.h
//
// Code generation for function 'driver'
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

struct struct_T;

namespace coder {
namespace internal {
class i_stickyStruct;

}
} // namespace coder
struct l_struct_T;

struct h_struct_T;

struct d_struct_T;

struct e_struct_T;

struct f_struct_T;

struct g_struct_T;

struct i_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void driver(const emlrtStack &sp, array<real_T, 2U> &Hessian,
            const array<real_T, 2U> &bineq, const real_T beq_data[],
            const array<real_T, 2U> &lb, const array<real_T, 2U> &ub,
            j_struct_T &b_TrialState, struct_T &b_MeritFunction,
            const ::coder::internal::i_stickyStruct &FcnEvaluator,
            l_struct_T &FiniteDifferences, h_struct_T &memspace,
            d_struct_T &WorkingSet, e_struct_T &b_QRManager,
            f_struct_T &b_CholManager, g_struct_T &QPObjective,
            const array<real_T, 1U> &fscales_lineq_constraint,
            const i_struct_T &runTimeOptions);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver.h)
