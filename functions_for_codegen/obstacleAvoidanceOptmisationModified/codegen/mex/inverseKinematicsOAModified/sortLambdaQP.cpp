//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sortLambdaQP.cpp
//
// Code generation for function 'sortLambdaQP'
//

// Include files
#include "sortLambdaQP.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo tf_emlrtRSI{
    1,              // lineNo
    "sortLambdaQP", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+parseoutput/sortLambdaQP.p" // pathName
};

static emlrtBCInfo cc_emlrtBCI{
    -1,             // iFirst
    -1,             // iLast
    1,              // lineNo
    1,              // colNo
    "",             // aName
    "sortLambdaQP", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+parseoutput/sortLambdaQP.p", // pName
    0                              // checkKind
};

static emlrtRTEInfo tb_emlrtRTEI{
    1,              // lineNo
    1,              // colNo
    "sortLambdaQP", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+parseoutput/sortLambdaQP.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace parseoutput {
void sortLambdaQP(const emlrtStack &sp, real_T lambda_data[],
                  int32_T &lambda_size, int32_T WorkingSet_nActiveConstr,
                  const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6],
                  const int32_T WorkingSet_Wid_data[],
                  int32_T WorkingSet_Wid_size,
                  const int32_T WorkingSet_Wlocalidx_data[],
                  int32_T WorkingSet_Wlocalidx_size,
                  array<real_T, 2U> &workspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if ((lambda_size != 0) && (WorkingSet_nActiveConstr != 0)) {
    int32_T currentMplier;
    int32_T i;
    int32_T idx;
    int32_T mAll;
    boolean_T exitg1;
    mAll =
        (((WorkingSet_sizes[0] + WorkingSet_sizes[1]) + WorkingSet_sizes[3]) +
         WorkingSet_sizes[4]) +
        WorkingSet_sizes[2];
    st.site = &tf_emlrtRSI;
    if (mAll >= 1) {
      b_st.site = &ub_emlrtRSI;
      c_st.site = &wb_emlrtRSI;
      n_t = (ptrdiff_t)mAll;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &lambda_data[0], &incx_t, &(workspace.data())[0], &incy_t);
    }
    r.set_size(&tb_emlrtRTEI, &sp, lambda_size);
    for (i = 0; i < lambda_size; i++) {
      r[i] = lambda_data[i];
    }
    st.site = &tf_emlrtRSI;
    b_st.site = &qf_emlrtRSI;
    c_st.site = &vb_emlrtRSI;
    if (mAll > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(d_st);
    }
    for (currentMplier = 0; currentMplier < mAll; currentMplier++) {
      r[currentMplier] = 0.0;
    }
    lambda_size = r.size(0);
    mAll = r.size(0);
    for (i = 0; i < mAll; i++) {
      lambda_data[i] = r[i];
    }
    currentMplier = 1;
    idx = 1;
    exitg1 = false;
    while ((!exitg1) && (idx <= WorkingSet_nActiveConstr)) {
      if (idx > WorkingSet_Wid_size) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wid_size, &cc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = WorkingSet_Wid_data[idx - 1];
      if (i <= 2) {
        if (idx > WorkingSet_Wlocalidx_size) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wlocalidx_size,
                                        &cc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if (idx > WorkingSet_Wid_size) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wid_size,
                                        &cc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if (i == 1) {
          mAll = 0;
        } else {
          mAll = WorkingSet_isActiveIdx[1] - 1;
        }
        i = workspace.size(0) * workspace.size(1);
        if ((currentMplier < 1) || (currentMplier > i)) {
          emlrtDynamicBoundsCheckR2012b(currentMplier, 1, i, &cc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        i = lambda_size;
        mAll += WorkingSet_Wlocalidx_data[idx - 1];
        if ((mAll < 1) || (mAll > i)) {
          emlrtDynamicBoundsCheckR2012b(mAll, 1, i, &cc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        lambda_data[mAll - 1] = workspace[currentMplier - 1];
        currentMplier++;
        idx++;
      } else {
        exitg1 = true;
      }
    }
    while (idx <= WorkingSet_nActiveConstr) {
      if (idx > WorkingSet_Wlocalidx_size) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wlocalidx_size,
                                      &cc_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if (idx > WorkingSet_Wid_size) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wid_size, &cc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      switch (WorkingSet_Wid_data[idx - 1]) {
      case 3:
        mAll = WorkingSet_isActiveIdx[2];
        break;
      case 4:
        mAll = WorkingSet_isActiveIdx[3];
        break;
      default:
        mAll = WorkingSet_isActiveIdx[4];
        break;
      }
      i = workspace.size(0) * workspace.size(1);
      if ((currentMplier < 1) || (currentMplier > i)) {
        emlrtDynamicBoundsCheckR2012b(currentMplier, 1, i, &cc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = lambda_size;
      mAll = (mAll + WorkingSet_Wlocalidx_data[idx - 1]) - 1;
      if ((mAll < 1) || (mAll > i)) {
        emlrtDynamicBoundsCheckR2012b(mAll, 1, i, &cc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lambda_data[mAll - 1] = workspace[currentMplier - 1];
      currentMplier++;
      idx++;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace parseoutput
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (sortLambdaQP.cpp)
