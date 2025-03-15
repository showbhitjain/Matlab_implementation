//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified_mexutil.cpp
//
// Code generation for function 'inverseKinematicsOAModified_mexutil'
//

// Include files
#include "inverseKinematicsOAModified_mexutil.h"
#include "inverseKinematicsOAModified_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Definitions
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

// End of code generation (inverseKinematicsOAModified_mexutil.cpp)
