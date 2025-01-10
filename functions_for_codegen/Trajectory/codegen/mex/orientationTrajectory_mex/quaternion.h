//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// quaternion.h
//
// Code generation for function 'quaternion'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace trajectoryGeneration {
namespace coder {
class c_quaternion;

}
} // namespace trajectoryGeneration

// Type Definitions
namespace trajectoryGeneration {
namespace coder {
class quaternion {
public:
  quaternion slerp(const emlrtStack &sp, const quaternion q2) const;
  quaternion quaternionBase_slerp(const emlrtStack &sp,
                                  const quaternion q2) const;
  quaternion slerp(const emlrtStack &sp, const quaternion q2, real_T t) const;
  void init();
  void normalize(const emlrtStack &sp);
  void b_log(const emlrtStack &sp);
  void parenReference(const emlrtStack &sp, c_quaternion &o) const;
  void parenAssign(const emlrtStack &sp, const c_quaternion rhs);
  real_T a;
  real_T b;
  real_T c;
  real_T d;
};

class b_quaternion {
public:
  void compact(const emlrtStack &sp, ::coder::array<real_T, 2U> &m) const;
  ::coder::array<real_T, 1U> a;
  ::coder::array<real_T, 1U> b;
  ::coder::array<real_T, 1U> c;
  ::coder::array<real_T, 1U> d;
};

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (quaternion.h)
