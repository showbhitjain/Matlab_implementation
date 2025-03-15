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
#include "xgemm.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    jf_emlrtRSI{
        51,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" // pathName
    };

static emlrtRSInfo
    kf_emlrtRSI{
        58,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" // pathName
    };

static emlrtRSInfo uh_emlrtRSI{
    1,                 // lineNo
    "partialColLDL3_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/partialColLDL3_.p" // pathName
};

static emlrtRSInfo
    vh_emlrtRSI{
        64,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" // pathName
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
  int32_T b_b_tmp;
  int32_T b_tmp;
  int32_T i;
  int32_T ix;
  int32_T lda;
  int32_T offsetColK;
  int32_T subRows;
  boolean_T b_overflow;
  boolean_T overflow;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  LDimSizeP1 = obj.ldm + 1;
  b_tmp = NColsRemain - 1;
  overflow = (NColsRemain - 1 > 2147483646);
  b_overflow = (NColsRemain - 1 > 2147483646);
  for (int32_T k{0}; k < 48; k++) {
    real_T y;
    subRows = (NColsRemain - k) - 1;
    LD_diagOffset_tmp = LDimSizeP1 * k;
    LD_diagOffset = LD_offset + LD_diagOffset_tmp;
    st.site = &uh_emlrtRSI;
    if (subRows > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
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
    st.site = &uh_emlrtRSI;
    if (overflow) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx <= b_tmp; idx++) {
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
    st.site = &uh_emlrtRSI;
    lda = obj.ldm;
    y = obj.workspace2_;
    b_st.site = &vh_emlrtRSI;
    if ((NColsRemain != 0) && (k != 0)) {
      boolean_T c_overflow;
      ix = LD_offset + k;
      b_b_tmp = obj.ldm * (k - 1) + 1;
      c_st.site = &jf_emlrtRSI;
      if ((obj.ldm == 0) || ((obj.ldm > 0) && (b_b_tmp < 1)) ||
          ((obj.ldm < 0) && (b_b_tmp > 1))) {
        c_overflow = false;
      } else if (obj.ldm > 0) {
        c_overflow = (b_b_tmp > MAX_int32_T - obj.ldm);
      } else {
        c_overflow = (b_b_tmp < MIN_int32_T - obj.ldm);
      }
      if (obj.ldm == 0) {
        emlrtErrorWithMessageIdR2018a(&c_st, &r_emlrtRTEI,
                                      "Coder:builtins:VectorStride",
                                      "Coder:builtins:VectorStride", 0);
      }
      if (c_overflow) {
        d_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(d_st);
      }
      for (int32_T idx{1}; lda < 0 ? idx >= b_b_tmp : idx <= b_b_tmp;
           idx += lda) {
        b = (idx + NColsRemain) - 1;
        c_st.site = &kf_emlrtRSI;
        if ((idx <= b) && (b > 2147483646)) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        for (int32_T ia{idx}; ia <= b; ia++) {
          y += obj.workspace_ * -obj.FMat[ix - 1];
        }
        ix += obj.ldm;
      }
    }
    obj.workspace2_ = y;
    st.site = &uh_emlrtRSI;
    if (b_overflow) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx <= b_tmp; idx++) {
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
    st.site = &uh_emlrtRSI;
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
    st.site = &uh_emlrtRSI;
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
  st.site = &uh_emlrtRSI;
  if (NColsRemain - 1 > 2147483599) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T j{48}; j <= b_tmp; j += 48) {
    int32_T subBlockSize;
    int32_T y_tmp;
    y_tmp = NColsRemain - j;
    subBlockSize = muIntScalarMin_sint32(48, y_tmp);
    b_b_tmp = j + subBlockSize;
    b = b_b_tmp - 1;
    st.site = &uh_emlrtRSI;
    if ((j <= b_b_tmp - 1) && (b_b_tmp - 1 > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T k{j}; k <= b; k++) {
      LD_diagOffset_tmp = b_b_tmp - k;
      LD_diagOffset = (LD_offset + LDimSizeP1 * k) - 1;
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
      st.site = &uh_emlrtRSI;
      ix = k + 1;
      lda = obj.ldm;
      b_st.site = &vh_emlrtRSI;
      if (LD_diagOffset_tmp != 0) {
        offsetColK = (k + obj.ldm * 47) + 1;
        c_st.site = &jf_emlrtRSI;
        if ((k + 1 <= offsetColK) && (offsetColK > MAX_int32_T - obj.ldm)) {
          d_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        for (int32_T idx{ix}; lda < 0 ? idx >= offsetColK : idx <= offsetColK;
             idx += lda) {
          subRows = (idx + LD_diagOffset_tmp) - 1;
          c_st.site = &kf_emlrtRSI;
          if ((idx <= subRows) && (subRows > 2147483646)) {
            d_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(d_st);
          }
          for (int32_T ia{idx}; ia <= subRows; ia++) {
            i = (LD_diagOffset + ia) - idx;
            obj.FMat[i] = obj.FMat[i] + obj.workspace_ * -obj.workspace2_;
          }
        }
      }
    }
    if (b_b_tmp < NColsRemain) {
      b = subBlockSize - 1;
      overflow = (subBlockSize - 1 > 2147483646);
      for (int32_T idx{0}; idx < 48; idx++) {
        ix = idx * obj.ldm;
        offsetColK = (LD_offset + j) + ix;
        st.site = &uh_emlrtRSI;
        if (overflow) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        for (subRows = 0; subRows <= b; subRows++) {
          i = (ix + subRows) + 1;
          if ((i < 1) || (i > 1)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, 1, &rd_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = obj.FMat.size(0) * obj.FMat.size(1);
          lda = offsetColK + subRows;
          if ((lda < 1) || (lda > i)) {
            emlrtDynamicBoundsCheckR2012b(lda, 1, i, &td_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          obj.workspace2_ = obj.FMat[lda - 1];
        }
      }
      st.site = &uh_emlrtRSI;
      internal::blas::xgemm(st, y_tmp - subBlockSize, subBlockSize,
                            obj.workspace_, obj.workspace2_, obj.ldm, obj.FMat,
                            (LD_offset + subBlockSize) + LDimSizeP1 * j,
                            obj.ldm);
    }
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (partialColLDL3_.cpp)
