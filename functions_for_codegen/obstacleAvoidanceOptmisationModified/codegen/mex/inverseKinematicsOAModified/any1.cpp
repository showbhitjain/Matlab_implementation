//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// any1.cpp
//
// Code generation for function 'any1'
//

// Include files
#include "any1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo pb_emlrtRSI{
    16,                                                         // lineNo
    "any",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/any.m" // pathName
};

// Function Definitions
namespace coder {
boolean_T any(const emlrtStack &sp, const array<boolean_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &pb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  b_st.site = &hb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  d_st.site = &jb_emlrtRSI;
  e_st.site = &kb_emlrtRSI;
  y = false;
  f_st.site = &lb_emlrtRSI;
  if (x.size(0) > 2147483646) {
    g_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(g_st);
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x.size(0))) {
    if (x[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

} // namespace coder

// End of code generation (any1.cpp)
