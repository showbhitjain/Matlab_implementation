//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// configurableObjective.cpp
//
// Code generation for function 'configurableObjective'
//

// Include files
#include "configurableObjective.h"
#include "Hessian_final_link.h"
#include "Jacobi_final_link.h"
#include "inv.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "xgetrf.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo
    w_emlrtRSI{
        142,      // lineNo
        "mtimes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRSInfo md_emlrtRSI{
    5,                       // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    9,                       // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    13,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    17,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    21,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo rd_emlrtRSI{
    44,                                                               // lineNo
    "mpower",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/mpower.m" // pathName
};

static emlrtRSInfo sd_emlrtRSI{
    71,                                                           // lineNo
    "power",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

static emlrtRSInfo ud_emlrtRSI{
    7,                               // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo vd_emlrtRSI{
    8,                               // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo wd_emlrtRSI{
    11,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo xd_emlrtRSI{
    21,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo yd_emlrtRSI{
    28,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    21,                                                            // lineNo
    "det",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/det.m" // pathName
};

static emlrtRTEInfo k_emlrtRTEI{
    13,                                                            // lineNo
    9,                                                             // colNo
    "sqrt",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

static emlrtECInfo g_emlrtECI{
    1,                       // nDims
    17,                      // lineNo
    63,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    17,                      // lineNo
    63,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pName
};

// Function Declarations
static void minus(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                  const real_T in2_data[], const int32_T &in2_size,
                  const coder::array<real_T, 1U> &in3);

// Function Definitions
static void minus(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                  const real_T in2_data[], const int32_T &in2_size,
                  const coder::array<real_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2_size;
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(&hb_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2_size != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = in2_data[i * stride_0_0] - in3[i * stride_1_0];
  }
}

real_T configurableObjective(
    const emlrtStack &sp, const real_T current_joint_velocity_data[],
    int32_T current_joint_velocity_size, const real_T jacobi_data[],
    const int32_T jacobi_size[2], const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &starting_joint_vel,
    const real_T joint_values_data[], int32_T joint_values_size,
    const real_T WeightMatrix_data[], const int32_T WeightMatrix_size[2],
    const struct0_T &config)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t n_t;
  coder::array<real_T, 1U> b;
  coder::array<real_T, 1U> b_current_joint_velocity_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T JJt[36];
  real_T inv_JJt[36];
  real_T y_data[12];
  real_T y[6];
  real_T a;
  real_T absx;
  real_T beta1;
  real_T objVal;
  int32_T y_size[2];
  int32_T b_i;
  int32_T i;
  int32_T k;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  covrtLogFcn(&emlrtCoverageInstance, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
  objVal = 0.0;
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 0,
                 config.useObjectiveNormInfinity)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 1);
    st.site = &md_emlrtRSI;
    if (current_joint_velocity_size == 0) {
      a = 0.0;
    } else {
      a = 0.0;
      for (k = 0; k < current_joint_velocity_size; k++) {
        absx = muDoubleScalarAbs(current_joint_velocity_data[k]);
        if (muDoubleScalarIsNaN(absx) || (absx > a)) {
          a = absx;
        }
      }
    }
    b_st.site = &rd_emlrtRSI;
    c_st.site = &sd_emlrtRSI;
    objVal = config.weightNormInfinity * (a * a) / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 1, config.useObjectiveNormL2)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 2);
    st.site = &nd_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    if (current_joint_velocity_size != WeightMatrix_size[0]) {
      if ((current_joint_velocity_size == 1) ||
          ((WeightMatrix_size[0] == 1) && (WeightMatrix_size[1] == 1))) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    b_current_joint_velocity_data.set((real_T *)&current_joint_velocity_data[0],
                                      current_joint_velocity_size);
    b_st.site = &v_emlrtRSI;
    coder::internal::blas::mtimes(b_current_joint_velocity_data,
                                  WeightMatrix_data, WeightMatrix_size, y_data,
                                  y_size);
    st.site = &nd_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    if (current_joint_velocity_size != y_size[1]) {
      if ((y_size[1] == 1) || (current_joint_velocity_size == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    if (y_size[1] < 1) {
      absx = 0.0;
    } else {
      n_t = (ptrdiff_t)y_size[1];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      absx = ddot(&n_t, &y_data[0], &incx_t,
                  (real_T *)&current_joint_velocity_data[0], &incy_t);
    }
    objVal += config.weightNormL2 * absx / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 2,
                 config.useObjectiveTrajectoryFollowing)) {
    real_T scale;
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 3);
    st.site = &od_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    if (current_joint_velocity_size != jacobi_size[1]) {
      if (current_joint_velocity_size == 1) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    b_st.site = &v_emlrtRSI;
    if ((jacobi_size[1] == 0) || (current_joint_velocity_size == 0)) {
      for (b_i = 0; b_i < 6; b_i++) {
        y[b_i] = 0.0;
      }
    } else {
      c_st.site = &w_emlrtRSI;
      TRANSB1 = 'N';
      TRANSA1 = 'N';
      absx = 1.0;
      beta1 = 0.0;
      incx_t = (ptrdiff_t)6;
      n_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)jacobi_size[1];
      lda_t = (ptrdiff_t)6;
      ldb_t = (ptrdiff_t)current_joint_velocity_size;
      ldc_t = (ptrdiff_t)6;
      dgemm(&TRANSA1, &TRANSB1, &incx_t, &n_t, &incy_t, &absx,
            (real_T *)&jacobi_data[0], &lda_t,
            (real_T *)&current_joint_velocity_data[0], &ldb_t, &beta1, &y[0],
            &ldc_t);
    }
    st.site = &od_emlrtRSI;
    a = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 0; k < 6; k++) {
      absx = y[k] - xd_eff_vel[k];
      y[k] = absx;
      absx = muDoubleScalarAbs(absx);
      if (absx > scale) {
        beta1 = scale / absx;
        a = a * beta1 * beta1 + 1.0;
        scale = absx;
      } else {
        beta1 = absx / scale;
        a += beta1 * beta1;
      }
    }
    a = scale * muDoubleScalarSqrt(a);
    b_st.site = &rd_emlrtRSI;
    c_st.site = &sd_emlrtRSI;
    objVal += config.weightTrajectoryFollowing * (a * a) / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 3,
                 config.useObjectiveJointAcceleration)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 4);
    i = starting_joint_vel.size(0);
    if ((current_joint_velocity_size != i) &&
        ((current_joint_velocity_size != 1) && (i != 1))) {
      emlrtDimSizeImpxCheckR2021b(current_joint_velocity_size, i, &g_emlrtECI,
                                  (emlrtConstCTX)&sp);
    }
    if (current_joint_velocity_size == starting_joint_vel.size(0)) {
      b.set_size(&hb_emlrtRTEI, &sp, current_joint_velocity_size);
      k = (current_joint_velocity_size / 2) << 1;
      b_i = k - 2;
      for (i = 0; i <= b_i; i += 2) {
        __m128d r;
        __m128d r1;
        r = _mm_loadu_pd(&current_joint_velocity_data[i]);
        r1 = _mm_loadu_pd(&starting_joint_vel[i]);
        _mm_storeu_pd(&b[i], _mm_sub_pd(r, r1));
      }
      for (i = k; i < current_joint_velocity_size; i++) {
        b[i] = current_joint_velocity_data[i] - starting_joint_vel[i];
      }
    } else {
      st.site = &pd_emlrtRSI;
      minus(st, b, current_joint_velocity_data, current_joint_velocity_size,
            starting_joint_vel);
    }
    st.site = &pd_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    if (b.size(0) != WeightMatrix_size[0]) {
      if ((b.size(0) == 1) ||
          ((WeightMatrix_size[0] == 1) && (WeightMatrix_size[1] == 1))) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    b_st.site = &v_emlrtRSI;
    coder::internal::blas::mtimes(b, WeightMatrix_data, WeightMatrix_size,
                                  y_data, y_size);
    st.site = &pd_emlrtRSI;
    b_st.site = &td_emlrtRSI;
    if (b.size(0) != y_size[1]) {
      if ((y_size[1] == 1) || (b.size(0) == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    if (y_size[1] < 1) {
      absx = 0.0;
    } else {
      n_t = (ptrdiff_t)y_size[1];
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      absx = ddot(&n_t, &y_data[0], &incx_t, &(b.data())[0], &incy_t);
    }
    objVal += config.weightJointAcceleration * absx / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 4,
                 config.useObjectiveManipulability)) {
    real_T H[294];
    real_T J[42];
    real_T Jm_transposed[7];
    int32_T ipiv[6];
    boolean_T isodd;
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 5);
    st.site = &qd_emlrtRSI;
    b_st.site = &qd_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
    //  Compute the Jacobian and Hessian first
    // [~, J, H] = computeKinematics(joint_values, mdhparams); because of syms
    // was too slow J = Jacobi_final_link1(joint_values); %for code generation
    // H = Hessian_final_link(joint_values); %for code generation
    y_size[0] = 1;
    y_size[1] = joint_values_size;
    if (joint_values_size - 1 >= 0) {
      std::copy(&joint_values_data[0], &joint_values_data[joint_values_size],
                &y_data[0]);
    }
    c_st.site = &ud_emlrtRSI;
    Jacobi_final_link(c_st, y_data, y_size, J);
    y_size[0] = 1;
    y_size[1] = joint_values_size;
    if (joint_values_size - 1 >= 0) {
      std::copy(&joint_values_data[0], &joint_values_data[joint_values_size],
                &y_data[0]);
    }
    c_st.site = &vd_emlrtRSI;
    Hessian_final_link(c_st, y_data, y_size, H);
    //  Compute the manipulability measure 'm'
    for (i = 0; i < 6; i++) {
      for (k = 0; k < 6; k++) {
        absx = 0.0;
        for (int32_T i1{0}; i1 < 7; i1++) {
          absx += J[i + 6 * i1] * J[k + 6 * i1];
        }
        JJt[i + 6 * k] = absx;
      }
    }
    c_st.site = &wd_emlrtRSI;
    std::copy(&JJt[0], &JJt[36], &inv_JJt[0]);
    d_st.site = &ce_emlrtRSI;
    coder::internal::lapack::xgetrf(d_st, inv_JJt, ipiv);
    absx = inv_JJt[0];
    isodd = false;
    for (k = 0; k < 5; k++) {
      absx *= inv_JJt[(k + 6 * (k + 1)) + 1];
      if (ipiv[k] > k + 1) {
        isodd = !isodd;
      }
    }
    if (isodd) {
      absx = -absx;
    }
    c_st.site = &wd_emlrtRSI;
    if (absx < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    beta1 = muDoubleScalarSqrt(absx);
    //  Compute the manipulability Jacobian 'Jm'
    //  Number of joints
    //  Initialize manipulability Jacobian transposed
    //  vec operation implemented as a function for convenience
    //  Pre-compute the inverse of JJt
    c_st.site = &xd_emlrtRSI;
    coder::inv(c_st, JJt, inv_JJt);
    //
    //  Pre-compute the pseudo-inverse of JJt
    // pseudo_inv_JJt = pinv(JJt);
    for (b_i = 0; b_i < 7; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 2);
      c_st.site = &yd_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
      c_st.site = &yd_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
      for (i = 0; i < 6; i++) {
        for (k = 0; k < 6; k++) {
          absx = 0.0;
          for (int32_T i1{0}; i1 < 7; i1++) {
            absx += J[i + 6 * i1] * H[(k + 6 * i1) + 42 * b_i];
          }
          JJt[i + 6 * k] = absx;
        }
      }
      absx = 0.0;
      for (i = 0; i < 36; i++) {
        absx += JJt[i] * inv_JJt[i];
      }
      Jm_transposed[b_i] = beta1 * absx;
      //  Equation (11)
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&b_st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 0);
    b_st.site = &td_emlrtRSI;
    if (current_joint_velocity_size != 7) {
      if (current_joint_velocity_size == 1) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    absx = 0.0;
    for (i = 0; i < 7; i++) {
      absx += -Jm_transposed[i] * current_joint_velocity_data[i];
    }
    objVal += config.weightManipulability * absx;
  }
  //  You can add more terms similarly with their checks and weights
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return objVal;
}

// End of code generation (configurableObjective.cpp)
