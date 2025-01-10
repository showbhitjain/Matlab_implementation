//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// makeBoundFeasible.cpp
//
// Code generation for function 'makeBoundFeasible'
//

// Include files
#include "makeBoundFeasible.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo vi_emlrtRSI{
    1,                   // lineNo
    "makeBoundFeasible", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "makeBoundFeasible.p" // pathName
};

static emlrtBCInfo nd_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    1,                   // lineNo
    1,                   // colNo
    "",                  // aName
    "makeBoundFeasible", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "makeBoundFeasible.p", // pName
    0                      // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
void makeBoundFeasible(const emlrtStack &sp, array<real_T, 1U> &xk,
                       const j_struct_T &WorkingSet,
                       const array<real_T, 1U> &lb, const array<real_T, 1U> &ub)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  int32_T i;
  int32_T mLB;
  int32_T mUB;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mLB = WorkingSet.sizes[3] - 1;
  mUB = WorkingSet.sizes[4] - 1;
  if (lb.size(0) != 0) {
    if (ub.size(0) == 0) {
      st.site = &vi_emlrtRSI;
      if (WorkingSet.sizes[3] > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx <= mLB; idx++) {
        i = WorkingSet.indexLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &nd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = xk.size(0);
        if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        i = WorkingSet.lb.size(0);
        if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        d = WorkingSet.lb[WorkingSet.indexLB[idx] - 1];
        if (-xk[WorkingSet.indexLB[idx] - 1] > d) {
          i = WorkingSet.lb.size(0);
          if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                          &nd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i = WorkingSet.lb.size(0);
          if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                          &nd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i = xk.size(0);
          if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                          &nd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          xk[WorkingSet.indexLB[idx] - 1] = -d + muDoubleScalarAbs(d);
        }
      }
    } else {
      st.site = &vi_emlrtRSI;
      if (WorkingSet.sizes[3] > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx <= mLB; idx++) {
        i = WorkingSet.indexLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &nd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = xk.size(0);
        if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        i = WorkingSet.lb.size(0);
        if ((WorkingSet.indexLB[idx] < 1) || (WorkingSet.indexLB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        d = WorkingSet.lb[WorkingSet.indexLB[idx] - 1];
        if (-xk[WorkingSet.indexLB[idx] - 1] > d) {
          if ((WorkingSet.indexLB[idx] < 1) ||
              (WorkingSet.indexLB[idx] > ub.size(0))) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1,
                                          ub.size(0), &nd_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (muDoubleScalarIsInf(ub[WorkingSet.indexLB[idx] - 1])) {
            i = WorkingSet.lb.size(0);
            if ((WorkingSet.indexLB[idx] < 1) ||
                (WorkingSet.indexLB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = WorkingSet.lb.size(0);
            if ((WorkingSet.indexLB[idx] < 1) ||
                (WorkingSet.indexLB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = xk.size(0);
            if ((WorkingSet.indexLB[idx] < 1) ||
                (WorkingSet.indexLB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            xk[WorkingSet.indexLB[idx] - 1] = -d + muDoubleScalarAbs(d);
          } else {
            i = WorkingSet.ub.size(0);
            if ((WorkingSet.indexLB[idx] < 1) ||
                (WorkingSet.indexLB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = WorkingSet.lb.size(0);
            if ((WorkingSet.indexLB[idx] < 1) ||
                (WorkingSet.indexLB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = xk.size(0);
            if ((WorkingSet.indexLB[idx] < 1) ||
                (WorkingSet.indexLB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexLB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            xk[WorkingSet.indexLB[idx] - 1] =
                (WorkingSet.ub[WorkingSet.indexLB[idx] - 1] - d) / 2.0;
          }
        }
      }
    }
  }
  if (ub.size(0) != 0) {
    if (lb.size(0) == 0) {
      st.site = &vi_emlrtRSI;
      if (WorkingSet.sizes[4] > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx <= mUB; idx++) {
        i = WorkingSet.indexUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &nd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = xk.size(0);
        if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        i = WorkingSet.ub.size(0);
        if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        d = WorkingSet.ub[WorkingSet.indexUB[idx] - 1];
        if (xk[WorkingSet.indexUB[idx] - 1] > d) {
          i = WorkingSet.ub.size(0);
          if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                          &nd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i = WorkingSet.ub.size(0);
          if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                          &nd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i = xk.size(0);
          if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > i)) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                          &nd_emlrtBCI, (emlrtConstCTX)&sp);
          }
          xk[WorkingSet.indexUB[idx] - 1] = d - muDoubleScalarAbs(d);
        }
      }
    } else {
      st.site = &vi_emlrtRSI;
      if (WorkingSet.sizes[4] > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{0}; idx <= mUB; idx++) {
        i = WorkingSet.indexUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &nd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = xk.size(0);
        if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        i = WorkingSet.ub.size(0);
        if ((WorkingSet.indexUB[idx] < 1) || (WorkingSet.indexUB[idx] > i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                        &nd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        d = WorkingSet.ub[WorkingSet.indexUB[idx] - 1];
        if (xk[WorkingSet.indexUB[idx] - 1] > d) {
          if ((WorkingSet.indexUB[idx] < 1) ||
              (WorkingSet.indexUB[idx] > lb.size(0))) {
            emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1,
                                          lb.size(0), &nd_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (muDoubleScalarIsInf(lb[WorkingSet.indexUB[idx] - 1])) {
            i = WorkingSet.ub.size(0);
            if ((WorkingSet.indexUB[idx] < 1) ||
                (WorkingSet.indexUB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = WorkingSet.ub.size(0);
            if ((WorkingSet.indexUB[idx] < 1) ||
                (WorkingSet.indexUB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = xk.size(0);
            if ((WorkingSet.indexUB[idx] < 1) ||
                (WorkingSet.indexUB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            xk[WorkingSet.indexUB[idx] - 1] = d - muDoubleScalarAbs(d);
          } else {
            i = WorkingSet.ub.size(0);
            if ((WorkingSet.indexUB[idx] < 1) ||
                (WorkingSet.indexUB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = WorkingSet.lb.size(0);
            if ((WorkingSet.indexUB[idx] < 1) ||
                (WorkingSet.indexUB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            i = xk.size(0);
            if ((WorkingSet.indexUB[idx] < 1) ||
                (WorkingSet.indexUB[idx] > i)) {
              emlrtDynamicBoundsCheckR2012b(WorkingSet.indexUB[idx], 1, i,
                                            &nd_emlrtBCI, (emlrtConstCTX)&sp);
            }
            xk[WorkingSet.indexUB[idx] - 1] =
                (d - WorkingSet.lb[WorkingSet.indexUB[idx] - 1]) / 2.0;
          }
        }
      }
    }
  }
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (makeBoundFeasible.cpp)
