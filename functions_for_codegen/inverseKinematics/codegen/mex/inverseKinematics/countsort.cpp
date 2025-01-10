//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// countsort.cpp
//
// Code generation for function 'countsort'
//

// Include files
#include "countsort.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    gc_emlrtRSI{
        1,           // lineNo
        "countsort", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
        "countsort.p" // pathName
    };

static emlrtBCInfo
    cb_emlrtBCI{
        -1,          // iFirst
        -1,          // iLast
        1,           // lineNo
        1,           // colNo
        "",          // aName
        "countsort", // fName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
        "countsort.p", // pName
        0              // checkKind
    };

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
void countsort(const emlrtStack &sp, array<int32_T, 1U> &x, int32_T xLen,
               array<int32_T, 1U> &workspace, int32_T xMax)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((xLen > 1) && (xMax > 1)) {
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T idxEnd;
    int32_T idxStart;
    st.site = &gc_emlrtRSI;
    if (xMax > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < xMax; idx++) {
      i = workspace.size(0);
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[idx] = 0;
    }
    st.site = &gc_emlrtRSI;
    if (xLen > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = x.size(0);
    i1 = x.size(0);
    for (int32_T idx{0}; idx < xLen; idx++) {
      i2 = workspace.size(0);
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idxStart = x[idx];
      if ((idxStart < 1) || (idxStart > i2)) {
        emlrtDynamicBoundsCheckR2012b(idxStart, 1, i2, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i2 = workspace.size(0);
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (idxStart > i2) {
        emlrtDynamicBoundsCheckR2012b(idxStart, 1, i2, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[idxStart - 1] = workspace[idxStart - 1] + 1;
    }
    st.site = &gc_emlrtRSI;
    for (int32_T idx{2}; idx <= xMax; idx++) {
      i = workspace.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = workspace.size(0);
      if (idx - 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx - 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = workspace.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[idx - 1] = workspace[idx - 1] + workspace[idx - 2];
    }
    idxStart = 1;
    idxEnd = workspace[0];
    st.site = &gc_emlrtRSI;
    i = workspace.size(0);
    i1 = workspace.size(0);
    for (int32_T idx{0}; idx <= xMax - 2; idx++) {
      st.site = &gc_emlrtRSI;
      if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idxFill{idxStart}; idxFill <= idxEnd; idxFill++) {
        i2 = x.size(0);
        if ((idxFill < 1) || (idxFill > i2)) {
          emlrtDynamicBoundsCheckR2012b(idxFill, 1, i2, &cb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        x[idxFill - 1] = idx + 1;
      }
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idxStart = workspace[idx] + 1;
      if (idx + 2 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 2, 1, i1, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idxEnd = workspace[idx + 1];
    }
    st.site = &gc_emlrtRSI;
    if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{idxStart}; idx <= idxEnd; idx++) {
      i = x.size(0);
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      x[idx - 1] = xMax;
    }
  }
}

void countsort(const emlrtStack &sp, array<int32_T, 1U> &x, int32_T xLen,
               array<int32_T, 1U> &workspace, int32_T xMin, int32_T xMax)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T i;
    int32_T idxEnd;
    int32_T idxStart;
    int32_T idxW;
    b_tmp = (xMax - xMin) + 1;
    st.site = &gc_emlrtRSI;
    if (b_tmp > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < b_tmp; idx++) {
      i = workspace.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[idx] = 0;
    }
    st.site = &gc_emlrtRSI;
    if (xLen > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = x.size(0);
    idxStart = x.size(0);
    for (int32_T idx{0}; idx < xLen; idx++) {
      idxEnd = workspace.size(0);
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idxW = (x[idx] - xMin) + 1;
      if ((idxW < 1) || (idxW > idxEnd)) {
        emlrtDynamicBoundsCheckR2012b(idxW, 1, idxEnd, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idxEnd = workspace.size(0);
      if (idx + 1 > idxStart) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idxStart, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (idxW > idxEnd) {
        emlrtDynamicBoundsCheckR2012b(idxW, 1, idxEnd, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[idxW - 1] = workspace[idxW - 1] + 1;
    }
    st.site = &gc_emlrtRSI;
    for (int32_T idx{2}; idx <= b_tmp; idx++) {
      i = workspace.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = workspace.size(0);
      if (idx - 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx - 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = workspace.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      workspace[idx - 1] = workspace[idx - 1] + workspace[idx - 2];
    }
    idxStart = 1;
    idxEnd = workspace[0];
    st.site = &gc_emlrtRSI;
    if (b_tmp - 1 > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (idxW = 0; idxW <= b_tmp - 2; idxW++) {
      st.site = &gc_emlrtRSI;
      if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{idxStart}; idx <= idxEnd; idx++) {
        i = x.size(0);
        if ((idx < 1) || (idx > i)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i, &cb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        x[idx - 1] = idxW + xMin;
      }
      i = workspace.size(0);
      if ((idxW + 1 < 1) || (idxW + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idxW + 1, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idxStart = workspace[idxW] + 1;
      i = workspace.size(0);
      if ((idxW + 2 < 1) || (idxW + 2 > i)) {
        emlrtDynamicBoundsCheckR2012b(idxW + 2, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      idxEnd = workspace[idxW + 1];
    }
    st.site = &gc_emlrtRSI;
    if ((idxStart <= idxEnd) && (idxEnd > 2147483646)) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{idxStart}; idx <= idxEnd; idx++) {
      i = x.size(0);
      if ((idx < 1) || (idx > i)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &cb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      x[idx - 1] = xMax;
    }
  }
}

} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (countsort.cpp)
