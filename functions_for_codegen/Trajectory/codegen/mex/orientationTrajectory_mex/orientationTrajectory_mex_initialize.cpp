//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// orientationTrajectory_mex_initialize.cpp
//
// Code generation for function 'orientationTrajectory_mex_initialize'
//

// Include files
#include "orientationTrajectory_mex_initialize.h"
#include "_coder_orientationTrajectory_mex_mex.h"
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"

// Function Declarations
namespace trajectoryGeneration {
static void orientationTrajectory_mex_once();

}

// Function Definitions
namespace trajectoryGeneration {
static void orientationTrajectory_mex_once()
{
  int32_T caseExprEnds_0_0[4]{1632, 1212, 1441, 1538};
  int32_T caseExprEnds_1_0[4]{2139, 1501, 1733, 1903};
  int32_T caseStarts_0_0[4]{1623, 1201, 1429, 1524};
  int32_T caseStarts_1_0[4]{2130, 1490, 1721, 1889};
  int32_T postfix_exprs_1_0[3]{0, 1, -2};
  int32_T postfix_exprs_1_1[3]{0, 1, -2};
  int32_T cond_ends_1_0[2]{831, 856};
  int32_T cond_ends_1_1[2]{962, 989};
  int32_T cond_starts_1_0[2]{821, 835};
  int32_T cond_starts_1_1[2]{952, 966};
  mex_InitInfAndNan();
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
      "ry/orientationTrajectory.m",
      0U, 1U, 9U, 2U, 0U, 0U, 1U, 1U, 0U, 0U, 0U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "orientationTrajectory", 0, -1,
               2224);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 8U, 1772, -1, 2218);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 6U, 1551, -1, 1614);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1454, -1, 1515);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1225, -1, 1420);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 7U, 1645, -1, 1719);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 907, -1, 1120);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 763, -1, 848);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 614, -1, 717);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 275, -1, 503);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 577, 605, 722, 902);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 722, 754, 853, 902);
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 543, 567, 2222);
  // Initialize While Information
  // Initialize Switch Information
  covrtSwitchInit(&emlrtCoverageInstance, 0U, 0U, 1177, 1192, 1727, 4U,
                  caseStarts_0_0, caseExprEnds_0_0);
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  // Initialize Coverage Information
  covrtScriptInit(
      &emlrtCoverageInstance,
      "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
      "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
      "ry/positionTrajectory.m",
      1U, 1U, 7U, 2U, 0U, 0U, 1U, 0U, 0U, 4U, 2U);
  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "positionTrajectory", 0, -1,
               2251);
  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 1916, -1, 2121);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 1746, -1, 1880);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 1514, -1, 1712);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 2152, -1, 2239);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 1128, -1, 1377);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 998, -1, 1041);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 865, -1, 915);
  // Initialize If Information
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 818, 856, -1, 944);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 949, 989, -1, 1073);
  // Initialize MCDC Information
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 0U, 821, 856, 2, 0, cond_starts_1_0,
                cond_ends_1_0, 3, postfix_exprs_1_0);
  covrtMcdcInit(&emlrtCoverageInstance, 1U, 1U, 952, 989, 2, 2, cond_starts_1_1,
                cond_ends_1_1, 3, postfix_exprs_1_1);
  // Initialize For Information
  // Initialize While Information
  // Initialize Switch Information
  covrtSwitchInit(&emlrtCoverageInstance, 1U, 0U, 1466, 1481, 2247, 4U,
                  caseStarts_1_0, caseExprEnds_1_0);
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 1U);
}

void orientationTrajectory_mex_initialize()
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
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    orientationTrajectory_mex_once();
  }
}

} // namespace trajectoryGeneration

// End of code generation (orientationTrajectory_mex_initialize.cpp)
