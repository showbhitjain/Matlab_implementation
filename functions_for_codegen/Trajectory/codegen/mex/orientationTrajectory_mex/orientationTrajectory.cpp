//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// orientationTrajectory.cpp
//
// Code generation for function 'orientationTrajectory'
//

// Include files
#include "orientationTrajectory.h"
#include "colon.h"
#include "cubicpolytraj.h"
#include "eul2quat.h"
#include "orientationTrajectory_mex_data.h"
#include "orientationTrajectory_mex_mexutil.h"
#include "quaternion.h"
#include "quinticpolytraj.h"
#include "rottraj.h"
#include "rt_nonfinite.h"
#include "trapveltraj.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include "omp.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    9,                       // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    21,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    22,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    27,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    32,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    38,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    42,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    44,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    46,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    50,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    57,                      // lineNo
    "orientationTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    9,                       // lineNo
    36,                      // colNo
    "waypointTimes",         // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    21,                      // lineNo
    49,                      // colNo
    "orientations",          // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    22,                      // lineNo
    49,                      // colNo
    "orientations",          // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    24,                      // lineNo
    40,                      // colNo
    "orientations",          // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    25,                      // lineNo
    40,                      // colNo
    "orientations",          // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtDCInfo emlrtDCI{
    57,                      // lineNo
    28,                      // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    1                             // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    57,                      // lineNo
    28,                      // colNo
    "desired_quaternions",   // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    57,                      // lineNo
    38,                      // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    1                             // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    57,                      // lineNo
    38,                      // colNo
    "desired_quaternions",   // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                      // nDims
    57,                      // lineNo
    5,                       // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

static emlrtDCInfo c_emlrtDCI{
    58,                      // lineNo
    33,                      // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    1                             // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    58,                         // lineNo
    33,                         // colNo
    "desired_angular_velocity", // aName
    "orientationTrajectory",    // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    58,                      // lineNo
    43,                      // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    1                             // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                         // iFirst
    -1,                         // iLast
    58,                         // lineNo
    43,                         // colNo
    "desired_angular_velocity", // aName
    "orientationTrajectory",    // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtECInfo b_emlrtECI{
    -1,                      // nDims
    58,                      // lineNo
    5,                       // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

static emlrtDCInfo e_emlrtDCI{
    59,                      // lineNo
    30,                      // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    1                             // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    59,                      // lineNo
    30,                      // colNo
    "desired_angular_accel", // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    59,                      // lineNo
    40,                      // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    1                             // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    59,                      // lineNo
    40,                      // colNo
    "desired_angular_accel", // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtECInfo c_emlrtECI{
    -1,                      // nDims
    59,                      // lineNo
    5,                       // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

static emlrtBCInfo l_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    29,                      // lineNo
    34,                      // colNo
    "waypointTimes",         // aName
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m", // pName
    0                             // checkKind
};

static emlrtRTEInfo lb_emlrtRTEI{
    11,                      // lineNo
    1,                       // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    12,                      // lineNo
    1,                       // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    13,                      // lineNo
    1,                       // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    32,                      // lineNo
    5,                       // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    308,                                                              // lineNo
    14,                                                               // colNo
    "cat",                                                            // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    57,                      // lineNo
    49,                      // colNo
    "orientationTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/orientationTrajectory.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
emlrtCTX emlrtGetRootTLSGlobal()
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void orientationTrajectory(const emlrtStack *sp,
                           const ::coder::array<real_T, 2U> &orientations,
                           const ::coder::array<real_T, 2U> &waypointTimes,
                           real_T ts,
                           const ::coder::array<char_T, 2U> &trajType,
                           ::coder::array<real_T, 2U> &desired_quaternions,
                           ::coder::array<real_T, 2U> &desired_angular_velocity,
                           ::coder::array<real_T, 2U> &desired_angular_accel)
{
  static const int32_T iv[2]{1, 19};
  static const int32_T iv1[2]{1, 58};
  static const char_T c_varargin_1[58]{
      'I', 'n',  'v', 'a', 'l', 'i',  'd', ' ',  't', 'r', 'a',  'j',
      'e', 'c',  't', 'o', 'r', 'y',  ' ', 't',  'y', 'p', 'e',  '!',
      ' ', 'U',  's', 'e', ' ', '\'', 't', 'r',  'a', 'p', '\'', ',',
      ' ', '\'', 'c', 'u', 'b', 'i',  'c', '\'', ',', ' ', 'o',  'r',
      ' ', '\'', 'q', 'u', 'i', 'n',  't', 'i',  'c', '\''};
  static const char_T varargin_1[19]{'I', 'n', 'v', 'a', 'l', 'i', 'd',
                                     ' ', 'O', 'r', 'i', 'e', 'n', 't',
                                     'a', 't', 'i', 'o', 'n'};
  static const char_T cv2[7]{'q', 'u', 'i', 'n', 't', 'i', 'c'};
  static const char_T cv1[5]{'c', 'u', 'b', 'i', 'c'};
  static const char_T cv[4]{'t', 'r', 'a', 'p'};
  coder::b_quaternion R;
  coder::quaternion R0;
  coder::quaternion Rf;
  ::coder::array<real_T, 2U> alpha;
  ::coder::array<real_T, 2U> b_s;
  ::coder::array<real_T, 2U> omega;
  ::coder::array<real_T, 2U> r;
  ::coder::array<real_T, 2U> r1;
  ::coder::array<real_T, 2U> s;
  ::coder::array<real_T, 2U> sd;
  ::coder::array<real_T, 2U> sdd;
  ::coder::array<real_T, 2U> trajTimes_rot;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T a;
  int32_T trajTimes_size[2];
  int32_T i;
  int32_T loop_ub;
  boolean_T b;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  // UNTITLED Summary of this function goes here
  //    Detailed explanation goes here
  //  Define trajectory sample times
  st.site = &emlrtRSI;
  if (waypointTimes.size(1) < 1) {
    emlrtDynamicBoundsCheckR2012b(waypointTimes.size(1), 1,
                                  waypointTimes.size(1), &emlrtBCI, &st);
  }
  b = muDoubleScalarIsNaN(ts);
  guard1 = false;
  if (b) {
    guard1 = true;
  } else {
    a = waypointTimes[waypointTimes.size(1) - 1];
    if (muDoubleScalarIsNaN(a)) {
      guard1 = true;
    } else if ((ts == 0.0) || ((a > 0.0) && (ts < 0.0)) ||
               ((a < 0.0) && (ts > 0.0))) {
      trajTimes_size[1] = 0;
    } else if (muDoubleScalarIsInf(a) && muDoubleScalarIsInf(ts)) {
      trajTimes_size[1] = 1;
    } else if (muDoubleScalarIsInf(ts)) {
      trajTimes_size[1] = 1;
    } else if (muDoubleScalarFloor(ts) == ts) {
      trajTimes_size[1] = static_cast<int32_T>(a / ts) + 1;
    } else {
      b_st.site = &l_emlrtRSI;
      coder::eml_float_colon(b_st, ts, a, trajTimes_rot);
      trajTimes_size[1] = trajTimes_rot.size(1);
    }
  }
  if (guard1) {
    trajTimes_size[1] = 1;
  }
  desired_quaternions.set_size(&lb_emlrtRTEI, sp, 4, trajTimes_size[1]);
  loop_ub = trajTimes_size[1] << 2;
  for (i = 0; i < loop_ub; i++) {
    desired_quaternions[i] = 0.0;
  }
  desired_angular_velocity.set_size(&mb_emlrtRTEI, sp, 3, trajTimes_size[1]);
  loop_ub = 3 * trajTimes_size[1];
  for (i = 0; i < loop_ub; i++) {
    desired_angular_velocity[i] = 0.0;
  }
  desired_angular_accel.set_size(&nb_emlrtRTEI, sp, 3, trajTimes_size[1]);
  for (i = 0; i < loop_ub; i++) {
    desired_angular_accel[i] = 0.0;
  }
  //  Loop through trajectory generation
  i = orientations.size(1);
  for (int32_T w{0}; w <= i - 2; w++) {
    real_T timeInterval[2];
    real_T b_tmp;
    real_T c_y;
    int32_T exitg1;
    int32_T i1;
    int32_T i2;
    int32_T trajTimes_size_tmp;
    boolean_T result;
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
    if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 0,
                   orientations.size(0) == 3)) {
      real_T b_varargin_1[4];
      real_T orientations_data[3];
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
      if (w + 1 > orientations.size(1)) {
        emlrtDynamicBoundsCheckR2012b(w + 1, 1, orientations.size(1),
                                      &b_emlrtBCI, (emlrtConstCTX)sp);
      }
      orientations_data[0] = orientations[orientations.size(0) * w];
      orientations_data[1] = orientations[orientations.size(0) * w + 1];
      orientations_data[2] = orientations[orientations.size(0) * w + 2];
      st.site = &b_emlrtRSI;
      coder::eul2quat(orientations_data, b_varargin_1);
      R0.a = b_varargin_1[0];
      R0.b = b_varargin_1[1];
      R0.c = b_varargin_1[2];
      R0.d = b_varargin_1[3];
      if (w + 2 > orientations.size(1)) {
        emlrtDynamicBoundsCheckR2012b(w + 2, 1, orientations.size(1),
                                      &c_emlrtBCI, (emlrtConstCTX)sp);
      }
      orientations_data[0] = orientations[orientations.size(0) * (w + 1)];
      orientations_data[1] = orientations[orientations.size(0) * (w + 1) + 1];
      orientations_data[2] = orientations[orientations.size(0) * (w + 1) + 2];
      st.site = &c_emlrtRSI;
      coder::eul2quat(orientations_data, b_varargin_1);
      Rf.a = b_varargin_1[0];
      Rf.b = b_varargin_1[1];
      Rf.c = b_varargin_1[2];
      Rf.d = b_varargin_1[3];
    } else if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 1,
                          orientations.size(0) == 4)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
      if (w + 1 > orientations.size(1)) {
        emlrtDynamicBoundsCheckR2012b(w + 1, 1, orientations.size(1),
                                      &d_emlrtBCI, (emlrtConstCTX)sp);
      }
      R0.a = orientations[orientations.size(0) * w];
      R0.b = orientations[orientations.size(0) * w + 1];
      R0.c = orientations[orientations.size(0) * w + 2];
      R0.d = orientations[orientations.size(0) * w + 3];
      if (w + 2 > orientations.size(1)) {
        emlrtDynamicBoundsCheckR2012b(w + 2, 1, orientations.size(1),
                                      &e_emlrtBCI, (emlrtConstCTX)sp);
      }
      Rf.a = orientations[orientations.size(0) * (w + 1)];
      Rf.b = orientations[orientations.size(0) * (w + 1) + 1];
      Rf.c = orientations[orientations.size(0) * (w + 1) + 2];
      Rf.d = orientations[orientations.size(0) * (w + 1) + 3];
    } else {
      st.site = &d_emlrtRSI;
      y = nullptr;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&st, 19, m, &varargin_1[0]);
      emlrtAssign(&y, m);
      b_st.site = &uh_emlrtRSI;
      b_error(b_st, y, emlrtMCI);
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
    if (w + 1 > waypointTimes.size(1)) {
      emlrtDynamicBoundsCheckR2012b(w + 1, 1, waypointTimes.size(1),
                                    &l_emlrtBCI, (emlrtConstCTX)sp);
    }
    timeInterval[0] = waypointTimes[w];
    if (w + 2 > waypointTimes.size(1)) {
      emlrtDynamicBoundsCheckR2012b(w + 2, 1, waypointTimes.size(1),
                                    &l_emlrtBCI, (emlrtConstCTX)sp);
    }
    timeInterval[1] = waypointTimes[w + 1];
    //  Recalculate trajectory times for the segment
    st.site = &e_emlrtRSI;
    a = waypointTimes[w];
    b_tmp = waypointTimes[static_cast<int32_T>(static_cast<uint32_T>(w) + 1U)];
    if (muDoubleScalarIsNaN(a) || b || muDoubleScalarIsNaN(b_tmp)) {
      trajTimes_rot.set_size(&ob_emlrtRTEI, &st, 1, 1);
      trajTimes_rot[0] = rtNaN;
    } else if ((ts == 0.0) || ((waypointTimes[w] < b_tmp) && (ts < 0.0)) ||
               ((b_tmp < waypointTimes[w]) && (ts > 0.0))) {
      trajTimes_rot.set_size(&ob_emlrtRTEI, &st, 1, 0);
    } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(b_tmp)) &&
               (muDoubleScalarIsInf(ts) || (waypointTimes[w] == b_tmp))) {
      trajTimes_rot.set_size(&ob_emlrtRTEI, &st, 1, 1);
      trajTimes_rot[0] = rtNaN;
    } else if (muDoubleScalarIsInf(ts)) {
      trajTimes_rot.set_size(&ob_emlrtRTEI, &st, 1, 1);
      trajTimes_rot[0] = waypointTimes[w];
    } else if ((muDoubleScalarFloor(a) == waypointTimes[w]) &&
               (muDoubleScalarFloor(ts) == ts)) {
      a = waypointTimes[w];
      loop_ub = static_cast<int32_T>((b_tmp - a) / ts);
      trajTimes_rot.set_size(&ob_emlrtRTEI, &st, 1, loop_ub + 1);
      for (i1 = 0; i1 <= loop_ub; i1++) {
        trajTimes_rot[i1] = a + ts * static_cast<real_T>(i1);
      }
    } else {
      b_st.site = &l_emlrtRSI;
      coder::eml_float_colon(b_st, waypointTimes[w], ts, b_tmp, trajTimes_rot);
    }
    //  Use appropriate trajectory generation method
    result = false;
    if (trajType.size(1) == 4) {
      loop_ub = 0;
      do {
        exitg1 = 0;
        if (loop_ub < 4) {
          if (cv[loop_ub] != trajType[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      loop_ub = 0;
    } else {
      result = false;
      if (trajType.size(1) == 5) {
        loop_ub = 0;
        do {
          exitg1 = 0;
          if (loop_ub < 5) {
            if (cv1[loop_ub] != trajType[loop_ub]) {
              exitg1 = 1;
            } else {
              loop_ub++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        loop_ub = 1;
      } else {
        result = false;
        if (trajType.size(1) == 7) {
          loop_ub = 0;
          do {
            exitg1 = 0;
            if (loop_ub < 7) {
              if (cv2[loop_ub] != trajType[loop_ub]) {
                exitg1 = 1;
              } else {
                loop_ub++;
              }
            } else {
              result = true;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }
        if (result) {
          loop_ub = 2;
        } else {
          loop_ub = -1;
        }
      }
    }
    switch (loop_ub) {
    case 0:
      covrtLogSwitch(&emlrtCoverageInstance, 0, 0, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 4);
      a = b_tmp - waypointTimes[w];
      st.site = &f_emlrtRSI;
      coder::trapveltraj(st, muDoubleScalarRound(a / ts) + 1.0, a / 3.0,
                         a * 2.0 / 3.0, s, sd, sdd);
      break;
    case 1:
      covrtLogSwitch(&emlrtCoverageInstance, 0, 0, 0, 2);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
      st.site = &g_emlrtRSI;
      coder::cubicpolytraj(st, timeInterval, trajTimes_rot, s, sd, sdd);
      break;
    case 2:
      covrtLogSwitch(&emlrtCoverageInstance, 0, 0, 0, 3);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 6);
      st.site = &h_emlrtRSI;
      coder::quinticpolytraj(st, timeInterval, trajTimes_rot, s, sd, sdd);
      break;
    default:
      covrtLogSwitch(&emlrtCoverageInstance, 0, 0, 0, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, 0, 7);
      st.site = &i_emlrtRSI;
      b_y = nullptr;
      m = emlrtCreateCharArray(2, &iv1[0]);
      emlrtInitCharArrayR2013a(&st, 58, m, &c_varargin_1[0]);
      emlrtAssign(&b_y, m);
      b_st.site = &uh_emlrtRSI;
      b_error(b_st, b_y, emlrtMCI);
      break;
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 8);
    //  Generate the rotation trajectory
    st.site = &j_emlrtRSI;
    b_st.site = &ed_emlrtRSI;
    c_st.site = &fd_emlrtRSI;
    loop_ub = s.size(1);
    if (sd.size(1) != s.size(1)) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
    }
    if (sdd.size(1) != s.size(1)) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
    }
    b_s.set_size(&pb_emlrtRTEI, sp, 3, s.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_s[3 * i1] = s[i1];
    }
    loop_ub = sd.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_s[3 * i1 + 1] = sd[i1];
    }
    loop_ub = sdd.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_s[3 * i1 + 2] = sdd[i1];
    }
    st.site = &j_emlrtRSI;
    coder::rottraj(st, R0, Rf, timeInterval, trajTimes_rot, b_s, R, omega,
                   alpha);
    //  Calculate start and end indices for the full trajectory
    c_y = muDoubleScalarRound(waypointTimes[w] / ts);
    a = muDoubleScalarRound(b_tmp / ts);
    //  Insert data
    if (c_y + 1.0 > a + 1.0) {
      i1 = 0;
      i2 = 0;
    } else {
      if (c_y + 1.0 != static_cast<int32_T>(c_y + 1.0)) {
        emlrtIntegerCheckR2012b(c_y + 1.0, &emlrtDCI, (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(c_y + 1.0) < 1) ||
          (static_cast<int32_T>(c_y + 1.0) > desired_quaternions.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c_y + 1.0), 1,
                                      desired_quaternions.size(1), &f_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i1 = static_cast<int32_T>(c_y + 1.0) - 1;
      if (a + 1.0 != static_cast<int32_T>(a + 1.0)) {
        emlrtIntegerCheckR2012b(a + 1.0, &b_emlrtDCI, (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(a + 1.0) < 1) ||
          (static_cast<int32_T>(a + 1.0) > desired_quaternions.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a + 1.0), 1,
                                      desired_quaternions.size(1), &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i2 = static_cast<int32_T>(a + 1.0);
    }
    st.site = &k_emlrtRSI;
    R.compact(st, r);
    r1.set_size(&qb_emlrtRTEI, sp, 4, r.size(0));
    loop_ub = r.size(0);
    for (trajTimes_size_tmp = 0; trajTimes_size_tmp < loop_ub;
         trajTimes_size_tmp++) {
      r1[4 * trajTimes_size_tmp] = r[trajTimes_size_tmp];
      r1[4 * trajTimes_size_tmp + 1] = r[trajTimes_size_tmp + r.size(0)];
      r1[4 * trajTimes_size_tmp + 2] = r[trajTimes_size_tmp + r.size(0) * 2];
      r1[4 * trajTimes_size_tmp + 3] = r[trajTimes_size_tmp + r.size(0) * 3];
    }
    trajTimes_size[0] = 4;
    trajTimes_size_tmp = i2 - i1;
    trajTimes_size[1] = trajTimes_size_tmp;
    emlrtSubAssignSizeCheckR2012b(&trajTimes_size[0], 2, r1.size(), 2,
                                  &emlrtECI, (emlrtCTX)sp);
    for (i2 = 0; i2 < trajTimes_size_tmp; i2++) {
      loop_ub = i1 + i2;
      desired_quaternions[4 * loop_ub] = r1[4 * i2];
      desired_quaternions[4 * loop_ub + 1] = r1[4 * i2 + 1];
      desired_quaternions[4 * loop_ub + 2] = r1[4 * i2 + 2];
      desired_quaternions[4 * loop_ub + 3] = r1[4 * i2 + 3];
    }
    if (c_y + 1.0 > a + 1.0) {
      i1 = 0;
      i2 = 0;
    } else {
      if (c_y + 1.0 != static_cast<int32_T>(c_y + 1.0)) {
        emlrtIntegerCheckR2012b(c_y + 1.0, &c_emlrtDCI, (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(c_y + 1.0) < 1) ||
          (static_cast<int32_T>(c_y + 1.0) >
           desired_angular_velocity.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c_y + 1.0), 1,
                                      desired_angular_velocity.size(1),
                                      &h_emlrtBCI, (emlrtConstCTX)sp);
      }
      i1 = static_cast<int32_T>(c_y + 1.0) - 1;
      if (a + 1.0 != static_cast<int32_T>(a + 1.0)) {
        emlrtIntegerCheckR2012b(a + 1.0, &d_emlrtDCI, (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(a + 1.0) < 1) ||
          (static_cast<int32_T>(a + 1.0) > desired_angular_velocity.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a + 1.0), 1,
                                      desired_angular_velocity.size(1),
                                      &i_emlrtBCI, (emlrtConstCTX)sp);
      }
      i2 = static_cast<int32_T>(a + 1.0);
    }
    trajTimes_size[0] = 3;
    trajTimes_size_tmp = i2 - i1;
    trajTimes_size[1] = trajTimes_size_tmp;
    emlrtSubAssignSizeCheckR2012b(&trajTimes_size[0], 2, omega.size(), 2,
                                  &b_emlrtECI, (emlrtCTX)sp);
    for (i2 = 0; i2 < trajTimes_size_tmp; i2++) {
      loop_ub = i1 + i2;
      desired_angular_velocity[3 * loop_ub] = omega[3 * i2];
      desired_angular_velocity[3 * loop_ub + 1] = omega[3 * i2 + 1];
      desired_angular_velocity[3 * loop_ub + 2] = omega[3 * i2 + 2];
    }
    if (c_y + 1.0 > a + 1.0) {
      i1 = 0;
      i2 = 0;
    } else {
      if (c_y + 1.0 != static_cast<int32_T>(c_y + 1.0)) {
        emlrtIntegerCheckR2012b(c_y + 1.0, &e_emlrtDCI, (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(c_y + 1.0) < 1) ||
          (static_cast<int32_T>(c_y + 1.0) > desired_angular_accel.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(c_y + 1.0), 1,
                                      desired_angular_accel.size(1),
                                      &j_emlrtBCI, (emlrtConstCTX)sp);
      }
      i1 = static_cast<int32_T>(c_y + 1.0) - 1;
      if (a + 1.0 != static_cast<int32_T>(a + 1.0)) {
        emlrtIntegerCheckR2012b(a + 1.0, &f_emlrtDCI, (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(a + 1.0) < 1) ||
          (static_cast<int32_T>(a + 1.0) > desired_angular_accel.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a + 1.0), 1,
                                      desired_angular_accel.size(1),
                                      &k_emlrtBCI, (emlrtConstCTX)sp);
      }
      i2 = static_cast<int32_T>(a + 1.0);
    }
    trajTimes_size[0] = 3;
    trajTimes_size_tmp = i2 - i1;
    trajTimes_size[1] = trajTimes_size_tmp;
    emlrtSubAssignSizeCheckR2012b(&trajTimes_size[0], 2, alpha.size(), 2,
                                  &c_emlrtECI, (emlrtCTX)sp);
    for (i2 = 0; i2 < trajTimes_size_tmp; i2++) {
      loop_ub = i1 + i2;
      desired_angular_accel[3 * loop_ub] = alpha[3 * i2];
      desired_angular_accel[3 * loop_ub + 1] = alpha[3 * i2 + 1];
      desired_angular_accel[3 * loop_ub + 2] = alpha[3 * i2 + 2];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

} // namespace trajectoryGeneration

// End of code generation (orientationTrajectory.cpp)
