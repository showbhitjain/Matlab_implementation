//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eul2quat.cpp
//
// Code generation for function 'eul2quat'
//

// Include files
#include "eul2quat.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void eul2quat(const real_T eul_data[], real_T q[4])
{
  __m128d r;
  real_T c_data[3];
  real_T s_data[3];
  real_T b_q_tmp;
  real_T q_tmp;
  r = _mm_loadu_pd(&eul_data[0]);
  r = _mm_div_pd(r, _mm_set1_pd(2.0));
  _mm_storeu_pd(&s_data[0], r);
  _mm_storeu_pd(&c_data[0], r);
  q_tmp = eul_data[2] / 2.0;
  s_data[2] = q_tmp;
  c_data[2] = q_tmp;
  c_data[0] = muDoubleScalarCos(c_data[0]);
  c_data[1] = muDoubleScalarCos(c_data[1]);
  c_data[2] = muDoubleScalarCos(c_data[2]);
  s_data[0] = muDoubleScalarSin(s_data[0]);
  s_data[1] = muDoubleScalarSin(s_data[1]);
  s_data[2] = muDoubleScalarSin(s_data[2]);
  q_tmp = c_data[0] * c_data[1];
  b_q_tmp = s_data[0] * s_data[1];
  q[0] = q_tmp * c_data[2] + b_q_tmp * s_data[2];
  q[1] = q_tmp * s_data[2] - b_q_tmp * c_data[2];
  q_tmp = s_data[0] * c_data[1];
  b_q_tmp = c_data[0] * s_data[1];
  q[2] = b_q_tmp * c_data[2] + q_tmp * s_data[2];
  q[3] = q_tmp * c_data[2] - b_q_tmp * s_data[2];
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (eul2quat.cpp)
