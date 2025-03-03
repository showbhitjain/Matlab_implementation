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
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo mb_emlrtRSI{
    1,                   // lineNo
    "checkLinearInputs", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+validate/"
    "checkLinearInputs.p" // pathName
};

static emlrtRSInfo ob_emlrtRSI{
    1,             // lineNo
    "checkBounds", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkBounds.p" // pathName
};

static emlrtRTEInfo e_emlrtRTEI{
    1,                   // lineNo
    1,                   // colNo
    "checkLinearInputs", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+validate/"
    "checkLinearInputs.p" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    1,             // lineNo
    1,             // colNo
    "checkBounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+validate/"
    "checkBounds.p" // pName
};

static emlrtBCInfo h_emlrtBCI{
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

static emlrtRTEInfo tc_emlrtRTEI{
    14,                                                                // lineNo
    5,                                                                 // colNo
    "isfinite",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/isfinite.m" // pName
};

static emlrtRTEInfo uc_emlrtRTEI{
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
                         const array<real_T, 2U> &Aineq,
                         const array<real_T, 2U> &bineq,
                         const array<real_T, 2U> &Aeq, const real_T beq_data[],
                         const int32_T beq_size[2], const array<real_T, 2U> &lb,
                         const array<real_T, 2U> &ub)
{
  array<boolean_T, 2U> b_lb;
  array<boolean_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T exitflag;
  int32_T Aineq_idx_0;
  boolean_T b;
  boolean_T guard1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if ((Aineq.size(0) != 0) && (Aineq.size(1) != 0)) {
    Aineq_idx_0 = Aineq.size(0) * Aineq.size(1);
    r.set_size(&tc_emlrtRTEI, &sp, Aineq_idx_0);
    for (int32_T i{0}; i < Aineq_idx_0; i++) {
      r[i] = ((!muDoubleScalarIsInf(Aineq[i])) &&
              (!muDoubleScalarIsNaN(Aineq[i])));
    }
    st.site = &mb_emlrtRSI;
    if (!all(st, r)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &e_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
          "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 1, "A");
    }
  }
  if ((bineq.size(0) != 0) && (bineq.size(1) != 0)) {
    r.set_size(&tc_emlrtRTEI, &sp, bineq.size(0));
    Aineq_idx_0 = bineq.size(0);
    for (int32_T i{0}; i < Aineq_idx_0; i++) {
      r[i] = ((!muDoubleScalarIsInf(bineq[i])) &&
              (!muDoubleScalarIsNaN(bineq[i])));
    }
    st.site = &mb_emlrtRSI;
    if (!all(st, r)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &e_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
          "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 1, "B");
    }
  }
  if ((Aeq.size(0) != 0) && (Aeq.size(1) != 0)) {
    Aineq_idx_0 = Aeq.size(0) * Aeq.size(1);
    r.set_size(&tc_emlrtRTEI, &sp, Aineq_idx_0);
    for (int32_T i{0}; i < Aineq_idx_0; i++) {
      r[i] = ((!muDoubleScalarIsInf(Aeq[i])) && (!muDoubleScalarIsNaN(Aeq[i])));
    }
    st.site = &mb_emlrtRSI;
    if (!all(st, r)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &e_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
          "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 3, "Aeq");
    }
  }
  if ((beq_size[0] != 0) && (beq_size[1] != 0)) {
    r.set_size(&tc_emlrtRTEI, &sp, beq_size[0]);
    Aineq_idx_0 = beq_size[0];
    for (int32_T i{0}; i < Aineq_idx_0; i++) {
      real_T d;
      d = beq_data[i];
      r[i] = ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d)));
    }
    st.site = &mb_emlrtRSI;
    if (!all(st, r)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &e_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetected",
          "optimlib_codegen:common:InfNaNComplexDetected", 3, 4, 3, "Beq");
    }
  }
  b = ((Aineq.size(0) != 0) && (Aineq.size(1) != 0));
  if (b && (Aineq.size(1) != nVar)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &e_emlrtRTEI, "optimlib_codegen:common:WrongNumberOfColumnsInA",
        "optimlib_codegen:common:WrongNumberOfColumnsInA", 2, 12, nVar);
  }
  if (b && (Aineq.size(0) != bineq.size(0) * bineq.size(1))) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &e_emlrtRTEI, "optimlib_codegen:common:AAndBinInconsistent",
        "optimlib_codegen:common:AAndBinInconsistent", 0);
  }
  b = ((Aeq.size(0) != 0) && (Aeq.size(1) != 0));
  if (b && (Aeq.size(1) != nVar)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &e_emlrtRTEI, "optimlib_codegen:common:WrongNumberOfColumnsInAeq",
        "optimlib_codegen:common:WrongNumberOfColumnsInAeq", 2, 12, nVar);
  }
  if (b && (Aeq.size(0) != beq_size[0] * beq_size[1])) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &e_emlrtRTEI, "optimlib_codegen:common:AeqAndBeqInconsistent",
        "optimlib_codegen:common:AeqAndBeqInconsistent", 0);
  }
  st.site = &mb_emlrtRSI;
  if ((lb.size(0) != 0) && (lb.size(0) != nVar)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "optimlib_codegen:common:InvalidPartialBounds",
        "optimlib_codegen:common:InvalidPartialBounds", 5, 4, 2, "lb", 12,
        nVar);
  }
  b_lb.set_size(&f_emlrtRTEI, &st, lb.size(0), 1);
  Aineq_idx_0 = lb.size(0);
  for (int32_T i{0}; i < Aineq_idx_0; i++) {
    b_lb[i] = (lb[i] >= rtInf);
  }
  guard1 = false;
  b_st.site = &ob_emlrtRSI;
  if (any(b_st, b_lb)) {
    guard1 = true;
  } else {
    b_lb.set_size(&uc_emlrtRTEI, &st, lb.size(0), 1);
    Aineq_idx_0 = lb.size(0);
    for (int32_T i{0}; i < Aineq_idx_0; i++) {
      b_lb[i] = muDoubleScalarIsNaN(lb[i]);
    }
    b_st.site = &ob_emlrtRSI;
    if (any(b_st, b_lb)) {
      guard1 = true;
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetectedLB",
        "optimlib_codegen:common:InfNaNComplexDetectedLB", 0);
  }
  if ((ub.size(0) != 0) && (ub.size(0) != nVar)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "optimlib_codegen:common:InvalidPartialBounds",
        "optimlib_codegen:common:InvalidPartialBounds", 5, 4, 2, "ub", 12,
        nVar);
  }
  b_lb.set_size(&f_emlrtRTEI, &st, ub.size(0), 1);
  Aineq_idx_0 = ub.size(0);
  for (int32_T i{0}; i < Aineq_idx_0; i++) {
    b_lb[i] = (ub[i] <= rtMinusInf);
  }
  guard1 = false;
  b_st.site = &ob_emlrtRSI;
  if (any(b_st, b_lb)) {
    guard1 = true;
  } else {
    b_lb.set_size(&uc_emlrtRTEI, &st, ub.size(0), 1);
    Aineq_idx_0 = ub.size(0);
    for (int32_T i{0}; i < Aineq_idx_0; i++) {
      b_lb[i] = muDoubleScalarIsNaN(ub[i]);
    }
    b_st.site = &ob_emlrtRSI;
    if (any(b_st, b_lb)) {
      guard1 = true;
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "optimlib_codegen:common:InfNaNComplexDetectedUB",
        "optimlib_codegen:common:InfNaNComplexDetectedUB", 0);
  }
  exitflag = rtInf;
  b = (lb.size(0) == 0);
  if ((!b) && (ub.size(0) != 0)) {
    boolean_T exitg1;
    b_st.site = &ob_emlrtRSI;
    if (nVar > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    Aineq_idx_0 = 0;
    exitg1 = false;
    while ((!exitg1) && (Aineq_idx_0 <= nVar - 1)) {
      if ((Aineq_idx_0 + 1 < 1) || (Aineq_idx_0 + 1 > lb.size(0))) {
        emlrtDynamicBoundsCheckR2012b(Aineq_idx_0 + 1, 1, lb.size(0),
                                      &h_emlrtBCI, &st);
      }
      if ((Aineq_idx_0 + 1 < 1) || (Aineq_idx_0 + 1 > ub.size(0))) {
        emlrtDynamicBoundsCheckR2012b(Aineq_idx_0 + 1, 1, ub.size(0),
                                      &h_emlrtBCI, &st);
      }
      if (lb[Aineq_idx_0] > ub[Aineq_idx_0]) {
        exitflag = -2.0;
        exitg1 = true;
      } else {
        Aineq_idx_0++;
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
