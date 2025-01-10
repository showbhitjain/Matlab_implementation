//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// constructLinearTimeScaling.cpp
//
// Code generation for function 'constructLinearTimeScaling'
//

// Include files
#include "constructLinearTimeScaling.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo xd_emlrtRSI{
    12,                           // lineNo
    "constructLinearTimeScaling", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m" // pathName
};

static emlrtRSInfo yd_emlrtRSI{
    27,                           // lineNo
    "constructLinearTimeScaling", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m" // pathName
};

static emlrtRSInfo ae_emlrtRSI{
    51,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pathName
};

static emlrtBCInfo hb_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    21,                           // lineNo
    1,                            // colNo
    "",                           // aName
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m", // pName
    0                                               // checkKind
};

static emlrtBCInfo ib_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    22,                           // lineNo
    1,                            // colNo
    "",                           // aName
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m", // pName
    0                                               // checkKind
};

static emlrtBCInfo jb_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    23,                           // lineNo
    1,                            // colNo
    "",                           // aName
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m", // pName
    0                                               // checkKind
};

static emlrtBCInfo kb_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    24,                           // lineNo
    1,                            // colNo
    "",                           // aName
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m", // pName
    0                                               // checkKind
};

static emlrtRTEInfo ic_emlrtRTEI{
    16,                           // lineNo
    1,                            // colNo
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m" // pName
};

static emlrtRTEInfo jc_emlrtRTEI{
    17,                           // lineNo
    1,                            // colNo
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    1,                            // lineNo
    20,                           // colNo
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m" // pName
};

static emlrtRTEInfo lc_emlrtRTEI{
    27,                           // lineNo
    1,                            // colNo
    "constructLinearTimeScaling", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/+robotics/"
    "+core/+internal/constructLinearTimeScaling.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
namespace robotics {
namespace core {
namespace internal {
void constructLinearTimeScaling(const emlrtStack &sp,
                                const real_T timeInterval[2],
                                const ::coder::array<real_T, 2U> &b_time,
                                ::coder::array<real_T, 2U> &scaling)
{
  ::coder::array<real_T, 2U> s;
  ::coder::array<real_T, 2U> sd;
  ::coder::array<int32_T, 2U> r2;
  ::coder::array<int32_T, 2U> r3;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_timeInterval;
  real_T linearScaling;
  int32_T end_tmp;
  int32_T loop_ub;
  int32_T n;
  int32_T nx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &xd_emlrtRSI;
  nx = b_time.size(1);
  b_st.site = &ae_emlrtRSI;
  n = 1;
  if (b_time.size(1) > 1) {
    n = b_time.size(1);
  }
  if (b_time.size(1) > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  linearScaling = 1.0 / (timeInterval[1] - timeInterval[0]);
  s.set_size(&ic_emlrtRTEI, &sp, 1, b_time.size(1));
  b_timeInterval = timeInterval[0];
  loop_ub = b_time.size(1);
  sd.set_size(&jc_emlrtRTEI, &sp, 1, b_time.size(1));
  nx = (loop_ub / 2) << 1;
  n = nx - 2;
  for (int32_T i{0}; i <= n; i += 2) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&b_time[i]);
    r1 = _mm_set1_pd(linearScaling);
    _mm_storeu_pd(&s[i],
                  _mm_mul_pd(r1, _mm_sub_pd(r, _mm_set1_pd(b_timeInterval))));
    _mm_storeu_pd(&sd[i], r1);
  }
  for (int32_T i{nx}; i < loop_ub; i++) {
    s[i] = linearScaling * (b_time[i] - b_timeInterval);
    sd[i] = linearScaling;
  }
  end_tmp = b_time.size(1) - 1;
  nx = 0;
  for (n = 0; n <= end_tmp; n++) {
    if (b_time[n] < timeInterval[0]) {
      nx++;
    }
  }
  r2.set_size(&kc_emlrtRTEI, &sp, 1, nx);
  nx = 0;
  for (n = 0; n <= end_tmp; n++) {
    if (b_time[n] < timeInterval[0]) {
      r2[nx] = n;
      nx++;
    }
  }
  nx = s.size(1);
  loop_ub = r2.size(1) - 1;
  for (int32_T i{0}; i <= loop_ub; i++) {
    if (r2[i] > nx - 1) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 0, nx - 1, &hb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    s[r2[i]] = 0.0;
  }
  nx = 0;
  for (n = 0; n <= end_tmp; n++) {
    if (b_time[n] > timeInterval[1]) {
      nx++;
    }
  }
  r3.set_size(&kc_emlrtRTEI, &sp, 1, nx);
  nx = 0;
  for (n = 0; n <= end_tmp; n++) {
    if (b_time[n] > timeInterval[1]) {
      r3[nx] = n;
      nx++;
    }
  }
  nx = s.size(1);
  n = r3.size(1) - 1;
  for (int32_T i{0}; i <= n; i++) {
    if (r3[i] > nx - 1) {
      emlrtDynamicBoundsCheckR2012b(r3[i], 0, nx - 1, &ib_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    s[r3[i]] = 1.0;
  }
  loop_ub = r2.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    if (r2[i] > end_tmp) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 0, end_tmp, &jb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    sd[r2[i]] = 0.0;
  }
  nx = sd.size(1);
  for (int32_T i{0}; i <= n; i++) {
    if (r3[i] > nx - 1) {
      emlrtDynamicBoundsCheckR2012b(r3[i], 0, nx - 1, &kb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    sd[r3[i]] = 0.0;
  }
  st.site = &yd_emlrtRSI;
  b_st.site = &ed_emlrtRSI;
  c_st.site = &fd_emlrtRSI;
  if (sd.size(1) != s.size(1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (b_time.size(1) != s.size(1)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  scaling.set_size(&lc_emlrtRTEI, &b_st, 3, s.size(1));
  loop_ub = s.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    scaling[3 * i] = s[i];
    scaling[3 * i + 1] = sd[i];
    scaling[3 * i + 2] = 0.0;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (constructLinearTimeScaling.cpp)
