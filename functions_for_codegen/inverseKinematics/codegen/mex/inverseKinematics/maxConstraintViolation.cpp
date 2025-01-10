//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// maxConstraintViolation.cpp
//
// Code generation for function 'maxConstraintViolation'
//

// Include files
#include "maxConstraintViolation.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo yg_emlrtRSI{
    1,                        // lineNo
    "maxConstraintViolation", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation.p" // pathName
};

static emlrtRSInfo ah_emlrtRSI{
    1,                                           // lineNo
    "maxConstraintViolation_AMats_regularized_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_regularized_.p" // pathName
};

static emlrtRSInfo bh_emlrtRSI{
    1,                                              // lineNo
    "maxConstraintViolation_AMats_nonregularized_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_nonregularized_.p" // pathName
};

static emlrtBCInfo ic_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    1,                                           // lineNo
    1,                                           // colNo
    "",                                          // aName
    "maxConstraintViolation_AMats_regularized_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_regularized_.p", // pName
    0                                                          // checkKind
};

static emlrtBCInfo jc_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    1,                        // lineNo
    1,                        // colNo
    "",                       // aName
    "maxConstraintViolation", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation.p", // pName
    0                                       // checkKind
};

static emlrtBCInfo kc_emlrtBCI{
    -1,                                             // iFirst
    -1,                                             // iLast
    1,                                              // lineNo
    1,                                              // colNo
    "",                                             // aName
    "maxConstraintViolation_AMats_nonregularized_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/maxConstraintViolation_AMats_nonregularized_.p", // pName
    0                                                             // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
real_T maxConstraintViolation(const emlrtStack &sp, j_struct_T &obj,
                              const array<real_T, 2U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T mEq;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mLB = obj.sizes[3];
  mUB = obj.sizes[4];
  mFixed = obj.sizes[0];
  if (obj.probType == 2) {
    st.site = &yg_emlrtRSI;
    v = 0.0;
    mEq = obj.sizes[1];
    if (obj.Aeq.size(0) != 0) {
      int32_T offsetEq2;
      b_st.site = &ah_emlrtRSI;
      if (obj.sizes[1] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.beq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      b_st.site = &ah_emlrtRSI;
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      offsetEq2 = obj.nVarOrig + obj.sizes[1];
      b_st.site = &ah_emlrtRSI;
      if (obj.sizes[1] > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < mEq; idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        i = x.size(0) * x.size(1);
        i1 = (obj.nVarOrig + idx) + 1;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ic_emlrtBCI, &st);
        }
        i2 = (offsetEq2 + idx) + 1;
        if ((i2 < 1) || (i2 > i)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ic_emlrtBCI, &st);
        }
        i = obj.maxConstrWorkspace.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        obj.maxConstrWorkspace[idx] =
            (obj.maxConstrWorkspace[idx] - x[i1 - 1]) + x[i2 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        v = muDoubleScalarMax(v,
                              muDoubleScalarAbs(obj.maxConstrWorkspace[idx]));
      }
    }
  } else {
    st.site = &yg_emlrtRSI;
    v = 0.0;
    mEq = obj.sizes[1];
    if (obj.Aeq.size(0) != 0) {
      b_st.site = &bh_emlrtRSI;
      if (obj.sizes[1] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.beq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      b_st.site = &bh_emlrtRSI;
      internal::blas::xgemv(obj.nVar, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      b_st.site = &bh_emlrtRSI;
      if (obj.sizes[1] > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < mEq; idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &kc_emlrtBCI, &st);
        }
        v = muDoubleScalarMax(v,
                              muDoubleScalarAbs(obj.maxConstrWorkspace[idx]));
      }
    }
  }
  if (obj.sizes[3] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[3] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = x.size(0) * x.size(1);
    i1 = obj.indexLB.size(0);
    i2 = obj.lb.size(0);
    for (int32_T idx{0}; idx < mLB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i1)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      mEq = obj.indexLB[idx] - 1;
      if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexLB[idx], 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i2)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexLB[idx], 1, i2, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v, -x[mEq] - obj.lb[mEq]);
    }
  }
  if (obj.sizes[4] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[4] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = x.size(0) * x.size(1);
    i1 = obj.indexUB.size(0);
    i2 = obj.ub.size(0);
    for (int32_T idx{0}; idx < mUB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i1)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      mEq = obj.indexUB[idx] - 1;
      if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexUB[idx], 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i2)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexUB[idx], 1, i2, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v, x[mEq] - obj.ub[mEq]);
    }
  }
  if (obj.sizes[0] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[0] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = x.size(0) * x.size(1);
    i1 = obj.indexFixed.size(0);
    i2 = obj.ub.size(0);
    for (int32_T idx{0}; idx < mFixed; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i1)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexFixed[idx], 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i2)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexFixed[idx], 1, i2, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v,
                            muDoubleScalarAbs(x[obj.indexFixed[idx] - 1] -
                                              obj.ub[obj.indexFixed[idx] - 1]));
    }
  }
  return v;
}

real_T maxConstraintViolation(const emlrtStack &sp, j_struct_T &obj,
                              const array<real_T, 2U> &x, int32_T ix0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T mEq;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mLB = obj.sizes[3];
  mUB = obj.sizes[4];
  mFixed = obj.sizes[0];
  if (obj.probType == 2) {
    st.site = &yg_emlrtRSI;
    v = 0.0;
    mEq = obj.sizes[1];
    if (obj.Aeq.size(0) != 0) {
      int32_T offsetEq2;
      b_st.site = &ah_emlrtRSI;
      if (obj.sizes[1] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.beq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      b_st.site = &ah_emlrtRSI;
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            ix0, obj.maxConstrWorkspace);
      offsetEq2 = (obj.nVarOrig + obj.sizes[1]) - 1;
      b_st.site = &ah_emlrtRSI;
      if (obj.sizes[1] > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < mEq; idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        i = x.size(0) * x.size(1);
        i1 = (ix0 + obj.nVarOrig) + idx;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ic_emlrtBCI, &st);
        }
        i2 = ((ix0 + offsetEq2) + idx) + 1;
        if ((i2 < 1) || (i2 > i)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ic_emlrtBCI, &st);
        }
        i = obj.maxConstrWorkspace.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        obj.maxConstrWorkspace[idx] =
            (obj.maxConstrWorkspace[idx] - x[i1 - 1]) + x[i2 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        v = muDoubleScalarMax(v,
                              muDoubleScalarAbs(obj.maxConstrWorkspace[idx]));
      }
    }
  } else {
    st.site = &yg_emlrtRSI;
    v = 0.0;
    mEq = obj.sizes[1];
    if (obj.Aeq.size(0) != 0) {
      b_st.site = &bh_emlrtRSI;
      if (obj.sizes[1] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.beq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      b_st.site = &bh_emlrtRSI;
      internal::blas::xgemv(obj.nVar, obj.sizes[1], obj.Aeq, obj.ldA, x, ix0,
                            obj.maxConstrWorkspace);
      b_st.site = &bh_emlrtRSI;
      if (obj.sizes[1] > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < mEq; idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &kc_emlrtBCI, &st);
        }
        v = muDoubleScalarMax(v,
                              muDoubleScalarAbs(obj.maxConstrWorkspace[idx]));
      }
    }
  }
  if (obj.sizes[3] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[3] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = obj.indexLB.size(0);
    i1 = x.size(0) * x.size(1);
    i2 = obj.lb.size(0);
    for (int32_T idx{0}; idx < mLB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      mEq = (ix0 + obj.indexLB[idx]) - 1;
      if ((mEq < 1) || (mEq > i1)) {
        emlrtDynamicBoundsCheckR2012b(mEq, 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i2)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexLB[idx], 1, i2, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v, -x[mEq - 1] - obj.lb[obj.indexLB[idx] - 1]);
    }
  }
  if (obj.sizes[4] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[4] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = obj.indexUB.size(0);
    i1 = x.size(0) * x.size(1);
    i2 = obj.ub.size(0);
    for (int32_T idx{0}; idx < mUB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      mEq = (ix0 + obj.indexUB[idx]) - 1;
      if ((mEq < 1) || (mEq > i1)) {
        emlrtDynamicBoundsCheckR2012b(mEq, 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i2)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexUB[idx], 1, i2, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v, x[mEq - 1] - obj.ub[obj.indexUB[idx] - 1]);
    }
  }
  if (obj.sizes[0] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[0] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = obj.indexFixed.size(0);
    i1 = x.size(0) * x.size(1);
    i2 = obj.ub.size(0);
    for (int32_T idx{0}; idx < mFixed; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      mEq = (ix0 + obj.indexFixed[idx]) - 1;
      if ((mEq < 1) || (mEq > i1)) {
        emlrtDynamicBoundsCheckR2012b(mEq, 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i2)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexFixed[idx], 1, i2, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(
          v, muDoubleScalarAbs(x[mEq - 1] - obj.ub[obj.indexFixed[idx] - 1]));
    }
  }
  return v;
}

real_T maxConstraintViolation(const emlrtStack &sp, j_struct_T &obj,
                              const array<real_T, 1U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T v;
  int32_T i;
  int32_T i1;
  int32_T mEq;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  mLB = obj.sizes[3];
  mUB = obj.sizes[4];
  mFixed = obj.sizes[0];
  if (obj.probType == 2) {
    st.site = &yg_emlrtRSI;
    v = 0.0;
    mEq = obj.sizes[1];
    if (obj.Aeq.size(0) != 0) {
      int32_T offsetEq2;
      b_st.site = &ah_emlrtRSI;
      if (obj.sizes[1] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.beq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      b_st.site = &ah_emlrtRSI;
      internal::blas::xgemv(obj.nVarOrig, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      offsetEq2 = obj.nVarOrig + obj.sizes[1];
      b_st.site = &ah_emlrtRSI;
      if (obj.sizes[1] > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < mEq; idx++) {
        int32_T i2;
        i = obj.maxConstrWorkspace.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        i = (obj.nVarOrig + idx) + 1;
        if ((i < 1) || (i > x.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, x.size(0), &ic_emlrtBCI, &st);
        }
        i1 = (offsetEq2 + idx) + 1;
        if ((i1 < 1) || (i1 > x.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, x.size(0), &ic_emlrtBCI, &st);
        }
        i2 = obj.maxConstrWorkspace.size(0);
        if (idx + 1 > i2) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i2, &ic_emlrtBCI, &st);
        }
        obj.maxConstrWorkspace[idx] =
            (obj.maxConstrWorkspace[idx] - x[i - 1]) + x[i1 - 1];
        i = obj.maxConstrWorkspace.size(0);
        if (idx + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ic_emlrtBCI, &st);
        }
        v = muDoubleScalarMax(v,
                              muDoubleScalarAbs(obj.maxConstrWorkspace[idx]));
      }
    }
  } else {
    st.site = &yg_emlrtRSI;
    v = 0.0;
    mEq = obj.sizes[1];
    if (obj.Aeq.size(0) != 0) {
      b_st.site = &bh_emlrtRSI;
      if (obj.sizes[1] >= 1) {
        n_t = (ptrdiff_t)obj.sizes[1];
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &obj.beq.data[0], &incx_t,
              &(obj.maxConstrWorkspace.data())[0], &incy_t);
      }
      b_st.site = &bh_emlrtRSI;
      internal::blas::xgemv(obj.nVar, obj.sizes[1], obj.Aeq, obj.ldA, x,
                            obj.maxConstrWorkspace);
      b_st.site = &bh_emlrtRSI;
      if (obj.sizes[1] > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T idx{0}; idx < mEq; idx++) {
        i = obj.maxConstrWorkspace.size(0);
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &kc_emlrtBCI, &st);
        }
        v = muDoubleScalarMax(v,
                              muDoubleScalarAbs(obj.maxConstrWorkspace[idx]));
      }
    }
  }
  if (obj.sizes[3] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[3] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = obj.indexLB.size(0);
    i1 = obj.lb.size(0);
    for (int32_T idx{0}; idx < mLB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      mEq = obj.indexLB[idx] - 1;
      if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > x.size(0))) {
        emlrtDynamicBoundsCheckR2012b(obj.indexLB[idx], 1, x.size(0),
                                      &jc_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((obj.indexLB[idx] < 1) || (obj.indexLB[idx] > i1)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexLB[idx], 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v, -x[mEq] - obj.lb[mEq]);
    }
  }
  if (obj.sizes[4] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[4] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = obj.indexUB.size(0);
    i1 = obj.ub.size(0);
    for (int32_T idx{0}; idx < mUB; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      mEq = obj.indexUB[idx] - 1;
      if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > x.size(0))) {
        emlrtDynamicBoundsCheckR2012b(obj.indexUB[idx], 1, x.size(0),
                                      &jc_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((obj.indexUB[idx] < 1) || (obj.indexUB[idx] > i1)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexUB[idx], 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v, x[mEq] - obj.ub[mEq]);
    }
  }
  if (obj.sizes[0] > 0) {
    st.site = &yg_emlrtRSI;
    if (obj.sizes[0] > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    i = obj.indexFixed.size(0);
    i1 = obj.ub.size(0);
    for (int32_T idx{0}; idx < mFixed; idx++) {
      if ((idx + 1 < 1) || (idx + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > x.size(0))) {
        emlrtDynamicBoundsCheckR2012b(obj.indexFixed[idx], 1, x.size(0),
                                      &jc_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if ((obj.indexFixed[idx] < 1) || (obj.indexFixed[idx] > i1)) {
        emlrtDynamicBoundsCheckR2012b(obj.indexFixed[idx], 1, i1, &jc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      v = muDoubleScalarMax(v,
                            muDoubleScalarAbs(x[obj.indexFixed[idx] - 1] -
                                              obj.ub[obj.indexFixed[idx] - 1]));
    }
  }
  return v;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (maxConstraintViolation.cpp)
