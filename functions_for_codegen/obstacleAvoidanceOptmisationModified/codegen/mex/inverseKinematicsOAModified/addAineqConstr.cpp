//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// addAineqConstr.cpp
//
// Code generation for function 'addAineqConstr'
//

// Include files
#include "addAineqConstr.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ni_emlrtRSI{
    1,                // lineNo
    "addAineqConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p" // pathName
};

static emlrtBCInfo wd_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "addAineqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addAineqConstr.p", // pName
    0                               // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void addAineqConstr(const emlrtStack &sp, d_struct_T &obj, int32_T idx_local)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_tmp;
  int32_T i;
  int32_T i1;
  int32_T iAineq0;
  int32_T iAw0;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ni_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  obj.nWConstr[2]++;
  i = obj.isActiveConstr.size[0];
  i1 = (obj.isActiveIdx[2] + idx_local) - 1;
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
  obj.Wid.data[i] = 3;
  i1 = obj.Wlocalidx.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &vd_emlrtBCI, &st);
  }
  obj.Wlocalidx.data[i] = idx_local;
  iAineq0 = obj.ldA * (idx_local - 1) + 1;
  iAw0 = obj.ldA * i + 1;
  b_tmp = obj.nVar - 1;
  st.site = &ni_emlrtRSI;
  if (b_tmp > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx <= b_tmp; idx++) {
    int32_T i2;
    int32_T i3;
    i1 = obj.Aineq.size(0);
    i2 = iAineq0 + idx;
    if ((i2 < 1) || (i2 > i1)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &wd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i1 = obj.ATwset.size(0);
    i3 = iAw0 + idx;
    if ((i3 < 1) || (i3 > i1)) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i1, &wd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.ATwset[i3 - 1] = obj.Aineq[i2 - 1];
  }
  i1 = obj.bineq.size[0];
  if ((idx_local < 1) || (idx_local > i1)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, i1, &wd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i1 = obj.bwset.size[0];
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &wd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.bwset.data[i] = obj.bineq.data[idx_local - 1];
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (addAineqConstr.cpp)
