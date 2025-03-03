//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// partialColLDL3_.cpp
//
// Code generation for function 'partialColLDL3_'
//

// Include files
#include "partialColLDL3_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo
    jf_emlrtRSI{
        51,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" // pathName
    };

static emlrtRSInfo
    dh_emlrtRSI{
        58,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" // pathName
    };

static emlrtRSInfo
    rh_emlrtRSI{
        64,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" // pathName
    };

static emlrtRSInfo th_emlrtRSI{
    1,                 // lineNo
    "partialColLDL3_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/partialColLDL3_.p" // pathName
};

static emlrtRSInfo
    uh_emlrtRSI{
        63,      // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    vh_emlrtRSI{
        70,      // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    wh_emlrtRSI{
        71,      // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    xh_emlrtRSI{
        125,     // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    yh_emlrtRSI{
        128,     // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtRSInfo
    ai_emlrtRSI{
        135,     // lineNo
        "xgemm", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemm.m" // pathName
    };

static emlrtBCInfo rd_emlrtBCI{
    1,                 // iFirst
    1,                 // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "partialColLDL3_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/partialColLDL3_.p", // pName
    3                                           // checkKind
};

static emlrtBCInfo sd_emlrtBCI{
    1,                 // iFirst
    1,                 // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "partialColLDL3_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/partialColLDL3_.p", // pName
    0                                           // checkKind
};

static emlrtBCInfo td_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "partialColLDL3_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/partialColLDL3_.p", // pName
    0                                           // checkKind
};

static emlrtRTEInfo r_emlrtRTEI{
    18,                               // lineNo
    27,                               // colNo
    "eml_int_forloop_overflow_check", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void partialColLDL3_(const emlrtStack &sp, f_struct_T &obj, int32_T LD_offset,
                     int32_T NColsRemain)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T LD_diagOffset;
  int32_T LD_diagOffset_tmp;
  int32_T LDimSizeP1;
  int32_T b;
  int32_T b_b;
  int32_T b_tmp;
  int32_T i;
  int32_T ia;
  int32_T ix;
  int32_T lda;
  int32_T offsetColK;
  int32_T subRows;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  LDimSizeP1 = obj.ldm + 1;
  b = NColsRemain - 1;
  for (int32_T k{0}; k < 48; k++) {
    real_T y;
    subRows = (NColsRemain - k) - 1;
    LD_diagOffset_tmp = LDimSizeP1 * k;
    LD_diagOffset = LD_offset + LD_diagOffset_tmp;
    for (int32_T idx{0}; idx <= subRows; idx++) {
      i = (LD_diagOffset_tmp + idx) + 1;
      if ((i < 1) || (i > 1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 1, &rd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = obj.FMat.size(0) * obj.FMat.size(1);
      lda = LD_diagOffset + idx;
      if ((lda < 1) || (lda > i)) {
        emlrtDynamicBoundsCheckR2012b(lda, 1, i, &td_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.workspace_ = obj.FMat[lda - 1];
    }
    offsetColK = obj.ldm * k + 1;
    for (int32_T idx{0}; idx <= b; idx++) {
      i = offsetColK + idx;
      if ((i < 1) || (i > 1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 1, &sd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((idx + 1 < 1) || (idx + 1 > 1)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 1, &rd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.workspace2_ = obj.workspace_;
    }
    st.site = &th_emlrtRSI;
    lda = obj.ldm;
    y = obj.workspace2_;
    b_st.site = &rh_emlrtRSI;
    if ((NColsRemain != 0) && (k != 0)) {
      boolean_T overflow;
      ix = LD_offset + k;
      b_tmp = obj.ldm * (k - 1) + 1;
      c_st.site = &jf_emlrtRSI;
      if ((obj.ldm == 0) || ((obj.ldm > 0) && (b_tmp < 1)) ||
          ((obj.ldm < 0) && (b_tmp > 1))) {
        overflow = false;
      } else if (obj.ldm > 0) {
        overflow = (b_tmp > MAX_int32_T - obj.ldm);
      } else {
        overflow = (b_tmp < MIN_int32_T - obj.ldm);
      }
      if (obj.ldm == 0) {
        emlrtErrorWithMessageIdR2018a(&c_st, &r_emlrtRTEI,
                                      "Coder:builtins:VectorStride",
                                      "Coder:builtins:VectorStride", 0);
      }
      if (overflow) {
        d_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(d_st);
      }
      for (int32_T iac{1}; lda < 0 ? iac >= b_tmp : iac <= b_tmp; iac += lda) {
        b_b = (iac + NColsRemain) - 1;
        c_st.site = &dh_emlrtRSI;
        if ((iac <= b_b) && (b_b > 2147483646)) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        for (ia = iac; ia <= b_b; ia++) {
          y += obj.workspace_ * -obj.FMat[ix - 1];
        }
        ix += obj.ldm;
      }
    }
    obj.workspace2_ = y;
    for (int32_T idx{0}; idx <= b; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > 1)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 1, &sd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = offsetColK + idx;
      if ((i < 1) || (i > 1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 1, &rd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.workspace_ = y;
    }
    for (int32_T idx{0}; idx <= subRows; idx++) {
      i = (LD_diagOffset_tmp + idx) + 1;
      if ((i < 1) || (i > 1)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, 1, &sd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = obj.FMat.size(0) * obj.FMat.size(1);
      lda = LD_diagOffset + idx;
      if ((lda < 1) || (lda > i)) {
        emlrtDynamicBoundsCheckR2012b(lda, 1, i, &td_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.FMat[lda - 1] = obj.workspace_;
    }
    i = obj.FMat.size(0) * obj.FMat.size(1);
    if ((LD_diagOffset < 1) || (LD_diagOffset > i)) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, i, &td_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    y = obj.FMat[LD_diagOffset - 1];
    if (muDoubleScalarAbs(y) <= obj.regTol_) {
      if (LD_diagOffset > i) {
        emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, i, &td_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.FMat[LD_diagOffset - 1] = y;
    }
    st.site = &th_emlrtRSI;
    if (subRows > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < subRows; idx++) {
      i = obj.FMat.size(0) * obj.FMat.size(1);
      lda = (LD_diagOffset + idx) + 1;
      if ((lda < 1) || (lda > i)) {
        emlrtDynamicBoundsCheckR2012b(lda, 1, i, &td_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (LD_diagOffset > i) {
        emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, i, &td_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (lda > i) {
        emlrtDynamicBoundsCheckR2012b(lda, 1, i, &td_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.FMat[lda - 1] = obj.FMat[lda - 1] / obj.FMat[LD_diagOffset - 1];
    }
  }
  st.site = &th_emlrtRSI;
  if (NColsRemain - 1 > 2147483599) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T j{48}; j <= b; j += 48) {
    int32_T c_b;
    int32_T m;
    subRows = NColsRemain - j;
    LD_diagOffset = muIntScalarMin_sint32(48, subRows);
    b_tmp = j + LD_diagOffset;
    b_b = b_tmp - 1;
    st.site = &th_emlrtRSI;
    if ((j <= b_tmp - 1) && (b_tmp - 1 > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T k{j}; k <= b_b; k++) {
      m = b_tmp - k;
      LD_diagOffset_tmp = (LD_offset + LDimSizeP1 * k) - 1;
      for (int32_T idx{0}; idx < 48; idx++) {
        if (idx + 1 > 1) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 1, &rd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = obj.FMat.size(0) * obj.FMat.size(1);
        lda = (LD_offset + k) + idx * obj.ldm;
        if ((lda < 1) || (lda > i)) {
          emlrtDynamicBoundsCheckR2012b(lda, 1, i, &td_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.workspace2_ = obj.FMat[lda - 1];
      }
      st.site = &th_emlrtRSI;
      ix = k + 1;
      lda = obj.ldm;
      b_st.site = &rh_emlrtRSI;
      if (m != 0) {
        c_b = (k + obj.ldm * 47) + 1;
        c_st.site = &jf_emlrtRSI;
        if ((k + 1 <= c_b) && (c_b > MAX_int32_T - obj.ldm)) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        for (int32_T iac{ix}; lda < 0 ? iac >= c_b : iac <= c_b; iac += lda) {
          offsetColK = (iac + m) - 1;
          c_st.site = &dh_emlrtRSI;
          if ((iac <= offsetColK) && (offsetColK > 2147483646)) {
            d_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(d_st);
          }
          for (ia = iac; ia <= offsetColK; ia++) {
            i = (LD_diagOffset_tmp + ia) - iac;
            obj.FMat[i] = obj.FMat[i] + obj.workspace_ * -obj.workspace2_;
          }
        }
      }
    }
    if (b_tmp < NColsRemain) {
      m = subRows - LD_diagOffset;
      ia = ((LD_offset + LD_diagOffset) + LDimSizeP1 * j) - 1;
      i = LD_diagOffset - 1;
      for (int32_T idx{0}; idx < 48; idx++) {
        ix = idx * obj.ldm;
        offsetColK = (LD_offset + j) + ix;
        for (LD_diagOffset_tmp = 0; LD_diagOffset_tmp <= i;
             LD_diagOffset_tmp++) {
          lda = (ix + LD_diagOffset_tmp) + 1;
          if ((lda < 1) || (lda > 1)) {
            emlrtDynamicBoundsCheckR2012b(lda, 1, 1, &rd_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          lda = obj.FMat.size(0) * obj.FMat.size(1);
          subRows = offsetColK + LD_diagOffset_tmp;
          if ((subRows < 1) || (subRows > lda)) {
            emlrtDynamicBoundsCheckR2012b(subRows, 1, lda, &td_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          obj.workspace2_ = obj.FMat[subRows - 1];
        }
      }
      st.site = &th_emlrtRSI;
      lda = obj.ldm;
      b_st.site = &uh_emlrtRSI;
      if ((m != 0) && (LD_diagOffset != 0)) {
        ix = ia + obj.ldm * (LD_diagOffset - 1);
        c_st.site = &vh_emlrtRSI;
        if ((ia <= ix) && (ix > MAX_int32_T - obj.ldm)) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        for (b_tmp = ia; lda < 0 ? b_tmp >= ix : b_tmp <= ix; b_tmp += lda) {
          b_b = b_tmp + m;
          c_st.site = &wh_emlrtRSI;
          if ((b_tmp + 1 <= b_b) && (b_b > 2147483646)) {
            d_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(d_st);
          }
        }
        offsetColK = 0;
        c_st.site = &xh_emlrtRSI;
        for (b_tmp = ia; lda < 0 ? b_tmp >= ix : b_tmp <= ix; b_tmp += lda) {
          offsetColK++;
          b_b = offsetColK + lda * 47;
          c_st.site = &yh_emlrtRSI;
          if ((offsetColK <= b_b) && (b_b > MAX_int32_T - lda)) {
            d_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(d_st);
          }
          for (int32_T idx{offsetColK}; lda < 0 ? idx >= b_b : idx <= b_b;
               idx += lda) {
            subRows = b_tmp + 1;
            c_b = b_tmp + m;
            c_st.site = &ai_emlrtRSI;
            if ((b_tmp + 1 <= c_b) && (c_b > 2147483646)) {
              d_st.site = &o_emlrtRSI;
              check_forloop_overflow_error(d_st);
            }
            LD_diagOffset_tmp = ((((c_b - b_tmp) / 2) << 1) + b_tmp) + 1;
            LD_diagOffset = LD_diagOffset_tmp - 2;
            for (int32_T iac{subRows}; iac <= LD_diagOffset; iac += 2) {
              __m128d r;
              r = _mm_loadu_pd(&obj.FMat[iac - 1]);
              _mm_storeu_pd(&obj.FMat[iac - 1],
                            _mm_add_pd(r, _mm_set1_pd(-obj.workspace2_ *
                                                      obj.workspace_)));
            }
            for (int32_T iac{LD_diagOffset_tmp}; iac <= c_b; iac++) {
              obj.FMat[iac - 1] =
                  obj.FMat[iac - 1] + -obj.workspace2_ * obj.workspace_;
            }
          }
        }
      }
    }
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (partialColLDL3_.cpp)
