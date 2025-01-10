//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cubicpolytraj.cpp
//
// Code generation for function 'cubicpolytraj'
//

// Include files
#include "cubicpolytraj.h"
#include "addFlatSegmentsToPPFormParts.h"
#include "assertValidSizeArg.h"
#include "changeEndSegBreaks.h"
#include "mpower.h"
#include "orientationTrajectory_mex_data.h"
#include "orientationTrajectory_mex_internal_types.h"
#include "ppval.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo xb_emlrtRSI{
    63,              // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    75,              // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    76,              // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    77,              // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    103,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    113,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo ec_emlrtRSI{
    117,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo fc_emlrtRSI{
    124,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    129,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    136,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo gh_emlrtRSI{
    62,              // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo hh_emlrtRSI{
    116,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo ih_emlrtRSI{
    127,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo jh_emlrtRSI{
    128,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo kh_emlrtRSI{
    134,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtRSInfo lh_emlrtRSI{
    135,             // lineNo
    "cubicpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pathName
};

static emlrtECInfo h_emlrtECI{
    -1,                                                                // nDims
    117,                                                               // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtECInfo i_emlrtECI{
    -1,                                                                // nDims
    129,                                                               // lineNo
    9,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtECInfo j_emlrtECI{
    -1,                                                                // nDims
    136,                                                               // lineNo
    9,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    80,                                                                // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    81,                                                                // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtBCInfo ad_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    107,             // lineNo
    21,              // colNo
    "",              // aName
    "cubicpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m", // pName
    0 // checkKind
};

static emlrtDCInfo x_emlrtDCI{
    92,              // lineNo
    21,              // colNo
    "cubicpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m", // pName
    1 // checkKind
};

static emlrtDCInfo y_emlrtDCI{
    92,              // lineNo
    5,               // colNo
    "cubicpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m", // pName
    1 // checkKind
};

static emlrtBCInfo bd_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    98,              // lineNo
    32,              // colNo
    "",              // aName
    "cubicpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo cd_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    98,              // lineNo
    50,              // colNo
    "",              // aName
    "cubicpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo dd_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    103,             // lineNo
    78,              // colNo
    "",              // aName
    "cubicpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo ed_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    103,             // lineNo
    61,              // colNo
    "",              // aName
    "cubicpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m", // pName
    0 // checkKind
};

static emlrtRTEInfo yb_emlrtRTEI{
    84,                                                                // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo ac_emlrtRTEI{
    85,                                                                // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    86,                                                                // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo oe_emlrtRTEI{
    66,                                                                // lineNo
    18,                                                                // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo pe_emlrtRTEI{
    66,                                                                // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo qe_emlrtRTEI{
    92,                                                                // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo re_emlrtRTEI{
    116,                                                               // lineNo
    5,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo se_emlrtRTEI{
    127,                                                               // lineNo
    9,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo te_emlrtRTEI{
    128,                                                               // lineNo
    9,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo ue_emlrtRTEI{
    134,                                                               // lineNo
    9,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

static emlrtRTEInfo ve_emlrtRTEI{
    135,                                                               // lineNo
    9,                                                                 // colNo
    "cubicpolytraj",                                                   // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/cubicpolytraj.m" // pName
};

// Function Declarations
namespace trajectoryGeneration {
namespace coder {
static void generateCubicCoeffs(const real_T posPts[2], const real_T velPts[2],
                                real_T finalTime, real_T coeffVec[4]);

}
} // namespace trajectoryGeneration

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
static void generateCubicCoeffs(const real_T posPts[2], const real_T velPts[2],
                                real_T finalTime, real_T coeffVec[4])
{
  real_T d;
  real_T posPts_idx_0;
  real_T posPts_idx_1;
  d = finalTime * finalTime;
  posPts_idx_0 = posPts[1] - (posPts[0] + velPts[0] * finalTime);
  posPts_idx_1 = velPts[1] - (0.0 * posPts[0] + velPts[0]);
  coeffVec[2] = 3.0 / d * posPts_idx_0 + -1.0 / finalTime * posPts_idx_1;
  coeffVec[0] = -2.0 / muDoubleScalarPower(finalTime, 3.0) * posPts_idx_0 +
                1.0 / d * posPts_idx_1;
  coeffVec[3] = posPts[0];
  coeffVec[1] = coeffVec[2];
  coeffVec[2] = velPts[0];
}

void cubicpolytraj(const emlrtStack &sp, const real_T timePoints[2],
                   const ::coder::array<real_T, 2U> &t,
                   ::coder::array<real_T, 2U> &q,
                   ::coder::array<real_T, 2U> &qd,
                   ::coder::array<real_T, 2U> &qdd)
{
  __m128d r1;
  __m128d r2;
  __m128d r3;
  __m128d r4;
  ::coder::array<real_T, 2U> r;
  b_struct_T b_expl_temp;
  b_struct_T expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T dCoeffs[12];
  real_T coefsWithFlatStart[8];
  real_T newSegmentCoeffs[4];
  int32_T iv[2];
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
  st.site = &xb_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(timePoints[k])) &&
        (!muDoubleScalarIsNaN(timePoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cubicpolytraj:expectedFinite", 3, 4, 10, "timePoints");
  }
  b_st.site = &ib_emlrtRSI;
  if (!(timePoints[0] < timePoints[1])) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &i_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:cubicpolytraj:expectedIncreasing", 3, 4, 10, "timePoints");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(timePoints[k] < 0.0)) {
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
        "MATLAB:cubicpolytraj:expectedNonnegative", 3, 4, 10, "timePoints");
  }
  st.site = &yb_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  st.site = &ac_emlrtRSI;
  st.site = &bc_emlrtRSI;
  q.set_size(&yb_emlrtRTEI, &sp, 1, t.size(1));
  k = t.size(1);
  qd.set_size(&ac_emlrtRTEI, &sp, 1, t.size(1));
  qdd.set_size(&bc_emlrtRTEI, &sp, 1, t.size(1));
  for (int32_T i{0}; i < k; i++) {
    q[i] = 0.0;
    qd[i] = 0.0;
    qdd[i] = 0.0;
  }
  real_T dv[2];
  real_T dv1[2];
  real_T expl_temp_tmp;
  dv[0] = 0.0;
  dv1[0] = 0.0;
  dv[1] = 1.0;
  dv1[1] = 0.0;
  expl_temp_tmp = timePoints[1] - timePoints[0];
  st.site = &cc_emlrtRSI;
  generateCubicCoeffs(dv, dv1, expl_temp_tmp, expl_temp.breaks);
  st.site = &dc_emlrtRSI;
  coefsWithFlatStart[0] = 0.0;
  coefsWithFlatStart[1] = expl_temp.breaks[0];
  coefsWithFlatStart[2] = 0.0;
  coefsWithFlatStart[3] = expl_temp.breaks[1];
  coefsWithFlatStart[4] = 0.0;
  coefsWithFlatStart[5] = expl_temp.breaks[2];
  coefsWithFlatStart[6] =
      ((expl_temp.breaks[0] * 0.0 + expl_temp.breaks[1] * 0.0) +
       expl_temp.breaks[2] * 0.0) +
      expl_temp.breaks[3];
  coefsWithFlatStart[7] = expl_temp.breaks[3];
  b_st.site = &ub_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  expl_temp.breaks[0] = mpower(c_st, expl_temp_tmp, 3.0);
  c_st.site = &vb_emlrtRSI;
  expl_temp.breaks[1] = mpower(c_st, expl_temp_tmp, 2.0);
  c_st.site = &vb_emlrtRSI;
  expl_temp.breaks[2] = mpower(c_st, expl_temp_tmp, 1.0);
  c_st.site = &vb_emlrtRSI;
  expl_temp.breaks[3] = mpower(c_st, expl_temp_tmp, 0.0);
  newSegmentCoeffs[0] = 0.0;
  newSegmentCoeffs[1] = 0.0;
  newSegmentCoeffs[2] = 0.0;
  newSegmentCoeffs[3] = ((expl_temp.breaks[0] * coefsWithFlatStart[1] +
                          expl_temp.breaks[1] * coefsWithFlatStart[3]) +
                         expl_temp.breaks[2] * coefsWithFlatStart[5]) +
                        expl_temp.breaks[3] * coefsWithFlatStart[7];
  std::memset(&b_expl_temp.coefs[0], 0, 12U * sizeof(real_T));
  for (int32_T i{0}; i < 4; i++) {
    k = i << 1;
    b_expl_temp.coefs[3 * i] = coefsWithFlatStart[k];
    b_expl_temp.coefs[3 * i + 1] = coefsWithFlatStart[k + 1];
    b_expl_temp.coefs[3 * i + 2] = newSegmentCoeffs[i];
  }
  expl_temp.breaks[0] = timePoints[0] - 1.0;
  expl_temp.breaks[1] = timePoints[0];
  expl_temp.breaks[2] = timePoints[1];
  expl_temp.breaks[3] = timePoints[1] + 1.0;
  std::copy(&b_expl_temp.coefs[0], &b_expl_temp.coefs[12], &expl_temp.coefs[0]);
  st.site = &ec_emlrtRSI;
  ppval(st, expl_temp, t, r);
  iv[0] = 1;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &h_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (int32_T i{0}; i < k; i++) {
    q[i] = r[i];
  }
  st.site = &fc_emlrtRSI;
  robotics::core::internal::changeEndSegBreaks(st, expl_temp.breaks, t);
  std::memset(&dCoeffs[0], 0, 12U * sizeof(real_T));
  r1 = _mm_loadu_pd(&b_expl_temp.coefs[0]);
  r2 = _mm_set1_pd(3.0);
  _mm_storeu_pd(&dCoeffs[3], _mm_mul_pd(r2, r1));
  dCoeffs[5] = 3.0 * b_expl_temp.coefs[2];
  r1 = _mm_loadu_pd(&b_expl_temp.coefs[3]);
  r3 = _mm_set1_pd(2.0);
  _mm_storeu_pd(&dCoeffs[6], _mm_mul_pd(r3, r1));
  dCoeffs[8] = 2.0 * b_expl_temp.coefs[5];
  r1 = _mm_loadu_pd(&b_expl_temp.coefs[6]);
  r4 = _mm_set1_pd(1.0);
  _mm_storeu_pd(&dCoeffs[9], _mm_mul_pd(r4, r1));
  dCoeffs[11] = b_expl_temp.coefs[8];
  std::copy(&dCoeffs[0], &dCoeffs[12], &expl_temp.coefs[0]);
  st.site = &gc_emlrtRSI;
  ppval(st, expl_temp, t, r);
  iv[0] = 1;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &i_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (int32_T i{0}; i < k; i++) {
    qd[i] = r[i];
  }
  std::memset(&b_expl_temp.coefs[0], 0, 12U * sizeof(real_T));
  r1 = _mm_loadu_pd(&dCoeffs[0]);
  _mm_storeu_pd(&b_expl_temp.coefs[3], _mm_mul_pd(r2, r1));
  b_expl_temp.coefs[5] = 3.0 * dCoeffs[2];
  r1 = _mm_loadu_pd(&dCoeffs[3]);
  _mm_storeu_pd(&b_expl_temp.coefs[6], _mm_mul_pd(r3, r1));
  b_expl_temp.coefs[8] = 2.0 * dCoeffs[5];
  r1 = _mm_loadu_pd(&dCoeffs[6]);
  _mm_storeu_pd(&b_expl_temp.coefs[9], _mm_mul_pd(r4, r1));
  b_expl_temp.coefs[11] = dCoeffs[8];
  b_expl_temp.breaks[0] = expl_temp.breaks[0];
  b_expl_temp.breaks[1] = expl_temp.breaks[1];
  b_expl_temp.breaks[2] = expl_temp.breaks[2];
  b_expl_temp.breaks[3] = expl_temp.breaks[3];
  st.site = &hc_emlrtRSI;
  ppval(st, b_expl_temp, t, r);
  iv[0] = 1;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &j_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (int32_T i{0}; i < k; i++) {
    qdd[i] = r[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void cubicpolytraj(
    const emlrtStack &sp, const ::coder::array<real_T, 2U> &wayPoints,
    ::coder::array<real_T, 2U> &timePoints, const ::coder::array<real_T, 2U> &t,
    const ::coder::array<real_T, 2U> &varargin_2, ::coder::array<real_T, 2U> &q,
    ::coder::array<real_T, 2U> &qd, ::coder::array<real_T, 2U> &qdd)
{
  __m128d r2;
  ::coder::array<real_T, 3U> pp_coefs;
  ::coder::array<real_T, 2U> b_timePoints;
  ::coder::array<real_T, 2U> coefMat;
  ::coder::array<real_T, 2U> dCoeffs;
  ::coder::array<real_T, 2U> derivativeBreaks;
  ::coder::array<real_T, 2U> modCoeffs;
  ::coder::array<real_T, 2U> r;
  ::coder::array<real_T, 1U> r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T newsize[3];
  real_T finalTime;
  int32_T iv[2];
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T vectorUB;
  uint32_T unnamed_idx_0;
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &gh_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (wayPoints.size(1) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:cubicpolytraj:expectedNonempty", 3, 4, 9, "wayPoints");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  i = 3 * wayPoints.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(wayPoints[k])) &&
        (!muDoubleScalarIsNaN(wayPoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cubicpolytraj:expectedFinite", 3, 4, 9, "wayPoints");
  }
  st.site = &xb_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (timePoints.size(1) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:cubicpolytraj:expectedNonempty", 3, 4, 10, "timePoints");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= timePoints.size(1) - 1)) {
    if ((!muDoubleScalarIsInf(timePoints[k])) &&
        (!muDoubleScalarIsNaN(timePoints[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:cubicpolytraj:expectedFinite", 3, 4, 10, "timePoints");
  }
  b_st.site = &ib_emlrtRSI;
  if (timePoints.size(1) > 1) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= timePoints.size(1) - 2)) {
      if (!(timePoints[k] < timePoints[k + 1])) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedIncreasing",
            "MATLAB:cubicpolytraj:expectedIncreasing", 3, 4, 10, "timePoints");
      } else {
        k++;
      }
    }
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= timePoints.size(1) - 1)) {
    if (!(timePoints[k] < 0.0)) {
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
        "MATLAB:cubicpolytraj:expectedNonnegative", 3, 4, 10, "timePoints");
  }
  b_timePoints.set_size(&oe_emlrtRTEI, &sp, 1, timePoints.size(1));
  k = timePoints.size(1);
  for (i = 0; i < k; i++) {
    b_timePoints[i] = timePoints[i];
  }
  timePoints.set_size(&pe_emlrtRTEI, &sp, 1, b_timePoints.size(1));
  k = b_timePoints.size(1);
  for (i = 0; i < k; i++) {
    timePoints[i] = b_timePoints[i];
  }
  st.site = &yb_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  st.site = &ac_emlrtRSI;
  st.site = &bc_emlrtRSI;
  if (timePoints.size(1) != wayPoints.size(1)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &eb_emlrtRTEI, "shared_robotics:robotcore:utils:WayPointMismatch",
        "shared_robotics:robotcore:utils:WayPointMismatch", 0);
  }
  if (varargin_2.size(1) != wayPoints.size(1)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &fb_emlrtRTEI,
        "shared_robotics:robotcore:utils:WaypointVelocityBCDimensionMismatch",
        "shared_robotics:robotcore:utils:WaypointVelocityBCDimensionMismatch",
        0);
  }
  q.set_size(&yb_emlrtRTEI, &sp, 3, t.size(1));
  loop_ub_tmp = 3 * t.size(1);
  for (i = 0; i < loop_ub_tmp; i++) {
    q[i] = 0.0;
  }
  qd.set_size(&ac_emlrtRTEI, &sp, 3, t.size(1));
  for (i = 0; i < loop_ub_tmp; i++) {
    qd[i] = 0.0;
  }
  qdd.set_size(&bc_emlrtRTEI, &sp, 3, t.size(1));
  for (i = 0; i < loop_ub_tmp; i++) {
    qdd[i] = 0.0;
  }
  finalTime = (static_cast<real_T>(wayPoints.size(1)) - 1.0) * 3.0;
  if (finalTime != static_cast<int32_T>(finalTime)) {
    emlrtIntegerCheckR2012b(finalTime, &x_emlrtDCI, (emlrtConstCTX)&sp);
  }
  coefMat.set_size(&qe_emlrtRTEI, &sp, static_cast<int32_T>(finalTime), 4);
  if (finalTime != static_cast<int32_T>(finalTime)) {
    emlrtIntegerCheckR2012b(finalTime, &y_emlrtDCI, (emlrtConstCTX)&sp);
  }
  k = static_cast<int32_T>(finalTime) << 2;
  for (i = 0; i < k; i++) {
    coefMat[i] = 0.0;
  }
  i = wayPoints.size(1);
  for (int32_T b_i{0}; b_i <= i - 2; b_i++) {
    real_T b_wayPoints[2];
    if (b_i + 2 > timePoints.size(1)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, timePoints.size(1),
                                    &bd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    if (b_i + 1 > timePoints.size(1)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, timePoints.size(1),
                                    &cd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    finalTime = timePoints[b_i + 1] - timePoints[b_i];
    for (j = 0; j < 3; j++) {
      real_T dv[4];
      real_T b_varargin_2[2];
      if (b_i + 1 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, wayPoints.size(1),
                                      &ed_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_wayPoints[0] = wayPoints[j + 3 * b_i];
      if (b_i + 2 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, wayPoints.size(1),
                                      &ed_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_wayPoints[1] = wayPoints[j + 3 * (b_i + 1)];
      if (b_i + 1 > varargin_2.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, varargin_2.size(1),
                                      &dd_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_varargin_2[0] = varargin_2[j + 3 * b_i];
      if (b_i + 2 > varargin_2.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, varargin_2.size(1),
                                      &dd_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_varargin_2[1] = varargin_2[j + 3 * (b_i + 1)];
      st.site = &cc_emlrtRSI;
      generateCubicCoeffs(b_wayPoints, b_varargin_2, finalTime, dv);
      k = static_cast<int32_T>(((static_cast<real_T>(b_i) + 1.0) - 1.0) * 3.0 +
                               (static_cast<real_T>(j) + 1.0));
      if ((k < 1) || (k > coefMat.size(0))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, coefMat.size(0), &ad_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      coefMat[k - 1] = dv[0];
      coefMat[(k + coefMat.size(0)) - 1] = dv[1];
      coefMat[(k + coefMat.size(0) * 2) - 1] = dv[2];
      coefMat[(k + coefMat.size(0) * 3) - 1] = dv[3];
    }
  }
  st.site = &dc_emlrtRSI;
  robotics::core::internal::addFlatSegmentsToPPFormParts(
      st, timePoints, coefMat, derivativeBreaks, modCoeffs);
  st.site = &hh_emlrtRSI;
  newsize[0] = 3.0;
  newsize[1] = static_cast<real_T>(derivativeBreaks.size(1)) - 1.0;
  newsize[2] = 4.0;
  i = modCoeffs.size(0) << 2;
  if (!(3.0 * (static_cast<real_T>(derivativeBreaks.size(1)) - 1.0) * 4.0 ==
        i)) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  k = modCoeffs.size(0);
  if (derivativeBreaks.size(1) - 1 > muIntScalarMax_sint32(i, k)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((3 * (derivativeBreaks.size(1) - 1)) << 2 != i) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  pp_coefs.set_size(&re_emlrtRTEI, &st, 3, derivativeBreaks.size(1) - 1, 4);
  k = (3 * (derivativeBreaks.size(1) - 1)) << 2;
  for (i = 0; i < k; i++) {
    pp_coefs[i] = modCoeffs[i];
  }
  b_timePoints.set_size(&re_emlrtRTEI, &st, 1, derivativeBreaks.size(1));
  k = derivativeBreaks.size(1);
  for (i = 0; i < k; i++) {
    b_timePoints[i] = derivativeBreaks[i];
  }
  st.site = &ec_emlrtRSI;
  ppval(st, b_timePoints, pp_coefs, t, r);
  iv[0] = 3;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &h_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (i = 0; i < k; i++) {
    q[3 * i] = r[3 * i];
    q[3 * i + 1] = r[3 * i + 1];
    q[3 * i + 2] = r[3 * i + 2];
  }
  st.site = &fc_emlrtRSI;
  robotics::core::internal::changeEndSegBreaks(st, derivativeBreaks, t);
  st.site = &ih_emlrtRSI;
  unnamed_idx_0 = static_cast<uint32_T>(modCoeffs.size(0));
  dCoeffs.set_size(&se_emlrtRTEI, &st, static_cast<int32_T>(unnamed_idx_0), 4);
  loop_ub_tmp = static_cast<int32_T>(unnamed_idx_0) << 2;
  for (i = 0; i < loop_ub_tmp; i++) {
    dCoeffs[i] = 0.0;
  }
  k = modCoeffs.size(0);
  j = (k / 2) << 1;
  vectorUB = j - 2;
  for (int32_T b_i{0}; b_i < 3; b_i++) {
    r1.set_size(&ae_emlrtRTEI, &st, modCoeffs.size(0));
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&modCoeffs[i + modCoeffs.size(0) * b_i]);
      _mm_storeu_pd(
          &r1[i],
          _mm_mul_pd(
              _mm_set1_pd((4.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0), r2));
    }
    for (i = j; i < k; i++) {
      r1[i] = ((4.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0) *
              modCoeffs[i + modCoeffs.size(0) * b_i];
    }
    loop_ub = dCoeffs.size(0);
    emlrtSubAssignSizeCheckR2012b(&loop_ub, 1, r1.size(), 1, &q_emlrtECI, &st);
    for (i = 0; i < loop_ub; i++) {
      dCoeffs[i + dCoeffs.size(0) * (b_i + 1)] = r1[i];
    }
  }
  st.site = &jh_emlrtRSI;
  newsize[0] = 3.0;
  newsize[1] = static_cast<real_T>(derivativeBreaks.size(1)) - 1.0;
  newsize[2] = 4.0;
  finalTime = 3.0 * (static_cast<real_T>(derivativeBreaks.size(1)) - 1.0) * 4.0;
  if (!(finalTime == loop_ub_tmp)) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  k = dCoeffs.size(0);
  if (derivativeBreaks.size(1) - 1 > muIntScalarMax_sint32(loop_ub_tmp, k)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  i = (3 * (derivativeBreaks.size(1) - 1)) << 2;
  if (i != loop_ub_tmp) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  pp_coefs.set_size(&te_emlrtRTEI, &st, 3, derivativeBreaks.size(1) - 1, 4);
  loop_ub_tmp = (3 * (derivativeBreaks.size(1) - 1)) << 2;
  for (int32_T i1{0}; i1 < loop_ub_tmp; i1++) {
    pp_coefs[i1] = dCoeffs[i1];
  }
  b_timePoints.set_size(&te_emlrtRTEI, &st, 1, derivativeBreaks.size(1));
  k = derivativeBreaks.size(1);
  for (int32_T i1{0}; i1 < k; i1++) {
    b_timePoints[i1] = derivativeBreaks[i1];
  }
  st.site = &gc_emlrtRSI;
  ppval(st, b_timePoints, pp_coefs, t, r);
  iv[0] = 3;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &i_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (int32_T i1{0}; i1 < k; i1++) {
    qd[3 * i1] = r[3 * i1];
    qd[3 * i1 + 1] = r[3 * i1 + 1];
    qd[3 * i1 + 2] = r[3 * i1 + 2];
  }
  st.site = &kh_emlrtRSI;
  unnamed_idx_0 = static_cast<uint32_T>(dCoeffs.size(0));
  coefMat.set_size(&ue_emlrtRTEI, &st, static_cast<int32_T>(unnamed_idx_0), 4);
  b_loop_ub_tmp = static_cast<int32_T>(unnamed_idx_0) << 2;
  for (int32_T i1{0}; i1 < b_loop_ub_tmp; i1++) {
    coefMat[i1] = 0.0;
  }
  k = dCoeffs.size(0);
  j = (k / 2) << 1;
  vectorUB = j - 2;
  for (int32_T b_i{0}; b_i < 3; b_i++) {
    r1.set_size(&ae_emlrtRTEI, &st, dCoeffs.size(0));
    for (int32_T i1{0}; i1 <= vectorUB; i1 += 2) {
      r2 = _mm_loadu_pd(&dCoeffs[i1 + dCoeffs.size(0) * b_i]);
      _mm_storeu_pd(
          &r1[i1],
          _mm_mul_pd(
              _mm_set1_pd((4.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0), r2));
    }
    for (int32_T i1{j}; i1 < k; i1++) {
      r1[i1] = ((4.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0) *
               dCoeffs[i1 + dCoeffs.size(0) * b_i];
    }
    emlrtSubAssignSizeCheckR2012b(coefMat.size(), 1, r1.size(), 1, &q_emlrtECI,
                                  &st);
    loop_ub = coefMat.size(0);
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      coefMat[i1 + coefMat.size(0) * (b_i + 1)] = r1[i1];
    }
  }
  st.site = &lh_emlrtRSI;
  newsize[0] = 3.0;
  newsize[1] = static_cast<real_T>(derivativeBreaks.size(1)) - 1.0;
  newsize[2] = 4.0;
  if (static_cast<int32_T>(finalTime) != b_loop_ub_tmp) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  k = coefMat.size(0);
  if (derivativeBreaks.size(1) - 1 > muIntScalarMax_sint32(b_loop_ub_tmp, k)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (i != b_loop_ub_tmp) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  pp_coefs.set_size(&ve_emlrtRTEI, &st, 3, derivativeBreaks.size(1) - 1, 4);
  for (i = 0; i < loop_ub_tmp; i++) {
    pp_coefs[i] = coefMat[i];
  }
  b_timePoints.set_size(&ve_emlrtRTEI, &st, 1, derivativeBreaks.size(1));
  k = derivativeBreaks.size(1);
  for (i = 0; i < k; i++) {
    b_timePoints[i] = derivativeBreaks[i];
  }
  st.site = &hc_emlrtRSI;
  ppval(st, b_timePoints, pp_coefs, t, r);
  iv[0] = 3;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &j_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (i = 0; i < k; i++) {
    qdd[3 * i] = r[3 * i];
    qdd[3 * i + 1] = r[3 * i + 1];
    qdd[3 * i + 2] = r[3 * i + 2];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (cubicpolytraj.cpp)
