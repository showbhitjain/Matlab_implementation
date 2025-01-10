//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematics.cpp
//
// Code generation for function 'inverseKinematics'
//

// Include files
#include "inverseKinematics.h"
#include "Hessian_final_link.h"
#include "Jacobi_final_link.h"
#include "anonymous_function.h"
#include "configurableObjective.h"
#include "fmincon.h"
#include "indexShapeCheck.h"
#include "inv.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types1.h"
#include "inverseKinematics_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "svd.h"
#include "xgetrf.h"
#include "blas.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static boolean_T starting_joint_vel_not_empty;

static boolean_T is_first_step_not_empty;

static emlrtRSInfo emlrtRSI{
    30,                  // lineNo
    "inverseKinematics", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/inverseKinematics.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    55,                  // lineNo
    "inverseKinematics", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/inverseKinematics.m" // pathName
};

static emlrtRSInfo
    c_emlrtRSI{
        94,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pathName
    };

static emlrtRSInfo
    d_emlrtRSI{
        69,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pathName
    };

static emlrtRSInfo
    e_emlrtRSI{
        142,      // lineNo
        "mtimes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRSInfo
    g_emlrtRSI{
        178,           // lineNo
        "mtimes_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

static emlrtRSInfo kc_emlrtRSI{
    55, // lineNo
    "@(q_vel)objFun(q_vel,jacobi,xd_eff_vel,starting_joint_vel,joint_values,"
    "config)", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/inverseKinematics.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    3,        // lineNo
    "objFun", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/objFun.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    5,                       // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pathName
};

static emlrtRSInfo oc_emlrtRSI{
    9,                       // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    13,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pathName
};

static emlrtRSInfo qc_emlrtRSI{
    17,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pathName
};

static emlrtRSInfo rc_emlrtRSI{
    21,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pathName
};

static emlrtRSInfo sc_emlrtRSI{
    25,                      // lineNo
    "configurableObjective", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pathName
};

static emlrtRSInfo tc_emlrtRSI{
    44,                                                               // lineNo
    "mpower",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/mpower.m" // pathName
};

static emlrtRSInfo uc_emlrtRSI{
    71,                                                           // lineNo
    "power",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    2,      // lineNo
    "smin", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/smin.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    3,      // lineNo
    "smin", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/smin.m" // pathName
};

static emlrtRSInfo xd_emlrtRSI{
    15,                                                             // lineNo
    "min",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/min.m" // pathName
};

static emlrtRSInfo yd_emlrtRSI{
    46,         // lineNo
    "minOrMax", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo ae_emlrtRSI{
    92,        // lineNo
    "minimum", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo be_emlrtRSI{
    7,                               // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    8,                               // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo de_emlrtRSI{
    11,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo ee_emlrtRSI{
    21,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo fe_emlrtRSI{
    28,                              // lineNo
    "computeManipulabilityJacobian", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/computeManipulabilityJacobian.m" // pathName
};

static emlrtRSInfo ie_emlrtRSI{
    21,                                                            // lineNo
    "det",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/det.m" // pathName
};

static emlrtRTEInfo
    emlrtRTEI{
        133,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

static emlrtRTEInfo
    b_emlrtRTEI{
        138,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

static emlrtRTEInfo g_emlrtRTEI{
    13,                                                            // lineNo
    9,                                                             // colNo
    "sqrt",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

static emlrtRTEInfo
    h_emlrtRTEI{
        134,             // lineNo
        27,              // colNo
        "unaryMinOrMax", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" // pName
    };

static emlrtECInfo emlrtECI{
    1,                       // nDims
    17,                      // lineNo
    49,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pName
};

static emlrtECInfo b_emlrtECI{
    1,                       // nDims
    13,                      // lineNo
    50,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    3,        // lineNo
    44,       // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/objFun.m", // pName
    0                     // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    3,        // lineNo
    42,       // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/objFun.m", // pName
    0                     // checkKind
};

static emlrtRTEInfo t_emlrtRTEI{
    18,                  // lineNo
    5,                   // colNo
    "inverseKinematics", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/inverseKinematics.m" // pName
};

static emlrtRTEInfo
    u_emlrtRTEI{
        218,      // lineNo
        20,       // colNo
        "mtimes", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pName
    };

static emlrtRTEInfo v_emlrtRTEI{
    30,                  // lineNo
    1,                   // colNo
    "inverseKinematics", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/inverseKinematics.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    35,                // lineNo
    13,                // colNo
    "function_handle", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    30,                // lineNo
    21,                // colNo
    "function_handle", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    55,                  // lineNo
    2,                   // colNo
    "inverseKinematics", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/inverseKinematics.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    60,                  // lineNo
    1,                   // colNo
    "inverseKinematics", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/inverseKinematics.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    3,        // lineNo
    36,       // colNo
    "objFun", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/objFun.m" // pName
};

static emlrtRTEInfo
    kb_emlrtRTEI{
        31,            // lineNo
        30,            // colNo
        "unsafeSxfun", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
        "unsafeSxfun.m" // pName
    };

static emlrtRTEInfo lb_emlrtRTEI{
    25,                      // lineNo
    75,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pName
};

// Function Definitions
void inverseKinematics(
    const emlrtStack *sp, const coder::array<real_T, 1U> &joint_values,
    const coder::array<real_T, 2U> &jacobi, const real_T xd_eff_vel_data[],
    const int32_T xd_eff_vel_size[1], const coder::array<real_T, 1U> &,
    const coder::array<real_T, 1U> &,
    const coder::array<real_T, 1U> &joint_min_vel,
    const coder::array<real_T, 1U> &joint_max_vel, const struct0_T *config,
    coder::array<real_T, 1U> &optimal_joint_velocity, real_T *Exit_Flag)
{
  static coder::array<real_T, 1U> starting_joint_vel;
  static const real_T A[36]{1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  static boolean_T is_first_step;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  coder::anonymous_function b_this;
  coder::array<real_T, 2U> Aeq;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  int32_T loop_ub;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  //  Assuming 'joint_values' is a column vector
  // total_variables = n_joints + n_slack;  % Total number of variables in the
  // optimization problem
  //  Ensure sizes are compatible for code generation
  //  coder.varsize('starting_joint_vel', [n_joints, 1], [true, false]);
  //  coder.varsize('optimal_joint_velocity', [n_joints, 1], [true, false]);
  //  Initialize 'starting_joint_vel' if it's the first execution or if it's
  //  undefined (starting joint velocity)
  if (covrtLogCond(&emlrtCoverageInstance, 0, 0, 0, !is_first_step_not_empty) ||
      covrtLogCond(&emlrtCoverageInstance, 0, 0, 1,
                   !starting_joint_vel_not_empty)) {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    is_first_step = true;
    is_first_step_not_empty = true;
    starting_joint_vel.set_size(&t_emlrtRTEI, sp, joint_values.size(0));
    loop_ub = joint_values.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      starting_joint_vel[i] = 0.0;
    }
    starting_joint_vel_not_empty = (starting_joint_vel.size(0) != 0);
    //  Default initialization
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, false);
  }
  //  Then, check if it's the first execution step to perform any first-time
  //  setup
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 1, is_first_step)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
    is_first_step = false;
    //  Ensure this block won't execute again
    //  No need to set 'starting_joint_vel' here again if it's already set above
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
  //  Default initializations
  st.site = &emlrtRSI;
  b_st.site = &d_emlrtRSI;
  if (jacobi.size(0) != 6) {
    if ((jacobi.size(0) == 1) && (jacobi.size(1) == 1)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &c_emlrtRSI;
  if (jacobi.size(1) == 0) {
    Aeq.set_size(&v_emlrtRTEI, &b_st, 6, 0);
  } else {
    c_st.site = &e_emlrtRSI;
    d_st.site = &g_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)6;
    n_t = (ptrdiff_t)jacobi.size(1);
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)6;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)6;
    Aeq.set_size(&u_emlrtRTEI, &d_st, 6, jacobi.size(1));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[0],
          &lda_t, &(((coder::array<real_T, 2U> *)&jacobi)->data())[0], &ldb_t,
          &beta1, &(Aeq.data())[0], &ldc_t);
  }
  //  Initial guess should include the slack variables
  //  Initial guess for the decision variable (joint velocities and slack)
  // 'Display','off', ...
  // 'Display', 'iter', ... % Displays each iteration progress
  //  Set up optimization options
  //  Run the optimization
  b_this.workspace.jacobi.set_size(&w_emlrtRTEI, sp, 6, jacobi.size(1));
  loop_ub = 6 * jacobi.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_this.workspace.jacobi[i] = jacobi[i];
  }
  b_this.workspace.xd_eff_vel.size[0] = xd_eff_vel_size[0];
  loop_ub = xd_eff_vel_size[0];
  if (loop_ub - 1 >= 0) {
    std::copy(&xd_eff_vel_data[0], &xd_eff_vel_data[loop_ub],
              &b_this.workspace.xd_eff_vel.data[0]);
  }
  b_this.workspace.starting_joint_vel.set_size(&x_emlrtRTEI, sp,
                                               starting_joint_vel.size(0));
  loop_ub = starting_joint_vel.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_this.workspace.starting_joint_vel[i] = starting_joint_vel[i];
  }
  b_this.workspace.joint_values.set_size(&x_emlrtRTEI, sp,
                                         joint_values.size(0));
  loop_ub = joint_values.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_this.workspace.joint_values[i] = joint_values[i];
  }
  b_this.workspace.config = *config;
  optimal_joint_velocity.set_size(&y_emlrtRTEI, sp, starting_joint_vel.size(0));
  loop_ub = starting_joint_vel.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    optimal_joint_velocity[i] = starting_joint_vel[i];
  }
  st.site = &b_emlrtRSI;
  coder::fmincon(st, b_this, optimal_joint_velocity, Aeq, xd_eff_vel_data,
                 xd_eff_vel_size[0], joint_min_vel, joint_max_vel, Exit_Flag);
  //  Separate the optimal joint velocities and slack variables if slack was
  //  applied
  starting_joint_vel.set_size(&ab_emlrtRTEI, sp,
                              optimal_joint_velocity.size(0));
  loop_ub = optimal_joint_velocity.size(0);
  for (int32_T i{0}; i < loop_ub; i++) {
    starting_joint_vel[i] = optimal_joint_velocity[i];
  }
  starting_joint_vel_not_empty = (starting_joint_vel.size(0) != 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

real_T inverseKinematics_anonFcn1(
    const emlrtStack &sp, const coder::array<real_T, 2U> &jacobi,
    const real_T xd_eff_vel_data[], int32_T xd_eff_vel_size,
    const coder::array<real_T, 1U> &starting_joint_vel,
    const coder::array<real_T, 1U> &joint_values, const struct0_T &config,
    const coder::array<real_T, 1U> &q_vel)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  coder::array<real_T, 2U> b_joint_values;
  coder::array<real_T, 1U> b_q_vel;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T JJt[36];
  real_T inv_JJt[36];
  real_T s_data[6];
  real_T a;
  real_T absx;
  real_T varargout_1;
  int32_T b_iv[2];
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T loop_ub;
  int32_T s_size;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
  st.site = &kc_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  if (joint_values.size(0) < 1) {
    loop_ub = 0;
  } else {
    if (q_vel.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, q_vel.size(0), &d_emlrtBCI, &st);
    }
    if (joint_values.size(0) > q_vel.size(0)) {
      emlrtDynamicBoundsCheckR2012b(joint_values.size(0), 1, q_vel.size(0),
                                    &c_emlrtBCI, &st);
    }
    loop_ub = joint_values.size(0);
  }
  b_iv[0] = 1;
  b_iv[1] = loop_ub;
  b_st.site = &lc_emlrtRSI;
  coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
  b_st.site = &lc_emlrtRSI;
  b_q_vel.set_size(&ib_emlrtRTEI, &b_st, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_q_vel[i] = q_vel[i];
  }
  covrtLogFcn(&emlrtCoverageInstance, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2, 0);
  varargout_1 = 0.0;
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 0, config.useObjective1)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 1);
    c_st.site = &nc_emlrtRSI;
    if (loop_ub == 0) {
      a = 0.0;
    } else {
      a = 0.0;
      for (k = 0; k < loop_ub; k++) {
        absx = muDoubleScalarAbs(q_vel[k]);
        if (muDoubleScalarIsNaN(absx) || (absx > a)) {
          a = absx;
        }
      }
    }
    d_st.site = &tc_emlrtRSI;
    e_st.site = &uc_emlrtRSI;
    varargout_1 = config.weight1 * (a * a) / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 1, config.useObjective2)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 2);
    c_st.site = &oc_emlrtRSI;
    if (loop_ub == 0) {
      a = 0.0;
    } else {
      n_t = (ptrdiff_t)loop_ub;
      incx_t = (ptrdiff_t)1;
      a = dnrm2(&n_t, &(b_q_vel.data())[0], &incx_t);
    }
    d_st.site = &tc_emlrtRSI;
    e_st.site = &uc_emlrtRSI;
    varargout_1 += config.weight2 * (a * a) / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 2, config.useObjective3)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 3);
    c_st.site = &pc_emlrtRSI;
    d_st.site = &d_emlrtRSI;
    if (jacobi.size(1) != loop_ub) {
      if (((jacobi.size(0) == 1) && (jacobi.size(1) == 1)) || (loop_ub == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    d_st.site = &c_emlrtRSI;
    s_size = coder::internal::blas::mtimes(jacobi, b_q_vel, s_data);
    if ((s_size != xd_eff_vel_size) &&
        ((s_size != 1) && (xd_eff_vel_size != 1))) {
      emlrtDimSizeImpxCheckR2021b(s_size, xd_eff_vel_size, &b_emlrtECI, &b_st);
    }
    c_st.site = &pc_emlrtRSI;
    if (s_size == xd_eff_vel_size) {
      b_q_vel.set_size(&jb_emlrtRTEI, &c_st, s_size);
      idx = (s_size / 2) << 1;
      k = idx - 2;
      for (i = 0; i <= k; i += 2) {
        __m128d r;
        __m128d r1;
        r = _mm_loadu_pd(&s_data[i]);
        r1 = _mm_loadu_pd(&xd_eff_vel_data[i]);
        _mm_storeu_pd(&b_q_vel[i], _mm_sub_pd(r, r1));
      }
      for (i = idx; i < s_size; i++) {
        b_q_vel[i] = s_data[i] - xd_eff_vel_data[i];
      }
    } else {
      d_st.site = &pc_emlrtRSI;
      binary_expand_op_1(d_st, b_q_vel, s_data, s_size, xd_eff_vel_data,
                         xd_eff_vel_size);
    }
    if (b_q_vel.size(0) == 0) {
      a = 0.0;
    } else {
      n_t = (ptrdiff_t)b_q_vel.size(0);
      incx_t = (ptrdiff_t)1;
      a = dnrm2(&n_t, &(b_q_vel.data())[0], &incx_t);
    }
    d_st.site = &tc_emlrtRSI;
    e_st.site = &uc_emlrtRSI;
    varargout_1 += config.weight3 * (a * a) / 2.0;
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 3, config.useObjective4)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 4);
    if ((loop_ub != starting_joint_vel.size(0)) &&
        ((loop_ub != 1) && (starting_joint_vel.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(loop_ub, starting_joint_vel.size(0),
                                  &emlrtECI, &b_st);
    }
    c_st.site = &qc_emlrtRSI;
    d_st.site = &uc_emlrtRSI;
    if (loop_ub == starting_joint_vel.size(0)) {
      b_q_vel.set_size(&kb_emlrtRTEI, &b_st, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        absx = q_vel[i] - starting_joint_vel[i];
        b_q_vel[i] = absx * absx;
      }
      c_st.site = &qc_emlrtRSI;
      varargout_1 += config.weight4 * coder::sum(c_st, b_q_vel);
    } else {
      c_st.site = &qc_emlrtRSI;
      varargout_1 = binary_expand_op(c_st, varargout_1, config, qc_emlrtRSI,
                                     q_vel, loop_ub, starting_joint_vel);
    }
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 4, config.useObjective5)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 5);
    c_st.site = &rc_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 3, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 3, 0);
    d_st.site = &id_emlrtRSI;
    s_size = coder::svd(d_st, jacobi, s_data);
    d_st.site = &jd_emlrtRSI;
    e_st.site = &xd_emlrtRSI;
    f_st.site = &yd_emlrtRSI;
    g_st.site = &ae_emlrtRSI;
    if (s_size < 1) {
      emlrtErrorWithMessageIdR2018a(
          &g_st, &h_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    if (s_size <= 2) {
      if (s_size == 1) {
        absx = s_data[0];
      } else if ((s_data[0] > s_data[1]) ||
                 (muDoubleScalarIsNaN(s_data[0]) &&
                  (!muDoubleScalarIsNaN(s_data[1])))) {
        absx = s_data[1];
      } else {
        absx = s_data[0];
      }
    } else {
      if (!muDoubleScalarIsNaN(s_data[0])) {
        idx = 1;
      } else {
        boolean_T exitg1;
        idx = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= s_size)) {
          if (!muDoubleScalarIsNaN(s_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        absx = s_data[0];
      } else {
        absx = s_data[idx - 1];
        i = idx + 1;
        for (k = i; k <= s_size; k++) {
          a = s_data[k - 1];
          if (absx > a) {
            absx = a;
          }
        }
      }
    }
    varargout_1 += config.weight5 / (absx + 1.0);
  }
  if (covrtLogIf(&emlrtCoverageInstance, 2, 0, 5, config.useObjective6)) {
    real_T H[294];
    real_T J[42];
    real_T Jm_transposed[7];
    real_T m;
    int32_T ipiv[6];
    boolean_T isodd;
    covrtLogBasicBlock(&emlrtCoverageInstance, 2, 6);
    c_st.site = &sc_emlrtRSI;
    d_st.site = &sc_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 4, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
    //  Compute the Jacobian and Hessian first
    // [~, J, H] = computeKinematics(joint_values, mdhparams); because of syms
    // was too slow J = Jacobi_final_link1(joint_values); %for code generation
    // H = Hessian_final_link(joint_values); %for code generation
    b_joint_values.set_size(&lb_emlrtRTEI, &d_st, 1, joint_values.size(0));
    idx = joint_values.size(0);
    for (i = 0; i < idx; i++) {
      b_joint_values[i] = joint_values[i];
    }
    e_st.site = &be_emlrtRSI;
    Jacobi_final_link(e_st, b_joint_values, J);
    b_joint_values.set_size(&lb_emlrtRTEI, &d_st, 1, joint_values.size(0));
    idx = joint_values.size(0);
    for (i = 0; i < idx; i++) {
      b_joint_values[i] = joint_values[i];
    }
    e_st.site = &ce_emlrtRSI;
    Hessian_final_link(e_st, b_joint_values, H);
    //  Compute the manipulability measure 'm'
    for (i = 0; i < 6; i++) {
      for (idx = 0; idx < 6; idx++) {
        a = 0.0;
        for (s_size = 0; s_size < 7; s_size++) {
          a += J[i + 6 * s_size] * J[idx + 6 * s_size];
        }
        JJt[i + 6 * idx] = a;
      }
    }
    e_st.site = &de_emlrtRSI;
    std::copy(&JJt[0], &JJt[36], &inv_JJt[0]);
    f_st.site = &ie_emlrtRSI;
    coder::internal::lapack::xgetrf(f_st, inv_JJt, ipiv);
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
    e_st.site = &de_emlrtRSI;
    if (absx < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    m = muDoubleScalarSqrt(absx);
    //  Compute the manipulability Jacobian 'Jm'
    //  Number of joints
    //  Initialize manipulability Jacobian transposed
    //  vec operation implemented as a function for convenience
    //  Pre-compute the inverse of JJt
    e_st.site = &ee_emlrtRSI;
    coder::inv(e_st, JJt, inv_JJt);
    //
    //  Pre-compute the pseudo-inverse of JJt
    // pseudo_inv_JJt = pinv(JJt);
    for (k = 0; k < 7; k++) {
      covrtLogFor(&emlrtCoverageInstance, 4, 0, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 4, 2);
      e_st.site = &fe_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 4, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 4, 1);
      e_st.site = &fe_emlrtRSI;
      covrtLogFcn(&emlrtCoverageInstance, 4, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 4, 1);
      for (i = 0; i < 6; i++) {
        for (idx = 0; idx < 6; idx++) {
          a = 0.0;
          for (s_size = 0; s_size < 7; s_size++) {
            a += J[i + 6 * s_size] * H[(idx + 6 * s_size) + 42 * k];
          }
          JJt[i + 6 * idx] = a;
        }
      }
      absx = 0.0;
      for (i = 0; i < 36; i++) {
        absx += JJt[i] * inv_JJt[i];
      }
      Jm_transposed[k] = m * absx;
      //  Equation (11)
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&d_st);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 4, 0, 0, 0);
    d_st.site = &d_emlrtRSI;
    if (loop_ub != 7) {
      if (loop_ub == 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    absx = 0.0;
    for (i = 0; i < 7; i++) {
      absx += -Jm_transposed[i] * q_vel[i];
    }
    varargout_1 += config.weight6 * absx;
  }
  //  You can add more terms similarly with their checks and weights
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return varargout_1;
}

void inverseKinematics_init()
{
  is_first_step_not_empty = false;
  starting_joint_vel_not_empty = false;
}

// End of code generation (inverseKinematics.cpp)
