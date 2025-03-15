//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xgeqrf.cpp
//
// Code generation for function 'xgeqrf'
//

// Include files
#include "xgeqrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    jg_emlrtRSI{
        27,       // lineNo
        "xgeqrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pathName
    };

static emlrtRSInfo
    kg_emlrtRSI{
        102,            // lineNo
        "ceval_xgeqrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pathName
    };

static emlrtRSInfo
    lg_emlrtRSI{
        99,             // lineNo
        "ceval_xgeqrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pathName
    };

static emlrtRSInfo
    mg_emlrtRSI{
        94,             // lineNo
        "ceval_xgeqrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pathName
    };

static emlrtRSInfo
    ng_emlrtRSI{
        93,             // lineNo
        "ceval_xgeqrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pathName
    };

static emlrtRSInfo
    og_emlrtRSI{
        91,             // lineNo
        "ceval_xgeqrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pathName
    };

static emlrtRTEInfo
    yb_emlrtRTEI{
        73,       // lineNo
        22,       // colNo
        "xgeqrf", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pName
    };

static emlrtRTEInfo
    ac_emlrtRTEI{
        75,       // lineNo
        5,        // colNo
        "xgeqrf", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgeqrf.m" // pName
    };

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
void xgeqrf(const emlrtStack &sp, array<real_T, 2U> &A, int32_T m, int32_T n,
            array<real_T, 1U> &tau)
{
  static const char_T fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 'q', 'r', 'f'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ma;
  int32_T minmana;
  int32_T na;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &jg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  ma = A.size(0);
  na = A.size(1);
  minmana = muIntScalarMin_sint32(ma, na);
  tau.set_size(&yb_emlrtRTEI, &st, minmana);
  if ((m == 0) || (n == 0)) {
    tau.set_size(&ac_emlrtRTEI, &st, minmana);
    for (na = 0; na < minmana; na++) {
      tau[na] = 0.0;
    }
  } else {
    ptrdiff_t info_t;
    boolean_T p;
    info_t = LAPACKE_dgeqrf(102, (ptrdiff_t)m, (ptrdiff_t)n, &(A.data())[0],
                            (ptrdiff_t)A.size(0), &(tau.data())[0]);
    b_st.site = &og_emlrtRSI;
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
      b_st.site = &ng_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (na = 0; na < n; na++) {
        b_st.site = &mg_emlrtRSI;
        if (m > 2147483646) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        for (int32_T i{0}; i < m; i++) {
          A[na * ma + i] = rtNaN;
        }
      }
      na = muIntScalarMin_sint32(m, n);
      b_st.site = &lg_emlrtRSI;
      for (int32_T i{0}; i < na; i++) {
        tau[i] = rtNaN;
      }
      ma = na + 1;
      b_st.site = &kg_emlrtRSI;
      if ((na + 1 <= minmana) && (minmana > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T i{ma}; i <= minmana; i++) {
        tau[i - 1] = 0.0;
      }
    }
  }
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xgeqrf.cpp)
