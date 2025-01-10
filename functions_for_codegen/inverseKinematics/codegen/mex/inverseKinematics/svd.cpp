//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// svd.cpp
//
// Code generation for function 'svd'
//

// Include files
#include "svd.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo kd_emlrtRSI{
    14,                                                            // lineNo
    "svd",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/svd.m" // pathName
};

static emlrtRSInfo ld_emlrtRSI{
    18,                                                            // lineNo
    "svd",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/svd.m" // pathName
};

static emlrtRSInfo
    md_emlrtRSI{
        29,             // lineNo
        "anyNonFinite", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
        "anyNonFinite.m" // pathName
    };

static emlrtRSInfo nd_emlrtRSI{
    44,          // lineNo
    "vAllOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    103,                  // lineNo
    "flatVectorAllOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    28,                                                               // lineNo
    "svd",                                                            // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/svd.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    107,                                                              // lineNo
    "callLAPACK",                                                     // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/svd.m" // pathName
};

static emlrtRSInfo
    rd_emlrtRSI{
        31,       // lineNo
        "xgesvd", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" // pathName
    };

static emlrtRSInfo
    sd_emlrtRSI{
        205,            // lineNo
        "ceval_xgesvd", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" // pathName
    };

static emlrtRTEInfo n_emlrtRTEI{
    111,                                                              // lineNo
    5,                                                                // colNo
    "callLAPACK",                                                     // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/svd.m" // pName
};

static emlrtRTEInfo
    mb_emlrtRTEI{
        31,       // lineNo
        33,       // colNo
        "xgesvd", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" // pName
    };

// Function Definitions
namespace coder {
int32_T svd(const emlrtStack &sp, const array<real_T, 2U> &A, real_T U_data[])
{
  static const char_T fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 's', 'v', 'd'};
  array<real_T, 2U> b_A;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T superb_data[5];
  int32_T U_size;
  int32_T m;
  int32_T n;
  boolean_T p;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &kd_emlrtRSI;
  b_st.site = &md_emlrtRSI;
  c_st.site = &nd_emlrtRSI;
  m = A.size(0) * A.size(1);
  p = true;
  d_st.site = &od_emlrtRSI;
  if (m > 2147483646) {
    e_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(e_st);
  }
  for (n = 0; n < m; n++) {
    if ((!p) || (muDoubleScalarIsInf(A[n]) || muDoubleScalarIsNaN(A[n]))) {
      p = false;
    }
  }
  if (p) {
    st.site = &ld_emlrtRSI;
    if ((A.size(0) == 0) || (A.size(1) == 0)) {
      U_size = 0;
    } else {
      ptrdiff_t info_t;
      b_st.site = &pd_emlrtRSI;
      c_st.site = &qd_emlrtRSI;
      d_st.site = &rd_emlrtRSI;
      b_A.set_size(&mb_emlrtRTEI, &d_st, A.size(0), A.size(1));
      for (n = 0; n < m; n++) {
        b_A[n] = A[n];
      }
      m = A.size(0);
      n = A.size(1);
      U_size = muIntScalarMin_sint32(n, m);
      info_t = LAPACKE_dgesvd(
          102, 'N', 'N', (ptrdiff_t)A.size(0), (ptrdiff_t)A.size(1),
          &(b_A.data())[0], (ptrdiff_t)A.size(0), &U_data[0], nullptr,
          (ptrdiff_t)1, nullptr, (ptrdiff_t)1, &superb_data[0]);
      e_st.site = &sd_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &m_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&e_st, &l_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)info_t);
        }
      }
      if ((int32_T)info_t > 0) {
        emlrtErrorWithMessageIdR2018a(&b_st, &n_emlrtRTEI,
                                      "Coder:MATLAB:svd_NoConvergence",
                                      "Coder:MATLAB:svd_NoConvergence", 0);
      }
    }
  } else {
    m = static_cast<int32_T>(muDoubleScalarMin(static_cast<real_T>(A.size(0)),
                                               static_cast<real_T>(A.size(1))));
    U_size = static_cast<int32_T>(muDoubleScalarMin(
        static_cast<real_T>(A.size(0)), static_cast<real_T>(A.size(1))));
    for (n = 0; n < m; n++) {
      U_data[n] = rtNaN;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return U_size;
}

} // namespace coder

// End of code generation (svd.cpp)
