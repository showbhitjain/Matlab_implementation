//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// assignResidualsToXSlack.h
//
// Code generation for function 'assignResidualsToXSlack'
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

struct i_struct_T;

struct g_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
namespace relaxed {
void assignResidualsToXSlack(const emlrtStack &sp, int32_T nVarOrig,
                             j_struct_T &WorkingSet, i_struct_T &b_TrialState,
                             g_struct_T &memspace);

}
} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (assignResidualsToXSlack.h)
