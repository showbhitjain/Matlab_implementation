//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// compute_deltax.cpp
//
// Code generation for function 'compute_deltax'
//

// Include files
#include "compute_deltax.h"
#include "eml_int_forloop_overflow_check.h"
#include "factor.h"
#include "factor1.h"
#include "fullColLDL2_.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types.h"
#include "partialColLDL3_.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "solve1.h"
#include "xgemm.h"
#include "xgemv.h"
#include "xpotrf.h"
#include "xtrsv.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo
    rc_emlrtRSI{
        91,           // lineNo
        "xgemv_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" // pathName
    };

static emlrtRSInfo nh_emlrtRSI{
    1,                // lineNo
    "compute_deltax", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_deltax.p" // pathName
};

static emlrtRSInfo
    ci_emlrtRSI{
        1,       // lineNo
        "solve", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+CholManager/"
        "solve.p" // pathName
    };

static emlrtRSInfo ei_emlrtRSI{
    1,                         // lineNo
    "computeProjectedHessian", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "computeProjectedHessian.p" // pathName
};

static emlrtRSInfo fi_emlrtRSI{
    1,                                     // lineNo
    "computeProjectedHessian_regularized", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/computeProjectedHessian_regularized.p" // pathName
};

static emlrtRSInfo gi_emlrtRSI{
    1,        // lineNo
    "factor", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_deltax.p" // pathName
};

static emlrtRSInfo hi_emlrtRSI{
    1,       // lineNo
    "solve", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_deltax.p" // pathName
};

static emlrtBCInfo od_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "compute_deltax", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "compute_deltax.p", // pName
    0                   // checkKind
};

static emlrtBCInfo pd_emlrtBCI{
    -1,                                    // iFirst
    -1,                                    // iLast
    1,                                     // lineNo
    1,                                     // colNo
    "",                                    // aName
    "computeProjectedHessian_regularized", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/+step/"
    "+relaxed/computeProjectedHessian_regularized.p", // pName
    0                                                 // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_deltax(const emlrtStack &sp, const array<real_T, 2U> &H,
                    j_struct_T &solution, h_struct_T &memspace,
                    const e_struct_T &qrmanager, f_struct_T &cholmanager,
                    const g_struct_T &objective, boolean_T alwaysPositiveDef)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  int32_T mNull_tmp;
  int32_T order;
  char_T TRANSA;
  char_T TRANSA1;
  char_T UPLO1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  order = qrmanager.mrows;
  mNull_tmp = qrmanager.mrows - qrmanager.ncols;
  if (mNull_tmp <= 0) {
    st.site = &nh_emlrtRSI;
    if (qrmanager.mrows > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T LDimSizeP1{0}; LDimSizeP1 < order; LDimSizeP1++) {
      int32_T i;
      i = solution.searchDir.size(0);
      if ((LDimSizeP1 + 1 < 1) || (LDimSizeP1 + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(LDimSizeP1 + 1, 1, i, &od_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      solution.searchDir[LDimSizeP1] = 0.0;
    }
  } else {
    int32_T LDimSizeP1;
    int32_T i;
    st.site = &nh_emlrtRSI;
    if (qrmanager.mrows > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (LDimSizeP1 = 0; LDimSizeP1 < order; LDimSizeP1++) {
      i = objective.grad.size(0);
      if ((LDimSizeP1 + 1 < 1) || (LDimSizeP1 + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(LDimSizeP1 + 1, 1, i, &od_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      i = solution.searchDir.size(0);
      if (LDimSizeP1 + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(LDimSizeP1 + 1, 1, i, &od_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      solution.searchDir[LDimSizeP1] = -objective.grad[LDimSizeP1];
    }
    if (qrmanager.ncols <= 0) {
      switch (objective.objtype) {
      case 5:
        break;
      case 3:
        st.site = &nh_emlrtRSI;
        if (alwaysPositiveDef) {
          b_st.site = &nh_emlrtRSI;
          CholManager::factor(b_st, cholmanager, H, qrmanager.mrows,
                              qrmanager.mrows);
        } else {
          b_st.site = &nh_emlrtRSI;
          DynamicRegCholManager::factor(b_st, cholmanager, H, qrmanager.mrows,
                                        qrmanager.mrows);
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else {
          st.site = &nh_emlrtRSI;
          if (alwaysPositiveDef) {
            b_st.site = &nh_emlrtRSI;
            CholManager::solve(cholmanager, solution.searchDir);
          } else {
            b_st.site = &nh_emlrtRSI;
            DynamicRegCholManager::solve(b_st, cholmanager, solution.searchDir);
          }
        }
        break;
      default: {
        if (alwaysPositiveDef) {
          st.site = &nh_emlrtRSI;
          b_st.site = &nh_emlrtRSI;
          CholManager::factor(b_st, cholmanager, H, objective.nvar,
                              objective.nvar);
          if (cholmanager.info != 0) {
            solution.state = -6;
          } else {
            int32_T k;
            st.site = &nh_emlrtRSI;
            b_st.site = &nh_emlrtRSI;
            CholManager::solve(cholmanager, solution.searchDir);
            st.site = &nh_emlrtRSI;
            k = qrmanager.mrows - objective.nvar;
            alpha1 = 1.0 / objective.beta;
            if (k >= 1) {
              b_st.site = &oc_emlrtRSI;
              c_st.site = &pc_emlrtRSI;
              n_t = (ptrdiff_t)k;
              incx_t = (ptrdiff_t)1;
              dscal(&n_t, &alpha1, &solution.searchDir[objective.nvar],
                    &incx_t);
            }
          }
        }
      } break;
      }
    } else {
      int32_T nullStartIdx_tmp;
      nullStartIdx_tmp = qrmanager.ldq * qrmanager.ncols + 1;
      if (objective.objtype == 5) {
        st.site = &nh_emlrtRSI;
        if (mNull_tmp > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        i = qrmanager.Q.size(0) * qrmanager.Q.size(1);
        for (LDimSizeP1 = 0; LDimSizeP1 < mNull_tmp; LDimSizeP1++) {
          int32_T LD_diagOffset;
          int32_T i1;
          i1 = order + qrmanager.ldq * (qrmanager.ncols + LDimSizeP1);
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &od_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          LD_diagOffset = memspace.workspace_double.size(0) *
                          memspace.workspace_double.size(1);
          if (LDimSizeP1 + 1 > LD_diagOffset) {
            emlrtDynamicBoundsCheckR2012b(LDimSizeP1 + 1, 1, LD_diagOffset,
                                          &od_emlrtBCI, (emlrtConstCTX)&sp);
          }
          memspace.workspace_double[LDimSizeP1] = -qrmanager.Q[i1 - 1];
        }
        st.site = &nh_emlrtRSI;
        internal::blas::xgemv(qrmanager.mrows, mNull_tmp, qrmanager.Q,
                              nullStartIdx_tmp, qrmanager.ldq,
                              memspace.workspace_double, solution.searchDir);
      } else {
        int32_T LD_diagOffset;
        int32_T i1;
        int32_T k;
        if (objective.objtype == 3) {
          st.site = &nh_emlrtRSI;
          b_st.site = &ei_emlrtRSI;
          internal::blas::xgemm(qrmanager.mrows, mNull_tmp, qrmanager.mrows, H,
                                qrmanager.mrows, qrmanager.Q, nullStartIdx_tmp,
                                qrmanager.ldq, memspace.workspace_double,
                                memspace.workspace_double.size(0));
          b_st.site = &ei_emlrtRSI;
          internal::blas::xgemm(mNull_tmp, mNull_tmp, qrmanager.mrows,
                                qrmanager.Q, nullStartIdx_tmp, qrmanager.ldq,
                                memspace.workspace_double,
                                memspace.workspace_double.size(0),
                                cholmanager.FMat, cholmanager.ldm);
        } else if (alwaysPositiveDef) {
          k = objective.nvar + 1;
          st.site = &nh_emlrtRSI;
          b_st.site = &fi_emlrtRSI;
          internal::blas::xgemm(objective.nvar, mNull_tmp, objective.nvar, H,
                                objective.nvar, qrmanager.Q, nullStartIdx_tmp,
                                qrmanager.ldq, memspace.workspace_double,
                                memspace.workspace_double.size(0));
          b_st.site = &fi_emlrtRSI;
          if (mNull_tmp > 2147483646) {
            c_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(c_st);
          }
          for (LD_diagOffset = 0; LD_diagOffset < mNull_tmp; LD_diagOffset++) {
            b_st.site = &fi_emlrtRSI;
            if ((k <= order) && (order > 2147483646)) {
              c_st.site = &o_emlrtRSI;
              check_forloop_overflow_error(c_st);
            }
            for (LDimSizeP1 = k; LDimSizeP1 <= order; LDimSizeP1++) {
              i = qrmanager.Q.size(0);
              if ((LDimSizeP1 < 1) || (LDimSizeP1 > i)) {
                emlrtDynamicBoundsCheckR2012b(LDimSizeP1, 1, i, &pd_emlrtBCI,
                                              &st);
              }
              i = qrmanager.Q.size(1);
              i1 = (LD_diagOffset + qrmanager.ncols) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &pd_emlrtBCI, &st);
              }
              i = memspace.workspace_double.size(0);
              if (LDimSizeP1 > i) {
                emlrtDynamicBoundsCheckR2012b(LDimSizeP1, 1, i, &pd_emlrtBCI,
                                              &st);
              }
              i = memspace.workspace_double.size(1);
              if (LD_diagOffset + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(LD_diagOffset + 1, 1, i,
                                              &pd_emlrtBCI, &st);
              }
              memspace.workspace_double[(LDimSizeP1 +
                                         memspace.workspace_double.size(0) *
                                             LD_diagOffset) -
                                        1] =
                  objective.beta *
                  qrmanager
                      .Q[(LDimSizeP1 + qrmanager.Q.size(0) * (i1 - 1)) - 1];
            }
          }
          b_st.site = &fi_emlrtRSI;
          internal::blas::xgemm(mNull_tmp, mNull_tmp, qrmanager.mrows,
                                qrmanager.Q, nullStartIdx_tmp, qrmanager.ldq,
                                memspace.workspace_double,
                                memspace.workspace_double.size(0),
                                cholmanager.FMat, cholmanager.ldm);
        }
        st.site = &nh_emlrtRSI;
        if (alwaysPositiveDef) {
          b_st.site = &gi_emlrtRSI;
          cholmanager.ndims = mNull_tmp;
          c_st.site = &oh_emlrtRSI;
          cholmanager.info = internal::lapack::xpotrf(
              c_st, mNull_tmp, cholmanager.FMat, cholmanager.ldm);
        } else {
          b_st.site = &gi_emlrtRSI;
          LDimSizeP1 = cholmanager.ldm + 1;
          cholmanager.ndims = mNull_tmp;
          n_t = (ptrdiff_t)mNull_tmp;
          incx_t = (ptrdiff_t)(cholmanager.ldm + 1);
          n_t = idamax(&n_t, &(cholmanager.FMat.data())[0], &incx_t);
          i = cholmanager.FMat.size(0) * cholmanager.FMat.size(1);
          i1 = (int32_T)n_t + cholmanager.ldm * ((int32_T)n_t - 1);
          if ((i1 < 1) || (i1 > i)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i, &nd_emlrtBCI, &b_st);
          }
          cholmanager.regTol_ = muDoubleScalarMax(
              muDoubleScalarAbs(
                  cholmanager.FMat[((int32_T)n_t +
                                    cholmanager.ldm * ((int32_T)n_t - 1)) -
                                   1]) *
                  2.2204460492503131E-16,
              0.0);
          if ((cholmanager.FMat.size(0) * cholmanager.FMat.size(1) > 16384) &&
              (mNull_tmp > 128)) {
            boolean_T exitg1;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < mNull_tmp)) {
              LD_diagOffset = LDimSizeP1 * k + 1;
              order = mNull_tmp - k;
              if (k + 48 <= mNull_tmp) {
                c_st.site = &sh_emlrtRSI;
                DynamicRegCholManager::partialColLDL3_(c_st, cholmanager,
                                                       LD_diagOffset, order);
                k += 48;
              } else {
                c_st.site = &sh_emlrtRSI;
                DynamicRegCholManager::fullColLDL2_(c_st, cholmanager,
                                                    LD_diagOffset, order);
                exitg1 = true;
              }
            }
          } else {
            c_st.site = &sh_emlrtRSI;
            DynamicRegCholManager::fullColLDL2_(c_st, cholmanager, mNull_tmp);
          }
          if (cholmanager.ConvexCheck) {
            c_st.site = &sh_emlrtRSI;
            if (mNull_tmp > 2147483646) {
              d_st.site = &o_emlrtRSI;
              check_forloop_overflow_error(d_st);
            }
            LDimSizeP1 = 0;
            int32_T exitg2;
            do {
              exitg2 = 0;
              if (LDimSizeP1 <= mNull_tmp - 1) {
                i = cholmanager.FMat.size(0) * cholmanager.FMat.size(1);
                i1 = (LDimSizeP1 + cholmanager.ldm * LDimSizeP1) + 1;
                if ((i1 < 1) || (i1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(i1, 1, i, &nd_emlrtBCI, &b_st);
                }
                if (cholmanager.FMat[i1 - 1] <= 0.0) {
                  cholmanager.info = -(LDimSizeP1 + 1);
                  exitg2 = 1;
                } else {
                  LDimSizeP1++;
                }
              } else {
                cholmanager.ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }
        if (cholmanager.info != 0) {
          solution.state = -6;
        } else {
          st.site = &nh_emlrtRSI;
          if (qrmanager.mrows >= 1) {
            b_st.site = &qc_emlrtRSI;
            c_st.site = &rc_emlrtRSI;
            alpha1 = -1.0;
            beta1 = 0.0;
            TRANSA = 'T';
            m_t = (ptrdiff_t)qrmanager.mrows;
            n_t = (ptrdiff_t)mNull_tmp;
            lda_t = (ptrdiff_t)qrmanager.ldq;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)1;
            dgemv(&TRANSA, &m_t, &n_t, &alpha1,
                  (real_T *)&qrmanager.Q[nullStartIdx_tmp - 1], &lda_t,
                  &(((array<real_T, 1U> *)&objective.grad)->data())[0], &incx_t,
                  &beta1, &(memspace.workspace_double.data())[0], &incy_t);
          }
          st.site = &nh_emlrtRSI;
          if (alwaysPositiveDef) {
            b_st.site = &hi_emlrtRSI;
            c_st.site = &ci_emlrtRSI;
            if (cholmanager.ndims >= 1) {
              TRANSA = 'N';
              TRANSA1 = 'T';
              UPLO1 = 'U';
              n_t = (ptrdiff_t)cholmanager.ndims;
              lda_t = (ptrdiff_t)cholmanager.ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &(cholmanager.FMat.data())[0], &lda_t,
                    &(memspace.workspace_double.data())[0], &incx_t);
            }
            c_st.site = &ci_emlrtRSI;
            internal::blas::xtrsv(cholmanager.ndims, cholmanager.FMat,
                                  cholmanager.ldm, memspace.workspace_double);
          } else {
            b_st.site = &hi_emlrtRSI;
            c_st.site = &di_emlrtRSI;
            if (cholmanager.ndims >= 1) {
              TRANSA = 'U';
              TRANSA1 = 'N';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager.ndims;
              lda_t = (ptrdiff_t)cholmanager.ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &(cholmanager.FMat.data())[0], &lda_t,
                    &(memspace.workspace_double.data())[0], &incx_t);
            }
            k = cholmanager.ndims;
            c_st.site = &di_emlrtRSI;
            if (cholmanager.ndims > 2147483646) {
              d_st.site = &o_emlrtRSI;
              check_forloop_overflow_error(d_st);
            }
            for (LDimSizeP1 = 0; LDimSizeP1 < k; LDimSizeP1++) {
              i = memspace.workspace_double.size(0) *
                  memspace.workspace_double.size(1);
              if ((LDimSizeP1 + 1 < 1) || (LDimSizeP1 + 1 > i)) {
                emlrtDynamicBoundsCheckR2012b(LDimSizeP1 + 1, 1, i,
                                              &qd_emlrtBCI, &b_st);
              }
              i1 = cholmanager.FMat.size(0) * cholmanager.FMat.size(1);
              LD_diagOffset = (LDimSizeP1 + cholmanager.ldm * LDimSizeP1) + 1;
              if ((LD_diagOffset < 1) || (LD_diagOffset > i1)) {
                emlrtDynamicBoundsCheckR2012b(LD_diagOffset, 1, i1,
                                              &qd_emlrtBCI, &b_st);
              }
              if (LDimSizeP1 + 1 > i) {
                emlrtDynamicBoundsCheckR2012b(LDimSizeP1 + 1, 1, i,
                                              &qd_emlrtBCI, &b_st);
              }
              memspace.workspace_double[LDimSizeP1] =
                  memspace.workspace_double[LDimSizeP1] /
                  cholmanager.FMat[LD_diagOffset - 1];
            }
            c_st.site = &di_emlrtRSI;
            if (cholmanager.ndims >= 1) {
              TRANSA = 'U';
              TRANSA1 = 'T';
              UPLO1 = 'L';
              n_t = (ptrdiff_t)cholmanager.ndims;
              lda_t = (ptrdiff_t)cholmanager.ldm;
              incx_t = (ptrdiff_t)1;
              dtrsv(&UPLO1, &TRANSA1, &TRANSA, &n_t,
                    &(cholmanager.FMat.data())[0], &lda_t,
                    &(memspace.workspace_double.data())[0], &incx_t);
            }
          }
          st.site = &nh_emlrtRSI;
          internal::blas::xgemv(qrmanager.mrows, mNull_tmp, qrmanager.Q,
                                nullStartIdx_tmp, qrmanager.ldq,
                                memspace.workspace_double, solution.searchDir);
        }
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (compute_deltax.cpp)
