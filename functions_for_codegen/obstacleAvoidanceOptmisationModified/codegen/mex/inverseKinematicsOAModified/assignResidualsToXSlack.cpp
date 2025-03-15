//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// assignResidualsToXSlack.cpp
//
// Code generation for function 'assignResidualsToXSlack'
//

// Include files
#include "assignResidualsToXSlack.h"
#include "addBoundToActiveSetMatrix_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo xi_emlrtRSI{
    1,                         // lineNo
    "assignResidualsToXSlack", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/assignResidualsToXSlack.p" // pathName
};

static emlrtBCInfo fe_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    1,                         // lineNo
    1,                         // colNo
    "",                        // aName
    "assignResidualsToXSlack", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/assignResidualsToXSlack.p", // pName
    0                                     // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace step {
namespace relaxed {
void assignResidualsToXSlack(const emlrtStack &sp, int32_T nVarOrig,
                             d_struct_T &WorkingSet, j_struct_T &b_TrialState,
                             h_struct_T &memspace)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T mEq;
  int32_T mIneq;
  int32_T mLBOrig;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  mIneq = WorkingSet.sizes[2];
  mEq = WorkingSet.sizes[1];
  mLBOrig =
      (WorkingSet.sizes[3] - (WorkingSet.sizes[1] << 1)) - WorkingSet.sizes[2];
  st.site = &xi_emlrtRSI;
  if (WorkingSet.sizes[2] >= 1) {
    n_t = (ptrdiff_t)WorkingSet.sizes[2];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.bineq.data[0], &incx_t,
          &(memspace.workspace_double.data())[0], &incy_t);
  }
  st.site = &xi_emlrtRSI;
  ::coder::internal::blas::xgemv(nVarOrig, WorkingSet.sizes[2],
                                 WorkingSet.Aineq, WorkingSet.ldA,
                                 b_TrialState.xstar, memspace.workspace_double);
  st.site = &xi_emlrtRSI;
  if (WorkingSet.sizes[2] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  i = static_cast<uint8_T>(WorkingSet.sizes[2]);
  for (int32_T idx{0}; idx < i; idx++) {
    i1 = memspace.workspace_double.size(0);
    i2 = memspace.workspace_double.size(1);
    i1 *= i2;
    if (idx + 1 > i1) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &fe_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i1 = b_TrialState.xstar.size(0);
    i2 = (nVarOrig + idx) + 1;
    if ((i2 < 1) || (i2 > i1)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fe_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_TrialState.xstar[i2 - 1] =
        static_cast<real_T>(memspace.workspace_double[idx] > 0.0) *
        memspace.workspace_double[idx];
  }
  st.site = &xi_emlrtRSI;
  if (WorkingSet.sizes[1] >= 1) {
    n_t = (ptrdiff_t)WorkingSet.sizes[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &WorkingSet.beq.data[0], &incx_t,
          &(memspace.workspace_double.data())[0], &incy_t);
  }
  st.site = &xi_emlrtRSI;
  ::coder::internal::blas::xgemv(nVarOrig, WorkingSet.sizes[1], WorkingSet.Aeq,
                                 WorkingSet.ldA, b_TrialState.xstar,
                                 memspace.workspace_double);
  st.site = &xi_emlrtRSI;
  if (WorkingSet.sizes[1] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < mEq; idx++) {
    real_T d;
    int32_T idx_negative;
    int32_T idx_positive;
    idx_positive = (mIneq + idx) + 1;
    idx_negative = ((mIneq + mEq) + idx) + 1;
    i = memspace.workspace_double.size(0) * memspace.workspace_double.size(1);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &fe_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    d = memspace.workspace_double[idx];
    if (d <= 0.0) {
      i1 = b_TrialState.xstar.size(0);
      i2 = nVarOrig + idx_positive;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_TrialState.xstar[i2 - 1] = 0.0;
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i1 = b_TrialState.xstar.size(0);
      i2 = nVarOrig + idx_negative;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_TrialState.xstar[i2 - 1] = -d;
      st.site = &xi_emlrtRSI;
      b_st.site = &oi_emlrtRSI;
      qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
          b_st, WorkingSet, mLBOrig + idx_positive);
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (d >= -1.8967E-5) {
        st.site = &xi_emlrtRSI;
        b_st.site = &oi_emlrtRSI;
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            b_st, WorkingSet, mLBOrig + idx_negative);
      }
    } else {
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i1 = b_TrialState.xstar.size(0);
      i2 = nVarOrig + idx_positive;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_TrialState.xstar[i2 - 1] = d;
      i1 = b_TrialState.xstar.size(0);
      i2 = nVarOrig + idx_negative;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_TrialState.xstar[i2 - 1] = 0.0;
      st.site = &xi_emlrtRSI;
      b_st.site = &oi_emlrtRSI;
      qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
          b_st, WorkingSet, mLBOrig + idx_negative);
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &fe_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (d <= 1.8967E-5) {
        st.site = &xi_emlrtRSI;
        b_st.site = &oi_emlrtRSI;
        qpactiveset::WorkingSet::addBoundToActiveSetMatrix_(
            b_st, WorkingSet, mLBOrig + idx_positive);
      }
    }
  }
}

} // namespace relaxed
} // namespace step
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (assignResidualsToXSlack.cpp)
