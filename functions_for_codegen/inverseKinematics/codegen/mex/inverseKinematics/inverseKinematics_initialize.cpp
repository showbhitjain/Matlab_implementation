//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematics_initialize.cpp
//
// Code generation for function 'inverseKinematics_initialize'
//

// Include files
#include "inverseKinematics_initialize.h"
#include "_coder_inverseKinematics_mex.h"
#include "inverseKinematics.h"
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Declarations
static void inverseKinematics_once();

// Function Definitions
static void inverseKinematics_once()
{
  int32_T postfix_exprs_0_0[3]{0, 1, -2};
  int32_T cond_ends_0_0[2]{715, 746};
  int32_T cond_starts_0_0[2]{693, 719};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
      "inematics/inverseKinematics.m",
      0U, 2U, 5U, 2U, 0U, 0U, 0U, 0U, 0U, 2U, 1U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "inverseKinematics", 0, -1,
               2261);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 1U, "inverseKinematics_anonFcn1",
               1945, -1, 2028);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1094, -1, 2256);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 947, -1, 969);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 751, -1, 816);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 208, -1, 240);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1945, -1, 2028);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 690, 746, -1, 845);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 926, 942, -1, 1092);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 693, 746, 2, 0, cond_starts_0_0,
                cond_ends_0_0, 3, postfix_exprs_0_0);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
      "inematics/objFun.m",
      1U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "objFun", 0, -1, 256);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 98, -1, 247);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
      "inematics/configurableObjective.m",
      2U, 1U, 7U, 6U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "configurableObjective", 0, -1,
               911);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 6U, 736, -1, 828);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 635, -1, 692);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 513, -1, 585);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 383, -1, 463);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 275, -1, 333);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 165, -1, 225);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 112, -1, 123);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 2U, 0U, 133, 156, -1, 233);
  covrtIfInit(&emlrtCoverageInstance, 2U, 1U, 243, 266, -1, 341);
  covrtIfInit(&emlrtCoverageInstance, 2U, 2U, 351, 374, -1, 471);
  covrtIfInit(&emlrtCoverageInstance, 2U, 3U, 481, 504, -1, 593);
  covrtIfInit(&emlrtCoverageInstance, 2U, 4U, 603, 626, -1, 700);
  covrtIfInit(&emlrtCoverageInstance, 2U, 5U, 706, 729, -1, 836);
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
      "inematics/smin.m",
      3U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "smin", 0, -1, 64);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 29, -1, 60);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 3U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
      "inematics/computeManipulabilityJacobian.m",
      4U, 2U, 3U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "computeManipulabilityJacobian",
               0, -1, 1085);
  covrtFcnInit(&emlrtCoverageInstance, 4U, 1U,
               "computeManipulabilityJacobian_anonFcn1", 758, -1, 780);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 2U, 958, -1, 1056);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 341, -1, 848);
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 1U, 758, -1, 780);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 4U, 0U, 938, 949, 1081);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 4U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
      "inematics/Jacobi_final_link.m",
      5U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "Jacobi_final_link", 0, -1,
               15071);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 191, -1, 15067);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 5U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
      "inematics/Hessian_final_link.m",
      6U, 3U, 3U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 6U, 0U, "Hessian_final_link", 0, -1,
               14057);
  covrtFcnInit(&emlrtCoverageInstance, 6U, 1U, "ft_1", 14058, -1, 32676);
  covrtFcnInit(&emlrtCoverageInstance, 6U, 2U, "ft_2", 32677, -1, 58010);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 0U, 206, -1, 14053);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 1U, 14086, -1, 32672);
  covrtBasicBlockInit(&emlrtCoverageInstance, 6U, 2U, 32705, -1, 58006);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 6U);
  inverseKinematics_init();
}

void inverseKinematics_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "optimization_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    inverseKinematics_once();
  }
}

// End of code generation (inverseKinematics_initialize.cpp)
