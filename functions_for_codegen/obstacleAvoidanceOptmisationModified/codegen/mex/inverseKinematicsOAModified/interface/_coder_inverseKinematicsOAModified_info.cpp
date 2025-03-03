//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inverseKinematicsOAModified_info.cpp
//
// Code generation for function 'inverseKinematicsOAModified'
//

// Include files
#include "_coder_inverseKinematicsOAModified_info.h"
#include "inverseKinematicsOAModified_data.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

// Function Definitions
static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[8]{
      "789ced575f4fd35014ef0c1a12ff4d13f5c990f801d8266c0b6f226c0ee61830023235f3"
      "f6f66cbbd07b6f696f07e88bdf8057a3898f7e04e3b3890fbef93df4"
      "81f8096ce9baad85b2c59132c6cecbe9e9efb6bfde5f4fceaf95220b85882449b72427be"
      "4d38f966b38e36f315c91b7e3cd2cc577db5d43a3fe6b9cec50f9a19",
      "7326604f380543145a572a9c12869858dbd740d2c1e06a039423a44a545823144a9dc592"
      "5dd16c07d42a6cc83e9eab03de2e9954d2eb46fb09d5cea2a5473c72"
      "f27ec77ad4e367801e511ffe32f33a56e71462469dcb7522622527af72998b0257405509"
      "abc574bba4adb280848ae40aa19a0a149840827016ab9a0cdb0746a5",
      "caf50ab656d780c5b86c088455986d70a22086a1a8094a8ca34b2c025225a0c4086b806e"
      "409e30a016828de2ac8b4dd2c829680531ceb298257cfabd09d0a757"
      "fdae05eae7205cdeca9a2c3c3e43e826166dbec33ef90e7cb5e45be7e203d21f8edc93b4"
      "abdeb77bdcbf3fb7d78f1fe55fabdf6b760e8b8fe4a6ae87c9e7c679",
      "f1ed05dcafd7febd17c017f5e109792b4fd71364631aa801e9e7e984de58ef788ee52e3c"
      "dd9e430aa8c3baff659f0361f591f59d5025355347b20a45790bac0d"
      "34ec6f85f39affeec2ffe5fb1cc8e7c507e4bd9f28bfd506a1cd2ff5f78f50fde0f0c983"
      "48987c6e5c543fb81fc017f5e10d5a5b5959594aa7167733b9fc5ab9",
      "1c9f9ddec90d8f1f8ce682772ebc0fd86faf7a3ceca2878b634e3553400131a299d61e89"
      "4ac4fe22c25c26c8fa4d08cd27146e5a52b4f9c6fbec872f817c5e7c"
      "60fae194d710a65fbc9af81aaa5ffc7df46ee417d2d9fb452ab7f32c2e66a632f8699941"
      "f2c5e67e32c5e787c72f46f3e1e4f9d06f7fdde9a28b8b3bdc952a61",
      "48ad587bde6e9e3f2fbfe8f7fbe163209f171f907e3826bfdd03760cab4f7cf873430a93"
      "cf8d61f789e5e40c4ecf97d8aa96296bf1c7f14d81de26e7463e31f2"
      "89d375b9db451717cf816158d4c78ce2a2fac4a7403e2f3e20fd705cfea6518c7ce26cf8"
      "dc18769fc01bba0a0b7ab6b8a3e4b102bbc5d4e26e79087ce21fd7b9",
      "3c94",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 8144U, &nameCaptureInfo);
  return nameCaptureInfo;
}

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
                emlrtMxCreateString("inverseKinematicsOAModified"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(11.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString("/home/shobhit/ShobhitRobotModelling/robotmodelling/"
                          "Matlab_implementation/functions_for_codegen/"
                          "obstacleAvoidanceOptmisationModif"
                          "ied/inverseKinematicsOAModified.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739679.78365740739));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2459199 (R2023b) Update 5"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("Arje6NltUoH2S5ufE1BJOC"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "CoverageInfo",
                covrtSerializeInstanceData(&emlrtCoverageInstance));
  return xResult;
}

// End of code generation (_coder_inverseKinematicsOAModified_info.cpp)
