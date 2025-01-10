//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// squareQ_appendCol.cpp
//
// Code generation for function 'squareQ_appendCol'
//

// Include files
#include "squareQ_appendCol.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo lh_emlrtRSI{
    1,                   // lineNo
    "squareQ_appendCol", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "squareQ_appendCol.p" // pathName
};

static emlrtBCInfo yc_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    1,                   // lineNo
    1,                   // colNo
    "",                  // aName
    "squareQ_appendCol", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "squareQ_appendCol.p", // pName
    0                      // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace QRManager {
void squareQ_appendCol(const emlrtStack &sp, d_struct_T &obj,
                       const array<real_T, 1U> &vec, int32_T iv0)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T beta1;
  real_T c;
  real_T s;
  real_T temp;
  int32_T Qk0;
  int32_T i;
  char_T TRANSA;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  Qk0 = obj.ncols + 1;
  obj.minRowCol = muIntScalarMin_sint32(obj.mrows, Qk0);
  st.site = &lh_emlrtRSI;
  if (obj.mrows >= 1) {
    b_st.site = &tb_emlrtRSI;
    temp = 1.0;
    beta1 = 0.0;
    TRANSA = 'T';
    m_t = (ptrdiff_t)obj.mrows;
    n_t = (ptrdiff_t)obj.mrows;
    lda_t = (ptrdiff_t)obj.ldq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dgemv(&TRANSA, &m_t, &n_t, &temp, &(obj.Q.data())[0], &lda_t,
          (real_T *)&vec[iv0 - 1], &incx_t, &beta1,
          &obj.QR[obj.ldq * obj.ncols], &incy_t);
  }
  obj.ncols = Qk0;
  i = obj.jpvt.size(0);
  if ((obj.ncols < 1) || (obj.ncols > i)) {
    emlrtDynamicBoundsCheckR2012b(obj.ncols, 1, i, &yc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  i = obj.ncols - 1;
  obj.jpvt[i] = obj.ncols;
  for (int32_T idx{obj.mrows}; idx > obj.ncols; idx--) {
    int32_T n;
    st.site = &lh_emlrtRSI;
    Qk0 = obj.QR.size(0) * obj.QR.size(1);
    n = idx + obj.ldq * i;
    if ((n - 1 < 1) || (n - 1 > Qk0)) {
      emlrtDynamicBoundsCheckR2012b(n - 1, 1, Qk0, &yc_emlrtBCI, &st);
    }
    beta1 = obj.QR[n - 2];
    Qk0 = obj.QR.size(0) * obj.QR.size(1);
    if ((n < 1) || (n > Qk0)) {
      emlrtDynamicBoundsCheckR2012b(n, 1, Qk0, &yc_emlrtBCI, &st);
    }
    temp = obj.QR[n - 1];
    b_st.site = &vd_emlrtRSI;
    c = 0.0;
    s = 0.0;
    drotg(&beta1, &temp, &c, &s);
    Qk0 = obj.QR.size(0) * obj.QR.size(1);
    if ((n - 1 < 1) || (n - 1 > Qk0)) {
      emlrtDynamicBoundsCheckR2012b(n - 1, 1, Qk0, &yc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.QR[n - 2] = beta1;
    Qk0 = obj.QR.size(0) * obj.QR.size(1);
    if (n > Qk0) {
      emlrtDynamicBoundsCheckR2012b(n, 1, Qk0, &yc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.QR[n - 1] = temp;
    Qk0 = obj.ldq * (idx - 2);
    st.site = &lh_emlrtRSI;
    n = obj.mrows;
    if (obj.mrows >= 1) {
      int32_T iy;
      iy = obj.ldq + Qk0;
      b_st.site = &mh_emlrtRSI;
      if (obj.mrows > 2147483646) {
        c_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(c_st);
      }
      for (int32_T k{0}; k < n; k++) {
        int32_T b_temp_tmp;
        int32_T temp_tmp;
        temp_tmp = iy + k;
        b_temp_tmp = Qk0 + k;
        temp = c * obj.Q[b_temp_tmp] + s * obj.Q[temp_tmp];
        obj.Q[temp_tmp] = c * obj.Q[temp_tmp] - s * obj.Q[b_temp_tmp];
        obj.Q[b_temp_tmp] = temp;
      }
    }
  }
}

} // namespace QRManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (squareQ_appendCol.cpp)
