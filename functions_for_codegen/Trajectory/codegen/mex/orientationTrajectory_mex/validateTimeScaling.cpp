//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// validateTimeScaling.cpp
//
// Code generation for function 'validateTimeScaling'
//

// Include files
#include "validateTimeScaling.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ce_emlrtRSI{
    10,                    // lineNo
    "validateTimeScaling", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pathName
};

static emlrtRSInfo de_emlrtRSI{
    17,                    // lineNo
    "validateTimeScaling", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pathName
};

static emlrtRSInfo ee_emlrtRSI{
    29,                    // lineNo
    "validateTimeScaling", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pathName
};

static emlrtRSInfo fe_emlrtRSI{
    32,                    // lineNo
    "validateTimeScaling", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pathName
};

static emlrtRSInfo ge_emlrtRSI{
    41,                                                               // lineNo
    "cat",                                                            // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtECInfo n_emlrtECI{
    2,                     // nDims
    26,                    // lineNo
    24,                    // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtECInfo o_emlrtECI{
    2,                     // nDims
    25,                    // lineNo
    24,                    // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    14,                    // lineNo
    1,                     // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtBCInfo lb_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    27,                    // lineNo
    16,                    // colNo
    "",                    // aName
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m", // pName
    0                                        // checkKind
};

static emlrtBCInfo mb_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    28,                    // lineNo
    16,                    // colNo
    "",                    // aName
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m", // pName
    0                                        // checkKind
};

static emlrtRTEInfo mc_emlrtRTEI{
    24,                    // lineNo
    1,                     // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    25,                    // lineNo
    25,                    // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtRTEInfo oc_emlrtRTEI{
    25,                    // lineNo
    57,                    // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    26,                    // lineNo
    25,                    // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtRTEInfo qc_emlrtRTEI{
    26,                    // lineNo
    57,                    // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtRTEInfo rc_emlrtRTEI{
    32,                    // lineNo
    41,                    // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

static emlrtRTEInfo sc_emlrtRTEI{
    32,                    // lineNo
    1,                     // colNo
    "validateTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/validateTimeScaling.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
namespace robotics {
namespace core {
namespace internal {
void validateTimeScaling(const emlrtStack &sp,
                         const ::coder::array<real_T, 2U> &timeScalingMatrix,
                         real_T timeVectorLength,
                         ::coder::array<real_T, 2U> &validatedTimeScaling)
{
  ::coder::array<real_T, 2U> b_timeScalingMatrix;
  ::coder::array<real_T, 2U> timeScalingPos;
  ::coder::array<boolean_T, 2U> r;
  ::coder::array<boolean_T, 2U> r1;
  ::coder::array<boolean_T, 2U> r2;
  ::coder::array<boolean_T, 2U> r3;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T d;
  int32_T i;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &ce_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (timeScalingMatrix.size(1) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:rottraj:expectedNonempty", 3, 4, 11, "TimeScaling");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  i = 3 * timeScalingMatrix.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(timeScalingMatrix[k])) &&
        (!muDoubleScalarIsNaN(timeScalingMatrix[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rottraj:expectedFinite", 3, 4, 11, "TimeScaling");
  }
  if (timeScalingMatrix.size(1) != timeVectorLength) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &s_emlrtRTEI,
        "shared_robotics:robotcore:utils:RotTrajTimeScalingLength",
        "shared_robotics:robotcore:utils:RotTrajTimeScalingLength", 0);
  }
  st.site = &de_emlrtRSI;
  timeScalingPos.set_size(&mc_emlrtRTEI, &sp, 1, timeScalingMatrix.size(1));
  k = timeScalingMatrix.size(1);
  r.set_size(&nc_emlrtRTEI, &sp, 1, timeScalingMatrix.size(1));
  r1.set_size(&oc_emlrtRTEI, &sp, 1, timeScalingMatrix.size(1));
  for (i = 0; i < k; i++) {
    d = timeScalingMatrix[3 * i];
    timeScalingPos[i] = d;
    r[i] = (d > 1.0);
    r1[i] = (d < 1.0000000149011612);
  }
  if (r.size(1) != r1.size(1)) {
    emlrtSizeEqCheckNDErrorR2021b(r.size(), r1.size(), &o_emlrtECI,
                                  (emlrtCTX)&sp);
  }
  r2.set_size(&pc_emlrtRTEI, &sp, 1, timeScalingMatrix.size(1));
  k = timeScalingMatrix.size(1);
  r3.set_size(&qc_emlrtRTEI, &sp, 1, timeScalingMatrix.size(1));
  for (i = 0; i < k; i++) {
    d = timeScalingMatrix[3 * i];
    r2[i] = (d < 0.0);
    r3[i] = (d > -1.4901161193847656E-8);
  }
  if (r2.size(1) != r3.size(1)) {
    emlrtSizeEqCheckNDErrorR2021b(r2.size(), r3.size(), &n_emlrtECI,
                                  (emlrtCTX)&sp);
  }
  k = r.size(1) - 1;
  for (int32_T b_i{0}; b_i <= k; b_i++) {
    if (r[b_i] && r1[b_i]) {
      if (b_i > k) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, k, &lb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      timeScalingPos[b_i] = 1.0;
    }
  }
  for (int32_T b_i{0}; b_i <= k; b_i++) {
    if (r2[b_i] && r3[b_i]) {
      if (b_i > timeScalingPos.size(1) - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, timeScalingPos.size(1) - 1,
                                      &mb_emlrtBCI, (emlrtConstCTX)&sp);
      }
      timeScalingPos[b_i] = 0.0;
    }
  }
  st.site = &ee_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= timeScalingPos.size(1) - 1)) {
    if (timeScalingPos[k] >= 0.0) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &r_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedArray",
                                  "MATLAB:rottraj:notGreaterEqual", 9, 4, 16,
                                  "TimeScaling(1,:)", 4, 2, ">=", 4, 1, "0");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= timeScalingPos.size(1) - 1)) {
    if (timeScalingPos[k] <= 1.0) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &q_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedArray",
                                  "MATLAB:rottraj:notLessEqual", 9, 4, 16,
                                  "TimeScaling(1,:)", 4, 2, "<=", 4, 1, "1");
  }
  st.site = &fe_emlrtRSI;
  b_st.site = &ge_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  if (timeScalingMatrix.size(1) != timeScalingPos.size(1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  b_timeScalingMatrix.set_size(&rc_emlrtRTEI, &b_st, 2,
                               timeScalingMatrix.size(1));
  k = timeScalingMatrix.size(1);
  validatedTimeScaling.set_size(&sc_emlrtRTEI, &b_st, 3,
                                timeScalingPos.size(1));
  for (i = 0; i < k; i++) {
    b_timeScalingMatrix[2 * i] = timeScalingMatrix[3 * i + 1];
    b_timeScalingMatrix[2 * i + 1] = timeScalingMatrix[3 * i + 2];
    validatedTimeScaling[validatedTimeScaling.size(0) * i] = timeScalingPos[i];
  }
  k = timeScalingPos.size(1);
  for (i = 0; i < k; i++) {
    for (int32_T b_i{0}; b_i < 2; b_i++) {
      validatedTimeScaling[(b_i + validatedTimeScaling.size(0) * i) + 1] =
          b_timeScalingMatrix[b_i + 2 * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (validateTimeScaling.cpp)
