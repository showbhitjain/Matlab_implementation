//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "eml_int_forloop_overflow_check.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo mc_emlrtRSI{
    144,                                                           // lineNo
    "eml_find",                                                    // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    382,                                                           // lineNo
    "find_first_indices",                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRTEInfo k_emlrtRTEI{
    81,                                                            // lineNo
    1,                                                             // colNo
    "eml_find",                                                    // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    392,                                                           // lineNo
    1,                                                             // colNo
    "find_first_indices",                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void eml_find(const emlrtStack &sp, const ::coder::array<boolean_T, 2U> &x,
              int32_T i_data[], int32_T i_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  int32_T ii;
  int32_T k;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  k = (x.size(1) >= 1);
  if (k > x.size(1)) {
    emlrtErrorWithMessageIdR2018a(&sp, &k_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  st.site = &mc_emlrtRSI;
  idx = 0;
  i_size[0] = 1;
  i_size[1] = k;
  b_st.site = &nc_emlrtRSI;
  if (x.size(1) > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x.size(1) - 1)) {
    if (x[ii]) {
      idx = 1;
      i_data[0] = ii + 1;
      exitg1 = true;
    } else {
      ii++;
    }
  }
  if (idx > k) {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (k == 1) {
    if (idx == 0) {
      i_size[0] = 1;
      i_size[1] = 0;
    }
  } else {
    i_size[1] = (idx >= 1);
  }
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (find.cpp)
