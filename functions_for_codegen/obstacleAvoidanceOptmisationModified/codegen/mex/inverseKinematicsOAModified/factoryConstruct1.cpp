//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct1.cpp
//
// Code generation for function 'factoryConstruct1'
//

// Include files
#include "factoryConstruct1.h"
#include "anonymous_function.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo xb_emlrtRSI{
    1,                  // lineNo
    "factoryConstruct", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/factoryConstruct.p" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    1,                 // lineNo
    "hasFiniteBounds", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "hasFiniteBounds.p" // pathName
};

static emlrtBCInfo i_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "hasFiniteBounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "hasFiniteBounds.p", // pName
    0                    // checkKind
};

static emlrtRTEInfo xc_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/factoryConstruct.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
void factoryConstruct(const emlrtStack &sp, const anonymous_function &objfun,
                      int32_T nVar, const array<real_T, 2U> &lb,
                      const array<real_T, 2U> &ub, l_struct_T &obj)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T idx;
  boolean_T b;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  obj.objfun = objfun;
  obj.f_1 = 0.0;
  obj.f_2 = 0.0;
  obj.nVar = nVar;
  obj.mIneq = 0;
  obj.mEq = 0;
  obj.numEvals = 0;
  obj.SpecifyObjectiveGradient = false;
  obj.SpecifyConstraintGradient = false;
  obj.isEmptyNonlcon = true;
  obj.hasLB.set_size(&xc_emlrtRTEI, &sp, nVar);
  obj.hasUB.set_size(&xc_emlrtRTEI, &sp, nVar);
  obj.FiniteDifferenceType = 0;
  st.site = &xb_emlrtRSI;
  b = false;
  idx = 1;
  switch (static_cast<uint32_T>(ub.size(0) == 0) << 1 |
          static_cast<uint32_T>(lb.size(0) == 0)) {
  case 0U: {
    real_T d;
    while ((!b) && (idx <= nVar)) {
      if ((idx < 1) || (idx > lb.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, lb.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = lb[idx - 1];
      obj.hasLB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      if (idx > ub.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ub.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = ub[idx - 1];
      obj.hasUB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      if (idx > obj.hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      if (obj.hasLB[idx - 1]) {
        b = true;
      } else {
        if (idx > obj.hasUB.size(0)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                        &st);
        }
        if (obj.hasUB[idx - 1]) {
          b = true;
        }
      }
      idx++;
    }
    while (idx <= nVar) {
      if ((idx < 1) || (idx > lb.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, lb.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = lb[idx - 1];
      obj.hasLB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      if (idx > ub.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ub.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = ub[idx - 1];
      obj.hasUB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      idx++;
    }
  } break;
  case 1U: {
    real_T d;
    while ((!b) && (idx <= nVar)) {
      if ((idx < 1) || (idx > obj.hasLB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      obj.hasLB[idx - 1] = false;
      if (idx > ub.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ub.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = ub[idx - 1];
      obj.hasUB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      if (idx > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                      &st);
      }
      b = obj.hasUB[idx - 1];
      idx++;
    }
    while (idx <= nVar) {
      if ((idx < 1) || (idx > obj.hasLB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      obj.hasLB[idx - 1] = false;
      if (idx > ub.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ub.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = ub[idx - 1];
      obj.hasUB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      idx++;
    }
  } break;
  case 2U: {
    real_T d;
    while ((!b) && (idx <= nVar)) {
      if ((idx < 1) || (idx > lb.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, lb.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = lb[idx - 1];
      obj.hasLB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      if (idx > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                      &st);
      }
      obj.hasUB[idx - 1] = false;
      if (idx > obj.hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      b = obj.hasLB[idx - 1];
      idx++;
    }
    while (idx <= nVar) {
      if ((idx < 1) || (idx > lb.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, lb.size(0), &i_emlrtBCI, &st);
      }
      if (idx > obj.hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasLB.size(0), &i_emlrtBCI,
                                      &st);
      }
      d = lb[idx - 1];
      obj.hasLB[idx - 1] =
          ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
      if (idx > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, obj.hasUB.size(0), &i_emlrtBCI,
                                      &st);
      }
      obj.hasUB[idx - 1] = false;
      idx++;
    }
  } break;
  default:
    b_st.site = &yb_emlrtRSI;
    if (nVar > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (idx = 0; idx < nVar; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > obj.hasLB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, obj.hasLB.size(0),
                                      &i_emlrtBCI, &st);
      }
      obj.hasLB[idx] = false;
      if (idx + 1 > obj.hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, obj.hasUB.size(0),
                                      &i_emlrtBCI, &st);
      }
      obj.hasUB[idx] = false;
    }
    break;
  }
  obj.hasBounds = b;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct1.cpp)
