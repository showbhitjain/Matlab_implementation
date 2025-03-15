//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified.cpp
//
// Code generation for function 'inverseKinematicsOAModified'
//

// Include files
#include "inverseKinematicsOAModified.h"
#include "abs.h"
#include "anonymous_function.h"
#include "configurableObjective.h"
#include "eye.h"
#include "fmincon.h"
#include "indexShapeCheck.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types1.h"
#include "inverseKinematicsOAModified_types.h"
#include "ixfun.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static boolean_T starting_joint_vel_not_empty;

static emlrtRSInfo emlrtRSI{
    61,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    62,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    87,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    96,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    133,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    134,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    148,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    149,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    163,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    169,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    225,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    241,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    15,                                                             // lineNo
    "min",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/min.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    31,         // lineNo
    "minOrMax", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    67,         // lineNo
    "minimum2", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo
    s_emlrtRSI{
        63,               // lineNo
        "binaryMinOrMax", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
        "binaryMinOrMax.m" // pathName
    };

static emlrtRSInfo t_emlrtRSI{
    57,      // lineNo
    "ixfun", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/ixfun.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    102,                          // lineNo
    "binaryImplicitExpansionFun", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/ixfun.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    41,                                                               // lineNo
    "cat",                                                            // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    113,                                                              // lineNo
    "cat_impl",                                                       // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    15,                                                             // lineNo
    "max",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/datafun/max.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    29,         // lineNo
    "minOrMax", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    58,         // lineNo
    "maximum2", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    225, // lineNo
    "@(q_vel)objFun(q_vel,jacobi,xd_eff_vel,starting_joint_vel,joint_values,"
    "jointVelocityWeightMatrix,config,slackIsUsed)", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    6,        // lineNo
    "objFun", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m" // pathName
};

static emlrtRSInfo kd_emlrtRSI{
    8,        // lineNo
    "objFun", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m" // pathName
};

static emlrtRTEInfo emlrtRTEI{
    288,                                                              // lineNo
    27,                                                               // colNo
    "check_non_axis_size",                                            // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    241,                           // lineNo
    46,                            // colNo
    "q_vel_opt",                   // aName
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    241,                           // lineNo
    44,                            // colNo
    "q_vel_opt",                   // aName
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m", // pName
    0                                    // checkKind
};

static emlrtECInfo emlrtECI{
    1,                             // nDims
    149,                           // lineNo
    46,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo b_emlrtECI{
    1,                             // nDims
    148,                           // lineNo
    46,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo c_emlrtECI{
    1,                             // nDims
    134,                           // lineNo
    39,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo d_emlrtECI{
    1,                             // nDims
    133,                           // lineNo
    39,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo e_emlrtECI{
    1,                             // nDims
    62,                            // lineNo
    28,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo f_emlrtECI{
    1,                             // nDims
    61,                            // lineNo
    28,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    64,                            // lineNo
    25,                            // colNo
    "min_dist",                    // aName
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    65,                            // lineNo
    20,                            // colNo
    "In",                          // aName
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    65,                            // lineNo
    22,                            // colNo
    "In",                          // aName
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    66,                            // lineNo
    51,                            // colNo
    "min_dist",                    // aName
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    66,                            // lineNo
    20,                            // colNo
    "bp",                          // aName
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m", // pName
    0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    6,        // lineNo
    42,       // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    6,        // lineNo
    44,       // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    6,        // lineNo
    181,      // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    6,        // lineNo
    192,      // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    6,        // lineNo
    240,      // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    6,        // lineNo
    251,      // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    8,        // lineNo
    42,       // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    8,        // lineNo
    44,       // colNo
    "q_vel",  // aName
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m", // pName
    0               // checkKind
};

static emlrtRTEInfo s_emlrtRTEI{
    25,                            // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    179,                           // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    177,                           // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    30,                // lineNo
    21,                // colNo
    "function_handle", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    241,                           // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    250,                           // lineNo
    5,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo
    gb_emlrtRTEI{
        74,                  // lineNo
        9,                   // colNo
        "eml_mtimes_helper", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

// Function Declarations
static int32_T binary_expand_op(real_T in1_data[], const struct0_T *in2,
                                const real_T in3_data[],
                                const int32_T &in3_size,
                                const real_T in4_data[],
                                const int32_T &in4_size);

static int32_T binary_expand_op_4(real_T in1_data[], const emlrtRSInfo in2,
                                  const real_T in3_data[],
                                  const int32_T &in3_size,
                                  const real_T in4_data[],
                                  const int32_T &in4_size);

// Function Definitions
static int32_T binary_expand_op(real_T in1_data[], const struct0_T *in2,
                                const real_T in3_data[],
                                const int32_T &in3_size,
                                const real_T in4_data[],
                                const int32_T &in4_size)
{
  int32_T in1_size;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in4_size == 1) {
    in1_size = in3_size;
  } else {
    in1_size = in4_size;
  }
  stride_0_0 = (in3_size != 1);
  stride_1_0 = (in4_size != 1);
  for (int32_T i{0}; i < in1_size; i++) {
    in1_data[i] =
        in2->gamma * (in3_data[i * stride_0_0] - in4_data[i * stride_1_0]);
  }
  return in1_size;
}

static int32_T binary_expand_op_4(real_T in1_data[], const emlrtRSInfo,
                                  const real_T in3_data[],
                                  const int32_T &in3_size,
                                  const real_T in4_data[],
                                  const int32_T &in4_size)
{
  real_T b_in3_data[12];
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in4_size == 1) {
    loop_ub = in3_size;
  } else {
    loop_ub = in4_size;
  }
  stride_0_0 = (in3_size != 1);
  stride_1_0 = (in4_size != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in3_data[i] = in3_data[i * stride_0_0] - in4_data[i * stride_1_0];
  }
  return coder::b_abs(b_in3_data, loop_ub, in1_data);
}

real_T c_inverseKinematicsOAModified_a(
    const emlrtStack &sp, const real_T jacobi_data[],
    const int32_T jacobi_size[2], const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &starting_joint_vel,
    const real_T joint_values_data[], int32_T joint_values_size,
    const real_T jointVelocityWeightMatrix_data[],
    const int32_T jointVelocityWeightMatrix_size[2], const struct0_T &config,
    boolean_T slackIsUsed, const coder::array<real_T, 1U> &q_vel)
{
  coder::array<real_T, 2U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b[36];
  real_T varargout_1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 22);
  st.site = &id_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  //  Add the cost for the slack variables
  if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, slackIsUsed)) {
    real_T q_vel_data[12];
    real_T b_y;
    int32_T b_iv[2];
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T i3;
    int32_T loop_ub;
    int32_T scalarLB;
    int32_T vectorUB;
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
    if (joint_values_size < 1) {
      loop_ub = 0;
    } else {
      i = q_vel.size(0);
      if (i < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &j_emlrtBCI, &st);
      }
      i = q_vel.size(0);
      if (joint_values_size > i) {
        emlrtDynamicBoundsCheckR2012b(joint_values_size, 1, i, &k_emlrtBCI,
                                      &st);
      }
      loop_ub = joint_values_size;
    }
    b_iv[0] = 1;
    b_iv[1] = loop_ub;
    b_st.site = &jd_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    if (joint_values_size + 1 > q_vel.size(0)) {
      i = 0;
      i1 = 0;
    } else {
      i = q_vel.size(0);
      if (joint_values_size + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(joint_values_size + 1, 1, i, &l_emlrtBCI,
                                      &st);
      }
      i = joint_values_size;
      i2 = q_vel.size(0);
      i1 = q_vel.size(0);
      if ((i1 < 1) || (i1 > i2)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &m_emlrtBCI, &st);
      }
    }
    b_iv[0] = 1;
    b_loop_ub = i1 - i;
    b_iv[1] = b_loop_ub;
    b_st.site = &jd_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    if (joint_values_size + 1 > q_vel.size(0)) {
      i2 = 0;
      i3 = 0;
    } else {
      i2 = q_vel.size(0);
      if (joint_values_size + 1 > i2) {
        emlrtDynamicBoundsCheckR2012b(joint_values_size + 1, 1, i2, &n_emlrtBCI,
                                      &st);
      }
      i2 = joint_values_size;
      i1 = q_vel.size(0);
      i3 = q_vel.size(0);
      if ((i3 < 1) || (i3 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i1, &o_emlrtBCI, &st);
      }
    }
    b_iv[0] = 1;
    i1 = i3 - i2;
    b_iv[1] = i1;
    b_st.site = &jd_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    y.set_size(&gb_emlrtRTEI, &st, 1, b_loop_ub);
    scalarLB = (b_loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i3 = 0; i3 <= vectorUB; i3 += 2) {
      __m128d r;
      r = _mm_loadu_pd(&q_vel[i + i3]);
      _mm_storeu_pd(&y[i3],
                    _mm_mul_pd(_mm_set1_pd(config.SlackObjectiveWeight), r));
    }
    for (i3 = scalarLB; i3 < b_loop_ub; i3++) {
      y[i3] = config.SlackObjectiveWeight * q_vel[i + i3];
    }
    b_st.site = &jd_emlrtRSI;
    std::memset(&b[0], 0, 36U * sizeof(real_T));
    for (b_loop_ub = 0; b_loop_ub < 6; b_loop_ub++) {
      b[b_loop_ub + 6 * b_loop_ub] = config.SlackPenaltyWeight[b_loop_ub];
    }
    c_st.site = &td_emlrtRSI;
    if (y.size(1) != 6) {
      if (y.size(1) == 1) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    b_st.site = &jd_emlrtRSI;
    c_st.site = &td_emlrtRSI;
    if (i1 != 6) {
      if (i1 == 1) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &i_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    for (i = 0; i < loop_ub; i++) {
      q_vel_data[i] = q_vel[i];
    }
    b_y = 0.0;
    for (i = 0; i < 6; i++) {
      real_T d;
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += y[i1] * b[i1 + 6 * i];
      }
      b_y += d * q_vel[i2 + i];
    }
    b_st.site = &jd_emlrtRSI;
    varargout_1 = configurableObjective(
                      b_st, q_vel_data, loop_ub, jacobi_data, jacobi_size,
                      xd_eff_vel, starting_joint_vel, joint_values_data,
                      joint_values_size, jointVelocityWeightMatrix_data,
                      jointVelocityWeightMatrix_size, config) +
                  b_y;
  } else {
    real_T q_vel_data[12];
    int32_T b_iv[2];
    int32_T i;
    int32_T loop_ub;
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
    if (joint_values_size < 1) {
      loop_ub = 0;
    } else {
      i = q_vel.size(0);
      if (i < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &p_emlrtBCI, &st);
      }
      i = q_vel.size(0);
      if (joint_values_size > i) {
        emlrtDynamicBoundsCheckR2012b(joint_values_size, 1, i, &q_emlrtBCI,
                                      &st);
      }
      loop_ub = joint_values_size;
    }
    b_iv[0] = 1;
    b_iv[1] = loop_ub;
    b_st.site = &kd_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    for (i = 0; i < loop_ub; i++) {
      q_vel_data[i] = q_vel[i];
    }
    b_st.site = &kd_emlrtRSI;
    varargout_1 = configurableObjective(
        b_st, q_vel_data, loop_ub, jacobi_data, jacobi_size, xd_eff_vel,
        starting_joint_vel, joint_values_data, joint_values_size,
        jointVelocityWeightMatrix_data, jointVelocityWeightMatrix_size, config);
  }
  // /usr/local/src/AndreiUtils
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return varargout_1;
}

void c_inverseKinematicsOAModified_i()
{
  starting_joint_vel_not_empty = false;
}

void inverseKinematicsOAModified(
    const emlrtStack *sp, const real_T joint_values_data[],
    const int32_T joint_values_size[1], const real_T jacobi_data[],
    const int32_T jacobi_size[2], const real_T xd_eff_vel[6],
    const real_T jointminvalues_data[], const int32_T jointminvalues_size[1],
    const real_T jointmaxvalues_data[], const int32_T jointmaxvalues_size[1],
    const real_T joint_min_vel_data[], const int32_T joint_min_vel_size[1],
    const real_T joint_max_vel_data[], const int32_T joint_max_vel_size[1],
    const real_T J_g_data[], const int32_T J_g_size[2], const real_T b_g_data[],
    const int32_T b_g_size[1], const real_T jointVelocityWeightMatrix_data[],
    const int32_T jointVelocityWeightMatrix_size[2],
    const struct0_T *configInput,
    coder::array<real_T, 1U> &optimal_joint_velocity, real_T *Exit_Flag)
{
  static coder::array<real_T, 1U> starting_joint_vel;
  __m128d r;
  __m128d r1;
  coder::anonymous_function b_this;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T A_data[2016];
  real_T b_b_data[112];
  real_T b_data[112];
  real_T Aeq_data[108];
  real_T lb_data[18];
  real_T ub_data[18];
  real_T min_dist_data[12];
  real_T ub_joints_data[12];
  real_T varargin_1_data[12];
  real_T beq_data[6];
  real_T infuence_dist;
  real_T stop_dist;
  real_T varargin_1;
  int32_T A_size[2];
  int32_T Aeq_size[2];
  int32_T b_size[2];
  int32_T beq_size[2];
  int32_T input_sizes[2];
  int32_T In_size_idx_0;
  int32_T In_size_idx_1;
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T ub_size;
  int32_T varargin_1_size;
  int32_T vectorUB;
  int8_T In_data[144];
  boolean_T slackIsUsed;
  st.prev = sp;
  st.tls = sp->tls;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  //  % [n_joints x 1]
  //  % [6 x n_joints]
  //  % [6 x 1]
  //  % [n_joints x 1]
  //  % Inequality constraint matrix
  //  % Inequality constraint vector
  // ----------------------------------------------------------------------
  //  1. PERSISTENT VARIABLES
  // ----------------------------------------------------------------------
  //  Number of joints
  //  One slack variable per end-effector velocity component (if used)
  //  Initialize the persistent variables only on the first call
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 0,
                 !starting_joint_vel_not_empty)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    starting_joint_vel.set_size(&s_emlrtRTEI, sp, joint_values_size[0]);
    loop_ub = joint_values_size[0];
    for (i = 0; i < loop_ub; i++) {
      starting_joint_vel[i] = 0.0;
    }
    starting_joint_vel_not_empty = (starting_joint_vel.size(0) != 0);
    //  Default
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
  //  Unpack config for convenience
  // ----------------------------------------------------------------------
  //  2. DETERMINE IF SLACK IS ACTUALLY USED
  // ----------------------------------------------------------------------
  //  The new dynamic logic:
  //    - If config.dynamicSlack is true AND (J_g or b_g are empty),
  //      we forcibly turn off slack.
  //    - Otherwise, we do whatever config.applySlack says.
  //
  slackIsUsed = configInput->applySlack;
  if (covrtLogCond(&emlrtCoverageInstance, 0, 0, 0,
                   configInput->dynamicSlack) &&
      covrtLogCond(&emlrtCoverageInstance, 0, 0, 1,
                   configInput->obstacleAvoidanceScheme)) {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 1, true);
    if (covrtLogCond(&emlrtCoverageInstance, 0, 0, 2,
                     (J_g_size[0] == 0) || (J_g_size[1] == 0)) ||
        covrtLogCond(&emlrtCoverageInstance, 0, 0, 3, b_g_size[0] == 0)) {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1, true);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
      slackIsUsed = false;
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1, false);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, false);
    }
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 1, false);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
  // ----------------------------------------------------------------------
  //  3. BUILD VELOCITY DAMPER MATRICES IF NEEDED
  // ----------------------------------------------------------------------
  In_size_idx_0 = joint_values_size[0];
  In_size_idx_1 = joint_values_size[0];
  loop_ub = joint_values_size[0] * joint_values_size[0];
  if (loop_ub - 1 >= 0) {
    std::memset(&In_data[0], 0,
                static_cast<uint32_T>(loop_ub) * sizeof(int8_T));
  }
  //  Will hold diagonal matrix for damped joints
  ub_size = joint_values_size[0];
  loop_ub = joint_values_size[0];
  if (loop_ub - 1 >= 0) {
    std::memset(&ub_data[0], 0,
                static_cast<uint32_T>(loop_ub) * sizeof(real_T));
  }
  //  Will hold vector for velocity damper if needed
  infuence_dist =
      0.017453292519943295 * configInput->jointLimitActivationDistance;
  stop_dist = 0.017453292519943295 * configInput->jointLimitStopDistance;
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 3,
                 configInput->applyVelocityDamper)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
    //  Compute distance to each joint limit, apply a linear velocity damper
    if ((jointminvalues_size[0] != joint_values_size[0]) &&
        ((jointminvalues_size[0] != 1) && (joint_values_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointminvalues_size[0], joint_values_size[0],
                                  &f_emlrtECI, (emlrtConstCTX)sp);
    }
    if ((jointmaxvalues_size[0] != joint_values_size[0]) &&
        ((jointmaxvalues_size[0] != 1) && (joint_values_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointmaxvalues_size[0], joint_values_size[0],
                                  &e_emlrtECI, (emlrtConstCTX)sp);
    }
    st.site = &emlrtRSI;
    if (jointminvalues_size[0] == joint_values_size[0]) {
      loop_ub = jointminvalues_size[0];
      scalarLB = (jointminvalues_size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointminvalues_data[i]);
        r1 = _mm_loadu_pd(&joint_values_data[i]);
        _mm_storeu_pd(&min_dist_data[i], _mm_sub_pd(r, r1));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        min_dist_data[i] = jointminvalues_data[i] - joint_values_data[i];
      }
      b_st.site = &emlrtRSI;
      varargin_1_size =
          coder::b_abs(min_dist_data, jointminvalues_size[0], varargin_1_data);
    } else {
      b_st.site = &emlrtRSI;
      varargin_1_size = binary_expand_op_4(
          varargin_1_data, emlrtRSI, jointminvalues_data,
          jointminvalues_size[0], joint_values_data, joint_values_size[0]);
    }
    if (jointmaxvalues_size[0] == joint_values_size[0]) {
      loop_ub = jointmaxvalues_size[0];
      scalarLB = (jointmaxvalues_size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointmaxvalues_data[i]);
        r1 = _mm_loadu_pd(&joint_values_data[i]);
        _mm_storeu_pd(&min_dist_data[i], _mm_sub_pd(r, r1));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        min_dist_data[i] = jointmaxvalues_data[i] - joint_values_data[i];
      }
      b_st.site = &b_emlrtRSI;
      scalarLB =
          coder::b_abs(min_dist_data, jointmaxvalues_size[0], ub_joints_data);
    } else {
      b_st.site = &b_emlrtRSI;
      scalarLB = binary_expand_op_4(ub_joints_data, b_emlrtRSI,
                                    jointmaxvalues_data, jointmaxvalues_size[0],
                                    joint_values_data, joint_values_size[0]);
    }
    b_st.site = &p_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = &r_emlrtRSI;
    e_st.site = &s_emlrtRSI;
    f_st.site = &t_emlrtRSI;
    if (varargin_1_size == scalarLB) {
      vectorUB = varargin_1_size;
      for (i = 0; i < varargin_1_size; i++) {
        varargin_1 = varargin_1_data[i];
        min_dist_data[i] = muDoubleScalarMin(varargin_1, ub_joints_data[i]);
      }
    } else {
      g_st.site = &u_emlrtRSI;
      vectorUB =
          coder::internal::expand_min(g_st, varargin_1_data, varargin_1_size,
                                      ub_joints_data, scalarLB, min_dist_data);
    }
    i = joint_values_size[0];
    for (scalarLB = 0; scalarLB < i; scalarLB++) {
      covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
      if (scalarLB + 1 > vectorUB) {
        emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, vectorUB, &c_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      varargin_1 = min_dist_data[scalarLB];
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 4,
                     varargin_1 < infuence_dist)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 6);
        if (scalarLB + 1 > In_size_idx_0) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, In_size_idx_0,
                                        &d_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (scalarLB + 1 > In_size_idx_1) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, In_size_idx_1,
                                        &e_emlrtBCI, (emlrtConstCTX)sp);
        }
        In_data[scalarLB + In_size_idx_0 * scalarLB] = 1;
        if (scalarLB + 1 > vectorUB) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, vectorUB, &f_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (scalarLB + 1 > ub_size) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, ub_size, &g_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ub_data[scalarLB] = configInput->jointLimitGain *
                            (varargin_1 - stop_dist) /
                            (infuence_dist - stop_dist);
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 7);
  // ----------------------------------------------------------------------
  //  4. SET UP CONSTRAINTS AND BOUNDS
  // ----------------------------------------------------------------------
  //  Default: no constraints
  Aeq_size[0] = 0;
  Aeq_size[1] = 0;
  beq_size[0] = 0;
  beq_size[1] = 0;
  A_size[0] = 0;
  A_size[1] = 0;
  b_size[0] = 0;
  b_size[1] = 0;
  //  lb  = [];
  //  ub  = [];
  //  Weight matrix for Jacobian in equality constraints
  //  ---- 4.1 Equality constraints ---------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 5,
                 configInput->applyEqualityConstraints)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 8);
    st.site = &c_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    coder::internal::blas::mtimes(jacobi_data, jacobi_size, Aeq_data, Aeq_size);
    beq_size[0] = 6;
    beq_size[1] = 1;
    for (i = 0; i < 6; i++) {
      beq_data[i] = xd_eff_vel[i];
    }
  }
  //  ---- 4.2 Inequality constraints -------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 6,
                 configInput->applyInequalityConstraints)) {
    if ((!covrtLogCond(&emlrtCoverageInstance, 0, 0, 4,
                       (J_g_size[0] == 0) || (J_g_size[1] == 0))) &&
        (!covrtLogCond(&emlrtCoverageInstance, 0, 0, 5, b_g_size[0] == 0))) {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 2, true);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 7, true);
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 8,
                     configInput->applyVelocityDamper)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 9);
        //  Combine both standard inequalities and velocity damper
        st.site = &d_emlrtRSI;
        b_st.site = &y_emlrtRSI;
        c_st.site = &ab_emlrtRSI;
        if ((joint_values_size[0] != J_g_size[1]) &&
            (joint_values_size[0] != 0)) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        input_sizes[0] = J_g_size[0];
        if (joint_values_size[0] != 0) {
          scalarLB = static_cast<int8_T>(joint_values_size[0]);
        } else {
          scalarLB = 0;
        }
        A_size[0] = J_g_size[0] + scalarLB;
        A_size[1] = J_g_size[1];
        loop_ub = J_g_size[1];
        vectorUB = input_sizes[0];
        for (i = 0; i < loop_ub; i++) {
          for (In_size_idx_1 = 0; In_size_idx_1 < vectorUB; In_size_idx_1++) {
            A_data[In_size_idx_1 + A_size[0] * i] =
                J_g_data[In_size_idx_1 + input_sizes[0] * i];
          }
          for (In_size_idx_1 = 0; In_size_idx_1 < scalarLB; In_size_idx_1++) {
            A_data[(In_size_idx_1 + input_sizes[0]) + A_size[0] * i] =
                In_data[In_size_idx_1 + scalarLB * i];
          }
        }
        scalarLB = b_g_size[0] + joint_values_size[0];
        loop_ub = b_g_size[0];
        std::copy(&b_g_data[0], &b_g_data[loop_ub], &b_b_data[0]);
        for (i = 0; i < ub_size; i++) {
          b_b_data[i + b_g_size[0]] = ub_data[i];
        }
        b_size[0] = scalarLB;
        b_size[1] = 1;
        std::copy(&b_b_data[0], &b_b_data[scalarLB], &b_data[0]);
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 10);
        //  No velocity damper
        A_size[0] = J_g_size[0];
        A_size[1] = J_g_size[1];
        loop_ub = J_g_size[0] * J_g_size[1];
        std::copy(&J_g_data[0], &J_g_data[loop_ub], &A_data[0]);
        b_size[0] = b_g_size[0];
        b_size[1] = 1;
        loop_ub = b_g_size[0];
        std::copy(&b_g_data[0], &b_g_data[loop_ub], &b_data[0]);
      }
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 2, false);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 7, false);
      //  If J_g, b_g are empty, we only apply velocity damper if set
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 9,
                     configInput->applyVelocityDamper)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 11);
        A_size[0] = joint_values_size[0];
        A_size[1] = joint_values_size[0];
        loop_ub = joint_values_size[0] * joint_values_size[0];
        for (i = 0; i < loop_ub; i++) {
          A_data[i] = In_data[i];
        }
        b_size[0] = joint_values_size[0];
        b_size[1] = 1;
        if (ub_size - 1 >= 0) {
          std::copy(&ub_data[0], &ub_data[ub_size], &b_data[0]);
        }
      }
    }

    //  If we do not apply inequality constraints at all but velocity
    //  damper is on, we can still do that by adding A=In, b=bp.
  } else if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 10,
                        configInput->applyVelocityDamper)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 12);
    A_size[0] = joint_values_size[0];
    A_size[1] = joint_values_size[0];
    loop_ub = joint_values_size[0] * joint_values_size[0];
    for (i = 0; i < loop_ub; i++) {
      A_data[i] = In_data[i];
    }
    b_size[0] = joint_values_size[0];
    b_size[1] = 1;
    if (ub_size - 1 >= 0) {
      std::copy(&ub_data[0], &ub_data[ub_size], &b_data[0]);
    }

    //  if config.applyVelocityDamper && (isempty(J_g) || isempty(b_g))
    //      A = In;
    //      b = bp;
    //  end
  }
  //  ---- 4.3 Determine final use of Slack and build lb, ub --------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 11,
                 covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 3,
                              !covrtLogCond(&emlrtCoverageInstance, 0, 0, 6,
                                            slackIsUsed)))) {
    //  BOUNDS without slack
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 12,
                   configInput->applyVelocityDamper)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 13);
      //  We do not scale velocities by gamma if velocity damper is active
      In_size_idx_0 = joint_min_vel_size[0];
      loop_ub = joint_min_vel_size[0];
      if (loop_ub - 1 >= 0) {
        std::copy(&joint_min_vel_data[0], &joint_min_vel_data[loop_ub],
                  &lb_data[0]);
      }
      ub_size = joint_max_vel_size[0];
      loop_ub = joint_max_vel_size[0];
      if (loop_ub - 1 >= 0) {
        std::copy(&joint_max_vel_data[0], &joint_max_vel_data[loop_ub],
                  &ub_data[0]);
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 14);
      //  Normal bounds: scale the move by config.gamma
      if ((jointminvalues_size[0] != joint_values_size[0]) &&
          ((jointminvalues_size[0] != 1) && (joint_values_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(jointminvalues_size[0],
                                    joint_values_size[0], &d_emlrtECI,
                                    (emlrtConstCTX)sp);
      }
      st.site = &e_emlrtRSI;
      if (jointminvalues_size[0] == joint_values_size[0]) {
        varargin_1_size = jointminvalues_size[0];
        loop_ub = jointminvalues_size[0];
        scalarLB = (jointminvalues_size[0] / 2) << 1;
        vectorUB = scalarLB - 2;
        for (i = 0; i <= vectorUB; i += 2) {
          r = _mm_loadu_pd(&jointminvalues_data[i]);
          r1 = _mm_loadu_pd(&joint_values_data[i]);
          _mm_storeu_pd(
              &varargin_1_data[i],
              _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
        }
        for (i = scalarLB; i < loop_ub; i++) {
          varargin_1_data[i] = configInput->gamma *
                               (jointminvalues_data[i] - joint_values_data[i]);
        }
      } else {
        varargin_1_size = binary_expand_op(
            varargin_1_data, configInput, jointminvalues_data,
            jointminvalues_size[0], joint_values_data, joint_values_size[0]);
      }
      b_st.site = &bb_emlrtRSI;
      c_st.site = &cb_emlrtRSI;
      d_st.site = &db_emlrtRSI;
      e_st.site = &s_emlrtRSI;
      f_st.site = &t_emlrtRSI;
      if (varargin_1_size == joint_min_vel_size[0]) {
        ub_size = varargin_1_size;
        for (i = 0; i < varargin_1_size; i++) {
          varargin_1 = varargin_1_data[i];
          ub_data[i] = muDoubleScalarMax(varargin_1, joint_min_vel_data[i]);
        }
      } else {
        g_st.site = &u_emlrtRSI;
        ub_size = coder::internal::expand_max(
            g_st, varargin_1_data, varargin_1_size, joint_min_vel_data,
            joint_min_vel_size[0], ub_data);
      }
      In_size_idx_0 = ub_size;
      if (ub_size - 1 >= 0) {
        std::copy(&ub_data[0], &ub_data[ub_size], &lb_data[0]);
      }
      if ((jointmaxvalues_size[0] != joint_values_size[0]) &&
          ((jointmaxvalues_size[0] != 1) && (joint_values_size[0] != 1))) {
        emlrtDimSizeImpxCheckR2021b(jointmaxvalues_size[0],
                                    joint_values_size[0], &c_emlrtECI,
                                    (emlrtConstCTX)sp);
      }
      st.site = &f_emlrtRSI;
      if (jointmaxvalues_size[0] == joint_values_size[0]) {
        varargin_1_size = jointmaxvalues_size[0];
        loop_ub = jointmaxvalues_size[0];
        scalarLB = (jointmaxvalues_size[0] / 2) << 1;
        vectorUB = scalarLB - 2;
        for (i = 0; i <= vectorUB; i += 2) {
          r = _mm_loadu_pd(&jointmaxvalues_data[i]);
          r1 = _mm_loadu_pd(&joint_values_data[i]);
          _mm_storeu_pd(
              &varargin_1_data[i],
              _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
        }
        for (i = scalarLB; i < loop_ub; i++) {
          varargin_1_data[i] = configInput->gamma *
                               (jointmaxvalues_data[i] - joint_values_data[i]);
        }
      } else {
        varargin_1_size = binary_expand_op(
            varargin_1_data, configInput, jointmaxvalues_data,
            jointmaxvalues_size[0], joint_values_data, joint_values_size[0]);
      }
      b_st.site = &p_emlrtRSI;
      c_st.site = &q_emlrtRSI;
      d_st.site = &r_emlrtRSI;
      e_st.site = &s_emlrtRSI;
      f_st.site = &t_emlrtRSI;
      if (varargin_1_size == joint_max_vel_size[0]) {
        ub_size = varargin_1_size;
        for (i = 0; i < varargin_1_size; i++) {
          varargin_1 = varargin_1_data[i];
          ub_data[i] = muDoubleScalarMin(varargin_1, joint_max_vel_data[i]);
        }
      } else {
        g_st.site = &u_emlrtRSI;
        ub_size = coder::internal::expand_min(
            g_st, varargin_1_data, varargin_1_size, joint_max_vel_data,
            joint_max_vel_size[0], ub_data);
      }
    }

    //  BOUNDS with slack
    //     first n_joints are for joint velocities
    //     next   n_slack are for slack
  } else if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 13,
                        configInput->applyVelocityDamper)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 15);
    In_size_idx_0 = joint_min_vel_size[0] + 6;
    loop_ub = joint_min_vel_size[0];
    if (loop_ub - 1 >= 0) {
      std::copy(&joint_min_vel_data[0], &joint_min_vel_data[loop_ub],
                &lb_data[0]);
    }
    for (i = 0; i < 6; i++) {
      lb_data[i + joint_min_vel_size[0]] = configInput->Slacklowerbound[i];
    }
    ub_size = joint_max_vel_size[0] + 6;
    loop_ub = joint_max_vel_size[0];
    if (loop_ub - 1 >= 0) {
      std::copy(&joint_max_vel_data[0], &joint_max_vel_data[loop_ub],
                &ub_data[0]);
    }
    for (i = 0; i < 6; i++) {
      ub_data[i + joint_max_vel_size[0]] = configInput->Slackupperbound[i];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 16);
    if ((jointminvalues_size[0] != joint_values_size[0]) &&
        ((jointminvalues_size[0] != 1) && (joint_values_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointminvalues_size[0], joint_values_size[0],
                                  &b_emlrtECI, (emlrtConstCTX)sp);
    }
    st.site = &g_emlrtRSI;
    if (jointminvalues_size[0] == joint_values_size[0]) {
      varargin_1_size = jointminvalues_size[0];
      loop_ub = jointminvalues_size[0];
      scalarLB = (jointminvalues_size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointminvalues_data[i]);
        r1 = _mm_loadu_pd(&joint_values_data[i]);
        _mm_storeu_pd(
            &varargin_1_data[i],
            _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        varargin_1_data[i] = configInput->gamma *
                             (jointminvalues_data[i] - joint_values_data[i]);
      }
    } else {
      varargin_1_size = binary_expand_op(
          varargin_1_data, configInput, jointminvalues_data,
          jointminvalues_size[0], joint_values_data, joint_values_size[0]);
    }
    b_st.site = &bb_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    e_st.site = &s_emlrtRSI;
    f_st.site = &t_emlrtRSI;
    if (varargin_1_size == joint_min_vel_size[0]) {
      ub_size = varargin_1_size;
      for (i = 0; i < varargin_1_size; i++) {
        varargin_1 = varargin_1_data[i];
        ub_data[i] = muDoubleScalarMax(varargin_1, joint_min_vel_data[i]);
      }
    } else {
      g_st.site = &u_emlrtRSI;
      ub_size = coder::internal::expand_max(g_st, varargin_1_data,
                                            varargin_1_size, joint_min_vel_data,
                                            joint_min_vel_size[0], ub_data);
    }
    if ((jointmaxvalues_size[0] != joint_values_size[0]) &&
        ((jointmaxvalues_size[0] != 1) && (joint_values_size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointmaxvalues_size[0], joint_values_size[0],
                                  &emlrtECI, (emlrtConstCTX)sp);
    }
    st.site = &h_emlrtRSI;
    if (jointmaxvalues_size[0] == joint_values_size[0]) {
      varargin_1_size = jointmaxvalues_size[0];
      loop_ub = jointmaxvalues_size[0];
      scalarLB = (jointmaxvalues_size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointmaxvalues_data[i]);
        r1 = _mm_loadu_pd(&joint_values_data[i]);
        _mm_storeu_pd(
            &varargin_1_data[i],
            _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        varargin_1_data[i] = configInput->gamma *
                             (jointmaxvalues_data[i] - joint_values_data[i]);
      }
    } else {
      varargin_1_size = binary_expand_op(
          varargin_1_data, configInput, jointmaxvalues_data,
          jointmaxvalues_size[0], joint_values_data, joint_values_size[0]);
    }
    b_st.site = &p_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = &r_emlrtRSI;
    e_st.site = &s_emlrtRSI;
    f_st.site = &t_emlrtRSI;
    if (varargin_1_size == joint_max_vel_size[0]) {
      scalarLB = varargin_1_size;
      for (i = 0; i < varargin_1_size; i++) {
        varargin_1 = varargin_1_data[i];
        ub_joints_data[i] =
            muDoubleScalarMin(varargin_1, joint_max_vel_data[i]);
      }
    } else {
      g_st.site = &u_emlrtRSI;
      scalarLB = coder::internal::expand_min(
          g_st, varargin_1_data, varargin_1_size, joint_max_vel_data,
          joint_max_vel_size[0], ub_joints_data);
    }
    In_size_idx_0 = ub_size + 6;
    if (ub_size - 1 >= 0) {
      std::copy(&ub_data[0], &ub_data[ub_size], &lb_data[0]);
    }
    for (i = 0; i < 6; i++) {
      lb_data[i + ub_size] = configInput->Slacklowerbound[i];
    }
    ub_size = scalarLB + 6;
    if (scalarLB - 1 >= 0) {
      std::copy(&ub_joints_data[0], &ub_joints_data[scalarLB], &ub_data[0]);
    }
    for (i = 0; i < 6; i++) {
      ub_data[i + scalarLB] = configInput->Slackupperbound[i];
    }
  }
  //  ---- 4.4 Expand constraints for Slack if needed ----------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 14, slackIsUsed)) {
    //  Expand the equality constraints
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 15,
                   configInput->applyEqualityConstraints)) {
      real_T dv[36];
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 17);
      st.site = &i_emlrtRSI;
      b_st.site = &v_emlrtRSI;
      coder::internal::blas::mtimes(jacobi_data, jacobi_size, Aeq_data,
                                    Aeq_size);
      coder::eye(dv);
      i = Aeq_size[1];
      Aeq_size[1] += 6;
      beq_size[0] = 6;
      beq_size[1] = 1;
      for (In_size_idx_1 = 0; In_size_idx_1 < 6; In_size_idx_1++) {
        for (scalarLB = 0; scalarLB < 6; scalarLB++) {
          Aeq_data[scalarLB + Aeq_size[0] * (In_size_idx_1 + i)] =
              dv[scalarLB + 6 * In_size_idx_1];
        }
        beq_data[In_size_idx_1] = xd_eff_vel[In_size_idx_1];
      }
    }
    //  Expand the inequality constraints
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 16,
                   covrtLogMcdc(
                       &emlrtCoverageInstance, 0, 0, 4,
                       !covrtLogCond(&emlrtCoverageInstance, 0, 0, 7,
                                     (A_size[0] == 0) || (A_size[1] == 0))))) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 18);
      st.site = &j_emlrtRSI;
      b_st.site = &y_emlrtRSI;
      scalarLB = A_size[0];
      c_st.site = &ab_emlrtRSI;
      input_sizes[0] = A_size[0];
      input_sizes[1] = A_size[1];
      loop_ub = A_size[1];
      for (i = 0; i < loop_ub; i++) {
        for (In_size_idx_1 = 0; In_size_idx_1 < scalarLB; In_size_idx_1++) {
          A_data[In_size_idx_1 + A_size[0] * i] =
              A_data[In_size_idx_1 + input_sizes[0] * i];
        }
      }
      A_size[1] += 6;
      for (i = 0; i < 6; i++) {
        for (In_size_idx_1 = 0; In_size_idx_1 < scalarLB; In_size_idx_1++) {
          A_data[In_size_idx_1 + A_size[0] * (i + input_sizes[1])] = 0.0;
        }
      }
    }
  }
  // ----------------------------------------------------------------------
  //  5. INITIAL GUESS
  // ----------------------------------------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 17, slackIsUsed)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 19);
    optimal_joint_velocity.set_size(&u_emlrtRTEI, sp,
                                    starting_joint_vel.size(0) + 6);
    loop_ub = starting_joint_vel.size(0);
    for (i = 0; i < loop_ub; i++) {
      optimal_joint_velocity[i] = starting_joint_vel[i];
    }
    for (i = 0; i < 6; i++) {
      optimal_joint_velocity[i + starting_joint_vel.size(0)] = 0.0;
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 20);
    optimal_joint_velocity.set_size(&t_emlrtRTEI, sp,
                                    starting_joint_vel.size(0));
    loop_ub = starting_joint_vel.size(0);
    for (i = 0; i < loop_ub; i++) {
      optimal_joint_velocity[i] = starting_joint_vel[i];
    }
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 21);
  // ----------------------------------------------------------------------
  //  6. OPTIMIZATION OPTIONS
  // ----------------------------------------------------------------------
  //   % or 'iter' to see solver progress
  //   % Code generation supports these options:
  //
  //  Algorithm — Must be 'sqp' or 'sqp-legacy'
  //
  //  ConstraintTolerance: of interest
  //
  //  FiniteDifferenceStepSize not of interest
  //
  //  FiniteDifferenceType: not of interest
  //
  //  MaxFunctionEvaluations: not of interest
  //
  //  MaxIterations: of interest
  //
  //  ObjectiveLimit: of interest only for unbounded problems (i.e)
  //
  //  OptimalityTolerance: of interest
  //
  //  ScaleProblem: not of interest
  //
  //  SpecifyConstraintGradient: not of interest
  //
  //  SpecifyObjectiveGradient: not of interest
  //
  //  StepTolerance: of interest
  //
  //  TypicalX: not of interest
  // ----------------------------------------------------------------------
  //  7. CALL THE OPTIMIZER (fmincon)
  // ----------------------------------------------------------------------
  b_this.workspace.slackIsUsed = slackIsUsed;
  b_this.workspace.jacobi.size[0] = 6;
  b_this.workspace.jacobi.size[1] = jacobi_size[1];
  loop_ub = 6 * jacobi_size[1];
  if (loop_ub - 1 >= 0) {
    std::copy(&jacobi_data[0], &jacobi_data[loop_ub],
              &b_this.workspace.jacobi.data[0]);
  }
  for (scalarLB = 0; scalarLB < 6; scalarLB++) {
    b_this.workspace.xd_eff_vel[scalarLB] = xd_eff_vel[scalarLB];
  }
  b_this.workspace.starting_joint_vel.set_size(&v_emlrtRTEI, sp,
                                               starting_joint_vel.size(0));
  loop_ub = starting_joint_vel.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.starting_joint_vel[i] = starting_joint_vel[i];
  }
  b_this.workspace.joint_values.size[0] = joint_values_size[0];
  loop_ub = joint_values_size[0];
  if (loop_ub - 1 >= 0) {
    std::copy(&joint_values_data[0], &joint_values_data[loop_ub],
              &b_this.workspace.joint_values.data[0]);
  }
  b_this.workspace.jointVelocityWeightMatrix.size[0] =
      jointVelocityWeightMatrix_size[0];
  b_this.workspace.jointVelocityWeightMatrix.size[1] =
      jointVelocityWeightMatrix_size[1];
  loop_ub =
      jointVelocityWeightMatrix_size[0] * jointVelocityWeightMatrix_size[1];
  if (loop_ub - 1 >= 0) {
    std::copy(&jointVelocityWeightMatrix_data[0],
              &jointVelocityWeightMatrix_data[loop_ub],
              &b_this.workspace.jointVelocityWeightMatrix.data[0]);
  }
  b_this.workspace.config = *configInput;
  st.site = &k_emlrtRSI;
  coder::fmincon(st, b_this, optimal_joint_velocity, A_data, A_size, b_data,
                 b_size, Aeq_data, Aeq_size, beq_data, beq_size, lb_data,
                 In_size_idx_0, ub_data, ub_size, Exit_Flag);
  // ----------------------------------------------------------------------
  //  8. EXTRACT THE RESULT
  // ----------------------------------------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 18, slackIsUsed)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 23);
    if (joint_values_size[0] < 1) {
      i = 0;
    } else {
      if (optimal_joint_velocity.size(0) < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, optimal_joint_velocity.size(0),
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (joint_values_size[0] > optimal_joint_velocity.size(0)) {
        emlrtDynamicBoundsCheckR2012b(joint_values_size[0], 1,
                                      optimal_joint_velocity.size(0), &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i = joint_values_size[0];
    }
    input_sizes[0] = 1;
    input_sizes[1] = i;
    st.site = &l_emlrtRSI;
    coder::internal::indexShapeCheck(st, optimal_joint_velocity.size(0),
                                     input_sizes);
    optimal_joint_velocity.set_size(&w_emlrtRTEI, sp, i);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 24);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 25);
  // ----------------------------------------------------------------------
  //  9. UPDATE PERSISTENT STATE
  // ----------------------------------------------------------------------
  starting_joint_vel.set_size(&x_emlrtRTEI, sp, optimal_joint_velocity.size(0));
  loop_ub = optimal_joint_velocity.size(0);
  for (i = 0; i < loop_ub; i++) {
    starting_joint_vel[i] = optimal_joint_velocity[i];
  }
  starting_joint_vel_not_empty = (starting_joint_vel.size(0) != 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (inverseKinematicsOAModified.cpp)
