//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// moveConstraint_.cpp
//
// Code generation for function 'moveConstraint_'
//

// Include files
#include "moveConstraint_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo eg_emlrtRSI{
    1,                 // lineNo
    "moveConstraint_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/moveConstraint_.p" // pathName
};

static emlrtBCInfo tc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "moveConstraint_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/moveConstraint_.p", // pName
    0                                // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void moveConstraint_(const emlrtStack &sp, d_struct_T &obj,
                     int32_T idx_global_start, int32_T idx_global_dest)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T i;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  i = obj.Wid.size(0);
  if ((idx_global_start < 1) || (idx_global_start > i)) {
    emlrtDynamicBoundsCheckR2012b(idx_global_start, 1, i, &tc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i = obj.Wid.size(0);
  if ((idx_global_dest < 1) || (idx_global_dest > i)) {
    emlrtDynamicBoundsCheckR2012b(idx_global_dest, 1, i, &tc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.Wid[idx_global_dest - 1] = obj.Wid[idx_global_start - 1];
  i = obj.Wlocalidx.size(0);
  if (idx_global_start > i) {
    emlrtDynamicBoundsCheckR2012b(idx_global_start, 1, i, &tc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i = obj.Wlocalidx.size(0);
  if (idx_global_dest > i) {
    emlrtDynamicBoundsCheckR2012b(idx_global_dest, 1, i, &tc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.Wlocalidx[idx_global_dest - 1] = obj.Wlocalidx[idx_global_start - 1];
  b = obj.nVar;
  st.site = &eg_emlrtRSI;
  if (obj.nVar > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < b; idx++) {
    int32_T i1;
    int32_T i2;
    i = obj.ATwset.size(0);
    i1 = (idx + obj.ldA * (idx_global_start - 1)) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &tc_emlrtBCI, (emlrtConstCTX)&sp);
    }
    i = obj.ATwset.size(0);
    i2 = (idx + obj.ldA * (idx_global_dest - 1)) + 1;
    if ((i2 < 1) || (i2 > i)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i, &tc_emlrtBCI, (emlrtConstCTX)&sp);
    }
    obj.ATwset[i2 - 1] = obj.ATwset[i1 - 1];
  }
  i = obj.bwset.size(0);
  if (idx_global_start > i) {
    emlrtDynamicBoundsCheckR2012b(idx_global_start, 1, i, &tc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i = obj.bwset.size(0);
  if (idx_global_dest > i) {
    emlrtDynamicBoundsCheckR2012b(idx_global_dest, 1, i, &tc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  obj.bwset[idx_global_dest - 1] = obj.bwset[idx_global_start - 1];
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (moveConstraint_.cpp)
