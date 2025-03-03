//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// saveState.cpp
//
// Code generation for function 'saveState'
//

// Include files
#include "saveState.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo uf_emlrtRSI{
    1,           // lineNo
    "saveState", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/saveState.p" // pathName
};

static emlrtBCInfo dc_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    1,           // lineNo
    1,           // colNo
    "",          // aName
    "saveState", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/saveState.p", // pName
    0                          // checkKind
};

static emlrtRTEInfo pd_emlrtRTEI{
    1,           // lineNo
    1,           // colNo
    "saveState", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/saveState.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void saveState(const emlrtStack &sp, j_struct_T &obj)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T nVar;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  obj.sqpFval_old = obj.sqpFval;
  nVar = obj.xstarsqp.size(0);
  st.site = &uf_emlrtRSI;
  if (obj.xstarsqp.size(0) >= 1) {
    n_t = (ptrdiff_t)obj.xstarsqp.size(0);
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(obj.xstarsqp.data())[0], &incx_t,
          &(obj.xstarsqp_old.data())[0], &incy_t);
  }
  st.site = &uf_emlrtRSI;
  if (obj.xstarsqp.size(0) > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T i{0}; i < nVar; i++) {
    b_i = obj.grad.size(0);
    if (i + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &dc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_i = obj.grad_old.size(0);
    if (i + 1 > b_i) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &dc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.grad_old[i] = obj.grad[i];
  }
  st.site = &uf_emlrtRSI;
  if (obj.mIneq >= 1) {
    n_t = (ptrdiff_t)obj.mIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &(obj.cIneq.data())[0], &incx_t, &(obj.cIneq_old.data())[0],
          &incy_t);
  }
  st.site = &uf_emlrtRSI;
  y.set_size(&pd_emlrtRTEI, &st, obj.cEq_old.size[0]);
  nVar = obj.cEq_old.size[0];
  for (b_i = 0; b_i < nVar; b_i++) {
    y[b_i] = obj.cEq_old.data[b_i];
  }
  if (obj.mEq >= 1) {
    n_t = (ptrdiff_t)obj.mEq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &obj.cEq.data[0], &incx_t, &(y.data())[0], &incy_t);
  }
  obj.cEq_old.size[0] = y.size(0);
  nVar = y.size(0);
  for (b_i = 0; b_i < nVar; b_i++) {
    obj.cEq_old.data[b_i] = y[b_i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace TrialState
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (saveState.cpp)
