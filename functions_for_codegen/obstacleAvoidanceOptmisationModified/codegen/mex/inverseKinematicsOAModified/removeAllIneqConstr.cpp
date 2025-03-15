//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// removeAllIneqConstr.cpp
//
// Code generation for function 'removeAllIneqConstr'
//

// Include files
#include "removeAllIneqConstr.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_bounded_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ah_emlrtRSI{
    1,                     // lineNo
    "removeAllIneqConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeAllIneqConstr.p" // pathName
};

static emlrtBCInfo ad_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    1,                     // lineNo
    1,                     // colNo
    "",                    // aName
    "removeAllIneqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeAllIneqConstr.p", // pName
    0                                    // checkKind
};

static emlrtBCInfo bd_emlrtBCI{
    1,                     // iFirst
    6,                     // iLast
    1,                     // lineNo
    1,                     // colNo
    "",                    // aName
    "removeAllIneqConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeAllIneqConstr.p", // pName
    0                                    // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void removeAllIneqConstr(const emlrtStack &sp, d_struct_T &obj)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T idxStartIneq_tmp;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idxStartIneq_tmp = obj.nWConstr[0] + obj.nWConstr[1];
  idxStartIneq = idxStartIneq_tmp + 1;
  idxEndIneq = obj.nActiveConstr;
  st.site = &ah_emlrtRSI;
  if ((idxStartIneq_tmp + 1 <= obj.nActiveConstr) &&
      (obj.nActiveConstr > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx_global{idxStartIneq}; idx_global <= idxEndIneq;
       idx_global++) {
    int32_T i;
    int32_T i1;
    i = obj.Wid.size[0];
    if ((idx_global < 1) || (idx_global > i)) {
      emlrtDynamicBoundsCheckR2012b(idx_global, 1, i, &ad_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = obj.Wlocalidx.size[0];
    if (idx_global > i) {
      emlrtDynamicBoundsCheckR2012b(idx_global, 1, i, &ad_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = obj.Wid.data[idx_global - 1];
    if ((i < 1) || (i > 6)) {
      emlrtDynamicBoundsCheckR2012b(obj.Wid.data[idx_global - 1], 1, 6,
                                    &bd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    i1 = obj.isActiveConstr.size[0];
    i = (obj.isActiveIdx[i - 1] + obj.Wlocalidx.data[idx_global - 1]) - 1;
    if ((i < 1) || (i > i1)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i1, &ad_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.isActiveConstr.data[i - 1] = false;
  }
  obj.nWConstr[2] = 0;
  obj.nWConstr[3] = 0;
  obj.nWConstr[4] = 0;
  obj.nActiveConstr = idxStartIneq_tmp;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (removeAllIneqConstr.cpp)
