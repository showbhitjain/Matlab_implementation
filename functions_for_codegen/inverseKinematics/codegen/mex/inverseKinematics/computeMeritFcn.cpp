//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeMeritFcn.cpp
//
// Code generation for function 'computeMeritFcn'
//

// Include files
#include "computeMeritFcn.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace MeritFunction {
real_T computeMeritFcn(real_T obj_penaltyParam, real_T fval,
                       const real_T Ceq_workspace_data[], int32_T mEq,
                       boolean_T evalWellDefined)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T val;
  if (evalWellDefined) {
    real_T constrViolationEq;
    if (mEq < 1) {
      constrViolationEq = 0.0;
    } else {
      n_t = (ptrdiff_t)mEq;
      incx_t = (ptrdiff_t)1;
      constrViolationEq =
          dasum(&n_t, (real_T *)&Ceq_workspace_data[0], &incx_t);
    }
    val = fval + obj_penaltyParam * constrViolationEq;
  } else {
    val = rtInf;
  }
  return val;
}

} // namespace MeritFunction
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeMeritFcn.cpp)
