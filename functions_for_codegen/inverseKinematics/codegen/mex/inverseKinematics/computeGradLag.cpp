//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeGradLag.cpp
//
// Code generation for function 'computeGradLag'
//

// Include files
#include "computeGradLag.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo nf_emlrtRSI{
    1,                // lineNo
    "computeGradLag", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeGradLag.p" // pathName
};

static emlrtBCInfo ae_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "computeGradLag", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+stopping/computeGradLag.p", // pName
    0                             // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
void computeGradLag(const emlrtStack &sp, array<real_T, 1U> &workspace,
                    int32_T ldA, int32_T nVar, const array<real_T, 1U> &grad,
                    int32_T AineqTrans_size, int32_T mEq,
                    const array<real_T, 1U> &AeqTrans,
                    const array<int32_T, 1U> &finiteFixed, int32_T mFixed,
                    const array<int32_T, 1U> &finiteLB, int32_T mLB,
                    const array<int32_T, 1U> &finiteUB, int32_T mUB,
                    const array<real_T, 1U> &lambda)
{
  array<real_T, 1U> AineqTrans_data;
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T iL0;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &nf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nVar > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (iL0 = 0; iL0 < nVar; iL0++) {
    if ((iL0 + 1 < 1) || (iL0 + 1 > grad.size(0))) {
      emlrtDynamicBoundsCheckR2012b(iL0 + 1, 1, grad.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = workspace.size(0);
    if (iL0 + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(iL0 + 1, 1, i, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    workspace[iL0] = grad[iL0];
  }
  st.site = &nf_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mFixed; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteFixed.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteFixed.size(0),
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    i = workspace.size(0);
    if ((finiteFixed[idx] < 1) || (finiteFixed[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteFixed[idx], 1, i, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((idx + 1 < 1) || (idx + 1 > lambda.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lambda.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = workspace.size(0);
    if ((finiteFixed[idx] < 1) || (finiteFixed[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteFixed[idx], 1, i, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    workspace[finiteFixed[idx] - 1] =
        workspace[finiteFixed[idx] - 1] + lambda[idx];
  }
  st.site = &nf_emlrtRSI;
  ::coder::internal::blas::xgemv(nVar, mEq, AeqTrans, ldA, lambda, mFixed + 1,
                                 workspace);
  iL0 = (mFixed + mEq) + 1;
  AineqTrans_data.set(nullptr, AineqTrans_size);
  st.site = &nf_emlrtRSI;
  ::coder::internal::blas::xgemv(nVar, 0, AineqTrans_data, ldA, lambda, iL0,
                                 workspace);
  st.site = &nf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mLB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteLB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = workspace.size(0);
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, i, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = iL0 + idx;
    if ((i < 1) || (i > lambda.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, lambda.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i1 = workspace.size(0);
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > i1)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, i1, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    workspace[finiteLB[idx] - 1] = workspace[finiteLB[idx] - 1] - lambda[i - 1];
  }
  if (mLB - 1 >= 0) {
    iL0 += mLB;
  }
  st.site = &nf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mUB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteUB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteUB.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = workspace.size(0);
    if ((finiteUB[idx] < 1) || (finiteUB[idx] > i)) {
      emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, i, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = iL0 + idx;
    if ((i < 1) || (i > lambda.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, lambda.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i1 = workspace.size(0);
    if ((finiteUB[idx] < 1) || (finiteUB[idx] > i1)) {
      emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, i1, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    workspace[finiteUB[idx] - 1] = workspace[finiteUB[idx] - 1] + lambda[i - 1];
  }
}

void computeGradLag(const emlrtStack &sp, array<real_T, 2U> &workspace,
                    int32_T ldA, int32_T nVar, const array<real_T, 1U> &grad,
                    int32_T AineqTrans_size, int32_T mEq,
                    const array<real_T, 1U> &AeqTrans,
                    const array<int32_T, 1U> &finiteFixed, int32_T mFixed,
                    const array<int32_T, 1U> &finiteLB, int32_T mLB,
                    const array<int32_T, 1U> &finiteUB, int32_T mUB,
                    const array<real_T, 1U> &lambda)
{
  array<real_T, 1U> AineqTrans_data;
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T iL0;
  int32_T workspace_tmp;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &nf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nVar > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (iL0 = 0; iL0 < nVar; iL0++) {
    workspace_tmp = workspace.size(0) * workspace.size(1);
    if ((iL0 + 1 < 1) || (iL0 + 1 > grad.size(0))) {
      emlrtDynamicBoundsCheckR2012b(iL0 + 1, 1, grad.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if (iL0 + 1 > workspace_tmp) {
      emlrtDynamicBoundsCheckR2012b(iL0 + 1, 1, workspace_tmp, &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    workspace[iL0] = grad[iL0];
  }
  st.site = &nf_emlrtRSI;
  if (mFixed > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mFixed; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteFixed.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteFixed.size(0),
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    workspace_tmp = workspace.size(0) * workspace.size(1);
    if ((finiteFixed[idx] < 1) || (finiteFixed[idx] > workspace_tmp)) {
      emlrtDynamicBoundsCheckR2012b(finiteFixed[idx], 1, workspace_tmp,
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    if ((idx + 1 < 1) || (idx + 1 > lambda.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, lambda.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((finiteFixed[idx] < 1) || (finiteFixed[idx] > workspace_tmp)) {
      emlrtDynamicBoundsCheckR2012b(finiteFixed[idx], 1, workspace_tmp,
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    workspace[finiteFixed[idx] - 1] =
        workspace[finiteFixed[idx] - 1] + lambda[idx];
  }
  st.site = &nf_emlrtRSI;
  ::coder::internal::blas::xgemv(nVar, mEq, AeqTrans, ldA, lambda, mFixed + 1,
                                 workspace);
  iL0 = (mFixed + mEq) + 1;
  AineqTrans_data.set(nullptr, AineqTrans_size);
  st.site = &nf_emlrtRSI;
  ::coder::internal::blas::xgemv(nVar, 0, AineqTrans_data, ldA, lambda, iL0,
                                 workspace);
  st.site = &nf_emlrtRSI;
  if (mLB > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mLB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteLB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteLB.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    workspace_tmp = workspace.size(0) * workspace.size(1);
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > workspace_tmp)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, workspace_tmp,
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    i = iL0 + idx;
    if ((i < 1) || (i > lambda.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, lambda.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((finiteLB[idx] < 1) || (finiteLB[idx] > workspace_tmp)) {
      emlrtDynamicBoundsCheckR2012b(finiteLB[idx], 1, workspace_tmp,
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    workspace[finiteLB[idx] - 1] = workspace[finiteLB[idx] - 1] - lambda[i - 1];
  }
  if (mLB - 1 >= 0) {
    iL0 += mLB;
  }
  st.site = &nf_emlrtRSI;
  if (mUB > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mUB; idx++) {
    if ((idx + 1 < 1) || (idx + 1 > finiteUB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, finiteUB.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    workspace_tmp = workspace.size(0) * workspace.size(1);
    if ((finiteUB[idx] < 1) || (finiteUB[idx] > workspace_tmp)) {
      emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, workspace_tmp,
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    i = iL0 + idx;
    if ((i < 1) || (i > lambda.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, lambda.size(0), &ae_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((finiteUB[idx] < 1) || (finiteUB[idx] > workspace_tmp)) {
      emlrtDynamicBoundsCheckR2012b(finiteUB[idx], 1, workspace_tmp,
                                    &ae_emlrtBCI, (emlrtConstCTX)&sp);
    }
    workspace[finiteUB[idx] - 1] = workspace[finiteUB[idx] - 1] + lambda[i - 1];
  }
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeGradLag.cpp)
