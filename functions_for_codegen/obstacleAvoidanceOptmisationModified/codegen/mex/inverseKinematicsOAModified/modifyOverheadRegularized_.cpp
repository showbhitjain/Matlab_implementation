//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// modifyOverheadRegularized_.cpp
//
// Code generation for function 'modifyOverheadRegularized_'
//

// Include files
#include "modifyOverheadRegularized_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo df_emlrtRSI{
    1,                            // lineNo
    "modifyOverheadRegularized_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/modifyOverheadRegularized_.p" // pathName
};

static emlrtBCInfo wb_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    1,                            // lineNo
    1,                            // colNo
    "",                           // aName
    "modifyOverheadRegularized_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/modifyOverheadRegularized_.p", // pName
    0                                           // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void modifyOverheadRegularized_(const emlrtStack &sp, d_struct_T &obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T b;
  int32_T b_tmp;
  int32_T colOffsetATw;
  int32_T colOffsetAeq;
  int32_T colOffsetAineq;
  int32_T i;
  int32_T i1;
  int32_T mEq;
  int32_T mIneq;
  int32_T offsetEq1_tmp;
  int32_T offsetEq2;
  int32_T offsetIneq_tmp;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mIneq = obj.sizes[2];
  mEq = obj.sizes[1];
  offsetIneq_tmp = obj.nVarOrig + 1;
  offsetEq1_tmp = obj.nVarOrig + obj.sizes[2];
  offsetEq2 = offsetEq1_tmp + obj.sizes[1];
  b = obj.sizes[0];
  st.site = &df_emlrtRSI;
  if (obj.sizes[0] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx_col{0}; idx_col < b; idx_col++) {
    colOffsetATw = obj.ldA * idx_col;
    colOffsetAeq = obj.nVar;
    st.site = &df_emlrtRSI;
    if ((offsetIneq_tmp <= obj.nVar) && (obj.nVar > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{offsetIneq_tmp}; idx_row <= colOffsetAeq; idx_row++) {
      i = obj.ATwset.size(0);
      i1 = idx_row + colOffsetATw;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i1 - 1] = 0.0;
    }
  }
  st.site = &df_emlrtRSI;
  if (obj.sizes[2] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx_col{0}; idx_col < mIneq; idx_col++) {
    colOffsetAineq = obj.ldA * idx_col;
    b_tmp = offsetIneq_tmp + idx_col;
    b = b_tmp - 1;
    st.site = &df_emlrtRSI;
    if ((offsetIneq_tmp <= b_tmp - 1) && (b_tmp - 1 > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{offsetIneq_tmp}; idx_row <= b; idx_row++) {
      i = obj.Aineq.size(0);
      i1 = idx_row + colOffsetAineq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Aineq[i1 - 1] = 0.0;
    }
    i = obj.Aineq.size(0);
    i1 = b_tmp + colOffsetAineq;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.Aineq[i1 - 1] = -1.0;
    a = b_tmp + 1;
    b = obj.nVar;
    st.site = &df_emlrtRSI;
    if ((b_tmp + 1 <= obj.nVar) && (obj.nVar > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{a}; idx_row <= b; idx_row++) {
      i = obj.Aineq.size(0);
      i1 = idx_row + colOffsetAineq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Aineq[i1 - 1] = 0.0;
    }
  }
  st.site = &df_emlrtRSI;
  if (obj.sizes[1] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx_col{0}; idx_col < mEq; idx_col++) {
    colOffsetAeq = obj.ldA * idx_col;
    colOffsetATw = colOffsetAeq + obj.ldA * (obj.isActiveIdx[1] - 1);
    st.site = &df_emlrtRSI;
    if ((offsetIneq_tmp <= offsetEq1_tmp) && (offsetEq1_tmp > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{offsetIneq_tmp}; idx_row <= offsetEq1_tmp; idx_row++) {
      i = obj.Aeq.size(0);
      i1 = idx_row + colOffsetAeq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Aeq[i1 - 1] = 0.0;
      i = obj.ATwset.size(0);
      i1 = idx_row + colOffsetATw;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i1 - 1] = 0.0;
    }
    a = offsetEq1_tmp + 1;
    b_tmp = offsetEq1_tmp + idx_col;
    st.site = &df_emlrtRSI;
    if ((offsetEq1_tmp + 1 <= b_tmp) && (b_tmp > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{a}; idx_row <= b_tmp; idx_row++) {
      i = obj.Aeq.size(0);
      i1 = idx_row + colOffsetAeq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Aeq[i1 - 1] = 0.0;
      i = obj.ATwset.size(0);
      i1 = idx_row + colOffsetATw;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i1 - 1] = 0.0;
    }
    i = obj.Aeq.size(0);
    i1 = (b_tmp + colOffsetAeq) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.Aeq[i1 - 1] = -1.0;
    i = obj.ATwset.size(0);
    i1 = (b_tmp + colOffsetATw) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = -1.0;
    a = b_tmp + 2;
    st.site = &df_emlrtRSI;
    if ((b_tmp + 2 <= offsetEq2) && (offsetEq2 > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{a}; idx_row <= offsetEq2; idx_row++) {
      i = obj.Aeq.size(0);
      i1 = idx_row + colOffsetAeq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Aeq[i1 - 1] = 0.0;
      i = obj.ATwset.size(0);
      i1 = idx_row + colOffsetATw;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i1 - 1] = 0.0;
    }
    a = offsetEq2 + 1;
    b_tmp = offsetEq2 + idx_col;
    st.site = &df_emlrtRSI;
    if ((offsetEq2 + 1 <= b_tmp) && (b_tmp > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{a}; idx_row <= b_tmp; idx_row++) {
      i = obj.Aeq.size(0);
      i1 = idx_row + colOffsetAeq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Aeq[i1 - 1] = 0.0;
      i = obj.ATwset.size(0);
      i1 = idx_row + colOffsetATw;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i1 - 1] = 0.0;
    }
    i = obj.Aeq.size(0);
    i1 = (b_tmp + colOffsetAeq) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.Aeq[i1 - 1] = 1.0;
    i = obj.ATwset.size(0);
    i1 = (b_tmp + colOffsetATw) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = 1.0;
    a = b_tmp + 2;
    b = obj.nVar;
    st.site = &df_emlrtRSI;
    if ((b_tmp + 2 <= obj.nVar) && (obj.nVar > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_row{a}; idx_row <= b; idx_row++) {
      i = obj.Aeq.size(0);
      i1 = idx_row + colOffsetAeq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Aeq[i1 - 1] = 0.0;
      i = obj.ATwset.size(0);
      i1 = idx_row + colOffsetATw;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i1 - 1] = 0.0;
    }
  }
  colOffsetAineq = obj.nVarOrig;
  a = obj.sizesNormal[3] + 1;
  b = obj.sizesRegularized[3];
  st.site = &df_emlrtRSI;
  if ((obj.sizesNormal[3] + 1 <= obj.sizesRegularized[3]) &&
      (obj.sizesRegularized[3] > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (colOffsetAeq = a; colOffsetAeq <= b; colOffsetAeq++) {
    colOffsetAineq++;
    i = obj.indexLB.size(0);
    if ((colOffsetAeq < 1) || (colOffsetAeq > i)) {
      emlrtDynamicBoundsCheckR2012b(colOffsetAeq, 1, i, &wb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.indexLB[colOffsetAeq - 1] = colOffsetAineq;
  }
  if (obj.nWConstr[4] > 0) {
    b = obj.sizesRegularized[4];
    st.site = &df_emlrtRSI;
    if (obj.sizesRegularized[4] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (colOffsetAeq = 0; colOffsetAeq < b; colOffsetAeq++) {
      i = obj.isActiveConstr.size(0);
      i1 = obj.isActiveIdx[4] + colOffsetAeq;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = obj.isActiveConstr.size(0);
      colOffsetAineq = (obj.isActiveIdxRegularized[4] + colOffsetAeq) + 1;
      if ((colOffsetAineq < 1) || (colOffsetAineq > i)) {
        emlrtDynamicBoundsCheckR2012b(colOffsetAineq, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.isActiveConstr[colOffsetAineq - 1] = obj.isActiveConstr[i1 - 1];
    }
  }
  a = obj.isActiveIdx[4];
  b = obj.isActiveIdxRegularized[4] - 1;
  st.site = &df_emlrtRSI;
  if ((obj.isActiveIdx[4] <= obj.isActiveIdxRegularized[4] - 1) &&
      (obj.isActiveIdxRegularized[4] - 1 > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (colOffsetAeq = a; colOffsetAeq <= b; colOffsetAeq++) {
    i = obj.isActiveConstr.size(0);
    if ((colOffsetAeq < 1) || (colOffsetAeq > i)) {
      emlrtDynamicBoundsCheckR2012b(colOffsetAeq, 1, i, &wb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.isActiveConstr[colOffsetAeq - 1] = false;
  }
  b = offsetEq1_tmp + (obj.sizes[1] << 1);
  st.site = &df_emlrtRSI;
  if ((offsetIneq_tmp <= b) && (b > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (colOffsetAeq = offsetIneq_tmp; colOffsetAeq <= b; colOffsetAeq++) {
    i = obj.lb.size(0);
    if ((colOffsetAeq < 1) || (colOffsetAeq > i)) {
      emlrtDynamicBoundsCheckR2012b(colOffsetAeq, 1, i, &wb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.lb[colOffsetAeq - 1] = 0.0;
  }
  colOffsetAineq = obj.isActiveIdx[2];
  b = obj.nActiveConstr;
  st.site = &df_emlrtRSI;
  if ((obj.isActiveIdx[2] <= obj.nActiveConstr) &&
      (obj.nActiveConstr > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx_col{colOffsetAineq}; idx_col <= b; idx_col++) {
    colOffsetATw = obj.ldA * (idx_col - 1);
    i = obj.Wid.size(0);
    if ((idx_col < 1) || (idx_col > i)) {
      emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &wb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if (obj.Wid[idx_col - 1] == 3) {
      i = obj.Wlocalidx.size(0);
      if (idx_col > i) {
        emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_tmp = offsetIneq_tmp + obj.Wlocalidx[idx_col - 1];
      colOffsetAeq = b_tmp - 2;
      st.site = &df_emlrtRSI;
      if ((offsetIneq_tmp <= b_tmp - 2) && (b_tmp - 2 > 2147483646)) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx_row{offsetIneq_tmp}; idx_row <= colOffsetAeq;
           idx_row++) {
        i = obj.ATwset.size(0);
        i1 = idx_row + colOffsetATw;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.ATwset[i1 - 1] = 0.0;
      }
      i = obj.ATwset.size(0);
      i1 = (b_tmp + colOffsetATw) - 1;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i1 - 1] = -1.0;
      colOffsetAeq = obj.nVar;
      st.site = &df_emlrtRSI;
      if ((b_tmp <= obj.nVar) && (obj.nVar > 2147483646)) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx_row{b_tmp}; idx_row <= colOffsetAeq; idx_row++) {
        i = obj.ATwset.size(0);
        i1 = idx_row + colOffsetATw;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.ATwset[i1 - 1] = 0.0;
      }
    } else {
      colOffsetAeq = obj.nVar;
      st.site = &df_emlrtRSI;
      if ((offsetIneq_tmp <= obj.nVar) && (obj.nVar > 2147483646)) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx_row{offsetIneq_tmp}; idx_row <= colOffsetAeq;
           idx_row++) {
        i = obj.ATwset.size(0);
        i1 = idx_row + colOffsetATw;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.ATwset[i1 - 1] = 0.0;
      }
    }
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (modifyOverheadRegularized_.cpp)
