//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_inverseKinematics_info.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 10-Nov-2024 04:04:05
//

// Include Files
#include "_coder_inverseKinematics_info.h"
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
      "789ced584d6f1241181e0c368d49154dd493b117f554a0565a3999c847699142dac6168c"
      "c161768029bb33b03b50e8c18f1f603ca87735c6c4c4a337e3c183bf"
      "c68b47935e5c0a0b5de876d7d00c14790fccbefbeceeb3f3cccbfbec2e70ad245c0080f3"
      "a015bf6fb4c69976ee698f6780397a71577b9ceac98d380bdca6f30c",
      "fc557b448c725ce7ad84420577ce94984228a47cb351c640c51a936b583a40f244c69b44"
      "c11b8793b566a6440f419da40935b743458c4a1b5505a845ad7b87f2"
      "e1a4a3c7acebe8f9ba1deaf1cd420f4f0ffe28f2d857640af66945962b12ee8baa9096e0"
      "1c5688fe9bcc691c2219cfc11a2312a408fbd6598ef10493b02c135a",
      "f0a9cd54e9a409c86598cb12a52c6305530e3961d497af52d4dcd0b279a666917e740153"
      "1fa135ac6a384e2856f4e390d6bfc7abb8faf6652165348ae8bc49af"
      "27167a38d5cbaa7e3c6d84e576a2552a8e4fe36a15f12edf9f01f9de5af299f191aa8796"
      "e85e05d8eb7ec1a10ebd63f7f8e983f147d25b0002f97efe9a9d15c9",
      "67c4b0f8ea16d7735ac7572cf83c3d78e06e2cbe16a84756a816ab657663a585a50a5aee"
      "de47ca86c7ee3e80452eeafa937ed08a41ebe9b28d0e06ae3f27e449"
      "a1aac29c8c93b91dacdf6f0d83e1f9c1f480cf071f2df9ccf848adff918b70500ec2fad9"
      "d5e0f5bc483eff8b7be744f219715afdc1e9ff792d96410b3c15921b",
      "77c2d283f94a239ec22a181f7f98f4877feb0f4e7571f7e45d5d5a88a6bf349e249f9d2f"
      "48acaa4ff6e49e0b5e5bf299f1915af7a6e8ad6516d6b7de7cdfc722"
      "f98cf85ff844f940295309a5e3f5344fc7ca682f9858667bea3698f8c0b8fbc0738b793b"
      "d5e59a8d2e068e9852ae729c809494abfa94884c7863152296239082",
      "e1f98467c0baf862c967c647ac2e8e590cb1ef111f4a62bf333dfbbc7f4b249f11a7d53f"
      "9c7e675a8c5596fd3cb81041f7331407b6d38dc0220b8f8f7f4cfac4"
      "f17d62d03abb68a38f81b7d8b37942a19cd5a7586aef1f967f8001ebe29d259f191fa9ba"
      "e85b04af22aabf3d7d28d62fc237bfce88e43362dcfd221508a2a5f0",
      "065d2f473265ff6d7f9ac3bd4068e21713bf70a6cf251b7d0c3c86354d27ef338c61f9c5"
      "a0efa1ef2df9ccf848d545ff22b4bf5289eb732f05fbc6d627f79448"
      "3e23c6dd37d0962ae315359aac487124e1dde4e2ea6e660c7ce32f5b49d686",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 9736U, &nameCaptureInfo);
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
  xInputs = emlrtCreateLogicalMatrix(1, 8);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("inverseKinematics"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(8.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
          "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
          "inematics/inverseKinematics.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739566.14116898144));
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
                emlrtMxCreateString("yUh6T0gpqfsdaEwy97Cc3F"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

//
// File trailer for _coder_inverseKinematics_info.cpp
//
// [EOF]
//
