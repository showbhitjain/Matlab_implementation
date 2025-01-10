//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// diff.cpp
//
// Code generation for function 'diff'
//

// Include files
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo qf_emlrtRSI{
    108,                                                             // lineNo
    "diff",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/diff.m" // pathName
};

static emlrtRSInfo rf_emlrtRSI{
    106,                                                             // lineNo
    "diff",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/diff.m" // pathName
};

static emlrtRTEInfo t_emlrtRTEI{
    51,                                                              // lineNo
    19,                                                              // colNo
    "diff",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/diff.m" // pName
};

static emlrtRTEInfo bd_emlrtRTEI{
    78,                                                              // lineNo
    21,                                                              // colNo
    "diff",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/diff.m" // pName
};

static emlrtRTEInfo cd_emlrtRTEI{
    47,                                                              // lineNo
    13,                                                              // colNo
    "diff",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/diff.m" // pName
};

static emlrtRTEInfo dd_emlrtRTEI{
    37,                                                              // lineNo
    9,                                                               // colNo
    "diff",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/diff.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void diff(const emlrtStack &sp, const ::coder::array<real_T, 2U> &x,
          ::coder::array<real_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T dimSize;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  dimSize = x.size(1);
  if (x.size(1) == 0) {
    y.set_size(&dd_emlrtRTEI, &sp, 1, 0);
  } else {
    int32_T m;
    m = x.size(1) - 1;
    if (muIntScalarMin_sint32(m, 1) < 1) {
      y.set_size(&cd_emlrtRTEI, &sp, 1, 0);
    } else {
      real_T work_data;
      if (x.size(1) == 1) {
        emlrtErrorWithMessageIdR2018a(
            &sp, &t_emlrtRTEI, "Coder:toolbox:autoDimIncompatibility",
            "Coder:toolbox:autoDimIncompatibility", 0);
      }
      y.set_size(&bd_emlrtRTEI, &sp, 1, x.size(1) - 1);
      work_data = x[0];
      st.site = &rf_emlrtRSI;
      if (x.size(1) > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (m = 2; m <= dimSize; m++) {
        real_T d;
        real_T tmp1;
        tmp1 = x[m - 1];
        st.site = &qf_emlrtRSI;
        d = tmp1;
        tmp1 -= work_data;
        work_data = d;
        y[m - 2] = tmp1;
      }
    }
  }
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (diff.cpp)
