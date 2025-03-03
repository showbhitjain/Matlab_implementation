//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inverseKinematicsOAModified_data.cpp
//
// Code generation for function 'inverseKinematicsOAModified_data'
//

// Include files
#include "inverseKinematicsOAModified_data.h"
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
    "inverseKinematicsOAModified",                        // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2666790369U, 2630951428U, 3350295197U, 1643587045U}, // fSigWrd
    nullptr                                               // fSigMem
};

emlrtRSInfo o_emlrtRSI{
    20,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" // pathName
};

emlrtRSInfo
    v_emlrtRSI{
        94,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pathName
    };

emlrtRSInfo
    w_emlrtRSI{
        142,      // lineNo
        "mtimes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" // pathName
    };

emlrtRSInfo hb_emlrtRSI{
    57,         // lineNo
    "allOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

emlrtRSInfo ib_emlrtRSI{
    106,                   // lineNo
    "applyToMultipleDims", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "applyToMultipleDims.m" // pathName
};

emlrtRSInfo jb_emlrtRSI{
    63,                               // lineNo
    "function_handle/parenReference", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "function_handle.m" // pathName
};

emlrtRSInfo kb_emlrtRSI{
    56,                                                             // lineNo
    "@(x)coder.internal.allOrAny(op,x,coder.internal.indexInt(1))", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

emlrtRSInfo lb_emlrtRSI{
    143,        // lineNo
    "allOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

emlrtRSInfo
    ub_emlrtRSI{
        44,      // lineNo
        "xcopy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xcopy.m" // pathName
    };

emlrtRSInfo
    vb_emlrtRSI{
        69,      // lineNo
        "xcopy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xcopy.m" // pathName
    };

emlrtRSInfo
    wb_emlrtRSI{
        55,           // lineNo
        "xcopy_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xcopy.m" // pathName
    };

emlrtRSInfo ec_emlrtRSI{
    1,           // lineNo
    "factorQRE", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "factorQRE.p" // pathName
};

emlrtRSInfo
    oc_emlrtRSI{
        37,      // lineNo
        "xscal", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xscal.m" // pathName
    };

emlrtRSInfo
    pc_emlrtRSI{
        49,           // lineNo
        "xscal_blas", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xscal.m" // pathName
    };

emlrtRSInfo
    qc_emlrtRSI{
        76,      // lineNo
        "xgemv", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgemv.m" // pathName
    };

emlrtRSInfo
    tc_emlrtRSI{
        15,     // lineNo
        "xger", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xger.m" // pathName
    };

emlrtRSInfo
    uc_emlrtRSI{
        41,      // lineNo
        "xgerx", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" // pathName
    };

emlrtRSInfo xc_emlrtRSI{
    1,                // lineNo
    "computeSquareQ", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
    "computeSquareQ.p" // pathName
};

emlrtRSInfo
    fd_emlrtRSI{
        93,                   // lineNo
        "validateattributes", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/lang/"
        "validateattributes.m" // pathName
    };

emlrtRSInfo
    sd_emlrtRSI{
        69,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pathName
    };

emlrtRSInfo ie_emlrtRSI{
    45,     // lineNo
    "xger", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/xger.m" // pathName
};

emlrtRSInfo
    je_emlrtRSI{
        54,      // lineNo
        "xgerx", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgerx.m" // pathName
    };

emlrtRSInfo se_emlrtRSI{
    1,                     // lineNo
    "computeConstraints_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+utils/"
    "+ObjNonlinEvaluator/computeConstraints_.p" // pathName
};

emlrtRSInfo bf_emlrtRSI{
    1,                // lineNo
    "setProblemType", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/setProblemType.p" // pathName
};

emlrtRSInfo
    pf_emlrtRSI{
        38,      // lineNo
        "xcopy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xcopy.m" // pathName
    };

emlrtRSInfo dg_emlrtRSI{
    1,              // lineNo
    "removeConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/removeConstr.p" // pathName
};

emlrtRSInfo fg_emlrtRSI{
    1,                      // lineNo
    "RemoveDependentIneq_", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+initialize/RemoveDependentIneq_.p" // pathName
};

emlrtRSInfo
    hg_emlrtRSI{
        1,          // lineNo
        "factorQR", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+QRManager/"
        "factorQR.p" // pathName
    };

emlrtRSInfo
    tg_emlrtRSI{
        53,      // lineNo
        "xaxpy", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xaxpy.m" // pathName
    };

emlrtRSInfo
    jh_emlrtRSI{
        23,      // lineNo
        "xrotg", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xrotg.m" // pathName
    };

emlrtRSInfo
    lh_emlrtRSI{
        24,     // lineNo
        "xrot", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xrot.m" // pathName
    };

emlrtRSInfo
    oh_emlrtRSI{
        1,        // lineNo
        "factor", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+CholManager/"
        "factor.p" // pathName
    };

emlrtRSInfo sh_emlrtRSI{
    1,        // lineNo
    "factor", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/factor.p" // pathName
};

emlrtRSInfo di_emlrtRSI{
    1,       // lineNo
    "solve", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/"
    "+DynamicRegCholManager/solve.p" // pathName
};

emlrtRSInfo mi_emlrtRSI{
    1,             // lineNo
    "addLBConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addLBConstr.p" // pathName
};

emlrtRSInfo oi_emlrtRSI{
    1,             // lineNo
    "addUBConstr", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+qpactiveset/"
    "+WorkingSet/addUBConstr.p" // pathName
};

emlrtRSInfo ri_emlrtRSI{
    1,                    // lineNo
    "updatePenaltyParam", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+MeritFunction/updatePenaltyParam.p" // pathName
};

emlrtRSInfo fj_emlrtRSI{
    1,                 // lineNo
    "computeMeritFcn", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/optim/+optim/+coder/+fminconsqp/"
    "+MeritFunction/computeMeritFcn.p" // pathName
};

emlrtRTEInfo
    h_emlrtRTEI{
        138,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

emlrtRTEInfo
    i_emlrtRTEI{
        133,                   // lineNo
        23,                    // colNo
        "dynamic_size_checks", // fName
        "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

emlrtRTEInfo n_emlrtRTEI{
    13,                 // lineNo
    37,                 // colNo
    "validatenonempty", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonempty.m" // pName
};

emlrtRTEInfo o_emlrtRTEI{
    45,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" // pName
};

emlrtRTEInfo p_emlrtRTEI{
    48,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+lapack/"
    "infocheck.m" // pName
};

emlrtBCInfo ub_emlrtBCI{
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

emlrtBCInfo jc_emlrtBCI{
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

emlrtBCInfo kc_emlrtBCI{
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

emlrtBCInfo lc_emlrtBCI{
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

emlrtBCInfo nc_emlrtBCI{
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

emlrtBCInfo pc_emlrtBCI{
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

emlrtBCInfo vc_emlrtBCI{
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

emlrtBCInfo nd_emlrtBCI{
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

emlrtBCInfo qd_emlrtBCI{
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

emlrtBCInfo vd_emlrtBCI{
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

const int32_T iv[4]{0, 1, 2, 3};

covrtInstance emlrtCoverageInstance;

// End of code generation (inverseKinematicsOAModified_data.cpp)
