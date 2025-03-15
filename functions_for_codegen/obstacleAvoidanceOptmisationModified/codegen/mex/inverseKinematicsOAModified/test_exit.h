//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// test_exit.h
//
// Code generation for function 'test_exit'
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
struct struct_T;

struct d_struct_T;

struct j_struct_T;

struct b_struct_T;

struct h_struct_T;

struct e_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
void b_test_exit(const emlrtStack &sp, b_struct_T &Flags, h_struct_T &memspace,
                 struct_T &b_MeritFunction,
                 int32_T fscales_lineq_constraint_size,
                 const d_struct_T &WorkingSet, j_struct_T &b_TrialState,
                 e_struct_T &b_QRManager, const real_T lb_data[],
                 int32_T lb_size, const real_T ub_data[], int32_T ub_size,
                 int32_T c_runTimeOptions_MaxFunctionEva);

boolean_T test_exit(const emlrtStack &sp, struct_T &b_MeritFunction,
                    int32_T fscales_lineq_constraint_size,
                    const d_struct_T &WorkingSet, j_struct_T &b_TrialState,
                    const real_T lb_data[], int32_T lb_size,
                    const real_T ub_data[], int32_T ub_size,
                    int32_T c_runTimeOptions_MaxFunctionEva,
                    boolean_T &Flags_fevalOK, boolean_T &Flags_done,
                    boolean_T &Flags_stepAccepted,
                    boolean_T &Flags_failedLineSearch, int32_T &Flags_stepType);

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (test_exit.h)
