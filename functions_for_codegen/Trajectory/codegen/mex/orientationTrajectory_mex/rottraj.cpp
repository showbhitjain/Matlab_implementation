//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rottraj.cpp
//
// Code generation for function 'rottraj'
//

// Include files
#include "rottraj.h"
#include "constructLinearTimeScaling.h"
#include "isequal.h"
#include "orientationTrajectory_mex_data.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "validateTimeScaling.h"
#include "validateattributes.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo gd_emlrtRSI{
    97,        // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    98,        // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    105,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    106,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo kd_emlrtRSI{
    107,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo ld_emlrtRSI{
    108,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    111,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    122,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    125,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    126,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    129,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo rd_emlrtRSI{
    130,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo sd_emlrtRSI{
    132,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo td_emlrtRSI{
    136,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo ud_emlrtRSI{
    137,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo vd_emlrtRSI{
    143,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo wd_emlrtRSI{
    144,       // lineNo
    "rottraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo he_emlrtRSI{
    11,                        // lineNo
    "quaternionBase/onesLike", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/onesLike.m" // pathName
};

static emlrtRSInfo ie_emlrtRSI{
    251,                 // lineNo
    "quaternioncg/ctor", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m" // pathName
};

static emlrtRSInfo ve_emlrtRSI{
    214,                          // lineNo
    "computeFirstQuatDerivative", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo ef_emlrtRSI{
    229,                           // lineNo
    "computeSecondQuatDerivative", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo ff_emlrtRSI{
    233,                           // lineNo
    "computeSecondQuatDerivative", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtRSInfo gf_emlrtRSI{
    235,                           // lineNo
    "computeSecondQuatDerivative", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pathName
};

static emlrtBCInfo q_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    169,                           // lineNo
    22,                            // colNo
    "",                            // aName
    "quaternioncg/parenReference", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    168,                           // lineNo
    22,                            // colNo
    "",                            // aName
    "quaternioncg/parenReference", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    167,                           // lineNo
    22,                            // colNo
    "",                            // aName
    "quaternioncg/parenReference", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    166,                           // lineNo
    22,                            // colNo
    "",                            // aName
    "quaternioncg/parenReference", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    145,       // lineNo
    17,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    138,       // lineNo
    17,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    143,       // lineNo
    76,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    136,       // lineNo
    74,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    132,       // lineNo
    34,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    116,       // lineNo
    23,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    115,       // lineNo
    22,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo cb_emlrtBCI{
    -1,        // iFirst
    -1,        // iLast
    114,       // lineNo
    21,        // colNo
    "",        // aName
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    175,                        // lineNo
    19,                         // colNo
    "",                         // aName
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    176,                        // lineNo
    19,                         // colNo
    "",                         // aName
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtBCInfo fb_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    177,                        // lineNo
    19,                         // colNo
    "",                         // aName
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtBCInfo gb_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    178,                        // lineNo
    19,                         // colNo
    "",                         // aName
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m", // pName
    0        // checkKind
};

static emlrtRTEInfo fc_emlrtRTEI{
    120,       // lineNo
    13,        // colNo
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    121,       // lineNo
    13,        // colNo
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    122,       // lineNo
    5,         // colNo
    "rottraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/rottraj.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void rottraj(const emlrtStack &sp, const quaternion R0, const quaternion RF,
             const real_T timeInterval[2], const ::coder::array<real_T, 2U> &t,
             const ::coder::array<real_T, 2U> &varargin_2, b_quaternion &R,
             ::coder::array<real_T, 2U> &omega,
             ::coder::array<real_T, 2U> &alpha)
{
  quaternion W_tmp;
  quaternion o;
  quaternion pn;
  quaternion pnCorrected;
  quaternion qdCalc;
  quaternion qn;
  quaternion y;
  ::coder::array<real_T, 2U> timeScaling;
  ::coder::array<real_T, 2U> vh_emlrtRSI;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T b_t[2];
  real_T c_t[2];
  real_T d_t[2];
  real_T e_t[2];
  real_T b_rhs_tmp;
  real_T c_rhs_tmp;
  real_T d_rhs_tmp;
  real_T rhs_tmp;
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
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &gd_emlrtRSI;
  validateattributes(st, timeInterval);
  st.site = &hd_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (t.size(1) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:rottraj:expectedNonempty", 3, 4, 1, "t");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= t.size(1) - 1)) {
    if ((!muDoubleScalarIsInf(t[k])) && (!muDoubleScalarIsNaN(t[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rottraj:expectedFinite", 3, 4, 1, "t");
  }
  b_st.site = &ib_emlrtRSI;
  if (t.size(1) > 1) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= t.size(1) - 2)) {
      if (!(t[k] < t[k + 1])) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedIncreasing",
            "MATLAB:rottraj:expectedIncreasing", 3, 4, 1, "t");
      } else {
        k++;
      }
    }
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= t.size(1) - 1)) {
    if (!(t[k] < 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:rottraj:expectedNonnegative", 3, 4, 1, "t");
  }
  st.site = &id_emlrtRSI;
  robotics::core::internal::constructLinearTimeScaling(st, timeInterval, t,
                                                       vh_emlrtRSI);
  st.site = &jd_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  st.site = &kd_emlrtRSI;
  st.site = &ld_emlrtRSI;
  st.site = &md_emlrtRSI;
  robotics::core::internal::validateTimeScaling(
      st, varargin_2, static_cast<real_T>(t.size(1)), timeScaling);
  if (timeScaling.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, timeScaling.size(0), &cb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  if (timeScaling.size(0) < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, timeScaling.size(0), &bb_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  if (timeScaling.size(0) < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, timeScaling.size(0), &ab_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  omega.set_size(&fc_emlrtRTEI, &sp, 3, t.size(1));
  alpha.set_size(&gc_emlrtRTEI, &sp, 3, t.size(1));
  st.site = &nd_emlrtRSI;
  b_st.site = &he_emlrtRSI;
  c_st.site = &ie_emlrtRSI;
  d_st.site = &je_emlrtRSI;
  e_st.site = &ke_emlrtRSI;
  f_st.site = &le_emlrtRSI;
  b_t[0] = t.size(1);
  b_t[1] = 1.0;
  c_t[0] = t.size(1);
  c_t[1] = 1.0;
  d_t[0] = t.size(1);
  d_t[1] = 1.0;
  e_t[0] = t.size(1);
  e_t[1] = 1.0;
  if (!isequal(b_t, c_t, d_t, e_t)) {
    emlrtErrorWithMessageIdR2018a(&f_st, &m_emlrtRTEI,
                                  "shared_rotations:quaternion:SameSize",
                                  "shared_rotations:quaternion:SameSize", 0);
  }
  R.a.set_size(&hc_emlrtRTEI, &d_st, t.size(1));
  k = t.size(1);
  R.b.set_size(&hc_emlrtRTEI, &d_st, t.size(1));
  R.c.set_size(&hc_emlrtRTEI, &d_st, t.size(1));
  R.d.set_size(&hc_emlrtRTEI, &d_st, t.size(1));
  for (i = 0; i < k; i++) {
    R.a[i] = 1.0;
    R.b[i] = 0.0;
    R.c[i] = 0.0;
    R.d[i] = 0.0;
  }
  quaternion qnCorrected;
  pn = R0;
  st.site = &od_emlrtRSI;
  pn.normalize(st);
  qn = RF;
  st.site = &pd_emlrtRSI;
  qn.normalize(st);
  st.site = &qd_emlrtRSI;
  pnCorrected = pn.slerp(st, qn);
  st.site = &rd_emlrtRSI;
  qnCorrected = pn.quaternionBase_slerp(st, qn);
  i = t.size(1);
  rhs_tmp = ((pnCorrected.a * qnCorrected.a - -pnCorrected.b * qnCorrected.b) -
             -pnCorrected.c * qnCorrected.c) -
            -pnCorrected.d * qnCorrected.d;
  b_rhs_tmp =
      ((pnCorrected.a * qnCorrected.b + -pnCorrected.b * qnCorrected.a) +
       -pnCorrected.c * qnCorrected.d) -
      -pnCorrected.d * qnCorrected.c;
  c_rhs_tmp =
      ((pnCorrected.a * qnCorrected.c - -pnCorrected.b * qnCorrected.d) +
       -pnCorrected.c * qnCorrected.a) +
      -pnCorrected.d * qnCorrected.b;
  d_rhs_tmp =
      ((pnCorrected.a * qnCorrected.d + -pnCorrected.b * qnCorrected.c) -
       -pnCorrected.c * qnCorrected.b) +
      -pnCorrected.d * qnCorrected.a;
  for (k = 0; k < i; k++) {
    real_T xa;
    real_T xb;
    real_T xc;
    real_T xd;
    st.site = &sd_emlrtRSI;
    if (k + 1 > timeScaling.size(1)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, timeScaling.size(1), &y_emlrtBCI,
                                    &st);
    }
    b_st.site = &sd_emlrtRSI;
    pnCorrected = pn.slerp(b_st, qn, timeScaling[timeScaling.size(0) * k]);
    if (k + 1 > R.a.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.a.size(0), &db_emlrtBCI, &st);
    }
    R.a[k] = pnCorrected.a;
    if (k + 1 > R.b.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.b.size(0), &eb_emlrtBCI, &st);
    }
    R.b[k] = pnCorrected.b;
    if (k + 1 > R.c.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.c.size(0), &fb_emlrtBCI, &st);
    }
    R.c[k] = pnCorrected.c;
    if (k + 1 > R.d.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.d.size(0), &gb_emlrtBCI, &st);
    }
    R.d[k] = pnCorrected.d;
    st.site = &td_emlrtRSI;
    if (k + 1 > R.a.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.a.size(0), &t_emlrtBCI, &st);
    }
    if (k + 1 > R.b.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.b.size(0), &s_emlrtBCI, &st);
    }
    if (k + 1 > R.c.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.c.size(0), &r_emlrtBCI, &st);
    }
    if (k + 1 > R.d.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.d.size(0), &q_emlrtBCI, &st);
    }
    st.site = &td_emlrtRSI;
    if (k + 1 > timeScaling.size(1)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, timeScaling.size(1), &x_emlrtBCI,
                                    &st);
    }
    pnCorrected.a = rhs_tmp;
    pnCorrected.b = b_rhs_tmp;
    pnCorrected.c = c_rhs_tmp;
    pnCorrected.d = d_rhs_tmp;
    b_st.site = &ve_emlrtRSI;
    pnCorrected.b_log(b_st);
    qdCalc.a = timeScaling[timeScaling.size(0) * k + 1] *
               (((R.a[k] * pnCorrected.a - R.b[k] * pnCorrected.b) -
                 R.c[k] * pnCorrected.c) -
                R.d[k] * pnCorrected.d);
    qdCalc.b = timeScaling[timeScaling.size(0) * k + 1] *
               (((R.a[k] * pnCorrected.b + R.b[k] * pnCorrected.a) +
                 R.c[k] * pnCorrected.d) -
                R.d[k] * pnCorrected.c);
    qdCalc.c = timeScaling[timeScaling.size(0) * k + 1] *
               (((R.a[k] * pnCorrected.c - R.b[k] * pnCorrected.d) +
                 R.c[k] * pnCorrected.a) +
                R.d[k] * pnCorrected.b);
    qdCalc.d = timeScaling[timeScaling.size(0) * k + 1] *
               (((R.a[k] * pnCorrected.d + R.b[k] * pnCorrected.c) -
                 R.c[k] * pnCorrected.b) +
                R.d[k] * pnCorrected.a);
    W_tmp.a = 2.0 * qdCalc.a;
    W_tmp.b = 2.0 * qdCalc.b;
    W_tmp.c = 2.0 * qdCalc.c;
    W_tmp.d = 2.0 * qdCalc.d;
    st.site = &ud_emlrtRSI;
    if (k + 1 > R.a.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.a.size(0), &t_emlrtBCI, &st);
    }
    if (k + 1 > R.b.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.b.size(0), &s_emlrtBCI, &st);
    }
    if (k + 1 > R.c.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.c.size(0), &r_emlrtBCI, &st);
    }
    if (k + 1 > R.d.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.d.size(0), &q_emlrtBCI, &st);
    }
    if (k + 1 > omega.size(1)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, omega.size(1), &v_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    omega[3 * k] =
        ((W_tmp.a * -R.b[k] + W_tmp.b * R.a[k]) + W_tmp.c * -R.d[k]) -
        W_tmp.d * -R.c[k];
    omega[3 * k + 1] =
        ((W_tmp.a * -R.c[k] - W_tmp.b * -R.d[k]) + W_tmp.c * R.a[k]) +
        W_tmp.d * -R.b[k];
    omega[3 * k + 2] =
        ((W_tmp.a * -R.d[k] + W_tmp.b * -R.c[k]) - W_tmp.c * -R.b[k]) +
        W_tmp.d * R.a[k];
    st.site = &vd_emlrtRSI;
    if (k + 1 > R.a.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.a.size(0), &t_emlrtBCI, &st);
    }
    if (k + 1 > R.b.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.b.size(0), &s_emlrtBCI, &st);
    }
    if (k + 1 > R.c.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.c.size(0), &r_emlrtBCI, &st);
    }
    if (k + 1 > R.d.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.d.size(0), &q_emlrtBCI, &st);
    }
    st.site = &vd_emlrtRSI;
    if (k + 1 > timeScaling.size(1)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, timeScaling.size(1), &w_emlrtBCI,
                                    &st);
    }
    b_st.site = &ef_emlrtRSI;
    pnCorrected.a = rhs_tmp;
    pnCorrected.b = b_rhs_tmp;
    pnCorrected.c = c_rhs_tmp;
    pnCorrected.d = d_rhs_tmp;
    c_st.site = &ve_emlrtRSI;
    pnCorrected.b_log(c_st);
    y.a = rhs_tmp;
    y.b = b_rhs_tmp;
    y.c = c_rhs_tmp;
    y.d = d_rhs_tmp;
    b_st.site = &ff_emlrtRSI;
    y.b_log(b_st);
    o.a = ((R.a[k] * y.a - R.b[k] * y.b) - R.c[k] * y.c) - R.d[k] * y.d;
    o.b = ((R.a[k] * y.b + R.b[k] * y.a) + R.c[k] * y.d) - R.d[k] * y.c;
    o.c = ((R.a[k] * y.c - R.b[k] * y.d) + R.c[k] * y.a) + R.d[k] * y.b;
    o.d = ((R.a[k] * y.d + R.b[k] * y.c) - R.c[k] * y.b) + R.d[k] * y.a;
    y.a = rhs_tmp;
    y.b = b_rhs_tmp;
    y.c = c_rhs_tmp;
    y.d = d_rhs_tmp;
    b_st.site = &ff_emlrtRSI;
    y.b_log(b_st);
    b_st.site = &gf_emlrtRSI;
    c_st.site = &mb_emlrtRSI;
    d_st.site = &nb_emlrtRSI;
    xd = timeScaling[timeScaling.size(0) * k + 1] *
         timeScaling[timeScaling.size(0) * k + 1];
    st.site = &wd_emlrtRSI;
    if (k + 1 > R.a.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.a.size(0), &t_emlrtBCI, &st);
    }
    if (k + 1 > R.b.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.b.size(0), &s_emlrtBCI, &st);
    }
    if (k + 1 > R.c.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.c.size(0), &r_emlrtBCI, &st);
    }
    if (k + 1 > R.d.size(0)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, R.d.size(0), &q_emlrtBCI, &st);
    }
    xa = 2.0 * (xd * (((o.a * y.a - o.b * y.b) - o.c * y.c) - o.d * y.d) +
                timeScaling[timeScaling.size(0) * k + 2] *
                    (((R.a[k] * pnCorrected.a - R.b[k] * pnCorrected.b) -
                      R.c[k] * pnCorrected.c) -
                     R.d[k] * pnCorrected.d));
    xb = 2.0 * (xd * (((o.a * y.b + o.b * y.a) + o.c * y.d) - o.d * y.c) +
                timeScaling[timeScaling.size(0) * k + 2] *
                    (((R.a[k] * pnCorrected.b + R.b[k] * pnCorrected.a) +
                      R.c[k] * pnCorrected.d) -
                     R.d[k] * pnCorrected.c));
    xc = 2.0 * (xd * (((o.a * y.c - o.b * y.d) + o.c * y.a) + o.d * y.b) +
                timeScaling[timeScaling.size(0) * k + 2] *
                    (((R.a[k] * pnCorrected.c - R.b[k] * pnCorrected.d) +
                      R.c[k] * pnCorrected.a) +
                     R.d[k] * pnCorrected.b));
    xd = 2.0 * (xd * (((o.a * y.d + o.b * y.c) - o.c * y.b) + o.d * y.a) +
                timeScaling[timeScaling.size(0) * k + 2] *
                    (((R.a[k] * pnCorrected.d + R.b[k] * pnCorrected.c) -
                      R.c[k] * pnCorrected.b) +
                     R.d[k] * pnCorrected.a));
    qdCalc.b = -qdCalc.b;
    qdCalc.c = -qdCalc.c;
    qdCalc.d = -qdCalc.d;
    if (k + 1 > alpha.size(1)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, alpha.size(1), &u_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    alpha[3 * k] =
        (((xa * -R.b[k] + xb * R.a[k]) + xc * -R.d[k]) - xd * -R.c[k]) -
        (((W_tmp.a * qdCalc.b + W_tmp.b * qdCalc.a) + W_tmp.c * qdCalc.d) -
         W_tmp.d * qdCalc.c);
    alpha[3 * k + 1] =
        (((xa * -R.c[k] - xb * -R.d[k]) + xc * R.a[k]) + xd * -R.b[k]) -
        (((W_tmp.a * qdCalc.c - W_tmp.b * qdCalc.d) + W_tmp.c * qdCalc.a) +
         W_tmp.d * qdCalc.b);
    alpha[3 * k + 2] =
        (((xa * -R.d[k] + xb * -R.c[k]) - xc * -R.b[k]) + xd * R.a[k]) -
        (((W_tmp.a * qdCalc.d + W_tmp.b * qdCalc.c) - W_tmp.c * qdCalc.b) +
         W_tmp.d * qdCalc.a);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (rottraj.cpp)
