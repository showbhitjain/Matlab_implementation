//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compressBounds.cpp
//
// Code generation for function 'compressBounds'
//

// Include files
#include "compressBounds.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ac_emlrtRSI{
    1,                // lineNo
    "compressBounds", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/compressBounds.p" // pathName
};

static emlrtBCInfo lb_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "compressBounds", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/compressBounds.p", // pName
    0                               // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int32_T compressBounds(const emlrtStack &sp, int32_T nVar,
                       array<int32_T, 1U> &indexLB, array<int32_T, 1U> &indexUB,
                       array<int32_T, 1U> &indexFixed,
                       const array<real_T, 2U> &lb, const array<real_T, 2U> &ub,
                       int32_T &mUB, int32_T &mFixed)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T mLB;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mLB = 0;
  mUB = 0;
  mFixed = 0;
  if (ub.size(0) != 0) {
    if (lb.size(0) != 0) {
      st.site = &ac_emlrtRSI;
      if (nVar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx < nVar; idx++) {
        real_T d;
        int32_T i;
        boolean_T guard1;
        if ((idx + 1 < 1) || (idx + 1 > lb.size(0))) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb.size(0), &lb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        d = lb[idx];
        guard1 = false;
        if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
          if (idx + 1 > lb.size(0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb.size(0), &lb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (idx + 1 > ub.size(0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub.size(0), &lb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (muDoubleScalarAbs(d - ub[idx]) < 1.0E-6) {
            mFixed++;
            i = indexFixed.size(0);
            if ((mFixed < 1) || (mFixed > i)) {
              emlrtDynamicBoundsCheckR2012b(mFixed, 1, i, &lb_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            indexFixed[mFixed - 1] = idx + 1;
            if (idx + 1 > ub.size(0)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub.size(0),
                                            &lb_emlrtBCI, (emlrtConstCTX)&sp);
            }
            if (idx + 1 > lb.size(0)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb.size(0),
                                            &lb_emlrtBCI, (emlrtConstCTX)&sp);
            }
          } else {
            mLB++;
            i = indexLB.size(0);
            if ((mLB < 1) || (mLB > i)) {
              emlrtDynamicBoundsCheckR2012b(mLB, 1, i, &lb_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            indexLB[mLB - 1] = idx + 1;
            if (idx + 1 > lb.size(0)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb.size(0),
                                            &lb_emlrtBCI, (emlrtConstCTX)&sp);
            }
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard1) {
          if (idx + 1 > ub.size(0)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub.size(0), &lb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          d = ub[idx];
          if ((!muDoubleScalarIsInf(d)) && (!muDoubleScalarIsNaN(d))) {
            mUB++;
            i = indexUB.size(0);
            if ((mUB < 1) || (mUB > i)) {
              emlrtDynamicBoundsCheckR2012b(mUB, 1, i, &lb_emlrtBCI,
                                            (emlrtConstCTX)&sp);
            }
            indexUB[mUB - 1] = idx + 1;
            if (idx + 1 > ub.size(0)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub.size(0),
                                            &lb_emlrtBCI, (emlrtConstCTX)&sp);
            }
          }
        }
      }
    } else {
      st.site = &ac_emlrtRSI;
      if (nVar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx < nVar; idx++) {
        boolean_T b;
        b = ((idx + 1 < 1) || (idx + 1 > ub.size(0)));
        if (b) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub.size(0), &lb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((!muDoubleScalarIsInf(ub[idx])) &&
            (!muDoubleScalarIsNaN(ub[idx]))) {
          int32_T i;
          mUB++;
          i = indexUB.size(0);
          if ((mUB < 1) || (mUB > i)) {
            emlrtDynamicBoundsCheckR2012b(mUB, 1, i, &lb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          indexUB[mUB - 1] = idx + 1;
        }
      }
    }
  } else if (lb.size(0) != 0) {
    st.site = &ac_emlrtRSI;
    if (nVar > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < nVar; idx++) {
      boolean_T b;
      b = ((idx + 1 < 1) || (idx + 1 > lb.size(0)));
      if (b) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb.size(0), &lb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((!muDoubleScalarIsInf(lb[idx])) && (!muDoubleScalarIsNaN(lb[idx]))) {
        int32_T i;
        mLB++;
        i = indexLB.size(0);
        if ((mLB < 1) || (mLB > i)) {
          emlrtDynamicBoundsCheckR2012b(mLB, 1, i, &lb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        indexLB[mLB - 1] = idx + 1;
      }
    }
  }
  return mLB;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compressBounds.cpp)
