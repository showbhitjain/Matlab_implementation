//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// solve1.cpp
//
// Code generation for function 'solve1'
//

// Include files
#include "solve1.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void solve(const emlrtStack &sp, const f_struct_T &obj, array<real_T, 1U> &rhs)
{
  ptrdiff_t incx_t;
  ptrdiff_t lda_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  char_T DIAGA1;
  char_T TRANSA1;
  char_T UPLO1;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &di_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj.ndims >= 1) {
    DIAGA1 = 'U';
    TRANSA1 = 'N';
    UPLO1 = 'L';
    n_t = (ptrdiff_t)obj.ndims;
    lda_t = (ptrdiff_t)obj.ldm;
    incx_t = (ptrdiff_t)1;
    dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t,
          &(((array<real_T, 2U> *)&obj.FMat)->data())[0], &lda_t,
          &(rhs.data())[0], &incx_t);
  }
  b = obj.ndims;
  st.site = &di_emlrtRSI;
  if (obj.ndims > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T idx{0}; idx < b; idx++) {
    int32_T i;
    int32_T i1;
    i = rhs.size(0);
    if ((idx + 1 < 1) || (idx + 1 > i)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &qd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    i = obj.FMat.size(0) * obj.FMat.size(1);
    i1 = (idx + obj.ldm * idx) + 1;
    if ((i1 < 1) || (i1 > i)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i, &qd_emlrtBCI, (emlrtConstCTX)&sp);
    }
    i = rhs.size(0);
    if (idx + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &qd_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    rhs[idx] = rhs[idx] / obj.FMat[i1 - 1];
  }
  st.site = &di_emlrtRSI;
  if (obj.ndims >= 1) {
    DIAGA1 = 'U';
    TRANSA1 = 'T';
    UPLO1 = 'L';
    n_t = (ptrdiff_t)obj.ndims;
    lda_t = (ptrdiff_t)obj.ldm;
    incx_t = (ptrdiff_t)1;
    dtrsv(&UPLO1, &TRANSA1, &DIAGA1, &n_t,
          &(((array<real_T, 2U> *)&obj.FMat)->data())[0], &lda_t,
          &(rhs.data())[0], &incx_t);
  }
}

} // namespace DynamicRegCholManager
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (solve1.cpp)
