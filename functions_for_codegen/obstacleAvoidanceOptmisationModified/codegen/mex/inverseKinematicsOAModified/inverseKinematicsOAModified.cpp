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
#include "mwmathutil.h"
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static boolean_T starting_joint_vel_not_empty;

static boolean_T is_first_step_not_empty;

static emlrtRSInfo emlrtRSI{
    63,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    64,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    89,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    98,                            // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    135,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    136,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    150,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    151,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    165,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    171,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    198,                           // lineNo
    "inverseKinematicsOAModified", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    214,                           // lineNo
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

static emlrtRSInfo hd_emlrtRSI{
    198, // lineNo
    "@(q_vel)objFun(q_vel,jacobi,xd_eff_vel,starting_joint_vel,joint_values,"
    "jointVelocityWeightMatrix,config,slackIsUsed)", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    6,        // lineNo
    "objFun", // fcnName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
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
    214,                           // lineNo
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
    214,                           // lineNo
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
    151,                           // lineNo
    46,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo b_emlrtECI{
    1,                             // nDims
    150,                           // lineNo
    46,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo c_emlrtECI{
    1,                             // nDims
    136,                           // lineNo
    39,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo d_emlrtECI{
    1,                             // nDims
    135,                           // lineNo
    39,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo e_emlrtECI{
    1,                             // nDims
    64,                            // lineNo
    28,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtECInfo f_emlrtECI{
    1,                             // nDims
    63,                            // lineNo
    28,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    66,                            // lineNo
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
    67,                            // lineNo
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
    67,                            // lineNo
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
    68,                            // lineNo
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
    68,                            // lineNo
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
    54,                            // lineNo
    5,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    55,                            // lineNo
    5,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    63,                            // lineNo
    28,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    64,                            // lineNo
    28,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    63,                            // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    77,                            // lineNo
    5,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    79,                            // lineNo
    5,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    80,                            // lineNo
    5,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    116,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    117,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    108,                           // lineNo
    17,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    109,                           // lineNo
    17,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    102,                           // lineNo
    17,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    103,                           // lineNo
    17,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    98,                            // lineNo
    17,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    99,                            // lineNo
    21,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    99,                            // lineNo
    17,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    150,                           // lineNo
    29,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    150,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    151,                           // lineNo
    29,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    151,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    154,                           // lineNo
    24,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    154,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    155,                           // lineNo
    24,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo sb_emlrtRTEI{
    155,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo tb_emlrtRTEI{
    147,                           // lineNo
    24,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ub_emlrtRTEI{
    147,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo vb_emlrtRTEI{
    148,                           // lineNo
    24,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    148,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo xb_emlrtRTEI{
    135,                           // lineNo
    22,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo yb_emlrtRTEI{
    135,                           // lineNo
    18,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ac_emlrtRTEI{
    135,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    136,                           // lineNo
    22,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    136,                           // lineNo
    18,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    136,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    131,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    132,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    165,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    171,                           // lineNo
    13,                            // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ic_emlrtRTEI{
    181,                           // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo jc_emlrtRTEI{
    179,                           // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    35,                // lineNo
    13,                // colNo
    "function_handle", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" // pName
};

static emlrtRTEInfo lc_emlrtRTEI{
    30,                // lineNo
    21,                // colNo
    "function_handle", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" // pName
};

static emlrtRTEInfo mc_emlrtRTEI{
    214,                           // lineNo
    9,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    223,                           // lineNo
    5,                             // colNo
    "inverseKinematicsOAModified", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/inverseKinematicsOAModified.m" // pName
};

static emlrtRTEInfo ad_emlrtRTEI{
    8,        // lineNo
    36,       // colNo
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m" // pName
};

static emlrtRTEInfo
    bd_emlrtRTEI{
        74,                  // lineNo
        9,                   // colNo
        "eml_mtimes_helper", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

static emlrtRTEInfo cd_emlrtRTEI{
    6,        // lineNo
    36,       // colNo
    "objFun", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/objFun.m" // pName
};

// Function Declarations
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real_T, 1U> &in1,
                             const struct0_T *in2,
                             const coder::array<real_T, 1U> &in3,
                             const coder::array<real_T, 1U> &in4);

static void binary_expand_op_4(const emlrtStack &sp,
                               coder::array<real_T, 1U> &in1,
                               const emlrtRSInfo in2,
                               const coder::array<real_T, 1U> &in3,
                               const coder::array<real_T, 1U> &in4);

// Function Definitions
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real_T, 1U> &in1,
                             const struct0_T *in2,
                             const coder::array<real_T, 1U> &in3,
                             const coder::array<real_T, 1U> &in4)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  in1.set_size(&bc_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = in2->gamma * (in3[i * stride_0_0] - in4[i * stride_1_0]);
  }
}

static void binary_expand_op_4(const emlrtStack &sp,
                               coder::array<real_T, 1U> &in1,
                               const emlrtRSInfo in2,
                               const coder::array<real_T, 1U> &in3,
                               const coder::array<real_T, 1U> &in4)
{
  coder::array<real_T, 1U> b_in3;
  emlrtStack st;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  b_in3.set_size(&w_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in3[i] = in3[i * stride_0_0] - in4[i * stride_1_0];
  }
  st.site = const_cast<emlrtRSInfo *>(&in2);
  coder::b_abs(st, b_in3, in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

real_T c_inverseKinematicsOAModified_a(
    const emlrtStack &sp, const coder::array<real_T, 2U> &jacobi,
    const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &starting_joint_vel,
    const coder::array<real_T, 1U> &joint_values,
    const coder::array<real_T, 2U> &jointVelocityWeightMatrix,
    const struct0_T &config, boolean_T slackIsUsed,
    const coder::array<real_T, 1U> &q_vel)
{
  coder::array<real_T, 2U> y;
  coder::array<real_T, 1U> b_q_vel;
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
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 23);
  st.site = &hd_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
  //  Add the cost for the slack variables
  if (covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, slackIsUsed)) {
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
    if (joint_values.size(0) < 1) {
      loop_ub = 0;
    } else {
      i = q_vel.size(0);
      if (i < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &j_emlrtBCI, &st);
      }
      i = q_vel.size(0);
      if (joint_values.size(0) > i) {
        emlrtDynamicBoundsCheckR2012b(joint_values.size(0), 1, i, &k_emlrtBCI,
                                      &st);
      }
      loop_ub = joint_values.size(0);
    }
    b_iv[0] = 1;
    b_iv[1] = loop_ub;
    b_st.site = &id_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    if (static_cast<uint32_T>(joint_values.size(0)) + 1U >
        static_cast<uint32_T>(q_vel.size(0))) {
      i = 0;
      i1 = 0;
    } else {
      i = q_vel.size(0);
      if ((static_cast<int32_T>(static_cast<uint32_T>(joint_values.size(0)) +
                                1U) < 1) ||
          (static_cast<int32_T>(static_cast<uint32_T>(joint_values.size(0)) +
                                1U) > i)) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<uint32_T>(joint_values.size(0)) +
                                 1U),
            1, i, &l_emlrtBCI, &st);
      }
      i = joint_values.size(0);
      i2 = q_vel.size(0);
      i1 = q_vel.size(0);
      if ((i1 < 1) || (i1 > i2)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i2, &m_emlrtBCI, &st);
      }
    }
    b_iv[0] = 1;
    b_loop_ub = i1 - i;
    b_iv[1] = b_loop_ub;
    b_st.site = &id_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    if (static_cast<uint32_T>(joint_values.size(0)) + 1U >
        static_cast<uint32_T>(q_vel.size(0))) {
      i2 = 0;
      i3 = 0;
    } else {
      i2 = q_vel.size(0);
      if ((static_cast<int32_T>(static_cast<uint32_T>(joint_values.size(0)) +
                                1U) < 1) ||
          (static_cast<int32_T>(static_cast<uint32_T>(joint_values.size(0)) +
                                1U) > i2)) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<uint32_T>(joint_values.size(0)) +
                                 1U),
            1, i2, &n_emlrtBCI, &st);
      }
      i2 = joint_values.size(0);
      i1 = q_vel.size(0);
      i3 = q_vel.size(0);
      if ((i3 < 1) || (i3 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i1, &o_emlrtBCI, &st);
      }
    }
    b_iv[0] = 1;
    i1 = i3 - i2;
    b_iv[1] = i1;
    b_st.site = &id_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    y.set_size(&bd_emlrtRTEI, &st, 1, b_loop_ub);
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
    b_st.site = &id_emlrtRSI;
    std::memset(&b[0], 0, 36U * sizeof(real_T));
    for (b_loop_ub = 0; b_loop_ub < 6; b_loop_ub++) {
      b[b_loop_ub + 6 * b_loop_ub] = config.SlackPenaltyWeight[b_loop_ub];
    }
    c_st.site = &sd_emlrtRSI;
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
    b_st.site = &id_emlrtRSI;
    c_st.site = &sd_emlrtRSI;
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
    b_q_vel.set_size(&cd_emlrtRTEI, &st, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_q_vel[i] = q_vel[i];
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
    b_st.site = &id_emlrtRSI;
    varargout_1 = configurableObjective(b_st, b_q_vel, jacobi, xd_eff_vel,
                                        starting_joint_vel, joint_values,
                                        jointVelocityWeightMatrix, config) +
                  b_y;
  } else {
    int32_T b_iv[2];
    int32_T i;
    int32_T loop_ub;
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
    if (joint_values.size(0) < 1) {
      loop_ub = 0;
    } else {
      i = q_vel.size(0);
      if (i < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &p_emlrtBCI, &st);
      }
      i = q_vel.size(0);
      if (joint_values.size(0) > i) {
        emlrtDynamicBoundsCheckR2012b(joint_values.size(0), 1, i, &q_emlrtBCI,
                                      &st);
      }
      loop_ub = joint_values.size(0);
    }
    b_iv[0] = 1;
    b_iv[1] = loop_ub;
    b_st.site = &jd_emlrtRSI;
    coder::internal::indexShapeCheck(b_st, q_vel.size(0), b_iv);
    b_q_vel.set_size(&ad_emlrtRTEI, &st, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      b_q_vel[i] = q_vel[i];
    }
    b_st.site = &jd_emlrtRSI;
    varargout_1 = configurableObjective(b_st, b_q_vel, jacobi, xd_eff_vel,
                                        starting_joint_vel, joint_values,
                                        jointVelocityWeightMatrix, config);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return varargout_1;
}

void c_inverseKinematicsOAModified_i()
{
  is_first_step_not_empty = false;
  starting_joint_vel_not_empty = false;
}

void inverseKinematicsOAModified(
    const emlrtStack *sp, const coder::array<real_T, 1U> &joint_values,
    const coder::array<real_T, 2U> &jacobi, const real_T xd_eff_vel[6],
    const coder::array<real_T, 1U> &jointminvalues,
    const coder::array<real_T, 1U> &jointmaxvalues,
    const coder::array<real_T, 1U> &joint_min_vel,
    const coder::array<real_T, 1U> &joint_max_vel,
    const coder::array<real_T, 2U> &J_g, const coder::array<real_T, 1U> &b_g,
    const coder::array<real_T, 2U> &jointVelocityWeightMatrix,
    const struct0_T *configInput,
    coder::array<real_T, 1U> &optimal_joint_velocity, real_T *Exit_Flag)
{
  static coder::array<real_T, 1U> starting_joint_vel;
  static boolean_T is_first_step;
  __m128d r;
  __m128d r1;
  coder::anonymous_function b_this;
  coder::array<real_T, 2U> A;
  coder::array<real_T, 2U> Aeq;
  coder::array<real_T, 2U> b;
  coder::array<real_T, 2U> lb;
  coder::array<real_T, 2U> ub;
  coder::array<real_T, 1U> bp;
  coder::array<real_T, 1U> lb_joints;
  coder::array<real_T, 1U> min_dist;
  coder::array<real_T, 1U> varargin_1;
  coder::array<int8_T, 2U> In;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T beq_data[6];
  real_T b_varargin_1;
  real_T infuence_dist;
  real_T stop_dist;
  real_T varargin_2;
  int32_T input_sizes[2];
  int32_T i;
  int32_T i1;
  int32_T input_sizes_idx_0;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T vectorUB;
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
  if (covrtLogCond(&emlrtCoverageInstance, 0, 0, 0, !is_first_step_not_empty) ||
      covrtLogCond(&emlrtCoverageInstance, 0, 0, 1,
                   !starting_joint_vel_not_empty)) {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    is_first_step = true;
    is_first_step_not_empty = true;
    starting_joint_vel.set_size(&s_emlrtRTEI, sp, joint_values.size(0));
    loop_ub = joint_values.size(0);
    for (i = 0; i < loop_ub; i++) {
      starting_joint_vel[i] = 0.0;
    }
    starting_joint_vel_not_empty = (starting_joint_vel.size(0) != 0);
    //  Default
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, false);
  }
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 1, is_first_step)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
    is_first_step = false;
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
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
  if (covrtLogCond(&emlrtCoverageInstance, 0, 0, 2,
                   configInput->dynamicSlack) &&
      covrtLogCond(&emlrtCoverageInstance, 0, 0, 3,
                   configInput->obstacleAvoidanceScheme)) {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, true);
    if (covrtLogCond(&emlrtCoverageInstance, 0, 0, 4,
                     (J_g.size(0) == 0) || (J_g.size(1) == 0)) ||
        covrtLogCond(&emlrtCoverageInstance, 0, 0, 5, b_g.size(0) == 0)) {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 2, true);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 3, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
      slackIsUsed = false;
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 2, false);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 3, false);
    }
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 1, false);
    covrtLogIf(&emlrtCoverageInstance, 0, 0, 2, false);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
  // ----------------------------------------------------------------------
  //  3. BUILD VELOCITY DAMPER MATRICES IF NEEDED
  // ----------------------------------------------------------------------
  In.set_size(&t_emlrtRTEI, sp, joint_values.size(0), joint_values.size(0));
  loop_ub = joint_values.size(0) * joint_values.size(0);
  for (i = 0; i < loop_ub; i++) {
    In[i] = 0;
  }
  //  Will hold diagonal matrix for damped joints
  bp.set_size(&u_emlrtRTEI, sp, joint_values.size(0));
  loop_ub = joint_values.size(0);
  for (i = 0; i < loop_ub; i++) {
    bp[i] = 0.0;
  }
  //  Will hold vector for velocity damper if needed
  infuence_dist =
      0.017453292519943295 * configInput->jointLimitActivationDistance;
  stop_dist = 0.017453292519943295 * configInput->jointLimitStopDistance;
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 4,
                 configInput->applyVelocityDamper)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 6);
    //  Compute distance to each joint limit, apply a linear velocity damper
    i = jointminvalues.size(0);
    i1 = joint_values.size(0);
    if ((i != i1) && ((i != 1) && (i1 != 1))) {
      emlrtDimSizeImpxCheckR2021b(i, i1, &f_emlrtECI, (emlrtConstCTX)sp);
    }
    i = jointmaxvalues.size(0);
    i1 = joint_values.size(0);
    if ((i != i1) && ((i != 1) && (i1 != 1))) {
      emlrtDimSizeImpxCheckR2021b(i, i1, &e_emlrtECI, (emlrtConstCTX)sp);
    }
    st.site = &emlrtRSI;
    if (jointminvalues.size(0) == joint_values.size(0)) {
      min_dist.set_size(&v_emlrtRTEI, &st, jointminvalues.size(0));
      loop_ub = jointminvalues.size(0);
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointminvalues[i]);
        r1 = _mm_loadu_pd(&joint_values[i]);
        _mm_storeu_pd(&min_dist[i], _mm_sub_pd(r, r1));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        min_dist[i] = jointminvalues[i] - joint_values[i];
      }
      b_st.site = &emlrtRSI;
      coder::b_abs(b_st, min_dist, varargin_1);
    } else {
      b_st.site = &emlrtRSI;
      binary_expand_op_4(b_st, varargin_1, emlrtRSI, jointminvalues,
                         joint_values);
    }
    if (jointmaxvalues.size(0) == joint_values.size(0)) {
      min_dist.set_size(&w_emlrtRTEI, &st, jointmaxvalues.size(0));
      loop_ub = jointmaxvalues.size(0);
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointmaxvalues[i]);
        r1 = _mm_loadu_pd(&joint_values[i]);
        _mm_storeu_pd(&min_dist[i], _mm_sub_pd(r, r1));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        min_dist[i] = jointmaxvalues[i] - joint_values[i];
      }
      b_st.site = &b_emlrtRSI;
      coder::b_abs(b_st, min_dist, lb_joints);
    } else {
      b_st.site = &b_emlrtRSI;
      binary_expand_op_4(b_st, lb_joints, b_emlrtRSI, jointmaxvalues,
                         joint_values);
    }
    b_st.site = &p_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = &r_emlrtRSI;
    e_st.site = &s_emlrtRSI;
    f_st.site = &t_emlrtRSI;
    if (varargin_1.size(0) == lb_joints.size(0)) {
      min_dist.set_size(&x_emlrtRTEI, &f_st, varargin_1.size(0));
      loop_ub = varargin_1.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_varargin_1 = varargin_1[i];
        varargin_2 = lb_joints[i];
        min_dist[i] = muDoubleScalarMin(b_varargin_1, varargin_2);
      }
    } else {
      g_st.site = &u_emlrtRSI;
      coder::internal::expand_min(g_st, varargin_1, lb_joints, min_dist);
    }
    i = joint_values.size(0);
    for (scalarLB = 0; scalarLB < i; scalarLB++) {
      covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
      i1 = min_dist.size(0);
      if (scalarLB + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, i1, &c_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_varargin_1 = min_dist[scalarLB];
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 5,
                     b_varargin_1 < infuence_dist)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 7);
        if (scalarLB + 1 > In.size(0)) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, In.size(0),
                                        &d_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (scalarLB + 1 > In.size(1)) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, In.size(1),
                                        &e_emlrtBCI, (emlrtConstCTX)sp);
        }
        In[scalarLB + In.size(0) * scalarLB] = 1;
        i1 = min_dist.size(0);
        if (scalarLB + 1 > i1) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, i1, &f_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (scalarLB + 1 > bp.size(0)) {
          emlrtDynamicBoundsCheckR2012b(scalarLB + 1, 1, bp.size(0),
                                        &g_emlrtBCI, (emlrtConstCTX)sp);
        }
        bp[scalarLB] = configInput->jointLimitGain *
                       (b_varargin_1 - stop_dist) / (infuence_dist - stop_dist);
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 8);
  // ----------------------------------------------------------------------
  //  4. SET UP CONSTRAINTS AND BOUNDS
  // ----------------------------------------------------------------------
  //  Default: no constraints
  Aeq.set_size(&y_emlrtRTEI, sp, 0, 0);
  input_sizes[0] = 0;
  input_sizes[1] = 0;
  A.set_size(&ab_emlrtRTEI, sp, 0, 0);
  b.set_size(&bb_emlrtRTEI, sp, 0, 0);
  //  Weight matrix for Jacobian in equality constraints
  //  ---- 4.1 Equality constraints ---------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 6,
                 configInput->applyEqualityConstraints)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 9);
    st.site = &c_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    coder::internal::blas::mtimes(b_st, jacobi, Aeq);
    input_sizes[0] = 6;
    input_sizes[1] = 1;
    for (i = 0; i < 6; i++) {
      beq_data[i] = xd_eff_vel[i];
    }
  }
  //  ---- 4.2 Inequality constraints -------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 7,
                 configInput->applyInequalityConstraints)) {
    if ((!covrtLogCond(&emlrtCoverageInstance, 0, 0, 6,
                       (J_g.size(0) == 0) || (J_g.size(1) == 0))) &&
        (!covrtLogCond(&emlrtCoverageInstance, 0, 0, 7, b_g.size(0) == 0))) {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 3, true);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 8, true);
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 9,
                     configInput->applyVelocityDamper)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 10);
        //  Combine both standard inequalities and velocity damper
        st.site = &d_emlrtRSI;
        b_st.site = &y_emlrtRSI;
        c_st.site = &ab_emlrtRSI;
        if ((In.size(1) != J_g.size(1)) &&
            ((In.size(0) != 0) && (In.size(1) != 0))) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        input_sizes_idx_0 = J_g.size(0);
        if ((In.size(0) != 0) && (In.size(1) != 0)) {
          scalarLB = In.size(0);
        } else {
          scalarLB = 0;
        }
        A.set_size(&ib_emlrtRTEI, &b_st, J_g.size(0) + scalarLB, J_g.size(1));
        loop_ub = J_g.size(1);
        for (i = 0; i < loop_ub; i++) {
          for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
            A[i1 + A.size(0) * i] = J_g[i1 + input_sizes_idx_0 * i];
          }
          for (i1 = 0; i1 < scalarLB; i1++) {
            A[(i1 + input_sizes_idx_0) + A.size(0) * i] = In[i1 + scalarLB * i];
          }
        }
        lb_joints.set_size(&jb_emlrtRTEI, sp, b_g.size(0) + bp.size(0));
        loop_ub = b_g.size(0);
        for (i = 0; i < loop_ub; i++) {
          lb_joints[i] = b_g[i];
        }
        loop_ub = bp.size(0);
        for (i = 0; i < loop_ub; i++) {
          lb_joints[i + b_g.size(0)] = bp[i];
        }
        b.set_size(&kb_emlrtRTEI, sp, lb_joints.size(0), 1);
        loop_ub = lb_joints.size(0);
        for (i = 0; i < loop_ub; i++) {
          b[i] = lb_joints[i];
        }
      } else {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 11);
        //  No velocity damper
        A.set_size(&gb_emlrtRTEI, sp, J_g.size(0), J_g.size(1));
        loop_ub = J_g.size(0) * J_g.size(1);
        for (i = 0; i < loop_ub; i++) {
          A[i] = J_g[i];
        }
        b.set_size(&hb_emlrtRTEI, sp, b_g.size(0), 1);
        loop_ub = b_g.size(0);
        for (i = 0; i < loop_ub; i++) {
          b[i] = b_g[i];
        }
      }
    } else {
      covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 3, false);
      covrtLogIf(&emlrtCoverageInstance, 0, 0, 8, false);
      //  If J_g, b_g are empty, we only apply velocity damper if set
      if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 10,
                     configInput->applyVelocityDamper)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 0, 12);
        A.set_size(&eb_emlrtRTEI, sp, In.size(0), In.size(1));
        loop_ub = In.size(0) * In.size(1);
        for (i = 0; i < loop_ub; i++) {
          A[i] = In[i];
        }
        b.set_size(&fb_emlrtRTEI, sp, bp.size(0), 1);
        loop_ub = bp.size(0);
        for (i = 0; i < loop_ub; i++) {
          b[i] = bp[i];
        }
      }
    }

    //  If we do not apply inequality constraints at all but velocity
    //  damper is on, we can still do that by adding A=In, b=bp.
  } else if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 11,
                        configInput->applyVelocityDamper)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 13);
    A.set_size(&cb_emlrtRTEI, sp, In.size(0), In.size(1));
    loop_ub = In.size(0) * In.size(1);
    for (i = 0; i < loop_ub; i++) {
      A[i] = In[i];
    }
    b.set_size(&db_emlrtRTEI, sp, bp.size(0), 1);
    loop_ub = bp.size(0);
    for (i = 0; i < loop_ub; i++) {
      b[i] = bp[i];
    }

    //  if config.applyVelocityDamper && (isempty(J_g) || isempty(b_g))
    //      A = In;
    //      b = bp;
    //  end
  }
  //  ---- 4.3 Determine final use of Slack and build lb, ub --------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 12,
                 covrtLogMcdc(&emlrtCoverageInstance, 0, 0, 4,
                              !covrtLogCond(&emlrtCoverageInstance, 0, 0, 8,
                                            slackIsUsed)))) {
    //  BOUNDS without slack
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 13,
                   configInput->applyVelocityDamper)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 14);
      //  We do not scale velocities by gamma if velocity damper is active
      lb.set_size(&ec_emlrtRTEI, sp, joint_min_vel.size(0), 1);
      loop_ub = joint_min_vel.size(0);
      for (i = 0; i < loop_ub; i++) {
        lb[i] = joint_min_vel[i];
      }
      ub.set_size(&fc_emlrtRTEI, sp, joint_max_vel.size(0), 1);
      loop_ub = joint_max_vel.size(0);
      for (i = 0; i < loop_ub; i++) {
        ub[i] = joint_max_vel[i];
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 15);
      //  Normal bounds: scale the move by config.gamma
      i = jointminvalues.size(0);
      i1 = joint_values.size(0);
      if ((i != i1) && ((i != 1) && (i1 != 1))) {
        emlrtDimSizeImpxCheckR2021b(i, i1, &d_emlrtECI, (emlrtConstCTX)sp);
      }
      st.site = &e_emlrtRSI;
      if (jointminvalues.size(0) == joint_values.size(0)) {
        varargin_1.set_size(&xb_emlrtRTEI, &st, jointminvalues.size(0));
        loop_ub = jointminvalues.size(0);
        scalarLB = (loop_ub / 2) << 1;
        vectorUB = scalarLB - 2;
        for (i = 0; i <= vectorUB; i += 2) {
          r = _mm_loadu_pd(&jointminvalues[i]);
          r1 = _mm_loadu_pd(&joint_values[i]);
          _mm_storeu_pd(
              &varargin_1[i],
              _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
        }
        for (i = scalarLB; i < loop_ub; i++) {
          varargin_1[i] =
              configInput->gamma * (jointminvalues[i] - joint_values[i]);
        }
      } else {
        b_st.site = &e_emlrtRSI;
        binary_expand_op(b_st, varargin_1, configInput, jointminvalues,
                         joint_values);
      }
      b_st.site = &bb_emlrtRSI;
      c_st.site = &cb_emlrtRSI;
      d_st.site = &db_emlrtRSI;
      e_st.site = &s_emlrtRSI;
      f_st.site = &t_emlrtRSI;
      if (varargin_1.size(0) == joint_min_vel.size(0)) {
        min_dist.set_size(&yb_emlrtRTEI, &f_st, varargin_1.size(0));
        loop_ub = varargin_1.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_varargin_1 = varargin_1[i];
          varargin_2 = joint_min_vel[i];
          min_dist[i] = muDoubleScalarMax(b_varargin_1, varargin_2);
        }
      } else {
        g_st.site = &u_emlrtRSI;
        coder::internal::expand_max(g_st, varargin_1, joint_min_vel, min_dist);
      }
      lb.set_size(&ac_emlrtRTEI, sp, min_dist.size(0), 1);
      loop_ub = min_dist.size(0);
      for (i = 0; i < loop_ub; i++) {
        lb[i] = min_dist[i];
      }
      i = jointmaxvalues.size(0);
      i1 = joint_values.size(0);
      if ((i != i1) && ((i != 1) && (i1 != 1))) {
        emlrtDimSizeImpxCheckR2021b(i, i1, &c_emlrtECI, (emlrtConstCTX)sp);
      }
      st.site = &f_emlrtRSI;
      if (jointmaxvalues.size(0) == joint_values.size(0)) {
        varargin_1.set_size(&bc_emlrtRTEI, &st, jointmaxvalues.size(0));
        loop_ub = jointmaxvalues.size(0);
        scalarLB = (loop_ub / 2) << 1;
        vectorUB = scalarLB - 2;
        for (i = 0; i <= vectorUB; i += 2) {
          r = _mm_loadu_pd(&jointmaxvalues[i]);
          r1 = _mm_loadu_pd(&joint_values[i]);
          _mm_storeu_pd(
              &varargin_1[i],
              _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
        }
        for (i = scalarLB; i < loop_ub; i++) {
          varargin_1[i] =
              configInput->gamma * (jointmaxvalues[i] - joint_values[i]);
        }
      } else {
        b_st.site = &f_emlrtRSI;
        binary_expand_op(b_st, varargin_1, configInput, jointmaxvalues,
                         joint_values);
      }
      b_st.site = &p_emlrtRSI;
      c_st.site = &q_emlrtRSI;
      d_st.site = &r_emlrtRSI;
      e_st.site = &s_emlrtRSI;
      f_st.site = &t_emlrtRSI;
      if (varargin_1.size(0) == joint_max_vel.size(0)) {
        lb_joints.set_size(&cc_emlrtRTEI, &f_st, varargin_1.size(0));
        loop_ub = varargin_1.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_varargin_1 = varargin_1[i];
          varargin_2 = joint_max_vel[i];
          lb_joints[i] = muDoubleScalarMin(b_varargin_1, varargin_2);
        }
      } else {
        g_st.site = &u_emlrtRSI;
        coder::internal::expand_min(g_st, varargin_1, joint_max_vel, lb_joints);
      }
      ub.set_size(&dc_emlrtRTEI, sp, lb_joints.size(0), 1);
      loop_ub = lb_joints.size(0);
      for (i = 0; i < loop_ub; i++) {
        ub[i] = lb_joints[i];
      }
    }

    //  BOUNDS with slack
    //     first n_joints are for joint velocities
    //     next   n_slack are for slack
  } else if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 14,
                        configInput->applyVelocityDamper)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 16);
    min_dist.set_size(&tb_emlrtRTEI, sp, joint_min_vel.size(0) + 6);
    loop_ub = joint_min_vel.size(0);
    for (i = 0; i < loop_ub; i++) {
      min_dist[i] = joint_min_vel[i];
    }
    for (i = 0; i < 6; i++) {
      min_dist[i + joint_min_vel.size(0)] = configInput->Slacklowerbound[i];
    }
    lb.set_size(&ub_emlrtRTEI, sp, min_dist.size(0), 1);
    loop_ub = min_dist.size(0);
    for (i = 0; i < loop_ub; i++) {
      lb[i] = min_dist[i];
    }
    lb_joints.set_size(&vb_emlrtRTEI, sp, joint_max_vel.size(0) + 6);
    loop_ub = joint_max_vel.size(0);
    for (i = 0; i < loop_ub; i++) {
      lb_joints[i] = joint_max_vel[i];
    }
    for (i = 0; i < 6; i++) {
      lb_joints[i + joint_max_vel.size(0)] = configInput->Slackupperbound[i];
    }
    ub.set_size(&wb_emlrtRTEI, sp, lb_joints.size(0), 1);
    loop_ub = lb_joints.size(0);
    for (i = 0; i < loop_ub; i++) {
      ub[i] = lb_joints[i];
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 17);
    i = jointminvalues.size(0);
    i1 = joint_values.size(0);
    if ((i != i1) && ((i != 1) && (i1 != 1))) {
      emlrtDimSizeImpxCheckR2021b(i, i1, &b_emlrtECI, (emlrtConstCTX)sp);
    }
    st.site = &g_emlrtRSI;
    if (jointminvalues.size(0) == joint_values.size(0)) {
      varargin_1.set_size(&lb_emlrtRTEI, &st, jointminvalues.size(0));
      loop_ub = jointminvalues.size(0);
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointminvalues[i]);
        r1 = _mm_loadu_pd(&joint_values[i]);
        _mm_storeu_pd(
            &varargin_1[i],
            _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        varargin_1[i] =
            configInput->gamma * (jointminvalues[i] - joint_values[i]);
      }
    } else {
      b_st.site = &g_emlrtRSI;
      binary_expand_op(b_st, varargin_1, configInput, jointminvalues,
                       joint_values);
    }
    b_st.site = &bb_emlrtRSI;
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    e_st.site = &s_emlrtRSI;
    f_st.site = &t_emlrtRSI;
    if (varargin_1.size(0) == joint_min_vel.size(0)) {
      lb_joints.set_size(&mb_emlrtRTEI, &f_st, varargin_1.size(0));
      loop_ub = varargin_1.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_varargin_1 = varargin_1[i];
        varargin_2 = joint_min_vel[i];
        lb_joints[i] = muDoubleScalarMax(b_varargin_1, varargin_2);
      }
    } else {
      g_st.site = &u_emlrtRSI;
      coder::internal::expand_max(g_st, varargin_1, joint_min_vel, lb_joints);
    }
    i = jointmaxvalues.size(0);
    i1 = joint_values.size(0);
    if ((i != i1) && ((i != 1) && (i1 != 1))) {
      emlrtDimSizeImpxCheckR2021b(i, i1, &emlrtECI, (emlrtConstCTX)sp);
    }
    st.site = &h_emlrtRSI;
    if (jointmaxvalues.size(0) == joint_values.size(0)) {
      varargin_1.set_size(&nb_emlrtRTEI, &st, jointmaxvalues.size(0));
      loop_ub = jointmaxvalues.size(0);
      scalarLB = (loop_ub / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i = 0; i <= vectorUB; i += 2) {
        r = _mm_loadu_pd(&jointmaxvalues[i]);
        r1 = _mm_loadu_pd(&joint_values[i]);
        _mm_storeu_pd(
            &varargin_1[i],
            _mm_mul_pd(_mm_set1_pd(configInput->gamma), _mm_sub_pd(r, r1)));
      }
      for (i = scalarLB; i < loop_ub; i++) {
        varargin_1[i] =
            configInput->gamma * (jointmaxvalues[i] - joint_values[i]);
      }
    } else {
      b_st.site = &h_emlrtRSI;
      binary_expand_op(b_st, varargin_1, configInput, jointmaxvalues,
                       joint_values);
    }
    b_st.site = &p_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    d_st.site = &r_emlrtRSI;
    e_st.site = &s_emlrtRSI;
    f_st.site = &t_emlrtRSI;
    if (varargin_1.size(0) == joint_max_vel.size(0)) {
      bp.set_size(&ob_emlrtRTEI, &f_st, varargin_1.size(0));
      loop_ub = varargin_1.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_varargin_1 = varargin_1[i];
        varargin_2 = joint_max_vel[i];
        bp[i] = muDoubleScalarMin(b_varargin_1, varargin_2);
      }
    } else {
      g_st.site = &u_emlrtRSI;
      coder::internal::expand_min(g_st, varargin_1, joint_max_vel, bp);
    }
    min_dist.set_size(&pb_emlrtRTEI, sp, lb_joints.size(0) + 6);
    loop_ub = lb_joints.size(0);
    for (i = 0; i < loop_ub; i++) {
      min_dist[i] = lb_joints[i];
    }
    for (i = 0; i < 6; i++) {
      min_dist[i + lb_joints.size(0)] = configInput->Slacklowerbound[i];
    }
    lb.set_size(&qb_emlrtRTEI, sp, min_dist.size(0), 1);
    loop_ub = min_dist.size(0);
    for (i = 0; i < loop_ub; i++) {
      lb[i] = min_dist[i];
    }
    lb_joints.set_size(&rb_emlrtRTEI, sp, bp.size(0) + 6);
    loop_ub = bp.size(0);
    for (i = 0; i < loop_ub; i++) {
      lb_joints[i] = bp[i];
    }
    for (i = 0; i < 6; i++) {
      lb_joints[i + bp.size(0)] = configInput->Slackupperbound[i];
    }
    ub.set_size(&sb_emlrtRTEI, sp, lb_joints.size(0), 1);
    loop_ub = lb_joints.size(0);
    for (i = 0; i < loop_ub; i++) {
      ub[i] = lb_joints[i];
    }
  }
  //  ---- 4.4 Expand constraints for Slack if needed ----------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 15, slackIsUsed)) {
    //  Expand the equality constraints
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 16,
                   configInput->applyEqualityConstraints)) {
      real_T dv[36];
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 18);
      st.site = &i_emlrtRSI;
      b_st.site = &v_emlrtRSI;
      coder::internal::blas::mtimes(b_st, jacobi, Aeq);
      coder::eye(dv);
      i = Aeq.size(1);
      Aeq.set_size(&gc_emlrtRTEI, sp, Aeq.size(0), Aeq.size(1) + 6);
      input_sizes[0] = 6;
      input_sizes[1] = 1;
      for (i1 = 0; i1 < 6; i1++) {
        for (scalarLB = 0; scalarLB < 6; scalarLB++) {
          Aeq[scalarLB + Aeq.size(0) * (i1 + i)] = dv[scalarLB + 6 * i1];
        }
        beq_data[i1] = xd_eff_vel[i1];
      }
    }
    //  Expand the inequality constraints
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 17,
                   covrtLogMcdc(
                       &emlrtCoverageInstance, 0, 0, 5,
                       !covrtLogCond(&emlrtCoverageInstance, 0, 0, 9,
                                     (A.size(0) == 0) || (A.size(1) == 0))))) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 19);
      st.site = &j_emlrtRSI;
      b_st.site = &y_emlrtRSI;
      scalarLB = A.size(0);
      c_st.site = &ab_emlrtRSI;
      input_sizes_idx_0 = A.size(0);
      vectorUB = A.size(1);
      loop_ub = A.size(1);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < scalarLB; i1++) {
          A[i1 + A.size(0) * i] = A[i1 + input_sizes_idx_0 * i];
        }
      }
      A.set_size(&hc_emlrtRTEI, &b_st, A.size(0), A.size(1) + 6);
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 < scalarLB; i1++) {
          A[i1 + A.size(0) * (i + vectorUB)] = 0.0;
        }
      }
    }
  }
  // ----------------------------------------------------------------------
  //  5. INITIAL GUESS
  // ----------------------------------------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 18, slackIsUsed)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 20);
    optimal_joint_velocity.set_size(&jc_emlrtRTEI, sp,
                                    starting_joint_vel.size(0) + 6);
    loop_ub = starting_joint_vel.size(0);
    for (i = 0; i < loop_ub; i++) {
      optimal_joint_velocity[i] = starting_joint_vel[i];
    }
    for (i = 0; i < 6; i++) {
      optimal_joint_velocity[i + starting_joint_vel.size(0)] = 0.0;
    }
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 21);
    optimal_joint_velocity.set_size(&ic_emlrtRTEI, sp,
                                    starting_joint_vel.size(0));
    loop_ub = starting_joint_vel.size(0);
    for (i = 0; i < loop_ub; i++) {
      optimal_joint_velocity[i] = starting_joint_vel[i];
    }
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 22);
  // ----------------------------------------------------------------------
  //  6. OPTIMIZATION OPTIONS
  // ----------------------------------------------------------------------
  //   % or 'iter' to see solver progress
  // ----------------------------------------------------------------------
  //  7. CALL THE OPTIMIZER (fmincon)
  // ----------------------------------------------------------------------
  b_this.workspace.slackIsUsed = slackIsUsed;
  b_this.workspace.jacobi.set_size(&kc_emlrtRTEI, sp, 6, jacobi.size(1));
  loop_ub = 6 * jacobi.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.jacobi[i] = jacobi[i];
  }
  for (scalarLB = 0; scalarLB < 6; scalarLB++) {
    b_this.workspace.xd_eff_vel[scalarLB] = xd_eff_vel[scalarLB];
  }
  b_this.workspace.starting_joint_vel.set_size(&lc_emlrtRTEI, sp,
                                               starting_joint_vel.size(0));
  loop_ub = starting_joint_vel.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.starting_joint_vel[i] = starting_joint_vel[i];
  }
  b_this.workspace.joint_values.set_size(&lc_emlrtRTEI, sp,
                                         joint_values.size(0));
  loop_ub = joint_values.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.joint_values[i] = joint_values[i];
  }
  b_this.workspace.jointVelocityWeightMatrix.set_size(
      &kc_emlrtRTEI, sp, jointVelocityWeightMatrix.size(0),
      jointVelocityWeightMatrix.size(1));
  loop_ub =
      jointVelocityWeightMatrix.size(0) * jointVelocityWeightMatrix.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.jointVelocityWeightMatrix[i] =
        jointVelocityWeightMatrix[i];
  }
  b_this.workspace.config = *configInput;
  st.site = &k_emlrtRSI;
  coder::fmincon(st, b_this, optimal_joint_velocity, A, b, Aeq, beq_data,
                 input_sizes, lb, ub, Exit_Flag);
  // ----------------------------------------------------------------------
  //  8. EXTRACT THE RESULT
  // ----------------------------------------------------------------------
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 19, slackIsUsed)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 24);
    if (joint_values.size(0) < 1) {
      i = 0;
    } else {
      if (optimal_joint_velocity.size(0) < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, optimal_joint_velocity.size(0),
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      i = joint_values.size(0);
      if ((i < 1) || (i > optimal_joint_velocity.size(0))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, optimal_joint_velocity.size(0),
                                      &emlrtBCI, (emlrtConstCTX)sp);
      }
    }
    input_sizes[0] = 1;
    input_sizes[1] = i;
    st.site = &l_emlrtRSI;
    coder::internal::indexShapeCheck(st, optimal_joint_velocity.size(0),
                                     input_sizes);
    optimal_joint_velocity.set_size(&mc_emlrtRTEI, sp, i);
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 25);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 26);
  // ----------------------------------------------------------------------
  //  9. UPDATE PERSISTENT STATE
  // ----------------------------------------------------------------------
  starting_joint_vel.set_size(&nc_emlrtRTEI, sp,
                              optimal_joint_velocity.size(0));
  loop_ub = optimal_joint_velocity.size(0);
  for (i = 0; i < loop_ub; i++) {
    starting_joint_vel[i] = optimal_joint_velocity[i];
  }
  starting_joint_vel_not_empty = (starting_joint_vel.size(0) != 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (inverseKinematicsOAModified.cpp)
