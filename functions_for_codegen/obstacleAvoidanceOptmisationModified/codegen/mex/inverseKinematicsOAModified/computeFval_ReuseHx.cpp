//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeFval_ReuseHx.cpp
//
// Code generation for function 'computeFval_ReuseHx'
//

// Include files
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo hh_emlrtRSI{
    1,                     // lineNo
    "computeFval_ReuseHx", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval_ReuseHx.p" // pathName
};

static emlrtBCInfo kd_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    1,                     // lineNo
    1,                     // colNo
    "",                    // aName
    "computeFval_ReuseHx", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeFval_ReuseHx.p", // pName
    0                                   // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
real_T computeFval_ReuseHx(const emlrtStack &sp, const g_struct_T &obj,
                           array<real_T, 2U> &workspace,
                           const array<real_T, 1U> &f,
                           const array<real_T, 1U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T val;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj.objtype) {
  case 5:
    if ((obj.nvar < 1) || (obj.nvar > x.size(0))) {
      emlrtDynamicBoundsCheckR2012b(obj.nvar, 1, x.size(0), &kd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    val = obj.gammaScalar * x[obj.nvar - 1];
    break;
  case 3: {
    if (obj.hasLinear) {
      int32_T a_tmp;
      a_tmp = obj.nvar;
      st.site = &hh_emlrtRSI;
      if (obj.nvar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T i{0}; i < a_tmp; i++) {
        int32_T b_i;
        int32_T idx;
        idx = workspace.size(0) * workspace.size(1);
        b_i = obj.Hx.size(0);
        if ((i + 1 < 1) || (i + 1 > b_i)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if (i + 1 > f.size(0)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, f.size(0), &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if (i + 1 > idx) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        workspace[i] = 0.5 * obj.Hx[i] + f[i];
      }
      if (obj.nvar < 1) {
        val = 0.0;
      } else {
        n_t = (ptrdiff_t)obj.nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t,
                   &(workspace.data())[0], &incy_t);
      }
    } else {
      if (obj.nvar < 1) {
        val = 0.0;
      } else {
        n_t = (ptrdiff_t)obj.nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t,
                   &(((array<real_T, 1U> *)&obj.Hx)->data())[0], &incy_t);
      }
      val *= 0.5;
    }
  } break;
  default: {
    int32_T maxRegVar_tmp;
    maxRegVar_tmp = obj.maxVar - 1;
    if (obj.hasLinear) {
      int32_T a_tmp;
      int32_T b_i;
      int32_T idx;
      a_tmp = obj.nvar;
      st.site = &hh_emlrtRSI;
      if (obj.nvar > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T i{0}; i < a_tmp; i++) {
        idx = workspace.size(0) * workspace.size(1);
        if ((i + 1 < 1) || (i + 1 > f.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, f.size(0), &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if (i + 1 > idx) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        workspace[i] = f[i];
      }
      a_tmp = (obj.maxVar - obj.nvar) - 1;
      st.site = &hh_emlrtRSI;
      if (a_tmp > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T i{0}; i < a_tmp; i++) {
        idx = workspace.size(0) * workspace.size(1);
        b_i = (obj.nvar + i) + 1;
        if ((b_i < 1) || (b_i > idx)) {
          emlrtDynamicBoundsCheckR2012b(b_i, 1, idx, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        workspace[b_i - 1] = obj.rho;
      }
      st.site = &hh_emlrtRSI;
      if (maxRegVar_tmp > 2147483646) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T i{0}; i < maxRegVar_tmp; i++) {
        idx = workspace.size(0) * workspace.size(1);
        if ((i + 1 < 1) || (i + 1 > idx)) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        b_i = obj.Hx.size(0);
        if (i + 1 > b_i) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, b_i, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if (i + 1 > idx) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, idx, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        workspace[i] = workspace[i] + 0.5 * obj.Hx[i];
      }
      if (maxRegVar_tmp < 1) {
        val = 0.0;
      } else {
        n_t = (ptrdiff_t)(obj.maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t,
                   &(workspace.data())[0], &incy_t);
      }
    } else {
      int32_T a_tmp;
      if (maxRegVar_tmp < 1) {
        val = 0.0;
      } else {
        n_t = (ptrdiff_t)(obj.maxVar - 1);
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        val = ddot(&n_t, &(((array<real_T, 1U> *)&x)->data())[0], &incx_t,
                   &(((array<real_T, 1U> *)&obj.Hx)->data())[0], &incy_t);
      }
      val *= 0.5;
      a_tmp = obj.nvar + 1;
      st.site = &hh_emlrtRSI;
      if ((a_tmp <= maxRegVar_tmp) && (maxRegVar_tmp > 2147483646)) {
        b_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T idx{a_tmp}; idx <= maxRegVar_tmp; idx++) {
        if ((idx < 1) || (idx > x.size(0))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, x.size(0), &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        val += x[idx - 1] * obj.rho;
      }
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

// End of code generation (computeFval_ReuseHx.cpp)
