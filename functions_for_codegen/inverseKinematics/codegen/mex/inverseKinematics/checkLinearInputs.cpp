//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkLinearInputs.cpp
//
// Code generation for function 'checkLinearInputs'
//

// Include files
#include "checkLinearInputs.h"
#include "all.h"
#include "any1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo p_emlrtRSI{
    1,                   // lineNo
    "checkLinearInputs", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+validate/"
    "checkLinearInputs.p" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    1,             // lineNo
    "checkBounds", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkBounds.p" // pathName
};

static emlrtRTEInfo d_emlrtRTEI{
    1,                   // lineNo
    1,                   // colNo
    "checkLinearInputs", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+validate/"
    "checkLinearInputs.p" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    1,             // lineNo
    1,             // colNo
    "checkBounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkBounds.p" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    1,             // lineNo
    1,             // colNo
    "",            // aName
    "checkBounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkBounds.p", // pName
    0                // checkKind
};

static emlrtRTEInfo cb_emlrtRTEI{
    14,                                                                // lineNo
    5,                                                                 // colNo
    "isfinite",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/isfinite.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    16,                                                             // lineNo
    13,                                                             // colNo
    "isnan",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/isnan.m" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace validate {
real_T checkLinearInputs(const emlrtStack &sp, int32_T nVar,
                         const array<real_T, 2U> &Aeq, const real_T beq_data[],
                         int32_T beq_size, const array<real_T, 1U> &lb,
                         const array<real_T, 1U> &ub)
{
  array<boolean_T, 1U> b_lb;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T exitflag;
  int32_T unnamed_idx_0;
  boolean_T guard1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (Aeq.size(1) != 0) {
    unnamed_idx_0 = 6 * Aeq.size(1);
    b_lb.set_size(&cb_emlrtRTEI, &sp, unnamed_idx_0);
    for (int32_T i{0}; i < unnamed_idx_0; i++) {
      b_lb[i] =
          ((!muDoubleScalarIsInf(Aeq[i])) && (!muDoubleScalarIsNaN(Aeq[i])));
    }
    st.site = &p_emlrtRSI;
    if (!all(st, b_lb)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &d_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
          "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 3, "Aeq");
    }
  }
  if (beq_size != 0) {
    b_lb.set_size(&cb_emlrtRTEI, &sp, beq_size);
    for (int32_T i{0}; i < beq_size; i++) {
      real_T d;
      d = beq_data[i];
      b_lb[i] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
    }
    st.site = &p_emlrtRSI;
    if (!all(st, b_lb)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &d_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
          "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 3, "Beq");
    }
  }
  if ((Aeq.size(1) != 0) && (Aeq.size(1) != nVar)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &d_emlrtRTEI, "optimlib_codegen:common:WrongNumberOfColumnsInAeq",
        "optimlib_codegen:common:WrongNumberOfColumnsInAeq", 2, 12, nVar);
  }
  if ((Aeq.size(1) != 0) && (beq_size != 6)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &d_emlrtRTEI, "optimlib_codegen:common:AeqAndBeqInconsistent",
        "optimlib_codegen:common:AeqAndBeqInconsistent", 0);
  }
  st.site = &p_emlrtRSI;
  if ((lb.size(0) != 0) && (lb.size(0) != nVar)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &e_emlrtRTEI, "optimlib_codegen:common:InvalidPartialBounds",
        "optimlib_codegen:common:InvalidPartialBounds", 5, 4, 2, "lb", 12,
        nVar);
  }
  b_lb.set_size(&e_emlrtRTEI, &st, lb.size(0));
  unnamed_idx_0 = lb.size(0);
  for (int32_T i{0}; i < unnamed_idx_0; i++) {
    b_lb[i] = (lb[i] >= rtInf);
  }
  guard1 = false;
  b_st.site = &r_emlrtRSI;
  if (any(b_st, b_lb)) {
    guard1 = true;
  } else {
    b_lb.set_size(&db_emlrtRTEI, &st, lb.size(0));
    unnamed_idx_0 = lb.size(0);
    for (int32_T i{0}; i < unnamed_idx_0; i++) {
      b_lb[i] = muDoubleScalarIsNaN(lb[i]);
    }
    b_st.site = &r_emlrtRSI;
    if (any(b_st, b_lb)) {
      guard1 = true;
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &e_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetectedLB",
        "optimlib_codegen:common:InfNaNComplexDetectedLB", 0);
  }
  if ((ub.size(0) != 0) && (ub.size(0) != nVar)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &e_emlrtRTEI, "optimlib_codegen:common:InvalidPartialBounds",
        "optimlib_codegen:common:InvalidPartialBounds", 5, 4, 2, "ub", 12,
        nVar);
  }
  b_lb.set_size(&e_emlrtRTEI, &st, ub.size(0));
  unnamed_idx_0 = ub.size(0);
  for (int32_T i{0}; i < unnamed_idx_0; i++) {
    b_lb[i] = (ub[i] <= rtMinusInf);
  }
  guard1 = false;
  b_st.site = &r_emlrtRSI;
  if (any(b_st, b_lb)) {
    guard1 = true;
  } else {
    b_lb.set_size(&db_emlrtRTEI, &st, ub.size(0));
    unnamed_idx_0 = ub.size(0);
    for (int32_T i{0}; i < unnamed_idx_0; i++) {
      b_lb[i] = muDoubleScalarIsNaN(ub[i]);
    }
    b_st.site = &r_emlrtRSI;
    if (any(b_st, b_lb)) {
      guard1 = true;
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &e_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetectedUB",
        "optimlib_codegen:common:InfNaNComplexDetectedUB", 0);
  }
  exitflag = rtInf;
  if ((lb.size(0) != 0) && (ub.size(0) != 0)) {
    boolean_T exitg1;
    b_st.site = &r_emlrtRSI;
    if (nVar > 2147483646) {
      c_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    unnamed_idx_0 = 0;
    exitg1 = false;
    while ((!exitg1) && (unnamed_idx_0 <= nVar - 1)) {
      if ((unnamed_idx_0 + 1 < 1) || (unnamed_idx_0 + 1 > lb.size(0))) {
        emlrtDynamicBoundsCheckR2012b(unnamed_idx_0 + 1, 1, lb.size(0),
                                      &emlrtBCI, &st);
      }
      if ((unnamed_idx_0 + 1 < 1) || (unnamed_idx_0 + 1 > ub.size(0))) {
        emlrtDynamicBoundsCheckR2012b(unnamed_idx_0 + 1, 1, ub.size(0),
                                      &emlrtBCI, &st);
      }
      if (lb[unnamed_idx_0] > ub[unnamed_idx_0]) {
        exitflag = -2.0;
        exitg1 = true;
      } else {
        unnamed_idx_0++;
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return exitflag;
}

} // namespace validate
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkLinearInputs.cpp)
