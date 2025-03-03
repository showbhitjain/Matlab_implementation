//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// feasibleratiotest.cpp
//
// Code generation for function 'feasibleratiotest'
//

// Include files
#include "feasibleratiotest.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo ki_emlrtRSI{
    1,                   // lineNo
    "feasibleratiotest", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "feasibleratiotest.p" // pathName
};

static emlrtBCInfo ne_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    1,                   // lineNo
    1,                   // colNo
    "",                  // aName
    "feasibleratiotest", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "feasibleratiotest.p", // pName
    0                      // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
real_T feasibleratiotest(
    const emlrtStack &sp, const array<real_T, 1U> &solution_xstar,
    const array<real_T, 1U> &solution_searchDir, array<real_T, 2U> &workspace,
    int32_T workingset_nVar, int32_T workingset_ldA,
    const array<real_T, 1U> &workingset_Aineq,
    const array<real_T, 1U> &workingset_bineq,
    const array<real_T, 1U> &workingset_lb,
    const array<real_T, 1U> &workingset_ub,
    const array<int32_T, 1U> &workingset_indexLB,
    const array<int32_T, 1U> &workingset_indexUB,
    const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
    const array<boolean_T, 1U> &workingset_isActiveConstr,
    const int32_T workingset_nWConstr[5], boolean_T isPhaseOne,
    boolean_T &newBlocking, int32_T &constrType, int32_T &constrIdx)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha;
  real_T alphaTemp;
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T pk_corrected;
  int32_T i;
  int32_T i1;
  int32_T totalIneq;
  int32_T totalUB;
  char_T TRANSA;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  alpha = 1.0E+30;
  newBlocking = false;
  constrType = 0;
  constrIdx = 0;
  if (workingset_nVar < 1) {
    alphaTemp = 0.0;
  } else {
    n_t = (ptrdiff_t)workingset_nVar;
    incx_t = (ptrdiff_t)1;
    alphaTemp =
        dnrm2(&n_t, &(((array<real_T, 1U> *)&solution_searchDir)->data())[0],
              &incx_t);
  }
  denomTol = 2.2204460492503131E-13 * alphaTemp;
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    int32_T ldw;
    st.site = &ki_emlrtRSI;
    if (workingset_sizes[2] >= 1) {
      n_t = (ptrdiff_t)workingset_sizes[2];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(((array<real_T, 1U> *)&workingset_bineq)->data())[0],
            &incx_t, &(workspace.data())[0], &incy_t);
    }
    st.site = &ki_emlrtRSI;
    internal::blas::xgemv(workingset_nVar, workingset_sizes[2],
                          workingset_Aineq, workingset_ldA, solution_xstar,
                          workspace);
    ldw = workspace.size(0);
    st.site = &ki_emlrtRSI;
    if ((workingset_nVar >= 1) && (workingset_sizes[2] >= 1)) {
      alphaTemp = 1.0;
      pk_corrected = 0.0;
      TRANSA = 'T';
      m_t = (ptrdiff_t)workingset_nVar;
      n_t = (ptrdiff_t)workingset_sizes[2];
      lda_t = (ptrdiff_t)workingset_ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &alphaTemp,
            &(((array<real_T, 1U> *)&workingset_Aineq)->data())[0], &lda_t,
            &(((array<real_T, 1U> *)&solution_searchDir)->data())[0], &incx_t,
            &pk_corrected, &workspace[workspace.size(0)], &incy_t);
    }
    st.site = &ki_emlrtRSI;
    if (workingset_sizes[2] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < totalIneq; idx++) {
      i = workspace.size(0) * workspace.size(1);
      i1 = (ldw + idx) + 1;
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ne_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      pk_corrected = workspace[i1 - 1];
      if (pk_corrected > denomTol) {
        int32_T i2;
        st.site = &ki_emlrtRSI;
        i2 = (workingset_isActiveIdx[2] + idx) + 1;
        if ((i2 - 1 < 1) || (i2 - 1 > workingset_isActiveConstr.size(0))) {
          emlrtDynamicBoundsCheckR2012b(
              i2 - 1, 1, workingset_isActiveConstr.size(0), &jc_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i2 - 2]) {
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ne_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (idx + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ne_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (i1 > i) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ne_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          alphaTemp = workspace[idx];
          alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(alphaTemp),
                                        1.0E-6 - alphaTemp) /
                      pk_corrected;
          if (alphaTemp < alpha) {
            alpha = alphaTemp;
            constrType = 3;
            constrIdx = idx + 1;
            newBlocking = true;
          }
        }
      }
    }
  }
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    if ((workingset_nVar < 1) || (workingset_nVar > solution_xstar.size(0))) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1, solution_xstar.size(0),
                                    &ne_emlrtBCI, (emlrtConstCTX)&sp);
    }
    phaseOneCorrectionX =
        static_cast<real_T>(isPhaseOne) * solution_xstar[workingset_nVar - 1];
    if (workingset_nVar > solution_searchDir.size(0)) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1,
                                    solution_searchDir.size(0), &ne_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    phaseOneCorrectionP = static_cast<real_T>(isPhaseOne) *
                          solution_searchDir[workingset_nVar - 1];
    i = workingset_sizes[3];
    st.site = &ki_emlrtRSI;
    for (int32_T idx{0}; idx <= i - 2; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > workingset_indexLB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, workingset_indexLB.size(0),
                                      &ne_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((workingset_indexLB[idx] < 1) ||
          (workingset_indexLB[idx] > solution_searchDir.size(0))) {
        emlrtDynamicBoundsCheckR2012b(workingset_indexLB[idx], 1,
                                      solution_searchDir.size(0), &ne_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      pk_corrected = -solution_searchDir[workingset_indexLB[idx] - 1] -
                     phaseOneCorrectionP;
      if (pk_corrected > denomTol) {
        st.site = &ki_emlrtRSI;
        i1 = workingset_isActiveIdx[3] + idx;
        if ((i1 < 1) || (i1 > workingset_isActiveConstr.size(0))) {
          emlrtDynamicBoundsCheckR2012b(
              i1, 1, workingset_isActiveConstr.size(0), &jc_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i1 - 1]) {
          if ((workingset_indexLB[idx] < 1) ||
              (workingset_indexLB[idx] > solution_xstar.size(0))) {
            emlrtDynamicBoundsCheckR2012b(workingset_indexLB[idx], 1,
                                          solution_xstar.size(0), &ne_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if ((workingset_indexLB[idx] < 1) ||
              (workingset_indexLB[idx] > workingset_lb.size(0))) {
            emlrtDynamicBoundsCheckR2012b(workingset_indexLB[idx], 1,
                                          workingset_lb.size(0), &ne_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          alphaTemp = (-solution_xstar[workingset_indexLB[idx] - 1] -
                       workingset_lb[workingset_indexLB[idx] - 1]) -
                      phaseOneCorrectionX;
          alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(alphaTemp),
                                        1.0E-6 - alphaTemp) /
                      pk_corrected;
          if (alphaTemp < alpha) {
            alpha = alphaTemp;
            constrType = 4;
            constrIdx = idx + 1;
            newBlocking = true;
          }
        }
      }
    }
    if ((workingset_sizes[3] < 1) ||
        (workingset_sizes[3] > workingset_indexLB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(workingset_sizes[3], 1,
                                    workingset_indexLB.size(0), &ne_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = workingset_indexLB[workingset_sizes[3] - 1];
    if ((i < 1) || (i > solution_searchDir.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, solution_searchDir.size(0),
                                    &ne_emlrtBCI, (emlrtConstCTX)&sp);
    }
    pk_corrected = -solution_searchDir[i - 1];
    if (pk_corrected > denomTol) {
      st.site = &ki_emlrtRSI;
      i1 = workingset_isActiveIdx[3] + workingset_sizes[3];
      if ((i1 - 1 < 1) || (i1 - 1 > workingset_isActiveConstr.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            i1 - 1, 1, workingset_isActiveConstr.size(0), &jc_emlrtBCI, &st);
      }
      if (!workingset_isActiveConstr[i1 - 2]) {
        if (i > solution_xstar.size(0)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, solution_xstar.size(0),
                                        &ne_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if (i > workingset_lb.size(0)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, workingset_lb.size(0),
                                        &ne_emlrtBCI, (emlrtConstCTX)&sp);
        }
        alphaTemp = -solution_xstar[i - 1] - workingset_lb[i - 1];
        if (i > solution_searchDir.size(0)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, solution_searchDir.size(0),
                                        &ne_emlrtBCI, (emlrtConstCTX)&sp);
        }
        alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(alphaTemp),
                                      1.0E-6 - alphaTemp) /
                    pk_corrected;
        if (alphaTemp < alpha) {
          alpha = alphaTemp;
          constrType = 4;
          constrIdx = workingset_sizes[3];
          newBlocking = true;
        }
      }
    }
  }
  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    if ((workingset_nVar < 1) || (workingset_nVar > solution_xstar.size(0))) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1, solution_xstar.size(0),
                                    &ne_emlrtBCI, (emlrtConstCTX)&sp);
    }
    phaseOneCorrectionX =
        static_cast<real_T>(isPhaseOne) * solution_xstar[workingset_nVar - 1];
    if (workingset_nVar > solution_searchDir.size(0)) {
      emlrtDynamicBoundsCheckR2012b(workingset_nVar, 1,
                                    solution_searchDir.size(0), &ne_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    phaseOneCorrectionP = static_cast<real_T>(isPhaseOne) *
                          solution_searchDir[workingset_nVar - 1];
    st.site = &ki_emlrtRSI;
    if (workingset_sizes[4] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T idx{0}; idx < totalUB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > workingset_indexUB.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, workingset_indexUB.size(0),
                                      &ne_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((workingset_indexUB[idx] < 1) ||
          (workingset_indexUB[idx] > solution_searchDir.size(0))) {
        emlrtDynamicBoundsCheckR2012b(workingset_indexUB[idx], 1,
                                      solution_searchDir.size(0), &ne_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      pk_corrected =
          solution_searchDir[workingset_indexUB[idx] - 1] - phaseOneCorrectionP;
      if (pk_corrected > denomTol) {
        st.site = &ki_emlrtRSI;
        i = workingset_isActiveIdx[4] + idx;
        if ((i < 1) || (i > workingset_isActiveConstr.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, workingset_isActiveConstr.size(0),
                                        &jc_emlrtBCI, &st);
        }
        if (!workingset_isActiveConstr[i - 1]) {
          if ((workingset_indexUB[idx] < 1) ||
              (workingset_indexUB[idx] > solution_xstar.size(0))) {
            emlrtDynamicBoundsCheckR2012b(workingset_indexUB[idx], 1,
                                          solution_xstar.size(0), &ne_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if ((workingset_indexUB[idx] < 1) ||
              (workingset_indexUB[idx] > workingset_ub.size(0))) {
            emlrtDynamicBoundsCheckR2012b(workingset_indexUB[idx], 1,
                                          workingset_ub.size(0), &ne_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          alphaTemp = (solution_xstar[workingset_indexUB[idx] - 1] -
                       workingset_ub[workingset_indexUB[idx] - 1]) -
                      phaseOneCorrectionX;
          alphaTemp = muDoubleScalarMin(muDoubleScalarAbs(alphaTemp),
                                        1.0E-6 - alphaTemp) /
                      pk_corrected;
          if (alphaTemp < alpha) {
            alpha = alphaTemp;
            constrType = 5;
            constrIdx = idx + 1;
            newBlocking = true;
          }
        }
      }
    }
  }
  if (!isPhaseOne) {
    if (newBlocking && (alpha > 1.0)) {
      newBlocking = false;
    }
    alpha = muDoubleScalarMin(alpha, 1.0);
  }
  return alpha;
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (feasibleratiotest.cpp)
