//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_inverseKinematics_api.cpp
//
// Code generation for function '_coder_inverseKinematics_api'
//

// Include files
#include "_coder_inverseKinematics_api.h"
#include "inverseKinematics.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_mexutil.h"
#include "inverseKinematics_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size);

static boolean_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static real_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, struct0_T &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T &y);

static boolean_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                const char_T *identifier, int32_T &y_size);

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T &y_size);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

// Function Definitions
static real_T *b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId,
                                  int32_T &ret_size)
{
  static const int32_T dims{6};
  real_T *ret_data;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &ret_size);
  ret_data = static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret_data;
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{6, -1};
  int32_T b_iv[2];
  boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret.prealloc(b_iv[0] * b_iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, b_iv[0], b_iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret.prealloc(i);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, i);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

static boolean_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
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

static real_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
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

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static real_T *emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                int32_T &y_size)
{
  real_T *y_data;
  y_data = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_size);
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

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[12]{
      "useObjective1", "weight1", "useObjective2", "weight2",
      "useObjective3", "weight3", "useObjective4", "weight4",
      "useObjective5", "weight5", "useObjective6", "weight6"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)&sp, parentId, u, 12,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "useObjective1";
  y.useObjective1 =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      0, "useObjective1")),
                       &thisId);
  thisId.fIdentifier = "weight1";
  y.weight1 = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 1, "weight1")),
      &thisId);
  thisId.fIdentifier = "useObjective2";
  y.useObjective2 =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      2, "useObjective2")),
                       &thisId);
  thisId.fIdentifier = "weight2";
  y.weight2 = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 3, "weight2")),
      &thisId);
  thisId.fIdentifier = "useObjective3";
  y.useObjective3 =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      4, "useObjective3")),
                       &thisId);
  thisId.fIdentifier = "weight3";
  y.weight3 = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 5, "weight3")),
      &thisId);
  thisId.fIdentifier = "useObjective4";
  y.useObjective4 =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      6, "useObjective4")),
                       &thisId);
  thisId.fIdentifier = "weight4";
  y.weight4 = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 7, "weight4")),
      &thisId);
  thisId.fIdentifier = "useObjective5";
  y.useObjective5 =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      8, "useObjective5")),
                       &thisId);
  thisId.fIdentifier = "weight5";
  y.weight5 = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 9, "weight5")),
      &thisId);
  thisId.fIdentifier = "useObjective6";
  y.useObjective6 =
      emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0,
                                                      10, "useObjective6")),
                       &thisId);
  thisId.fIdentifier = "weight6";
  y.weight6 = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 11, "weight6")),
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

void inverseKinematics_api(const mxArray *const prhs[8], int32_T nlhs,
                           const mxArray *plhs[2])
{
  coder::array<real_T, 2U> jacobi;
  coder::array<real_T, 1U> joint_max_vel;
  coder::array<real_T, 1U> joint_min_vel;
  coder::array<real_T, 1U> joint_values;
  coder::array<real_T, 1U> jointmaxvalues;
  coder::array<real_T, 1U> jointminvalues;
  coder::array<real_T, 1U> optimal_joint_velocity;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T config;
  real_T(*xd_eff_vel_data)[6];
  real_T Exit_Flag;
  int32_T xd_eff_vel_size;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  joint_values.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[0]), "joint_values", joint_values);
  jacobi.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[1]), "jacobi", jacobi);
  *(real_T **)&xd_eff_vel_data =
      emlrt_marshallIn(st, emlrtAlias(prhs[2]), "xd_eff_vel", xd_eff_vel_size);
  jointminvalues.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[3]), "jointminvalues", jointminvalues);
  jointmaxvalues.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[4]), "jointmaxvalues", jointmaxvalues);
  joint_min_vel.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[5]), "joint_min_vel", joint_min_vel);
  joint_max_vel.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[6]), "joint_max_vel", joint_max_vel);
  emlrt_marshallIn(st, emlrtAliasP(prhs[7]), "config", config);
  // Invoke the target function
  inverseKinematics(&st, joint_values, jacobi, *xd_eff_vel_data,
                    &xd_eff_vel_size, jointminvalues, jointmaxvalues,
                    joint_min_vel, joint_max_vel, &config,
                    optimal_joint_velocity, &Exit_Flag);
  // Marshall function outputs
  optimal_joint_velocity.no_free();
  plhs[0] = emlrt_marshallOut(optimal_joint_velocity);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(Exit_Flag);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_inverseKinematics_api.cpp)
