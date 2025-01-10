//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// addFlatSegmentsToPPFormParts.cpp
//
// Code generation for function 'addFlatSegmentsToPPFormParts'
//

// Include files
#include "addFlatSegmentsToPPFormParts.h"
#include "mpower.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo rg_emlrtRSI{
    18,                             // lineNo
    "addFlatSegmentsToPPFormParts", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pathName
};

static emlrtRSInfo sg_emlrtRSI{
    37,                  // lineNo
    "addSegmentToStart", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pathName
};

static emlrtRSInfo tg_emlrtRSI{
    33,                  // lineNo
    "addSegmentToStart", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pathName
};

static emlrtRSInfo
    ug_emlrtRSI{
        94,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pathName
    };

static emlrtRSInfo
    vg_emlrtRSI{
        142,      // lineNo
        "mtimes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRSInfo
    wg_emlrtRSI{
        178,           // lineNo
        "mtimes_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRSInfo xg_emlrtRSI{
    68,                // lineNo
    "addSegmentToEnd", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pathName
};

static emlrtRSInfo yg_emlrtRSI{
    64,                // lineNo
    "addSegmentToEnd", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pathName
};

static emlrtECInfo r_emlrtECI{
    -1,                  // nDims
    43,                  // lineNo
    1,                   // colNo
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtBCInfo nc_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    43,                  // lineNo
    20,                  // colNo
    "",                  // aName
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo oc_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    43,                  // lineNo
    12,                  // colNo
    "",                  // aName
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtECInfo s_emlrtECI{
    -1,                  // nDims
    42,                  // lineNo
    1,                   // colNo
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtBCInfo pc_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    42,                  // lineNo
    12,                  // colNo
    "",                  // aName
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo qc_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    33,                  // lineNo
    24,                  // colNo
    "",                  // aName
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo rc_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    33,                  // lineNo
    22,                  // colNo
    "",                  // aName
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtECInfo t_emlrtECI{
    -1,                // nDims
    74,                // lineNo
    1,                 // colNo
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtBCInfo sc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    74,                // lineNo
    19,                // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo tc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    74,                // lineNo
    12,                // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtECInfo u_emlrtECI{
    -1,                // nDims
    73,                // lineNo
    1,                 // colNo
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtBCInfo uc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    73,                // lineNo
    12,                // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo vc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    64,                // lineNo
    32,                // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo wc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    64,                // lineNo
    21,                // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtECInfo v_emlrtECI{
    -1,                               // nDims
    85,                               // lineNo
    1,                                // colNo
    "createConstantPolynomialCoeffs", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtDCInfo t_emlrtDCI{
    41,                  // lineNo
    18,                  // colNo
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    1                                           // checkKind
};

static emlrtDCInfo u_emlrtDCI{
    72,                // lineNo
    18,                // colNo
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    1                                           // checkKind
};

static emlrtDCInfo v_emlrtDCI{
    41,                  // lineNo
    1,                   // colNo
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    1                                           // checkKind
};

static emlrtBCInfo xc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    59,                // lineNo
    20,                // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo yc_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    59,                // lineNo
    32,                // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtDCInfo w_emlrtDCI{
    72,                // lineNo
    1,                 // colNo
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    1                                           // checkKind
};

static emlrtBCInfo fd_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    46,                  // lineNo
    21,                  // colNo
    "",                  // aName
    "addSegmentToStart", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtBCInfo gd_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    74,                // lineNo
    1,                 // colNo
    "",                // aName
    "addSegmentToEnd", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m", // pName
    0                                           // checkKind
};

static emlrtRTEInfo
    ge_emlrtRTEI{
        218,      // lineNo
        20,       // colNo
        "mtimes", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pName
    };

static emlrtRTEInfo he_emlrtRTEI{
    41,                             // lineNo
    1,                              // colNo
    "addFlatSegmentsToPPFormParts", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtRTEInfo ie_emlrtRTEI{
    46,                             // lineNo
    1,                              // colNo
    "addFlatSegmentsToPPFormParts", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtRTEInfo je_emlrtRTEI{
    64,                             // lineNo
    14,                             // colNo
    "addFlatSegmentsToPPFormParts", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtRTEInfo ke_emlrtRTEI{
    64,                             // lineNo
    1,                              // colNo
    "addFlatSegmentsToPPFormParts", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtRTEInfo le_emlrtRTEI{
    72,                             // lineNo
    1,                              // colNo
    "addFlatSegmentsToPPFormParts", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

static emlrtRTEInfo me_emlrtRTEI{
    77,                             // lineNo
    1,                              // colNo
    "addFlatSegmentsToPPFormParts", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
namespace robotics {
namespace core {
namespace internal {
void addFlatSegmentsToPPFormParts(const emlrtStack &sp,
                                  const ::coder::array<real_T, 2U> &oldbreaks,
                                  const ::coder::array<real_T, 2U> &oldCoeffs,
                                  real_T dim,
                                  ::coder::array<real_T, 2U> &newBreaks,
                                  ::coder::array<real_T, 2U> &newCoefs)
{
  static const real_T B[3]{0.0, 0.0, 1.0};
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ::coder::array<real_T, 2U> a;
  ::coder::array<real_T, 2U> breaksWithFlatStart;
  ::coder::array<real_T, 2U> coefsWithFlatStart;
  ::coder::array<real_T, 1U> valueAtEnd;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T newSegmentCoeffs_data[9];
  real_T valueAtStart_data[3];
  real_T alpha1;
  real_T beta1;
  real_T holdPoint_tmp;
  int32_T b_dim[2];
  int32_T newSegmentCoeffs_size[2];
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T b;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &rg_emlrtRSI;
  if (oldCoeffs.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, oldCoeffs.size(0), &rc_emlrtBCI, &st);
  }
  loop_ub_tmp = static_cast<int32_T>(dim);
  if ((static_cast<int32_T>(dim) < 1) ||
      (static_cast<int32_T>(dim) > oldCoeffs.size(0))) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(dim), 1,
                                  oldCoeffs.size(0), &qc_emlrtBCI, &st);
  }
  b_st.site = &tg_emlrtRSI;
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      newSegmentCoeffs_data[i1 + static_cast<int32_T>(dim) * i] =
          oldCoeffs[i1 + oldCoeffs.size(0) * i];
    }
  }
  c_st.site = &ug_emlrtRSI;
  d_st.site = &vg_emlrtRSI;
  TRANSB1 = 'T';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t) static_cast<int32_T>(dim);
  n_t = (ptrdiff_t)1;
  k_t = (ptrdiff_t)3;
  lda_t = (ptrdiff_t) static_cast<int32_T>(dim);
  ldb_t = (ptrdiff_t)1;
  ldc_t = (ptrdiff_t) static_cast<int32_T>(dim);
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
        &newSegmentCoeffs_data[0], &lda_t, (real_T *)&B[0], &ldb_t, &beta1,
        &valueAtStart_data[0], &ldc_t);
  b_st.site = &sg_emlrtRSI;
  newSegmentCoeffs_size[0] = static_cast<int32_T>(dim);
  newSegmentCoeffs_size[1] = 3;
  b_loop_ub_tmp = static_cast<int32_T>(dim) * 3;
  if (b_loop_ub_tmp - 1 >= 0) {
    std::memset(&newSegmentCoeffs_data[0], 0,
                static_cast<uint32_T>(b_loop_ub_tmp) * sizeof(real_T));
  }
  emlrtSubAssignSizeCheckR2012b(&loop_ub_tmp, 1, &loop_ub_tmp, 1, &v_emlrtECI,
                                &b_st);
  for (i = 0; i < loop_ub_tmp; i++) {
    newSegmentCoeffs_data[i + static_cast<int32_T>(dim) * 2] =
        valueAtStart_data[i];
  }
  alpha1 = static_cast<real_T>(oldCoeffs.size(0)) + dim;
  i = static_cast<int32_T>(muDoubleScalarFloor(alpha1));
  if (alpha1 != i) {
    emlrtIntegerCheckR2012b(alpha1, &t_emlrtDCI, &st);
  }
  i1 = static_cast<int32_T>(alpha1);
  coefsWithFlatStart.set_size(&he_emlrtRTEI, &st, i1, 3);
  if (i1 != i) {
    emlrtIntegerCheckR2012b(alpha1, &v_emlrtDCI, &st);
  }
  loop_ub = i1 * 3;
  for (i = 0; i < loop_ub; i++) {
    coefsWithFlatStart[i] = 0.0;
  }
  if ((static_cast<int32_T>(dim) < 1) || (static_cast<int32_T>(dim) > i1)) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(dim), 1,
                                  static_cast<int32_T>(alpha1), &pc_emlrtBCI,
                                  &st);
  }
  b_dim[0] = static_cast<int32_T>(dim);
  b_dim[1] = 3;
  emlrtSubAssignSizeCheckR2012b(&b_dim[0], 2, &newSegmentCoeffs_size[0], 2,
                                &s_emlrtECI, &st);
  for (i = 0; i < 3; i++) {
    for (int32_T i2{0}; i2 < loop_ub_tmp; i2++) {
      coefsWithFlatStart[i2 + coefsWithFlatStart.size(0) * i] =
          newSegmentCoeffs_data[i2 + static_cast<int32_T>(dim) * i];
    }
  }
  if (dim + 1.0 > alpha1) {
    i = 0;
    i1 = 0;
  } else {
    if ((static_cast<int32_T>(dim + 1.0) < 1) ||
        (static_cast<int32_T>(dim + 1.0) > coefsWithFlatStart.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(dim + 1.0), 1,
                                    coefsWithFlatStart.size(0), &oc_emlrtBCI,
                                    &st);
    }
    i = static_cast<int32_T>(dim + 1.0) - 1;
    if ((alpha1 < 1.0) || (i1 > coefsWithFlatStart.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(alpha1), 1,
                                    coefsWithFlatStart.size(0), &nc_emlrtBCI,
                                    &st);
    }
  }
  loop_ub = i1 - i;
  b_dim[0] = loop_ub;
  b_dim[1] = 3;
  emlrtSubAssignSizeCheckR2012b(
      &b_dim[0], 2, ((::coder::array<real_T, 2U> *)&oldCoeffs)->size(), 2,
      &r_emlrtECI, &st);
  for (i1 = 0; i1 < 3; i1++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      coefsWithFlatStart[(i + i2) + coefsWithFlatStart.size(0) * i1] =
          oldCoeffs[i2 + oldCoeffs.size(0) * i1];
    }
  }
  breaksWithFlatStart.set_size(&ie_emlrtRTEI, &st, 1, oldbreaks.size(1) + 1);
  breaksWithFlatStart[0] = oldbreaks[0] - 1.0;
  loop_ub = oldbreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    breaksWithFlatStart[i + 1] = oldbreaks[i];
  }
  st.site = &ub_emlrtRSI;
  b = (breaksWithFlatStart.size(1) < 1);
  if (b) {
    emlrtDynamicBoundsCheckR2012b(breaksWithFlatStart.size(1), 1,
                                  breaksWithFlatStart.size(1), &xc_emlrtBCI,
                                  &st);
  }
  if ((breaksWithFlatStart.size(1) - 1 < 1) ||
      (breaksWithFlatStart.size(1) - 1 > breaksWithFlatStart.size(1))) {
    emlrtDynamicBoundsCheckR2012b(breaksWithFlatStart.size(1) - 1, 1,
                                  breaksWithFlatStart.size(1), &yc_emlrtBCI,
                                  &st);
  }
  holdPoint_tmp = breaksWithFlatStart[breaksWithFlatStart.size(1) - 1];
  alpha1 = holdPoint_tmp - breaksWithFlatStart[breaksWithFlatStart.size(1) - 2];
  b_st.site = &vb_emlrtRSI;
  valueAtStart_data[0] = mpower(b_st, alpha1, 2.0);
  b_st.site = &vb_emlrtRSI;
  valueAtStart_data[1] = mpower(b_st, alpha1, 1.0);
  b_st.site = &vb_emlrtRSI;
  valueAtStart_data[2] = mpower(b_st, alpha1, 0.0);
  alpha1 = (static_cast<real_T>(coefsWithFlatStart.size(0)) - dim) + 1.0;
  if (alpha1 > coefsWithFlatStart.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    if ((static_cast<int32_T>(alpha1) < 1) ||
        (static_cast<int32_T>(alpha1) > coefsWithFlatStart.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(alpha1), 1,
                                    coefsWithFlatStart.size(0), &wc_emlrtBCI,
                                    &st);
    }
    i = static_cast<int32_T>(alpha1) - 1;
    if (coefsWithFlatStart.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0), 1,
                                    coefsWithFlatStart.size(0), &vc_emlrtBCI,
                                    &st);
    }
    i1 = coefsWithFlatStart.size(0);
  }
  b_st.site = &yg_emlrtRSI;
  loop_ub = i1 - i;
  a.set_size(&je_emlrtRTEI, &b_st, loop_ub, 3);
  for (i1 = 0; i1 < 3; i1++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      a[i2 + a.size(0) * i1] =
          coefsWithFlatStart[(i + i2) + coefsWithFlatStart.size(0) * i1];
    }
  }
  c_st.site = &ug_emlrtRSI;
  if (loop_ub == 0) {
    valueAtEnd.set_size(&ke_emlrtRTEI, &c_st, 0);
  } else {
    d_st.site = &vg_emlrtRSI;
    e_st.site = &wg_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)loop_ub;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)3;
    lda_t = (ptrdiff_t)loop_ub;
    ldb_t = (ptrdiff_t)3;
    ldc_t = (ptrdiff_t)loop_ub;
    valueAtEnd.set_size(&ge_emlrtRTEI, &e_st, loop_ub);
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(a.data())[0], &lda_t,
          &valueAtStart_data[0], &ldb_t, &beta1, &(valueAtEnd.data())[0],
          &ldc_t);
  }
  b_st.site = &xg_emlrtRSI;
  newSegmentCoeffs_size[0] = static_cast<int32_T>(dim);
  newSegmentCoeffs_size[1] = 3;
  if (b_loop_ub_tmp - 1 >= 0) {
    std::memset(&newSegmentCoeffs_data[0], 0,
                static_cast<uint32_T>(b_loop_ub_tmp) * sizeof(real_T));
  }
  emlrtSubAssignSizeCheckR2012b(&loop_ub_tmp, 1, valueAtEnd.size(), 1,
                                &v_emlrtECI, &b_st);
  for (i = 0; i < loop_ub_tmp; i++) {
    newSegmentCoeffs_data[i + static_cast<int32_T>(dim) * 2] = valueAtEnd[i];
  }
  alpha1 = static_cast<real_T>(coefsWithFlatStart.size(0)) + dim;
  i = static_cast<int32_T>(muDoubleScalarFloor(alpha1));
  if (alpha1 != i) {
    emlrtIntegerCheckR2012b(alpha1, &u_emlrtDCI, &st);
  }
  i1 = static_cast<int32_T>(alpha1);
  newCoefs.set_size(&le_emlrtRTEI, &st, i1, 3);
  if (i1 != i) {
    emlrtIntegerCheckR2012b(alpha1, &w_emlrtDCI, &st);
  }
  loop_ub = i1 * 3;
  for (i = 0; i < loop_ub; i++) {
    newCoefs[i] = 0.0;
  }
  if ((coefsWithFlatStart.size(0) < 1) || (coefsWithFlatStart.size(0) > i1)) {
    emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0), 1,
                                  static_cast<int32_T>(alpha1), &uc_emlrtBCI,
                                  &st);
  }
  b_dim[0] = coefsWithFlatStart.size(0);
  b_dim[1] = 3;
  emlrtSubAssignSizeCheckR2012b(&b_dim[0], 2, coefsWithFlatStart.size(), 2,
                                &u_emlrtECI, &st);
  loop_ub = coefsWithFlatStart.size(0);
  for (i = 0; i < 3; i++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      newCoefs[i2 + newCoefs.size(0) * i] =
          coefsWithFlatStart[i2 + coefsWithFlatStart.size(0) * i];
    }
  }
  if (static_cast<real_T>(coefsWithFlatStart.size(0)) + 1.0 > alpha1) {
    i = 0;
    i1 = 0;
  } else {
    if ((static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U) < 1) ||
        (static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U) >
         newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(
              static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U),
          1, newCoefs.size(0), &tc_emlrtBCI, &st);
    }
    i = coefsWithFlatStart.size(0);
    if ((alpha1 < 1.0) || (i1 > newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(alpha1), 1,
                                    newCoefs.size(0), &sc_emlrtBCI, &st);
    }
  }
  loop_ub = i1 - i;
  b_dim[0] = loop_ub;
  b_dim[1] = 3;
  emlrtSubAssignSizeCheckR2012b(&b_dim[0], 2, &newSegmentCoeffs_size[0], 2,
                                &t_emlrtECI, &st);
  for (i1 = 0; i1 < 3; i1++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      newCoefs[(i + i2) + newCoefs.size(0) * i1] =
          newSegmentCoeffs_data[i2 + static_cast<int32_T>(dim) * i1];
    }
  }
  newBreaks.set_size(&me_emlrtRTEI, &st, 1, breaksWithFlatStart.size(1) + 1);
  loop_ub = breaksWithFlatStart.size(1);
  for (i = 0; i < loop_ub; i++) {
    newBreaks[i] = breaksWithFlatStart[i];
  }
  newBreaks[breaksWithFlatStart.size(1)] = holdPoint_tmp + 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void addFlatSegmentsToPPFormParts(const emlrtStack &sp,
                                  const ::coder::array<real_T, 2U> &oldbreaks,
                                  const ::coder::array<real_T, 2U> &oldCoeffs,
                                  ::coder::array<real_T, 2U> &newBreaks,
                                  ::coder::array<real_T, 2U> &newCoefs)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ::coder::array<real_T, 2U> a;
  ::coder::array<real_T, 2U> breaksWithFlatStart;
  ::coder::array<real_T, 2U> coefsWithFlatStart;
  ::coder::array<real_T, 1U> valueAtEnd;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T newSegmentCoeffs[12];
  real_T evalPointVector[4];
  real_T beta1;
  real_T holdPoint;
  real_T holdPoint_tmp;
  int32_T b_coefsWithFlatStart[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T b;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &rg_emlrtRSI;
  if (oldCoeffs.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, oldCoeffs.size(0), &rc_emlrtBCI, &st);
  }
  if (oldCoeffs.size(0) < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, oldCoeffs.size(0), &rc_emlrtBCI, &st);
  }
  if (oldCoeffs.size(0) < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, oldCoeffs.size(0), &rc_emlrtBCI, &st);
  }
  std::memset(&newSegmentCoeffs[0], 0, 12U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    newSegmentCoeffs[i + 9] =
        ((oldCoeffs[i] * 0.0 + oldCoeffs[i + oldCoeffs.size(0)] * 0.0) +
         oldCoeffs[i + oldCoeffs.size(0) * 2] * 0.0) +
        oldCoeffs[i + oldCoeffs.size(0) * 3];
  }
  if (static_cast<real_T>(oldCoeffs.size(0)) + 3.0 != oldCoeffs.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(oldCoeffs.size(0)) + 3.0,
                            &t_emlrtDCI, &st);
  }
  coefsWithFlatStart.set_size(&he_emlrtRTEI, &st, oldCoeffs.size(0) + 3, 4);
  if (static_cast<real_T>(oldCoeffs.size(0)) + 3.0 != oldCoeffs.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(oldCoeffs.size(0)) + 3.0,
                            &v_emlrtDCI, &st);
  }
  loop_ub = (oldCoeffs.size(0) + 3) << 2;
  for (i = 0; i < loop_ub; i++) {
    coefsWithFlatStart[i] = 0.0;
  }
  for (i = 0; i < 4; i++) {
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i] =
        newSegmentCoeffs[3 * i];
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i + 1] =
        newSegmentCoeffs[3 * i + 1];
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i + 2] =
        newSegmentCoeffs[3 * i + 2];
  }
  if (static_cast<uint32_T>(oldCoeffs.size(0)) + 3U < 4U) {
    i = 0;
    i1 = 0;
  } else {
    if (coefsWithFlatStart.size(0) < 4) {
      emlrtDynamicBoundsCheckR2012b(4, 1, coefsWithFlatStart.size(0),
                                    &oc_emlrtBCI, &st);
    }
    i = 3;
    if ((static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U) <
         1) ||
        (static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U) >
         coefsWithFlatStart.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U),
          1, coefsWithFlatStart.size(0), &nc_emlrtBCI, &st);
    }
    i1 = static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U);
  }
  loop_ub = i1 - i;
  b_coefsWithFlatStart[0] = loop_ub;
  b_coefsWithFlatStart[1] = 4;
  emlrtSubAssignSizeCheckR2012b(
      &b_coefsWithFlatStart[0], 2,
      ((::coder::array<real_T, 2U> *)&oldCoeffs)->size(), 2, &r_emlrtECI, &st);
  for (i1 = 0; i1 < 4; i1++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      coefsWithFlatStart[(i + i2) + coefsWithFlatStart.size(0) * i1] =
          oldCoeffs[i2 + oldCoeffs.size(0) * i1];
    }
  }
  if (oldbreaks.size(1) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, oldbreaks.size(1), &fd_emlrtBCI, &st);
  }
  breaksWithFlatStart.set_size(&ie_emlrtRTEI, &st, 1, oldbreaks.size(1) + 1);
  breaksWithFlatStart[0] = oldbreaks[0] - 1.0;
  loop_ub = oldbreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    breaksWithFlatStart[i + 1] = oldbreaks[i];
  }
  st.site = &ub_emlrtRSI;
  b = (breaksWithFlatStart.size(1) < 1);
  if (b) {
    emlrtDynamicBoundsCheckR2012b(breaksWithFlatStart.size(1), 1,
                                  breaksWithFlatStart.size(1), &xc_emlrtBCI,
                                  &st);
  }
  if ((breaksWithFlatStart.size(1) - 1 < 1) ||
      (breaksWithFlatStart.size(1) - 1 > breaksWithFlatStart.size(1))) {
    emlrtDynamicBoundsCheckR2012b(breaksWithFlatStart.size(1) - 1, 1,
                                  breaksWithFlatStart.size(1), &yc_emlrtBCI,
                                  &st);
  }
  holdPoint_tmp = breaksWithFlatStart[breaksWithFlatStart.size(1) - 1];
  holdPoint =
      holdPoint_tmp - breaksWithFlatStart[breaksWithFlatStart.size(1) - 2];
  b_st.site = &vb_emlrtRSI;
  evalPointVector[0] = mpower(b_st, holdPoint, 3.0);
  b_st.site = &vb_emlrtRSI;
  evalPointVector[1] = mpower(b_st, holdPoint, 2.0);
  b_st.site = &vb_emlrtRSI;
  evalPointVector[2] = mpower(b_st, holdPoint, 1.0);
  b_st.site = &vb_emlrtRSI;
  evalPointVector[3] = mpower(b_st, holdPoint, 0.0);
  if (coefsWithFlatStart.size(0) - 2 > coefsWithFlatStart.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    if ((coefsWithFlatStart.size(0) - 2 < 1) ||
        (coefsWithFlatStart.size(0) - 2 > coefsWithFlatStart.size(0))) {
      emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0) - 2, 1,
                                    coefsWithFlatStart.size(0), &wc_emlrtBCI,
                                    &st);
    }
    i = coefsWithFlatStart.size(0) - 3;
    if (coefsWithFlatStart.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0), 1,
                                    coefsWithFlatStart.size(0), &vc_emlrtBCI,
                                    &st);
    }
    i1 = coefsWithFlatStart.size(0);
  }
  b_st.site = &yg_emlrtRSI;
  loop_ub = i1 - i;
  a.set_size(&je_emlrtRTEI, &b_st, loop_ub, 4);
  for (i1 = 0; i1 < 4; i1++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      a[i2 + a.size(0) * i1] =
          coefsWithFlatStart[(i + i2) + coefsWithFlatStart.size(0) * i1];
    }
  }
  c_st.site = &ug_emlrtRSI;
  if (loop_ub == 0) {
    valueAtEnd.set_size(&ke_emlrtRTEI, &c_st, 0);
  } else {
    d_st.site = &vg_emlrtRSI;
    e_st.site = &wg_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    holdPoint = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)loop_ub;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)4;
    lda_t = (ptrdiff_t)loop_ub;
    ldb_t = (ptrdiff_t)4;
    ldc_t = (ptrdiff_t)loop_ub;
    valueAtEnd.set_size(&ge_emlrtRTEI, &e_st, loop_ub);
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &holdPoint, &(a.data())[0],
          &lda_t, &evalPointVector[0], &ldb_t, &beta1, &(valueAtEnd.data())[0],
          &ldc_t);
  }
  b_st.site = &xg_emlrtRSI;
  std::memset(&newSegmentCoeffs[0], 0, 12U * sizeof(real_T));
  loop_ub = 3;
  emlrtSubAssignSizeCheckR2012b(&loop_ub, 1, valueAtEnd.size(), 1, &v_emlrtECI,
                                &b_st);
  newSegmentCoeffs[9] = valueAtEnd[0];
  newSegmentCoeffs[10] = valueAtEnd[1];
  newSegmentCoeffs[11] = valueAtEnd[2];
  if (static_cast<real_T>(coefsWithFlatStart.size(0)) + 3.0 !=
      coefsWithFlatStart.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(coefsWithFlatStart.size(0)) +
                                3.0,
                            &u_emlrtDCI, &st);
  }
  newCoefs.set_size(&le_emlrtRTEI, &st, coefsWithFlatStart.size(0) + 3, 4);
  if (static_cast<real_T>(coefsWithFlatStart.size(0)) + 3.0 !=
      coefsWithFlatStart.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(coefsWithFlatStart.size(0)) +
                                3.0,
                            &w_emlrtDCI, &st);
  }
  loop_ub = (coefsWithFlatStart.size(0) + 3) << 2;
  for (i = 0; i < loop_ub; i++) {
    newCoefs[i] = 0.0;
  }
  if ((coefsWithFlatStart.size(0) < 1) ||
      (coefsWithFlatStart.size(0) > coefsWithFlatStart.size(0) + 3)) {
    emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0), 1,
                                  coefsWithFlatStart.size(0) + 3, &uc_emlrtBCI,
                                  &st);
  }
  b_coefsWithFlatStart[0] = coefsWithFlatStart.size(0);
  b_coefsWithFlatStart[1] = 4;
  emlrtSubAssignSizeCheckR2012b(&b_coefsWithFlatStart[0], 2,
                                coefsWithFlatStart.size(), 2, &u_emlrtECI, &st);
  loop_ub = coefsWithFlatStart.size(0);
  for (i = 0; i < 4; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      newCoefs[i1 + newCoefs.size(0) * i] =
          coefsWithFlatStart[i1 + coefsWithFlatStart.size(0) * i];
    }
  }
  for (i = 0; i < 4; i++) {
    if ((static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U) < 1) ||
        (static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U) >
         newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(
              static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U),
          1, newCoefs.size(0), &gd_emlrtBCI, &st);
    }
    newCoefs[coefsWithFlatStart.size(0) + newCoefs.size(0) * i] =
        newSegmentCoeffs[3 * i];
    if ((static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 2U) < 1) ||
        (static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 2U) >
         newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(
              static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 2U),
          1, newCoefs.size(0), &gd_emlrtBCI, &st);
    }
    newCoefs[(coefsWithFlatStart.size(0) + newCoefs.size(0) * i) + 1] =
        newSegmentCoeffs[3 * i + 1];
    if ((static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 3U) < 1) ||
        (static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 3U) >
         newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(
              static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 3U),
          1, newCoefs.size(0), &gd_emlrtBCI, &st);
    }
    newCoefs[(coefsWithFlatStart.size(0) + newCoefs.size(0) * i) + 2] =
        newSegmentCoeffs[3 * i + 2];
  }
  newBreaks.set_size(&me_emlrtRTEI, &st, 1, breaksWithFlatStart.size(1) + 1);
  loop_ub = breaksWithFlatStart.size(1);
  for (i = 0; i < loop_ub; i++) {
    newBreaks[i] = breaksWithFlatStart[i];
  }
  newBreaks[breaksWithFlatStart.size(1)] = holdPoint_tmp + 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void b_addFlatSegmentsToPPFormParts(const emlrtStack &sp,
                                    const ::coder::array<real_T, 2U> &oldbreaks,
                                    const ::coder::array<real_T, 2U> &oldCoeffs,
                                    ::coder::array<real_T, 2U> &newBreaks,
                                    ::coder::array<real_T, 2U> &newCoefs)
{
  static const int8_T iv[6]{0, 0, 0, 0, 0, 1};
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ::coder::array<real_T, 2U> a;
  ::coder::array<real_T, 2U> breaksWithFlatStart;
  ::coder::array<real_T, 2U> coefsWithFlatStart;
  ::coder::array<real_T, 1U> valueAtEnd;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T newSegmentCoeffs[18];
  real_T evalPointVector[6];
  real_T beta1;
  real_T holdPoint;
  real_T holdPoint_tmp;
  int32_T b_coefsWithFlatStart[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T b;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &rg_emlrtRSI;
  if (oldCoeffs.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, oldCoeffs.size(0), &rc_emlrtBCI, &st);
  }
  if (oldCoeffs.size(0) < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, oldCoeffs.size(0), &rc_emlrtBCI, &st);
  }
  if (oldCoeffs.size(0) < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, oldCoeffs.size(0), &rc_emlrtBCI, &st);
  }
  std::memset(&newSegmentCoeffs[0], 0, 18U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    holdPoint = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      holdPoint +=
          oldCoeffs[i + oldCoeffs.size(0) * i1] * static_cast<real_T>(iv[i1]);
    }
    newSegmentCoeffs[i + 15] = holdPoint;
  }
  if (static_cast<real_T>(oldCoeffs.size(0)) + 3.0 != oldCoeffs.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(oldCoeffs.size(0)) + 3.0,
                            &t_emlrtDCI, &st);
  }
  coefsWithFlatStart.set_size(&he_emlrtRTEI, &st, oldCoeffs.size(0) + 3, 6);
  if (static_cast<real_T>(oldCoeffs.size(0)) + 3.0 != oldCoeffs.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(oldCoeffs.size(0)) + 3.0,
                            &v_emlrtDCI, &st);
  }
  loop_ub = (oldCoeffs.size(0) + 3) * 6;
  for (i = 0; i < loop_ub; i++) {
    coefsWithFlatStart[i] = 0.0;
  }
  for (i = 0; i < 6; i++) {
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i] =
        newSegmentCoeffs[3 * i];
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i + 1] =
        newSegmentCoeffs[3 * i + 1];
    coefsWithFlatStart[coefsWithFlatStart.size(0) * i + 2] =
        newSegmentCoeffs[3 * i + 2];
  }
  if (static_cast<uint32_T>(oldCoeffs.size(0)) + 3U < 4U) {
    i = 0;
    i1 = 0;
  } else {
    if (coefsWithFlatStart.size(0) < 4) {
      emlrtDynamicBoundsCheckR2012b(4, 1, coefsWithFlatStart.size(0),
                                    &oc_emlrtBCI, &st);
    }
    i = 3;
    if ((static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U) <
         1) ||
        (static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U) >
         coefsWithFlatStart.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U),
          1, coefsWithFlatStart.size(0), &nc_emlrtBCI, &st);
    }
    i1 = static_cast<int32_T>(static_cast<uint32_T>(oldCoeffs.size(0)) + 3U);
  }
  loop_ub = i1 - i;
  b_coefsWithFlatStart[0] = loop_ub;
  b_coefsWithFlatStart[1] = 6;
  emlrtSubAssignSizeCheckR2012b(
      &b_coefsWithFlatStart[0], 2,
      ((::coder::array<real_T, 2U> *)&oldCoeffs)->size(), 2, &r_emlrtECI, &st);
  for (i1 = 0; i1 < 6; i1++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      coefsWithFlatStart[(i + i2) + coefsWithFlatStart.size(0) * i1] =
          oldCoeffs[i2 + oldCoeffs.size(0) * i1];
    }
  }
  if (oldbreaks.size(1) < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, oldbreaks.size(1), &fd_emlrtBCI, &st);
  }
  breaksWithFlatStart.set_size(&ie_emlrtRTEI, &st, 1, oldbreaks.size(1) + 1);
  breaksWithFlatStart[0] = oldbreaks[0] - 1.0;
  loop_ub = oldbreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    breaksWithFlatStart[i + 1] = oldbreaks[i];
  }
  st.site = &ub_emlrtRSI;
  b = (breaksWithFlatStart.size(1) < 1);
  if (b) {
    emlrtDynamicBoundsCheckR2012b(breaksWithFlatStart.size(1), 1,
                                  breaksWithFlatStart.size(1), &xc_emlrtBCI,
                                  &st);
  }
  if ((breaksWithFlatStart.size(1) - 1 < 1) ||
      (breaksWithFlatStart.size(1) - 1 > breaksWithFlatStart.size(1))) {
    emlrtDynamicBoundsCheckR2012b(breaksWithFlatStart.size(1) - 1, 1,
                                  breaksWithFlatStart.size(1), &yc_emlrtBCI,
                                  &st);
  }
  holdPoint_tmp = breaksWithFlatStart[breaksWithFlatStart.size(1) - 1];
  holdPoint =
      holdPoint_tmp - breaksWithFlatStart[breaksWithFlatStart.size(1) - 2];
  for (loop_ub = 0; loop_ub < 6; loop_ub++) {
    b_st.site = &vb_emlrtRSI;
    evalPointVector[loop_ub] =
        mpower(b_st, holdPoint, 6.0 - (static_cast<real_T>(loop_ub) + 1.0));
  }
  if (coefsWithFlatStart.size(0) - 2 > coefsWithFlatStart.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    if ((coefsWithFlatStart.size(0) - 2 < 1) ||
        (coefsWithFlatStart.size(0) - 2 > coefsWithFlatStart.size(0))) {
      emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0) - 2, 1,
                                    coefsWithFlatStart.size(0), &wc_emlrtBCI,
                                    &st);
    }
    i = coefsWithFlatStart.size(0) - 3;
    if (coefsWithFlatStart.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0), 1,
                                    coefsWithFlatStart.size(0), &vc_emlrtBCI,
                                    &st);
    }
    i1 = coefsWithFlatStart.size(0);
  }
  b_st.site = &yg_emlrtRSI;
  loop_ub = i1 - i;
  a.set_size(&je_emlrtRTEI, &b_st, loop_ub, 6);
  for (i1 = 0; i1 < 6; i1++) {
    for (int32_T i2{0}; i2 < loop_ub; i2++) {
      a[i2 + a.size(0) * i1] =
          coefsWithFlatStart[(i + i2) + coefsWithFlatStart.size(0) * i1];
    }
  }
  c_st.site = &ug_emlrtRSI;
  if (loop_ub == 0) {
    valueAtEnd.set_size(&ke_emlrtRTEI, &c_st, 0);
  } else {
    d_st.site = &vg_emlrtRSI;
    e_st.site = &wg_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    holdPoint = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)loop_ub;
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)loop_ub;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)loop_ub;
    valueAtEnd.set_size(&ge_emlrtRTEI, &e_st, loop_ub);
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &holdPoint, &(a.data())[0],
          &lda_t, &evalPointVector[0], &ldb_t, &beta1, &(valueAtEnd.data())[0],
          &ldc_t);
  }
  b_st.site = &xg_emlrtRSI;
  std::memset(&newSegmentCoeffs[0], 0, 18U * sizeof(real_T));
  loop_ub = 3;
  emlrtSubAssignSizeCheckR2012b(&loop_ub, 1, valueAtEnd.size(), 1, &v_emlrtECI,
                                &b_st);
  newSegmentCoeffs[15] = valueAtEnd[0];
  newSegmentCoeffs[16] = valueAtEnd[1];
  newSegmentCoeffs[17] = valueAtEnd[2];
  if (static_cast<real_T>(coefsWithFlatStart.size(0)) + 3.0 !=
      coefsWithFlatStart.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(coefsWithFlatStart.size(0)) +
                                3.0,
                            &u_emlrtDCI, &st);
  }
  newCoefs.set_size(&le_emlrtRTEI, &st, coefsWithFlatStart.size(0) + 3, 6);
  if (static_cast<real_T>(coefsWithFlatStart.size(0)) + 3.0 !=
      coefsWithFlatStart.size(0) + 3) {
    emlrtIntegerCheckR2012b(static_cast<real_T>(coefsWithFlatStart.size(0)) +
                                3.0,
                            &w_emlrtDCI, &st);
  }
  loop_ub = (coefsWithFlatStart.size(0) + 3) * 6;
  for (i = 0; i < loop_ub; i++) {
    newCoefs[i] = 0.0;
  }
  if ((coefsWithFlatStart.size(0) < 1) ||
      (coefsWithFlatStart.size(0) > coefsWithFlatStart.size(0) + 3)) {
    emlrtDynamicBoundsCheckR2012b(coefsWithFlatStart.size(0), 1,
                                  coefsWithFlatStart.size(0) + 3, &uc_emlrtBCI,
                                  &st);
  }
  b_coefsWithFlatStart[0] = coefsWithFlatStart.size(0);
  b_coefsWithFlatStart[1] = 6;
  emlrtSubAssignSizeCheckR2012b(&b_coefsWithFlatStart[0], 2,
                                coefsWithFlatStart.size(), 2, &u_emlrtECI, &st);
  loop_ub = coefsWithFlatStart.size(0);
  for (i = 0; i < 6; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      newCoefs[i1 + newCoefs.size(0) * i] =
          coefsWithFlatStart[i1 + coefsWithFlatStart.size(0) * i];
    }
  }
  for (i = 0; i < 6; i++) {
    if ((static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U) < 1) ||
        (static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U) >
         newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(
              static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 1U),
          1, newCoefs.size(0), &gd_emlrtBCI, &st);
    }
    newCoefs[coefsWithFlatStart.size(0) + newCoefs.size(0) * i] =
        newSegmentCoeffs[3 * i];
    if ((static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 2U) < 1) ||
        (static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 2U) >
         newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(
              static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 2U),
          1, newCoefs.size(0), &gd_emlrtBCI, &st);
    }
    newCoefs[(coefsWithFlatStart.size(0) + newCoefs.size(0) * i) + 1] =
        newSegmentCoeffs[3 * i + 1];
    if ((static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 3U) < 1) ||
        (static_cast<int32_T>(
             static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 3U) >
         newCoefs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(
          static_cast<int32_T>(
              static_cast<uint32_T>(coefsWithFlatStart.size(0)) + 3U),
          1, newCoefs.size(0), &gd_emlrtBCI, &st);
    }
    newCoefs[(coefsWithFlatStart.size(0) + newCoefs.size(0) * i) + 2] =
        newSegmentCoeffs[3 * i + 2];
  }
  newBreaks.set_size(&me_emlrtRTEI, &st, 1, breaksWithFlatStart.size(1) + 1);
  loop_ub = breaksWithFlatStart.size(1);
  for (i = 0; i < loop_ub; i++) {
    newBreaks[i] = breaksWithFlatStart[i];
  }
  newBreaks[breaksWithFlatStart.size(1)] = holdPoint_tmp + 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (addFlatSegmentsToPPFormParts.cpp)
