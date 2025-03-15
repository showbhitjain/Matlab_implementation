//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Jacobi_final_link.cpp
//
// Code generation for function 'Jacobi_final_link'
//

// Include files
#include "Jacobi_final_link.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtBCInfo r_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    8,                   // lineNo
    16,                  // colNo
    "in1",               // aName
    "Jacobi_final_link", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/Jacobi_final_link.m", // pName
    0                          // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    9,                   // lineNo
    16,                  // colNo
    "in1",               // aName
    "Jacobi_final_link", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/Jacobi_final_link.m", // pName
    0                          // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    10,                  // lineNo
    16,                  // colNo
    "in1",               // aName
    "Jacobi_final_link", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/Jacobi_final_link.m", // pName
    0                          // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    11,                  // lineNo
    16,                  // colNo
    "in1",               // aName
    "Jacobi_final_link", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/Jacobi_final_link.m", // pName
    0                          // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    12,                  // lineNo
    16,                  // colNo
    "in1",               // aName
    "Jacobi_final_link", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/Jacobi_final_link.m", // pName
    0                          // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    13,                  // lineNo
    16,                  // colNo
    "in1",               // aName
    "Jacobi_final_link", // fName
    "/home/shobhit/ShobhitRobotModelling/robotmodelling/Matlab_implementation/"
    "functions_for_codegen/obstacleAvoidanceOptmisationModif"
    "ied/Jacobi_final_link.m", // pName
    0                          // checkKind
};

// Function Definitions
void Jacobi_final_link(const emlrtStack &sp, const real_T in1_data[],
                       const int32_T in1_size[2], real_T J[42])
{
  real_T et41;
  real_T et43;
  real_T t10;
  real_T t102;
  real_T t103;
  real_T t104;
  real_T t106;
  real_T t107;
  real_T t109_tmp;
  real_T t11;
  real_T t113;
  real_T t114;
  real_T t115;
  real_T t119;
  real_T t12;
  real_T t120;
  real_T t13;
  real_T t14;
  real_T t148;
  real_T t149;
  real_T t15;
  real_T t157;
  real_T t158;
  real_T t159;
  real_T t16;
  real_T t160;
  real_T t162;
  real_T t166;
  real_T t17;
  real_T t171;
  real_T t172;
  real_T t18;
  real_T t187;
  real_T t188;
  real_T t19;
  real_T t192;
  real_T t199;
  real_T t2;
  real_T t20;
  real_T t202;
  real_T t202_tmp;
  real_T t203;
  real_T t204;
  real_T t204_tmp;
  real_T t207;
  real_T t21;
  real_T t213;
  real_T t214;
  real_T t215;
  real_T t22;
  real_T t222;
  real_T t23;
  real_T t235;
  real_T t237;
  real_T t237_tmp;
  real_T t238;
  real_T t238_tmp;
  real_T t239;
  real_T t242;
  real_T t244;
  real_T t245;
  real_T t248;
  real_T t249;
  real_T t254;
  real_T t255;
  real_T t255_tmp;
  real_T t257;
  real_T t257_tmp;
  real_T t258;
  real_T t259_tmp;
  real_T t261;
  real_T t264;
  real_T t266;
  real_T t267;
  real_T t269;
  real_T t27;
  real_T t271;
  real_T t274_tmp;
  real_T t276;
  real_T t277;
  real_T t283;
  real_T t285;
  real_T t287_tmp;
  real_T t291;
  real_T t292;
  real_T t297;
  real_T t299;
  real_T t299_tmp;
  real_T t3;
  real_T t301;
  real_T t302;
  real_T t303_tmp_tmp;
  real_T t308_tmp;
  real_T t311_tmp;
  real_T t312;
  real_T t313;
  real_T t314;
  real_T t314_tmp;
  real_T t315;
  real_T t315_tmp;
  real_T t317;
  real_T t317_tmp;
  real_T t318;
  real_T t318_tmp;
  real_T t328;
  real_T t328_tmp;
  real_T t329;
  real_T t329_tmp;
  real_T t333;
  real_T t335;
  real_T t36;
  real_T t4;
  real_T t43;
  real_T t5;
  real_T t54;
  real_T t57;
  real_T t58;
  real_T t59;
  real_T t6;
  real_T t60;
  real_T t61;
  real_T t62;
  real_T t63;
  real_T t64;
  real_T t67;
  real_T t7;
  real_T t70;
  real_T t71;
  real_T t8;
  real_T t87;
  real_T t88;
  real_T t94;
  real_T t95_tmp;
  real_T t96;
  real_T theta1;
  real_T theta2;
  real_T theta3;
  real_T theta4;
  real_T theta5;
  real_T theta6;
  covrtLogFcn(&emlrtCoverageInstance, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 4, 0);
  // Jacobi_final_link
  //     J = Jacobi_final_link(IN1)
  //     This function was generated by the Symbolic Math Toolbox version 23.2.
  //     08-Nov-2024 19:20:44
  if (in1_size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, in1_size[1], &r_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  theta1 = in1_data[0];
  if (in1_size[1] < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &s_emlrtBCI, (emlrtConstCTX)&sp);
  }
  theta2 = in1_data[1];
  if (in1_size[1] < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &t_emlrtBCI, (emlrtConstCTX)&sp);
  }
  theta3 = in1_data[2];
  if (in1_size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, 3, &u_emlrtBCI, (emlrtConstCTX)&sp);
  }
  theta4 = in1_data[3];
  if (in1_size[1] < 5) {
    emlrtDynamicBoundsCheckR2012b(5, 1, 4, &v_emlrtBCI, (emlrtConstCTX)&sp);
  }
  theta5 = in1_data[4];
  if (in1_size[1] < 6) {
    emlrtDynamicBoundsCheckR2012b(6, 1, 5, &w_emlrtBCI, (emlrtConstCTX)&sp);
  }
  theta6 = in1_data[5];
  t2 = muDoubleScalarCos(theta1);
  t3 = muDoubleScalarCos(theta2);
  t4 = muDoubleScalarCos(theta3);
  t5 = muDoubleScalarCos(theta4);
  t6 = muDoubleScalarCos(theta5);
  t7 = muDoubleScalarCos(theta6);
  t8 = muDoubleScalarSin(theta1);
  theta1 = muDoubleScalarSin(theta2);
  t10 = muDoubleScalarSin(theta3);
  t11 = muDoubleScalarSin(theta4);
  t12 = muDoubleScalarSin(theta5);
  t13 = muDoubleScalarSin(theta6);
  t14 = t2 * t3;
  t15 = t2 * t4;
  t16 = t2 * theta1;
  t17 = t3 * t8;
  t18 = t2 * t10;
  t19 = t4 * t8;
  t20 = t4 * theta1;
  t21 = t8 * theta1;
  t22 = t8 * t10;
  t23 = theta1 * t10;
  theta1 = t3 * 6.123233995736766E-17;
  theta5 = t4 * 6.123233995736766E-17;
  t36 = t10 * 6.123233995736766E-17;
  t54 = t10 * 5.0516680464828323E-18;
  t70 = t3 * 3.749399456654644E-33;
  t71 = t4 * 3.749399456654644E-33;
  t119 = t3 * 2.2958450216584679E-49;
  t120 = t4 * 2.2958450216584679E-49;
  t171 = t3 * 1.504205602555149E-66;
  t172 = t4 * 1.504205602555149E-66;
  t187 = t3 * 1.439769391355383E-33;
  t188 = t4 * 1.439769391355383E-33;
  t239 = t2 * 1.9349419426528181E-17;
  t27 = t18 * 0.0825;
  theta2 = t14 * 6.123233995736766E-17;
  t43 = t16 * 6.123233995736766E-17;
  theta4 = t21 * 6.123233995736766E-17;
  t87 = t5 * (t3 + 3.749399456654644E-33);
  t88 = t11 * (t3 + 3.749399456654644E-33);
  t95_tmp = t3 * t4;
  theta6 = (t23 + theta5) + t95_tmp * -6.123233995736766E-17;
  t148 = t15 * 2.3513218543629179E-17;
  t149 = t19 * 2.3513218543629179E-17;
  t192 = t4 * t187;
  t222 = t21 * 0.316;
  t242 = t14 * 1.9349419426528181E-17;
  t57 = t16 + t17 * 6.123233995736766E-17;
  t58 = t17 + t43;
  t60 = -t21 + theta2;
  theta3 = (t20 - t36) + t10 * theta1;
  t199 = t87 * 0.384;
  t238_tmp = t5 * theta6;
  t238 = t238_tmp * 2.3513218543629179E-17;
  t244 = (((-t23 + theta1) - theta5) + t4 * theta1) + 2.2958450216584679E-49;
  t59 = t14 - theta4;
  t61 = t4 * t58;
  t62 = t10 * t58;
  t94 = (t21 + t2 * 6.123233995736766E-17) - theta2;
  t96 = -(t8 * 6.123233995736766E-17) + t57;
  theta2 = t5 * theta3;
  t107 = t11 * theta3;
  t109_tmp = t10 * t57;
  t235 = t57 * t188;
  t237_tmp = t4 * t60;
  t237 = t237_tmp * -1.439769391355383E-33;
  t245 = t6 * t244;
  t63 = t4 * t59;
  t64 = t10 * t59;
  t67 = t61 * 0.0825;
  t102 = t5 * t94;
  t103 = t5 * t96;
  t104 = t11 * t94;
  t106 = t11 * t96;
  t114 = theta2 * 0.0825;
  theta1 = (t18 + t61) + t36 * t60;
  t203 = t62 * 2.3513218543629179E-17;
  t215 = t107 * 0.384;
  t254 = t245 * 6.55186037543834E-18;
  t258 = (t87 + t107) + t238_tmp * 6.123233995736766E-17;
  t269 = ((((-t15 + theta4) + t62) + t2 * 3.749399456654644E-33) -
          t14 * 3.749399456654644E-33) +
         t237_tmp * -6.123233995736766E-17;
  t113 = t104 * 0.0825;
  t115 = t106 * 0.0825;
  theta4 = (t19 + t64) + theta5 * t57;
  theta3 = (t15 - t62) + theta5 * t60;
  t157 = t5 * theta1;
  t158 = t11 * theta1;
  t207 = t64 * 2.3513218543629179E-17;
  t213 = t102 * 0.384;
  t214 = t103 * 0.384;
  t259_tmp = t11 * theta6;
  theta2 = (t88 - theta2) + t259_tmp * 6.123233995736766E-17;
  t271 = t6 * t269;
  t274_tmp = t6 * t258;
  t335 = t274_tmp * 4.011857418620469E-34;
  t301 = ((((-(t23 * 6.123233995736766E-17) + t70) - t71) + t4 * t70) + t258) +
         1.405799628556214E-65;
  theta1 = (t22 - t63) + t36 * t57;
  t162 = t157 * 0.0825;
  t202_tmp = t11 * theta4;
  t202 = t202_tmp * 5.0516680464828323E-18;
  t204_tmp = t11 * theta3;
  t204 = t204_tmp * 5.0516680464828323E-18;
  t248 = t158 * 0.384;
  t255_tmp = t5 * theta4;
  t255 = t255_tmp * 2.3513218543629179E-17;
  t257_tmp = t5 * theta3;
  t257 = t257_tmp * 2.3513218543629179E-17;
  t261 = t12 * theta2;
  t264 = ((t43 - t8 * 3.749399456654644E-33) + t17 * 3.749399456654644E-33) +
         theta4;
  t277 = t271 * 6.55186037543834E-18;
  t302 = t13 * t301 * 0.088;
  t303_tmp_tmp = t7 * t301;
  t333 = t303_tmp_tmp * 0.107;
  t159 = t5 * theta1;
  t160 = t11 * theta1;
  t266 = t261 * 6.55186037543834E-18;
  t267 = t6 * t264;
  theta4 = (t104 + t157) + t204_tmp * 6.123233995736766E-17;
  theta5 = (t102 - t158) + t257_tmp * 6.123233995736766E-17;
  theta3 = (t245 + t261) - t274_tmp * 6.123233995736766E-17;
  theta1 = (-(t12 * t244) + t6 * theta2) + t12 * t258 * 6.123233995736766E-17;
  t166 = t159 * 0.0825;
  t249 = t160 * 0.384;
  t276 = t267 * 6.55186037543834E-18;
  t258 = (t103 + t160) - t255_tmp * 6.123233995736766E-17;
  t5 = (-t106 + t159) + t202_tmp * 6.123233995736766E-17;
  t283 = t12 * theta4;
  t299_tmp = t6 * theta5;
  t299 = t299_tmp * 4.011857418620469E-34;
  t11 = t7 * theta1 * 0.088;
  t308_tmp = t13 * theta1;
  theta6 = t308_tmp * 0.107;
  t70 = t13 * theta3 * 5.3884459162483537E-18;
  t311_tmp = t7 * theta3;
  t43 = t311_tmp * 6.55186037543834E-18;
  t313 = (((((-(t15 * 6.123233995736766E-17) + t21 * 3.749399456654644E-33) +
             t36 * t58) +
            t2 * 2.2958450216584679E-49) -
           t14 * 2.2958450216584679E-49) +
          t237_tmp * -3.749399456654644E-33) +
         theta5;
  et41 = ((((((-(t23 * 3.749399456654644E-33) + t119) - t120) + t4 * t119) +
            t87 * 6.123233995736766E-17) +
           t107 * 6.123233995736766E-17) +
          t238_tmp * 3.749399456654644E-33) +
         theta3;
  t285 = t12 * t5;
  t287_tmp = t6 * t258;
  t58 = t287_tmp * 6.123233995736766E-17;
  t291 = t283 * 6.55186037543834E-18;
  t297 = t287_tmp * 4.011857418620469E-34;
  t312 = (((((t19 * 6.123233995736766E-17 + t16 * 3.749399456654644E-33) +
             t36 * t59) -
            t8 * 2.2958450216584679E-49) +
           t17 * 2.2958450216584679E-49) +
          t57 * t71) +
         t258;
  t317_tmp = t13 * t313;
  t317 = t317_tmp * 0.088;
  t318_tmp = t7 * t313;
  t318 = t318_tmp * 0.107;
  theta1 = (-(t12 * t269) + t6 * theta4) + t12 * theta5 * 6.123233995736766E-17;
  t292 = t285 * 6.55186037543834E-18;
  t314_tmp = t13 * t312;
  t314 = t314_tmp * 0.088;
  t315_tmp = t7 * t312;
  t315 = t315_tmp * 0.107;
  theta2 = (-t267 + t285) + t58;
  theta4 = (t271 + t283) - t299_tmp * 6.123233995736766E-17;
  t328_tmp = t7 * theta1;
  t328 = t328_tmp * 0.088;
  t329_tmp = t13 * theta1;
  t329 = t329_tmp * 0.107;
  et43 =
      ((((((((((((((-(t23 * 2.45655417317456E-50) + t171) - t172) + t4 * t171) +
                 t87 * 4.011857418620469E-34) +
                t107 * 4.011857418620469E-34) +
               t238_tmp * 2.45655417317456E-50) +
              t254) +
             t266) -
            t335) +
           t302) -
          t333) +
         t11) +
        theta6) -
       t70) +
      t43;
  theta1 = t259_tmp * 5.0516680464828323E-18;
  t187 = (((((((((((((((((-(t88 * 0.0825) + t114) - theta1) -
                        t23 * 2.3513218543629179E-17) +
                       t187) -
                      t188) +
                     t192) +
                    t199) +
                   t215) +
                  t238) +
                 t254) +
                t266) -
               t335) +
              t302) -
             t333) +
            t11) +
           theta6) -
          t70) +
         t43;
  theta3 = (-(t20 * 0.0825) + t54) + t3 * t10 * -5.0516680464828323E-18;
  t114 = (((((((((((((((((((theta3 - t88 * 0.0825) + t114) - theta1) -
                         t23 * 2.3513218543629179E-17) -
                        t188) +
                       t192) +
                      t199) +
                     t215) +
                    t3 * 0.316) +
                   t238) +
                  t254) +
                 t266) -
                t335) +
               t302) -
              t333) +
             t11) +
            theta6) -
           t70) +
          t43) +
         1.184810228302868E-33;
  theta1 = (t12 * t264 + t6 * t5) - t12 * t258 * 6.123233995736766E-17;
  t171 = t13 * theta2;
  t36 = t171 * 5.3884459162483537E-18;
  t266 = t7 * theta2;
  t119 = t266 * 6.55186037543834E-18;
  t302 = t13 * theta4;
  t333 = t302 * 5.3884459162483537E-18;
  t259_tmp = t7 * theta4;
  t335 = t259_tmp * 6.55186037543834E-18;
  t71 = ((((((((((t19 * 3.749399456654644E-33 + t16 * 2.2958450216584679E-49) +
                 t64 * 3.749399456654644E-33) +
                t103 * 6.123233995736766E-17) -
               t8 * 1.405799628556214E-65) +
              t17 * 1.405799628556214E-65) +
             t57 * t120) +
            t160 * 6.123233995736766E-17) -
           t255_tmp * 3.749399456654644E-33) +
          t267) -
         t285) -
        t58;
  t59 = ((((((((-(t15 * 3.749399456654644E-33) + t21 * 2.2958450216584679E-49) +
               t62 * 3.749399456654644E-33) +
              t102 * 6.123233995736766E-17) +
             t2 * 1.405799628556214E-65) -
            t14 * 1.405799628556214E-65) +
           t237_tmp * -2.2958450216584679E-49) -
          t158 * 6.123233995736766E-17) +
         t257_tmp * 3.749399456654644E-33) +
        theta4;
  t58 = theta3 + (t187 + 5.3982705736558617E-66);
  t5 = t7 * theta1;
  theta3 = t5 * 0.088;
  t43 = t13 * theta1;
  theta2 = t43 * 0.107;
  t11 = ((((((((((((((((-(t15 * 2.45655417317456E-50) +
                        t21 * 1.504205602555149E-66) +
                       t62 * 2.45655417317456E-50) +
                      t102 * 4.011857418620469E-34) +
                     t2 * 9.2106028821433953E-83) -
                    t14 * 9.2106028821433953E-83) +
                   t237_tmp * -1.504205602555149E-66) -
                  t158 * 4.011857418620469E-34) +
                 t257_tmp * 2.45655417317456E-50) +
                t277) +
               t291) -
              t299) +
             t317) -
            t318) +
           t328) +
          t329) -
         t333) +
        t335;
  t258 =
      (((((((((((((((((((-t113 - t148) - t162) + t21 * 1.439769391355383E-33) +
                      t203) -
                     t204) +
                    t213) +
                   t2 * 8.8160448831685167E-50) -
                  t14 * 8.8160448831685167E-50) +
                 t237) -
                t248) +
               t257) +
              t277) +
             t291) -
            t299) +
           t317) -
          t318) +
         t328) +
        t329) -
       t333) +
      t335;
  theta6 = ((((((((((((((((t19 * 2.45655417317456E-50 +
                           t16 * 1.504205602555149E-66) +
                          t64 * 2.45655417317456E-50) +
                         t103 * 4.011857418620469E-34) -
                        t8 * 9.2106028821433953E-83) +
                       t17 * 9.2106028821433953E-83) +
                      t57 * t172) +
                     t160 * 4.011857418620469E-34) -
                    t255_tmp * 2.45655417317456E-50) +
                   t276) -
                  t292) -
                 t297) +
                t314) -
               t315) -
              theta3) -
             theta2) +
            t36) -
           t119;
  t70 =
      (((((((((((((((((((-t115 + t149) + t166) + t16 * 1.439769391355383E-33) +
                      t202) +
                     t207) +
                    t214) -
                   t8 * 8.8160448831685167E-50) +
                  t17 * 8.8160448831685167E-50) +
                 t235) +
                t249) -
               t255) +
              t276) -
             t292) -
            t297) +
           t314) -
          t315) -
         theta3) -
        theta2) +
       t36) -
      t119;
  theta4 = (t27 + t67) + t54 * t60;
  theta5 = theta4 + t258;
  theta1 =
      (-(t22 * 0.0825) + t63 * 0.0825) + t109_tmp * -5.0516680464828323E-18;
  theta3 = ((((((((((((((((((((theta1 - t115) + t149) + t166) + t202) + t207) +
                          t214) +
                         t16 * 0.316) +
                        t235) -
                       t8 * 1.9349419426528181E-17) +
                      t17 * 1.9349419426528181E-17) +
                     t249) -
                    t255) +
                   t276) -
                  t292) -
                 t297) +
                t314) -
               t315) -
              theta3) -
             theta2) +
            t36) -
           t119;
  theta2 = theta1 + t70;
  theta1 = t10 * t60;
  J[0] = ((((((((((((((((((((((-t27 - t67) + t113) + t148) + t162) - t203) +
                          t204) -
                         t213) -
                        t222) +
                       t60 * t188) -
                      t239) +
                     t242) +
                    t248) -
                   t257) -
                  t277) -
                 t291) +
                t299) -
               t317) +
              t318) -
             t328) -
            t329) +
           t333) -
          t335) -
         theta1 * 5.0516680464828323E-18;
  J[1] = theta3;
  J[2] = 0.0;
  J[3] = 0.0;
  J[4] = 0.0;
  J[5] = 1.0;
  J[6] =
      ((((((((((((((((t2 * -1.184810228302868E-33 +
                      t14 * 1.184810228302868E-33) +
                     t15 * 1.439769391355383E-33) -
                    t18 * 5.0516680464828323E-18) +
                   t21 * -1.9349419426528181E-17) -
                  t61 * 5.0516680464828323E-18) +
                 t62 * -1.439769391355383E-33) +
                t102 * -2.3513218543629179E-17) +
               (t104 * 5.0516680464828323E-18 +
                t157 * 5.0516680464828323E-18)) +
              t158 * 2.3513218543629179E-17) +
             t271 * -4.011857418620469E-34) +
            (t283 * -4.011857418620469E-34 +
             t237_tmp * 8.8160448831685167E-50)) +
           (theta1 * -3.0932545517400808E-34 +
            t257_tmp * -1.439769391355383E-33)) +
          t204_tmp * 3.0932545517400808E-34) +
         t299_tmp * 2.45655417317456E-50) +
        (t318_tmp * 6.55186037543834E-18 - t317_tmp * 5.3884459162483537E-18)) +
       (t259_tmp * -4.011857418620469E-34 -
        t328_tmp * 5.3884459162483537E-18)) +
      ((t302 * 3.2994715218560868E-34 - t329_tmp * 6.55186037543834E-18) +
       t2 * t114);
  theta1 = t4 * t57;
  J[7] =
      ((((((((((((((((t8 * -1.184810228302868E-33 +
                      t16 * 1.9349419426528181E-17) +
                     t17 * 1.184810228302868E-33) +
                    t19 * 1.439769391355383E-33) -
                   t22 * 5.0516680464828323E-18) +
                  t63 * 5.0516680464828323E-18) +
                 t64 * 1.439769391355383E-33) +
                t103 * 2.3513218543629179E-17) +
               (t106 * -5.0516680464828323E-18 +
                t159 * 5.0516680464828323E-18)) +
              t160 * 2.3513218543629179E-17) +
             t267 * 4.011857418620469E-34) +
            (t285 * -4.011857418620469E-34 + theta1 * 8.8160448831685167E-50)) +
           (t109_tmp * -3.0932545517400808E-34 +
            t255_tmp * -1.439769391355383E-33)) +
          t202_tmp * 3.0932545517400808E-34) +
         t287_tmp * -2.45655417317456E-50) +
        ((t315_tmp * -6.55186037543834E-18 +
          t314_tmp * 5.3884459162483537E-18) -
         t5 * 5.3884459162483537E-18)) +
       (t266 * -4.011857418620469E-34 - t43 * 6.55186037543834E-18)) +
      (t171 * 3.2994715218560868E-34 + t8 * t114);
  J[8] =
      -t2 * theta3 -
      t8 * (((((((((((((((((((((theta4 - t113) - t148) - t162) + t203) - t204) +
                           t213) +
                          t222) +
                         t237) +
                        t239) -
                       t242) -
                      t248) +
                     t257) +
                    t277) +
                   t291) -
                  t299) +
                 t317) -
                t318) +
               t328) +
              t329) -
             t333) +
            t335);
  J[9] = -t8;
  J[10] = t2;
  J[11] = 6.123233995736766E-17;
  J[12] = -(t3 + 3.749399456654644E-33) * theta5 + t94 * t58;
  J[13] = (t3 + 3.749399456654644E-33) * theta2 - t96 * t58;
  J[14] = -t94 * theta2 + t96 * theta5;
  J[15] = t96;
  J[16] = t94;
  J[17] = t3 + 3.749399456654644E-33;
  J[18] = -t244 * t258 + t269 * (t187 + 5.3982705736558617E-66);
  J[19] = t244 * t70 - t264 * (t187 + 5.3982705736558617E-66);
  J[20] = t264 * t258 - t269 * t70;
  J[21] = t264;
  J[22] = t269;
  J[23] = t244;
  J[24] = -t301 * t11 + t313 * (et43 + 5.6398676689171484E-99);
  J[25] = t301 * theta6 - t312 * (et43 + 5.6398676689171484E-99);
  J[26] = t312 * t11 - t313 * theta6;
  J[27] = t312;
  J[28] = t313;
  J[29] = t301;
  J[30] = t59 * (et43 + 5.6398676689171484E-99) -
          (et41 + 8.6080400767695281E-82) * t11;
  J[31] = -t71 * (et43 + 5.6398676689171484E-99) +
          (et41 + 8.6080400767695281E-82) * theta6;
  J[32] = t71 * t11 - t59 * theta6;
  J[33] = t71;
  J[34] = t59;
  J[35] = et41 + 8.6080400767695281E-82;
  J[36] = 0.0;
  J[37] = 0.0;
  J[38] = 0.0;
  J[39] = ((((((((t8 * -8.6080400767695281E-82 + t16 * 1.405799628556214E-65) +
                 t17 * 8.6080400767695281E-82) +
                t19 * 2.2958450216584679E-49) +
               t64 * 2.2958450216584679E-49) +
              (t103 * 3.749399456654644E-33 + t160 * 3.749399456654644E-33)) +
             (t267 * 6.123233995736766E-17 - t285 * 6.123233995736766E-17)) +
            theta1 * 1.405799628556214E-65) +
           t255_tmp * -2.2958450216584679E-49) +
          (((t287_tmp * -3.749399456654644E-33 - t315_tmp) -
            t266 * 6.123233995736766E-17) -
           t43);
  J[40] =
      (((((((((t2 * 8.6080400767695281E-82 + t14 * -8.6080400767695281E-82) -
              t15 * 2.2958450216584679E-49) +
             t21 * 1.405799628556214E-65) +
            t62 * 2.2958450216584679E-49) +
           t102 * 3.749399456654644E-33) +
          (t158 * -3.749399456654644E-33 + t271 * 6.123233995736766E-17)) +
         t283 * 6.123233995736766E-17) +
        t237_tmp * -1.405799628556214E-65) +
       t257_tmp * 2.2958450216584679E-49) +
      (((t299_tmp * -3.749399456654644E-33 - t318_tmp) +
        t259_tmp * 6.123233995736766E-17) +
       t329_tmp);
  J[41] = (((((((t3 * 1.405799628556214E-65 + t4 * -1.405799628556214E-65) +
                t23 * -2.2958450216584679E-49) +
               (t87 * 3.749399456654644E-33 + t107 * 3.749399456654644E-33)) +
              (t245 * 6.123233995736766E-17 + t261 * 6.123233995736766E-17)) +
             t95_tmp * 1.405799628556214E-65) +
            t238_tmp * 2.2958450216584679E-49) +
           (((t274_tmp * -3.749399456654644E-33 - t303_tmp_tmp) +
             t311_tmp * 6.123233995736766E-17) +
            t308_tmp)) +
          5.27090436347397E-98;
}

// End of code generation (Jacobi_final_link.cpp)
