//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fullColLDL2_.cpp
//
// Code generation for function 'fullColLDL2_'
//

// Include files
#include "fullColLDL2_.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "xger.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo ci_emlrtRSI{
    1,              // lineNo
    "fullColLDL2_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/fullColLDL2_.p" // pathName
};

static emlrtBCInfo id_emlrtBCI{
    -1,             // iFirst
    -1,             // iLast
    1,              // lineNo
    1,              // colNo
    "",             // aName
    "fullColLDL2_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/fullColLDL2_.p", // pName
    0                                        // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void fullColLDL2_(const emlrtStack &sp, e_struct_T &obj, int32_T NColsRemain)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T a;
  int32_T b_k;
  int32_T lastDiag;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  lastDiag = obj.ldm + 1;
  st.site = &ci_emlrtRSI;
  if (NColsRemain > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T k{0}; k < NColsRemain; k++) {
    int32_T LD_diagOffset;
    int32_T subMatrixDim;
    LD_diagOffset = lastDiag * k + 1;
    b_k = obj.FMat.size(0) * obj.FMat.size(1);
    if ((LD_diagOffset < 1) || (LD_diagOffset > b_k)) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    a = obj.FMat[LD_diagOffset - 1];
    if (muDoubleScalarAbs(a) <= obj.regTol_) {
      if (LD_diagOffset > b_k) {
        emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.FMat[LD_diagOffset - 1] = a;
    }
    b_k = obj.FMat.size(0) * obj.FMat.size(1);
    if (LD_diagOffset > b_k) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    subMatrixDim = (NColsRemain - k) - 1;
    st.site = &ci_emlrtRSI;
    b_st.site = &uf_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    if (subMatrixDim > 2147483646) {
      d_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(d_st);
    }
    for (b_k = 0; b_k < subMatrixDim; b_k++) {
      obj.workspace_ = obj.FMat[LD_diagOffset + b_k];
    }
    st.site = &ci_emlrtRSI;
    internal::blas::xger(st, subMatrixDim, subMatrixDim,
                         -1.0 / obj.FMat[LD_diagOffset - 1], obj.workspace_,
                         obj.workspace_, obj.FMat, LD_diagOffset + lastDiag,
                         obj.ldm);
    b_k = obj.FMat.size(0) * obj.FMat.size(1);
    if (LD_diagOffset > b_k) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    a = 1.0 / obj.FMat[LD_diagOffset - 1];
    st.site = &ci_emlrtRSI;
    if (subMatrixDim >= 1) {
      b_st.site = &rb_emlrtRSI;
      c_st.site = &sb_emlrtRSI;
      n_t = (ptrdiff_t)subMatrixDim;
      incx_t = (ptrdiff_t)1;
      dscal(&n_t, &a, &obj.FMat[LD_diagOffset], &incx_t);
    }
  }
  lastDiag = lastDiag * (NColsRemain - 1) + 1;
  b_k = obj.FMat.size(0) * obj.FMat.size(1);
  if ((lastDiag < 1) || (lastDiag > b_k)) {
    emlrtDynamicBoundsCheckR2012b(lastDiag, 1, b_k, &id_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  a = obj.FMat[lastDiag - 1];
  if (muDoubleScalarAbs(a) <= obj.regTol_) {
    if (lastDiag > b_k) {
      emlrtDynamicBoundsCheckR2012b(lastDiag, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.FMat[lastDiag - 1] = a;
  }
}

void fullColLDL2_(const emlrtStack &sp, e_struct_T &obj, int32_T LD_offset,
                  int32_T NColsRemain)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T a;
  int32_T b_k;
  int32_T lastDiag;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  lastDiag = obj.ldm + 1;
  st.site = &ci_emlrtRSI;
  if (NColsRemain > 2147483646) {
    b_st.site = &f_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T k{0}; k < NColsRemain; k++) {
    int32_T LD_diagOffset;
    int32_T subMatrixDim;
    LD_diagOffset = LD_offset + lastDiag * k;
    b_k = obj.FMat.size(0) * obj.FMat.size(1);
    if ((LD_diagOffset < 1) || (LD_diagOffset > b_k)) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    a = obj.FMat[LD_diagOffset - 1];
    if (muDoubleScalarAbs(a) <= obj.regTol_) {
      if (LD_diagOffset > b_k) {
        emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      obj.FMat[LD_diagOffset - 1] = a;
    }
    b_k = obj.FMat.size(0) * obj.FMat.size(1);
    if (LD_diagOffset > b_k) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    subMatrixDim = (NColsRemain - k) - 1;
    st.site = &ci_emlrtRSI;
    b_st.site = &uf_emlrtRSI;
    c_st.site = &y_emlrtRSI;
    if (subMatrixDim > 2147483646) {
      d_st.site = &f_emlrtRSI;
      check_forloop_overflow_error(d_st);
    }
    for (b_k = 0; b_k < subMatrixDim; b_k++) {
      obj.workspace_ = obj.FMat[LD_diagOffset + b_k];
    }
    st.site = &ci_emlrtRSI;
    internal::blas::xger(st, subMatrixDim, subMatrixDim,
                         -1.0 / obj.FMat[LD_diagOffset - 1], obj.workspace_,
                         obj.workspace_, obj.FMat, LD_diagOffset + lastDiag,
                         obj.ldm);
    b_k = obj.FMat.size(0) * obj.FMat.size(1);
    if (LD_diagOffset > b_k) {
      emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    a = 1.0 / obj.FMat[LD_diagOffset - 1];
    st.site = &ci_emlrtRSI;
    if (subMatrixDim >= 1) {
      b_st.site = &rb_emlrtRSI;
      c_st.site = &sb_emlrtRSI;
      n_t = (ptrdiff_t)subMatrixDim;
      incx_t = (ptrdiff_t)1;
      dscal(&n_t, &a, &obj.FMat[LD_diagOffset], &incx_t);
    }
  }
  lastDiag = LD_offset + lastDiag * (NColsRemain - 1);
  b_k = obj.FMat.size(0) * obj.FMat.size(1);
  if ((lastDiag < 1) || (lastDiag > b_k)) {
    emlrtDynamicBoundsCheckR2012b(lastDiag, 1, b_k, &id_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  a = obj.FMat[lastDiag - 1];
  if (muDoubleScalarAbs(a) <= obj.regTol_) {
    if (lastDiag > b_k) {
      emlrtDynamicBoundsCheckR2012b(lastDiag, 1, b_k, &id_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    obj.FMat[lastDiag - 1] = a;
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (fullColLDL2_.cpp)
