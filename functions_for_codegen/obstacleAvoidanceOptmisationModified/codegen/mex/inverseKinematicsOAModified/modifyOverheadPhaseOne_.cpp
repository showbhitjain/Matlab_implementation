//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// modifyOverheadPhaseOne_.cpp
//
// Code generation for function 'modifyOverheadPhaseOne_'
//

// Include files
#include "modifyOverheadPhaseOne_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo cf_emlrtRSI{
    1,                         // lineNo
    "modifyOverheadPhaseOne_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/modifyOverheadPhaseOne_.p" // pathName
};

static emlrtBCInfo vb_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    1,                         // lineNo
    1,                         // colNo
    "",                        // aName
    "modifyOverheadPhaseOne_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/modifyOverheadPhaseOne_.p", // pName
    0                                        // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void modifyOverheadPhaseOne_(const emlrtStack &sp, d_struct_T &obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T i1;
  int32_T idxEq;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = obj.sizes[0];
  st.site = &cf_emlrtRSI;
  if (obj.sizes[0] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < b; idx++) {
    i = obj.ATwset.size(0);
    i1 = obj.nVar + obj.ldA * idx;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = 0.0;
  }
  b = obj.sizes[1];
  st.site = &cf_emlrtRSI;
  if (obj.sizes[1] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < b; idx++) {
    idxEq = obj.nVar + obj.ldA * idx;
    i = obj.Aeq.size(0);
    if ((idxEq < 1) || (idxEq > i)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, i, &vb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.Aeq[idxEq - 1] = 0.0;
    i = obj.ATwset.size(0);
    i1 = idxEq + obj.ldA * (obj.isActiveIdx[1] - 1);
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = 0.0;
  }
  st.site = &cf_emlrtRSI;
  if (obj.sizes[2] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  i = static_cast<uint8_T>(obj.sizes[2]);
  for (int32_T idx{0}; idx < i; idx++) {
    i1 = obj.Aineq.size(0);
    idxEq = obj.nVar + obj.ldA * idx;
    if ((idxEq < 1) || (idxEq > i1)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, i1, &vb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.Aineq[idxEq - 1] = -1.0;
  }
  i = obj.indexLB.size(0);
  if ((obj.sizes[3] < 1) || (obj.sizes[3] > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.sizes[3], 1, i, &vb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.indexLB[obj.sizes[3] - 1] = obj.nVar;
  i = obj.lb.size(0);
  if ((obj.nVar < 1) || (obj.nVar > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.nVar, 1, i, &vb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.lb[obj.nVar - 1] = 1.0E-5;
  idxEq = obj.isActiveIdx[2];
  b = obj.nActiveConstr;
  st.site = &cf_emlrtRSI;
  if ((obj.isActiveIdx[2] <= obj.nActiveConstr) &&
      (obj.nActiveConstr > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{idxEq}; idx <= b; idx++) {
    i = obj.ATwset.size(0);
    i1 = obj.nVar + obj.ldA * (idx - 1);
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = -1.0;
  }
  if (obj.nWConstr[4] > 0) {
    b = obj.sizesNormal[4];
    st.site = &cf_emlrtRSI;
    if (obj.sizesNormal[4] + 1 > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx <= b; idx++) {
      i = obj.isActiveConstr.size[0];
      i1 = obj.isActiveIdx[4] + idx;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.isActiveConstr.data[i1 - 1] = false;
    }
  }
  i = obj.isActiveConstr.size[0];
  i1 = obj.isActiveIdx[4] - 1;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vb_emlrtBCI, (emlrtConstCTX)&sp);
  }
  obj.isActiveConstr.data[i1 - 1] = false;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (modifyOverheadPhaseOne_.cpp)
