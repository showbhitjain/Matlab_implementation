//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematics_internal_types.h
//
// Code generation for function 'inverseKinematics'
//

#pragma once

// Include files
#include "anonymous_function.h"
#include "inverseKinematics_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "emlrt.h"

// Type Definitions
struct struct_T {
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
  boolean_T hasObjective;
};

struct b_struct_T {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
};

struct d_struct_T {
  int32_T ldq;
  coder::array<real_T, 2U> QR;
  coder::array<real_T, 2U> Q;
  coder::array<int32_T, 1U> jpvt;
  int32_T mrows;
  int32_T ncols;
  coder::array<real_T, 1U> tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

struct e_struct_T {
  coder::array<real_T, 2U> FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_;
  real_T workspace2_;
};

struct f_struct_T {
  coder::array<real_T, 1U> grad;
  coder::array<real_T, 1U> Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

struct g_struct_T {
  coder::array<real_T, 2U> workspace_double;
  coder::array<int32_T, 1U> workspace_int;
  coder::array<int32_T, 1U> workspace_sort;
};

struct h_struct_T {
  coder::array<real_T, 1U> FiniteDifferenceStepSize;
  int32_T MaxIterations;
  int32_T MaxFunctionEvaluations;
  coder::array<real_T, 1U> TypicalX;
  real_T ConstrRelTolFactor;
};

struct i_struct_T {
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  coder::array<real_T, 1U> xstarsqp;
  coder::array<real_T, 1U> xstarsqp_old;
  coder::bounded_array<real_T, 6U, 1U> cEq;
  coder::bounded_array<real_T, 6U, 1U> cEq_old;
  coder::array<real_T, 1U> grad;
  coder::array<real_T, 1U> grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  coder::array<real_T, 1U> lambdasqp;
  coder::array<real_T, 1U> lambdaStopTest;
  coder::array<real_T, 1U> lambdaStopTestPrev;
  real_T steplength;
  coder::array<real_T, 1U> delta_x;
  coder::array<real_T, 1U> socDirection;
  coder::array<int32_T, 1U> workingset_old;
  coder::array<real_T, 1U> gradLag;
  coder::array<real_T, 1U> delta_gradLag;
  coder::array<real_T, 1U> xstar;
  real_T fstar;
  real_T firstorderopt;
  coder::array<real_T, 1U> lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  coder::array<real_T, 1U> searchDir;
};

struct j_struct_T {
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  coder::empty_bounded_array<real_T, 1U> Aineq;
  coder::array<real_T, 1U> Aeq;
  coder::bounded_array<real_T, 6U, 1U> beq;
  coder::array<real_T, 1U> lb;
  coder::array<real_T, 1U> ub;
  coder::array<int32_T, 1U> indexLB;
  coder::array<int32_T, 1U> indexUB;
  coder::array<int32_T, 1U> indexFixed;
  int32_T mEqRemoved;
  coder::bounded_array<int32_T, 6U, 1U> indexEqRemoved;
  coder::array<real_T, 1U> ATwset;
  coder::array<real_T, 1U> bwset;
  int32_T nActiveConstr;
  coder::array<real_T, 1U> maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  coder::array<boolean_T, 1U> isActiveConstr;
  coder::array<int32_T, 1U> Wid;
  coder::array<int32_T, 1U> Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

struct k_struct_T {
  char_T SolverName[7];
  int32_T MaxIterations;
  real_T StepTolerance;
  real_T ObjectiveLimit;
};

struct l_struct_T {
  coder::anonymous_function objfun;
  real_T f_1;
  real_T f_2;
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  coder::array<boolean_T, 1U> hasLB;
  coder::array<boolean_T, 1U> hasUB;
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtDoubleCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
  int32_T checkKind;
};

struct rtRunTimeErrorInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

// End of code generation (inverseKinematics_internal_types.h)
