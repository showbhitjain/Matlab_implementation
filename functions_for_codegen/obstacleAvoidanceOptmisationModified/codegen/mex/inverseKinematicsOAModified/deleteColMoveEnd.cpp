//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// deleteColMoveEnd.cpp
//
// Code generation for function 'deleteColMoveEnd'
//

// Include files
#include "deleteColMoveEnd.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo oh_emlrtRSI{
    1,                  // lineNo
    "deleteColMoveEnd", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "deleteColMoveEnd.p" // pathName
};

static emlrtBCInfo md_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    1,                  // lineNo
    1,                  // colNo
    "",                 // aName
    "deleteColMoveEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "deleteColMoveEnd.p", // pName
    0                     // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void deleteColMoveEnd(const emlrtStack &sp, e_struct_T &obj, int32_T idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T c;
  real_T d;
  real_T s;
  real_T temp;
  int32_T b_i;
  int32_T i;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (obj.usedPivoting) {
    boolean_T exitg1;
    i = 1;
    exitg1 = false;
    while ((!exitg1) && (i <= obj.ncols)) {
      b_i = obj.jpvt.size(0);
      if ((i < 1) || (i > b_i)) {
        emlrtDynamicBoundsCheckR2012b(i, 1, b_i, &md_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (obj.jpvt[i - 1] != idx) {
        i++;
      } else {
        exitg1 = true;
      }
    }
    idx = i;
  }
  if (idx >= obj.ncols) {
    obj.ncols--;
  } else {
    int32_T i1;
    int32_T ix;
    int32_T k;
    int32_T temp_tmp;
    b_i = obj.jpvt.size(0);
    if ((obj.ncols < 1) || (obj.ncols > b_i)) {
      emlrtDynamicBoundsCheckR2012b(obj.ncols, 1, b_i, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_i = obj.jpvt.size(0);
    if ((idx < 1) || (idx > b_i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, b_i, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_i = obj.ncols - 1;
    obj.jpvt[idx - 1] = obj.jpvt[b_i];
    i = obj.minRowCol;
    st.site = &oh_emlrtRSI;
    if (obj.minRowCol > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (k = 0; k < i; k++) {
      i1 = obj.QR.size(0) * obj.QR.size(1);
      temp_tmp = (k + obj.ldq * b_i) + 1;
      if ((temp_tmp < 1) || (temp_tmp > i1)) {
        emlrtDynamicBoundsCheckR2012b(temp_tmp, 1, i1, &md_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i1 = obj.QR.size(0) * obj.QR.size(1);
      ix = (k + obj.ldq * (idx - 1)) + 1;
      if ((ix < 1) || (ix > i1)) {
        emlrtDynamicBoundsCheckR2012b(ix, 1, i1, &md_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.QR[ix - 1] = obj.QR[temp_tmp - 1];
    }
    obj.ncols = b_i;
    obj.minRowCol = muIntScalarMin_sint32(obj.mrows, obj.ncols);
    if (idx < obj.mrows) {
      int32_T endIdx;
      int32_T idxRotGCol;
      int32_T n;
      i = obj.mrows - 1;
      endIdx = muIntScalarMin_sint32(i, obj.ncols);
      k = endIdx;
      idxRotGCol = obj.ldq * (idx - 1);
      while (k >= idx) {
        st.site = &oh_emlrtRSI;
        b_i = obj.QR.size(0) * obj.QR.size(1);
        i1 = k + idxRotGCol;
        if ((i1 < 1) || (i1 > b_i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &md_emlrtBCI, &st);
        }
        temp = obj.QR[i1 - 1];
        b_i = obj.QR.size(0) * obj.QR.size(1);
        if ((i1 + 1 < 1) || (i1 + 1 > b_i)) {
          emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, b_i, &md_emlrtBCI, &st);
        }
        d = obj.QR[i1];
        b_st.site = &lh_emlrtRSI;
        c = 0.0;
        s = 0.0;
        drotg(&temp, &d, &c, &s);
        b_i = obj.QR.size(0) * obj.QR.size(1);
        if (i1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &md_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.QR[i1 - 1] = temp;
        b_i = obj.QR.size(0) * obj.QR.size(1);
        if ((i1 + 1 < 1) || (i1 + 1 > b_i)) {
          emlrtDynamicBoundsCheckR2012b(i1 + 1, 1, b_i, &md_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.QR[i1] = d;
        b_i = obj.QR.size(0) * obj.QR.size(1);
        i1 = obj.ldq * (k - 1);
        temp_tmp = (k + i1) + 1;
        if ((temp_tmp < 1) || (temp_tmp > b_i)) {
          emlrtDynamicBoundsCheckR2012b(temp_tmp, 1, b_i, &md_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.QR[temp_tmp - 1] = 0.0;
        i = k + obj.ldq * idx;
        st.site = &oh_emlrtRSI;
        n = obj.ncols - idx;
        if (n >= 1) {
          ix = i - 1;
          b_st.site = &nh_emlrtRSI;
          if (n > 2147483646) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(c_st);
          }
          for (int32_T b_k{0}; b_k < n; b_k++) {
            temp = c * obj.QR[ix] + s * obj.QR[i];
            obj.QR[i] = c * obj.QR[i] - s * obj.QR[ix];
            obj.QR[ix] = temp;
            i += obj.ldq;
            ix += obj.ldq;
          }
        }
        i = obj.ldq + i1;
        st.site = &oh_emlrtRSI;
        n = obj.mrows;
        b_st.site = &nh_emlrtRSI;
        if (obj.mrows > 2147483646) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        for (int32_T b_k{0}; b_k < n; b_k++) {
          temp_tmp = i + b_k;
          ix = i1 + b_k;
          temp = c * obj.Q[ix] + s * obj.Q[temp_tmp];
          obj.Q[temp_tmp] = c * obj.Q[temp_tmp] - s * obj.Q[ix];
          obj.Q[ix] = temp;
        }
        k--;
      }
      b_i = idx + 1;
      st.site = &oh_emlrtRSI;
      for (k = b_i; k <= endIdx; k++) {
        idxRotGCol = obj.ldq * (k - 1);
        st.site = &oh_emlrtRSI;
        i1 = obj.QR.size(0) * obj.QR.size(1);
        temp_tmp = k + idxRotGCol;
        if ((temp_tmp < 1) || (temp_tmp > i1)) {
          emlrtDynamicBoundsCheckR2012b(temp_tmp, 1, i1, &md_emlrtBCI, &st);
        }
        temp = obj.QR[temp_tmp - 1];
        i1 = obj.QR.size(0) * obj.QR.size(1);
        if ((temp_tmp + 1 < 1) || (temp_tmp + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(temp_tmp + 1, 1, i1, &md_emlrtBCI, &st);
        }
        d = obj.QR[temp_tmp];
        b_st.site = &lh_emlrtRSI;
        c = 0.0;
        s = 0.0;
        drotg(&temp, &d, &c, &s);
        i1 = obj.QR.size(0) * obj.QR.size(1);
        if (temp_tmp > i1) {
          emlrtDynamicBoundsCheckR2012b(temp_tmp, 1, i1, &md_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.QR[temp_tmp - 1] = temp;
        i1 = obj.QR.size(0) * obj.QR.size(1);
        if ((temp_tmp + 1 < 1) || (temp_tmp + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(temp_tmp + 1, 1, i1, &md_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.QR[temp_tmp] = d;
        i = k * (obj.ldq + 1);
        st.site = &oh_emlrtRSI;
        n = obj.ncols - k;
        if (n >= 1) {
          ix = i - 1;
          b_st.site = &nh_emlrtRSI;
          if (n > 2147483646) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(c_st);
          }
          for (int32_T b_k{0}; b_k < n; b_k++) {
            temp = c * obj.QR[ix] + s * obj.QR[i];
            obj.QR[i] = c * obj.QR[i] - s * obj.QR[ix];
            obj.QR[ix] = temp;
            i += obj.ldq;
            ix += obj.ldq;
          }
        }
        i = obj.ldq + idxRotGCol;
        st.site = &oh_emlrtRSI;
        n = obj.mrows;
        b_st.site = &nh_emlrtRSI;
        if (obj.mrows > 2147483646) {
          c_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(c_st);
        }
        for (int32_T b_k{0}; b_k < n; b_k++) {
          temp_tmp = i + b_k;
          ix = idxRotGCol + b_k;
          temp = c * obj.Q[ix] + s * obj.Q[temp_tmp];
          obj.Q[temp_tmp] = c * obj.Q[temp_tmp] - s * obj.Q[ix];
          obj.Q[ix] = temp;
        }
      }
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (deleteColMoveEnd.cpp)
