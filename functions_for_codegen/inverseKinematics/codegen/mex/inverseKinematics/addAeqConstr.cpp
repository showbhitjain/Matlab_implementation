//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// addAeqConstr.cpp
//
// Code generation for function 'addAeqConstr'
//

// Include files
#include "addAeqConstr.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "moveConstraint_.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ui_emlrtRSI{
    1,              // lineNo
    "addAeqConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAeqConstr.p" // pathName
};

static emlrtBCInfo md_emlrtBCI{
    -1,             // iFirst
    -1,             // iLast
    1,              // lineNo
    1,              // colNo
    "",             // aName
    "addAeqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAeqConstr.p", // pName
    0                             // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void addAeqConstr(const emlrtStack &sp, j_struct_T &obj, int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T totalEq;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  totalEq = (obj.nWConstr[0] + obj.nWConstr[1]) + 1;
  if ((obj.nActiveConstr == totalEq - 1) && (idx_local > obj.nWConstr[1])) {
    int32_T b;
    int32_T i;
    int32_T i1;
    int32_T iAeq0;
    int32_T iAw0;
    st.site = &ui_emlrtRSI;
    obj.nWConstr[1]++;
    i = obj.isActiveConstr.size(0);
    i1 = (obj.isActiveIdx[1] + idx_local) - 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &sc_emlrtBCI, &st);
    }
    obj.isActiveConstr[i1 - 1] = true;
    obj.nActiveConstr++;
    i = obj.Wid.size(0);
    if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i)) {
      emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i, &sc_emlrtBCI, &st);
    }
    i = obj.nActiveConstr - 1;
    obj.Wid[i] = 2;
    i1 = obj.Wlocalidx.size(0);
    if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
      emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &sc_emlrtBCI,
                                    &st);
    }
    obj.Wlocalidx[i] = idx_local;
    iAeq0 = obj.ldA * (idx_local - 1);
    iAw0 = obj.ldA * i;
    b = obj.nVar;
    st.site = &ui_emlrtRSI;
    if (obj.nVar > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < b; idx++) {
      int32_T i2;
      i1 = obj.Aeq.size(0);
      i2 = (iAeq0 + idx) + 1;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &md_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i1 = obj.ATwset.size(0);
      totalEq = (iAw0 + idx) + 1;
      if ((totalEq < 1) || (totalEq > i1)) {
        emlrtDynamicBoundsCheckR2012b(totalEq, 1, i1, &md_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[totalEq - 1] = obj.Aeq[i2 - 1];
    }
    i1 = obj.beq.size[0];
    if ((idx_local < 1) || (idx_local > i1)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, i1, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i1 = obj.bwset.size(0);
    if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
      emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.bwset[i] = obj.beq.data[idx_local - 1];
  } else {
    int32_T b;
    int32_T i;
    int32_T i1;
    int32_T iAeq0;
    int32_T iAw0;
    obj.nActiveConstr++;
    st.site = &ui_emlrtRSI;
    moveConstraint_(st, obj, totalEq, obj.nActiveConstr);
    obj.nWConstr[1]++;
    i = obj.isActiveConstr.size(0);
    i1 = (obj.isActiveIdx[1] + idx_local) - 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &md_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.isActiveConstr[i1 - 1] = true;
    i = obj.Wid.size(0);
    if ((totalEq < 1) || (totalEq > i)) {
      emlrtDynamicBoundsCheckR2012b(totalEq, 1, i, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.Wid[totalEq - 1] = 2;
    i = obj.Wlocalidx.size(0);
    if (totalEq > i) {
      emlrtDynamicBoundsCheckR2012b(totalEq, 1, i, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.Wlocalidx[totalEq - 1] = idx_local;
    iAeq0 = obj.ldA * (idx_local - 1);
    iAw0 = obj.ldA * (totalEq - 1);
    b = obj.nVar;
    st.site = &ui_emlrtRSI;
    if (obj.nVar > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < b; idx++) {
      int32_T i2;
      i = obj.Aeq.size(0);
      i1 = (iAeq0 + idx) + 1;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &md_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = obj.ATwset.size(0);
      i2 = (iAw0 + idx) + 1;
      if ((i2 < 1) || (i2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i, &md_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.ATwset[i2 - 1] = obj.Aeq[i1 - 1];
    }
    i = obj.beq.size[0];
    if ((idx_local < 1) || (idx_local > i)) {
      emlrtDynamicBoundsCheckR2012b(idx_local, 1, i, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = obj.bwset.size(0);
    if (totalEq > i) {
      emlrtDynamicBoundsCheckR2012b(totalEq, 1, i, &md_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.bwset[totalEq - 1] = obj.beq.data[idx_local - 1];
  }
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (addAeqConstr.cpp)
