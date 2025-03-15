//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqp3.cpp
//
// Code generation for function 'xgeqp3'
//

// Include files
#include "xgeqp3.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo
    fc_emlrtRSI{
        63,       // lineNo
        "xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    gc_emlrtRSI{
        158,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    hc_emlrtRSI{
        154,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    ic_emlrtRSI{
        151,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    jc_emlrtRSI{
        148,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    kc_emlrtRSI{
        143,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    lc_emlrtRSI{
        141,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    mc_emlrtRSI{
        138,            // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRSInfo
    nc_emlrtRSI{
        98,             // lineNo
        "ceval_xgeqp3", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pathName
    };

static emlrtRTEInfo
    nb_emlrtRTEI{
        92,       // lineNo
        22,       // colNo
        "xgeqp3", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pName
    };

static emlrtRTEInfo
    ob_emlrtRTEI{
        105,      // lineNo
        1,        // colNo
        "xgeqp3", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pName
    };

static emlrtRTEInfo
    pb_emlrtRTEI{
        97,       // lineNo
        5,        // colNo
        "xgeqp3", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqp3.m" // pName
    };

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void xgeqp3(const emlrtStack &sp, array<real_T, 2U> &A, int32_T m, int32_T n,
            array<int32_T, 1U> &jpvt, array<real_T, 1U> &tau)
{
  static const char_T fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 'q', 'p', '3'};
  array<ptrdiff_t, 1U> jpvt_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ma;
  int32_T minmana;
  int32_T na;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &fc_emlrtRSI;
  ma = A.size(0);
  na = A.size(1);
  minmana = muIntScalarMin_sint32(ma, na);
  tau.set_size(&nb_emlrtRTEI, &st, minmana);
  if ((m < 1) || (n < 1)) {
    tau.set_size(&pb_emlrtRTEI, &st, minmana);
    for (int32_T k{0}; k < minmana; k++) {
      tau[k] = 0.0;
    }
    b_st.site = &nc_emlrtRSI;
    if (n > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    na = (n / 4) << 2;
    ma = na - 4;
    for (int32_T k{0}; k <= ma; k += 4) {
      __m128i r;
      r = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32(k),
                                      _mm_loadu_si128((const __m128i *)&iv[0])),
                        _mm_set1_epi32(1));
      _mm_storeu_si128((__m128i *)&jpvt[k], r);
    }
    for (int32_T k{na}; k < n; k++) {
      jpvt[k] = k + 1;
    }
  } else {
    ptrdiff_t info_t;
    boolean_T p;
    jpvt_t.set_size(&ob_emlrtRTEI, &st, jpvt.size(0));
    na = jpvt.size(0);
    for (int32_T k{0}; k < na; k++) {
      jpvt_t[k] = (ptrdiff_t)jpvt[k];
    }
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)m, (ptrdiff_t)n, &(A.data())[0],
                            (ptrdiff_t)A.size(0), &(jpvt_t.data())[0],
                            &(tau.data())[0]);
    b_st.site = &mc_emlrtRSI;
    if ((int32_T)info_t != 0) {
      p = true;
      if ((int32_T)info_t != -4) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)info_t);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      b_st.site = &lc_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (na = 0; na < n; na++) {
        b_st.site = &kc_emlrtRSI;
        if (m > 2147483646) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        for (int32_T k{0}; k < m; k++) {
          A[na * ma + k] = rtNaN;
        }
      }
      na = muIntScalarMin_sint32(m, n) + 1;
      b_st.site = &jc_emlrtRSI;
      for (int32_T k{0}; k <= na - 2; k++) {
        tau[k] = rtNaN;
      }
      b_st.site = &ic_emlrtRSI;
      if ((na <= minmana) && (minmana > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T k{na}; k <= minmana; k++) {
        tau[k - 1] = 0.0;
      }
      b_st.site = &hc_emlrtRSI;
      na = (n / 4) << 2;
      ma = na - 4;
      for (int32_T k{0}; k <= ma; k += 4) {
        __m128i r;
        r = _mm_add_epi32(
            _mm_add_epi32(_mm_set1_epi32(k),
                          _mm_loadu_si128((const __m128i *)&iv[0])),
            _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&jpvt[k], r);
      }
      for (int32_T k{na}; k < n; k++) {
        jpvt[k] = k + 1;
      }
    } else {
      b_st.site = &gc_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T k{0}; k < n; k++) {
        jpvt[k] = (int32_T)jpvt_t[k];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xgeqp3.cpp)
