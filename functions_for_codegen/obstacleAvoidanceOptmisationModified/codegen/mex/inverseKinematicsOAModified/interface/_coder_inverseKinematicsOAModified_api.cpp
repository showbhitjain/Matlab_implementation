//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inverseKinematicsOAModified_api.cpp
//
// Code generation for function '_coder_inverseKinematicsOAModified_api'
//

// Include files
#include "_coder_inverseKinematicsOAModified_api.h"
#include "inverseKinematicsOAModified.h"
#include "inverseKinematicsOAModified_data.h"
#include "inverseKinematicsOAModified_mexutil.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Declarations
static real_T *b_emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier, int32_T y_size[2]);

static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2]);

static boolean_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static real_T *b_emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier, int32_T &y_size);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6]);

static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T &y_size);

static real_T *c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2]);

static real_T *c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size);

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6]);

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T *c_emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier, int32_T y_size[2]);

static real_T *d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size);

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6]);

static real_T *d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static real_T (*d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6];

static real_T *e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

static boolean_T e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, struct0_T &y);

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[6];

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[6];

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T y_size[2]);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T y_size[2]);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T &y_size);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T &y_size);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[6]);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T &y);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static real_T f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T *f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2]);

// Function Definitions
static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T &y_size)
{
  real_T *y_data;
  y_data = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T *b_emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier, int32_T &y_size)
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y_data = b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y_size);
  emlrtDestroyArray(&b_nullptr);
  return y_data;
}

static boolean_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2])
{
  real_T *y_data;
  y_data = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T *b_emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y_data = b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y_size);
  emlrtDestroyArray(&b_nullptr);
  return y_data;
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[6])
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T *c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId,
                                  int32_T y_size[2])
{
  real_T *y_data;
  y_data = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T *c_emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y_data = c_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y_size);
  emlrtDestroyArray(&b_nullptr);
  return y_data;
}

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims{6};
  real_T(*r)[6];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                          (const void *)&dims);
  r = (real_T(*)[6])emlrtMxGetData(src);
  for (int32_T i{0}; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T *c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size)
{
  static const int32_T dims{12};
  real_T *ret_data;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &ret_size);
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T *d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size)
{
  static const int32_T dims{100};
  real_T *ret_data;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &ret_size);
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6]
{
  static const int32_T dims{6};
  real_T(*ret)[6];
  int32_T i;
  boolean_T b{false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T *d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2]{6, 12};
  real_T *ret_data;
  int32_T b_iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret_size[0] = b_iv[0];
  ret_size[1] = b_iv[1];
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[6])
{
  static const int32_T dims[2]{1, 6};
  real_T(*r)[6];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[6])emlrtMxGetData(src);
  for (int32_T i{0}; i < 6; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static boolean_T e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "logical", false, 0U,
                          (const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T *e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2]{100, 12};
  real_T *ret_data;
  int32_T b_iv[2];
  boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret_size[0] = b_iv[0];
  ret_size[1] = b_iv[1];
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T &y_size)
{
  real_T *y_data;
  y_data = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T y_size[2])
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y_data = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y_size);
  emlrtDestroyArray(&b_nullptr);
  return y_data;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T y_size[2])
{
  real_T *y_data;
  y_data = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
  emlrtDestroyArray(&u);
  return y_data;
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T &y_size)
{
  emlrtMsgIdentifier thisId;
  real_T *y_data;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y_data = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y_size);
  emlrtDestroyArray(&b_nullptr);
  return y_data;
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[6]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[6];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId))[6]
{
  real_T(*y)[6];
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[6])
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[25]{"useObjectiveNormInfinity",
                                      "weightNormInfinity",
                                      "useObjectiveNormL2",
                                      "weightNormL2",
                                      "useObjectiveTrajectoryFollowing",
                                      "weightTrajectoryFollowing",
                                      "useObjectiveJointAcceleration",
                                      "weightJointAcceleration",
                                      "useObjectiveManipulability",
                                      "weightManipulability",
                                      "applyEqualityConstraints",
                                      "applyInequalityConstraints",
                                      "applySlack",
                                      "Slacklowerbound",
                                      "Slackupperbound",
                                      "SlackPenaltyWeight",
                                      "SlackObjectiveWeight",
                                      "obstacleAvoidanceScheme",
                                      "k",
                                      "gamma",
                                      "dynamicSlack",
                                      "applyVelocityDamper",
                                      "jointLimitActivationDistance",
                                      "jointLimitStopDistance",
                                      "jointLimitGain"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)&sp, parentId, u, 25,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "useObjectiveNormInfinity";
  y.useObjectiveNormInfinity = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 0,
                                     "useObjectiveNormInfinity")),
      &thisId);
  thisId.fIdentifier = "weightNormInfinity";
  y.weightNormInfinity = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 1,
                                     "weightNormInfinity")),
      &thisId);
  thisId.fIdentifier = "useObjectiveNormL2";
  y.useObjectiveNormL2 = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 2,
                                     "useObjectiveNormL2")),
      &thisId);
  thisId.fIdentifier = "weightNormL2";
  y.weightNormL2 =
      c_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 3, "weightNormL2")),
                         &thisId);
  thisId.fIdentifier = "useObjectiveTrajectoryFollowing";
  y.useObjectiveTrajectoryFollowing = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 4,
                                     "useObjectiveTrajectoryFollowing")),
      &thisId);
  thisId.fIdentifier = "weightTrajectoryFollowing";
  y.weightTrajectoryFollowing = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 5,
                                     "weightTrajectoryFollowing")),
      &thisId);
  thisId.fIdentifier = "useObjectiveJointAcceleration";
  y.useObjectiveJointAcceleration = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 6,
                                     "useObjectiveJointAcceleration")),
      &thisId);
  thisId.fIdentifier = "weightJointAcceleration";
  y.weightJointAcceleration = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 7,
                                     "weightJointAcceleration")),
      &thisId);
  thisId.fIdentifier = "useObjectiveManipulability";
  y.useObjectiveManipulability = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 8,
                                     "useObjectiveManipulability")),
      &thisId);
  thisId.fIdentifier = "weightManipulability";
  y.weightManipulability = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 9,
                                     "weightManipulability")),
      &thisId);
  thisId.fIdentifier = "applyEqualityConstraints";
  y.applyEqualityConstraints = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 10,
                                     "applyEqualityConstraints")),
      &thisId);
  thisId.fIdentifier = "applyInequalityConstraints";
  y.applyInequalityConstraints = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 11,
                                     "applyInequalityConstraints")),
      &thisId);
  thisId.fIdentifier = "applySlack";
  y.applySlack =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 12, "applySlack")),
                         &thisId);
  thisId.fIdentifier = "Slacklowerbound";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 13,
                                                  "Slacklowerbound")),
                   &thisId, y.Slacklowerbound);
  thisId.fIdentifier = "Slackupperbound";
  emlrt_marshallIn(sp,
                   emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 14,
                                                  "Slackupperbound")),
                   &thisId, y.Slackupperbound);
  thisId.fIdentifier = "SlackPenaltyWeight";
  b_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                    15, "SlackPenaltyWeight")),
                     &thisId, y.SlackPenaltyWeight);
  thisId.fIdentifier = "SlackObjectiveWeight";
  y.SlackObjectiveWeight = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 16,
                                     "SlackObjectiveWeight")),
      &thisId);
  thisId.fIdentifier = "obstacleAvoidanceScheme";
  y.obstacleAvoidanceScheme = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 17,
                                     "obstacleAvoidanceScheme")),
      &thisId);
  thisId.fIdentifier = "k";
  y.k = c_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 18, "k")),
      &thisId);
  thisId.fIdentifier = "gamma";
  y.gamma = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 19, "gamma")),
      &thisId);
  thisId.fIdentifier = "dynamicSlack";
  y.dynamicSlack =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 20, "dynamicSlack")),
                         &thisId);
  thisId.fIdentifier = "applyVelocityDamper";
  y.applyVelocityDamper = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 21,
                                     "applyVelocityDamper")),
      &thisId);
  thisId.fIdentifier = "jointLimitActivationDistance";
  y.jointLimitActivationDistance = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 22,
                                     "jointLimitActivationDistance")),
      &thisId);
  thisId.fIdentifier = "jointLimitStopDistance";
  y.jointLimitStopDistance = c_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 23,
                                     "jointLimitStopDistance")),
      &thisId);
  thisId.fIdentifier = "jointLimitGain";
  y.jointLimitGain =
      c_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtConstCTX)&sp, u, 0, 24, "jointLimitGain")),
                         &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, struct0_T &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 1U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 1U> *)&u)->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static real_T *f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T ret_size[2])
{
  static const int32_T dims[2]{12, 12};
  real_T *ret_data;
  int32_T b_iv[2];
  boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret_size[0] = b_iv[0];
  ret_size[1] = b_iv[1];
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

void inverseKinematicsOAModified_api(const mxArray *const prhs[11],
                                     int32_T nlhs, const mxArray *plhs[2])
{
  coder::array<real_T, 1U> optimal_joint_velocity;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T configInput;
  real_T(*J_g_data)[1200];
  real_T(*jointVelocityWeightMatrix_data)[144];
  real_T(*b_g_data)[100];
  real_T(*jacobi_data)[72];
  real_T(*joint_max_vel_data)[12];
  real_T(*joint_min_vel_data)[12];
  real_T(*joint_values_data)[12];
  real_T(*jointmaxvalues_data)[12];
  real_T(*jointminvalues_data)[12];
  real_T(*xd_eff_vel)[6];
  real_T Exit_Flag;
  int32_T J_g_size[2];
  int32_T jacobi_size[2];
  int32_T jointVelocityWeightMatrix_size[2];
  int32_T b_g_size;
  int32_T joint_max_vel_size;
  int32_T joint_min_vel_size;
  int32_T joint_values_size;
  int32_T jointmaxvalues_size;
  int32_T jointminvalues_size;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  *(real_T **)&joint_values_data = emlrt_marshallIn(
      st, emlrtAlias(prhs[0]), "joint_values", joint_values_size);
  *(real_T **)&jacobi_data =
      emlrt_marshallIn(st, emlrtAlias(prhs[1]), "jacobi", jacobi_size);
  xd_eff_vel = emlrt_marshallIn(st, emlrtAlias(prhs[2]), "xd_eff_vel");
  *(real_T **)&jointminvalues_data = emlrt_marshallIn(
      st, emlrtAlias(prhs[3]), "jointminvalues", jointminvalues_size);
  *(real_T **)&jointmaxvalues_data = emlrt_marshallIn(
      st, emlrtAlias(prhs[4]), "jointmaxvalues", jointmaxvalues_size);
  *(real_T **)&joint_min_vel_data = emlrt_marshallIn(
      st, emlrtAlias(prhs[5]), "joint_min_vel", joint_min_vel_size);
  *(real_T **)&joint_max_vel_data = emlrt_marshallIn(
      st, emlrtAlias(prhs[6]), "joint_max_vel", joint_max_vel_size);
  *(real_T **)&J_g_data =
      b_emlrt_marshallIn(st, emlrtAlias(prhs[7]), "J_g", J_g_size);
  *(real_T **)&b_g_data =
      b_emlrt_marshallIn(st, emlrtAlias(prhs[8]), "b_g", b_g_size);
  *(real_T **)&jointVelocityWeightMatrix_data =
      c_emlrt_marshallIn(st, emlrtAlias(prhs[9]), "jointVelocityWeightMatrix",
                         jointVelocityWeightMatrix_size);
  emlrt_marshallIn(st, emlrtAliasP(prhs[10]), "configInput", configInput);
  // Invoke the target function
  inverseKinematicsOAModified(
      &st, *joint_values_data, &joint_values_size, *jacobi_data, jacobi_size,
      *xd_eff_vel, *jointminvalues_data, &jointminvalues_size,
      *jointmaxvalues_data, &jointmaxvalues_size, *joint_min_vel_data,
      &joint_min_vel_size, *joint_max_vel_data, &joint_max_vel_size, *J_g_data,
      J_g_size, *b_g_data, &b_g_size, *jointVelocityWeightMatrix_data,
      jointVelocityWeightMatrix_size, &configInput, optimal_joint_velocity,
      &Exit_Flag);
  // Marshall function outputs
  optimal_joint_velocity.no_free();
  plhs[0] = emlrt_marshallOut(optimal_joint_velocity);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(Exit_Flag);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_inverseKinematicsOAModified_api.cpp)
