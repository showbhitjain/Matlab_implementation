//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeGradLag.h
//
// Code generation for function 'computeGradLag'
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

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
void computeGradLag(const emlrtStack &sp, array<real_T, 1U> &workspace,
                    int32_T ldA, int32_T nVar, const array<real_T, 1U> &grad,
                    int32_T mIneq, const array<real_T, 1U> &AineqTrans,
                    int32_T mEq, const array<real_T, 1U> &AeqTrans,
                    const array<int32_T, 1U> &finiteFixed, int32_T mFixed,
                    const array<int32_T, 1U> &finiteLB, int32_T mLB,
                    const array<int32_T, 1U> &finiteUB, int32_T mUB,
                    const real_T lambda_data[], int32_T lambda_size);

void computeGradLag(const emlrtStack &sp, array<real_T, 2U> &workspace,
                    int32_T ldA, int32_T nVar, const array<real_T, 1U> &grad,
                    int32_T mIneq, const array<real_T, 1U> &AineqTrans,
                    int32_T mEq, const array<real_T, 1U> &AeqTrans,
                    const array<int32_T, 1U> &finiteFixed, int32_T mFixed,
                    const array<int32_T, 1U> &finiteLB, int32_T mLB,
                    const array<int32_T, 1U> &finiteUB, int32_T mUB,
                    const real_T lambda_data[], int32_T lambda_size);

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeGradLag.h)
