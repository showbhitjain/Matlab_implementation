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
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo sf_emlrtRSI{
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

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace parseoutput {
void sortLambdaQP(const emlrtStack &sp, array<real_T, 1U> &lambda,
                  int32_T WorkingSet_nActiveConstr,
                  const int32_T WorkingSet_sizes[5],
                  const int32_T WorkingSet_isActiveIdx[6],
                  const array<int32_T, 1U> &WorkingSet_Wid,
                  const array<int32_T, 1U> &WorkingSet_Wlocalidx,
                  array<real_T, 2U> &workspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  if (WorkingSet_nActiveConstr != 0) {
    int32_T currentMplier;
    int32_T i;
    int32_T idx;
    int32_T mAll;
    boolean_T exitg1;
    mAll =
        (((WorkingSet_sizes[0] + WorkingSet_sizes[1]) + WorkingSet_sizes[3]) +
         WorkingSet_sizes[4]) +
        WorkingSet_sizes[2];
    if (mAll >= 1) {
      n_t = (ptrdiff_t)mAll;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(lambda.data())[0], &incx_t, &(workspace.data())[0],
            &incy_t);
    }
    st.site = &sf_emlrtRSI;
    internal::blas::xcopy(st, mAll, lambda);
    currentMplier = 1;
    idx = 1;
    exitg1 = false;
    while ((!exitg1) && (idx <= WorkingSet_nActiveConstr)) {
      if ((idx < 1) || (idx > WorkingSet_Wid.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wid.size(0),
                                      &cc_emlrtBCI, (emlrtConstCTX)&sp);
      }
      i = WorkingSet_Wid[idx - 1];
      if (i <= 2) {
        if (idx > WorkingSet_Wlocalidx.size(0)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wlocalidx.size(0),
                                        &cc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if (idx > WorkingSet_Wid.size(0)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wid.size(0),
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
        i = lambda.size(0);
        mAll += WorkingSet_Wlocalidx[idx - 1];
        if ((mAll < 1) || (mAll > i)) {
          emlrtDynamicBoundsCheckR2012b(mAll, 1, i, &cc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        lambda[mAll - 1] = workspace[currentMplier - 1];
        currentMplier++;
        idx++;
      } else {
        exitg1 = true;
      }
    }
    while (idx <= WorkingSet_nActiveConstr) {
      if ((idx < 1) || (idx > WorkingSet_Wlocalidx.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wlocalidx.size(0),
                                      &cc_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if (idx > WorkingSet_Wid.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, WorkingSet_Wid.size(0),
                                      &cc_emlrtBCI, (emlrtConstCTX)&sp);
      }
      switch (WorkingSet_Wid[idx - 1]) {
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
      i = lambda.size(0);
      mAll = (mAll + WorkingSet_Wlocalidx[idx - 1]) - 1;
      if ((mAll < 1) || (mAll > i)) {
        emlrtDynamicBoundsCheckR2012b(mAll, 1, i, &cc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      lambda[mAll - 1] = workspace[currentMplier - 1];
      currentMplier++;
      idx++;
    }
  }
}

} // namespace parseoutput
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (sortLambdaQP.cpp)
