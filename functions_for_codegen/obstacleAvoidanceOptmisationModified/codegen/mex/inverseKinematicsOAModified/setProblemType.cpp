//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// setProblemType.cpp
//
// Code generation for function 'setProblemType'
//

// Include files
#include "setProblemType.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "modifyOverheadPhaseOne_.h"
#include "modifyOverheadRegularized_.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void setProblemType(const emlrtStack &sp, d_struct_T &obj, int32_T PROBLEM_TYPE)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (PROBLEM_TYPE) {
  case 3: {
    int32_T i;
    obj.nVar = obj.nVarOrig;
    obj.mConstr = obj.mConstrOrig;
    if (obj.nWConstr[4] > 0) {
      int32_T b;
      b = obj.sizesNormal[4];
      st.site = &bf_emlrtRSI;
      if (obj.sizesNormal[4] > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx < b; idx++) {
        int32_T i1;
        int32_T i2;
        i = obj.isActiveConstr.size(0);
        i1 = obj.isActiveIdx[4] + idx;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ub_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = obj.isActiveConstr.size(0);
        i2 = obj.isActiveIdxNormal[4] + idx;
        if ((i2 < 1) || (i2 > i)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ub_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        obj.isActiveConstr[i2 - 1] = obj.isActiveConstr[i1 - 1];
      }
    }
    for (i = 0; i < 5; i++) {
      obj.sizes[i] = obj.sizesNormal[i];
    }
    for (i = 0; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxNormal[i];
    }
  } break;
  case 1:
    obj.nVar = obj.nVarOrig + 1;
    obj.mConstr = obj.mConstrOrig + 1;
    for (int32_T i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesPhaseOne[i];
    }
    for (int32_T i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxPhaseOne[i];
    }
    st.site = &bf_emlrtRSI;
    modifyOverheadPhaseOne_(st, obj);
    break;
  case 2:
    obj.nVar = obj.nVarMax - 1;
    obj.mConstr = obj.mConstrMax - 1;
    for (int32_T i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegularized[i];
    }
    if (obj.probType != 4) {
      st.site = &bf_emlrtRSI;
      modifyOverheadRegularized_(st, obj);
    }
    for (int32_T i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegularized[i];
    }
    break;
  default:
    obj.nVar = obj.nVarMax;
    obj.mConstr = obj.mConstrMax;
    for (int32_T i{0}; i < 5; i++) {
      obj.sizes[i] = obj.sizesRegPhaseOne[i];
    }
    for (int32_T i{0}; i < 6; i++) {
      obj.isActiveIdx[i] = obj.isActiveIdxRegPhaseOne[i];
    }
    st.site = &bf_emlrtRSI;
    modifyOverheadPhaseOne_(st, obj);
    break;
  }
  obj.probType = PROBLEM_TYPE;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (setProblemType.cpp)
