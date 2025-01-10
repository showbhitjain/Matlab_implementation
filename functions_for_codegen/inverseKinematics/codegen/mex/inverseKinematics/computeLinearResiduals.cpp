//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeLinearResiduals.cpp
//
// Code generation for function 'computeLinearResiduals'
//

// Include files
#include "computeLinearResiduals.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace internal {
void computeLinearResiduals(const emlrtStack &sp, const array<real_T, 1U> &x,
                            int32_T nVar, real_T workspaceEq_data[],
                            int32_T &workspaceEq_size, int32_T mLinEq,
                            const array<real_T, 1U> &AeqT,
                            const real_T beq_data[], int32_T ldAe)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  array<real_T, 1U> y;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (mLinEq > 0) {
    int32_T loop_ub;
    st.site = &ff_emlrtRSI;
    y.set_size(&rb_emlrtRTEI, &st, workspaceEq_size);
    for (int32_T i{0}; i < workspaceEq_size; i++) {
      y[i] = workspaceEq_data[i];
    }
    n_t = (ptrdiff_t)mLinEq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, (real_T *)&beq_data[0], &incx_t, &(y.data())[0], &incy_t);
    ::coder::internal::blas::xgemv(nVar, mLinEq, AeqT, ldAe, x, y);
    workspaceEq_size = y.size(0);
    loop_ub = y.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      workspaceEq_data[i] = y[i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (computeLinearResiduals.cpp)
