//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// updateWorkingSetForNewQP.cpp
//
// Code generation for function 'updateWorkingSetForNewQP'
//

// Include files
#include "updateWorkingSetForNewQP.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ye_emlrtRSI{
    1,                          // lineNo
    "updateWorkingSetForNewQP", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p" // pathName
};

static emlrtBCInfo le_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    1,                          // lineNo
    1,                          // colNo
    "",                         // aName
    "updateWorkingSetForNewQP", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/updateWorkingSetForNewQP.p", // pName
    0                                       // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
void updateWorkingSetForNewQP(const emlrtStack &sp, const array<real_T, 1U> &xk,
                              d_struct_T &WorkingSet, int32_T mIneq,
                              const real_T cIneq_data[], int32_T cIneq_size,
                              int32_T mEq, const real_T cEq_data[],
                              int32_T cEq_size, int32_T mLB,
                              const real_T lb_data[], int32_T lb_size,
                              int32_T mUB, const real_T ub_data[],
                              int32_T ub_size, int32_T mFixed)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T y;
  boolean_T hasLB;
  boolean_T hasUB;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ye_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (mEq > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mEq; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > cEq_size)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cEq_size, &le_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    y = WorkingSet.beq.size[0];
    if (idx + 1 > y) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &le_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    WorkingSet.beq.data[idx] = -cEq_data[idx];
    y = WorkingSet.beq.size[0];
    if (idx + 1 > y) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &le_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    y = WorkingSet.bwset.size[0];
    i = (mFixed + idx) + 1;
    if ((i < 1) || (i > y)) {
      emlrtDynamicBoundsCheckR2012b(i, 1, y, &le_emlrtBCI, (emlrtConstCTX)&sp);
    }
    WorkingSet.bwset.data[i - 1] = WorkingSet.beq.data[idx];
  }
  st.site = &ye_emlrtRSI;
  st.site = &ye_emlrtRSI;
  if (mIneq > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  y = static_cast<uint8_T>(mIneq);
  for (int32_T idx{0}; idx < y; idx++) {
    if (idx + 1 > cIneq_size) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, cIneq_size, &le_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = WorkingSet.bineq.size[0];
    if (idx + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &le_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    WorkingSet.bineq.data[idx] = -cIneq_data[idx];
  }
  hasLB = (lb_size != 0);
  hasUB = (ub_size != 0);
  if (hasLB) {
    st.site = &ye_emlrtRSI;
    if (mLB > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < mLB; idx++) {
      y = WorkingSet.indexLB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > y)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &le_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((WorkingSet.indexLB[idx] < 1) ||
          (WorkingSet.indexLB[idx] > lb_size)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, lb_size,
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((WorkingSet.indexLB[idx] < 1) ||
          (WorkingSet.indexLB[idx] > xk.size(0))) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, xk.size(0),
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      y = WorkingSet.lb.size(0);
      if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > y)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, y,
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      WorkingSet.lb[WorkingSet.indexLB[idx] - 1] =
          -lb_data[WorkingSet.indexLB[idx] - 1] +
          xk[WorkingSet.indexLB[idx] - 1];
    }
  }
  if (hasUB) {
    st.site = &ye_emlrtRSI;
    if (mUB > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < mUB; idx++) {
      y = WorkingSet.indexUB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > y)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &le_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((WorkingSet.indexUB[idx] < 1) ||
          (WorkingSet.indexUB[idx] > ub_size)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, ub_size,
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((WorkingSet.indexUB[idx] < 1) ||
          (WorkingSet.indexUB[idx] > xk.size(0))) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, xk.size(0),
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      y = WorkingSet.ub.size(0);
      if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > y)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, y,
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      WorkingSet.ub[WorkingSet.indexUB[idx] - 1] =
          ub_data[WorkingSet.indexUB[idx] - 1] -
          xk[WorkingSet.indexUB[idx] - 1];
    }
  }
  if (hasLB && hasUB) {
    st.site = &ye_emlrtRSI;
    if (mFixed > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < mFixed; idx++) {
      real_T d;
      y = WorkingSet.indexFixed.size(0);
      if ((idx + 1 < 1) || (idx + 1 > y)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &le_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((WorkingSet.indexFixed[idx] < 1) ||
          (WorkingSet.indexFixed[idx] > ub_size)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[idx], 1, ub_size,
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((WorkingSet.indexFixed[idx] < 1) ||
          (WorkingSet.indexFixed[idx] > xk.size(0))) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[idx], 1, xk.size(0),
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      y = WorkingSet.ub.size(0);
      if ((WorkingSet.indexFixed[idx] < 1) ||
          (WorkingSet.indexFixed[idx] > y)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[idx], 1, y,
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      d = ub_data[WorkingSet.indexFixed[idx] - 1] -
          xk[WorkingSet.indexFixed[idx] - 1];
      WorkingSet.ub[WorkingSet.indexFixed[idx] - 1] = d;
      if ((WorkingSet.indexFixed[idx] < 1) ||
          (WorkingSet.indexFixed[idx] > ub_size)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[idx], 1, ub_size,
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((WorkingSet.indexFixed[idx] < 1) ||
          (WorkingSet.indexFixed[idx] > xk.size(0))) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.indexFixed[idx], 1, xk.size(0),
                                      &le_emlrtBCI, (emlrtConstCTX)&sp);
      }
      y = WorkingSet.bwset.size[0];
      if ((idx + 1 < 1) || (idx + 1 > y)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, y, &le_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      WorkingSet.bwset.data[idx] = d;
    }
  }
  y = mFixed + mEq;
  if (WorkingSet.nActiveConstr > y) {
    int32_T b;
    int32_T ineqStart;
    y++;
    ineqStart = muIntScalarMax_sint32(y, 1);
    b = WorkingSet.nActiveConstr;
    st.site = &ye_emlrtRSI;
    if ((ineqStart <= WorkingSet.nActiveConstr) &&
        (WorkingSet.nActiveConstr > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{ineqStart}; idx <= b; idx++) {
      y = WorkingSet.Wlocalidx.size[0];
      if (idx > y) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, y, &le_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      y = WorkingSet.Wid.size[0];
      if (idx > y) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, y, &le_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      switch (WorkingSet.Wid.data[idx - 1]) {
      case 4:
        y = WorkingSet.indexLB.size(0);
        i = WorkingSet.Wlocalidx.data[idx - 1];
        if ((i < 1) || (i > y)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.Wlocalidx.data[idx - 1], 1,
                                        y, &le_emlrtBCI, (emlrtConstCTX)&sp);
        }
        y = WorkingSet.lb.size(0);
        i = WorkingSet.indexLB[i - 1];
        if ((i < 1) || (i > y)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, y, &le_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        y = WorkingSet.bwset.size[0];
        if (idx > y) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, y, &le_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        WorkingSet.bwset.data[idx - 1] = WorkingSet.lb[i - 1];
        break;
      case 5:
        y = WorkingSet.indexUB.size(0);
        i = WorkingSet.Wlocalidx.data[idx - 1];
        if ((i < 1) || (i > y)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.Wlocalidx.data[idx - 1], 1,
                                        y, &le_emlrtBCI, (emlrtConstCTX)&sp);
        }
        y = WorkingSet.ub.size(0);
        i = WorkingSet.indexUB[WorkingSet.Wlocalidx.data[idx - 1] - 1];
        if ((i < 1) || (i > y)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, y, &le_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        y = WorkingSet.bwset.size[0];
        if (idx > y) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, y, &le_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        WorkingSet.bwset.data[idx - 1] = WorkingSet.ub[i - 1];
        break;
      default:
        y = WorkingSet.bineq.size[0];
        i = WorkingSet.Wlocalidx.data[idx - 1];
        if ((i < 1) || (i > y)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.Wlocalidx.data[idx - 1], 1,
                                        y, &le_emlrtBCI, (emlrtConstCTX)&sp);
        }
        y = WorkingSet.bwset.size[0];
        if (idx > y) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, y, &le_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        WorkingSet.bwset.data[idx - 1] = WorkingSet.bineq.data[i - 1];
        break;
      }
    }
  }
}

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (updateWorkingSetForNewQP.cpp)
