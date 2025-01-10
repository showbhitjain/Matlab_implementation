//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// soc.cpp
//
// Code generation for function 'soc'
//

// Include files
#include "soc.h"
#include "addAeqConstr.h"
#include "driver1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "sortLambdaQP.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo bj_emlrtRSI{
    1,     // lineNo
    "soc", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "soc.p" // pathName
};

static emlrtRSInfo cj_emlrtRSI{
    1,                  // lineNo
    "updateWorkingSet", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p" // pathName
};

static emlrtRSInfo dj_emlrtRSI{
    1,                   // lineNo
    "restoreWorkingSet", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/restoreWorkingSet.p" // pathName
};

static emlrtBCInfo sd_emlrtBCI{
    -1,    // iFirst
    -1,    // iLast
    1,     // lineNo
    1,     // colNo
    "",    // aName
    "soc", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "soc.p", // pName
    0        // checkKind
};

static emlrtBCInfo td_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    1,                  // lineNo
    1,                  // colNo
    "",                 // aName
    "updateWorkingSet", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/updateWorkingSet.p", // pName
    0                          // checkKind
};

static emlrtBCInfo ud_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    1,                   // lineNo
    1,                   // colNo
    "",                  // aName
    "restoreWorkingSet", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+soc/restoreWorkingSet.p", // pName
    0                           // checkKind
};

static emlrtRTEInfo
    cc_emlrtRTEI{
        76,      // lineNo
        65,      // colNo
        "xgemv", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" // pName
    };

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
boolean_T soc(const emlrtStack &sp, const array<real_T, 2U> &Hessian,
              const array<real_T, 1U> &grad, i_struct_T &b_TrialState,
              g_struct_T &memspace, j_struct_T &WorkingSet,
              d_struct_T &b_QRManager, e_struct_T &b_CholManager,
              f_struct_T &QPObjective, const k_struct_T &qpoptions)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  k_struct_T b_qpoptions;
  real_T lenQPNormal;
  real_T lenSOC;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T mConstrMax;
  int32_T nVar;
  char_T TRANSA;
  boolean_T success;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  nVar = WorkingSet.nVar;
  mConstrMax = WorkingSet.mConstrMax;
  st.site = &bj_emlrtRSI;
  if (WorkingSet.nVar >= 1) {
    b_st.site = &x_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.xstarsqp_old.data())[0], &incx_t,
          &(b_TrialState.xstarsqp.data())[0], &incy_t);
  }
  st.site = &bj_emlrtRSI;
  if (WorkingSet.nVar > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (i = 0; i < nVar; i++) {
    b_i = b_TrialState.xstar.size(0);
    if ((i + 1 < 1) || (i + 1 > b_i)) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &sd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_i = b_TrialState.socDirection.size(0);
    if (i + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &sd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.socDirection[i] = b_TrialState.xstar[i];
  }
  st.site = &bj_emlrtRSI;
  if (WorkingSet.mConstrMax >= 1) {
    b_st.site = &x_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.mConstrMax;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.lambda.data())[0], &incx_t,
          &(b_TrialState.lambdaStopTest.data())[0], &incy_t);
  }
  st.site = &bj_emlrtRSI;
  if (WorkingSet.sizes[1] > 0) {
    b_st.site = &cj_emlrtRSI;
    if (WorkingSet.sizes[1] > 2147483646) {
      c_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    b_i = static_cast<uint8_T>(WorkingSet.sizes[1]);
    i = b_TrialState.cEq.size[0];
    for (int32_T idx{0}; idx < b_i; idx++) {
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &td_emlrtBCI, &st);
      }
      i1 = WorkingSet.beq.size[0];
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &td_emlrtBCI, &st);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    b_st.site = &cj_emlrtRSI;
    if (WorkingSet.nVar >= 1) {
      c_st.site = &tb_emlrtRSI;
      y.set_size(&cc_emlrtRTEI, &c_st, WorkingSet.beq.size[0]);
      i = WorkingSet.beq.size[0];
      for (b_i = 0; b_i < i; b_i++) {
        y[b_i] = WorkingSet.beq.data[b_i];
      }
      lenSOC = 1.0;
      lenQPNormal = 1.0;
      TRANSA = 'T';
      m_t = (ptrdiff_t)WorkingSet.nVar;
      n_t = (ptrdiff_t)WorkingSet.sizes[1];
      lda_t = (ptrdiff_t)WorkingSet.ldA;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dgemv(&TRANSA, &m_t, &n_t, &lenSOC, &(WorkingSet.Aeq.data())[0], &lda_t,
            &(b_TrialState.searchDir.data())[0], &incx_t, &lenQPNormal,
            &(y.data())[0], &incy_t);
      WorkingSet.beq.size[0] = y.size(0);
      i = y.size(0);
      for (b_i = 0; b_i < i; b_i++) {
        WorkingSet.beq.data[b_i] = y[b_i];
      }
    }
    b_st.site = &cj_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.sizes[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.beq.data[0], &incx_t,
          &WorkingSet.bwset[WorkingSet.sizes[0]], &incy_t);
  }
  st.site = &bj_emlrtRSI;
  if (WorkingSet.nVar >= 1) {
    b_st.site = &x_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.nVar;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(b_TrialState.xstarsqp.data())[0], &incx_t,
          &(b_TrialState.xstar.data())[0], &incy_t);
  }
  b_qpoptions = qpoptions;
  st.site = &bj_emlrtRSI;
  ::coder::optim::coder::qpactiveset::driver(
      st, Hessian, grad, b_TrialState, memspace, WorkingSet, b_QRManager,
      b_CholManager, QPObjective, b_qpoptions, qpoptions.MaxIterations);
  if (WorkingSet.indexEqRemoved.size[0] > 0) {
    boolean_T exitg1;
    exitg1 = false;
    while ((!exitg1) && (WorkingSet.mEqRemoved > 0)) {
      b_i = WorkingSet.indexEqRemoved.size[0];
      if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > b_i)) {
        emlrtDynamicBoundsCheckR2012b(WorkingSet.mEqRemoved, 1, b_i,
                                      &sd_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if (WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1] >=
          b_TrialState.iNonEq0) {
        b_i = WorkingSet.indexEqRemoved.size[0];
        if ((WorkingSet.mEqRemoved < 1) || (WorkingSet.mEqRemoved > b_i)) {
          emlrtDynamicBoundsCheckR2012b(WorkingSet.mEqRemoved, 1, b_i,
                                        &sd_emlrtBCI, (emlrtConstCTX)&sp);
        }
        st.site = &bj_emlrtRSI;
        qpactiveset::WorkingSet::addAeqConstr(
            st, WorkingSet,
            WorkingSet.indexEqRemoved.data[WorkingSet.mEqRemoved - 1]);
        WorkingSet.mEqRemoved--;
      } else {
        exitg1 = true;
      }
    }
  }
  st.site = &bj_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < nVar; idx++) {
    b_i = b_TrialState.socDirection.size(0);
    if ((idx + 1 < 1) || (idx + 1 > b_i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, b_i, &sd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    lenSOC = b_TrialState.socDirection[idx];
    b_i = b_TrialState.xstar.size(0);
    if (idx + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, b_i, &sd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_i = b_TrialState.socDirection.size(0);
    if (idx + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, b_i, &sd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.socDirection[idx] = b_TrialState.xstar[idx] - lenSOC;
    b_i = b_TrialState.xstar.size(0);
    if (idx + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, b_i, &sd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.xstar[idx] = lenSOC;
  }
  if (nVar < 1) {
    lenSOC = 0.0;
    lenQPNormal = 0.0;
  } else {
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    lenSOC = dnrm2(&n_t, &(b_TrialState.socDirection.data())[0], &incx_t);
    n_t = (ptrdiff_t)nVar;
    incx_t = (ptrdiff_t)1;
    lenQPNormal = dnrm2(&n_t, &(b_TrialState.xstar.data())[0], &incx_t);
  }
  success = (lenSOC <= 2.0 * lenQPNormal);
  st.site = &bj_emlrtRSI;
  if (WorkingSet.sizes[1] > 0) {
    b_st.site = &dj_emlrtRSI;
    if (WorkingSet.sizes[1] > 2147483646) {
      c_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    b_i = static_cast<uint8_T>(WorkingSet.sizes[1]);
    i = b_TrialState.cEq.size[0];
    for (int32_T idx{0}; idx < b_i; idx++) {
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ud_emlrtBCI, &st);
      }
      i1 = WorkingSet.beq.size[0];
      if (idx + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &ud_emlrtBCI, &st);
      }
      WorkingSet.beq.data[idx] = -b_TrialState.cEq.data[idx];
    }
    b_st.site = &dj_emlrtRSI;
    n_t = (ptrdiff_t)WorkingSet.sizes[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.beq.data[0], &incx_t,
          &WorkingSet.bwset[WorkingSet.sizes[0]], &incy_t);
  }
  if (!success) {
    st.site = &bj_emlrtRSI;
    if (mConstrMax >= 1) {
      b_st.site = &x_emlrtRSI;
      n_t = (ptrdiff_t)mConstrMax;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &(b_TrialState.lambdaStopTest.data())[0], &incx_t,
            &(b_TrialState.lambda.data())[0], &incy_t);
    }
  } else {
    st.site = &bj_emlrtRSI;
    qpactiveset::parseoutput::sortLambdaQP(
        st, b_TrialState.lambda, WorkingSet.nActiveConstr, WorkingSet.sizes,
        WorkingSet.isActiveIdx, WorkingSet.Wid, WorkingSet.Wlocalidx,
        memspace.workspace_double);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return success;
}

} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (soc.cpp)
