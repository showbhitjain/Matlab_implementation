//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ixfun.cpp
//
// Code generation for function 'ixfun'
//

// Include files
#include "ixfun.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRTEInfo b_emlrtRTEI{
    225,          // lineNo
    23,           // colNo
    "expand_min", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/ixfun.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    225,          // lineNo
    23,           // colNo
    "expand_max", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/ixfun.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    234,     // lineNo
    20,      // colNo
    "ixfun", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/ixfun.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void expand_max(const emlrtStack &sp, const array<real_T, 1U> &a,
                const array<real_T, 1U> &b, array<real_T, 1U> &c)
{
  int32_T sak;
  int32_T sbk;
  sak = a.size(0);
  sbk = b.size(0);
  if (b.size(0) == 1) {
    sak = a.size(0);
  } else if (a.size(0) == 1) {
    sak = b.size(0);
  } else {
    sak = muIntScalarMin_sint32(sak, sbk);
    if (a.size(0) != b.size(0)) {
      emlrtErrorWithMessageIdR2018a(&sp, &c_emlrtRTEI,
                                    "MATLAB:sizeDimensionsMustMatch",
                                    "MATLAB:sizeDimensionsMustMatch", 0);
    }
  }
  c.set_size(&pc_emlrtRTEI, &sp, sak);
  if (sak != 0) {
    boolean_T b1;
    boolean_T b_b;
    b_b = (a.size(0) != 1);
    b1 = (b.size(0) != 1);
    sak--;
    for (sbk = 0; sbk <= sak; sbk++) {
      c[sbk] = muDoubleScalarMax(a[b_b * sbk], b[b1 * sbk]);
    }
  }
}

void expand_min(const emlrtStack &sp, const array<real_T, 1U> &a,
                const array<real_T, 1U> &b, array<real_T, 1U> &c)
{
  int32_T sak;
  int32_T sbk;
  sak = a.size(0);
  sbk = b.size(0);
  if (b.size(0) == 1) {
    sak = a.size(0);
  } else if (a.size(0) == 1) {
    sak = b.size(0);
  } else {
    sak = muIntScalarMin_sint32(sak, sbk);
    if (a.size(0) != b.size(0)) {
      emlrtErrorWithMessageIdR2018a(&sp, &b_emlrtRTEI,
                                    "MATLAB:sizeDimensionsMustMatch",
                                    "MATLAB:sizeDimensionsMustMatch", 0);
    }
  }
  c.set_size(&pc_emlrtRTEI, &sp, sak);
  if (sak != 0) {
    boolean_T b1;
    boolean_T b_b;
    b_b = (a.size(0) != 1);
    b1 = (b.size(0) != 1);
    sak--;
    for (sbk = 0; sbk <= sak; sbk++) {
      c[sbk] = muDoubleScalarMin(a[b_b * sbk], b[b1 * sbk]);
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (ixfun.cpp)
