//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFiniteDifferences.cpp
//
// Code generation for function 'computeFiniteDifferences'
//

// Include files
#include "computeFiniteDifferences.h"
#include "anonymous_function.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "inverseKinematicsOAModified_internal_types1.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo te_emlrtRSI{
    1,                          // lineNo
    "computeFiniteDifferences", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/computeFiniteDifferences.p" // pathName
};

static emlrtRSInfo ue_emlrtRSI{
    1,                           // lineNo
    "computeForwardDifferences", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/+internal/computeForwardDifferences.p" // pathName
};

static emlrtRSInfo ve_emlrtRSI{
    1,               // lineNo
    "computeDeltaX", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/computeDeltaX.p" // pathName
};

static emlrtRSInfo we_emlrtRSI{
    1,                      // lineNo
    "finDiffEvalAndChkErr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/+internal/finDiffEvalAndChkErr.p" // pathName
};

static emlrtBCInfo rb_emlrtBCI{
    -1,                          // iFirst
    -1,                          // iLast
    1,                           // lineNo
    1,                           // colNo
    "",                          // aName
    "computeForwardDifferences", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/+internal/computeForwardDifferences.p", // pName
    0                                                           // checkKind
};

static emlrtBCInfo sb_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "ForwardStepSize", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/+internal/ForwardStepSize.p", // pName
    0                                                 // checkKind
};

static emlrtBCInfo tb_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    1,                      // lineNo
    1,                      // colNo
    "",                     // aName
    "finDiffEvalAndChkErr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/optimlib/+optim/+coder/+utils/"
    "+FiniteDifferences/+internal/finDiffEvalAndChkErr.p", // pName
    0                                                      // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
boolean_T computeFiniteDifferences(
    const emlrtStack &sp, l_struct_T &obj, real_T fCurrent,
    array<real_T, 1U> &xk, array<real_T, 1U> &gradf, const real_T lb_data[],
    int32_T lb_size, const real_T ub_data[], int32_T ub_size,
    const array<real_T, 1U> &c_runTimeOptions_FiniteDifferen,
    const array<real_T, 1U> &runTimeOptions_TypicalX)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T idx;
  boolean_T evalOK;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &te_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  evalOK = true;
  obj.numEvals = 0;
  b_st.site = &ue_emlrtRSI;
  if (obj.nVar > 2147483646) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= obj.nVar - 1)) {
    real_T deltaX;
    real_T lbDiff;
    real_T ubDiff;
    int32_T i;
    boolean_T b_guard1;
    boolean_T guard1;
    boolean_T guard2;
    boolean_T modifiedStep;
    modifiedStep = false;
    b_st.site = &ue_emlrtRSI;
    c_st.site = &ve_emlrtRSI;
    i = xk.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &sb_emlrtBCI, &c_st);
    }
    if ((idx + 1 < 1) || (idx + 1 > c_runTimeOptions_FiniteDifferen.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1,
                                    c_runTimeOptions_FiniteDifferen.size(0),
                                    &sb_emlrtBCI, &c_st);
    }
    if ((idx + 1 < 1) || (idx + 1 > runTimeOptions_TypicalX.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, runTimeOptions_TypicalX.size(0),
                                    &sb_emlrtBCI, &c_st);
    }
    i = xk.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &sb_emlrtBCI, &c_st);
    }
    deltaX = 1.4901161193847656E-8 *
             (1.0 - 2.0 * static_cast<real_T>(xk[idx] < 0.0)) *
             muDoubleScalarMax(muDoubleScalarAbs(xk[idx]), 1.0);
    i = obj.hasLB.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
    }
    guard1 = false;
    guard2 = false;
    if (obj.hasLB[idx]) {
      guard2 = true;
    } else {
      i = obj.hasUB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
      }
      if (obj.hasUB[idx]) {
        guard2 = true;
      }
    }
    if (guard2) {
      i = obj.hasLB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
      }
      if (obj.hasLB[idx]) {
        i = obj.hasUB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
        }
        if (obj.hasUB[idx]) {
          if ((idx + 1 < 1) || (idx + 1 > lb_size)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb_size, &rb_emlrtBCI,
                                          &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > ub_size)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub_size, &rb_emlrtBCI,
                                          &st);
          }
          lbDiff = deltaX;
          if ((lb_data[idx] != ub_data[idx]) && (xk[idx] >= lb_data[idx]) &&
              (xk[idx] <= ub_data[idx])) {
            ubDiff = xk[idx] + deltaX;
            if ((ubDiff > ub_data[idx]) || (ubDiff < lb_data[idx])) {
              lbDiff = -deltaX;
              modifiedStep = true;
              ubDiff = xk[idx] - deltaX;
              if ((ubDiff > ub_data[idx]) || (ubDiff < lb_data[idx])) {
                lbDiff = xk[idx] - lb_data[idx];
                ubDiff = ub_data[idx] - xk[idx];
                if (lbDiff <= ubDiff) {
                  lbDiff = -lbDiff;
                } else {
                  lbDiff = ubDiff;
                }
              }
            }
          }
          deltaX = lbDiff;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
    if (guard1) {
      i = obj.hasUB.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
      }
      if (obj.hasUB[idx]) {
        if ((idx + 1 < 1) || (idx + 1 > ub_size)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub_size, &rb_emlrtBCI, &st);
        }
        if ((xk[idx] <= ub_data[idx]) && (xk[idx] + deltaX > ub_data[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      } else {
        if ((idx + 1 < 1) || (idx + 1 > lb_size)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb_size, &rb_emlrtBCI, &st);
        }
        if ((xk[idx] >= lb_data[idx]) && (xk[idx] + deltaX < lb_data[idx])) {
          deltaX = -deltaX;
          modifiedStep = true;
        }
      }
    }
    b_st.site = &ue_emlrtRSI;
    lbDiff = xk[idx];
    i = xk.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &tb_emlrtBCI, &b_st);
    }
    xk[idx] = lbDiff + deltaX;
    c_st.site = &we_emlrtRSI;
    d_st.site = &jb_emlrtRSI;
    ubDiff = c_inverseKinematicsOAModified_a(
        d_st, obj.objfun.workspace.jacobi.data,
        obj.objfun.workspace.jacobi.size, obj.objfun.workspace.xd_eff_vel,
        obj.objfun.workspace.starting_joint_vel,
        obj.objfun.workspace.joint_values.data,
        obj.objfun.workspace.joint_values.size[0],
        obj.objfun.workspace.jointVelocityWeightMatrix.data,
        obj.objfun.workspace.jointVelocityWeightMatrix.size,
        obj.objfun.workspace.config, obj.objfun.workspace.slackIsUsed, xk);
    evalOK = ((!muDoubleScalarIsInf(ubDiff)) && (!muDoubleScalarIsNaN(ubDiff)));
    if (evalOK) {
      i = xk.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &tb_emlrtBCI, &b_st);
      }
      xk[idx] = lbDiff;
    }
    obj.f_1 = ubDiff;
    obj.numEvals++;
    b_guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -deltaX;
        i = obj.hasLB.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
        }
        if (obj.hasLB[idx]) {
          i = xk.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > lb_size)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lb_size, &rb_emlrtBCI,
                                          &st);
          }
          ubDiff = xk[idx] + deltaX;
          if (ubDiff >= lb_data[idx]) {
            i = obj.hasUB.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
            }
            if (obj.hasUB[idx]) {
              if ((idx + 1 < 1) || (idx + 1 > ub_size)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, ub_size, &rb_emlrtBCI,
                                              &st);
              }
              if (ubDiff <= ub_data[idx]) {
                modifiedStep = true;
              } else {
                modifiedStep = false;
              }
            } else {
              modifiedStep = false;
            }
          } else {
            modifiedStep = false;
          }
        } else {
          modifiedStep = false;
        }
        if ((!obj.hasBounds) || modifiedStep) {
          b_st.site = &ue_emlrtRSI;
          i = xk.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &tb_emlrtBCI, &b_st);
          }
          lbDiff = xk[idx];
          i = xk.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &tb_emlrtBCI, &b_st);
          }
          xk[idx] = lbDiff + deltaX;
          c_st.site = &we_emlrtRSI;
          d_st.site = &jb_emlrtRSI;
          ubDiff = c_inverseKinematicsOAModified_a(
              d_st, obj.objfun.workspace.jacobi.data,
              obj.objfun.workspace.jacobi.size, obj.objfun.workspace.xd_eff_vel,
              obj.objfun.workspace.starting_joint_vel,
              obj.objfun.workspace.joint_values.data,
              obj.objfun.workspace.joint_values.size[0],
              obj.objfun.workspace.jointVelocityWeightMatrix.data,
              obj.objfun.workspace.jointVelocityWeightMatrix.size,
              obj.objfun.workspace.config, obj.objfun.workspace.slackIsUsed,
              xk);
          evalOK = ((!muDoubleScalarIsInf(ubDiff)) &&
                    (!muDoubleScalarIsNaN(ubDiff)));
          if (evalOK) {
            i = xk.size(0);
            if ((idx + 1 < 1) || (idx + 1 > i)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &tb_emlrtBCI, &b_st);
            }
            xk[idx] = lbDiff;
          }
          obj.f_1 = ubDiff;
          obj.numEvals++;
        }
      }
      if (!evalOK) {
        exitg1 = true;
      } else {
        b_guard1 = true;
      }
    } else {
      b_guard1 = true;
    }
    if (b_guard1) {
      i = gradf.size(0);
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &rb_emlrtBCI, &st);
      }
      gradf[idx] = (obj.f_1 - fCurrent) / deltaX;
      idx++;
    }
  }
  return evalOK;
}

} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeFiniteDifferences.cpp)
