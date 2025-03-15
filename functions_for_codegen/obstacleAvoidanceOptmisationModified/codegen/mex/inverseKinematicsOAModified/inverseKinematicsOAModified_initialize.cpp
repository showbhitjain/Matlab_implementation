//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified_initialize.cpp
//
// Code generation for function 'inverseKinematicsOAModified_initialize'
//

// Include files
#include "inverseKinematicsOAModified_initialize.h"
#include "_coder_inverseKinematicsOAModified_mex.h"
#include "inverseKinematicsOAModified.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Declarations
static void c_inverseKinematicsOAModified_o();

// Function Definitions
static void c_inverseKinematicsOAModified_o()
{
  int32_T postfix_exprs_0_2[5]{0, -1, 1, -1, -3};
  int32_T postfix_exprs_0_0[3]{0, 1, -3};
  int32_T postfix_exprs_0_1[3]{0, 1, -2};
  int32_T cond_ends_0_0[2]{1669, 1703};
  int32_T cond_ends_0_1[2]{1727, 1743};
  int32_T cond_ends_0_2[2]{3603, 3620};
  int32_T cond_starts_0_0[2]{1650, 1673};
  int32_T cond_starts_0_1[2]{1715, 1731};
  int32_T cond_starts_0_2[2]{3591, 3608};
  int32_T postfix_exprs_0_3[2]{0, -1};
  int32_T postfix_exprs_0_4[2]{0, -1};
  int32_T cond_ends_0_3{4609};
  int32_T cond_ends_0_4{6291};
  int32_T cond_starts_0_3{4598};
  int32_T cond_starts_0_4{6281};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                  "Matlab_implementation/functions_for_codegen/"
                  "obstacleAvoidanceOptmisationModif"
                  "ied/inverseKinematicsOAModified.m",
                  0U, 2U, 26U, 19U, 0U, 0U, 0U, 1U, 0U, 8U, 5U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "inverseKinematicsOAModified", 0,
               -1, 9113);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 1U,
               "inverseKinematicsOAModified_anonFcn1", 8183, -1, 8462);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 25U, 9063, -1, 9107);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 24U, 8829, -1, 8864);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 23U, 8755, -1, 8802);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 21U, 6882, -1, 8546);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 20U, 6641, -1, 6682);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 19U, 6563, -1, 6623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 18U, 6304, -1, 6339);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 17U, 6122, -1, 6202);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 16U, 5538, -1, 5897);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 15U, 5261, -1, 5512);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 14U, 4907, -1, 5066);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 13U, 4770, -1, 4821);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 12U, 4324, -1, 4351);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 11U, 4065, -1, 4096);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 10U, 3870, -1, 3903);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 3754, -1, 3799);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 3388, -1, 3448);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 3067, -1, 3258);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 2696, -1, 2804);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 2495, -1, 2609);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 2004, -1, 2354);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1756, -1, 1776);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1180, -1, 1642);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1065, -1, 1104);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 786, -1, 856);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 22U, 8183, -1, 8462);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1018, 1048, -1, 1131);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1647, 1703, -1, 1796);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 1712, 1743, -1, 1788);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 2369, 2398, -1, 2840);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 2649, 2679, -1, 2820);
  covrtIfInit(&emlrtCoverageInstance, 0U, 5U, 3345, 3379, -1, 3456);
  covrtIfInit(&emlrtCoverageInstance, 0U, 6U, 3542, 3578, 4129, 4512);
  covrtIfInit(&emlrtCoverageInstance, 0U, 7U, 3587, 3620, 3928, 4124);
  covrtIfInit(&emlrtCoverageInstance, 0U, 8U, 3635, 3664, 3812, 3919);
  covrtIfInit(&emlrtCoverageInstance, 0U, 9U, 4019, 4048, -1, 4112);
  covrtIfInit(&emlrtCoverageInstance, 0U, 10U, 4282, 4311, -1, 4363);
  covrtIfInit(&emlrtCoverageInstance, 0U, 11U, 4594, 4609, 5083, 5927);
  covrtIfInit(&emlrtCoverageInstance, 0U, 12U, 4649, 4678, 4830, 5078);
  covrtIfInit(&emlrtCoverageInstance, 0U, 13U, 5219, 5248, 5521, 5909);
  covrtIfInit(&emlrtCoverageInstance, 0U, 14U, 6010, 6024, -1, 6359);
  covrtIfInit(&emlrtCoverageInstance, 0U, 15U, 6075, 6109, -1, 6215);
  covrtIfInit(&emlrtCoverageInstance, 0U, 16U, 6277, 6291, -1, 6351);
  covrtIfInit(&emlrtCoverageInstance, 0U, 17U, 6540, 6554, 6628, 6690);
  covrtIfInit(&emlrtCoverageInstance, 0U, 18U, 8732, 8746, 8816, 8872);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 1650, 1703, 2, 0,
                cond_starts_0_0, cond_ends_0_0, 3, postfix_exprs_0_0);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 1U, 1715, 1743, 2, 2,
                cond_starts_0_1, cond_ends_0_1, 3, postfix_exprs_0_1);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 2U, 3590, 3620, 2, 4,
                cond_starts_0_2, cond_ends_0_2, 5, postfix_exprs_0_2);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 3U, 4597, 4609, 1, 6,
                &cond_starts_0_3, &cond_ends_0_3, 2, postfix_exprs_0_3);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 4U, 6280, 6291, 1, 7,
                &cond_starts_0_4, &cond_ends_0_4, 2, postfix_exprs_0_4);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 2618, 2636, 2832);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                  "Matlab_implementation/functions_for_codegen/"
                  "obstacleAvoidanceOptmisationModif"
                  "ied/objFun.m",
                  1U, 1U, 3U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "objFun", 0, -1, 631);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 485, -1, 623);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 224, -1, 475);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 132, -1, 164);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 204, 218, 476, 627);
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                  "Matlab_implementation/functions_for_codegen/"
                  "obstacleAvoidanceOptmisationModif"
                  "ied/configurableObjective.m",
                  2U, 1U, 6U, 5U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "configurableObjective", 0, -1,
               1138);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 933, -1, 1055);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 708, -1, 876);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 527, -1, 642);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 349, -1, 459);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 206, -1, 294);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 142, -1, 153);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 2U, 0U, 163, 197, -1, 302);
  covrtIfInit(&emlrtCoverageInstance, 2U, 1U, 312, 340, -1, 467);
  covrtIfInit(&emlrtCoverageInstance, 2U, 2U, 477, 518, -1, 650);
  covrtIfInit(&emlrtCoverageInstance, 2U, 3U, 660, 699, -1, 884);
  covrtIfInit(&emlrtCoverageInstance, 2U, 4U, 890, 926, -1, 1063);
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                  "Matlab_implementation/functions_for_codegen/"
                  "obstacleAvoidanceOptmisationModif"
                  "ied/computeManipulabilityJacobian.m",
                  3U, 2U, 3U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "computeManipulabilityJacobian",
               0, -1, 1085);
  covrtFcnInit(&emlrtCoverageInstance, 3U, 1U,
               "computeManipulabilityJacobian_anonFcn1", 758, -1, 780);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 2U, 958, -1, 1056);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 341, -1, 848);
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 1U, 758, -1, 780);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 3U, 0U, 938, 949, 1081);
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 3U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                  "Matlab_implementation/functions_for_codegen/"
                  "obstacleAvoidanceOptmisationModif"
                  "ied/Jacobi_final_link.m",
                  4U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 4U, 0U, "Jacobi_final_link", 0, -1,
               15071);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 4U, 0U, 191, -1, 15067);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 4U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                  "Matlab_implementation/functions_for_codegen/"
                  "obstacleAvoidanceOptmisationModif"
                  "ied/Hessian_final_link.m",
                  5U, 3U, 3U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 5U, 0U, "Hessian_final_link", 0, -1,
               14057);
  covrtFcnInit(&emlrtCoverageInstance, 5U, 1U, "ft_1", 14058, -1, 32676);
  covrtFcnInit(&emlrtCoverageInstance, 5U, 2U, "ft_2", 32677, -1, 58010);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 0U, 206, -1, 14053);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 1U, 14086, -1, 32672);
  covrtBasicBlockInit(&emlrtCoverageInstance, 5U, 2U, 32705, -1, 58006);
  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 5U);
  c_inverseKinematicsOAModified_i();
}

void inverseKinematicsOAModified_initialize()
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
    c_inverseKinematicsOAModified_o();
  }
}

// End of code generation (inverseKinematicsOAModified_initialize.cpp)
