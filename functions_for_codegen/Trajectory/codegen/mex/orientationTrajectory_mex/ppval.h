//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ppval.h
//
// Code generation for function 'ppval'
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
namespace trajectoryGeneration {
struct struct_T;

struct b_struct_T;

struct c_struct_T;

struct d_struct_T;

} // namespace trajectoryGeneration

// Function Declarations
namespace trajectoryGeneration {
namespace coder {
void b_ppval(const emlrtStack &sp, const ::coder::array<real_T, 2U> &pp_breaks,
             const ::coder::array<real_T, 3U> &pp_coefs,
             const ::coder::array<real_T, 2U> &x,
             ::coder::array<real_T, 2U> &v);

void ppval(const emlrtStack &sp, const struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v);

void ppval(const emlrtStack &sp, const b_struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v);

void ppval(const emlrtStack &sp, const c_struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v);

void ppval(const emlrtStack &sp, const d_struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v);

void ppval(const emlrtStack &sp, const ::coder::array<real_T, 2U> &pp_breaks,
           const ::coder::array<real_T, 3U> &pp_coefs,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v);

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (ppval.h)
