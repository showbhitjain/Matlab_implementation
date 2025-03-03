//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// loadProblem.cpp
//
// Code generation for function 'loadProblem'
//

// Include files
#include "loadProblem.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo bc_emlrtRSI{
    1,             // lineNo
    "loadProblem", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/loadProblem.p" // pathName
};

static emlrtBCInfo mb_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    1,             // lineNo
    1,             // colNo
    "",            // aName
    "loadProblem", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/loadProblem.p", // pName
    0                            // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void loadProblem(const emlrtStack &sp, d_struct_T &obj, int32_T mIneq,
                 int32_T mLinIneq, const array<real_T, 2U> &Aineq, int32_T mEq,
                 int32_T mLinEq, const array<real_T, 2U> &Aeq, int32_T mLB,
                 int32_T mUB, int32_T mFixed, int32_T mConstrMax)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = (((mIneq + mEq) + mLB) + mUB) + mFixed;
  obj.mConstr = i;
  obj.mConstrOrig = i;
  obj.mConstrMax = mConstrMax;
  obj.sizes[0] = mFixed;
  obj.sizes[1] = mEq;
  obj.sizes[2] = mIneq;
  obj.sizes[3] = mLB;
  obj.sizes[4] = mUB;
  obj.sizesPhaseOne[0] = mFixed;
  obj.sizesPhaseOne[1] = mEq;
  obj.sizesPhaseOne[2] = mIneq;
  obj.sizesPhaseOne[3] = mLB + 1;
  obj.sizesPhaseOne[4] = mUB;
  obj.sizesRegularized[0] = mFixed;
  obj.sizesRegularized[1] = mEq;
  obj.sizesRegularized[2] = mIneq;
  i = (mLB + mIneq) + (mEq << 1);
  obj.sizesRegularized[3] = i;
  obj.sizesRegularized[4] = mUB;
  obj.sizesRegPhaseOne[0] = mFixed;
  obj.sizesRegPhaseOne[1] = mEq;
  obj.sizesRegPhaseOne[2] = mIneq;
  obj.sizesRegPhaseOne[3] = i + 1;
  obj.sizesRegPhaseOne[4] = mUB;
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = mEq;
  obj.isActiveIdxRegPhaseOne[3] = mIneq;
  obj.isActiveIdxRegPhaseOne[4] = mLB;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.sizesNormal[k] = obj.sizes[k];
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  for (i1 = 0; i1 < 6; i1++) {
    obj.isActiveIdx[i1] = obj.isActiveIdxRegPhaseOne[i1];
    obj.isActiveIdxNormal[i1] = obj.isActiveIdxRegPhaseOne[i1];
  }
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = mEq;
  obj.isActiveIdxRegPhaseOne[3] = mIneq;
  obj.isActiveIdxRegPhaseOne[4] = mLB + 1;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  for (i1 = 0; i1 < 6; i1++) {
    obj.isActiveIdxPhaseOne[i1] = obj.isActiveIdxRegPhaseOne[i1];
  }
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = mEq;
  obj.isActiveIdxRegPhaseOne[3] = mIneq;
  obj.isActiveIdxRegPhaseOne[4] = i;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  for (i1 = 0; i1 < 6; i1++) {
    obj.isActiveIdxRegularized[i1] = obj.isActiveIdxRegPhaseOne[i1];
  }
  obj.isActiveIdxRegPhaseOne[0] = 1;
  obj.isActiveIdxRegPhaseOne[1] = mFixed;
  obj.isActiveIdxRegPhaseOne[2] = mEq;
  obj.isActiveIdxRegPhaseOne[3] = mIneq;
  obj.isActiveIdxRegPhaseOne[4] = i + 1;
  obj.isActiveIdxRegPhaseOne[5] = mUB;
  for (k = 0; k < 5; k++) {
    obj.isActiveIdxRegPhaseOne[k + 1] += obj.isActiveIdxRegPhaseOne[k];
  }
  if (mIneq > 0) {
    st.site = &bc_emlrtRSI;
    if (mLinIneq > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx_col{0}; idx_col < mLinIneq; idx_col++) {
      k = obj.nVar;
      st.site = &bc_emlrtRSI;
      if (obj.nVar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx_row{0}; idx_row < k; idx_row++) {
        i = Aineq.size(0) * Aineq.size(1);
        i1 = (idx_col + mLinIneq * idx_row) + 1;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &mb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = obj.Aineq.size(0);
        i2 = (idx_row + obj.ldA * idx_col) + 1;
        if ((i2 < 1) || (i2 > i)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &mb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.Aineq[i2 - 1] = Aineq[i1 - 1];
      }
    }
  }
  if (mEq > 0) {
    st.site = &bc_emlrtRSI;
    if (mLinEq > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = static_cast<uint8_T>(mLinEq);
    for (int32_T idx_col{0}; idx_col < i; idx_col++) {
      k = obj.nVar;
      st.site = &bc_emlrtRSI;
      if (obj.nVar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx_row{0}; idx_row < k; idx_row++) {
        int32_T i3;
        i1 = Aeq.size(0) * Aeq.size(1);
        i2 = (idx_col + mLinEq * idx_row) + 1;
        if ((i2 < 1) || (i2 > i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &mb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i1 = obj.Aeq.size(0);
        i3 = (idx_row + obj.ldA * idx_col) + 1;
        if ((i3 < 1) || (i3 > i1)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, i1, &mb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.Aeq[i3 - 1] = Aeq[i2 - 1];
      }
    }
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (loadProblem.cpp)
