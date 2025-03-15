//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eye.cpp
//
// Code generation for function 'eye'
//

// Include files
#include "eye.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo rb_emlrtRSI{
    50,                                                           // lineNo
    "eye",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/eye.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    96,                                                           // lineNo
    "eye",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/eye.m" // pathName
};

static emlrtRTEInfo cb_emlrtRTEI{
    94,                                                           // lineNo
    5,                                                            // colNo
    "eye",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/eye.m" // pName
};

// Function Definitions
namespace coder {
void eye(real_T b_I[36])
{
  std::memset(&b_I[0], 0, 36U * sizeof(real_T));
  for (int32_T k{0}; k < 6; k++) {
    b_I[k + 6 * k] = 1.0;
  }
}

void eye(const emlrtStack &sp, int32_T varargin_1, array<real_T, 2U> &b_I)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T loop_ub;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &rb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_I.set_size(&cb_emlrtRTEI, &sp, varargin_1, varargin_1);
  loop_ub = varargin_1 * varargin_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    b_I[i] = 0.0;
  }
  if (varargin_1 > 0) {
    st.site = &sb_emlrtRSI;
    if (varargin_1 > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (loop_ub = 0; loop_ub < varargin_1; loop_ub++) {
      b_I[loop_ub + b_I.size(0) * loop_ub] = 1.0;
    }
  }
}

} // namespace coder

// End of code generation (eye.cpp)
