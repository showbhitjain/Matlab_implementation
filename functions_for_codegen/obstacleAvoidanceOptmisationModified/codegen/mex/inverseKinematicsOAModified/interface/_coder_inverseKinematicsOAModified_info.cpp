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
      "789ced574d6fd3401075504195f80a487043953870ac13da24aac4a5b40969439ab6a95a"
      "1a40c15e4f926dbdbbaebd4e5bb8f00f7a452071e427a09eb971431c"
      "38f20b38207e01761d27b15b3711a9dcd4642ee3f15bfb799f47f36c21b6508c09827043"
      "70e270c2c9d75b75bc952f09def0e3b156beecab85f6f931cf752e7e",
      "d0ca88510e7bdc29a844a07da5c208a612e56bfb1a083a184c6d827284d4b00a6b9840b9"
      "bb58b22b92eb82da850dd9c7730d40db6593087ac3e83ca1da5db4f5"
      "48c44edeef589f7a7c0dd023eec39f675f8a0d4640341a4c6e602e969dbcca64c68b4c01"
      "55c5b42eea7649da6551e2aa245731d1542040b9c431a362cda4c83e",
      "30aa35a65791b5ba0e5464b2c125a4c26c936145a2084a1a27d838bac422c0350c8a8869"
      "1374030a9802b1106494665d6c92c44e41ab1265348768d2a7dfab00"
      "7dfad5ef4aa07e0ec2e4ad9c49c3e333b86e22dee1fb3d20df81af167ceb5c7c48fac391"
      "7b92f4d4fb669ffbf7e7cefaf1a3fc6df54bddce61f1e1fcd4d530f9",
      "dc382fbebd80fbf5dbbf7702f8e23e3c296f15c87a126f4c033120f33493d49beb5dcfb1"
      "dc83a7d77308017558f7ffdfe740587d647d27d470ddd425598592bc"
      "05d6069af6b7c279cd7f77e1bff27d0ce4f3e243f2de4f94df6a83d0e6d78fef87a1fac1"
      "cf470fc6c3e473e3a2fac1dd00beb80f6f92facacaca5226bdb89bcd",
      "17d62a95c4ecf44e3e3a7e309a0bdeb9f03660bffdea71af871e2e8e18d14c0e458962cd"
      "b4f68855ccf71725c4642c59bf09a1f984c24c4b8a0edff880fdf029"
      "90cf8b0f4d3f9cf21ac2f48b17139f43f58b3ff7dfc4c2e47323ea7e91ceef3c49f099a9"
      "2c7a5ca1907ab6b99f4ab3f9e8f8c5683e9c3c1f06edaf5b3d747171",
      "87bb5ac35452abd69eb75be7cfcb2f06fd7e781fc8e7c587a41f8ec96ff7801d51f58977"
      "bfae0961f2b911759f584ecda0cc7c99ae6ad98a967898d8e4d2ebd4"
      "dcc827463e71ba2eb77be8e2e279300c8bfa98515c549ff810c8e7c587a41f8ecbdf328a"
      "914f9c0d9f1b51f709b4a1abb0a0e74a3b4a0129b05b4a2fee5622e0",
      "137f0174973cd8",
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
                emlrtMxCreateDoubleScalar(739677.05752314813));
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
