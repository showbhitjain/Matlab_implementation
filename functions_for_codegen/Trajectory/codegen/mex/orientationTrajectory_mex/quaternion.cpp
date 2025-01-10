//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// quaternion.cpp
//
// Code generation for function 'quaternion'
//

// Include files
#include "quaternion.h"
#include "div.h"
#include "isequal.h"
#include "log.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"

// Type Definitions
namespace trajectoryGeneration {
namespace coder {
class c_quaternion {
public:
  ::coder::bounded_array<real_T, 1U, 2U> a;
  ::coder::bounded_array<real_T, 1U, 2U> b;
  ::coder::bounded_array<real_T, 1U, 2U> c;
  ::coder::bounded_array<real_T, 1U, 2U> d;
};

} // namespace coder
} // namespace trajectoryGeneration

// Variable Definitions
static emlrtRSInfo me_emlrtRSI{
    10,                         // lineNo
    "quaternionBase/normalize", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/normalize.m" // pathName
};

static emlrtRSInfo ne_emlrtRSI{
    29,                     // lineNo
    "quaternionBase/slerp", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/slerp.m" // pathName
};

static emlrtRSInfo oe_emlrtRSI{
    26,          // lineNo
    "privslerp", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/privslerp.m" // pathName
};

static emlrtRSInfo pe_emlrtRSI{
    27,          // lineNo
    "privslerp", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/privslerp.m" // pathName
};

static emlrtRSInfo qe_emlrtRSI{
    60,          // lineNo
    "privslerp", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/privslerp.m" // pathName
};

static emlrtRSInfo re_emlrtRSI{
    78,          // lineNo
    "privslerp", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/privslerp.m" // pathName
};

static emlrtRSInfo se_emlrtRSI{
    81,          // lineNo
    "privslerp", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/privslerp.m" // pathName
};

static emlrtRSInfo te_emlrtRSI{
    170,                           // lineNo
    "quaternioncg/parenReference", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m" // pathName
};

static emlrtRSInfo ue_emlrtRSI{
    16,          // lineNo
    "privslerp", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/privslerp.m" // pathName
};

static emlrtRSInfo we_emlrtRSI{
    18,                   // lineNo
    "quaternionBase/log", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pathName
};

static emlrtRSInfo xe_emlrtRSI{
    19,                   // lineNo
    "quaternionBase/log", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pathName
};

static emlrtRSInfo ye_emlrtRSI{
    24,                   // lineNo
    "quaternionBase/log", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pathName
};

static emlrtRSInfo af_emlrtRSI{
    26,                   // lineNo
    "quaternionBase/log", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pathName
};

static emlrtRSInfo hf_emlrtRSI{
    11,                       // lineNo
    "quaternionBase/compact", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/compact.m" // pathName
};

static emlrtRTEInfo x_emlrtRTEI{
    13,                                                            // lineNo
    9,                                                             // colNo
    "sqrt",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

static emlrtECInfo w_emlrtECI{
    -1,                         // nDims
    175,                        // lineNo
    13,                         // colNo
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m" // pName
};

static emlrtECInfo x_emlrtECI{
    -1,                         // nDims
    176,                        // lineNo
    13,                         // colNo
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m" // pName
};

static emlrtECInfo y_emlrtECI{
    -1,                         // nDims
    177,                        // lineNo
    13,                         // colNo
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m" // pName
};

static emlrtECInfo ab_emlrtECI{
    -1,                         // nDims
    178,                        // lineNo
    13,                         // colNo
    "quaternioncg/parenAssign", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m" // pName
};

static emlrtECInfo bb_emlrtECI{
    2,                    // nDims
    27,                   // lineNo
    9,                    // colNo
    "quaternionBase/log", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pName
};

static emlrtECInfo cb_emlrtECI{
    -1,                   // nDims
    27,                   // lineNo
    1,                    // colNo
    "quaternionBase/log", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pName
};

static emlrtECInfo db_emlrtECI{
    2,                    // nDims
    29,                   // lineNo
    9,                    // colNo
    "quaternionBase/log", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pName
};

static emlrtECInfo eb_emlrtECI{
    -1,                   // nDims
    29,                   // lineNo
    1,                    // colNo
    "quaternionBase/log", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pName
};

static emlrtECInfo fb_emlrtECI{
    2,                    // nDims
    31,                   // lineNo
    9,                    // colNo
    "quaternionBase/log", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pName
};

static emlrtECInfo gb_emlrtECI{
    -1,                   // nDims
    31,                   // lineNo
    1,                    // colNo
    "quaternionBase/log", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/log.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    14,                                                            // lineNo
    9,                                                             // colNo
    "acos",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/acos.m" // pName
};

static emlrtRTEInfo tc_emlrtRTEI{
    11,        // lineNo
    1,         // colNo
    "compact", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/compact.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void quaternion::init()
{
  a = 1.0;
  b = 0.0;
  c = 0.0;
  d = 0.0;
}

void quaternion::parenAssign(const emlrtStack &sp, const c_quaternion rhs)
{
  real_T b_d;
  if (rhs.a.size[1] != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, rhs.a.size[1], &w_emlrtECI,
                                    (emlrtConstCTX)&sp);
  }
  b_d = a;
  if (rhs.a.size[1] - 1 >= 0) {
    b_d = rhs.a.data[0];
  }
  a = b_d;
  if (rhs.b.size[1] != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, rhs.b.size[1], &x_emlrtECI,
                                    (emlrtConstCTX)&sp);
  }
  b_d = b;
  if (rhs.b.size[1] - 1 >= 0) {
    b_d = rhs.b.data[0];
  }
  b = b_d;
  if (rhs.c.size[1] != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, rhs.c.size[1], &y_emlrtECI,
                                    (emlrtConstCTX)&sp);
  }
  b_d = c;
  if (rhs.c.size[1] - 1 >= 0) {
    b_d = rhs.c.data[0];
  }
  c = b_d;
  if (rhs.d.size[1] != 1) {
    emlrtSubAssignSizeCheck1dR2017a(1, rhs.d.size[1], &ab_emlrtECI,
                                    (emlrtConstCTX)&sp);
  }
  b_d = d;
  if (rhs.d.size[1] - 1 >= 0) {
    b_d = rhs.d.data[0];
  }
  d = b_d;
}

void quaternion::parenReference(const emlrtStack &sp, c_quaternion &o) const
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T dv[2];
  real_T dv1[2];
  real_T dv2[2];
  real_T dv3[2];
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &te_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &je_emlrtRSI;
  c_st.site = &ke_emlrtRSI;
  d_st.site = &le_emlrtRSI;
  dv[0] = 1.0;
  dv[1] = 1.0;
  dv1[0] = 1.0;
  dv1[1] = 1.0;
  dv2[0] = 1.0;
  dv2[1] = 1.0;
  dv3[0] = 1.0;
  dv3[1] = 1.0;
  if (!isequal(dv, dv1, dv2, dv3)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &m_emlrtRTEI,
                                  "shared_rotations:quaternion:SameSize",
                                  "shared_rotations:quaternion:SameSize", 0);
  }
  o.a.size[0] = 1;
  o.a.size[1] = 1;
  o.a.data[0] = a;
  o.b.size[0] = 1;
  o.b.size[1] = 1;
  o.b.data[0] = b;
  o.c.size[0] = 1;
  o.c.size[1] = 1;
  o.c.data[0] = c;
  o.d.size[0] = 1;
  o.d.size[1] = 1;
  o.d.data[0] = d;
}

void quaternion::b_log(const emlrtStack &sp)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T qnorm;
  real_T tmp_data;
  real_T vnorm;
  real_T vscale_data;
  int32_T tmp_size[2];
  int32_T vscale_size[2];
  int32_T k;
  int32_T loop_ub;
  int32_T trueCount;
  int8_T size_tmp[2];
  boolean_T nz;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &we_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &we_emlrtRSI;
  st.site = &we_emlrtRSI;
  st.site = &we_emlrtRSI;
  vnorm = (b * b + c * c) + d * d;
  if (vnorm < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  vnorm = muDoubleScalarSqrt(vnorm);
  st.site = &xe_emlrtRSI;
  st.site = &xe_emlrtRSI;
  st.site = &xe_emlrtRSI;
  qnorm = a * a + vnorm * vnorm;
  if (qnorm < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  qnorm = muDoubleScalarSqrt(qnorm);
  nz = (vnorm != 0.0);
  st.site = &ye_emlrtRSI;
  vscale_size[0] = 1;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  vscale_size[1] = trueCount;
  if (nz) {
    vscale_data = a / qnorm;
  }
  st.site = &ye_emlrtRSI;
  b_st.site = &ye_emlrtRSI;
  p = false;
  for (k = 0; k < trueCount; k++) {
    if (p || ((vscale_data < -1.0) || (vscale_data > 1.0))) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &kb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "acos");
  }
  for (k = 0; k < trueCount; k++) {
    vscale_data = muDoubleScalarAcos(vscale_data);
  }
  k = 0;
  if (nz) {
    k = 1;
  }
  if (trueCount == k) {
    loop_ub = trueCount - 1;
    vscale_size[0] = 1;
    for (trueCount = 0; trueCount <= loop_ub; trueCount++) {
      vscale_data /= vnorm;
    }
  } else {
    binary_expand_op_3((real_T *)&vscale_data, vscale_size, vnorm, k);
  }
  st.site = &af_emlrtRSI;
  a = muDoubleScalarLog(qnorm);
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = static_cast<int8_T>(trueCount);
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &bb_emlrtECI, (emlrtConstCTX)&sp);
  }
  k = 0;
  if (nz) {
    k = 1;
  }
  if (trueCount == vscale_size[1]) {
    tmp_size[0] = 1;
    tmp_size[1] = trueCount;
    if (vscale_size[1] - 1 >= 0) {
      tmp_data = b * vscale_data;
    }
  } else {
    binary_expand_op_2((real_T *)&tmp_data, tmp_size, this, size_tmp,
                       (const real_T *)&vscale_data, vscale_size);
  }
  if (k != tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(k, tmp_size[1], &cb_emlrtECI,
                                    (emlrtConstCTX)&sp);
  }
  vnorm = b;
  if (tmp_size[1] - 1 >= 0) {
    vnorm = tmp_data;
  }
  p = !nz;
  if (p) {
    vnorm = 0.0;
  }
  b = vnorm;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = static_cast<int8_T>(trueCount);
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &db_emlrtECI, (emlrtConstCTX)&sp);
  }
  k = 0;
  if (nz) {
    k = 1;
  }
  if (trueCount == vscale_size[1]) {
    tmp_size[1] = trueCount;
    if (vscale_size[1] - 1 >= 0) {
      tmp_data = c * vscale_data;
    }
  } else {
    binary_expand_op_1((real_T *)&tmp_data, tmp_size, this, size_tmp,
                       (const real_T *)&vscale_data, vscale_size);
  }
  if (k != tmp_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(k, tmp_size[1], &eb_emlrtECI,
                                    (emlrtConstCTX)&sp);
  }
  vnorm = c;
  if (tmp_size[1] - 1 >= 0) {
    vnorm = tmp_data;
  }
  if (p) {
    vnorm = 0.0;
  }
  c = vnorm;
  trueCount = 0;
  if (nz) {
    trueCount = 1;
  }
  size_tmp[0] = 1;
  size_tmp[1] = static_cast<int8_T>(trueCount);
  if ((trueCount != vscale_size[1]) &&
      ((trueCount != 1) && (vscale_size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(0, 0, &fb_emlrtECI, (emlrtConstCTX)&sp);
  }
  k = 0;
  if (nz) {
    k = 1;
  }
  if (trueCount == vscale_size[1]) {
    loop_ub = vscale_size[1] - 1;
    vscale_size[1] = trueCount;
    for (trueCount = 0; trueCount <= loop_ub; trueCount++) {
      vscale_data *= d;
    }
  } else {
    binary_expand_op((real_T *)&vscale_data, vscale_size, this, size_tmp);
  }
  if (k != vscale_size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(k, vscale_size[1], &gb_emlrtECI,
                                    (emlrtConstCTX)&sp);
  }
  vnorm = d;
  if (vscale_size[1] - 1 >= 0) {
    vnorm = vscale_data;
  }
  if (p) {
    vnorm = 0.0;
  }
  d = vnorm;
}

void b_quaternion::compact(const emlrtStack &sp,
                           ::coder::array<real_T, 2U> &m) const
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T loop_ub;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &hf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ed_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  if (b.size(0) != a.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (c.size(0) != a.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (d.size(0) != a.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  m.set_size(&tc_emlrtRTEI, &b_st, a.size(0), 4);
  loop_ub = a.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    m[i] = a[i];
  }
  loop_ub = b.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    m[i + m.size(0)] = b[i];
  }
  loop_ub = c.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    m[i + m.size(0) * 2] = c[i];
  }
  loop_ub = d.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    m[i + m.size(0) * 3] = d[i];
  }
}

void quaternion::normalize(const emlrtStack &sp)
{
  emlrtStack st;
  real_T n;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &me_emlrtRSI;
  n = ((a * a + b * b) + c * c) + d * d;
  if (n < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  n = muDoubleScalarSqrt(n);
  a /= n;
  b /= n;
  c /= n;
  d /= n;
}

quaternion quaternion::quaternionBase_slerp(const emlrtStack &sp,
                                            const quaternion q2) const
{
  c_quaternion r;
  quaternion q1n;
  quaternion q1n_tmp;
  quaternion q2n;
  quaternion qo;
  quaternion replaceval;
  quaternion x;
  emlrtStack b_st;
  emlrtStack st;
  real_T dp;
  real_T sinv;
  real_T sinv_tmp;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ne_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  q1n_tmp.init();
  x = *this;
  b_st.site = &oe_emlrtRSI;
  x.normalize(b_st);
  q1n.a =
      ((x.a * q1n_tmp.a - x.b * q1n_tmp.b) - x.c * q1n_tmp.c) - x.d * q1n_tmp.d;
  q1n.b =
      ((x.a * q1n_tmp.b + x.b * q1n_tmp.a) + x.c * q1n_tmp.d) - x.d * q1n_tmp.c;
  q1n.c =
      ((x.a * q1n_tmp.c - x.b * q1n_tmp.d) + x.c * q1n_tmp.a) + x.d * q1n_tmp.b;
  q1n.d =
      ((x.a * q1n_tmp.d + x.b * q1n_tmp.c) - x.c * q1n_tmp.b) + x.d * q1n_tmp.a;
  x = q2;
  b_st.site = &pe_emlrtRSI;
  x.normalize(b_st);
  q2n.a =
      ((x.a * q1n_tmp.a - x.b * q1n_tmp.b) - x.c * q1n_tmp.c) - x.d * q1n_tmp.d;
  q2n.b =
      ((x.a * q1n_tmp.b + x.b * q1n_tmp.a) + x.c * q1n_tmp.d) - x.d * q1n_tmp.c;
  q2n.c =
      ((x.a * q1n_tmp.c - x.b * q1n_tmp.d) + x.c * q1n_tmp.a) + x.d * q1n_tmp.b;
  q2n.d =
      ((x.a * q1n_tmp.d + x.b * q1n_tmp.c) - x.c * q1n_tmp.b) + x.d * q1n_tmp.a;
  dp = ((q1n.a * q2n.a + q1n.b * q2n.b) + q1n.c * q2n.c) + q1n.d * q2n.d;
  if (dp < 0.0) {
    q2n.a = -q2n.a;
    q2n.b = -q2n.b;
    q2n.c = -q2n.c;
    q2n.d = -q2n.d;
    dp = -dp;
  }
  if (dp > 1.0) {
    dp = 1.0;
  }
  dp = muDoubleScalarAcos(dp);
  sinv_tmp = muDoubleScalarSin(dp);
  sinv = 1.0 / sinv_tmp;
  dp = muDoubleScalarSin(0.0 * dp);
  qo.a = sinv * (dp * q1n.a + sinv_tmp * q2n.a);
  qo.b = sinv * (dp * q1n.b + sinv_tmp * q2n.b);
  qo.c = sinv * (dp * q1n.c + sinv_tmp * q2n.c);
  qo.d = sinv * (dp * q1n.d + sinv_tmp * q2n.d);
  if (muDoubleScalarIsInf(sinv)) {
    replaceval.a = a;
    replaceval.b = b;
    replaceval.c = c;
    replaceval.d = d;
    b_st.site = &re_emlrtRSI;
    replaceval.parenReference(b_st, r);
    b_st.site = &re_emlrtRSI;
    qo.parenAssign(b_st, r);
  }
  b_st.site = &se_emlrtRSI;
  qo.normalize(b_st);
  return qo;
}

quaternion quaternion::slerp(const emlrtStack &sp, const quaternion q2) const
{
  c_quaternion r;
  quaternion q1n;
  quaternion q1n_tmp;
  quaternion q2n;
  quaternion qo;
  quaternion replaceval;
  quaternion x;
  emlrtStack b_st;
  emlrtStack st;
  real_T dp;
  real_T sinv;
  real_T sinv_tmp;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ne_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  q1n_tmp.init();
  x = *this;
  b_st.site = &oe_emlrtRSI;
  x.normalize(b_st);
  q1n.a =
      ((x.a * q1n_tmp.a - x.b * q1n_tmp.b) - x.c * q1n_tmp.c) - x.d * q1n_tmp.d;
  q1n.b =
      ((x.a * q1n_tmp.b + x.b * q1n_tmp.a) + x.c * q1n_tmp.d) - x.d * q1n_tmp.c;
  q1n.c =
      ((x.a * q1n_tmp.c - x.b * q1n_tmp.d) + x.c * q1n_tmp.a) + x.d * q1n_tmp.b;
  q1n.d =
      ((x.a * q1n_tmp.d + x.b * q1n_tmp.c) - x.c * q1n_tmp.b) + x.d * q1n_tmp.a;
  x = q2;
  b_st.site = &pe_emlrtRSI;
  x.normalize(b_st);
  q2n.a =
      ((x.a * q1n_tmp.a - x.b * q1n_tmp.b) - x.c * q1n_tmp.c) - x.d * q1n_tmp.d;
  q2n.b =
      ((x.a * q1n_tmp.b + x.b * q1n_tmp.a) + x.c * q1n_tmp.d) - x.d * q1n_tmp.c;
  q2n.c =
      ((x.a * q1n_tmp.c - x.b * q1n_tmp.d) + x.c * q1n_tmp.a) + x.d * q1n_tmp.b;
  q2n.d =
      ((x.a * q1n_tmp.d + x.b * q1n_tmp.c) - x.c * q1n_tmp.b) + x.d * q1n_tmp.a;
  dp = ((q1n.a * q2n.a + q1n.b * q2n.b) + q1n.c * q2n.c) + q1n.d * q2n.d;
  if (dp < 0.0) {
    q2n.a = -q2n.a;
    q2n.b = -q2n.b;
    q2n.c = -q2n.c;
    q2n.d = -q2n.d;
    dp = -dp;
  }
  if (dp > 1.0) {
    dp = 1.0;
  }
  dp = muDoubleScalarAcos(dp);
  sinv_tmp = muDoubleScalarSin(dp);
  sinv = 1.0 / sinv_tmp;
  dp = muDoubleScalarSin(0.0 * dp);
  qo.a = sinv * (sinv_tmp * q1n.a + dp * q2n.a);
  qo.b = sinv * (sinv_tmp * q1n.b + dp * q2n.b);
  qo.c = sinv * (sinv_tmp * q1n.c + dp * q2n.c);
  qo.d = sinv * (sinv_tmp * q1n.d + dp * q2n.d);
  if (muDoubleScalarIsInf(sinv)) {
    replaceval.a = a;
    replaceval.b = b;
    replaceval.c = c;
    replaceval.d = d;
    b_st.site = &re_emlrtRSI;
    replaceval.parenReference(b_st, r);
    b_st.site = &re_emlrtRSI;
    qo.parenAssign(b_st, r);
  }
  b_st.site = &se_emlrtRSI;
  qo.normalize(b_st);
  return qo;
}

quaternion quaternion::slerp(const emlrtStack &sp, const quaternion q2,
                             real_T t) const
{
  c_quaternion r;
  quaternion q1n;
  quaternion q1n_tmp;
  quaternion q2n;
  quaternion qo;
  quaternion replaceval;
  quaternion x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T dp;
  real_T sinv;
  real_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ne_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ue_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  if (!(t >= 0.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &r_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedArray",
                                  "MATLAB:slerp:notGreaterEqual", 9, 4, 18,
                                  "input number 3, t,", 4, 2, ">=", 4, 1, "0");
  }
  c_st.site = &ib_emlrtRSI;
  if (!(t <= 1.0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
                                  "MATLAB:validateattributes:expectedArray",
                                  "MATLAB:slerp:notLessEqual", 9, 4, 18,
                                  "input number 3, t,", 4, 2, "<=", 4, 1, "1");
  }
  q1n_tmp.init();
  x = *this;
  b_st.site = &oe_emlrtRSI;
  x.normalize(b_st);
  q1n.a =
      ((x.a * q1n_tmp.a - x.b * q1n_tmp.b) - x.c * q1n_tmp.c) - x.d * q1n_tmp.d;
  q1n.b =
      ((x.a * q1n_tmp.b + x.b * q1n_tmp.a) + x.c * q1n_tmp.d) - x.d * q1n_tmp.c;
  q1n.c =
      ((x.a * q1n_tmp.c - x.b * q1n_tmp.d) + x.c * q1n_tmp.a) + x.d * q1n_tmp.b;
  q1n.d =
      ((x.a * q1n_tmp.d + x.b * q1n_tmp.c) - x.c * q1n_tmp.b) + x.d * q1n_tmp.a;
  x = q2;
  b_st.site = &pe_emlrtRSI;
  x.normalize(b_st);
  q2n.a =
      ((x.a * q1n_tmp.a - x.b * q1n_tmp.b) - x.c * q1n_tmp.c) - x.d * q1n_tmp.d;
  q2n.b =
      ((x.a * q1n_tmp.b + x.b * q1n_tmp.a) + x.c * q1n_tmp.d) - x.d * q1n_tmp.c;
  q2n.c =
      ((x.a * q1n_tmp.c - x.b * q1n_tmp.d) + x.c * q1n_tmp.a) + x.d * q1n_tmp.b;
  q2n.d =
      ((x.a * q1n_tmp.d + x.b * q1n_tmp.c) - x.c * q1n_tmp.b) + x.d * q1n_tmp.a;
  dp = ((q1n.a * q2n.a + q1n.b * q2n.b) + q1n.c * q2n.c) + q1n.d * q2n.d;
  if (dp < 0.0) {
    q2n.a = -q2n.a;
    q2n.b = -q2n.b;
    q2n.c = -q2n.c;
    q2n.d = -q2n.d;
    dp = -dp;
  }
  if (dp > 1.0) {
    dp = 1.0;
  }
  b_st.site = &qe_emlrtRSI;
  dp = muDoubleScalarAcos(dp);
  sinv = 1.0 / muDoubleScalarSin(dp);
  y = muDoubleScalarSin((1.0 - t) * dp);
  dp = muDoubleScalarSin(t * dp);
  qo.a = sinv * (y * q1n.a + dp * q2n.a);
  qo.b = sinv * (y * q1n.b + dp * q2n.b);
  qo.c = sinv * (y * q1n.c + dp * q2n.c);
  qo.d = sinv * (y * q1n.d + dp * q2n.d);
  if (muDoubleScalarIsInf(sinv)) {
    replaceval.a = a;
    replaceval.b = b;
    replaceval.c = c;
    replaceval.d = d;
    b_st.site = &re_emlrtRSI;
    replaceval.parenReference(b_st, r);
    b_st.site = &re_emlrtRSI;
    qo.parenAssign(b_st, r);
  }
  b_st.site = &se_emlrtRSI;
  qo.normalize(b_st);
  return qo;
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (quaternion.cpp)
