//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xpotrf.cpp
//
// Code generation for function 'xpotrf'
//

// Include files
#include "xpotrf.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "lapacke.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    qh_emlrtRSI{
        79,             // lineNo
        "ceval_xpotrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xpotrf.m" // pathName
    };

static emlrtRSInfo
    rh_emlrtRSI{
        13,       // lineNo
        "xpotrf", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xpotrf.m" // pathName
    };

// Function Definitions
namespace coder {
namespace internal {
namespace lapack {
int32_T xpotrf(const emlrtStack &sp, int32_T n, array<real_T, 2U> &A,
               int32_T lda)
{
  static const char_T fname[19]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'p', 'o', 't', 'r', 'f',
                                '_', 'w', 'o', 'r', 'k'};
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &rh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_dpotrf_work(102, 'U', (ptrdiff_t)n, &(A.data())[0],
                               (ptrdiff_t)lda);
  b_st.site = &qh_emlrtRSI;
  if ((int32_T)info_t < 0) {
    if ((int32_T)info_t == -1010) {
      emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
                                    "Coder:toolbox:LAPACKCallErrorInfo",
                                    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                    19, &fname[0], 12, (int32_T)info_t);
    }
  }
  return (int32_T)info_t;
}

} // namespace lapack
} // namespace internal
} // namespace coder

// End of code generation (xpotrf.cpp)
