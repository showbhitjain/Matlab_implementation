//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_orientationTrajectory_mex_api.cpp
//
// Code generation for function '_coder_orientationTrajectory_mex_api'
//

// Include files
#include "_coder_orientationTrajectory_mex_api.h"
#include "orientationTrajectory.h"
#include "orientationTrajectory_mex_data.h"
#include "positionTrajectory.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace trajectoryGeneration {
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               ::coder::array<real_T, 2U> &y);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               ::coder::array<real_T, 2U> &y);

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<char_T, 2U> &ret);

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               ::coder::array<real_T, 2U> &y);

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               ::coder::array<real_T, 2U> &y);

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<real_T, 2U> &ret);

static void e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<real_T, 2U> &ret);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             ::coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             ::coder::array<real_T, 2U> &y);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             ::coder::array<char_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             ::coder::array<char_T, 2U> &y);

static const mxArray *emlrt_marshallOut(const ::coder::array<real_T, 2U> &u);

static void f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<real_T, 2U> &ret);

} // namespace trajectoryGeneration

// Function Definitions
namespace trajectoryGeneration {
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<char_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "char", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  emlrtImportArrayR2015b((emlrtConstCTX)&sp, src, &ret[0], 1, false);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               ::coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               ::coder::array<real_T, 2U> &y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
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

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               ::coder::array<real_T, 2U> &y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               ::coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  c_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{4, -1};
  int32_T iv[2];
  boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             ::coder::array<real_T, 2U> &y)
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
                             ::coder::array<char_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             ::coder::array<char_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             ::coder::array<real_T, 2U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const ::coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m,
                 &(((::coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((::coder::array<real_T, 2U> *)&u)->size(),
                     2);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               ::coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{3, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

void orientationTrajectory_api(const mxArray *const prhs[4], int32_T nlhs,
                               const mxArray *plhs[3])
{
  ::coder::array<real_T, 2U> desired_angular_accel;
  ::coder::array<real_T, 2U> desired_angular_velocity;
  ::coder::array<real_T, 2U> desired_quaternions;
  ::coder::array<real_T, 2U> orientations;
  ::coder::array<real_T, 2U> waypointTimes;
  ::coder::array<char_T, 2U> trajType;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T ts;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  orientations.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[0]), "orientations", orientations);
  waypointTimes.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[1]), "waypointTimes", waypointTimes);
  ts = emlrt_marshallIn(st, emlrtAliasP(prhs[2]), "ts");
  emlrt_marshallIn(st, emlrtAliasP(prhs[3]), "trajType", trajType);
  // Invoke the target function
  orientationTrajectory(&st, orientations, waypointTimes, ts, trajType,
                        desired_quaternions, desired_angular_velocity,
                        desired_angular_accel);
  // Marshall function outputs
  desired_quaternions.no_free();
  plhs[0] = emlrt_marshallOut(desired_quaternions);
  if (nlhs > 1) {
    desired_angular_velocity.no_free();
    plhs[1] = emlrt_marshallOut(desired_angular_velocity);
  }
  if (nlhs > 2) {
    desired_angular_accel.no_free();
    plhs[2] = emlrt_marshallOut(desired_angular_accel);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void positionTrajectory_api(const mxArray *const prhs[6], int32_T nlhs,
                            const mxArray *plhs[3])
{
  ::coder::array<real_T, 2U> waypointAccels;
  ::coder::array<real_T, 2U> waypointTimes;
  ::coder::array<real_T, 2U> waypointVels;
  ::coder::array<real_T, 2U> waypoints;
  ::coder::array<real_T, 2U> xd;
  ::coder::array<real_T, 2U> xd_vel;
  ::coder::array<real_T, 2U> xdd;
  ::coder::array<char_T, 2U> trajType;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  real_T ts;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  prhs_copy_idx_4 = emlrtProtectR2012b(prhs[4], 4, false, -1);
  prhs_copy_idx_5 = emlrtProtectR2012b(prhs[5], 5, false, -1);
  // Marshall function inputs
  waypoints.no_free();
  c_emlrt_marshallIn(st, emlrtAlias(prhs[0]), "waypoints", waypoints);
  waypointTimes.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[1]), "waypointTimes", waypointTimes);
  ts = emlrt_marshallIn(st, emlrtAliasP(prhs[2]), "ts");
  emlrt_marshallIn(st, emlrtAliasP(prhs[3]), "trajType", trajType);
  waypointVels.no_free();
  c_emlrt_marshallIn(st, emlrtAlias(prhs_copy_idx_4), "waypointVels",
                     waypointVels);
  waypointAccels.no_free();
  c_emlrt_marshallIn(st, emlrtAlias(prhs_copy_idx_5), "waypointAccels",
                     waypointAccels);
  // Invoke the target function
  positionTrajectory(&st, waypoints, waypointTimes, ts, trajType, waypointVels,
                     waypointAccels, xd, xd_vel, xdd);
  // Marshall function outputs
  xd.no_free();
  plhs[0] = emlrt_marshallOut(xd);
  if (nlhs > 1) {
    xd_vel.no_free();
    plhs[1] = emlrt_marshallOut(xd_vel);
  }
  if (nlhs > 2) {
    xdd.no_free();
    plhs[2] = emlrt_marshallOut(xdd);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

} // namespace trajectoryGeneration

// End of code generation (_coder_orientationTrajectory_mex_api.cpp)
