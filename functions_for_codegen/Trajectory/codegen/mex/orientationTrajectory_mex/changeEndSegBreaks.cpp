//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// changeEndSegBreaks.cpp
//
// Code generation for function 'changeEndSegBreaks'
//

// Include files
#include "changeEndSegBreaks.h"
#include "find.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo kc_emlrtRSI{
    50,                   // lineNo
    "changeEndSegBreaks", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/changeEndSegBreaks.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    39,                                                            // lineNo
    "find",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtBCInfo nd_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    57,                   // lineNo
    31,                   // colNo
    "",                   // aName
    "changeEndSegBreaks", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/changeEndSegBreaks.m", // pName
    0                                 // checkKind
};

static emlrtBCInfo od_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    48,                   // lineNo
    23,                   // colNo
    "",                   // aName
    "changeEndSegBreaks", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/changeEndSegBreaks.m", // pName
    0                                 // checkKind
};

static emlrtRTEInfo ff_emlrtRTEI{
    50,                   // lineNo
    26,                   // colNo
    "changeEndSegBreaks", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/changeEndSegBreaks.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
namespace robotics {
namespace core {
namespace internal {
void changeEndSegBreaks(const emlrtStack &sp, real_T oldBreaks[4],
                        const ::coder::array<real_T, 2U> &evalTime)
{
  ::coder::array<boolean_T, 2U> b_evalTime;
  emlrtStack b_st;
  emlrtStack st;
  real_T b_oldBreaks;
  real_T dt;
  int32_T ii_size[2];
  int32_T ii_data;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  dt = 0.01;
  st.site = &kc_emlrtRSI;
  b_oldBreaks = oldBreaks[2];
  b_evalTime.set_size(&ff_emlrtRTEI, &st, 1, evalTime.size(1));
  ii_data = evalTime.size(1);
  for (int32_T i{0}; i < ii_data; i++) {
    b_evalTime[i] = (evalTime[i] > b_oldBreaks);
  }
  b_st.site = &lc_emlrtRSI;
  eml_find(b_st, b_evalTime, (int32_T *)&ii_data, ii_size);
  if (ii_size[1] != 0) {
    if ((ii_data < 1) || (ii_data > evalTime.size(1))) {
      emlrtDynamicBoundsCheckR2012b(ii_data, 1, evalTime.size(1), &nd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    dt = muDoubleScalarMin((evalTime[ii_data - 1] - oldBreaks[2]) / 2.0, 0.01);
  }
  oldBreaks[2] += dt;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void changeEndSegBreaks(const emlrtStack &sp,
                        ::coder::array<real_T, 2U> &oldBreaks,
                        const ::coder::array<real_T, 2U> &evalTime)
{
  ::coder::array<boolean_T, 2U> b_evalTime;
  emlrtStack b_st;
  emlrtStack st;
  real_T dt;
  real_T oldBreaks_tmp;
  int32_T ii_size[2];
  int32_T i;
  int32_T i1;
  int32_T ii_data;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  dt = 0.01;
  i = oldBreaks.size(1);
  i1 = oldBreaks.size(1) - 1;
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &od_emlrtBCI, (emlrtConstCTX)&sp);
  }
  st.site = &kc_emlrtRSI;
  oldBreaks_tmp = oldBreaks[oldBreaks.size(1) - 2];
  b_evalTime.set_size(&ff_emlrtRTEI, &st, 1, evalTime.size(1));
  ii_data = evalTime.size(1);
  for (i = 0; i < ii_data; i++) {
    b_evalTime[i] = (evalTime[i] > oldBreaks_tmp);
  }
  b_st.site = &lc_emlrtRSI;
  eml_find(b_st, b_evalTime, (int32_T *)&ii_data, ii_size);
  if (ii_size[1] != 0) {
    if ((ii_data < 1) || (ii_data > evalTime.size(1))) {
      emlrtDynamicBoundsCheckR2012b(ii_data, 1, evalTime.size(1), &nd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    dt = muDoubleScalarMin((evalTime[ii_data - 1] - oldBreaks_tmp) / 2.0, 0.01);
  }
  oldBreaks[i1 - 1] = oldBreaks_tmp + dt;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace core
} // namespace robotics
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (changeEndSegBreaks.cpp)
