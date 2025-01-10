//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_utilsMatlab_info.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 14-Nov-2024 02:49:51
//

// Include Files
#include "_coder_utilsMatlab_info.h"
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
  const char_T *data[5]{
      "789ce554cb4ec240149d1a5436281b133726fe0034c6c70f18888a8801a289c6d4697ba1"
      "03f320ed14c19f70efcef815fe9d2da5051a2625211a13efa2774e4f"
      "6fef9933b745da655d4308eda0282eb6a35c98e2e2346fa0c548f39a22c7b189720b7531"
      "ff36cd96e0124632021c33482a6dc108c75cb6c703402e78820ec19e",
      "301d42a14d18b4e6c14d8858758e4a404885eb7307ac7ecb67c875bc99423a0f123f0eb5"
      "e5fbcdade8c797c28f628a7fac3ce98e60a07b8e301d22f5aa8b791f"
      "978091e0da303d892d0a253c14c4c6dc02bd294c21ebc2064a09efea6e085902eb58526c"
      "1a840d2830e0124b22b8def1b9152e3ca3235cc30a9eee02d77d49a8",
      "1715e8243885ae8b25347dde859a2f252e336dc95d0373c1ab163f4af93552f8b1aa5ffb"
      "197ec57c4f04a20c7b1c8c0ab13c235118eb785e53c7965247c4d8c2"
      "3729ccf69d5f734e3e94fd16f93f32272afbcb6caa33eb1c7657f445f53f29a0fc247fbe"
      "1f747eb35f1cffa5dfbadff39ea25f31c59fbc5ef9a35aafddf0ae1f",
      "2a77e2b8f572767f3aa7e336a34f960ea4c03ffdfe6f6c03cc20", ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1888U, &nameCaptureInfo);
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
      emlrtCreateStructMatrix(1, 2, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("add_noise"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
          "robotmodelling/Matlab_implementation/functions_for_codegen/utilsMat"
          "lab/add_noise.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739357.85053240741));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 1, "Name",
                emlrtMxCreateString("integrateRungeKutta"));
  emlrtSetField(xEntryPoints, 1, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 1, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 1, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 1, "FullPath",
      emlrtMxCreateString(
          "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
          "robotmodelling/Matlab_implementation/functions_for_codegen/utilsMat"
          "lab/integrateRungeKutta.m"));
  emlrtSetField(xEntryPoints, 1, "TimeStamp",
                emlrtMxCreateDoubleScalar(739570.09292824077));
  emlrtSetField(xEntryPoints, 1, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 1, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2485118 (R2023b) Update 6"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("RV36yqvjDQD0kujQTRh5DH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

//
// File trailer for _coder_utilsMatlab_info.cpp
//
// [EOF]
//
