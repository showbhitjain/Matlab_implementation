//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkX0.cpp
//
// Code generation for function 'checkX0'
//

// Include files
#include "checkX0.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo fb_emlrtRSI{
    1,         // lineNo
    "checkX0", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkX0.p" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    16,                                                         // lineNo
    "all",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/all.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    57,         // lineNo
    "allOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    106,                   // lineNo
    "applyToMultipleDims", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    56,                                                             // lineNo
    "@(x)coder.internal.allOrAny(op,x,coder.internal.indexInt(1))", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    143,        // lineNo
    "allOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

static emlrtRTEInfo d_emlrtRTEI{
    1,         // lineNo
    1,         // colNo
    "checkX0", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkX0.p" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    14,                                                                // lineNo
    1,                                                                 // colNo
    "isfinite",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/isfinite.m" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace validate {
void checkX0(const emlrtStack &sp, const array<real_T, 1U> &x0)
{
  array<boolean_T, 1U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  int32_T loop_ub;
  boolean_T exitg1;
  boolean_T y;
  st.prev = &sp;
  st.tls = sp.tls;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (x0.size(0) == 0) {
    emlrtErrorWithMessageIdR2018a(&sp, &d_emlrtRTEI,
                                  "optimlib_codegen:common:EmptyX",
                                  "optimlib_codegen:common:EmptyX", 0);
  }
  b.set_size(&y_emlrtRTEI, &sp, x0.size(0));
  loop_ub = x0.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    b[i] = ((!muDoubleScalarIsInf(x0[i])) && (!muDoubleScalarIsNaN(x0[i])));
  }
  st.site = &fb_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  d_st.site = &ib_emlrtRSI;
  e_st.site = &jb_emlrtRSI;
  f_st.site = &kb_emlrtRSI;
  y = true;
  g_st.site = &lb_emlrtRSI;
  if (b.size(0) > 2147483646) {
    h_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(h_st);
  }
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= b.size(0))) {
    if (!b[loop_ub - 1]) {
      y = false;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }
  if (!y) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &d_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
        "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 2, "x0");
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace validate
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkX0.cpp)
