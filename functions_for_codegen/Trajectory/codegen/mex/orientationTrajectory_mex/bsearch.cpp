//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// bsearch.cpp
//
// Code generation for function 'bsearch'
//

// Include files
#include "bsearch.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
namespace internal {
int32_T b_bsearch(const ::coder::array<real_T, 2U> &x, real_T xi)
{
  int32_T high_i;
  int32_T low_ip1;
  int32_T n;
  high_i = x.size(1);
  n = 1;
  low_ip1 = 2;
  while (high_i > low_ip1) {
    int32_T mid_i;
    mid_i = (n >> 1) + (high_i >> 1);
    if (((n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }
    if (xi >= x[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }
  return n;
}

} // namespace internal
} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (bsearch.cpp)
