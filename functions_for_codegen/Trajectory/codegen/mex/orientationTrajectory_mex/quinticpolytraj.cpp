//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// quinticpolytraj.cpp
//
// Code generation for function 'quinticpolytraj'
//

// Include files
#include "quinticpolytraj.h"
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

// Type Definitions
namespace trajectoryGeneration {
struct cell_wrap_17 {
  real_T f1[2];
};

} // namespace trajectoryGeneration

// Variable Definitions
static emlrtRSInfo oc_emlrtRSI{
    73,                // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    85,                // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo qc_emlrtRSI{
    86,                // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo rc_emlrtRSI{
    87,                // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo sc_emlrtRSI{
    88,                // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo tc_emlrtRSI{
    115,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo uc_emlrtRSI{
    125,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo vc_emlrtRSI{
    129,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo wc_emlrtRSI{
    136,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo xc_emlrtRSI{
    141,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo yc_emlrtRSI{
    148,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo mh_emlrtRSI{
    72,                // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo nh_emlrtRSI{
    128,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo oh_emlrtRSI{
    139,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo ph_emlrtRSI{
    140,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo qh_emlrtRSI{
    146,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtRSInfo rh_emlrtRSI{
    147,               // lineNo
    "quinticpolytraj", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pathName
};

static emlrtECInfo k_emlrtECI{
    -1,                // nDims
    141,               // lineNo
    9,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtECInfo l_emlrtECI{
    -1,                // nDims
    148,               // lineNo
    9,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtECInfo m_emlrtECI{
    -1,                // nDims
    129,               // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    91,                // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    92,                // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    93,                // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtBCInfo hd_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    119,               // lineNo
    21,                // colNo
    "",                // aName
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    0 // checkKind
};

static emlrtDCInfo ab_emlrtDCI{
    104,               // lineNo
    21,                // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    1 // checkKind
};

static emlrtDCInfo bb_emlrtDCI{
    104,               // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    1 // checkKind
};

static emlrtBCInfo id_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    110,               // lineNo
    32,                // colNo
    "",                // aName
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo jd_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    110,               // lineNo
    50,                // colNo
    "",                // aName
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo kd_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    115,               // lineNo
    97,                // colNo
    "",                // aName
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo ld_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    115,               // lineNo
    80,                // colNo
    "",                // aName
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    0 // checkKind
};

static emlrtBCInfo md_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    115,               // lineNo
    63,                // colNo
    "",                // aName
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m", // pName
    0 // checkKind
};

static emlrtRTEInfo cc_emlrtRTEI{
    96,                // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    97,                // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    98,                // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo we_emlrtRTEI{
    76,                // lineNo
    18,                // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo xe_emlrtRTEI{
    76,                // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo ye_emlrtRTEI{
    104,               // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo af_emlrtRTEI{
    128,               // lineNo
    5,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo bf_emlrtRTEI{
    139,               // lineNo
    9,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo cf_emlrtRTEI{
    140,               // lineNo
    9,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo df_emlrtRTEI{
    146,               // lineNo
    9,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

static emlrtRTEInfo ef_emlrtRTEI{
    147,               // lineNo
    9,                 // colNo
    "quinticpolytraj", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/quinticpolytraj.m" // pName
};

// Function Declarations
namespace trajectoryGeneration {
namespace coder {
static void generateQuinticCoeffs(const real_T posPts[2],
                                  const real_T velPts[2],
                                  const real_T accPts[2], real_T finalTime,
                                  real_T coeffVec[6]);

}
} // namespace trajectoryGeneration

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
static void generateQuinticCoeffs(const real_T posPts[2],
                                  const real_T velPts[2],
                                  const real_T accPts[2], real_T finalTime,
                                  real_T coeffVec[6])
{
  __m128d r;
  __m128d r1;
  real_T dv[9];
  real_T y[3];
  real_T d;
  real_T posPts_idx_1;
  real_T posPts_idx_2;
  real_T xtmp;
  coeffVec[0] = posPts[0];
  coeffVec[1] = velPts[0];
  coeffVec[2] = accPts[0] / 2.0;
  coeffVec[3] = 0.0;
  coeffVec[4] = 0.0;
  coeffVec[5] = 0.0;
  dv[0] = 1.0;
  dv[3] = finalTime;
  xtmp = finalTime * finalTime;
  dv[6] = xtmp;
  dv[1] = 0.0;
  dv[4] = 1.0;
  dv[7] = 2.0 * finalTime;
  dv[2] = 0.0;
  dv[5] = 0.0;
  dv[8] = 2.0;
  posPts_idx_1 = posPts[0];
  posPts_idx_2 = velPts[0];
  d = coeffVec[2];
  r = _mm_loadu_pd(&dv[0]);
  r = _mm_mul_pd(r, _mm_set1_pd(posPts_idx_1));
  r1 = _mm_loadu_pd(&dv[3]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(posPts_idx_2));
  r = _mm_add_pd(r, r1);
  r1 = _mm_loadu_pd(&dv[6]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(d));
  r = _mm_add_pd(r, r1);
  _mm_storeu_pd(&y[0], r);
  y[2] = (dv[2] * posPts_idx_1 + dv[5] * posPts_idx_2) + dv[8] * d;
  posPts_idx_1 = muDoubleScalarPower(finalTime, 3.0);
  dv[0] = 10.0 / posPts_idx_1;
  dv[3] = -4.0 / xtmp;
  dv[6] = 1.0 / (2.0 * finalTime);
  posPts_idx_2 = muDoubleScalarPower(finalTime, 4.0);
  dv[1] = -15.0 / posPts_idx_2;
  dv[4] = 7.0 / posPts_idx_1;
  dv[7] = -1.0 / xtmp;
  dv[2] = 6.0 / muDoubleScalarPower(finalTime, 5.0);
  dv[5] = -3.0 / posPts_idx_2;
  dv[8] = 1.0 / (2.0 * posPts_idx_1);
  xtmp = posPts[1] - y[0];
  posPts_idx_1 = velPts[1] - y[1];
  posPts_idx_2 = accPts[1] - y[2];
  r = _mm_loadu_pd(&dv[0]);
  r = _mm_mul_pd(r, _mm_set1_pd(xtmp));
  r1 = _mm_loadu_pd(&dv[3]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(posPts_idx_1));
  r = _mm_add_pd(r, r1);
  r1 = _mm_loadu_pd(&dv[6]);
  r1 = _mm_mul_pd(r1, _mm_set1_pd(posPts_idx_2));
  r = _mm_add_pd(r, r1);
  _mm_storeu_pd(&coeffVec[3], r);
  coeffVec[5] = (dv[2] * xtmp + dv[5] * posPts_idx_1) + dv[8] * posPts_idx_2;
  xtmp = coeffVec[0];
  coeffVec[0] = coeffVec[5];
  coeffVec[5] = xtmp;
  xtmp = coeffVec[1];
  coeffVec[1] = coeffVec[4];
  coeffVec[4] = xtmp;
  xtmp = coeffVec[2];
  coeffVec[2] = coeffVec[3];
  coeffVec[3] = xtmp;
}

void quinticpolytraj(const emlrtStack &sp, const real_T timePoints[2],
                     const ::coder::array<real_T, 2U> &t,
                     ::coder::array<real_T, 2U> &q,
                     ::coder::array<real_T, 2U> &qd,
                     ::coder::array<real_T, 2U> &qdd)
{
  static const int8_T iv[6]{0, 0, 0, 0, 0, 1};
  __m128d r3;
  ::coder::array<real_T, 2U> r2;
  c_struct_T b_expl_temp;
  c_struct_T expl_temp;
  cell_wrap_17 r;
  cell_wrap_17 r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T dCoeffs[18];
  real_T coefsWithFlatStart[12];
  real_T coeffMat[6];
  real_T newSegmentCoeffs[6];
  real_T b_coeffMat;
  real_T coeffMat_tmp;
  int32_T iv1[2];
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
  st.site = &oc_emlrtRSI;
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
        "MATLAB:quinticpolytraj:expectedFinite", 3, 4, 10, "timePoints");
  }
  b_st.site = &ib_emlrtRSI;
  if (!(timePoints[0] < timePoints[1])) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &i_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:quinticpolytraj:expectedIncreasing", 3, 4, 10, "timePoints");
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
        "MATLAB:quinticpolytraj:expectedNonnegative", 3, 4, 10, "timePoints");
  }
  st.site = &pc_emlrtRSI;
  r.f1[0] = 0.0;
  r1.f1[0] = 0.0;
  r.f1[1] = 0.0;
  r1.f1[1] = 0.0;
  b_st.site = &jb_emlrtRSI;
  st.site = &qc_emlrtRSI;
  st.site = &rc_emlrtRSI;
  st.site = &sc_emlrtRSI;
  q.set_size(&cc_emlrtRTEI, &sp, 1, t.size(1));
  k = t.size(1);
  qd.set_size(&dc_emlrtRTEI, &sp, 1, t.size(1));
  qdd.set_size(&ec_emlrtRTEI, &sp, 1, t.size(1));
  for (i = 0; i < k; i++) {
    q[i] = 0.0;
    qd[i] = 0.0;
    qdd[i] = 0.0;
  }
  real_T dv[2];
  dv[0] = 0.0;
  dv[1] = 1.0;
  coeffMat_tmp = timePoints[1] - timePoints[0];
  st.site = &tc_emlrtRSI;
  generateQuinticCoeffs(dv, r.f1, r1.f1, coeffMat_tmp, coeffMat);
  st.site = &uc_emlrtRSI;
  b_coeffMat = 0.0;
  for (i = 0; i < 6; i++) {
    newSegmentCoeffs[i] = 0.0;
    b_coeffMat += coeffMat[i] * static_cast<real_T>(iv[i]);
  }
  newSegmentCoeffs[5] = b_coeffMat;
  for (i = 0; i < 6; i++) {
    k = i << 1;
    coefsWithFlatStart[k] = newSegmentCoeffs[i];
    coefsWithFlatStart[k + 1] = coeffMat[i];
  }
  b_st.site = &ub_emlrtRSI;
  for (k = 0; k < 6; k++) {
    c_st.site = &vb_emlrtRSI;
    coeffMat[k] =
        mpower(c_st, coeffMat_tmp, 6.0 - (static_cast<real_T>(k) + 1.0));
  }
  coeffMat_tmp = 0.0;
  for (i = 0; i < 6; i++) {
    newSegmentCoeffs[i] = 0.0;
    coeffMat_tmp += coeffMat[i] * coefsWithFlatStart[(i << 1) + 1];
  }
  newSegmentCoeffs[5] = coeffMat_tmp;
  std::memset(&expl_temp.coefs[0], 0, 18U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    k = i << 1;
    expl_temp.coefs[3 * i] = coefsWithFlatStart[k];
    expl_temp.coefs[3 * i + 1] = coefsWithFlatStart[k + 1];
    expl_temp.coefs[3 * i + 2] = newSegmentCoeffs[i];
  }
  b_expl_temp.breaks[0] = timePoints[0] - 1.0;
  b_expl_temp.breaks[1] = timePoints[0];
  b_expl_temp.breaks[2] = timePoints[1];
  b_expl_temp.breaks[3] = timePoints[1] + 1.0;
  std::copy(&expl_temp.coefs[0], &expl_temp.coefs[18], &b_expl_temp.coefs[0]);
  st.site = &vc_emlrtRSI;
  ppval(st, b_expl_temp, t, r2);
  iv1[0] = 1;
  iv1[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, r2.size(), 2, &m_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (i = 0; i < k; i++) {
    q[i] = r2[i];
  }
  st.site = &wc_emlrtRSI;
  robotics::core::internal::changeEndSegBreaks(st, b_expl_temp.breaks, t);
  std::memset(&dCoeffs[0], 0, 18U * sizeof(real_T));
  for (k = 0; k < 5; k++) {
    r3 = _mm_loadu_pd(&expl_temp.coefs[3 * k]);
    i = 3 * (k + 1);
    _mm_storeu_pd(
        &dCoeffs[i],
        _mm_mul_pd(_mm_set1_pd((6.0 - (static_cast<real_T>(k) + 2.0)) + 1.0),
                   r3));
    dCoeffs[i + 2] = ((6.0 - (static_cast<real_T>(k) + 2.0)) + 1.0) *
                     expl_temp.coefs[3 * k + 2];
  }
  std::copy(&dCoeffs[0], &dCoeffs[18], &b_expl_temp.coefs[0]);
  st.site = &xc_emlrtRSI;
  ppval(st, b_expl_temp, t, r2);
  iv1[0] = 1;
  iv1[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, r2.size(), 2, &k_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (i = 0; i < k; i++) {
    qd[i] = r2[i];
  }
  std::memset(&expl_temp.coefs[0], 0, 18U * sizeof(real_T));
  for (k = 0; k < 5; k++) {
    r3 = _mm_loadu_pd(&dCoeffs[3 * k]);
    i = 3 * (k + 1);
    _mm_storeu_pd(
        &expl_temp.coefs[i],
        _mm_mul_pd(_mm_set1_pd((6.0 - (static_cast<real_T>(k) + 2.0)) + 1.0),
                   r3));
    expl_temp.coefs[i + 2] =
        ((6.0 - (static_cast<real_T>(k) + 2.0)) + 1.0) * dCoeffs[3 * k + 2];
  }
  expl_temp.breaks[0] = b_expl_temp.breaks[0];
  expl_temp.breaks[1] = b_expl_temp.breaks[1];
  expl_temp.breaks[2] = b_expl_temp.breaks[2];
  expl_temp.breaks[3] = b_expl_temp.breaks[3];
  st.site = &yc_emlrtRSI;
  ppval(st, expl_temp, t, r2);
  iv1[0] = 1;
  iv1[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, r2.size(), 2, &l_emlrtECI,
                                (emlrtCTX)&sp);
  k = t.size(1);
  for (i = 0; i < k; i++) {
    qdd[i] = r2[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void quinticpolytraj(
    const emlrtStack &sp, const ::coder::array<real_T, 2U> &wayPoints,
    ::coder::array<real_T, 2U> &timePoints, const ::coder::array<real_T, 2U> &t,
    const ::coder::array<real_T, 2U> &varargin_2,
    const ::coder::array<real_T, 2U> &varargin_4, ::coder::array<real_T, 2U> &q,
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
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T nx;
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
  st.site = &mh_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (wayPoints.size(1) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:quinticpolytraj:expectedNonempty", 3, 4, 9, "wayPoints");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  i = 3 * wayPoints.size(1);
  nx = 0;
  exitg1 = false;
  while ((!exitg1) && (nx <= i - 1)) {
    if ((!muDoubleScalarIsInf(wayPoints[nx])) &&
        (!muDoubleScalarIsNaN(wayPoints[nx]))) {
      nx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:quinticpolytraj:expectedFinite", 3, 4, 9, "wayPoints");
  }
  st.site = &oc_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (timePoints.size(1) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:quinticpolytraj:expectedNonempty", 3, 4, 10, "timePoints");
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  nx = 0;
  exitg1 = false;
  while ((!exitg1) && (nx <= timePoints.size(1) - 1)) {
    if ((!muDoubleScalarIsInf(timePoints[nx])) &&
        (!muDoubleScalarIsNaN(timePoints[nx]))) {
      nx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:quinticpolytraj:expectedFinite", 3, 4, 10, "timePoints");
  }
  b_st.site = &ib_emlrtRSI;
  if (timePoints.size(1) > 1) {
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx <= timePoints.size(1) - 2)) {
      if (!(timePoints[nx] < timePoints[nx + 1])) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedIncreasing",
            "MATLAB:quinticpolytraj:expectedIncreasing", 3, 4, 10,
            "timePoints");
      } else {
        nx++;
      }
    }
  }
  b_st.site = &ib_emlrtRSI;
  p = true;
  nx = 0;
  exitg1 = false;
  while ((!exitg1) && (nx <= timePoints.size(1) - 1)) {
    if (!(timePoints[nx] < 0.0)) {
      nx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:quinticpolytraj:expectedNonnegative", 3, 4, 10, "timePoints");
  }
  b_timePoints.set_size(&we_emlrtRTEI, &sp, 1, timePoints.size(1));
  nx = timePoints.size(1);
  for (i = 0; i < nx; i++) {
    b_timePoints[i] = timePoints[i];
  }
  timePoints.set_size(&xe_emlrtRTEI, &sp, 1, b_timePoints.size(1));
  nx = b_timePoints.size(1);
  for (i = 0; i < nx; i++) {
    timePoints[i] = b_timePoints[i];
  }
  st.site = &pc_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  st.site = &qc_emlrtRSI;
  st.site = &rc_emlrtRSI;
  st.site = &sc_emlrtRSI;
  if (timePoints.size(1) != wayPoints.size(1)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &gb_emlrtRTEI, "shared_robotics:robotcore:utils:WayPointMismatch",
        "shared_robotics:robotcore:utils:WayPointMismatch", 0);
  }
  if (varargin_2.size(1) != wayPoints.size(1)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &hb_emlrtRTEI,
        "shared_robotics:robotcore:utils:WaypointVelocityBCDimensionMismatch",
        "shared_robotics:robotcore:utils:WaypointVelocityBCDimensionMismatch",
        0);
  }
  if (varargin_4.size(1) != wayPoints.size(1)) {
    emlrtErrorWithMessageIdR2018a(&sp, &ib_emlrtRTEI,
                                  "shared_robotics:robotcore:utils:"
                                  "WaypointAccelerationBCDimensionMismatch",
                                  "shared_robotics:robotcore:utils:"
                                  "WaypointAccelerationBCDimensionMismatch",
                                  0);
  }
  q.set_size(&cc_emlrtRTEI, &sp, 3, t.size(1));
  loop_ub_tmp = 3 * t.size(1);
  for (i = 0; i < loop_ub_tmp; i++) {
    q[i] = 0.0;
  }
  qd.set_size(&dc_emlrtRTEI, &sp, 3, t.size(1));
  for (i = 0; i < loop_ub_tmp; i++) {
    qd[i] = 0.0;
  }
  qdd.set_size(&ec_emlrtRTEI, &sp, 3, t.size(1));
  for (i = 0; i < loop_ub_tmp; i++) {
    qdd[i] = 0.0;
  }
  finalTime = (static_cast<real_T>(wayPoints.size(1)) - 1.0) * 3.0;
  if (finalTime != static_cast<int32_T>(finalTime)) {
    emlrtIntegerCheckR2012b(finalTime, &ab_emlrtDCI, (emlrtConstCTX)&sp);
  }
  coefMat.set_size(&ye_emlrtRTEI, &sp, static_cast<int32_T>(finalTime), 6);
  if (finalTime != static_cast<int32_T>(finalTime)) {
    emlrtIntegerCheckR2012b(finalTime, &bb_emlrtDCI, (emlrtConstCTX)&sp);
  }
  nx = static_cast<int32_T>(finalTime) * 6;
  for (i = 0; i < nx; i++) {
    coefMat[i] = 0.0;
  }
  i = wayPoints.size(1);
  for (int32_T b_i{0}; b_i <= i - 2; b_i++) {
    real_T coeffMat[18];
    real_T b_wayPoints[2];
    if (b_i + 2 > timePoints.size(1)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, timePoints.size(1),
                                    &id_emlrtBCI, (emlrtConstCTX)&sp);
    }
    if (b_i + 1 > timePoints.size(1)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, timePoints.size(1),
                                    &jd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    finalTime = timePoints[b_i + 1] - timePoints[b_i];
    for (j = 0; j < 3; j++) {
      real_T dv[6];
      real_T b_varargin_2[2];
      real_T b_varargin_4[2];
      if (b_i + 1 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, wayPoints.size(1),
                                      &md_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_wayPoints[0] = wayPoints[j + 3 * b_i];
      if (b_i + 2 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, wayPoints.size(1),
                                      &md_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_wayPoints[1] = wayPoints[j + 3 * (b_i + 1)];
      if (b_i + 1 > varargin_2.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, varargin_2.size(1),
                                      &ld_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_varargin_2[0] = varargin_2[j + 3 * b_i];
      if (b_i + 2 > varargin_2.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, varargin_2.size(1),
                                      &ld_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_varargin_2[1] = varargin_2[j + 3 * (b_i + 1)];
      if (b_i + 1 > varargin_4.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, varargin_4.size(1),
                                      &kd_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_varargin_4[0] = varargin_4[j + 3 * b_i];
      if (b_i + 2 > varargin_4.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, varargin_4.size(1),
                                      &kd_emlrtBCI, (emlrtConstCTX)&sp);
      }
      b_varargin_4[1] = varargin_4[j + 3 * (b_i + 1)];
      st.site = &tc_emlrtRSI;
      generateQuinticCoeffs(b_wayPoints, b_varargin_2, b_varargin_4, finalTime,
                            dv);
      for (int32_T i1{0}; i1 < 6; i1++) {
        coeffMat[j + 3 * i1] = dv[i1];
      }
      nx = static_cast<int32_T>(((static_cast<real_T>(b_i) + 1.0) - 1.0) * 3.0 +
                                (static_cast<real_T>(j) + 1.0));
      if ((nx < 1) || (nx > coefMat.size(0))) {
        emlrtDynamicBoundsCheckR2012b(nx, 1, coefMat.size(0), &hd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      for (int32_T i1{0}; i1 < 6; i1++) {
        coefMat[(nx + coefMat.size(0) * i1) - 1] = coeffMat[j + 3 * i1];
      }
    }
  }
  st.site = &uc_emlrtRSI;
  robotics::core::internal::b_addFlatSegmentsToPPFormParts(
      st, timePoints, coefMat, derivativeBreaks, modCoeffs);
  st.site = &nh_emlrtRSI;
  newsize[0] = 3.0;
  newsize[1] = static_cast<real_T>(derivativeBreaks.size(1)) - 1.0;
  newsize[2] = 6.0;
  if (!(3.0 * (static_cast<real_T>(derivativeBreaks.size(1)) - 1.0) * 6.0 ==
        modCoeffs.size(0) * 6)) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  nx = modCoeffs.size(0) * 6;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  j = modCoeffs.size(0);
  if (derivativeBreaks.size(1) - 1 > muIntScalarMax_sint32(nx, j)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (3 * (derivativeBreaks.size(1) - 1) * 6 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  pp_coefs.set_size(&af_emlrtRTEI, &st, 3, derivativeBreaks.size(1) - 1, 6);
  nx = 3 * (derivativeBreaks.size(1) - 1) * 6;
  for (i = 0; i < nx; i++) {
    pp_coefs[i] = modCoeffs[i];
  }
  b_timePoints.set_size(&af_emlrtRTEI, &st, 1, derivativeBreaks.size(1));
  nx = derivativeBreaks.size(1);
  for (i = 0; i < nx; i++) {
    b_timePoints[i] = derivativeBreaks[i];
  }
  st.site = &vc_emlrtRSI;
  b_ppval(st, b_timePoints, pp_coefs, t, r);
  iv[0] = 3;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &m_emlrtECI,
                                (emlrtCTX)&sp);
  nx = t.size(1);
  for (i = 0; i < nx; i++) {
    q[3 * i] = r[3 * i];
    q[3 * i + 1] = r[3 * i + 1];
    q[3 * i + 2] = r[3 * i + 2];
  }
  st.site = &wc_emlrtRSI;
  robotics::core::internal::changeEndSegBreaks(st, derivativeBreaks, t);
  st.site = &oh_emlrtRSI;
  unnamed_idx_0 = static_cast<uint32_T>(modCoeffs.size(0));
  dCoeffs.set_size(&bf_emlrtRTEI, &st, static_cast<int32_T>(unnamed_idx_0), 6);
  loop_ub_tmp = static_cast<int32_T>(unnamed_idx_0) * 6;
  for (i = 0; i < loop_ub_tmp; i++) {
    dCoeffs[i] = 0.0;
  }
  nx = modCoeffs.size(0);
  j = (nx / 2) << 1;
  vectorUB = j - 2;
  for (int32_T b_i{0}; b_i < 5; b_i++) {
    r1.set_size(&ae_emlrtRTEI, &st, modCoeffs.size(0));
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&modCoeffs[i + modCoeffs.size(0) * b_i]);
      _mm_storeu_pd(
          &r1[i],
          _mm_mul_pd(
              _mm_set1_pd((6.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0), r2));
    }
    for (i = j; i < nx; i++) {
      r1[i] = ((6.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0) *
              modCoeffs[i + modCoeffs.size(0) * b_i];
    }
    loop_ub = dCoeffs.size(0);
    emlrtSubAssignSizeCheckR2012b(&loop_ub, 1, r1.size(), 1, &q_emlrtECI, &st);
    for (i = 0; i < loop_ub; i++) {
      dCoeffs[i + dCoeffs.size(0) * (b_i + 1)] = r1[i];
    }
  }
  st.site = &ph_emlrtRSI;
  newsize[0] = 3.0;
  newsize[1] = static_cast<real_T>(derivativeBreaks.size(1)) - 1.0;
  newsize[2] = 6.0;
  finalTime = 3.0 * (static_cast<real_T>(derivativeBreaks.size(1)) - 1.0) * 6.0;
  if (!(finalTime == dCoeffs.size(0) * 6)) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  j = dCoeffs.size(0);
  if (derivativeBreaks.size(1) - 1 > muIntScalarMax_sint32(loop_ub_tmp, j)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  i = 3 * (derivativeBreaks.size(1) - 1) * 6;
  if (i != loop_ub_tmp) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  pp_coefs.set_size(&cf_emlrtRTEI, &st, 3, derivativeBreaks.size(1) - 1, 6);
  loop_ub_tmp = 3 * (derivativeBreaks.size(1) - 1) * 6;
  for (int32_T i1{0}; i1 < loop_ub_tmp; i1++) {
    pp_coefs[i1] = dCoeffs[i1];
  }
  b_timePoints.set_size(&cf_emlrtRTEI, &st, 1, derivativeBreaks.size(1));
  nx = derivativeBreaks.size(1);
  for (int32_T i1{0}; i1 < nx; i1++) {
    b_timePoints[i1] = derivativeBreaks[i1];
  }
  st.site = &xc_emlrtRSI;
  b_ppval(st, b_timePoints, pp_coefs, t, r);
  iv[0] = 3;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &k_emlrtECI,
                                (emlrtCTX)&sp);
  nx = t.size(1);
  for (int32_T i1{0}; i1 < nx; i1++) {
    qd[3 * i1] = r[3 * i1];
    qd[3 * i1 + 1] = r[3 * i1 + 1];
    qd[3 * i1 + 2] = r[3 * i1 + 2];
  }
  st.site = &qh_emlrtRSI;
  unnamed_idx_0 = static_cast<uint32_T>(dCoeffs.size(0));
  coefMat.set_size(&df_emlrtRTEI, &st, static_cast<int32_T>(unnamed_idx_0), 6);
  b_loop_ub_tmp = static_cast<int32_T>(unnamed_idx_0) * 6;
  for (int32_T i1{0}; i1 < b_loop_ub_tmp; i1++) {
    coefMat[i1] = 0.0;
  }
  nx = dCoeffs.size(0);
  j = (nx / 2) << 1;
  vectorUB = j - 2;
  for (int32_T b_i{0}; b_i < 5; b_i++) {
    r1.set_size(&ae_emlrtRTEI, &st, dCoeffs.size(0));
    for (int32_T i1{0}; i1 <= vectorUB; i1 += 2) {
      r2 = _mm_loadu_pd(&dCoeffs[i1 + dCoeffs.size(0) * b_i]);
      _mm_storeu_pd(
          &r1[i1],
          _mm_mul_pd(
              _mm_set1_pd((6.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0), r2));
    }
    for (int32_T i1{j}; i1 < nx; i1++) {
      r1[i1] = ((6.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0) *
               dCoeffs[i1 + dCoeffs.size(0) * b_i];
    }
    emlrtSubAssignSizeCheckR2012b(coefMat.size(), 1, r1.size(), 1, &q_emlrtECI,
                                  &st);
    loop_ub = coefMat.size(0);
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      coefMat[i1 + coefMat.size(0) * (b_i + 1)] = r1[i1];
    }
  }
  st.site = &rh_emlrtRSI;
  newsize[0] = 3.0;
  newsize[1] = static_cast<real_T>(derivativeBreaks.size(1)) - 1.0;
  newsize[2] = 6.0;
  if (static_cast<int32_T>(finalTime) != coefMat.size(0) * 6) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  j = coefMat.size(0);
  if (derivativeBreaks.size(1) - 1 > muIntScalarMax_sint32(b_loop_ub_tmp, j)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (i != b_loop_ub_tmp) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  pp_coefs.set_size(&ef_emlrtRTEI, &st, 3, derivativeBreaks.size(1) - 1, 6);
  for (i = 0; i < loop_ub_tmp; i++) {
    pp_coefs[i] = coefMat[i];
  }
  b_timePoints.set_size(&ef_emlrtRTEI, &st, 1, derivativeBreaks.size(1));
  nx = derivativeBreaks.size(1);
  for (i = 0; i < nx; i++) {
    b_timePoints[i] = derivativeBreaks[i];
  }
  st.site = &yc_emlrtRSI;
  b_ppval(st, b_timePoints, pp_coefs, t, r);
  iv[0] = 3;
  iv[1] = t.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &l_emlrtECI,
                                (emlrtCTX)&sp);
  nx = t.size(1);
  for (i = 0; i < nx; i++) {
    qdd[3 * i] = r[3 * i];
    qdd[3 * i + 1] = r[3 * i + 1];
    qdd[3 * i + 2] = r[3 * i + 2];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (quinticpolytraj.cpp)
