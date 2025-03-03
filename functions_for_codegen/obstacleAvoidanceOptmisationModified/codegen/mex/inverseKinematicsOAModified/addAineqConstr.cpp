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
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo li_emlrtRSI{
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
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T iAineq0;
  int32_T iAw0;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &li_emlrtRSI;
  obj.nWConstr[2]++;
  i = obj.isActiveConstr.size(0);
  i1 = (obj.isActiveIdx[2] + idx_local) - 1;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vd_emlrtBCI, &st);
  }
  obj.isActiveConstr[i1 - 1] = true;
  obj.nActiveConstr++;
  i = obj.Wid.size(0);
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i, &vd_emlrtBCI, &st);
  }
  i = obj.nActiveConstr - 1;
  obj.Wid[i] = 3;
  i1 = obj.Wlocalidx.size(0);
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &vd_emlrtBCI, &st);
  }
  obj.Wlocalidx[i] = idx_local;
  iAineq0 = obj.ldA * (idx_local - 1) + 1;
  iAw0 = obj.ldA * i + 1;
  i1 = obj.nVar - 1;
  for (int32_T idx{0}; idx <= i1; idx++) {
    int32_T i2;
    int32_T i3;
    int32_T i4;
    i2 = obj.Aineq.size(0);
    i3 = iAineq0 + idx;
    if ((i3 < 1) || (i3 > i2)) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &wd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i2 = obj.ATwset.size(0);
    i4 = iAw0 + idx;
    if ((i4 < 1) || (i4 > i2)) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, i2, &wd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.ATwset[i4 - 1] = obj.Aineq[i3 - 1];
  }
  i1 = obj.bineq.size(0);
  if ((idx_local < 1) || (idx_local > i1)) {
    emlrtDynamicBoundsCheckR2012b(idx_local, 1, i1, &wd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i1 = obj.bwset.size(0);
  if ((obj.nActiveConstr < 1) || (obj.nActiveConstr > i1)) {
    emlrtDynamicBoundsCheckR2012b(obj.nActiveConstr, 1, i1, &wd_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.bwset[i] = obj.bineq[idx_local - 1];
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (addAineqConstr.cpp)
