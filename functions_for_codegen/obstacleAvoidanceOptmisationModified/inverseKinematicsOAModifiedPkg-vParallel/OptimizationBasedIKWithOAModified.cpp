//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: OptimizationBasedIKWithOAModified.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "OptimizationBasedIKWithOAModified.h"
#include "anonymous_function.h"
#include "configurableObjective.h"
#include "eml_int_forloop_overflow_check.h"
#include "fmincon.h"
#include "indexShapeCheck.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_internal_types1.h"
#include "inverseKinematicsOAModified_rtwutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "ixfun.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const struct0_T *in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4);

static void inverseKinematicsOAModified_init(
    OptimizationBasedIKWithOAModified *aInstancePtr);

static void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : void
// Return Type  : inverseKinematicsOAModifiedStackData *
//
inverseKinematicsOAModifiedStackData *
OptimizationBasedIKWithOAModified::getStackData()
{
  return &SD_;
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const struct0_T *in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const struct0_T *in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  if (static_cast<int>(loop_ub < 1600)) {
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2->gamma * (in3[i * stride_0_0] - in4[i * stride_1_0]);
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int i = 0; i < loop_ub; i++) {
      in1[i] = in2->gamma * (in3[i * stride_0_0] - in4[i * stride_1_0]);
    }
  }
}

//
// function [optimal_joint_velocity, Exit_Flag] = inverseKinematicsOAModified(
// ...
//     joint_values,       ... % [n_joints x 1]
//     jacobi,             ... % [6 x n_joints]
//     xd_eff_vel,         ... % [6 x 1]
//     jointminvalues,     ... % [n_joints x 1]
//     jointmaxvalues,     ... % [n_joints x 1]
//     joint_min_vel,      ... % [n_joints x 1]
//     joint_max_vel,      ... % [n_joints x 1]
//     J_g,                ... % Inequality constraint matrix
//     b_g,                ... % Inequality constraint vector
//     jointVelocityWeightMatrix, ...
//     configInput)
//
// % [n_joints x 1]
//  % [6 x n_joints]
//  % [6 x 1]
//  % [n_joints x 1]
//  % [n_joints x 1]
//  % [n_joints x 1]
//  % [n_joints x 1]
//  % Inequality constraint matrix
//  % Inequality constraint vector
//
// Arguments    : OptimizationBasedIKWithOAModified *aInstancePtr
// Return Type  : void
//
static void inverseKinematicsOAModified_init(
    OptimizationBasedIKWithOAModified *aInstancePtr)
{
  inverseKinematicsOAModifiedStackData *localSD;
  localSD = aInstancePtr->getStackData();
  localSD->pd->starting_joint_vel_not_empty = false;
}

//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Dimensions of arrays being concatenated are not consistent.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : void
// Return Type  : void
//
OptimizationBasedIKWithOAModified::OptimizationBasedIKWithOAModified()
{
  SD_.pd = &pd_;
  omp_init_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
  inverseKinematicsOAModified_init(this);
}

//
// Arguments    : void
// Return Type  : void
//
OptimizationBasedIKWithOAModified::~OptimizationBasedIKWithOAModified()
{
  omp_destroy_nest_lock(&inverseKinematicsOAModified_nestLockGlobal);
}

//
// function [optimal_joint_velocity, Exit_Flag] = inverseKinematicsOAModified(
// ...
//     joint_values,       ... % [n_joints x 1]
//     jacobi,             ... % [6 x n_joints]
//     xd_eff_vel,         ... % [6 x 1]
//     jointminvalues,     ... % [n_joints x 1]
//     jointmaxvalues,     ... % [n_joints x 1]
//     joint_min_vel,      ... % [n_joints x 1]
//     joint_max_vel,      ... % [n_joints x 1]
//     J_g,                ... % Inequality constraint matrix
//     b_g,                ... % Inequality constraint vector
//     jointVelocityWeightMatrix, ...
//     configInput)
//
// % [n_joints x 1]
//  % [6 x n_joints]
//  % [6 x 1]
//  % [n_joints x 1]
//  % [n_joints x 1]
//  % [n_joints x 1]
//  % [n_joints x 1]
//  % Inequality constraint matrix
//  % Inequality constraint vector
//
// Arguments    : const coder::array<double, 1U> &joint_values
//                const coder::array<double, 2U> &jacobi
//                const double xd_eff_vel[6]
//                const coder::array<double, 1U> &jointminvalues
//                const coder::array<double, 1U> &jointmaxvalues
//                const coder::array<double, 1U> &joint_min_vel
//                const coder::array<double, 1U> &joint_max_vel
//                const coder::array<double, 2U> &J_g
//                const coder::array<double, 1U> &b_g
//                const coder::array<double, 2U> &jointVelocityWeightMatrix
//                const struct0_T *configInput
//                coder::array<double, 1U> &optimal_joint_velocity
//                double *Exit_Flag
// Return Type  : void
//
void OptimizationBasedIKWithOAModified::inverseKinematicsOAModified(
    const coder::array<double, 1U> &joint_values,
    const coder::array<double, 2U> &jacobi, const double xd_eff_vel[6],
    const coder::array<double, 1U> &jointminvalues,
    const coder::array<double, 1U> &jointmaxvalues,
    const coder::array<double, 1U> &joint_min_vel,
    const coder::array<double, 1U> &joint_max_vel,
    const coder::array<double, 2U> &J_g, const coder::array<double, 1U> &b_g,
    const coder::array<double, 2U> &jointVelocityWeightMatrix,
    const struct0_T *configInput,
    coder::array<double, 1U> &optimal_joint_velocity, double *Exit_Flag)
{
  static rtBoundsCheckInfo ab_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      62,                            // lineNo
      20,                            // colNo
      "bp",                          // aName
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m", // pName
      0                                    // checkKind
  };
  static rtBoundsCheckInfo bb_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      62,                            // lineNo
      51,                            // colNo
      "min_dist",                    // aName
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m", // pName
      0                                    // checkKind
  };
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      209,                           // lineNo
      44,                            // colNo
      "q_vel_opt",                   // aName
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m", // pName
      0                                    // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      209,                           // lineNo
      46,                            // colNo
      "q_vel_opt",                   // aName
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m", // pName
      0                                    // checkKind
  };
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      60,                            // lineNo
      25,                            // colNo
      "min_dist",                    // aName
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m", // pName
      0                                    // checkKind
  };
  static rtBoundsCheckInfo x_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      61,                            // lineNo
      22,                            // colNo
      "In",                          // aName
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m", // pName
      0                                    // checkKind
  };
  static rtBoundsCheckInfo y_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      61,                            // lineNo
      20,                            // colNo
      "In",                          // aName
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m", // pName
      0                                    // checkKind
  };
  static rtEqualityCheckInfo b_emlrtECI{
      1,                             // nDims
      58,                            // lineNo
      28,                            // colNo
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m" // pName
  };
  static rtEqualityCheckInfo c_emlrtECI{
      1,                             // nDims
      129,                           // lineNo
      39,                            // colNo
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m" // pName
  };
  static rtEqualityCheckInfo d_emlrtECI{
      1,                             // nDims
      130,                           // lineNo
      39,                            // colNo
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m" // pName
  };
  static rtEqualityCheckInfo e_emlrtECI{
      1,                             // nDims
      144,                           // lineNo
      46,                            // colNo
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m" // pName
  };
  static rtEqualityCheckInfo emlrtECI{
      1,                             // nDims
      57,                            // lineNo
      28,                            // colNo
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m" // pName
  };
  static rtEqualityCheckInfo f_emlrtECI{
      1,                             // nDims
      145,                           // lineNo
      46,                            // colNo
      "inverseKinematicsOAModified", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/inverseKinematicsOAModified.m" // pName
  };
  static rtRunTimeErrorInfo e_emlrtRTEI{
      288,                  // lineNo
      "check_non_axis_size" // fName
  };
  coder::anonymous_function b_this;
  coder::array<double, 2U> A;
  coder::array<double, 2U> Aeq;
  coder::array<double, 2U> b;
  coder::array<double, 2U> lb;
  coder::array<double, 2U> ub;
  coder::array<double, 1U> bp;
  coder::array<double, 1U> min_dist;
  coder::array<double, 1U> varargin_1;
  coder::array<double, 1U> varargin_2;
  coder::array<signed char, 2U> In;
  double beq_data[6];
  double b_varargin_1;
  double b_varargin_2;
  double c_varargin_1;
  double c_varargin_2;
  double infuence_dist;
  double stop_dist;
  int input_sizes[2];
  int i;
  int i1;
  int loop_ub;
  int loop_ub_tmp;
  int nx;
  int sizes_idx_1;
  boolean_T slackIsUsed;
  // ----------------------------------------------------------------------
  //  1. PERSISTENT VARIABLES
  // ----------------------------------------------------------------------
  // 'inverseKinematicsOAModified:19' n_joints = length(joint_values);
  //  Number of joints
  // 'inverseKinematicsOAModified:20' n_slack  = 6;
  //  One slack variable per end-effector velocity component (if used)
  //  Initialize the persistent variables only on the first call
  // 'inverseKinematicsOAModified:23' if isempty(starting_joint_vel)
  if (!pd_.starting_joint_vel_not_empty) {
    // 'inverseKinematicsOAModified:24' starting_joint_vel = zeros(n_joints,1);
    pd_.starting_joint_vel.set_size(joint_values.size(0));
    loop_ub = joint_values.size(0);
    if (static_cast<int>(joint_values.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        pd_.starting_joint_vel[k] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        pd_.starting_joint_vel[k] = 0.0;
      }
    }
    pd_.starting_joint_vel_not_empty = (pd_.starting_joint_vel.size(0) != 0);
    //  Default
  }
  //  Unpack config for convenience
  // 'inverseKinematicsOAModified:28' config = configInput;
  // ----------------------------------------------------------------------
  //  2. DETERMINE IF SLACK IS ACTUALLY USED
  // ----------------------------------------------------------------------
  //  The new dynamic logic:
  //    - If config.dynamicSlack is true AND (J_g or b_g are empty),
  //      we forcibly turn off slack.
  //    - Otherwise, we do whatever config.applySlack says.
  //
  // 'inverseKinematicsOAModified:38' slackIsUsed = config.applySlack;
  slackIsUsed = configInput->applySlack;
  // 'inverseKinematicsOAModified:39' if config.dynamicSlack &&
  // config.obstacleAvoidanceScheme
  if (configInput->dynamicSlack && configInput->obstacleAvoidanceScheme &&
      ((J_g.size(0) == 0) || (J_g.size(1) == 0) || (b_g.size(0) == 0))) {
    // 'inverseKinematicsOAModified:40' if isempty(J_g) || isempty(b_g)
    // 'inverseKinematicsOAModified:41' slackIsUsed = false;
    slackIsUsed = false;
  }
  // ----------------------------------------------------------------------
  //  3. BUILD VELOCITY DAMPER MATRICES IF NEEDED
  // ----------------------------------------------------------------------
  // 'inverseKinematicsOAModified:48' In            = zeros(n_joints);
  In.set_size(joint_values.size(0), joint_values.size(0));
  loop_ub_tmp = joint_values.size(0) * joint_values.size(0);
  i = (loop_ub_tmp < 1600);
  if (i) {
    for (int k{0}; k < loop_ub_tmp; k++) {
      In[k] = 0;
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int k = 0; k < loop_ub_tmp; k++) {
      In[k] = 0;
    }
  }
  //  Will hold diagonal matrix for damped joints
  // 'inverseKinematicsOAModified:49' bp            = zeros(n_joints,1);
  bp.set_size(joint_values.size(0));
  loop_ub = joint_values.size(0);
  i1 = (joint_values.size(0) < 1600);
  if (i1) {
    for (int k{0}; k < loop_ub; k++) {
      bp[k] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int k = 0; k < loop_ub; k++) {
      bp[k] = 0.0;
    }
  }
  //  Will hold vector for velocity damper if needed
  // 'inverseKinematicsOAModified:50' infuence_dist =
  // deg2rad(config.jointLimitActivationDistance);
  infuence_dist =
      0.017453292519943295 * configInput->jointLimitActivationDistance;
  // 'inverseKinematicsOAModified:51' stop_dist     =
  // deg2rad(config.jointLimitStopDistance);
  stop_dist = 0.017453292519943295 * configInput->jointLimitStopDistance;
  // 'inverseKinematicsOAModified:52' joint_gain    = config.jointLimitGain;
  // 'inverseKinematicsOAModified:54' if config.applyVelocityDamper
  if (configInput->applyVelocityDamper) {
    //  Compute distance to each joint limit, apply a linear velocity damper
    // 'inverseKinematicsOAModified:57' min_dist = min(abs(jointminvalues -
    // joint_values), ... 'inverseKinematicsOAModified:58' abs(jointmaxvalues -
    // joint_values));
    if ((jointminvalues.size(0) != joint_values.size(0)) &&
        ((jointminvalues.size(0) != 1) && (joint_values.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointminvalues.size(0), joint_values.size(0),
                                  emlrtECI);
    }
    if ((jointmaxvalues.size(0) != joint_values.size(0)) &&
        ((jointmaxvalues.size(0) != 1) && (joint_values.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointmaxvalues.size(0), joint_values.size(0),
                                  b_emlrtECI);
    }
    if (jointminvalues.size(0) == joint_values.size(0)) {
      min_dist.set_size(jointminvalues.size(0));
      loop_ub = jointminvalues.size(0);
      if (static_cast<int>(jointminvalues.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          min_dist[k] = jointminvalues[k] - joint_values[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          min_dist[k] = jointminvalues[k] - joint_values[k];
        }
      }
    } else {
      minus(min_dist, jointminvalues, joint_values);
    }
    nx = min_dist.size(0);
    varargin_1.set_size(min_dist.size(0));
    if (min_dist.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    sizes_idx_1 = (min_dist.size(0) < 1600);
    if (sizes_idx_1) {
      for (int k{0}; k < nx; k++) {
        varargin_1[k] = std::abs(min_dist[k]);
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < nx; k++) {
        varargin_1[k] = std::abs(min_dist[k]);
      }
    }
    if (jointmaxvalues.size(0) == joint_values.size(0)) {
      min_dist.set_size(jointmaxvalues.size(0));
      loop_ub = jointmaxvalues.size(0);
      if (static_cast<int>(jointmaxvalues.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          min_dist[k] = jointmaxvalues[k] - joint_values[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          min_dist[k] = jointmaxvalues[k] - joint_values[k];
        }
      }
    } else {
      minus(min_dist, jointmaxvalues, joint_values);
    }
    nx = min_dist.size(0);
    varargin_2.set_size(min_dist.size(0));
    if (min_dist.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    if (static_cast<int>(min_dist.size(0) < 1600)) {
      for (int k{0}; k < nx; k++) {
        varargin_2[k] = std::abs(min_dist[k]);
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < nx; k++) {
        varargin_2[k] = std::abs(min_dist[k]);
      }
    }
    if (varargin_1.size(0) == varargin_2.size(0)) {
      min_dist.set_size(varargin_1.size(0));
      loop_ub = varargin_1.size(0);
      if (sizes_idx_1) {
        for (int k{0}; k < loop_ub; k++) {
          b_varargin_1 = varargin_1[k];
          b_varargin_2 = varargin_2[k];
          min_dist[k] = std::fmin(b_varargin_1, b_varargin_2);
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(c_varargin_1, c_varargin_2)

        for (int k = 0; k < loop_ub; k++) {
          c_varargin_1 = varargin_1[k];
          c_varargin_2 = varargin_2[k];
          min_dist[k] = std::fmin(c_varargin_1, c_varargin_2);
        }
      }
    } else {
      coder::internal::expand_min(varargin_1, varargin_2, min_dist);
    }
    // 'inverseKinematicsOAModified:59' for i = 1:n_joints
    sizes_idx_1 = joint_values.size(0);
    for (nx = 0; nx < sizes_idx_1; nx++) {
      // 'inverseKinematicsOAModified:60' if min_dist(i) < infuence_dist
      if (nx + 1 > min_dist.size(0)) {
        rtDynamicBoundsError(nx + 1, 1, min_dist.size(0), w_emlrtBCI);
      }
      b_varargin_1 = min_dist[nx];
      if (b_varargin_1 < infuence_dist) {
        // 'inverseKinematicsOAModified:61' In(i,i)  = 1;
        if (nx + 1 > In.size(1)) {
          rtDynamicBoundsError(nx + 1, 1, In.size(1), x_emlrtBCI);
        }
        if (nx + 1 > In.size(0)) {
          rtDynamicBoundsError(nx + 1, 1, In.size(0), y_emlrtBCI);
        }
        In[nx + In.size(0) * nx] = 1;
        // 'inverseKinematicsOAModified:62' bp(i)    = joint_gain * (min_dist(i)
        // - stop_dist)/(infuence_dist - stop_dist);
        if (nx + 1 > bp.size(0)) {
          rtDynamicBoundsError(nx + 1, 1, bp.size(0), ab_emlrtBCI);
        }
        if (nx + 1 > min_dist.size(0)) {
          rtDynamicBoundsError(nx + 1, 1, min_dist.size(0), bb_emlrtBCI);
        }
        bp[nx] = configInput->jointLimitGain * (b_varargin_1 - stop_dist) /
                 (infuence_dist - stop_dist);
      }
    }
  }
  // ----------------------------------------------------------------------
  //  4. SET UP CONSTRAINTS AND BOUNDS
  // ----------------------------------------------------------------------
  //  Default: no constraints
  // 'inverseKinematicsOAModified:71' Aeq = [];
  Aeq.set_size(0, 0);
  // 'inverseKinematicsOAModified:72' beq = [];
  input_sizes[0] = 0;
  input_sizes[1] = 0;
  // 'inverseKinematicsOAModified:73' A   = [];
  A.set_size(0, 0);
  // 'inverseKinematicsOAModified:74' b   = [];
  b.set_size(0, 0);
  // 'inverseKinematicsOAModified:75' lb  = [];
  // 'inverseKinematicsOAModified:76' ub  = [];
  //  Weight matrix for Jacobian in equality constraints
  // 'inverseKinematicsOAModified:79' JacobiWeightMatrix = diag([1,1,1,1,1,1]);
  //  ---- 4.1 Equality constraints ---------------------------------------
  // 'inverseKinematicsOAModified:82' if config.applyEqualityConstraints
  if (configInput->applyEqualityConstraints) {
    // 'inverseKinematicsOAModified:83' Aeq = JacobiWeightMatrix * jacobi;
    coder::internal::blas::mtimes(jacobi, Aeq);
    // 'inverseKinematicsOAModified:84' beq = xd_eff_vel;
    input_sizes[0] = 6;
    input_sizes[1] = 1;
    for (sizes_idx_1 = 0; sizes_idx_1 < 6; sizes_idx_1++) {
      beq_data[sizes_idx_1] = xd_eff_vel[sizes_idx_1];
    }
  }
  //  ---- 4.2 Inequality constraints -------------------------------------
  // 'inverseKinematicsOAModified:88' if config.applyInequalityConstraints
  if (configInput->applyInequalityConstraints) {
    // 'inverseKinematicsOAModified:89' if ~isempty(J_g) && ~isempty(b_g)
    if ((J_g.size(0) != 0) && (J_g.size(1) != 0) && (b_g.size(0) != 0)) {
      // 'inverseKinematicsOAModified:90' if config.applyVelocityDamper
      if (configInput->applyVelocityDamper) {
        //  Combine both standard inequalities and velocity damper
        // 'inverseKinematicsOAModified:92' A = [J_g; In];
        if ((In.size(1) != J_g.size(1)) &&
            ((In.size(0) != 0) && (In.size(1) != 0))) {
          rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
        }
        nx = J_g.size(0);
        if ((In.size(0) != 0) && (In.size(1) != 0)) {
          loop_ub_tmp = In.size(0);
        } else {
          loop_ub_tmp = 0;
        }
        A.set_size(J_g.size(0) + loop_ub_tmp, J_g.size(1));
        loop_ub = J_g.size(1);
        for (i = 0; i < loop_ub; i++) {
          for (sizes_idx_1 = 0; sizes_idx_1 < nx; sizes_idx_1++) {
            A[sizes_idx_1 + A.size(0) * i] = J_g[sizes_idx_1 + nx * i];
          }
          for (sizes_idx_1 = 0; sizes_idx_1 < loop_ub_tmp; sizes_idx_1++) {
            A[(sizes_idx_1 + nx) + A.size(0) * i] =
                In[sizes_idx_1 + loop_ub_tmp * i];
          }
        }
        // 'inverseKinematicsOAModified:93' b = [b_g; bp];
        min_dist.set_size(b_g.size(0) + bp.size(0));
        loop_ub = b_g.size(0);
        if (static_cast<int>(b_g.size(0) < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            min_dist[k] = b_g[k];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

          for (int k = 0; k < loop_ub; k++) {
            min_dist[k] = b_g[k];
          }
        }
        loop_ub = bp.size(0);
        if (i1) {
          for (int k{0}; k < loop_ub; k++) {
            min_dist[k + b_g.size(0)] = bp[k];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

          for (int k = 0; k < loop_ub; k++) {
            min_dist[k + b_g.size(0)] = bp[k];
          }
        }
        b.set_size(min_dist.size(0), 1);
        loop_ub = min_dist.size(0);
        if (static_cast<int>(min_dist.size(0) < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            b[k] = min_dist[k];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

          for (int k = 0; k < loop_ub; k++) {
            b[k] = min_dist[k];
          }
        }
      } else {
        // 'inverseKinematicsOAModified:94' else
        //  No velocity damper
        // 'inverseKinematicsOAModified:96' A = J_g;
        A.set_size(J_g.size(0), J_g.size(1));
        loop_ub = J_g.size(0) * J_g.size(1);
        if (static_cast<int>(loop_ub < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            A[k] = J_g[k];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

          for (int k = 0; k < loop_ub; k++) {
            A[k] = J_g[k];
          }
        }
        // 'inverseKinematicsOAModified:97' b = b_g;
        b.set_size(b_g.size(0), 1);
        loop_ub = b_g.size(0);
        if (static_cast<int>(b_g.size(0) < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            b[k] = b_g[k];
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

          for (int k = 0; k < loop_ub; k++) {
            b[k] = b_g[k];
          }
        }
      }

      // 'inverseKinematicsOAModified:99' else
      //  If J_g, b_g are empty, we only apply velocity damper if set
      // 'inverseKinematicsOAModified:101' if config.applyVelocityDamper
    } else if (configInput->applyVelocityDamper) {
      // 'inverseKinematicsOAModified:102' A = In;
      A.set_size(In.size(0), In.size(1));
      if (i) {
        for (int k{0}; k < loop_ub_tmp; k++) {
          A[k] = In[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub_tmp; k++) {
          A[k] = In[k];
        }
      }
      // 'inverseKinematicsOAModified:103' b = bp;
      b.set_size(bp.size(0), 1);
      loop_ub = bp.size(0);
      if (i1) {
        for (int k{0}; k < loop_ub; k++) {
          b[k] = bp[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          b[k] = bp[k];
        }
      }
    }

    // 'inverseKinematicsOAModified:106' else
    //  If we do not apply inequality constraints at all but velocity
    //  damper is on, we can still do that by adding A=In, b=bp.
    // 'inverseKinematicsOAModified:109' if config.applyVelocityDamper
  } else if (configInput->applyVelocityDamper) {
    // 'inverseKinematicsOAModified:110' A = In;
    A.set_size(In.size(0), In.size(1));
    if (i) {
      for (int k{0}; k < loop_ub_tmp; k++) {
        A[k] = In[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub_tmp; k++) {
        A[k] = In[k];
      }
    }
    // 'inverseKinematicsOAModified:111' b = bp;
    b.set_size(bp.size(0), 1);
    loop_ub = bp.size(0);
    if (i1) {
      for (int k{0}; k < loop_ub; k++) {
        b[k] = bp[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        b[k] = bp[k];
      }
    }

    //  if config.applyVelocityDamper && (isempty(J_g) || isempty(b_g))
    //      A = In;
    //      b = bp;
    //  end
  }
  //  ---- 4.3 Determine final use of Slack and build lb, ub --------------
  // 'inverseKinematicsOAModified:121' if ~slackIsUsed
  if (!slackIsUsed) {
    //  BOUNDS without slack
    // 'inverseKinematicsOAModified:123' if config.applyVelocityDamper
    if (configInput->applyVelocityDamper) {
      //  We do not scale velocities by gamma if velocity damper is active
      // 'inverseKinematicsOAModified:125' lb = joint_min_vel;
      lb.set_size(joint_min_vel.size(0), 1);
      loop_ub = joint_min_vel.size(0);
      if (static_cast<int>(joint_min_vel.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          lb[k] = joint_min_vel[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          lb[k] = joint_min_vel[k];
        }
      }
      // 'inverseKinematicsOAModified:126' ub = joint_max_vel;
      ub.set_size(joint_max_vel.size(0), 1);
      loop_ub = joint_max_vel.size(0);
      if (static_cast<int>(joint_max_vel.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          ub[k] = joint_max_vel[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          ub[k] = joint_max_vel[k];
        }
      }
    } else {
      // 'inverseKinematicsOAModified:127' else
      //  Normal bounds: scale the move by config.gamma
      // 'inverseKinematicsOAModified:129' lb = max(config.gamma .*
      // (jointminvalues - joint_values), joint_min_vel);
      if ((jointminvalues.size(0) != joint_values.size(0)) &&
          ((jointminvalues.size(0) != 1) && (joint_values.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(jointminvalues.size(0),
                                    joint_values.size(0), c_emlrtECI);
      }
      if (jointminvalues.size(0) == joint_values.size(0)) {
        varargin_1.set_size(jointminvalues.size(0));
        loop_ub = jointminvalues.size(0);
        if (static_cast<int>(jointminvalues.size(0) < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            varargin_1[k] =
                configInput->gamma * (jointminvalues[k] - joint_values[k]);
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

          for (int k = 0; k < loop_ub; k++) {
            varargin_1[k] =
                configInput->gamma * (jointminvalues[k] - joint_values[k]);
          }
        }
      } else {
        binary_expand_op(varargin_1, configInput, jointminvalues, joint_values);
      }
      if (varargin_1.size(0) == joint_min_vel.size(0)) {
        varargin_2.set_size(varargin_1.size(0));
        loop_ub = varargin_1.size(0);
        if (static_cast<int>(varargin_1.size(0) < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            b_varargin_1 = varargin_1[k];
            b_varargin_2 = joint_min_vel[k];
            varargin_2[k] = std::fmax(b_varargin_1, b_varargin_2);
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(c_varargin_1, c_varargin_2)

          for (int k = 0; k < loop_ub; k++) {
            c_varargin_1 = varargin_1[k];
            c_varargin_2 = joint_min_vel[k];
            varargin_2[k] = std::fmax(c_varargin_1, c_varargin_2);
          }
        }
      } else {
        coder::internal::expand_max(varargin_1, joint_min_vel, varargin_2);
      }
      lb.set_size(varargin_2.size(0), 1);
      loop_ub = varargin_2.size(0);
      if (static_cast<int>(varargin_2.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          lb[k] = varargin_2[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          lb[k] = varargin_2[k];
        }
      }
      // 'inverseKinematicsOAModified:130' ub = min(config.gamma .*
      // (jointmaxvalues - joint_values), joint_max_vel);
      if ((jointmaxvalues.size(0) != joint_values.size(0)) &&
          ((jointmaxvalues.size(0) != 1) && (joint_values.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(jointmaxvalues.size(0),
                                    joint_values.size(0), d_emlrtECI);
      }
      if (jointmaxvalues.size(0) == joint_values.size(0)) {
        varargin_1.set_size(jointmaxvalues.size(0));
        loop_ub = jointmaxvalues.size(0);
        if (static_cast<int>(jointmaxvalues.size(0) < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            varargin_1[k] =
                configInput->gamma * (jointmaxvalues[k] - joint_values[k]);
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

          for (int k = 0; k < loop_ub; k++) {
            varargin_1[k] =
                configInput->gamma * (jointmaxvalues[k] - joint_values[k]);
          }
        }
      } else {
        binary_expand_op(varargin_1, configInput, jointmaxvalues, joint_values);
      }
      if (varargin_1.size(0) == joint_max_vel.size(0)) {
        min_dist.set_size(varargin_1.size(0));
        loop_ub = varargin_1.size(0);
        if (static_cast<int>(varargin_1.size(0) < 1600)) {
          for (int k{0}; k < loop_ub; k++) {
            b_varargin_1 = varargin_1[k];
            b_varargin_2 = joint_max_vel[k];
            min_dist[k] = std::fmin(b_varargin_1, b_varargin_2);
          }
        } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(c_varargin_1, c_varargin_2)

          for (int k = 0; k < loop_ub; k++) {
            c_varargin_1 = varargin_1[k];
            c_varargin_2 = joint_max_vel[k];
            min_dist[k] = std::fmin(c_varargin_1, c_varargin_2);
          }
        }
      } else {
        coder::internal::expand_min(varargin_1, joint_max_vel, min_dist);
      }
      ub.set_size(min_dist.size(0), 1);
      loop_ub = min_dist.size(0);
      if (static_cast<int>(min_dist.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          ub[k] = min_dist[k];
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          ub[k] = min_dist[k];
        }
      }
    }

    // 'inverseKinematicsOAModified:132' else
    //  BOUNDS with slack
    //     first n_joints are for joint velocities
    //     next   n_slack are for slack
    // 'inverseKinematicsOAModified:136' if config.applyVelocityDamper
  } else if (configInput->applyVelocityDamper) {
    // 'inverseKinematicsOAModified:137' lb_joints = joint_min_vel;
    // 'inverseKinematicsOAModified:138' ub_joints = joint_max_vel;
    // 'inverseKinematicsOAModified:139' lb_slack = config.Slacklowerbound;
    // 'inverseKinematicsOAModified:140' ub_slack = config.Slackupperbound;
    // 'inverseKinematicsOAModified:141' lb       = [lb_joints; lb_slack];
    varargin_2.set_size(joint_min_vel.size(0) + 6);
    loop_ub = joint_min_vel.size(0);
    if (static_cast<int>(joint_min_vel.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        varargin_2[k] = joint_min_vel[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        varargin_2[k] = joint_min_vel[k];
      }
    }
    for (i = 0; i < 6; i++) {
      varargin_2[i + joint_min_vel.size(0)] = configInput->Slacklowerbound[i];
    }
    lb.set_size(varargin_2.size(0), 1);
    loop_ub = varargin_2.size(0);
    if (static_cast<int>(varargin_2.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        lb[k] = varargin_2[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        lb[k] = varargin_2[k];
      }
    }
    // 'inverseKinematicsOAModified:142' ub       = [ub_joints; ub_slack];
    min_dist.set_size(joint_max_vel.size(0) + 6);
    loop_ub = joint_max_vel.size(0);
    if (static_cast<int>(joint_max_vel.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        min_dist[k] = joint_max_vel[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        min_dist[k] = joint_max_vel[k];
      }
    }
    for (i = 0; i < 6; i++) {
      min_dist[i + joint_max_vel.size(0)] = configInput->Slackupperbound[i];
    }
    ub.set_size(min_dist.size(0), 1);
    loop_ub = min_dist.size(0);
    if (static_cast<int>(min_dist.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        ub[k] = min_dist[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        ub[k] = min_dist[k];
      }
    }
  } else {
    // 'inverseKinematicsOAModified:143' else
    // 'inverseKinematicsOAModified:144' lb_joints = max(config.gamma .*
    // (jointminvalues - joint_values), joint_min_vel);
    if ((jointminvalues.size(0) != joint_values.size(0)) &&
        ((jointminvalues.size(0) != 1) && (joint_values.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointminvalues.size(0), joint_values.size(0),
                                  e_emlrtECI);
    }
    if (jointminvalues.size(0) == joint_values.size(0)) {
      varargin_1.set_size(jointminvalues.size(0));
      loop_ub = jointminvalues.size(0);
      if (static_cast<int>(jointminvalues.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          varargin_1[k] =
              configInput->gamma * (jointminvalues[k] - joint_values[k]);
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          varargin_1[k] =
              configInput->gamma * (jointminvalues[k] - joint_values[k]);
        }
      }
    } else {
      binary_expand_op(varargin_1, configInput, jointminvalues, joint_values);
    }
    if (varargin_1.size(0) == joint_min_vel.size(0)) {
      min_dist.set_size(varargin_1.size(0));
      loop_ub = varargin_1.size(0);
      if (static_cast<int>(varargin_1.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          b_varargin_1 = varargin_1[k];
          b_varargin_2 = joint_min_vel[k];
          min_dist[k] = std::fmax(b_varargin_1, b_varargin_2);
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(c_varargin_1, c_varargin_2)

        for (int k = 0; k < loop_ub; k++) {
          c_varargin_1 = varargin_1[k];
          c_varargin_2 = joint_min_vel[k];
          min_dist[k] = std::fmax(c_varargin_1, c_varargin_2);
        }
      }
    } else {
      coder::internal::expand_max(varargin_1, joint_min_vel, min_dist);
    }
    // 'inverseKinematicsOAModified:145' ub_joints = min(config.gamma .*
    // (jointmaxvalues - joint_values), joint_max_vel);
    if ((jointmaxvalues.size(0) != joint_values.size(0)) &&
        ((jointmaxvalues.size(0) != 1) && (joint_values.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(jointmaxvalues.size(0), joint_values.size(0),
                                  f_emlrtECI);
    }
    if (jointmaxvalues.size(0) == joint_values.size(0)) {
      varargin_1.set_size(jointmaxvalues.size(0));
      loop_ub = jointmaxvalues.size(0);
      if (static_cast<int>(jointmaxvalues.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          varargin_1[k] =
              configInput->gamma * (jointmaxvalues[k] - joint_values[k]);
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

        for (int k = 0; k < loop_ub; k++) {
          varargin_1[k] =
              configInput->gamma * (jointmaxvalues[k] - joint_values[k]);
        }
      }
    } else {
      binary_expand_op(varargin_1, configInput, jointmaxvalues, joint_values);
    }
    if (varargin_1.size(0) == joint_max_vel.size(0)) {
      bp.set_size(varargin_1.size(0));
      loop_ub = varargin_1.size(0);
      if (static_cast<int>(varargin_1.size(0) < 1600)) {
        for (int k{0}; k < loop_ub; k++) {
          b_varargin_1 = varargin_1[k];
          b_varargin_2 = joint_max_vel[k];
          bp[k] = std::fmin(b_varargin_1, b_varargin_2);
        }
      } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads()                         \
                               : 16) private(c_varargin_1, c_varargin_2)

        for (int k = 0; k < loop_ub; k++) {
          c_varargin_1 = varargin_1[k];
          c_varargin_2 = joint_max_vel[k];
          bp[k] = std::fmin(c_varargin_1, c_varargin_2);
        }
      }
    } else {
      coder::internal::expand_min(varargin_1, joint_max_vel, bp);
    }
    // 'inverseKinematicsOAModified:146' lb_slack = config.Slacklowerbound;
    // 'inverseKinematicsOAModified:147' ub_slack = config.Slackupperbound;
    // 'inverseKinematicsOAModified:148' lb       = [lb_joints; lb_slack];
    varargin_2.set_size(min_dist.size(0) + 6);
    loop_ub = min_dist.size(0);
    if (static_cast<int>(min_dist.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        varargin_2[k] = min_dist[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        varargin_2[k] = min_dist[k];
      }
    }
    for (i = 0; i < 6; i++) {
      varargin_2[i + min_dist.size(0)] = configInput->Slacklowerbound[i];
    }
    lb.set_size(varargin_2.size(0), 1);
    loop_ub = varargin_2.size(0);
    if (static_cast<int>(varargin_2.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        lb[k] = varargin_2[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        lb[k] = varargin_2[k];
      }
    }
    // 'inverseKinematicsOAModified:149' ub       = [ub_joints; ub_slack];
    min_dist.set_size(bp.size(0) + 6);
    loop_ub = bp.size(0);
    if (static_cast<int>(bp.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        min_dist[k] = bp[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        min_dist[k] = bp[k];
      }
    }
    for (i = 0; i < 6; i++) {
      min_dist[i + bp.size(0)] = configInput->Slackupperbound[i];
    }
    ub.set_size(min_dist.size(0), 1);
    loop_ub = min_dist.size(0);
    if (static_cast<int>(min_dist.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        ub[k] = min_dist[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        ub[k] = min_dist[k];
      }
    }
  }
  //  ---- 4.4 Expand constraints for Slack if needed ----------------------
  // 'inverseKinematicsOAModified:156' if slackIsUsed
  if (slackIsUsed) {
    //  Expand the equality constraints
    // 'inverseKinematicsOAModified:158' if config.applyEqualityConstraints
    if (configInput->applyEqualityConstraints) {
      signed char b_I[36];
      // 'inverseKinematicsOAModified:159' Aeq = [JacobiWeightMatrix * jacobi,
      // eye(n_slack)];
      coder::internal::blas::mtimes(jacobi, Aeq);
      for (i = 0; i < 36; i++) {
        b_I[i] = 0;
      }
      for (nx = 0; nx < 6; nx++) {
        b_I[nx + 6 * nx] = 1;
      }
      i = Aeq.size(1);
      Aeq.set_size(Aeq.size(0), Aeq.size(1) + 6);
      // 'inverseKinematicsOAModified:160' beq = xd_eff_vel;
      input_sizes[0] = 6;
      input_sizes[1] = 1;
      for (i1 = 0; i1 < 6; i1++) {
        for (sizes_idx_1 = 0; sizes_idx_1 < 6; sizes_idx_1++) {
          Aeq[sizes_idx_1 + Aeq.size(0) * (i1 + i)] = b_I[sizes_idx_1 + 6 * i1];
        }
        beq_data[i1] = xd_eff_vel[i1];
      }
    }
    //  Expand the inequality constraints
    // 'inverseKinematicsOAModified:164' if ~isempty(A)
    if ((A.size(0) != 0) && (A.size(1) != 0)) {
      // 'inverseKinematicsOAModified:165' A = [A, zeros(size(A,1), n_slack)];
      nx = A.size(0);
      loop_ub_tmp = A.size(0);
      sizes_idx_1 = A.size(1);
      loop_ub = A.size(1);
      for (i = 0; i < loop_ub; i++) {
        for (i1 = 0; i1 < nx; i1++) {
          A[i1 + A.size(0) * i] = A[i1 + loop_ub_tmp * i];
        }
      }
      A.set_size(A.size(0), A.size(1) + 6);
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 < nx; i1++) {
          A[i1 + A.size(0) * (i + sizes_idx_1)] = 0.0;
        }
      }
    }
    // 'inverseKinematicsOAModified:173' q_vel_initial_guess =
    // [starting_joint_vel;zeros(n_slack,1)];
    optimal_joint_velocity.set_size(pd_.starting_joint_vel.size(0) + 6);
    loop_ub = pd_.starting_joint_vel.size(0);
    if (static_cast<int>(pd_.starting_joint_vel.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        optimal_joint_velocity[k] = pd_.starting_joint_vel[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        optimal_joint_velocity[k] = pd_.starting_joint_vel[k];
      }
    }
    for (i = 0; i < 6; i++) {
      optimal_joint_velocity[i + pd_.starting_joint_vel.size(0)] = 0.0;
    }
  } else {
    // 'inverseKinematicsOAModified:174' else
    // 'inverseKinematicsOAModified:175' q_vel_initial_guess =
    // starting_joint_vel;
    optimal_joint_velocity.set_size(pd_.starting_joint_vel.size(0));
    loop_ub = pd_.starting_joint_vel.size(0);
    if (static_cast<int>(pd_.starting_joint_vel.size(0) < 1600)) {
      for (int k{0}; k < loop_ub; k++) {
        optimal_joint_velocity[k] = pd_.starting_joint_vel[k];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k < loop_ub; k++) {
        optimal_joint_velocity[k] = pd_.starting_joint_vel[k];
      }
    }
  }
  // ----------------------------------------------------------------------
  //  5. INITIAL GUESS
  // ----------------------------------------------------------------------
  // 'inverseKinematicsOAModified:172' if slackIsUsed
  // ----------------------------------------------------------------------
  //  6. OPTIMIZATION OPTIONS
  // ----------------------------------------------------------------------
  // 'inverseKinematicsOAModified:181' options = optimoptions('fmincon', ...
  // 'inverseKinematicsOAModified:182'         'Algorithm',           'sqp', ...
  // 'inverseKinematicsOAModified:183'         'Display',            'off', ...
  // % or 'iter' to see solver progress 'inverseKinematicsOAModified:184'
  // 'OptimalityTolerance', 1e-6, ... 'inverseKinematicsOAModified:185'
  // 'ConstraintTolerance', 1e-6, ... 'inverseKinematicsOAModified:186'
  // 'StepTolerance',       1e-6, ... 'inverseKinematicsOAModified:187'
  // 'MaxIterations',       1000, ... 'inverseKinematicsOAModified:188'
  // 'UseParallel',true);
  //   % or 'iter' to see solver progress
  // ----------------------------------------------------------------------
  //  7. CALL THE OPTIMIZER (fmincon)
  // ----------------------------------------------------------------------
  // 'inverseKinematicsOAModified:193' [q_vel_opt, ~, Exit_Flag] =
  // fmincon(@(q_vel) objFun( ... 'inverseKinematicsOAModified:194' q_vel, ...
  // 'inverseKinematicsOAModified:195'             jacobi, ...
  // 'inverseKinematicsOAModified:196'             xd_eff_vel, ...
  // 'inverseKinematicsOAModified:197'             starting_joint_vel, ...
  // 'inverseKinematicsOAModified:198'             joint_values, ...
  // 'inverseKinematicsOAModified:199'             jointVelocityWeightMatrix,
  // ... 'inverseKinematicsOAModified:200'             config, ...
  // 'inverseKinematicsOAModified:201'             slackIsUsed), ...
  // 'inverseKinematicsOAModified:202'         q_vel_initial_guess, ...
  // 'inverseKinematicsOAModified:203'         A, b, Aeq, beq, lb, ub, [],
  // options);
  b_this.workspace.slackIsUsed = slackIsUsed;
  b_this.workspace.jacobi.set_size(6, jacobi.size(1));
  loop_ub = 6 * jacobi.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.jacobi[i] = jacobi[i];
  }
  for (nx = 0; nx < 6; nx++) {
    b_this.workspace.xd_eff_vel[nx] = xd_eff_vel[nx];
  }
  b_this.workspace.starting_joint_vel.set_size(pd_.starting_joint_vel.size(0));
  loop_ub = pd_.starting_joint_vel.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.starting_joint_vel[i] = pd_.starting_joint_vel[i];
  }
  b_this.workspace.joint_values.set_size(joint_values.size(0));
  loop_ub = joint_values.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.joint_values[i] = joint_values[i];
  }
  b_this.workspace.jointVelocityWeightMatrix.set_size(
      jointVelocityWeightMatrix.size(0), jointVelocityWeightMatrix.size(1));
  loop_ub =
      jointVelocityWeightMatrix.size(0) * jointVelocityWeightMatrix.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_this.workspace.jointVelocityWeightMatrix[i] =
        jointVelocityWeightMatrix[i];
  }
  b_this.workspace.config = *configInput;
  coder::fmincon(b_this, optimal_joint_velocity, A, b, Aeq, beq_data,
                 input_sizes, lb, ub, Exit_Flag);
  // ----------------------------------------------------------------------
  //  8. EXTRACT THE RESULT
  // ----------------------------------------------------------------------
  // 'inverseKinematicsOAModified:208' if slackIsUsed
  if (slackIsUsed) {
    // 'inverseKinematicsOAModified:209' optimal_joint_velocity =
    // q_vel_opt(1:n_joints);
    if (joint_values.size(0) < 1) {
      i = 0;
    } else {
      if (optimal_joint_velocity.size(0) < 1) {
        rtDynamicBoundsError(1, 1, optimal_joint_velocity.size(0), cb_emlrtBCI);
      }
      if (joint_values.size(0) > optimal_joint_velocity.size(0)) {
        rtDynamicBoundsError(joint_values.size(0), 1,
                             optimal_joint_velocity.size(0), db_emlrtBCI);
      }
      i = joint_values.size(0);
    }
    input_sizes[0] = 1;
    input_sizes[1] = i;
    coder::internal::indexShapeCheck(optimal_joint_velocity.size(0),
                                     input_sizes);
    optimal_joint_velocity.set_size(i);
  } else {
    // 'inverseKinematicsOAModified:211' else
    // 'inverseKinematicsOAModified:212' optimal_joint_velocity = q_vel_opt;
  }
  // ----------------------------------------------------------------------
  //  9. UPDATE PERSISTENT STATE
  // ----------------------------------------------------------------------
  // 'inverseKinematicsOAModified:218' starting_joint_vel =
  // optimal_joint_velocity;
  pd_.starting_joint_vel.set_size(optimal_joint_velocity.size(0));
  loop_ub = optimal_joint_velocity.size(0);
  if (static_cast<int>(optimal_joint_velocity.size(0) < 1600)) {
    for (int k{0}; k < loop_ub; k++) {
      pd_.starting_joint_vel[k] = optimal_joint_velocity[k];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int k = 0; k < loop_ub; k++) {
      pd_.starting_joint_vel[k] = optimal_joint_velocity[k];
    }
  }
  pd_.starting_joint_vel_not_empty = (pd_.starting_joint_vel.size(0) != 0);
}

//
// @(q_vel)
//
// Arguments    : const coder::array<double, 2U> &jacobi
//                const double xd_eff_vel[6]
//                const coder::array<double, 1U> &starting_joint_vel
//                const coder::array<double, 1U> &joint_values
//                const coder::array<double, 2U> &jointVelocityWeightMatrix
//                const struct0_T &config
//                boolean_T slackIsUsed
//                const coder::array<double, 1U> &q_vel
// Return Type  : double
//
double inverseKinematicsOAModified_anonFcn1(
    const coder::array<double, 2U> &jacobi, const double xd_eff_vel[6],
    const coder::array<double, 1U> &starting_joint_vel,
    const coder::array<double, 1U> &joint_values,
    const coder::array<double, 2U> &jointVelocityWeightMatrix,
    const struct0_T &config, boolean_T slackIsUsed,
    const coder::array<double, 1U> &q_vel)
{
  static rtBoundsCheckInfo ab_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      6,        // lineNo
      192,      // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo bb_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      6,        // lineNo
      42,       // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      6,        // lineNo
      44,       // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      8,        // lineNo
      42,       // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      8,        // lineNo
      44,       // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo w_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      6,        // lineNo
      240,      // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo x_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      6,        // lineNo
      251,      // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  static rtBoundsCheckInfo y_emlrtBCI{
      -1,       // iFirst
      -1,       // iLast
      6,        // lineNo
      181,      // colNo
      "q_vel",  // aName
      "objFun", // fName
      "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
      "Matlab_implementation/functions_for_codegen/"
      "obstacleAvoidanceOptmisationModif"
      "ied/objFun.m", // pName
      0               // checkKind
  };
  coder::array<double, 2U> y;
  coder::array<double, 1U> b_q_vel;
  double b[36];
  double varargout_1;
  // 'inverseKinematicsOAModified:193' @(q_vel) objFun( ...
  // 'inverseKinematicsOAModified:194'             q_vel, ...
  // 'inverseKinematicsOAModified:195'             jacobi, ...
  // 'inverseKinematicsOAModified:196'             xd_eff_vel, ...
  // 'inverseKinematicsOAModified:197'             starting_joint_vel, ...
  // 'inverseKinematicsOAModified:198'             joint_values, ...
  // 'inverseKinematicsOAModified:199'             jointVelocityWeightMatrix,
  // ... 'inverseKinematicsOAModified:200'             config, ...
  // 'inverseKinematicsOAModified:201'             slackIsUsed)
  // 'objFun:2' n_joints = length(joint_values);
  //  Add the cost for the slack variables
  // 'objFun:4' if slackIsUsed
  if (slackIsUsed) {
    double b_y;
    int iv[2];
    int b_loop_ub;
    int i;
    int i1;
    int i3;
    int loop_ub;
    // 'objFun:6' objVal = configurableObjective(q_vel(1:n_joints), jacobi,
    // xd_eff_vel, starting_joint_vel, joint_values,jointVelocityWeightMatrix,
    // config) + config.SlackObjectiveWeight * q_vel(n_joints+1:end)' *
    // diag(config.SlackPenaltyWeight) * q_vel(n_joints+1:end);
    if (joint_values.size(0) < 1) {
      loop_ub = 0;
    } else {
      if (q_vel.size(0) < 1) {
        rtDynamicBoundsError(1, 1, q_vel.size(0), bb_emlrtBCI);
      }
      if (joint_values.size(0) > q_vel.size(0)) {
        rtDynamicBoundsError(joint_values.size(0), 1, q_vel.size(0),
                             cb_emlrtBCI);
      }
      loop_ub = joint_values.size(0);
    }
    iv[0] = 1;
    iv[1] = loop_ub;
    coder::internal::indexShapeCheck(q_vel.size(0), iv);
    if (static_cast<unsigned int>(joint_values.size(0)) + 1U >
        static_cast<unsigned int>(q_vel.size(0))) {
      i = 0;
      i1 = 0;
    } else {
      if ((static_cast<int>(static_cast<unsigned int>(joint_values.size(0)) +
                            1U) < 1) ||
          (static_cast<int>(static_cast<unsigned int>(joint_values.size(0)) +
                            1U) > q_vel.size(0))) {
        rtDynamicBoundsError(
            static_cast<int>(static_cast<unsigned int>(joint_values.size(0)) +
                             1U),
            1, q_vel.size(0), y_emlrtBCI);
      }
      i = joint_values.size(0);
      if (q_vel.size(0) < 1) {
        rtDynamicBoundsError(q_vel.size(0), 1, q_vel.size(0), ab_emlrtBCI);
      }
      i1 = q_vel.size(0);
    }
    iv[0] = 1;
    b_loop_ub = i1 - i;
    iv[1] = b_loop_ub;
    coder::internal::indexShapeCheck(q_vel.size(0), iv);
    if (static_cast<unsigned int>(joint_values.size(0)) + 1U >
        static_cast<unsigned int>(q_vel.size(0))) {
      i1 = 0;
      i3 = 0;
    } else {
      if ((static_cast<int>(static_cast<unsigned int>(joint_values.size(0)) +
                            1U) < 1) ||
          (static_cast<int>(static_cast<unsigned int>(joint_values.size(0)) +
                            1U) > q_vel.size(0))) {
        rtDynamicBoundsError(
            static_cast<int>(static_cast<unsigned int>(joint_values.size(0)) +
                             1U),
            1, q_vel.size(0), w_emlrtBCI);
      }
      i1 = joint_values.size(0);
      if (q_vel.size(0) < 1) {
        rtDynamicBoundsError(q_vel.size(0), 1, q_vel.size(0), x_emlrtBCI);
      }
      i3 = q_vel.size(0);
    }
    iv[0] = 1;
    i3 -= i1;
    iv[1] = i3;
    coder::internal::indexShapeCheck(q_vel.size(0), iv);
    y.set_size(1, b_loop_ub);
    if (static_cast<int>(b_loop_ub < 1600)) {
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        y[i2] = config.SlackObjectiveWeight * q_vel[i + i2];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int i2 = 0; i2 < b_loop_ub; i2++) {
        y[i2] = config.SlackObjectiveWeight * q_vel[i + i2];
      }
    }
    std::memset(&b[0], 0, 36U * sizeof(double));
    for (b_loop_ub = 0; b_loop_ub < 6; b_loop_ub++) {
      b[b_loop_ub + 6 * b_loop_ub] = config.SlackPenaltyWeight[b_loop_ub];
    }
    if (y.size(1) != 6) {
      if (y.size(1) == 1) {
        h_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
      } else {
        g_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
      }
    }
    if (i3 != 6) {
      if (i3 == 1) {
        h_rtErrorWithMessageID(b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
      } else {
        g_rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
      }
    }
    b_q_vel.set_size(loop_ub);
    if (static_cast<int>(loop_ub < 1600)) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_q_vel[i2] = q_vel[i2];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int i2 = 0; i2 < loop_ub; i2++) {
        b_q_vel[i2] = q_vel[i2];
      }
    }
    b_y = 0.0;
    for (i = 0; i < 6; i++) {
      double d;
      d = 0.0;
      for (i3 = 0; i3 < 6; i3++) {
        d += y[i3] * b[i3 + 6 * i];
      }
      b_y += d * q_vel[i1 + i];
    }
    varargout_1 =
        configurableObjective(
            b_q_vel, jacobi, xd_eff_vel, starting_joint_vel, joint_values,
            jointVelocityWeightMatrix, config.useObjectiveNormInfinity,
            config.weightNormInfinity, config.useObjectiveNormL2,
            config.weightNormL2, config.useObjectiveTrajectoryFollowing,
            config.weightTrajectoryFollowing,
            config.useObjectiveJointAcceleration,
            config.weightJointAcceleration, config.useObjectiveManipulability,
            config.weightManipulability) +
        b_y;
  } else {
    int iv[2];
    int loop_ub;
    // 'objFun:7' else
    // 'objFun:8' objVal = configurableObjective(q_vel(1:n_joints), jacobi,
    // xd_eff_vel, starting_joint_vel, joint_values,jointVelocityWeightMatrix,
    // config);
    if (joint_values.size(0) < 1) {
      loop_ub = 0;
    } else {
      if (q_vel.size(0) < 1) {
        rtDynamicBoundsError(1, 1, q_vel.size(0), db_emlrtBCI);
      }
      if (joint_values.size(0) > q_vel.size(0)) {
        rtDynamicBoundsError(joint_values.size(0), 1, q_vel.size(0),
                             eb_emlrtBCI);
      }
      loop_ub = joint_values.size(0);
    }
    iv[0] = 1;
    iv[1] = loop_ub;
    coder::internal::indexShapeCheck(q_vel.size(0), iv);
    b_q_vel.set_size(loop_ub);
    if (static_cast<int>(loop_ub < 1600)) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_q_vel[i2] = q_vel[i2];
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int i2 = 0; i2 < loop_ub; i2++) {
        b_q_vel[i2] = q_vel[i2];
      }
    }
    varargout_1 = configurableObjective(
        b_q_vel, jacobi, xd_eff_vel, starting_joint_vel, joint_values,
        jointVelocityWeightMatrix, config.useObjectiveNormInfinity,
        config.weightNormInfinity, config.useObjectiveNormL2,
        config.weightNormL2, config.useObjectiveTrajectoryFollowing,
        config.weightTrajectoryFollowing, config.useObjectiveJointAcceleration,
        config.weightJointAcceleration, config.useObjectiveManipulability,
        config.weightManipulability);
  }
  return varargout_1;
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
void minus(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2,
           const coder::array<double, 1U> &in3)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (static_cast<int>(loop_ub < 1600)) {
    for (int i{0}; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_0] - in3[i * stride_1_0];
    }
  } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

    for (int i = 0; i < loop_ub; i++) {
      in1[i] = in2[i * stride_0_0] - in3[i * stride_1_0];
    }
  }
}

//
// File trailer for OptimizationBasedIKWithOAModified.cpp
//
// [EOF]
//
