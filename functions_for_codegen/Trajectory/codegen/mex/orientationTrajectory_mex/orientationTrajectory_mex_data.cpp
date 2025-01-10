//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// orientationTrajectory_mex_data.cpp
//
// Code generation for function 'orientationTrajectory_mex_data'
//

// Include files
#include "orientationTrajectory_mex_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131643U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "orientationTrajectory_mex",                          // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

emlrtRSInfo l_emlrtRSI{
    125,                                                          // lineNo
    "colon",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/colon.m" // pathName
};

emlrtRSInfo o_emlrtRSI{
    20,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" // pathName
};

emlrtRSInfo
    ib_emlrtRSI{
        93,                   // lineNo
        "validateattributes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/lang/"
        "validateattributes.m" // pathName
    };

emlrtRSInfo jb_emlrtRSI{
    31,                                // lineNo
    "NameValueParser/NameValueParser", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+core/+internal/+codegen/NameValueParser.m" // pathName
};

emlrtRSInfo kb_emlrtRSI{
    39,                                                  // lineNo
    "NameValueParserInterface/NameValueParserInterface", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+core/+internal/NameValueParserInterface.m" // pathName
};

emlrtRSInfo mb_emlrtRSI{
    44,                                                               // lineNo
    "mpower",                                                         // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/matfun/mpower.m" // pathName
};

emlrtRSInfo nb_emlrtRSI{
    71,                                                           // lineNo
    "power",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

emlrtRSInfo ub_emlrtRSI{
    19,                             // lineNo
    "addFlatSegmentsToPPFormParts", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pathName
};

emlrtRSInfo vb_emlrtRSI{
    62,                // lineNo
    "addSegmentToEnd", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/addFlatSegmentsToPPFormParts.m" // pathName
};

emlrtRSInfo ed_emlrtRSI{
    39,                                                               // lineNo
    "cat",                                                            // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

emlrtRSInfo fd_emlrtRSI{
    113,                                                              // lineNo
    "cat_impl",                                                       // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pathName
};

emlrtRSInfo je_emlrtRSI{
    12,                          // lineNo
    "quaternioncg/quaternioncg", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/+coder/@quaternioncg/quaternio"
    "ncg.m" // pathName
};

emlrtRSInfo ke_emlrtRSI{
    72,                              // lineNo
    "quaternionBase/quaternionBase", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/quaternionBase"
    ".m" // pathName
};

emlrtRSInfo le_emlrtRSI{
    318,                     // lineNo
    "processFourInputConst", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/quaternionBase"
    ".m" // pathName
};

emlrtRSInfo sf_emlrtRSI{
    66,                                                              // lineNo
    "repmat",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

emlrtRSInfo ah_emlrtRSI{
    78,                                                              // lineNo
    "mkpp",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/mkpp.m" // pathName
};

emlrtRSInfo bh_emlrtRSI{
    40,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pathName
};

emlrtMCInfo emlrtMCI{
    27,                                                            // lineNo
    5,                                                             // colNo
    "error",                                                       // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/lang/error.m" // pName
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t orientationTrajectory_nestLockGlobal;

emlrtRTEInfo emlrtRTEI{
    288,                                                              // lineNo
    27,                                                               // colNo
    "check_non_axis_size",                                            // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

emlrtRTEInfo d_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatefinite", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatefinite.m" // pName
};

emlrtRTEInfo i_emlrtRTEI{
    13,                   // lineNo
    37,                   // colNo
    "validateincreasing", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateincreasing.m" // pName
};

emlrtRTEInfo j_emlrtRTEI{
    14,                    // lineNo
    37,                    // colNo
    "validatenonnegative", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnegative.m" // pName
};

emlrtRTEInfo m_emlrtRTEI{
    324,           // lineNo
    27,            // colNo
    "localAssert", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/quaternionBase"
    ".m" // pName
};

emlrtRTEInfo n_emlrtRTEI{
    13,                 // lineNo
    37,                 // colNo
    "validatenonempty", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonempty.m" // pName
};

emlrtRTEInfo o_emlrtRTEI{
    74,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

emlrtRTEInfo q_emlrtRTEI{
    28,           // lineNo
    27,           // colNo
    "validatele", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatele.m" // pName
};

emlrtRTEInfo r_emlrtRTEI{
    28,           // lineNo
    27,           // colNo
    "validatege", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatege.m" // pName
};

emlrtRTEInfo ab_emlrtRTEI{
    76,                                                              // lineNo
    15,                                                              // colNo
    "mkpp",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/mkpp.m" // pName
};

emlrtRTEInfo cb_emlrtRTEI{
    81,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

emlrtECInfo q_emlrtECI{
    -1,                     // nDims
    19,                     // lineNo
    5,                      // colNo
    "polyCoeffsDerivative", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/polyCoeffsDerivative.m" // pName
};

emlrtRTEInfo ed_emlrtRTEI{
    59,                                                              // lineNo
    28,                                                              // colNo
    "repmat",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" // pName
};

emlrtRTEInfo ae_emlrtRTEI{
    19,                     // lineNo
    20,                     // colNo
    "polyCoeffsDerivative", // fName
    "/usr/local/MATLAB/R2023b/toolbox/shared/polytraj/+robotics/+core/"
    "+internal/polyCoeffsDerivative.m" // pName
};

emlrtRSInfo uh_emlrtRSI{
    27,                                                            // lineNo
    "error",                                                       // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/lang/error.m" // pathName
};

covrtInstance emlrtCoverageInstance;

// End of code generation (orientationTrajectory_mex_data.cpp)
