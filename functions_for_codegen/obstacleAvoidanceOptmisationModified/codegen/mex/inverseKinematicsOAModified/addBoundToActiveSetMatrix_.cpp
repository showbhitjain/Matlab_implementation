//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// addBoundToActiveSetMatrix_.cpp
//
// Code generation for function 'addBoundToActiveSetMatrix_'
//

// Include files
#include "addBoundToActiveSetMatrix_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo pi_emlrtRSI{
    1,                            // lineNo
    "addBoundToActiveSetMatrix_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p" // pathName
};

static emlrtBCInfo xd_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    1,                            // lineNo
    1,                            // colNo
    "",                           // aName
    "addBoundToActiveSetMatrix_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p", // pName
    0                                           // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void addBoundToActiveSetMatrix_(const emlrtStack &sp, d_struct_T &obj,
                                int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a_tmp;
  int32_T b;
  int32_T colOffset;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &pi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj.nWConstr[3]++;
  i = obj.isActiveConstr.size[0];
  i1 = (obj.isActiveIdx[3] + idx_local) - 1;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vd_emlrtBCI, &st);
  }
  obj.isActiveConstr.data[i1 - 1] = true;
  obj.nActiveConstr++;
  i = obj.Wid.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i, &vd_emlrtBCI, &st);
  }
  i = obj.nActiveConstr - 1;
  obj.Wid.data[i] = 4;
  i1 = obj.Wlocalidx.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &vd_emlrtBCI, &st);
  }
  obj.Wlocalidx.data[i] = idx_local;
  colOffset = obj.ldA * i;
  i1 = obj.indexLB.size(0);
  if ((idx_local < 1) || (idx_local > i1)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, i1, &xd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i1 = obj.lb.size(0);
  i2 = obj.indexLB[idx_local - 1];
  if ((i2 < 1) || (i2 > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.indexLB[idx_local - 1], 1, i1,
                                  &xd_emlrtBCI, (emlrtConstCTX)&sp);
  }
  i1 = obj.bwset.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &xd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.bwset.data[i] = obj.lb[i2 - 1];
  st.site = &pi_emlrtRSI;
  for (int32_T idx{0}; idx <= i2 - 2; idx++) {
    i = obj.ATwset.size(0);
    i1 = (idx + colOffset) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = 0.0;
  }
  i = obj.ATwset.size(0);
  i1 = i2 + colOffset;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xd_emlrtBCI, (emlrtConstCTX)&sp);
  }
  obj.ATwset[i1 - 1] = -1.0;
  a_tmp = i2 + 1;
  b = obj.nVar;
  st.site = &pi_emlrtRSI;
  if ((i2 + 1 <= obj.nVar) && (obj.nVar > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{a_tmp}; idx <= b; idx++) {
    i = obj.ATwset.size(0);
    i1 = idx + colOffset;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = 0.0;
  }
  switch (obj.probType) {
  case 3:
  case 2:
    break;
  default:
    i = obj.ATwset.size(0);
    i1 = obj.nVar + colOffset;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = -1.0;
    break;
  }
}

void b_addBoundToActiveSetMatrix_(const emlrtStack &sp, d_struct_T &obj,
                                  int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a_tmp;
  int32_T b;
  int32_T colOffset;
  int32_T i;
  int32_T i1;
  int32_T i2;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &pi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj.nWConstr[4]++;
  i = obj.isActiveConstr.size[0];
  i1 = (obj.isActiveIdx[4] + idx_local) - 1;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vd_emlrtBCI, &st);
  }
  obj.isActiveConstr.data[i1 - 1] = true;
  obj.nActiveConstr++;
  i = obj.Wid.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i, &vd_emlrtBCI, &st);
  }
  i = obj.nActiveConstr - 1;
  obj.Wid.data[i] = 5;
  i1 = obj.Wlocalidx.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &vd_emlrtBCI, &st);
  }
  obj.Wlocalidx.data[i] = idx_local;
  colOffset = obj.ldA * i;
  i1 = obj.indexUB.size(0);
  if ((idx_local < 1) || (idx_local > i1)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, i1, &xd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i1 = obj.ub.size(0);
  i2 = obj.indexUB[idx_local - 1];
  if ((i2 < 1) || (i2 > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.indexUB[idx_local - 1], 1, i1,
                                  &xd_emlrtBCI, (emlrtConstCTX)&sp);
  }
  i1 = obj.bwset.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &xd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.bwset.data[i] = obj.ub[i2 - 1];
  st.site = &pi_emlrtRSI;
  i = static_cast<uint8_T>(i2 - 1);
  for (int32_T idx{0}; idx < i; idx++) {
    i1 = obj.ATwset.size(0);
    a_tmp = (idx + colOffset) + 1;
    if ((a_tmp < 1) || (a_tmp > i1)) {
      emlrtDynamicBoundsCheckR2012b(a_tmp, 1, i1, &xd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.ATwset[a_tmp - 1] = 0.0;
  }
  i = obj.ATwset.size(0);
  i1 = i2 + colOffset;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xd_emlrtBCI, (emlrtConstCTX)&sp);
  }
  obj.ATwset[i1 - 1] = 1.0;
  a_tmp = i2 + 1;
  b = obj.nVar;
  st.site = &pi_emlrtRSI;
  if ((i2 + 1 <= obj.nVar) && (obj.nVar > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{a_tmp}; idx <= b; idx++) {
    i = obj.ATwset.size(0);
    i1 = idx + colOffset;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = 0.0;
  }
  switch (obj.probType) {
  case 3:
  case 2:
    break;
  default:
    i = obj.ATwset.size(0);
    i1 = obj.nVar + colOffset;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i1 - 1] = -1.0;
    break;
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (addBoundToActiveSetMatrix_.cpp)
