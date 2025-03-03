//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// IndexOfDependentEq_.cpp
//
// Code generation for function 'IndexOfDependentEq_'
//

// Include files
#include "IndexOfDependentEq_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo cd_emlrtRSI{
    1,                     // lineNo
    "IndexOfDependentEq_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/IndexOfDependentEq_.p" // pathName
};

static emlrtBCInfo pb_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    1,                     // lineNo
    1,                     // colNo
    "",                    // aName
    "IndexOfDependentEq_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/IndexOfDependentEq_.p", // pName
    0                                    // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void IndexOfDependentEq_(const emlrtStack &sp, array<int32_T, 1U> &depIdx,
                         int32_T mFixed, int32_T nDep, e_struct_T &qrmanager,
                         int32_T mRows, int32_T nCols)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T i;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &cd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (mFixed > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mFixed; idx++) {
    i = qrmanager.jpvt.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &pb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    qrmanager.jpvt[idx] = 1;
  }
  a = mFixed + 1;
  st.site = &cd_emlrtRSI;
  if ((mFixed + 1 <= nCols) && (nCols > 2147483646)) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{a}; idx <= nCols; idx++) {
    i = qrmanager.jpvt.size(0);
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &pb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    qrmanager.jpvt[idx - 1] = 0;
  }
  st.site = &cd_emlrtRSI;
  if (mRows * nCols == 0) {
    qrmanager.mrows = mRows;
    qrmanager.ncols = nCols;
    qrmanager.minRowCol = 0;
  } else {
    qrmanager.usedPivoting = true;
    qrmanager.mrows = mRows;
    qrmanager.ncols = nCols;
    qrmanager.minRowCol = muIntScalarMin_sint32(mRows, nCols);
    b_st.site = &ec_emlrtRSI;
    internal::lapack::xgeqp3(b_st, qrmanager.QR, mRows, nCols, qrmanager.jpvt,
                             qrmanager.tau);
  }
  st.site = &cd_emlrtRSI;
  if (nDep > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  i = qrmanager.jpvt.size(0);
  for (int32_T idx{0}; idx < nDep; idx++) {
    int32_T i1;
    a = ((nCols - nDep) + idx) + 1;
    if ((a < 1) || (a > i)) {
      emlrtDynamicBoundsCheckR2012b(a, 1, i, &pb_emlrtBCI, (emlrtConstCTX)&sp);
    }
    i1 = depIdx.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i1)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &pb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    depIdx[idx] = qrmanager.jpvt[a - 1];
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (IndexOfDependentEq_.cpp)
