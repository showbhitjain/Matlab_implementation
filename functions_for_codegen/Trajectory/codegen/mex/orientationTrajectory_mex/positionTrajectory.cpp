//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// positionTrajectory.cpp
//
// Code generation for function 'positionTrajectory'
//

// Include files
#include "positionTrajectory.h"
#include "colon.h"
#include "cubicpolytraj.h"
#include "diff.h"
#include "orientationTrajectory_mex_data.h"
#include "orientationTrajectory_mex_mexutil.h"
#include "quinticpolytraj.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "trapveltraj.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo if_emlrtRSI{
    26,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtRSInfo jf_emlrtRSI{
    29,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtRSInfo kf_emlrtRSI{
    39,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtRSInfo lf_emlrtRSI{
    40,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtRSInfo mf_emlrtRSI{
    38,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtRSInfo nf_emlrtRSI{
    42,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtRSInfo of_emlrtRSI{
    45,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtRSInfo pf_emlrtRSI{
    49,                   // lineNo
    "positionTrajectory", // fcnName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pathName
};

static emlrtBCInfo nb_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    29,                   // lineNo
    36,                   // colNo
    "waypointTimes",      // aName
    "positionTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m", // pName
    0                          // checkKind
};

static emlrtRTEInfo uc_emlrtRTEI{
    19,                   // lineNo
    9,                    // colNo
    "positionTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pName
};

static emlrtRTEInfo vc_emlrtRTEI{
    22,                   // lineNo
    9,                    // colNo
    "positionTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pName
};

static emlrtRTEInfo wc_emlrtRTEI{
    29,                   // lineNo
    5,                    // colNo
    "positionTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pName
};

static emlrtRTEInfo
    xc_emlrtRTEI{
        76,                  // lineNo
        13,                  // colNo
        "eml_mtimes_helper", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

static emlrtRTEInfo yc_emlrtRTEI{
    42,                   // lineNo
    58,                   // colNo
    "positionTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pName
};

static emlrtRTEInfo ad_emlrtRTEI{
    45,                   // lineNo
    60,                   // colNo
    "positionTrajectory", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/Trajecto"
    "ry/positionTrajectory.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
void positionTrajectory(const emlrtStack *sp,
                        const ::coder::array<real_T, 2U> &waypoints,
                        const ::coder::array<real_T, 2U> &waypointTimes,
                        real_T ts, const ::coder::array<char_T, 2U> &trajType,
                        ::coder::array<real_T, 2U> &waypointVels,
                        ::coder::array<real_T, 2U> &waypointAccels,
                        ::coder::array<real_T, 2U> &xd,
                        ::coder::array<real_T, 2U> &xd_vel,
                        ::coder::array<real_T, 2U> &xdd)
{
  static const int32_T iv[2]{1, 69};
  static const char_T varargin_1[69]{
      'I', 'n',  'v', 'a', 'l',  'i', 'd',  ' ', 't', 'r',  'a', 'j', 'e',  'c',
      't', 'o',  'r', 'y', ' ',  't', 'y',  'p', 'e', '!',  ' ', 'U', 's',  'e',
      ' ', '\'', 't', 'r', 'a',  'p', '\'', ',', ' ', '\'', 'c', 'u', 'b',  'i',
      'c', '\'', ',', ' ', '\'', 'q', 'u',  'i', 'n', 't',  'i', 'c', '\'', ',',
      ' ', 'o',  'r', ' ', '\'', 'b', 's',  'p', 'l', 'i',  'n', 'e', '\''};
  static const char_T cv2[7]{'q', 'u', 'i', 'n', 't', 'i', 'c'};
  static const char_T cv1[5]{'c', 'u', 'b', 'i', 'c'};
  static const char_T cv[4]{'t', 'r', 'a', 'p'};
  ::coder::array<real_T, 2U> b;
  ::coder::array<real_T, 2U> b_waypointTimes;
  ::coder::array<real_T, 2U> r1;
  ::coder::array<real_T, 2U> r2;
  ::coder::array<real_T, 2U> trajTimes;
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *m;
  const mxArray *y;
  int32_T exitg1;
  int32_T loop_ub;
  boolean_T guard1;
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 1, 0);
  // trajectory interpolation between waypoints
  //  INPUTS:
  //  waypoints: size = (3xn), row order x;y;z
  //  waypointTimes : timepoints at waypoints
  //  ts : sample time
  //  trajType : type of interpolation trajectory 'trap' , 'cubic' or 'quintic'
  //  possible values waypointVels: optional input (only for 'cubic' or
  //  'quintic') with default value to be chosen as same in the code
  //  waypointAccels: optional input (only for 'quintic' ) with default value to
  //  be chosen as same in the code
  // OUTPUTS: [xd,xd_vel,xdd]
  // xd: desired cartesian order x;y;z (3xn) positions between waypoints
  //  xd_vel: desired cartesian velocity (3xn)
  //  xdd : desired cartesian accelration (3xn)
  //  Validate input arguments
  covrtLogCond(&emlrtCoverageInstance, 1, 0, 0, false);
  if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 1,
                   waypointVels.size(1) == 0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 0);
    waypointVels.set_size(&uc_emlrtRTEI, sp, 3, waypoints.size(1));
    loop_ub = 3 * waypoints.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      waypointVels[i] = 0.0;
    }
    //  Default velocities
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 0, false);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 0, false);
  }
  covrtLogCond(&emlrtCoverageInstance, 1, 0, 2, false);
  if (covrtLogCond(&emlrtCoverageInstance, 1, 0, 3,
                   waypointAccels.size(1) == 0)) {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 1, true);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 1, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 1);
    waypointAccels.set_size(&vc_emlrtRTEI, sp, 3, waypointVels.size(1));
    loop_ub = 3 * waypointVels.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      waypointAccels[i] = 0.0;
    }
    //  Default accelerations
  } else {
    covrtLogMcdc(&emlrtCoverageInstance, 1, 0, 1, false);
    covrtLogIf(&emlrtCoverageInstance, 1, 0, 1, false);
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 1, 2);
  //  Calculate acceleration times if applicable
  st.site = &if_emlrtRSI;
  coder::diff(st, waypointTimes, b);
  //  Define trajectory sample times
  st.site = &jf_emlrtRSI;
  if (waypointTimes.size(1) < 1) {
    emlrtDynamicBoundsCheckR2012b(waypointTimes.size(1), 1,
                                  waypointTimes.size(1), &nb_emlrtBCI, &st);
  }
  guard1 = false;
  if (muDoubleScalarIsNaN(ts)) {
    guard1 = true;
  } else {
    real_T d;
    d = waypointTimes[waypointTimes.size(1) - 1];
    if (muDoubleScalarIsNaN(d)) {
      guard1 = true;
    } else if ((ts == 0.0) || ((d > 0.0) && (ts < 0.0)) ||
               ((d < 0.0) && (ts > 0.0))) {
      trajTimes.set_size(&wc_emlrtRTEI, &st, 1, 0);
    } else if (muDoubleScalarIsInf(d) && muDoubleScalarIsInf(ts)) {
      trajTimes.set_size(&wc_emlrtRTEI, &st, 1, 1);
      trajTimes[0] = rtNaN;
    } else if (muDoubleScalarIsInf(ts)) {
      trajTimes.set_size(&wc_emlrtRTEI, &st, 1, 1);
      trajTimes[0] = 0.0;
    } else if (muDoubleScalarFloor(ts) == ts) {
      loop_ub = static_cast<int32_T>(d / ts);
      trajTimes.set_size(&wc_emlrtRTEI, &st, 1, loop_ub + 1);
      for (int32_T i{0}; i <= loop_ub; i++) {
        trajTimes[i] = ts * static_cast<real_T>(i);
      }
    } else {
      b_st.site = &l_emlrtRSI;
      coder::eml_float_colon(b_st, ts, d, trajTimes);
    }
  }
  if (guard1) {
    trajTimes.set_size(&wc_emlrtRTEI, &st, 1, 1);
    trajTimes[0] = rtNaN;
  }
  //  Switch between trajectory types and generate the desired trajectory
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
  case 0: {
    int32_T scalarLB;
    int32_T vectorUB;
    covrtLogSwitch(&emlrtCoverageInstance, 1, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 3);
    b_waypointTimes.set_size(&xc_emlrtRTEI, sp, 1, b.size(1));
    loop_ub = b.size(1);
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T i{0}; i <= vectorUB; i += 2) {
      __m128d r;
      r = _mm_loadu_pd(&b[i]);
      _mm_storeu_pd(&b_waypointTimes[i], _mm_mul_pd(_mm_set1_pd(0.25), r));
    }
    for (int32_T i{scalarLB}; i < loop_ub; i++) {
      b_waypointTimes[i] = 0.25 * b[i];
    }
    st.site = &kf_emlrtRSI;
    coder::repmat(st, b_waypointTimes, r1);
    st.site = &lf_emlrtRSI;
    coder::diff(st, waypointTimes, b);
    st.site = &lf_emlrtRSI;
    coder::repmat(st, b, r2);
    st.site = &mf_emlrtRSI;
    coder::trapveltraj(st, waypoints, static_cast<real_T>(trajTimes.size(1)),
                       r1, r2, xd, xd_vel, xdd);
  } break;
  case 1:
    covrtLogSwitch(&emlrtCoverageInstance, 1, 0, 0, 2);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 4);
    b_waypointTimes.set_size(&yc_emlrtRTEI, sp, 1, waypointTimes.size(1));
    loop_ub = waypointTimes.size(0) * waypointTimes.size(1) - 1;
    for (int32_T i{0}; i <= loop_ub; i++) {
      b_waypointTimes[i] = waypointTimes[i];
    }
    st.site = &nf_emlrtRSI;
    coder::cubicpolytraj(st, waypoints, b_waypointTimes, trajTimes,
                         waypointVels, xd, xd_vel, xdd);
    break;
  case 2:
    covrtLogSwitch(&emlrtCoverageInstance, 1, 0, 0, 3);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 5);
    b_waypointTimes.set_size(&ad_emlrtRTEI, sp, 1, waypointTimes.size(1));
    loop_ub = waypointTimes.size(0) * waypointTimes.size(1) - 1;
    for (int32_T i{0}; i <= loop_ub; i++) {
      b_waypointTimes[i] = waypointTimes[i];
    }
    st.site = &of_emlrtRSI;
    coder::quinticpolytraj(st, waypoints, b_waypointTimes, trajTimes,
                           waypointVels, waypointAccels, xd, xd_vel, xdd);
    break;
  default:
    covrtLogSwitch(&emlrtCoverageInstance, 1, 0, 0, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1, 6);
    st.site = &pf_emlrtRSI;
    y = nullptr;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&st, 69, m, &varargin_1[0]);
    emlrtAssign(&y, m);
    b_st.site = &uh_emlrtRSI;
    b_error(b_st, y, emlrtMCI);
    break;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

} // namespace trajectoryGeneration

// End of code generation (positionTrajectory.cpp)
