//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// linspace.cpp
//
// Code generation for function 'linspace'
//

// Include files
#include "linspace.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo wb_emlrtRTEI{
    49,                                                                // lineNo
    20,                                                                // colNo
    "linspace",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/linspace.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void linspace(const emlrtStack &sp, real_T d2, real_T n,
              ::coder::array<real_T, 2U> &y)
{
  real_T delta1;
  delta1 = muDoubleScalarFloor(n);
  y.set_size(&wb_emlrtRTEI, &sp, 1, static_cast<int32_T>(delta1));
  if (static_cast<int32_T>(delta1) >= 1) {
    int32_T y_tmp;
    y_tmp = static_cast<int32_T>(delta1) - 1;
    y[static_cast<int32_T>(delta1) - 1] = d2;
    if (y.size(1) >= 2) {
      y[0] = 0.0;
      if (y.size(1) >= 3) {
        if (-d2 == 0.0) {
          delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
          for (int32_T k{2}; k <= y_tmp; k++) {
            y[k - 1] = static_cast<real_T>(((k << 1) - y.size(1)) - 1) * delta1;
          }
          if ((y.size(1) & 1) == 1) {
            y[y.size(1) >> 1] = 0.0;
          }
        } else if ((d2 < 0.0) &&
                   (muDoubleScalarAbs(d2) > 8.9884656743115785E+307)) {
          delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
          y_tmp = y.size(1);
          for (int32_T k{0}; k <= y_tmp - 3; k++) {
            y[k + 1] = delta1 * (static_cast<real_T>(k) + 1.0);
          }
        } else {
          delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
          y_tmp = y.size(1);
          for (int32_T k{0}; k <= y_tmp - 3; k++) {
            y[k + 1] = (static_cast<real_T>(k) + 1.0) * delta1;
          }
        }
      }
    }
  }
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (linspace.cpp)
