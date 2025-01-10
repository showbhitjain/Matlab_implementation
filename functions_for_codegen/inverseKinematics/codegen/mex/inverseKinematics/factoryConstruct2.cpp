//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// factoryConstruct2.cpp
//
// Code generation for function 'factoryConstruct2'
//

// Include files
#include "factoryConstruct2.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <cstring>

// Variable Definitions
static emlrtRTEInfo hb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "factoryConstruct", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/factoryConstruct.p" // pName
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace WorkingSet {
void factoryConstruct(const emlrtStack &sp, int32_T mEqMax, int32_T nVar,
                      int32_T nVarMax, int32_T mConstrMax, j_struct_T &obj)
{
  obj.mConstr = 0;
  obj.mConstrOrig = 0;
  obj.mConstrMax = mConstrMax;
  obj.nVar = nVar;
  obj.nVarOrig = nVar;
  obj.nVarMax = nVarMax;
  obj.ldA = nVarMax;
  obj.Aineq.size[0] = 0;
  obj.Aeq.set_size(&hb_emlrtRTEI, &sp, mEqMax * nVarMax);
  obj.beq.size[0] = mEqMax;
  obj.lb.set_size(&hb_emlrtRTEI, &sp, nVarMax);
  obj.ub.set_size(&hb_emlrtRTEI, &sp, nVarMax);
  obj.indexLB.set_size(&hb_emlrtRTEI, &sp, nVarMax);
  obj.indexUB.set_size(&hb_emlrtRTEI, &sp, nVarMax);
  obj.indexFixed.set_size(&hb_emlrtRTEI, &sp, nVarMax);
  obj.mEqRemoved = 0;
  obj.indexEqRemoved.size[0] = mEqMax;
  obj.ATwset.set_size(&hb_emlrtRTEI, &sp, nVarMax * mConstrMax);
  obj.bwset.set_size(&hb_emlrtRTEI, &sp, mConstrMax);
  obj.nActiveConstr = 0;
  obj.maxConstrWorkspace.set_size(&hb_emlrtRTEI, &sp, mConstrMax);
  for (int32_T i{0}; i < 5; i++) {
    obj.sizes[i] = 0;
    obj.sizesNormal[i] = 0;
    obj.sizesPhaseOne[i] = 0;
    obj.sizesRegularized[i] = 0;
    obj.sizesRegPhaseOne[i] = 0;
  }
  for (int32_T i{0}; i < 6; i++) {
    obj.isActiveIdx[i] = 0;
    obj.isActiveIdxNormal[i] = 0;
    obj.isActiveIdxPhaseOne[i] = 0;
    obj.isActiveIdxRegularized[i] = 0;
    obj.isActiveIdxRegPhaseOne[i] = 0;
  }
  obj.isActiveConstr.set_size(&hb_emlrtRTEI, &sp, mConstrMax);
  obj.Wid.set_size(&hb_emlrtRTEI, &sp, mConstrMax);
  obj.Wlocalidx.set_size(&hb_emlrtRTEI, &sp, mConstrMax);
  for (int32_T i{0}; i < 5; i++) {
    obj.nWConstr[i] = 0;
  }
  obj.probType = 3;
  obj.SLACK0 = 1.0E-5;
}

} // namespace WorkingSet
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (factoryConstruct2.cpp)
