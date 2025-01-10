//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeNumDependentEq_.cpp
//
// Code generation for function 'ComputeNumDependentEq_'
//

// Include files
#include "ComputeNumDependentEq_.h"
#include "computeQ_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo gb_emlrtRSI{
    1,                        // lineNo
    "ComputeNumDependentEq_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/ComputeNumDependentEq_.p" // pathName
};

static emlrtBCInfo ab_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    1,                        // lineNo
    1,                        // colNo
    "",                       // aName
    "ComputeNumDependentEq_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/ComputeNumDependentEq_.p", // pName
    0                                       // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
int32_T ComputeNumDependentEq_(const emlrtStack &sp, d_struct_T &qrmanager,
                               const array<real_T, 1U> &beqf, int32_T mConstr,
                               int32_T nVar)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T tol;
  int32_T i;
  int32_T numDependent;
  int32_T totalRank;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  totalRank = mConstr - nVar;
  numDependent = muIntScalarMax_sint32(0, totalRank);
  st.site = &gb_emlrtRSI;
  if (nVar > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (totalRank = 0; totalRank < nVar; totalRank++) {
    i = qrmanager.jpvt.size(0);
    if ((totalRank + 1 < 1) || (totalRank + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(totalRank + 1, 1, i, &ab_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    qrmanager.jpvt[totalRank] = 0;
  }
  st.site = &gb_emlrtRSI;
  if (mConstr * nVar == 0) {
    qrmanager.mrows = mConstr;
    qrmanager.ncols = nVar;
    qrmanager.minRowCol = 0;
  } else {
    qrmanager.usedPivoting = true;
    qrmanager.mrows = mConstr;
    qrmanager.ncols = nVar;
    qrmanager.minRowCol = muIntScalarMin_sint32(mConstr, nVar);
    b_st.site = &hb_emlrtRSI;
    internal::lapack::xgeqp3(b_st, qrmanager.QR, mConstr, nVar, qrmanager.jpvt,
                             qrmanager.tau);
  }
  tol = 100.0 * static_cast<real_T>(nVar) * 2.2204460492503131E-16;
  totalRank = muIntScalarMin_sint32(nVar, mConstr);
  totalRank += qrmanager.ldq * (totalRank - 1);
  exitg1 = false;
  while ((!exitg1) && (totalRank > 0)) {
    i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
    if (totalRank > i) {
      emlrtDynamicBoundsCheckR2012b(totalRank, 1, i, &ab_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if (muDoubleScalarAbs(qrmanager.QR[totalRank - 1]) < tol) {
      totalRank = (totalRank - qrmanager.ldq) - 1;
      numDependent++;
    } else {
      exitg1 = true;
    }
  }
  if (numDependent > 0) {
    st.site = &gb_emlrtRSI;
    b_st.site = &bc_emlrtRSI;
    QRManager::computeQ_(b_st, qrmanager, qrmanager.mrows);
    st.site = &gb_emlrtRSI;
    if (numDependent > 2147483646) {
      b_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    totalRank = 0;
    exitg1 = false;
    while ((!exitg1) && (totalRank <= numDependent - 1)) {
      real_T x;
      if (mConstr < 1) {
        x = 0.0;
      } else {
        n_t = (ptrdiff_t)mConstr;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        x = ddot(&n_t,
                 &qrmanager.Q[qrmanager.ldq * ((mConstr - totalRank) - 1)],
                 &incx_t, &(((array<real_T, 1U> *)&beqf)->data())[0], &incy_t);
      }
      if (muDoubleScalarAbs(x) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        totalRank++;
      }
    }
  }
  return numDependent;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (ComputeNumDependentEq_.cpp)
