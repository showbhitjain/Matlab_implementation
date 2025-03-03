//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linesearch.h
//
// Code generation for function 'linesearch'
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

namespace coder {
namespace internal {
class i_stickyStruct;

}
} // namespace coder

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
real_T linesearch(const emlrtStack &sp, boolean_T &evalWellDefined,
                  const array<real_T, 2U> &bineq, const real_T beq_data[],
                  int32_T WorkingSet_nVar, int32_T WorkingSet_ldA,
                  const array<real_T, 1U> &WorkingSet_Aineq,
                  const array<real_T, 1U> &WorkingSet_Aeq,
                  j_struct_T &b_TrialState, real_T MeritFunction_penaltyParam,
                  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus,
                  real_T MeritFunction_phiFullStep,
                  const ::coder::internal::i_stickyStruct &FcnEvaluator,
                  boolean_T socTaken, int32_T c_runTimeOptions_MaxFunctionEva,
                  int32_T &exitflag);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (linesearch.h)
