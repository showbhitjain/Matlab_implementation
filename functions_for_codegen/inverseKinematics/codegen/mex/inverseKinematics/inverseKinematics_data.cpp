//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematics_data.cpp
//
// Code generation for function 'inverseKinematics_data'
//

// Include files
#include "inverseKinematics_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131643U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "inverseKinematics",                                  // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2666790369U, 2630951428U, 3350295197U, 1643587045U}, // fSigWrd
    nullptr                                               // fSigMem
};

emlrtRSInfo f_emlrtRSI{
    20,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" // pathName
};

emlrtRSInfo k_emlrtRSI{
    57,         // lineNo
    "allOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

emlrtRSInfo l_emlrtRSI{
    106,                   // lineNo
    "applyToMultipleDims", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" // pathName
};

emlrtRSInfo m_emlrtRSI{
    63,                               // lineNo
    "function_handle/parenReference", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" // pathName
};

emlrtRSInfo n_emlrtRSI{
    56,                                                             // lineNo
    "@(x)coder.internal.allOrAny(op,x,coder.internal.indexInt(1))", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

emlrtRSInfo o_emlrtRSI{
    143,        // lineNo
    "allOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

emlrtRSInfo
    x_emlrtRSI{
        44,      // lineNo
        "xcopy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xcopy.m" // pathName
    };

emlrtRSInfo
    y_emlrtRSI{
        69,      // lineNo
        "xcopy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xcopy.m" // pathName
    };

emlrtRSInfo hb_emlrtRSI{
    1,           // lineNo
    "factorQRE", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "factorQRE.p" // pathName
};

emlrtRSInfo
    rb_emlrtRSI{
        37,      // lineNo
        "xscal", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xscal.m" // pathName
    };

emlrtRSInfo
    sb_emlrtRSI{
        49,           // lineNo
        "xscal_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xscal.m" // pathName
    };

emlrtRSInfo
    tb_emlrtRSI{
        76,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" // pathName
    };

emlrtRSInfo
    wb_emlrtRSI{
        15,     // lineNo
        "xger", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xger.m" // pathName
    };

emlrtRSInfo
    xb_emlrtRSI{
        41,      // lineNo
        "xgerx", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" // pathName
    };

emlrtRSInfo bc_emlrtRSI{
    1,                // lineNo
    "computeSquareQ", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "computeSquareQ.p" // pathName
};

emlrtRSInfo
    ic_emlrtRSI{
        93,                   // lineNo
        "validateattributes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/lang/"
        "validateattributes.m" // pathName
    };

emlrtRSInfo
    td_emlrtRSI{
        53,      // lineNo
        "xaxpy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xaxpy.m" // pathName
    };

emlrtRSInfo
    vd_emlrtRSI{
        23,      // lineNo
        "xrotg", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xrotg.m" // pathName
    };

emlrtRSInfo pe_emlrtRSI{
    45,     // lineNo
    "xger", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m" // pathName
};

emlrtRSInfo
    qe_emlrtRSI{
        54,      // lineNo
        "xgerx", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" // pathName
    };

emlrtRSInfo af_emlrtRSI{
    1,                     // lineNo
    "computeConstraints_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
    "+ObjNonlinEvaluator/computeConstraints_.p" // pathName
};

emlrtRSInfo ff_emlrtRSI{
    1,                        // lineNo
    "computeLinearResiduals", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/computeLinearResiduals.p" // pathName
};

emlrtRSInfo if_emlrtRSI{
    1,                // lineNo
    "setProblemType", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/setProblemType.p" // pathName
};

emlrtRSInfo
    uf_emlrtRSI{
        38,      // lineNo
        "xcopy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xcopy.m" // pathName
    };

emlrtRSInfo ig_emlrtRSI{
    1,              // lineNo
    "removeConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p" // pathName
};

emlrtRSInfo kg_emlrtRSI{
    1,                      // lineNo
    "RemoveDependentIneq_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentIneq_.p" // pathName
};

emlrtRSInfo
    mg_emlrtRSI{
        1,          // lineNo
        "factorQR", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
        "factorQR.p" // pathName
    };

emlrtRSInfo
    mh_emlrtRSI{
        24,     // lineNo
        "xrot", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xrot.m" // pathName
    };

emlrtRSInfo
    ph_emlrtRSI{
        1,        // lineNo
        "factor", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+CholManager/"
        "factor.p" // pathName
    };

emlrtRSInfo th_emlrtRSI{
    1,        // lineNo
    "factor", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/factor.p" // pathName
};

emlrtRSInfo ei_emlrtRSI{
    1,       // lineNo
    "solve", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/solve.p" // pathName
};

emlrtRSInfo ni_emlrtRSI{
    1,             // lineNo
    "addLBConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addLBConstr.p" // pathName
};

emlrtRSInfo oi_emlrtRSI{
    1,                            // lineNo
    "addBoundToActiveSetMatrix_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p" // pathName
};

emlrtRTEInfo l_emlrtRTEI{
    48,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" // pName
};

emlrtRTEInfo m_emlrtRTEI{
    45,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" // pName
};

emlrtRTEInfo q_emlrtRTEI{
    13,                 // lineNo
    37,                 // colNo
    "validatenonempty", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonempty.m" // pName
};

emlrtBCInfo gb_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    1,                // lineNo
    1,                // colNo
    "",               // aName
    "setProblemType", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/setProblemType.p", // pName
    0                               // checkKind
};

emlrtBCInfo ub_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    1,          // lineNo
    1,          // colNo
    "",         // aName
    "isActive", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/isActive.p", // pName
    0                         // checkKind
};

emlrtBCInfo vb_emlrtBCI{
    -1,             // iFirst
    -1,             // iLast
    1,              // lineNo
    1,              // colNo
    "",             // aName
    "removeConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p", // pName
    0                             // checkKind
};

emlrtBCInfo wb_emlrtBCI{
    1,              // iFirst
    6,              // iLast
    1,              // lineNo
    1,              // colNo
    "",             // aName
    "removeConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p", // pName
    0                             // checkKind
};

emlrtBCInfo yb_emlrtBCI{
    1,              // iFirst
    5,              // iLast
    1,              // lineNo
    1,              // colNo
    "",             // aName
    "removeConstr", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p", // pName
    3                             // checkKind
};

emlrtBCInfo bc_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    1,                      // lineNo
    1,                      // colNo
    "",                     // aName
    "RemoveDependentIneq_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentIneq_.p", // pName
    0                                     // checkKind
};

emlrtBCInfo hc_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    1,          // lineNo
    1,          // colNo
    "",         // aName
    "factorQR", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "factorQR.p", // pName
    0             // checkKind
};

emlrtBCInfo qc_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    1,                            // lineNo
    1,                            // colNo
    "",                           // aName
    "addBoundToActiveSetMatrix_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addBoundToActiveSetMatrix_.p", // pName
    0                                           // checkKind
};

emlrtBCInfo sc_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    1,                         // lineNo
    1,                         // colNo
    "",                        // aName
    "addConstrUpdateRecords_", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addConstrUpdateRecords_.p", // pName
    0                                        // checkKind
};

emlrtBCInfo bd_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    1,        // lineNo
    1,        // colNo
    "",       // aName
    "factor", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/factor.p", // pName
    0                                  // checkKind
};

emlrtBCInfo ed_emlrtBCI{
    -1,      // iFirst
    -1,      // iLast
    1,       // lineNo
    1,       // colNo
    "",      // aName
    "solve", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/solve.p", // pName
    0                                 // checkKind
};

emlrtRTEInfo jb_emlrtRTEI{
    13,                      // lineNo
    50,                      // colNo
    "configurableObjective", // fName
    "/home/shobhit/Franka-emika-Obstacle-avoidance/RobotModelling/"
    "robotmodelling/Matlab_implementation/functions_for_codegen/inverseK"
    "inematics/configurableObjective.m" // pName
};

emlrtRTEInfo rb_emlrtRTEI{
    1,                        // lineNo
    1,                        // colNo
    "computeLinearResiduals", // fName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+internal/computeLinearResiduals.p" // pName
};

const int32_T iv[4]{0, 1, 2, 3};

covrtInstance emlrtCoverageInstance;

// End of code generation (inverseKinematics_data.cpp)
