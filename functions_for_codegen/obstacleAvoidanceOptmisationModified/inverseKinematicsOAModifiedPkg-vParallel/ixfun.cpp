//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixfun.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Mar-2025 16:37:43
//

// Include Files
#include "ixfun.h"
#include "inverseKinematicsOAModified_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
//
// Arguments    : const char *aFcnName
//                int aLineNum
// Return Type  : void
//
static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::string errMsg;
  std::stringstream outStream;
  outStream << "Arrays have incompatible sizes for this operation.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  if (omp_in_parallel()) {
    errMsg = outStream.str();
    std::fprintf(stderr, "%s", errMsg.c_str());
    std::abort();
  } else {
    throw std::runtime_error(outStream.str());
  }
}

//
// Arguments    : const array<double, 1U> &a
//                const array<double, 1U> &b
//                array<double, 1U> &c
// Return Type  : void
//
namespace coder {
namespace internal {
void expand_max(const array<double, 1U> &a, const array<double, 1U> &b,
                array<double, 1U> &c)
{
  static rtRunTimeErrorInfo e_emlrtRTEI{
      225,         // lineNo
      "expand_max" // fName
  };
  int csz_idx_0;
  int u0;
  if (b.size(0) == 1) {
    csz_idx_0 = a.size(0);
  } else if (a.size(0) == 1) {
    csz_idx_0 = b.size(0);
  } else {
    u0 = a.size(0);
    csz_idx_0 = b.size(0);
    if (u0 <= csz_idx_0) {
      csz_idx_0 = u0;
    }
    if (a.size(0) != b.size(0)) {
      b_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
  }
  c.set_size(csz_idx_0);
  if (csz_idx_0 != 0) {
    boolean_T b1;
    boolean_T b_b;
    b_b = (a.size(0) != 1);
    b1 = (b.size(0) != 1);
    u0 = csz_idx_0 - 1;
    if (static_cast<int>(csz_idx_0 < 1600)) {
      for (int k{0}; k <= u0; k++) {
        c[k] = std::fmax(a[b_b * k], b[b1 * k]);
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k <= u0; k++) {
        c[k] = std::fmax(a[b_b * k], b[b1 * k]);
      }
    }
  }
}

//
// Arguments    : const array<double, 1U> &a
//                const array<double, 1U> &b
//                array<double, 1U> &c
// Return Type  : void
//
void expand_min(const array<double, 1U> &a, const array<double, 1U> &b,
                array<double, 1U> &c)
{
  static rtRunTimeErrorInfo e_emlrtRTEI{
      225,         // lineNo
      "expand_min" // fName
  };
  int csz_idx_0;
  int u0;
  if (b.size(0) == 1) {
    csz_idx_0 = a.size(0);
  } else if (a.size(0) == 1) {
    csz_idx_0 = b.size(0);
  } else {
    u0 = a.size(0);
    csz_idx_0 = b.size(0);
    if (u0 <= csz_idx_0) {
      csz_idx_0 = u0;
    }
    if (a.size(0) != b.size(0)) {
      b_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
  }
  c.set_size(csz_idx_0);
  if (csz_idx_0 != 0) {
    boolean_T b1;
    boolean_T b_b;
    b_b = (a.size(0) != 1);
    b1 = (b.size(0) != 1);
    u0 = csz_idx_0 - 1;
    if (static_cast<int>(csz_idx_0 < 1600)) {
      for (int k{0}; k <= u0; k++) {
        c[k] = std::fmin(a[b_b * k], b[b1 * k]);
      }
    } else {
#pragma omp parallel for num_threads(                                          \
    16 > omp_get_max_threads() ? omp_get_max_threads() : 16)

      for (int k = 0; k <= u0; k++) {
        c[k] = std::fmin(a[b_b * k], b[b1 * k]);
      }
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for ixfun.cpp
//
// [EOF]
//
