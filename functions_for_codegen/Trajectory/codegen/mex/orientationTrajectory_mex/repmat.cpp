//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void repmat(const emlrtStack &sp, const ::coder::array<real_T, 2U> &a,
            ::coder::array<real_T, 2U> &b)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T ncols;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b.set_size(&ed_emlrtRTEI, &sp, 3, a.size(1));
  ncols = a.size(1);
  st.site = &sf_emlrtRSI;
  if (a.size(1) > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T jcol{0}; jcol < ncols; jcol++) {
    int32_T ibmat;
    ibmat = jcol * 3;
    b[ibmat] = a[jcol];
    b[ibmat + 1] = a[jcol];
    b[ibmat + 2] = a[jcol];
  }
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (repmat.cpp)
