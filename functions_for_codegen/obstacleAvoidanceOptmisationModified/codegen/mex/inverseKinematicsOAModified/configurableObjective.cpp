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
static emlrtRSInfo ld_emlrtRSI{
    5,                       // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    9,                       // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    13,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    17,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    21,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    44,                                                               // lineNo
    "mpower",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/mpower.m" // pathName
};

static emlrtRSInfo rd_emlrtRSI{
    71,                                                           // lineNo
    "power",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

static emlrtRSInfo td_emlrtRSI{
    7,                               // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo ud_emlrtRSI{
    8,                               // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo vd_emlrtRSI{
    11,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo wd_emlrtRSI{
    21,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo xd_emlrtRSI{
    28,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo be_emlrtRSI{
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

static emlrtRTEInfo dd_emlrtRTEI{
    17,                      // lineNo
    63,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pName
};

static emlrtRTEInfo ed_emlrtRTEI{
    21,                      // lineNo
    88,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/configurableObjective.m" // pName
};

// Function Declarations
static void minus(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                  const coder::array<real_T, 1U> &in2,
                  const coder::array<real_T, 1U> &in3);

// Function Definitions
static void minus(const emlrtStack &sp, coder::array<real_T, 1U> &in1,
                  const coder::array<real_T, 1U> &in2,
                  const coder::array<real_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(&dd_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] - in3[i * stride_1_0];
  }
}

real_T configurableObjective(
    const emlrtStack &sp,
    const coder::array<real_T, 1U> &current_joint_velocity,
    const coder::array<real_T, 2U> &jacobi, const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &starting_joint_vel,
    const coder::array<real_T, 1U> &joint_values,
    const coder::array<real_T, 2U> &WeightMatrix, const struct0_T &config)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t n_t;
  coder::array<real_T, 2U> b_y;
  coder::array<real_T, 1U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T JJt[36];
  real_T inv_JJt[36];
  real_T y[6];
  real_T a;
  real_T absx;
  real_T beta1;
  real_T objVal;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T vectorUB;
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
    st.site = &ld_emlrtRSI;
    if (current_joint_velocity.size(0) == 0) {
      a = 0.0;
    } else {
      a = 0.0;
      i = current_joint_velocity.size(0);
      for (k = 0; k < i; k++) {
        absx = muDoubleScalarAbs(current_joint_velocity[k]);
        if (muDoubleScalarIsNaN(absx) || (absx > a)) {
          a = absx;
        }
      }
    }
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    objVal = config.weightNormInfinity * (a * a) / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 1, config.useObjectiveNormL2)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 2);
    st.site = &md_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    if (current_joint_velocity.size(0) != WeightMatrix.size(0)) {
      if ((current_joint_velocity.size(0) == 1) ||
          ((WeightMatrix.size(0) == 1) && (WeightMatrix.size(1) == 1))) {
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
    coder::internal::blas::mtimes(b_st, current_joint_velocity, WeightMatrix,
                                  b_y);
    st.site = &md_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    if (current_joint_velocity.size(0) != b_y.size(1)) {
      if ((b_y.size(1) == 1) || (current_joint_velocity.size(0) == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    if (b_y.size(1) < 1) {
      absx = 0.0;
    } else {
      n_t = (ptrdiff_t)b_y.size(1);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      absx = ddot(
          &n_t, &b_y[0], &incx_t,
          &(((coder::array<real_T, 1U> *)&current_joint_velocity)->data())[0],
          &incy_t);
    }
    objVal += config.weightNormL2 * absx / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 2,
                 config.useObjectiveTrajectoryFollowing)) {
    real_T scale;
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 3);
    st.site = &nd_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    if (current_joint_velocity.size(0) != jacobi.size(1)) {
      if (current_joint_velocity.size(0) == 1) {
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
    if ((jacobi.size(1) == 0) || (current_joint_velocity.size(0) == 0)) {
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
      incy_t = (ptrdiff_t)jacobi.size(1);
      lda_t = (ptrdiff_t)6;
      ldb_t = (ptrdiff_t)current_joint_velocity.size(0);
      ldc_t = (ptrdiff_t)6;
      dgemm(&TRANSA1, &TRANSB1, &incx_t, &n_t, &incy_t, &absx,
            &(((coder::array<real_T, 2U> *)&jacobi)->data())[0], &lda_t,
            &(((coder::array<real_T, 1U> *)&current_joint_velocity)->data())[0],
            &ldb_t, &beta1, &y[0], &ldc_t);
    }
    st.site = &nd_emlrtRSI;
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
    b_st.site = &qd_emlrtRSI;
    c_st.site = &rd_emlrtRSI;
    objVal += config.weightTrajectoryFollowing * (a * a) / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 3,
                 config.useObjectiveJointAcceleration)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 4);
    i = current_joint_velocity.size(0);
    vectorUB = starting_joint_vel.size(0);
    if ((i != vectorUB) && ((i != 1) && (vectorUB != 1))) {
      emlrtDimSizeImpxCheckR2021b(i, vectorUB, &g_emlrtECI, (emlrtConstCTX)&sp);
    }
    if (current_joint_velocity.size(0) == starting_joint_vel.size(0)) {
      b.set_size(&dd_emlrtRTEI, &sp, current_joint_velocity.size(0));
      k = current_joint_velocity.size(0);
      b_i = (k / 2) << 1;
      vectorUB = b_i - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        __m128d r;
        __m128d r1;
        r = _mm_loadu_pd(&current_joint_velocity[i]);
        r1 = _mm_loadu_pd(&starting_joint_vel[i]);
        _mm_storeu_pd(&b[i], _mm_sub_pd(r, r1));
      }
      for (i = b_i; i < k; i++) {
        b[i] = current_joint_velocity[i] - starting_joint_vel[i];
      }
    } else {
      st.site = &od_emlrtRSI;
      minus(st, b, current_joint_velocity, starting_joint_vel);
    }
    st.site = &od_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    if (b.size(0) != WeightMatrix.size(0)) {
      if ((b.size(0) == 1) ||
          ((WeightMatrix.size(0) == 1) && (WeightMatrix.size(1) == 1))) {
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
    coder::internal::blas::mtimes(b_st, b, WeightMatrix, b_y);
    st.site = &od_emlrtRSI;
    b_st.site = &sd_emlrtRSI;
    if (b.size(0) != b_y.size(1)) {
      if ((b_y.size(1) == 1) || (b.size(0) == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    if (b_y.size(1) < 1) {
      absx = 0.0;
    } else {
      n_t = (ptrdiff_t)b_y.size(1);
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      absx = ddot(&n_t, &b_y[0], &incx_t, &(b.data())[0], &incy_t);
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
    st.site = &pd_emlrtRSI;
    b_st.site = &pd_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
    //  Compute the Jacobian and Hessian first
    // [~, J, H] = computeKinematics(joint_values, mdhparams); because of syms
    // was too slow J = Jacobi_final_link1(joint_values); %for code generation
    // H = Hessian_final_link(joint_values); %for code generation
    b_y.set_size(&ed_emlrtRTEI, &b_st, 1, joint_values.size(0));
    k = joint_values.size(0);
    for (i = 0; i < k; i++) {
      b_y[i] = joint_values[i];
    }
    c_st.site = &td_emlrtRSI;
    Jacobi_final_link(c_st, b_y, J);
    b_y.set_size(&ed_emlrtRTEI, &b_st, 1, joint_values.size(0));
    k = joint_values.size(0);
    for (i = 0; i < k; i++) {
      b_y[i] = joint_values[i];
    }
    c_st.site = &ud_emlrtRSI;
    Hessian_final_link(c_st, b_y, H);
    //  Compute the manipulability measure 'm'
    for (i = 0; i < 6; i++) {
      for (vectorUB = 0; vectorUB < 6; vectorUB++) {
        absx = 0.0;
        for (k = 0; k < 7; k++) {
          absx += J[i + 6 * k] * J[vectorUB + 6 * k];
        }
        JJt[i + 6 * vectorUB] = absx;
      }
    }
    c_st.site = &vd_emlrtRSI;
    std::copy(&JJt[0], &JJt[36], &inv_JJt[0]);
    d_st.site = &be_emlrtRSI;
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
    c_st.site = &vd_emlrtRSI;
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
    c_st.site = &wd_emlrtRSI;
    coder::inv(c_st, JJt, inv_JJt);
    //
    //  Pre-compute the pseudo-inverse of JJt
    // pseudo_inv_JJt = pinv(JJt);
    for (b_i = 0; b_i < 7; b_i++) {
      covrtLogFor(&emlrtCoverageInstance, 3, 0, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 2);
      c_st.site = &xd_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
      c_st.site = &xd_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 3, 1);
      for (i = 0; i < 6; i++) {
        for (vectorUB = 0; vectorUB < 6; vectorUB++) {
          absx = 0.0;
          for (k = 0; k < 7; k++) {
            absx += J[i + 6 * k] * H[(vectorUB + 6 * k) + 42 * b_i];
          }
          JJt[i + 6 * vectorUB] = absx;
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
    b_st.site = &sd_emlrtRSI;
    if (current_joint_velocity.size(0) != 7) {
      if (current_joint_velocity.size(0) == 1) {
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
      absx += -Jm_transposed[i] * current_joint_velocity[i];
    }
    objVal += config.weightManipulability * absx;
  }
  //  You can add more terms similarly with their checks and weights
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return objVal;
}

// End of code generation (configurableObjective.cpp)
