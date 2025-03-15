//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFval.cpp
//
// Code generation for function 'computeFval'
//

// Include files
#include "computeFval.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "linearForm_.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo ch_emlrtRSI{
    1,             // lineNo
    "computeFval", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval.p" // pathName
};

static emlrtRSInfo eh_emlrtRSI{
    1,                // lineNo
    "linearFormReg_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/linearFormReg_.p" // pathName
};

static emlrtBCInfo cd_emlrtBCI{
    -1,            // iFirst
    -1,            // iLast
    1,             // lineNo
    1,             // colNo
    "",            // aName
    "computeFval", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval.p", // pName
    0                           // checkKind
};

static emlrtBCInfo dd_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "linearFormReg_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/linearFormReg_.p", // pName
    0                              // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
real_T computeFval(const emlrtStack &sp, const g_struct_T &obj,
                   array<real_T, 2U> &workspace, const array<real_T, 2U> &H,
                   const array<real_T, 1U> &f, const array<real_T, 1U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T val;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  switch (obj.objtype) {
  case 5:
    if ((obj.nvar < 1) || (obj.nvar > x.size(0))) {
      emlrtDynamicBoundsCheckR2012b(obj.nvar, 1, x.size(0), &cd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    val = obj.gammaScalar * x[obj.nvar - 1];
    break;
  case 3:
    st.site = &ch_emlrtRSI;
    linearForm_(st, obj.hasLinear, obj.nvar, workspace, H, f, x);
    if (obj.nvar < 1) {
      val = 0.0;
    } else {
      n_t = (ptrdiff_t)obj.nvar;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t,
                 &(workspace.data())[0], &incy_t);
    }
    break;
  default: {
    int32_T a_tmp;
    int32_T b_tmp;
    st.site = &ch_emlrtRSI;
    linearForm_(st, obj.hasLinear, obj.nvar, workspace, H, f, x);
    st.site = &ch_emlrtRSI;
    a_tmp = obj.nvar + 1;
    b_tmp = obj.maxVar - 1;
    b_st.site = &eh_emlrtRSI;
    if ((a_tmp <= b_tmp) && (b_tmp > 2147483646)) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (int32_T idx{a_tmp}; idx <= b_tmp; idx++) {
      int32_T workspace_tmp;
      workspace_tmp = workspace.size(0) * workspace.size(1);
      if ((idx < 1) || (idx > x.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, x.size(0), &dd_emlrtBCI, &st);
      }
      if (idx > workspace_tmp) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, workspace_tmp, &dd_emlrtBCI, &st);
      }
      workspace[idx - 1] = 0.5 * obj.beta * x[idx - 1] + obj.rho;
    }
    if (b_tmp < 1) {
      val = 0.0;
    } else {
      n_t = (ptrdiff_t)(obj.maxVar - 1);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      val = ddot(&n_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t,
                 &(workspace.data())[0], &incy_t);
    }
  } break;
  }
  return val;
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeFval.cpp)
