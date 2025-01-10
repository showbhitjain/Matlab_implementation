//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct.cpp
//
// Code generation for function 'factoryConstruct'
//

// Include files
#include "factoryConstruct.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Variable Definitions
static emlrtRTEInfo fb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+TrialState/factoryConstruct.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace TrialState {
void factoryConstruct(const emlrtStack &sp, int32_T nVarMax, int32_T mConstrMax,
                      int32_T mEq, const array<real_T, 1U> &x0, i_struct_T &obj)
{
  obj.nVarMax = nVarMax;
  obj.mNonlinIneq = 0;
  obj.mNonlinEq = 0;
  obj.mIneq = 0;
  obj.mEq = mEq;
  obj.iNonIneq0 = 1;
  obj.iNonEq0 = mEq + 1;
  obj.sqpFval = 0.0;
  obj.sqpFval_old = 0.0;
  obj.xstarsqp.set_size(&fb_emlrtRTEI, &sp, x0.size(0));
  obj.xstarsqp_old.set_size(&fb_emlrtRTEI, &sp, x0.size(0));
  obj.cEq.size[0] = mEq;
  obj.cEq_old.size[0] = mEq;
  obj.grad.set_size(&fb_emlrtRTEI, &sp, nVarMax);
  obj.grad_old.set_size(&fb_emlrtRTEI, &sp, nVarMax);
  obj.FunctionEvaluations = 0;
  obj.sqpIterations = 0;
  obj.sqpExitFlag = 0;
  obj.lambdasqp.set_size(&fb_emlrtRTEI, &sp, mConstrMax);
  for (int32_T i{0}; i < mConstrMax; i++) {
    obj.lambdasqp[i] = 0.0;
  }
  obj.lambdaStopTest.set_size(&fb_emlrtRTEI, &sp, mConstrMax);
  obj.lambdaStopTestPrev.set_size(&fb_emlrtRTEI, &sp, mConstrMax);
  obj.steplength = 1.0;
  obj.delta_x.set_size(&fb_emlrtRTEI, &sp, nVarMax);
  for (int32_T i{0}; i < nVarMax; i++) {
    obj.delta_x[i] = 0.0;
  }
  obj.socDirection.set_size(&fb_emlrtRTEI, &sp, nVarMax);
  obj.workingset_old.set_size(&fb_emlrtRTEI, &sp, mConstrMax);
  obj.gradLag.set_size(&fb_emlrtRTEI, &sp, nVarMax);
  obj.delta_gradLag.set_size(&fb_emlrtRTEI, &sp, nVarMax);
  obj.xstar.set_size(&fb_emlrtRTEI, &sp, nVarMax);
  obj.fstar = 0.0;
  obj.firstorderopt = 0.0;
  obj.lambda.set_size(&fb_emlrtRTEI, &sp, mConstrMax);
  for (int32_T i{0}; i < mConstrMax; i++) {
    obj.lambda[i] = 0.0;
  }
  obj.state = 0;
  obj.maxConstr = 0.0;
  obj.iterations = 0;
  obj.searchDir.set_size(&fb_emlrtRTEI, &sp, nVarMax);
}

} // namespace TrialState
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct.cpp)
