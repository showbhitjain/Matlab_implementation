//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeGrad_StoreHx.cpp
//
// Code generation for function 'computeGrad_StoreHx'
//

// Include files
#include "computeGrad_StoreHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo gh_emlrtRSI{
    1,                     // lineNo
    "computeGrad_StoreHx", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeGrad_StoreHx.p" // pathName
};

static emlrtBCInfo jd_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    1,                     // lineNo
    1,                     // colNo
    "",                    // aName
    "computeGrad_StoreHx", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+Objective/computeGrad_StoreHx.p", // pName
    0                                   // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace Objective {
void computeGrad_StoreHx(const emlrtStack &sp, g_struct_T &obj,
                         const array<real_T, 2U> &H, const array<real_T, 1U> &f,
                         const array<real_T, 1U> &x)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T a;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  switch (obj.objtype) {
  case 5: {
    int32_T a_tmp;
    int32_T i;
    a_tmp = obj.nvar;
    st.site = &gh_emlrtRSI;
    if (obj.nvar - 1 > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T iy{0}; iy <= a_tmp - 2; iy++) {
      i = obj.grad.size(0);
      if ((iy + 1 < 1) || (iy + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(iy + 1, 1, i, &jd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.grad[iy] = 0.0;
    }
    i = obj.grad.size(0);
    if ((obj.nvar < 1) || (obj.nvar > i)) {
      emlrtDynamicBoundsCheckR2012b(obj.nvar, 1, i, &jd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.grad[obj.nvar - 1] = obj.gammaScalar;
  } break;
  case 3: {
    int32_T a_tmp;
    st.site = &gh_emlrtRSI;
    internal::blas::xgemv(obj.nvar, obj.nvar, H, obj.nvar, x, obj.Hx);
    a_tmp = obj.nvar;
    st.site = &gh_emlrtRSI;
    if (obj.nvar > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T iy{0}; iy < a_tmp; iy++) {
      int32_T i;
      i = obj.Hx.size(0);
      if ((iy + 1 < 1) || (iy + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(iy + 1, 1, i, &jd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = obj.grad.size(0);
      if (iy + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(iy + 1, 1, i, &jd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.grad[iy] = obj.Hx[iy];
    }
    if (obj.hasLinear) {
      st.site = &gh_emlrtRSI;
      if (obj.nvar >= 1) {
        a = 1.0;
        n_t = (ptrdiff_t)obj.nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &a, &(((array<real_T, 1U> *)&f)->data())[0], &incx_t,
              &(obj.grad.data())[0], &incy_t);
      }
    }
  } break;
  default: {
    int32_T a_tmp;
    int32_T i;
    int32_T idx;
    int32_T iy;
    int32_T maxRegVar_tmp;
    maxRegVar_tmp = obj.maxVar - 1;
    st.site = &gh_emlrtRSI;
    internal::blas::xgemv(obj.nvar, obj.nvar, H, obj.nvar, x, obj.Hx);
    a_tmp = obj.nvar + 1;
    st.site = &gh_emlrtRSI;
    if ((a_tmp <= maxRegVar_tmp) && (maxRegVar_tmp > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (idx = a_tmp; idx <= maxRegVar_tmp; idx++) {
      if ((idx < 1) || (idx > x.size(0))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, x.size(0), &jd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = obj.Hx.size(0);
      if (idx > i) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, i, &jd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.Hx[idx - 1] = obj.beta * x[idx - 1];
    }
    st.site = &gh_emlrtRSI;
    for (iy = 0; iy < maxRegVar_tmp; iy++) {
      i = obj.Hx.size(0);
      if ((iy + 1 < 1) || (iy + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(iy + 1, 1, i, &jd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = obj.grad.size(0);
      if (iy + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(iy + 1, 1, i, &jd_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.grad[iy] = obj.Hx[iy];
    }
    if (obj.hasLinear) {
      st.site = &gh_emlrtRSI;
      if (obj.nvar >= 1) {
        a = 1.0;
        n_t = (ptrdiff_t)obj.nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, &a, &(((array<real_T, 1U> *)&f)->data())[0], &incx_t,
              &(obj.grad.data())[0], &incy_t);
      }
    }
    st.site = &gh_emlrtRSI;
    a_tmp = (obj.maxVar - obj.nvar) - 1;
    if (a_tmp >= 1) {
      iy = obj.nvar;
      i = a_tmp - 1;
      a_tmp = (a_tmp / 2) << 1;
      maxRegVar_tmp = a_tmp - 2;
      for (int32_T k{0}; k <= maxRegVar_tmp; k += 2) {
        __m128d r;
        idx = iy + k;
        r = _mm_loadu_pd(&obj.grad[idx]);
        _mm_storeu_pd(&obj.grad[idx], _mm_add_pd(r, _mm_set1_pd(obj.rho)));
      }
      for (int32_T k{a_tmp}; k <= i; k++) {
        idx = iy + k;
        obj.grad[idx] = obj.grad[idx] + obj.rho;
      }
    }
  } break;
  }
}

} // namespace Objective
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeGrad_StoreHx.cpp)
