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
  int32_T postfix_exprs_0_3[5]{0, -1, 1, -1, -3};
  int32_T postfix_exprs_0_0[3]{0, 1, -2};
  int32_T postfix_exprs_0_1[3]{0, 1, -3};
  int32_T postfix_exprs_0_2[3]{0, 1, -2};
  int32_T cond_ends_0_0[2]{1056, 1087};
  int32_T cond_ends_0_1[2]{1788, 1822};
  int32_T cond_ends_0_2[2]{1846, 1862};
  int32_T cond_ends_0_3[2]{3718, 3735};
  int32_T cond_starts_0_0[2]{1034, 1060};
  int32_T cond_starts_0_1[2]{1769, 1792};
  int32_T cond_starts_0_2[2]{1834, 1850};
  int32_T cond_starts_0_3[2]{3706, 3723};
  int32_T postfix_exprs_0_4[2]{0, -1};
  int32_T postfix_exprs_0_5[2]{0, -1};
  int32_T cond_ends_0_4{4724};
  int32_T cond_ends_0_5{6406};
  int32_T cond_starts_0_4{4713};
  int32_T cond_starts_0_5{6396};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                  "Matlab_implementation/functions_for_codegen/"
                  "obstacleAvoidanceOptmisationModif"
                  "ied/inverseKinematicsOAModified.m",
                  0U, 2U, 27U, 20U, 0U, 0U, 0U, 1U, 0U, 10U, 6U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "inverseKinematicsOAModified", 0,
               -1, 8446);
  covrtFcnInit(&emlrtCoverageInstance, 0U, 1U,
               "inverseKinematicsOAModified_anonFcn1", 7542, -1, 7795);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 26U, 8396, -1, 8440);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 25U, 8162, -1, 8197);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 24U, 8088, -1, 8135);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 22U, 6993, -1, 7879);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 21U, 6756, -1, 6797);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 20U, 6678, -1, 6738);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 19U, 6419, -1, 6454);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 18U, 6237, -1, 6317);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 17U, 5653, -1, 6012);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 16U, 5376, -1, 5627);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 15U, 5022, -1, 5181);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 14U, 4885, -1, 4936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 13U, 4439, -1, 4466);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 12U, 4180, -1, 4211);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 11U, 3985, -1, 4018);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 10U, 3869, -1, 3914);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 9U, 3503, -1, 3563);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 3186, -1, 3373);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 2815, -1, 2923);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 2614, -1, 2728);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 2123, -1, 2473);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1875, -1, 1895);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1299, -1, 1761);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1227, -1, 1249);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1096, -1, 1165);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 799, -1, 869);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 23U, 7542, -1, 7795);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1031, 1087, -1, 1192);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1202, 1218, -1, 1257);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 1766, 1822, -1, 1915);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 1831, 1862, -1, 1907);
  covrtIfInit(&emlrtCoverageInstance, 0U, 4U, 2488, 2517, -1, 2959);
  covrtIfInit(&emlrtCoverageInstance, 0U, 5U, 2768, 2798, -1, 2939);
  covrtIfInit(&emlrtCoverageInstance, 0U, 6U, 3460, 3494, -1, 3571);
  covrtIfInit(&emlrtCoverageInstance, 0U, 7U, 3657, 3693, 4244, 4627);
  covrtIfInit(&emlrtCoverageInstance, 0U, 8U, 3702, 3735, 4043, 4239);
  covrtIfInit(&emlrtCoverageInstance, 0U, 9U, 3750, 3779, 3927, 4034);
  covrtIfInit(&emlrtCoverageInstance, 0U, 10U, 4134, 4163, -1, 4227);
  covrtIfInit(&emlrtCoverageInstance, 0U, 11U, 4397, 4426, -1, 4478);
  covrtIfInit(&emlrtCoverageInstance, 0U, 12U, 4709, 4724, 5198, 6042);
  covrtIfInit(&emlrtCoverageInstance, 0U, 13U, 4764, 4793, 4945, 5193);
  covrtIfInit(&emlrtCoverageInstance, 0U, 14U, 5334, 5363, 5636, 6024);
  covrtIfInit(&emlrtCoverageInstance, 0U, 15U, 6125, 6139, -1, 6474);
  covrtIfInit(&emlrtCoverageInstance, 0U, 16U, 6190, 6224, -1, 6330);
  covrtIfInit(&emlrtCoverageInstance, 0U, 17U, 6392, 6406, -1, 6466);
  covrtIfInit(&emlrtCoverageInstance, 0U, 18U, 6655, 6669, 6743, 6805);
  covrtIfInit(&emlrtCoverageInstance, 0U, 19U, 8065, 8079, 8149, 8205);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 0U, 1034, 1087, 2, 0,
                cond_starts_0_0, cond_ends_0_0, 3, postfix_exprs_0_0);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 1U, 1769, 1822, 2, 2,
                cond_starts_0_1, cond_ends_0_1, 3, postfix_exprs_0_1);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 2U, 1834, 1862, 2, 4,
                cond_starts_0_2, cond_ends_0_2, 3, postfix_exprs_0_2);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 3U, 3705, 3735, 2, 6,
                cond_starts_0_3, cond_ends_0_3, 5, postfix_exprs_0_3);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 4U, 4712, 4724, 1, 8,
                &cond_starts_0_4, &cond_ends_0_4, 2, postfix_exprs_0_4);
  covrtMcdcInit(&emlrtCoverageInstance, 0U, 5U, 6395, 6406, 1, 9,
                &cond_starts_0_5, &cond_ends_0_5, 2, postfix_exprs_0_5);
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 2737, 2755, 2951);
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
