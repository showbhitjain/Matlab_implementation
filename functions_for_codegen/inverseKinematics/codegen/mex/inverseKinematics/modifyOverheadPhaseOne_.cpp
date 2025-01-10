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
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo jf_emlrtRSI{
    1,                         // lineNo
    "modifyOverheadPhaseOne_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/modifyOverheadPhaseOne_.p" // pathName
};

static emlrtBCInfo hb_emlrtBCI{
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
void modifyOverheadPhaseOne_(const emlrtStack &sp, j_struct_T &obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  int32_T idxEq;
  int32_T idxStartIneq;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b = obj.sizes[0];
  st.site = &jf_emlrtRSI;
  if (obj.sizes[0] > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < b; idx++) {
    i = obj.ATwset.size(0);
    idxEq = obj.nVar + obj.ldA * idx;
    if ((idxEq < 1) || (idxEq > i)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, i, &hb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.ATwset[idxEq - 1] = 0.0;
  }
  b = obj.sizes[1];
  st.site = &jf_emlrtRSI;
  if (obj.sizes[1] > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < b; idx++) {
    idxEq = obj.nVar + obj.ldA * idx;
    i = obj.Aeq.size(0);
    if ((idxEq < 1) || (idxEq > i)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, i, &hb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.Aeq[idxEq - 1] = 0.0;
    i = obj.ATwset.size(0);
    idxEq += obj.ldA * (obj.isActiveIdx[1] - 1);
    if ((idxEq < 1) || (idxEq > i)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, i, &hb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.ATwset[idxEq - 1] = 0.0;
  }
  st.site = &jf_emlrtRSI;
  i = obj.indexLB.size(0);
  if ((obj.sizes[3] < 1) || (obj.sizes[3] > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.sizes[3], 1, i, &hb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.indexLB[obj.sizes[3] - 1] = obj.nVar;
  i = obj.lb.size(0);
  if ((obj.nVar < 1) || (obj.nVar > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.nVar, 1, i, &hb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.lb[obj.nVar - 1] = 1.0E-5;
  idxStartIneq = obj.isActiveIdx[2];
  b = obj.nActiveConstr;
  st.site = &jf_emlrtRSI;
  if ((obj.isActiveIdx[2] <= obj.nActiveConstr) &&
      (obj.nActiveConstr > 2147483646)) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{idxStartIneq}; idx <= b; idx++) {
    i = obj.ATwset.size(0);
    idxEq = obj.nVar + obj.ldA * (idx - 1);
    if ((idxEq < 1) || (idxEq > i)) {
      emlrtDynamicBoundsCheckR2012b(idxEq, 1, i, &hb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.ATwset[idxEq - 1] = -1.0;
  }
  if (obj.nWConstr[4] > 0) {
    b = obj.sizesNormal[4];
    st.site = &jf_emlrtRSI;
    if (obj.sizesNormal[4] + 1 > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx <= b; idx++) {
      i = obj.isActiveConstr.size(0);
      idxEq = obj.isActiveIdx[4] + idx;
      if ((idxEq < 1) || (idxEq > i)) {
        emlrtDynamicBoundsCheckR2012b(idxEq, 1, i, &hb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.isActiveConstr[idxEq - 1] = false;
    }
  }
  i = obj.isActiveConstr.size(0);
  idxEq = obj.isActiveIdx[4] - 1;
  if ((idxEq < 1) || (idxEq > i)) {
    emlrtDynamicBoundsCheckR2012b(idxEq, 1, i, &hb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.isActiveConstr[idxEq - 1] = false;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (modifyOverheadPhaseOne_.cpp)
