//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified_types.h
//
// Code generation for function 'inverseKinematicsOAModified'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T {
  boolean_T useObjectiveNormInfinity;
  real_T weightNormInfinity;
  boolean_T useObjectiveNormL2;
  real_T weightNormL2;
  boolean_T useObjectiveTrajectoryFollowing;
  real_T weightTrajectoryFollowing;
  boolean_T useObjectiveJointAcceleration;
  real_T weightJointAcceleration;
  boolean_T useObjectiveManipulability;
  real_T weightManipulability;
  boolean_T applyEqualityConstraints;
  boolean_T applyInequalityConstraints;
  boolean_T applySlack;
  real_T Slacklowerbound[6];
  real_T Slackupperbound[6];
  real_T SlackPenaltyWeight[6];
  real_T SlackObjectiveWeight;
  boolean_T obstacleAvoidanceScheme;
  real_T k;
  real_T gamma;
  boolean_T dynamicSlack;
  boolean_T applyVelocityDamper;
  real_T jointLimitActivationDistance;
  real_T jointLimitStopDistance;
  real_T jointLimitGain;
};

// End of code generation (inverseKinematicsOAModified_types.h)
