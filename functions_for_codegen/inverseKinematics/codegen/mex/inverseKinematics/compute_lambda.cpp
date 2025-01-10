//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compute_lambda.cpp
//
// Code generation for function 'compute_lambda'
//

// Include files
#include "compute_lambda.h"
#include "eml_int_forloop_overflow_check.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xtrsv.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo ji_emlrtRSI{
    1,                // lineNo
    "compute_lambda", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_lambda.p" // pathName
};

static emlrtBCInfo jd_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "isNonDegenerate", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "isNonDegenerate.p", // pName
    0                    // checkKind
};

static emlrtBCInfo kd_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "compute_lambda", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_lambda.p", // pName
    0                   // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_lambda(const emlrtStack &sp, array<real_T, 2U> &workspace,
                    i_struct_T &solution, const f_struct_T &objective,
                    const d_struct_T &qrmanager)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T nActiveConstr_tmp;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nActiveConstr_tmp = qrmanager.ncols;
  if (qrmanager.ncols > 0) {
    int32_T i;
    int32_T idx;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective.objtype != 4) {
      real_T tol;
      boolean_T nonDegenerate;
      tol =
          100.0 * static_cast<real_T>(qrmanager.mrows) * 2.2204460492503131E-16;
      st.site = &ji_emlrtRSI;
      if ((qrmanager.mrows > 0) && (qrmanager.ncols > 0)) {
        nonDegenerate = true;
      } else {
        nonDegenerate = false;
      }
      if (nonDegenerate) {
        boolean_T exitg1;
        boolean_T guard2;
        idx = nActiveConstr_tmp;
        guard2 = false;
        if (qrmanager.mrows < qrmanager.ncols) {
          idxQR = qrmanager.mrows + qrmanager.ldq * (qrmanager.ncols - 1);
          exitg1 = false;
          while ((!exitg1) && (idx > qrmanager.mrows)) {
            i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
            if ((idxQR < 1) || (idxQR > i)) {
              emlrtDynamicBoundsCheckR2012b(idxQR, 1, i, &jd_emlrtBCI, &st);
            }
            if (muDoubleScalarAbs(qrmanager.QR[idxQR - 1]) >= tol) {
              idx--;
              idxQR -= qrmanager.ldq;
            } else {
              exitg1 = true;
            }
          }
          nonDegenerate = (idx == qrmanager.mrows);
          if (nonDegenerate) {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }
        if (guard2) {
          idxQR = idx + qrmanager.ldq * (idx - 1);
          exitg1 = false;
          while ((!exitg1) && (idx >= 1)) {
            i = qrmanager.QR.size(0) * qrmanager.QR.size(1);
            if ((idxQR < 1) || (idxQR > i)) {
              emlrtDynamicBoundsCheckR2012b(idxQR, 1, i, &jd_emlrtBCI, &st);
            }
            if (muDoubleScalarAbs(qrmanager.QR[idxQR - 1]) >= tol) {
              idx--;
              idxQR = (idxQR - qrmanager.ldq) - 1;
            } else {
              exitg1 = true;
            }
          }
          nonDegenerate = (idx == 0);
        }
      }
      if (!nonDegenerate) {
        solution.state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      st.site = &ji_emlrtRSI;
      internal::blas::xgemv(qrmanager.mrows, qrmanager.ncols, qrmanager.Q,
                            qrmanager.ldq, objective.grad, workspace);
      st.site = &ji_emlrtRSI;
      internal::blas::xtrsv(qrmanager.ncols, qrmanager.QR, qrmanager.ldq,
                            workspace);
      st.site = &ji_emlrtRSI;
      if (qrmanager.ncols > 2147483646) {
        b_st.site = &f_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      i = workspace.size(0) * workspace.size(1);
      for (idx = 0; idx < nActiveConstr_tmp; idx++) {
        if ((idx + 1 < 1) || (idx + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        idxQR = solution.lambda.size(0);
        if (idx + 1 > idxQR) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, idxQR, &kd_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        solution.lambda[idx] = -workspace[idx];
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compute_lambda.cpp)
