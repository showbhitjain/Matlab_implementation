//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inv.cpp
//
// Code generation for function 'inv'
//

// Include files
#include "inv.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_mexutil.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgetrf.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ke_emlrtRSI{
    21,                                                            // lineNo
    "inv",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/inv.m" // pathName
};

static emlrtRSInfo le_emlrtRSI{
    22,                                                            // lineNo
    "inv",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/inv.m" // pathName
};

static emlrtRSInfo me_emlrtRSI{
    173,                                                           // lineNo
    "invNxN",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/inv.m" // pathName
};

static emlrtRSInfo ne_emlrtRSI{
    190,                                                           // lineNo
    "invNxN",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/inv.m" // pathName
};

static emlrtRSInfo
    oe_emlrtRSI{
        59,      // lineNo
        "xtrsm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xtrsm.m" // pathName
    };

static emlrtRSInfo qe_emlrtRSI{
    42,                                                            // lineNo
    "checkcond",                                                   // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/inv.m" // pathName
};

static emlrtRSInfo re_emlrtRSI{
    46,                                                            // lineNo
    "checkcond",                                                   // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/inv.m" // pathName
};

static emlrtMCInfo c_emlrtMCI{
    53,        // lineNo
    19,        // colNo
    "flt2str", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/flt2str.m" // pName
};

static emlrtRSInfo nj_emlrtRSI{
    53,        // lineNo
    "flt2str", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/flt2str.m" // pathName
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14]);

static const mxArray *b_sprintf(const emlrtStack &sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo &location);

static void emlrt_marshallIn(const emlrtStack &sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[14]);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[14]);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2]{1, 14};
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "char", false, 2U,
                          (const void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtConstCTX)&sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static const mxArray *b_sprintf(const emlrtStack &sp, const mxArray *m1,
                                const mxArray *m2, emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 2, &pArrays[0],
                               "sprintf", true, &location);
}

static void emlrt_marshallIn(const emlrtStack &sp,
                             const mxArray *a__output_of_sprintf_,
                             const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[14])
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

namespace coder {
void inv(const emlrtStack &sp, const real_T x[36], real_T y[36])
{
  static const int32_T b_iv[2]{1, 6};
  static const char_T rfmt[6]{'%', '1', '4', '.', '6', 'e'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  real_T b_x[36];
  real_T n1x;
  real_T n1xinv;
  real_T s;
  int32_T ipiv[6];
  int32_T i;
  int32_T j;
  int32_T kAcol;
  int32_T pipk;
  int32_T y_tmp;
  int8_T p[6];
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ke_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (i = 0; i < 36; i++) {
    y[i] = 0.0;
    b_x[i] = x[i];
  }
  b_st.site = &me_emlrtRSI;
  internal::lapack::xgetrf(b_st, b_x, ipiv);
  for (i = 0; i < 6; i++) {
    p[i] = static_cast<int8_T>(i + 1);
  }
  for (int32_T k{0}; k < 5; k++) {
    i = ipiv[k];
    if (i > k + 1) {
      pipk = p[i - 1];
      p[i - 1] = p[k];
      p[k] = static_cast<int8_T>(pipk);
    }
  }
  for (int32_T k{0}; k < 6; k++) {
    y_tmp = 6 * (p[k] - 1);
    y[k + y_tmp] = 1.0;
    for (j = k + 1; j < 7; j++) {
      i = (j + y_tmp) - 1;
      if (y[i] != 0.0) {
        pipk = j + 1;
        for (int32_T b_i{pipk}; b_i < 7; b_i++) {
          kAcol = (b_i + y_tmp) - 1;
          y[kAcol] -= y[i] * b_x[(b_i + 6 * (j - 1)) - 1];
        }
      }
    }
  }
  b_st.site = &ne_emlrtRSI;
  c_st.site = &oe_emlrtRSI;
  for (j = 0; j < 6; j++) {
    pipk = 6 * j;
    for (int32_T k{5}; k >= 0; k--) {
      kAcol = 6 * k;
      i = k + pipk;
      s = y[i];
      if (s != 0.0) {
        y[i] = s / b_x[k + kAcol];
        for (int32_T b_i{0}; b_i < k; b_i++) {
          y_tmp = b_i + pipk;
          y[y_tmp] -= y[i] * b_x[b_i + kAcol];
        }
      }
    }
  }
  st.site = &le_emlrtRSI;
  n1x = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 6)) {
    s = 0.0;
    for (int32_T b_i{0}; b_i < 6; b_i++) {
      s += muDoubleScalarAbs(x[b_i + 6 * j]);
    }
    if (muDoubleScalarIsNaN(s)) {
      n1x = rtNaN;
      exitg1 = true;
    } else {
      if (s > n1x) {
        n1x = s;
      }
      j++;
    }
  }
  n1xinv = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 6)) {
    s = 0.0;
    for (int32_T b_i{0}; b_i < 6; b_i++) {
      s += muDoubleScalarAbs(y[b_i + 6 * j]);
    }
    if (muDoubleScalarIsNaN(s)) {
      n1xinv = rtNaN;
      exitg1 = true;
    } else {
      if (s > n1xinv) {
        n1xinv = s;
      }
      j++;
    }
  }
  s = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (s == 0.0)) {
    b_st.site = &qe_emlrtRSI;
    internal::warning(b_st);
  } else if (muDoubleScalarIsNaN(s) || (s < 2.2204460492503131E-16)) {
    char_T str[14];
    b_st.site = &re_emlrtRSI;
    b_y = nullptr;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 6, m, &rfmt[0]);
    emlrtAssign(&b_y, m);
    c_st.site = &nj_emlrtRSI;
    emlrt_marshallIn(c_st,
                     b_sprintf(c_st, b_y, emlrt_marshallOut(s), c_emlrtMCI),
                     "<output of sprintf>", str);
    b_st.site = &re_emlrtRSI;
    internal::warning(b_st, str);
  }
}

} // namespace coder

// End of code generation (inv.cpp)
