//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_inverseKinematicsOA_info.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 10-Jan-2025 01:08:30
//

// Include Files
#include "_coder_inverseKinematicsOA_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
//
// Arguments    : void
// Return Type  : const mxArray *
//
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8]{
      "789ced574d6fd330184ed198b8000509c405893fb0a61bebd88edb9aeea32a19db18dd10"
      "2a8ee3b66e633b4b9c769d10e2888410fc04c415248efc077e0e278e"
      "244bd32eddb2145578a5c4873aaf9fd88ffdf8d5fba4526aa3949224e986e4b7f5077e7f"
      "bd1ba7bbfd1529dc06f154b7bf3a104bbdf1a9d0bc00ffd0ed21a31c",
      "1d713fa080a0de4c9d114c01e5bb1d134916b299d142fa0952c506dac504ed9c0e1e7b11"
      "299c827a810779cfab75049b3b0e91acbadddfa1713ae8e9914d9d7f"
      "dea921f5f811a1477a007faebc90eb8c20d9ae33ad8eb95cb0006d821944b0fbab6a3607"
      "d04033a0c5b00e2844f236d3182f311d1906a635d9f242d20b4b801b",
      "40ab60621a8820ca01c78cca558742efc1ae54995581eedb354465d65d7c39585b3539c1"
      "b63f05d316b26c54c414117704daea7286a4ce19ad00ca6801d2d9b0"
      "7e2f23f41956bfe948fd7c84698d8243c5f1d9dc7220eff34923e6c7a748be303eaef9e1"
      "eb9f2171fadf1c528fc1befffeb593bef3b353f37a517c0de5d5a248",
      "bea05d16df51c47ac3e6f3dd08bef4007e582a6637f36a756eb6adace03d456d379faa4a"
      "7f1f5b313c71fb90226251eb2775215c1746cdab3b317a04b8fb1d51"
      "c535c7029a8154ad81dc7db7bc6f89cbf287f48879f02d922f8c8f6b1e9c7b1f1922aebe"
      "7d3c12ea17efdefe9a16c917b489f78badf979334f9f38cbc7e572a3",
      "5c5cb4f24b646d72fc22a91317d7893711e71f569ffb31fa043864c474382a018a4dc73d"
      "1a3630ef6c02c8340cdcbf19c27c44678eab449fefde88f9f13d922f"
      "8c8f6f7e5c702f02fde4733323d44f82f6bff089f29385f5c3b52c5f7aa8c095038a72e5"
      "fd4e6e81e527c74f927a315cbd1835df6ec5e814e03e75a58a29302a",
      "ee519bddf1cbf29351bf37be44f285f171cd8f33f7e1e684d744d5bdd77b898ffc4d3e51"
      "3eb2955b828ff23b74db540eccec5c769f83e3dc6ae223898ffc994e"
      "b763740af07564db2ef31923f9577de46b245f181fd7fc387b1fbe9188aa7bef131ff9ab"
      "7ca27c043eb30cb46115d443bd0875d4561736db0713e023bf01b57f",
      "6cd6",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 8288U, &nameCaptureInfo);
  return nameCaptureInfo;
}

//
// Arguments    : void
// Return Type  : mxArray *
//
mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9]{"Version",
                                 "ResolvedFunctions",
                                 "Checksum",
                                 "EntryPoints",
                                 "CoverageInfo",
                                 "IsPolymorphic",
                                 "PropertyList",
                                 "UUID",
                                 "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8]{
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 11);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("inverseKinematicsOA"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(11.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
          "robotmodelling/Matlab_implementation/functions_for_codegen/obstacle"
          "AvoidanceOptmisation/inverseKinematicsOA.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739627.03116898146));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2485118 (R2023b) Update 6"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("GoqJqDnchemTOsNlhRv3FB"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

//
// File trailer for _coder_inverseKinematicsOA_info.cpp
//
// [EOF]
//
