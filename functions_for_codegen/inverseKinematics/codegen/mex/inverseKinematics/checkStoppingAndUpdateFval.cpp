//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkStoppingAndUpdateFval.cpp
//
// Code generation for function 'checkStoppingAndUpdateFval'
//

// Include files
#include "checkStoppingAndUpdateFval.h"
#include "computeFval_ReuseHx.h"
#include "eml_int_forloop_overflow_check.h"
#include "feasibleX0ForWorkingSet.h"
#include "inverseKinematics_data.h"
#include "inverseKinematics_internal_types.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo ri_emlrtRSI{
    1,                            // lineNo
    "checkStoppingAndUpdateFval", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkStoppingAndUpdateFval.p" // pathName
};

static emlrtBCInfo ld_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    1,                            // lineNo
    1,                            // colNo
    "",                           // aName
    "checkStoppingAndUpdateFval", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+stopping/checkStoppingAndUpdateFval.p", // pName
    0                                         // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace stopping {
void checkStoppingAndUpdateFval(
    const emlrtStack &sp, int32_T &activeSetChangeID,
    const array<real_T, 1U> &f, i_struct_T &solution, g_struct_T &memspace,
    const f_struct_T &objective, j_struct_T &workingset, d_struct_T &qrmanager,
    real_T options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations,
    boolean_T updateFval)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T nVar;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  solution.iterations++;
  nVar = objective.nvar;
  if ((solution.iterations >= runTimeOptions_MaxIterations) &&
      ((solution.state != 1) || (objective.objtype == 5))) {
    solution.state = 0;
  }
  if (solution.iterations - solution.iterations / 50 * 50 == 0) {
    real_T tempMaxConstr;
    int32_T i;
    st.site = &ri_emlrtRSI;
    solution.maxConstr =
        WorkingSet::maxConstraintViolation(st, workingset, solution.xstar);
    tempMaxConstr = solution.maxConstr;
    if (objective.objtype == 5) {
      i = solution.xstar.size(0);
      if ((objective.nvar < 1) || (objective.nvar > i)) {
        emlrtDynamicBoundsCheckR2012b(objective.nvar, 1, i, &ld_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      tempMaxConstr = solution.maxConstr - solution.xstar[objective.nvar - 1];
    }
    if (tempMaxConstr > 1.0E-6) {
      boolean_T nonDegenerateWset;
      st.site = &ri_emlrtRSI;
      if (objective.nvar >= 1) {
        n_t = (ptrdiff_t)objective.nvar;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        dcopy(&n_t, &(solution.xstar.data())[0], &incx_t,
              &(solution.searchDir.data())[0], &incy_t);
      }
      st.site = &ri_emlrtRSI;
      nonDegenerateWset = initialize::feasibleX0ForWorkingSet(
          st, memspace.workspace_double, solution.searchDir, workingset,
          qrmanager);
      if ((!nonDegenerateWset) && (solution.state != 0)) {
        solution.state = -2;
      }
      activeSetChangeID = 0;
      st.site = &ri_emlrtRSI;
      tempMaxConstr = WorkingSet::maxConstraintViolation(st, workingset,
                                                         solution.searchDir);
      if (tempMaxConstr < solution.maxConstr) {
        st.site = &ri_emlrtRSI;
        if (objective.nvar > 2147483646) {
          b_st.site = &f_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        for (int32_T idx{0}; idx < nVar; idx++) {
          i = solution.searchDir.size(0);
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ld_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i = solution.xstar.size(0);
          if (idx + 1 > i) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ld_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          solution.xstar[idx] = solution.searchDir[idx];
        }
        solution.maxConstr = tempMaxConstr;
      }
    }
  }
  if (updateFval && (options_ObjectiveLimit > rtMinusInf)) {
    st.site = &ri_emlrtRSI;
    solution.fstar = Objective::computeFval_ReuseHx(
        st, objective, memspace.workspace_double, f, solution.xstar);
    if ((solution.fstar < options_ObjectiveLimit) &&
        ((solution.state != 0) || (objective.objtype != 5))) {
      solution.state = 2;
    }
  }
}

} // namespace stopping
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (checkStoppingAndUpdateFval.cpp)
