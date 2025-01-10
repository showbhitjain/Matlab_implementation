//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// trapveltraj.cpp
//
// Code generation for function 'trapveltraj'
//

// Include files
#include "trapveltraj.h"
#include "addFlatSegmentsToPPFormParts.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "linspace.h"
#include "mpower.h"
#include "orientationTrajectory_mex_data.h"
#include "orientationTrajectory_mex_internal_types.h"
#include "orientationTrajectory_mex_mexutil.h"
#include "ppval.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include "mwmathutil.h"
#include <cstring>
#include <emmintrin.h>

// Type Definitions
namespace trajectoryGeneration {
struct cell_wrap_10 {
  real_T f1[4];
};

struct cell_wrap_11 {
  real_T f1[9];
};

struct cell_wrap_19 {
  ::coder::array<real_T, 2U> f1;
};

struct cell_wrap_30 {
  ::coder::array<real_T, 2U> f1;
};

} // namespace trajectoryGeneration

// Variable Definitions
static emlrtRSInfo
    v_emlrtRSI{
        83,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    w_emlrtRSI{
        93,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    x_emlrtRSI{
        94,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    y_emlrtRSI{
        95,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    ab_emlrtRSI{
        96,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    bb_emlrtRSI{
        97,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    cb_emlrtRSI{
        98,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    db_emlrtRSI{
        104,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    eb_emlrtRSI{
        105,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    fb_emlrtRSI{
        133,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    gb_emlrtRSI{
        136,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    hb_emlrtRSI{
        177,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    lb_emlrtRSI{
        277,               // lineNo
        "isOptInputValid", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    qb_emlrtRSI{
        192,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    rb_emlrtRSI{
        203,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    sb_emlrtRSI{
        204,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    tb_emlrtRSI{
        205,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    tf_emlrtRSI{
        82,            // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    uf_emlrtRSI{
        110,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    vf_emlrtRSI{
        111,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    wf_emlrtRSI{
        143,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    xf_emlrtRSI{
        152,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    yf_emlrtRSI{
        153,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    ag_emlrtRSI{
        292,             // lineNo
        "reformatInput", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo bg_emlrtRSI{
    28,                                                              // lineNo
    "repmat",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

static emlrtRSInfo cg_emlrtRSI{
    64,                                                              // lineNo
    "repmat",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

static emlrtRSInfo
    fg_emlrtRSI{
        224,                          // lineNo
        "checkPolyForMultipleBreaks", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo gg_emlrtRSI{
    19,                                                           // lineNo
    "abs",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elfun/abs.m" // pathName
};

static emlrtRSInfo hg_emlrtRSI{
    74,                    // lineNo
    "applyScalarFunction", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunction.m" // pathName
};

static emlrtRSInfo ig_emlrtRSI{
    13,                                                         // lineNo
    "any",                                                      // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/ops/any.m" // pathName
};

static emlrtRSInfo jg_emlrtRSI{
    143,        // lineNo
    "allOrAny", // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/allOrAny.m" // pathName
};

static emlrtRSInfo
    kg_emlrtRSI{
        251,                        // lineNo
        "processPolynomialResults", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo lg_emlrtRSI{
    69,                                                              // lineNo
    "repmat",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

static emlrtRSInfo
    mg_emlrtRSI{
        194,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    ng_emlrtRSI{
        195,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    og_emlrtRSI{
        197,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    pg_emlrtRSI{
        198,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo
    qg_emlrtRSI{
        199,                             // lineNo
        "generateTrajectoriesFromCoefs", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtMCInfo b_emlrtMCI{
    47,                                                              // lineNo
    5,                                                               // colNo
    "repmat",                                                        // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" // pName
};

static emlrtDCInfo
    g_emlrtDCI{
        116,           // lineNo
        20,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtDCInfo
    h_emlrtDCI{
        115,           // lineNo
        19,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtDCInfo
    i_emlrtDCI{
        114,           // lineNo
        18,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        4                // checkKind
    };

static emlrtDCInfo
    j_emlrtDCI{
        114,           // lineNo
        18,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtRTEInfo c_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatenonnan", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnan.m" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    14,                 // lineNo
    37,                 // colNo
    "validatepositive", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatepositive.m" // pName
};

static emlrtRTEInfo
    f_emlrtRTEI{
        479,                    // lineNo
        9,                      // colNo
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    g_emlrtRTEI{
        478,                    // lineNo
        9,                      // colNo
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtECInfo
    d_emlrtECI{
        -1,            // nDims
        177,           // lineNo
        53,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtBCInfo
    m_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        177,           // lineNo
        72,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtECInfo
    e_emlrtECI{
        -1,            // nDims
        177,           // lineNo
        10,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtBCInfo
    n_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        177,           // lineNo
        27,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    o_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        177,           // lineNo
        25,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtECInfo
    f_emlrtECI{
        -1,            // nDims
        177,           // lineNo
        31,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtBCInfo
    p_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        177,           // lineNo
        49,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtECInfo
    g_emlrtECI{
        -1,            // nDims
        146,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtDCInfo
    k_emlrtDCI{
        114,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtDCInfo
    l_emlrtDCI{
        115,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtDCInfo
    m_emlrtDCI{
        116,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtRTEInfo p_emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" // pName
};

static emlrtRTEInfo
    u_emlrtRTEI{
        101,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    v_emlrtRTEI{
        104,           // lineNo
        68,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    w_emlrtRTEI{
        105,           // lineNo
        70,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtBCInfo
    ob_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        134,           // lineNo
        28,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    pb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        177,           // lineNo
        47,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    qb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        177,           // lineNo
        70,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    rb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        168,           // lineNo
        43,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtDCInfo
    n_emlrtDCI{
        125,           // lineNo
        22,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtDCInfo
    o_emlrtDCI{
        126,           // lineNo
        25,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtBCInfo
    sb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        146,           // lineNo
        22,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtDCInfo
    p_emlrtDCI{
        125,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtDCInfo
    q_emlrtDCI{
        126,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtBCInfo
    tb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        134,           // lineNo
        13,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    ub_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        136,           // lineNo
        73,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    vb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        136,           // lineNo
        89,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtDCInfo
    r_emlrtDCI{
        142,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtDCInfo
    s_emlrtDCI{
        144,           // lineNo
        23,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        1                // checkKind
    };

static emlrtBCInfo
    wb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        144,           // lineNo
        23,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    xb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        147,           // lineNo
        66,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    yb_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        177,           // lineNo
        76,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    ac_emlrtBCI{
        -1,            // iFirst
        -1,            // iLast
        147,           // lineNo
        13,            // colNo
        "",            // aName
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    bc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        324,                    // lineNo
        22,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    cc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        325,                    // lineNo
        22,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    dc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        422,                    // lineNo
        29,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    ec_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        422,                    // lineNo
        31,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    fc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        431,                    // lineNo
        29,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    gc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        431,                    // lineNo
        31,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    hc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        443,                    // lineNo
        29,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    ic_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        443,                    // lineNo
        31,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    jc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        423,                    // lineNo
        29,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    kc_emlrtBCI{
        -1,                     // iFirst
        -1,                     // iLast
        423,                    // lineNo
        31,                     // colNo
        "",                     // aName
        "computeProfileParams", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtECInfo
    p_emlrtECI{
        2,                            // nDims
        224,                          // lineNo
        37,                           // colNo
        "checkPolyForMultipleBreaks", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtBCInfo
    lc_emlrtBCI{
        -1,                         // iFirst
        -1,                         // iLast
        238,                        // lineNo
        36,                         // colNo
        "",                         // aName
        "processPolynomialResults", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtBCInfo
    mc_emlrtBCI{
        -1,                         // iFirst
        -1,                         // iLast
        252,                        // lineNo
        38,                         // colNo
        "",                         // aName
        "processPolynomialResults", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m", // pName
        0                // checkKind
    };

static emlrtRTEInfo bb_emlrtRTEI{
    48,                                                              // lineNo
    19,                                                              // colNo
    "mkpp",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/mkpp.m" // pName
};

static emlrtRTEInfo
    sb_emlrtRTEI{
        114,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    tb_emlrtRTEI{
        115,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    ub_emlrtRTEI{
        116,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    vb_emlrtRTEI{
        1,             // lineNo
        37,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    fd_emlrtRTEI{
        120,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    gd_emlrtRTEI{
        125,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    hd_emlrtRTEI{
        126,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    id_emlrtRTEI{
        142,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    jd_emlrtRTEI{
        143,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    kd_emlrtRTEI{
        144,           // lineNo
        23,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    ld_emlrtRTEI{
        288,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    md_emlrtRTEI{
        350,           // lineNo
        46,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    nd_emlrtRTEI{
        350,           // lineNo
        23,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    od_emlrtRTEI{
        351,           // lineNo
        46,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    pd_emlrtRTEI{
        351,           // lineNo
        23,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    qd_emlrtRTEI{
        224,           // lineNo
        37,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo rd_emlrtRTEI{
    30,                    // lineNo
    21,                    // colNo
    "applyScalarFunction", // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunction.m" // pName
};

static emlrtRTEInfo
    sd_emlrtRTEI{
        224,           // lineNo
        33,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    td_emlrtRTEI{
        255,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    ud_emlrtRTEI{
        256,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    vd_emlrtRTEI{
        228,           // lineNo
        36,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    wd_emlrtRTEI{
        252,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    xd_emlrtRTEI{
        253,           // lineNo
        13,            // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    yd_emlrtRTEI{
        194,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    be_emlrtRTEI{
        195,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    ce_emlrtRTEI{
        197,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    de_emlrtRTEI{
        198,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    ee_emlrtRTEI{
        199,           // lineNo
        5,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRTEInfo
    fe_emlrtRTEI{
        203,           // lineNo
        9,             // colNo
        "trapveltraj", // fName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pName
    };

static emlrtRSInfo
    sh_emlrtRSI{
        156,           // lineNo
        "trapveltraj", // fcnName
        "/usr/local/MATLAB/R2023b/toolbox/shared/robotics/robotcore/"
        "trapveltraj.m" // pathName
    };

static emlrtRSInfo th_emlrtRSI{
    47,                                                              // lineNo
    "repmat",                                                        // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

// Function Declarations
namespace trajectoryGeneration {
namespace coder {
static boolean_T b_isOptInputValid(const emlrtStack &sp, real_T p,
                                   const ::coder::array<real_T, 2U> &inputVar);

static boolean_T
checkPolyForMultipleBreaks(const emlrtStack &sp,
                           const ::coder::array<real_T, 2U> &breakMat);

static real_T computeProfileParams(const emlrtStack &sp, real_T i, real_T j,
                                   const ::coder::array<real_T, 2U> &wayPoints,
                                   const ::coder::array<real_T, 2U> &TFi,
                                   const ::coder::array<real_T, 2U> &TAc,
                                   real_T &aParam, real_T &tAParam,
                                   real_T &tFParam);

static void computeScalarLSPBCoefficients(real_T s0, real_T sF, real_T v,
                                          real_T a, real_T ta, real_T tf,
                                          real_T coefs[9], real_T breaks[4]);

static void generateTrajectoriesFromCoefs(
    const emlrtStack &sp, const ::coder::array<real_T, 2U> &breaks,
    const ::coder::array<real_T, 2U> &coeffs, real_T dim,
    const ::coder::array<real_T, 2U> &t, ::coder::array<real_T, 2U> &q,
    ::coder::array<real_T, 2U> &qd, ::coder::array<real_T, 2U> &qdd,
    ::coder::array<real_T, 2U> &pp_breaks,
    ::coder::array<real_T, 3U> &pp_coefs);

static boolean_T isOptInputValid(const emlrtStack &sp, real_T p,
                                 const ::coder::array<real_T, 2U> &inputVar);

static void processPolynomialResults(const emlrtStack &sp,
                                     const ::coder::array<real_T, 2U> &breakMat,
                                     const ::coder::array<real_T, 2U> &coeffMat,
                                     boolean_T hasMultipleBreaks, real_T p,
                                     cell_wrap_19 breaksCell[3],
                                     cell_wrap_30 coeffCell[3]);

static void reformatInput(const emlrtStack &sp,
                          const ::coder::array<real_T, 2U> &input, real_T p,
                          ::coder::array<real_T, 2U> &matrixInput);

} // namespace coder
} // namespace trajectoryGeneration

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
static boolean_T b_isOptInputValid(const emlrtStack &sp, real_T p,
                                   const ::coder::array<real_T, 2U> &inputVar)
{
  emlrtStack b_st;
  emlrtStack st;
  boolean_T isValid;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  isValid = true;
  if (inputVar.size(1) != 0) {
    int32_T k;
    boolean_T x[2];
    boolean_T exitg1;
    boolean_T guard1;
    boolean_T y;
    x[0] = false;
    x[1] = (inputVar.size(1) == 1);
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    guard1 = false;
    if (y) {
      guard1 = true;
    } else {
      x[0] = true;
      x[1] = (inputVar.size(1) == 1);
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (!x[k]) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (y) {
        guard1 = true;
      } else {
        x[0] = true;
        x[1] = (inputVar.size(1) == p - 1.0);
        y = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 2)) {
          if (!x[k]) {
            y = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (y) {
          guard1 = true;
        } else {
          isValid = false;
        }
      }
    }
    if (guard1) {
      int32_T i;
      st.site = &lb_emlrtRSI;
      b_st.site = &ib_emlrtRSI;
      y = true;
      i = 3 * inputVar.size(1);
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i - 1)) {
        if (!(inputVar[k] <= 0.0)) {
          k++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &e_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedPositive",
            "MATLAB:trapveltraj:expectedPositive", 3, 4, 9, "AccelTime");
      }
      b_st.site = &ib_emlrtRSI;
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i - 1)) {
        if ((!muDoubleScalarIsInf(inputVar[k])) &&
            (!muDoubleScalarIsNaN(inputVar[k]))) {
          k++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &d_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedFinite",
            "MATLAB:trapveltraj:expectedFinite", 3, 4, 9, "AccelTime");
      }
      b_st.site = &ib_emlrtRSI;
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i - 1)) {
        if (!muDoubleScalarIsNaN(inputVar[k])) {
          k++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &c_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedNonNaN",
            "MATLAB:trapveltraj:expectedNonNaN", 3, 4, 9, "AccelTime");
      }
    }
  }
  return isValid;
}

static boolean_T
checkPolyForMultipleBreaks(const emlrtStack &sp,
                           const ::coder::array<real_T, 2U> &breakMat)
{
  ::coder::array<real_T, 2U> x;
  ::coder::array<real_T, 2U> y;
  ::coder::array<boolean_T, 2U> b_x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T loop_ub;
  boolean_T hasMultipleBreaks;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  hasMultipleBreaks = false;
  iv[0] = 1;
  iv[1] = breakMat.size(1);
  iv1[0] = 1;
  iv1[1] = breakMat.size(1);
  loop_ub = breakMat.size(1);
  for (int32_T i{0}; i < 2; i++) {
    int32_T nx;
    boolean_T b_y;
    boolean_T exitg1;
    if (iv[1] != iv1[1]) {
      emlrtSizeEqCheckNDErrorR2021b(&iv[0], &iv1[0], &p_emlrtECI,
                                    (emlrtCTX)&sp);
    }
    st.site = &fg_emlrtRSI;
    x.set_size(&qd_emlrtRTEI, &st, 1, breakMat.size(1));
    for (int32_T k{0}; k < loop_ub; k++) {
      x[k] = breakMat[i + 3 * k] - breakMat[(i + 3 * k) + 1];
    }
    b_st.site = &gg_emlrtRSI;
    nx = x.size(1);
    y.set_size(&rd_emlrtRTEI, &b_st, 1, x.size(1));
    c_st.site = &hg_emlrtRSI;
    if (x.size(1) > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(d_st);
    }
    for (int32_T k{0}; k < nx; k++) {
      y[k] = muDoubleScalarAbs(x[k]);
    }
    st.site = &fg_emlrtRSI;
    b_x.set_size(&sd_emlrtRTEI, &st, 1, y.size(1));
    nx = y.size(1);
    for (int32_T k{0}; k < nx; k++) {
      b_x[k] = (y[k] > 2.2204460492503131E-16);
    }
    b_st.site = &ig_emlrtRSI;
    b_y = false;
    c_st.site = &jg_emlrtRSI;
    if (b_x.size(1) > 2147483646) {
      d_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(d_st);
    }
    nx = 1;
    exitg1 = false;
    while ((!exitg1) && (nx <= b_x.size(1))) {
      if (b_x[nx - 1]) {
        b_y = true;
        exitg1 = true;
      } else {
        nx++;
      }
    }
    if (b_y || hasMultipleBreaks) {
      hasMultipleBreaks = true;
    } else {
      hasMultipleBreaks = false;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return hasMultipleBreaks;
}

static real_T computeProfileParams(const emlrtStack &sp, real_T i, real_T j,
                                   const ::coder::array<real_T, 2U> &wayPoints,
                                   const ::coder::array<real_T, 2U> &TFi,
                                   const ::coder::array<real_T, 2U> &TAc,
                                   real_T &aParam, real_T &tAParam,
                                   real_T &tFParam)
{
  ::coder::array<real_T, 2U> TAcSwitch;
  ::coder::array<real_T, 2U> TFiSwitch;
  real_T b_sF;
  real_T s0;
  real_T sF;
  real_T vParam;
  int32_T deltaSign;
  int32_T loop_ub;
  boolean_T inputCombo_idx_2;
  boolean_T inputCombo_idx_3;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if ((static_cast<int32_T>(j) < 1) ||
      (static_cast<int32_T>(j) > wayPoints.size(1))) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j), 1, wayPoints.size(1),
                                  &bc_emlrtBCI, (emlrtConstCTX)&sp);
  }
  s0 = wayPoints[(static_cast<int32_T>(i) + 3 * (static_cast<int32_T>(j) - 1)) -
                 1];
  if ((static_cast<int32_T>(j + 1.0) < 1) ||
      (static_cast<int32_T>(j + 1.0) > wayPoints.size(1))) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j + 1.0), 1,
                                  wayPoints.size(1), &cc_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  sF = wayPoints[(static_cast<int32_T>(i) +
                  3 * (static_cast<int32_T>(j + 1.0) - 1)) -
                 1];
  deltaSign = 1;
  if (sF < s0) {
    b_sF = s0;
    s0 = sF;
    sF = b_sF;
    deltaSign = -1;
  }
  inputCombo_idx_2 = (TFi.size(1) != 0);
  inputCombo_idx_3 = (TAc.size(1) != 0);
  if (inputCombo_idx_2) {
    TFiSwitch.set_size(&nd_emlrtRTEI, &sp, 3, TFi.size(1));
    loop_ub = 3 * TFi.size(1);
    for (int32_T b_i{0}; b_i < loop_ub; b_i++) {
      TFiSwitch[b_i] = TFi[b_i];
    }
  } else {
    TFiSwitch.set_size(&md_emlrtRTEI, &sp, static_cast<int32_T>(i),
                       static_cast<int32_T>(j));
    loop_ub = static_cast<int32_T>(i) * static_cast<int32_T>(j);
    for (int32_T b_i{0}; b_i < loop_ub; b_i++) {
      TFiSwitch[b_i] = 1.0;
    }
  }
  if (inputCombo_idx_3) {
    TAcSwitch.set_size(&pd_emlrtRTEI, &sp, 3, TAc.size(1));
    loop_ub = 3 * TAc.size(1);
    for (int32_T b_i{0}; b_i < loop_ub; b_i++) {
      TAcSwitch[b_i] = TAc[b_i];
    }
  } else {
    TAcSwitch.set_size(&od_emlrtRTEI, &sp, static_cast<int32_T>(i),
                       static_cast<int32_T>(j));
    loop_ub = static_cast<int32_T>(i) * static_cast<int32_T>(j);
    for (int32_T b_i{0}; b_i < loop_ub; b_i++) {
      TAcSwitch[b_i] = 1.0;
    }
  }
  switch (inputCombo_idx_2 * 2 + inputCombo_idx_3) {
  case 3:
    if ((static_cast<int32_T>(i) < 1) ||
        (static_cast<int32_T>(i) > TFiSwitch.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i), 1,
                                    TFiSwitch.size(0), &dc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((static_cast<int32_T>(j) < 1) ||
        (static_cast<int32_T>(j) > TFiSwitch.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j), 1,
                                    TFiSwitch.size(1), &ec_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    tFParam = TFiSwitch[(static_cast<int32_T>(i) +
                         TFiSwitch.size(0) * (static_cast<int32_T>(j) - 1)) -
                        1];
    if ((static_cast<int32_T>(i) < 1) ||
        (static_cast<int32_T>(i) > TAcSwitch.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i), 1,
                                    TAcSwitch.size(0), &jc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((static_cast<int32_T>(j) < 1) ||
        (static_cast<int32_T>(j) > TAcSwitch.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j), 1,
                                    TAcSwitch.size(1), &kc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    tAParam = TAcSwitch[(static_cast<int32_T>(i) +
                         TAcSwitch.size(0) * (static_cast<int32_T>(j) - 1)) -
                        1];
    vParam = (sF - s0) / (tFParam - tAParam);
    aParam = vParam / tAParam;
    break;
  case 2:
    if ((static_cast<int32_T>(i) < 1) ||
        (static_cast<int32_T>(i) > TFiSwitch.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i), 1,
                                    TFiSwitch.size(0), &fc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((static_cast<int32_T>(j) < 1) ||
        (static_cast<int32_T>(j) > TFiSwitch.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j), 1,
                                    TFiSwitch.size(1), &gc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    tFParam = TFiSwitch[(static_cast<int32_T>(i) +
                         TFiSwitch.size(0) * (static_cast<int32_T>(j) - 1)) -
                        1];
    vParam = 1.5 * (sF - s0) / tFParam;
    tAParam = ((s0 - sF) + vParam * tFParam) / vParam;
    aParam = vParam / tAParam;
    break;
  case 1: {
    real_T aParam_tmp;
    if ((static_cast<int32_T>(i) < 1) ||
        (static_cast<int32_T>(i) > TAcSwitch.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i), 1,
                                    TAcSwitch.size(0), &hc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((static_cast<int32_T>(j) < 1) ||
        (static_cast<int32_T>(j) > TAcSwitch.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(j), 1,
                                    TAcSwitch.size(1), &ic_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    tAParam = TAcSwitch[(static_cast<int32_T>(i) +
                         TAcSwitch.size(0) * (static_cast<int32_T>(j) - 1)) -
                        1];
    b_sF = sF - s0;
    aParam_tmp = tAParam * tAParam;
    aParam = b_sF / (2.0 * aParam_tmp);
    vParam = aParam * tAParam;
    tFParam = (b_sF + aParam * aParam_tmp) / vParam;
  } break;
  default:
    tFParam = 1.0;
    vParam = 1.5 * (sF - s0);
    tAParam = ((s0 - sF) + vParam) / vParam;
    aParam = vParam / tAParam;
    break;
  }
  if (s0 == sF) {
    aParam = 0.0;
    vParam = 0.0;
    if (muDoubleScalarIsNaN(tFParam) || (tFParam == 0.0)) {
      tFParam = 1.0;
    }
    tAParam = tFParam / 3.0;
  } else {
    b_sF = sF - s0;
    if (!(b_sF / tFParam < vParam)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &g_emlrtRTEI,
          "shared_robotics:robotcore:utils:TrapVelLowerBoundCondition",
          "shared_robotics:robotcore:utils:TrapVelLowerBoundCondition", 6, 6, i,
          6, j, 6, j + 1.0);
    }
    if (!(vParam <= 2.0 * b_sF / tFParam)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &f_emlrtRTEI,
          "shared_robotics:robotcore:utils:TrapVelUpperBoundCondition",
          "shared_robotics:robotcore:utils:TrapVelUpperBoundCondition", 6, 6, i,
          6, j, 6, j + 1.0);
    }
  }
  vParam *= static_cast<real_T>(deltaSign);
  aParam *= static_cast<real_T>(deltaSign);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return vParam;
}

static void computeScalarLSPBCoefficients(real_T s0, real_T sF, real_T v,
                                          real_T a, real_T ta, real_T tf,
                                          real_T coefs[9], real_T breaks[4])
{
  breaks[0] = 0.0;
  breaks[1] = ta;
  breaks[2] = tf - ta;
  breaks[3] = tf;
  std::memset(&coefs[0], 0, 9U * sizeof(real_T));
  if (v == 0.0) {
    coefs[6] = s0;
    coefs[7] = s0;
    coefs[8] = s0;
  } else {
    real_T coefs_tmp;
    coefs[0] = a / 2.0;
    coefs[3] = 0.0;
    coefs[6] = s0;
    coefs[1] = 0.0;
    coefs[4] = v;
    coefs_tmp = a / 2.0 * (ta * ta);
    coefs[7] = coefs_tmp + s0;
    coefs[2] = -a / 2.0;
    coefs[5] = v;
    coefs[8] = (sF + coefs_tmp) - v * ta;
  }
}

static void generateTrajectoriesFromCoefs(
    const emlrtStack &sp, const ::coder::array<real_T, 2U> &breaks,
    const ::coder::array<real_T, 2U> &coeffs, real_T dim,
    const ::coder::array<real_T, 2U> &t, ::coder::array<real_T, 2U> &q,
    ::coder::array<real_T, 2U> &qd, ::coder::array<real_T, 2U> &qdd,
    ::coder::array<real_T, 2U> &pp_breaks, ::coder::array<real_T, 3U> &pp_coefs)
{
  __m128d r1;
  ::coder::array<real_T, 2U> dCoeffs;
  ::coder::array<real_T, 2U> ddCoeffs;
  ::coder::array<real_T, 2U> modBreaks;
  ::coder::array<real_T, 2U> modCoeffs;
  ::coder::array<real_T, 1U> r;
  d_struct_T b_expl_temp;
  d_struct_T c_expl_temp;
  d_struct_T expl_temp;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T newsize[3];
  real_T y_tmp;
  int32_T b_loop_ub;
  int32_T b_loop_ub_tmp;
  int32_T i;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T nx;
  int32_T vectorUB;
  uint32_T unnamed_idx_0;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &qb_emlrtRSI;
  robotics::core::internal::addFlatSegmentsToPPFormParts(
      st, breaks, coeffs, dim, modBreaks, modCoeffs);
  st.site = &mg_emlrtRSI;
  unnamed_idx_0 = static_cast<uint32_T>(modCoeffs.size(0));
  dCoeffs.set_size(&yd_emlrtRTEI, &st, static_cast<int32_T>(unnamed_idx_0), 3);
  loop_ub_tmp = static_cast<int32_T>(unnamed_idx_0) * 3;
  for (i = 0; i < loop_ub_tmp; i++) {
    dCoeffs[i] = 0.0;
  }
  loop_ub = modCoeffs.size(0);
  nx = (loop_ub / 2) << 1;
  vectorUB = nx - 2;
  for (int32_T b_i{0}; b_i < 2; b_i++) {
    r.set_size(&ae_emlrtRTEI, &st, modCoeffs.size(0));
    for (i = 0; i <= vectorUB; i += 2) {
      r1 = _mm_loadu_pd(&modCoeffs[i + modCoeffs.size(0) * b_i]);
      _mm_storeu_pd(
          &r[i],
          _mm_mul_pd(
              _mm_set1_pd((3.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0), r1));
    }
    for (i = nx; i < loop_ub; i++) {
      r[i] = ((3.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0) *
             modCoeffs[i + modCoeffs.size(0) * b_i];
    }
    b_loop_ub = dCoeffs.size(0);
    emlrtSubAssignSizeCheckR2012b(&b_loop_ub, 1, r.size(), 1, &q_emlrtECI, &st);
    for (i = 0; i < b_loop_ub; i++) {
      dCoeffs[i + dCoeffs.size(0) * (b_i + 1)] = r[i];
    }
  }
  st.site = &ng_emlrtRSI;
  unnamed_idx_0 = static_cast<uint32_T>(dCoeffs.size(0));
  ddCoeffs.set_size(&be_emlrtRTEI, &st, static_cast<int32_T>(unnamed_idx_0), 3);
  b_loop_ub_tmp = static_cast<int32_T>(unnamed_idx_0) * 3;
  for (i = 0; i < b_loop_ub_tmp; i++) {
    ddCoeffs[i] = 0.0;
  }
  loop_ub = dCoeffs.size(0);
  nx = (loop_ub / 2) << 1;
  vectorUB = nx - 2;
  for (int32_T b_i{0}; b_i < 2; b_i++) {
    r.set_size(&ae_emlrtRTEI, &st, dCoeffs.size(0));
    for (i = 0; i <= vectorUB; i += 2) {
      r1 = _mm_loadu_pd(&dCoeffs[i + dCoeffs.size(0) * b_i]);
      _mm_storeu_pd(
          &r[i],
          _mm_mul_pd(
              _mm_set1_pd((3.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0), r1));
    }
    for (i = nx; i < loop_ub; i++) {
      r[i] = ((3.0 - (static_cast<real_T>(b_i) + 2.0)) + 1.0) *
             dCoeffs[i + dCoeffs.size(0) * b_i];
    }
    emlrtSubAssignSizeCheckR2012b(ddCoeffs.size(), 1, r.size(), 1, &q_emlrtECI,
                                  &st);
    b_loop_ub = ddCoeffs.size(0);
    for (i = 0; i < b_loop_ub; i++) {
      ddCoeffs[i + ddCoeffs.size(0) * (b_i + 1)] = r[i];
    }
  }
  st.site = &og_emlrtRSI;
  if (!(dim == muDoubleScalarFloor(dim))) {
    emlrtErrorWithMessageIdR2018a(&st, &bb_emlrtRTEI, "Coder:toolbox:InvalidD",
                                  "Coder:toolbox:InvalidD", 0);
  }
  newsize[0] = dim;
  newsize[1] = static_cast<real_T>(modBreaks.size(1)) - 1.0;
  newsize[2] = 3.0;
  y_tmp = dim * (static_cast<real_T>(modBreaks.size(1)) - 1.0) * 3.0;
  if (!(y_tmp == modCoeffs.size(0) * 3)) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  nx = modCoeffs.size(0) * 3;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  vectorUB = modCoeffs.size(0);
  if (modCoeffs.size(0) < 3) {
    vectorUB = 3;
  }
  if (modBreaks.size(1) - 1 > muIntScalarMax_sint32(nx, vectorUB)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  i = static_cast<int32_T>(dim) * (modBreaks.size(1) - 1) * 3;
  if (i != nx) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  pp_coefs.set_size(&ce_emlrtRTEI, &st, static_cast<int32_T>(dim),
                    modBreaks.size(1) - 1, 3);
  nx = static_cast<int32_T>(dim) * (modBreaks.size(1) - 1) * 3;
  for (b_loop_ub = 0; b_loop_ub < nx; b_loop_ub++) {
    pp_coefs[b_loop_ub] = modCoeffs[b_loop_ub];
  }
  pp_breaks.set_size(&ce_emlrtRTEI, &st, 1, modBreaks.size(1));
  loop_ub = modBreaks.size(1);
  for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
    pp_breaks[b_loop_ub] = modBreaks[b_loop_ub];
  }
  st.site = &pg_emlrtRSI;
  newsize[0] = dim;
  newsize[1] = static_cast<real_T>(modBreaks.size(1)) - 1.0;
  newsize[2] = 3.0;
  b_loop_ub = static_cast<int32_T>(y_tmp);
  if (b_loop_ub != dCoeffs.size(0) * 3) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  vectorUB = dCoeffs.size(0);
  if (dCoeffs.size(0) < 3) {
    vectorUB = 3;
  }
  if (modBreaks.size(1) - 1 > muIntScalarMax_sint32(loop_ub_tmp, vectorUB)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (i != loop_ub_tmp) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  expl_temp.coefs.set_size(&de_emlrtRTEI, &st, static_cast<int32_T>(dim),
                           modBreaks.size(1) - 1, 3);
  for (vectorUB = 0; vectorUB < nx; vectorUB++) {
    expl_temp.coefs[vectorUB] = dCoeffs[vectorUB];
  }
  expl_temp.breaks.set_size(&de_emlrtRTEI, &st, 1, modBreaks.size(1));
  loop_ub = modBreaks.size(1);
  for (vectorUB = 0; vectorUB < loop_ub; vectorUB++) {
    expl_temp.breaks[vectorUB] = modBreaks[vectorUB];
  }
  st.site = &qg_emlrtRSI;
  newsize[0] = dim;
  newsize[1] = static_cast<real_T>(modBreaks.size(1)) - 1.0;
  newsize[2] = 3.0;
  if (b_loop_ub != ddCoeffs.size(0) * 3) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:toolbox:MKPPSizeMismatch",
                                  "Coder:toolbox:MKPPSizeMismatch", 0);
  }
  b_st.site = &ah_emlrtRSI;
  c_st.site = &bh_emlrtRSI;
  internal::assertValidSizeArg(c_st, newsize);
  vectorUB = ddCoeffs.size(0);
  if (ddCoeffs.size(0) < 3) {
    vectorUB = 3;
  }
  if (modBreaks.size(1) - 1 > muIntScalarMax_sint32(b_loop_ub_tmp, vectorUB)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (i != b_loop_ub_tmp) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &cb_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  b_expl_temp.coefs.set_size(&ee_emlrtRTEI, &st, static_cast<int32_T>(dim),
                             modBreaks.size(1) - 1, 3);
  for (i = 0; i < nx; i++) {
    b_expl_temp.coefs[i] = ddCoeffs[i];
  }
  b_expl_temp.breaks.set_size(&ee_emlrtRTEI, &st, 1, modBreaks.size(1));
  loop_ub = modBreaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_expl_temp.breaks[i] = modBreaks[i];
  }
  c_expl_temp.coefs.set_size(&fe_emlrtRTEI, &sp, pp_coefs.size(0),
                             pp_coefs.size(1), 3);
  for (i = 0; i < nx; i++) {
    c_expl_temp.coefs[i] = pp_coefs[i];
  }
  c_expl_temp.breaks.set_size(&fe_emlrtRTEI, &sp, 1, pp_breaks.size(1));
  loop_ub = pp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_expl_temp.breaks[i] = pp_breaks[i];
  }
  st.site = &rb_emlrtRSI;
  ppval(st, c_expl_temp, t, q);
  st.site = &sb_emlrtRSI;
  ppval(st, expl_temp, t, qd);
  st.site = &tb_emlrtRSI;
  ppval(st, b_expl_temp, t, qdd);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static boolean_T isOptInputValid(const emlrtStack &sp, real_T p,
                                 const ::coder::array<real_T, 2U> &inputVar)
{
  emlrtStack b_st;
  emlrtStack st;
  boolean_T isValid;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  isValid = true;
  if (inputVar.size(1) != 0) {
    int32_T k;
    boolean_T x[2];
    boolean_T exitg1;
    boolean_T guard1;
    boolean_T y;
    x[0] = false;
    x[1] = (inputVar.size(1) == 1);
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (!x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    guard1 = false;
    if (y) {
      guard1 = true;
    } else {
      x[0] = true;
      x[1] = (inputVar.size(1) == 1);
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 2)) {
        if (!x[k]) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (y) {
        guard1 = true;
      } else {
        x[0] = true;
        x[1] = (inputVar.size(1) == p - 1.0);
        y = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 2)) {
          if (!x[k]) {
            y = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (y) {
          guard1 = true;
        } else {
          isValid = false;
        }
      }
    }
    if (guard1) {
      int32_T i;
      st.site = &lb_emlrtRSI;
      b_st.site = &ib_emlrtRSI;
      y = true;
      i = 3 * inputVar.size(1);
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i - 1)) {
        if (!(inputVar[k] <= 0.0)) {
          k++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &e_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedPositive",
            "MATLAB:trapveltraj:expectedPositive", 3, 4, 7, "EndTime");
      }
      b_st.site = &ib_emlrtRSI;
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i - 1)) {
        if ((!muDoubleScalarIsInf(inputVar[k])) &&
            (!muDoubleScalarIsNaN(inputVar[k]))) {
          k++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &d_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedFinite",
            "MATLAB:trapveltraj:expectedFinite", 3, 4, 7, "EndTime");
      }
      b_st.site = &ib_emlrtRSI;
      y = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i - 1)) {
        if (!muDoubleScalarIsNaN(inputVar[k])) {
          k++;
        } else {
          y = false;
          exitg1 = true;
        }
      }
      if (!y) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &c_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedNonNaN",
            "MATLAB:trapveltraj:expectedNonNaN", 3, 4, 7, "EndTime");
      }
    }
  }
  return isValid;
}

static void processPolynomialResults(const emlrtStack &sp,
                                     const ::coder::array<real_T, 2U> &breakMat,
                                     const ::coder::array<real_T, 2U> &coeffMat,
                                     boolean_T hasMultipleBreaks, real_T p,
                                     cell_wrap_19 breaksCell[3],
                                     cell_wrap_30 coeffCell[3])
{
  static const int32_T iv[2]{1, 15};
  static const int32_T iv1[2]{1, 15};
  static const int32_T iv2[2]{1, 15};
  static const char_T u[15]{'M', 'A', 'T', 'L', 'A', 'B', ':', 'p',
                            'm', 'a', 'x', 's', 'i', 'z', 'e'};
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<boolean_T, 1U> coeffIndex;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (breakMat.size(1) < 1) {
    emlrtDynamicBoundsCheckR2012b(breakMat.size(1), 1, breakMat.size(1),
                                  &lc_emlrtBCI, (emlrtConstCTX)&sp);
  }
  if (hasMultipleBreaks) {
    real_T varargin_1_tmp;
    int32_T end_tmp;
    int32_T ibcol;
    int32_T loop_ub;
    int32_T ntilerows_tmp;
    int32_T outsize_idx_0_tmp;
    boolean_T b;
    st.site = &kg_emlrtRSI;
    varargin_1_tmp = 3.0 * (p - 1.0);
    b_st.site = &bg_emlrtRSI;
    if ((varargin_1_tmp != varargin_1_tmp) ||
        muDoubleScalarIsInf(varargin_1_tmp) ||
        (varargin_1_tmp > 2.147483647E+9)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &p_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
          "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
    }
    outsize_idx_0_tmp = 3 * static_cast<int32_T>(varargin_1_tmp);
    b = !(outsize_idx_0_tmp ==
          3.0 * static_cast<real_T>(static_cast<int32_T>(varargin_1_tmp)));
    if (b) {
      y = nullptr;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&st, 15, m, &u[0]);
      emlrtAssign(&y, m);
      b_st.site = &th_emlrtRSI;
      b_error(b_st, y, b_emlrtMCI);
    }
    coeffIndex.set_size(&ed_emlrtRTEI, &st, outsize_idx_0_tmp);
    ntilerows_tmp = static_cast<int32_T>(varargin_1_tmp);
    b_st.site = &lg_emlrtRSI;
    if (static_cast<int32_T>(varargin_1_tmp) > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (loop_ub = 0; loop_ub < ntilerows_tmp; loop_ub++) {
      ibcol = loop_ub * 3;
      coeffIndex[ibcol] = true;
      coeffIndex[ibcol + 1] = false;
      coeffIndex[ibcol + 2] = false;
    }
    end_tmp = coeffIndex.size(0) - 1;
    ibcol = 0;
    for (loop_ub = 0; loop_ub <= end_tmp; loop_ub++) {
      if (coeffIndex[loop_ub]) {
        ibcol++;
      }
    }
    r.set_size(&vd_emlrtRTEI, &sp, ibcol);
    ibcol = 0;
    for (loop_ub = 0; loop_ub <= end_tmp; loop_ub++) {
      if (coeffIndex[loop_ub]) {
        r[ibcol] = loop_ub;
        ibcol++;
      }
    }
    coeffCell[0].f1.set_size(&wd_emlrtRTEI, &sp, r.size(0), 3);
    loop_ub = r.size(0);
    for (int32_T i{0}; i < 3; i++) {
      for (ibcol = 0; ibcol < loop_ub; ibcol++) {
        if (r[ibcol] > coeffMat.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(r[ibcol], 0, coeffMat.size(0) - 1,
                                        &mc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        coeffCell[0].f1[ibcol + coeffCell[0].f1.size(0) * i] =
            coeffMat[r[ibcol] + coeffMat.size(0) * i];
      }
    }
    breaksCell[0].f1.set_size(&xd_emlrtRTEI, &sp, 1, breakMat.size(1));
    loop_ub = breakMat.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      breaksCell[0].f1[i] = breakMat[3 * i];
    }
    st.site = &kg_emlrtRSI;
    b_st.site = &bg_emlrtRSI;
    if (muDoubleScalarIsInf(varargin_1_tmp)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &p_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
          "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
    }
    if (b) {
      b_y = nullptr;
      m = emlrtCreateCharArray(2, &iv1[0]);
      emlrtInitCharArrayR2013a(&st, 15, m, &u[0]);
      emlrtAssign(&b_y, m);
      b_st.site = &th_emlrtRSI;
      b_error(b_st, b_y, b_emlrtMCI);
    }
    coeffIndex.set_size(&ed_emlrtRTEI, &st, outsize_idx_0_tmp);
    b_st.site = &lg_emlrtRSI;
    if (static_cast<int32_T>(varargin_1_tmp) > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (loop_ub = 0; loop_ub < ntilerows_tmp; loop_ub++) {
      ibcol = loop_ub * 3;
      coeffIndex[ibcol] = false;
      coeffIndex[ibcol + 1] = true;
      coeffIndex[ibcol + 2] = false;
    }
    ibcol = 0;
    for (loop_ub = 0; loop_ub <= end_tmp; loop_ub++) {
      if (coeffIndex[loop_ub]) {
        ibcol++;
      }
    }
    r1.set_size(&vd_emlrtRTEI, &sp, ibcol);
    ibcol = 0;
    for (loop_ub = 0; loop_ub <= end_tmp; loop_ub++) {
      if (coeffIndex[loop_ub]) {
        r1[ibcol] = loop_ub;
        ibcol++;
      }
    }
    coeffCell[1].f1.set_size(&wd_emlrtRTEI, &sp, r1.size(0), 3);
    loop_ub = r1.size(0);
    for (int32_T i{0}; i < 3; i++) {
      for (ibcol = 0; ibcol < loop_ub; ibcol++) {
        if (r1[ibcol] > coeffMat.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(r1[ibcol], 0, coeffMat.size(0) - 1,
                                        &mc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        coeffCell[1].f1[ibcol + coeffCell[1].f1.size(0) * i] =
            coeffMat[r1[ibcol] + coeffMat.size(0) * i];
      }
    }
    breaksCell[1].f1.set_size(&xd_emlrtRTEI, &sp, 1, breakMat.size(1));
    loop_ub = breakMat.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      breaksCell[1].f1[i] = breakMat[3 * i + 1];
    }
    st.site = &kg_emlrtRSI;
    b_st.site = &bg_emlrtRSI;
    if (muDoubleScalarIsInf(varargin_1_tmp)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &p_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
          "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
    }
    if (b) {
      c_y = nullptr;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(&st, 15, m, &u[0]);
      emlrtAssign(&c_y, m);
      b_st.site = &th_emlrtRSI;
      b_error(b_st, c_y, b_emlrtMCI);
    }
    coeffIndex.set_size(&ed_emlrtRTEI, &st, outsize_idx_0_tmp);
    b_st.site = &lg_emlrtRSI;
    if (static_cast<int32_T>(varargin_1_tmp) > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (loop_ub = 0; loop_ub < ntilerows_tmp; loop_ub++) {
      ibcol = loop_ub * 3;
      coeffIndex[ibcol] = false;
      coeffIndex[ibcol + 1] = false;
      coeffIndex[ibcol + 2] = true;
    }
    ibcol = 0;
    for (loop_ub = 0; loop_ub <= end_tmp; loop_ub++) {
      if (coeffIndex[loop_ub]) {
        ibcol++;
      }
    }
    r2.set_size(&vd_emlrtRTEI, &sp, ibcol);
    ibcol = 0;
    for (loop_ub = 0; loop_ub <= end_tmp; loop_ub++) {
      if (coeffIndex[loop_ub]) {
        r2[ibcol] = loop_ub;
        ibcol++;
      }
    }
    coeffCell[2].f1.set_size(&wd_emlrtRTEI, &sp, r2.size(0), 3);
    loop_ub = r2.size(0);
    for (int32_T i{0}; i < 3; i++) {
      for (ibcol = 0; ibcol < loop_ub; ibcol++) {
        if (r2[ibcol] > coeffMat.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(r2[ibcol], 0, coeffMat.size(0) - 1,
                                        &mc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        coeffCell[2].f1[ibcol + coeffCell[2].f1.size(0) * i] =
            coeffMat[r2[ibcol] + coeffMat.size(0) * i];
      }
    }
    breaksCell[2].f1.set_size(&xd_emlrtRTEI, &sp, 1, breakMat.size(1));
    loop_ub = breakMat.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      breaksCell[2].f1[i] = breakMat[3 * i + 2];
    }
  } else {
    int32_T ibcol;
    int32_T loop_ub;
    coeffCell[0].f1.set_size(&td_emlrtRTEI, &sp, coeffMat.size(0), 3);
    ibcol = coeffMat.size(0) * 3;
    for (int32_T i{0}; i < ibcol; i++) {
      coeffCell[0].f1[i] = coeffMat[i];
    }
    breaksCell[0].f1.set_size(&ud_emlrtRTEI, &sp, 1, breakMat.size(1));
    loop_ub = breakMat.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      breaksCell[0].f1[i] = breakMat[3 * i];
    }
    coeffCell[1].f1.set_size(&td_emlrtRTEI, &sp, coeffMat.size(0), 3);
    for (int32_T i{0}; i < ibcol; i++) {
      coeffCell[1].f1[i] = coeffMat[i];
    }
    breaksCell[1].f1.set_size(&ud_emlrtRTEI, &sp, 1, breakMat.size(1));
    loop_ub = breakMat.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      breaksCell[1].f1[i] = breakMat[3 * i];
    }
    coeffCell[2].f1.set_size(&td_emlrtRTEI, &sp, coeffMat.size(0), 3);
    for (int32_T i{0}; i < ibcol; i++) {
      coeffCell[2].f1[i] = coeffMat[i];
    }
    breaksCell[2].f1.set_size(&ud_emlrtRTEI, &sp, 1, breakMat.size(1));
    loop_ub = breakMat.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      breaksCell[2].f1[i] = breakMat[3 * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void reformatInput(const emlrtStack &sp,
                          const ::coder::array<real_T, 2U> &input, real_T p,
                          ::coder::array<real_T, 2U> &matrixInput)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T ibtile;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  matrixInput.set_size(&ld_emlrtRTEI, &sp, 3, input.size(1));
  ibtile = 3 * input.size(1);
  for (i = 0; i < ibtile; i++) {
    matrixInput[i] = input[i];
  }
  if (input.size(1) == 1) {
    st.site = &ag_emlrtRSI;
    b_st.site = &bg_emlrtRSI;
    if ((p - 1.0 != p - 1.0) || muDoubleScalarIsInf(p - 1.0) ||
        (p - 1.0 > 2.147483647E+9)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &p_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
          "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
    }
    i = static_cast<int32_T>(p - 1.0);
    matrixInput.set_size(&ed_emlrtRTEI, &st, 3, i);
    b_st.site = &cg_emlrtRSI;
    if (static_cast<int32_T>(p - 1.0) > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (int32_T jtilecol{0}; jtilecol < i; jtilecol++) {
      ibtile = jtilecol * 3 - 1;
      b_st.site = &sf_emlrtRSI;
      matrixInput[ibtile + 1] = input[0];
      matrixInput[ibtile + 2] = input[1];
      matrixInput[ibtile + 3] = input[2];
    }
  }
}

void trapveltraj(const emlrtStack &sp, real_T numSamples, real_T varargin_2,
                 real_T varargin_4, ::coder::array<real_T, 2U> &q,
                 ::coder::array<real_T, 2U> &qd,
                 ::coder::array<real_T, 2U> &qdd)
{
  ::coder::array<real_T, 2U> r3;
  ::coder::array<real_T, 2U> r4;
  ::coder::array<real_T, 2U> r5;
  ::coder::array<real_T, 2U> t;
  cell_wrap_10 breaksCell;
  cell_wrap_11 coeffsCell;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  struct_T b_expl_temp;
  struct_T c_expl_temp;
  struct_T expl_temp;
  real_T coefsWithFlatStart[12];
  real_T coefs[9];
  real_T breaksWithFlatStart[5];
  real_T newSegmentCoeffs[3];
  real_T holdPoint;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T coefsWithFlatStart_tmp;
  int32_T i;
  int32_T loop_ub_tmp;
  int8_T tmp_data[3];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &v_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsInf(numSamples) || muDoubleScalarIsNaN(numSamples)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trapveltraj:expectedFinite", 3, 4, 1, "m");
  }
  st.site = &w_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  st.site = &x_emlrtRSI;
  st.site = &y_emlrtRSI;
  st.site = &ab_emlrtRSI;
  st.site = &bb_emlrtRSI;
  st.site = &cb_emlrtRSI;
  st.site = &db_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  if (varargin_4 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:trapveltraj:expectedPositive", 3, 4, 7, "EndTime");
  }
  c_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_4) || muDoubleScalarIsNaN(varargin_4)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trapveltraj:expectedFinite", 3, 4, 7, "EndTime");
  }
  c_st.site = &ib_emlrtRSI;
  st.site = &eb_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  if (varargin_2 <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:trapveltraj:expectedPositive", 3, 4, 9, "AccelTime");
  }
  c_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsInf(varargin_2) || muDoubleScalarIsNaN(varargin_2)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trapveltraj:expectedFinite", 3, 4, 9, "AccelTime");
  }
  c_st.site = &ib_emlrtRSI;
  q.set_size(&sb_emlrtRTEI, &sp, 1, q.size(1));
  if (!(numSamples >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numSamples, &i_emlrtDCI, (emlrtConstCTX)&sp);
  }
  i = static_cast<int32_T>(muDoubleScalarFloor(numSamples));
  if (numSamples != i) {
    emlrtIntegerCheckR2012b(numSamples, &j_emlrtDCI, (emlrtConstCTX)&sp);
  }
  loop_ub_tmp = static_cast<int32_T>(numSamples);
  q.set_size(&sb_emlrtRTEI, &sp, q.size(0), loop_ub_tmp);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(numSamples, &k_emlrtDCI, (emlrtConstCTX)&sp);
  }
  for (coefsWithFlatStart_tmp = 0; coefsWithFlatStart_tmp < loop_ub_tmp;
       coefsWithFlatStart_tmp++) {
    q[coefsWithFlatStart_tmp] = 0.0;
  }
  qd.set_size(&tb_emlrtRTEI, &sp, 1, qd.size(1));
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(numSamples, &h_emlrtDCI, (emlrtConstCTX)&sp);
  }
  qd.set_size(&tb_emlrtRTEI, &sp, qd.size(0), loop_ub_tmp);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(numSamples, &l_emlrtDCI, (emlrtConstCTX)&sp);
  }
  for (coefsWithFlatStart_tmp = 0; coefsWithFlatStart_tmp < loop_ub_tmp;
       coefsWithFlatStart_tmp++) {
    qd[coefsWithFlatStart_tmp] = 0.0;
  }
  qdd.set_size(&ub_emlrtRTEI, &sp, 1, qdd.size(1));
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(numSamples, &g_emlrtDCI, (emlrtConstCTX)&sp);
  }
  qdd.set_size(&ub_emlrtRTEI, &sp, qdd.size(0), loop_ub_tmp);
  if (loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(numSamples, &m_emlrtDCI, (emlrtConstCTX)&sp);
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    qdd[i] = 0.0;
  }
  std::memset(&coeffsCell.f1[0], 0, 9U * sizeof(real_T));
  st.site = &fb_emlrtRSI;
  holdPoint = 1.0 / (varargin_4 - varargin_2);
  if (!(1.0 / varargin_4 < holdPoint)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &g_emlrtRTEI,
        "shared_robotics:robotcore:utils:TrapVelLowerBoundCondition",
        "shared_robotics:robotcore:utils:TrapVelLowerBoundCondition", 6, 6, 1.0,
        6, 1.0, 6, 2.0);
  }
  if (!(holdPoint <= 2.0 / varargin_4)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI,
        "shared_robotics:robotcore:utils:TrapVelUpperBoundCondition",
        "shared_robotics:robotcore:utils:TrapVelUpperBoundCondition", 6, 6, 1.0,
        6, 1.0, 6, 2.0);
  }
  st.site = &gb_emlrtRSI;
  computeScalarLSPBCoefficients(0.0, 1.0, holdPoint, holdPoint / varargin_2,
                                varargin_2, varargin_4, coefs, breaksCell.f1);
  tmp_data[0] = 0;
  tmp_data[1] = 1;
  tmp_data[2] = 2;
  iv[0] = 3;
  iv[1] = 3;
  iv1[0] = 3;
  iv1[1] = 3;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &g_emlrtECI,
                                (emlrtCTX)&sp);
  for (i = 0; i < 3; i++) {
    for (coefsWithFlatStart_tmp = 0; coefsWithFlatStart_tmp < 3;
         coefsWithFlatStart_tmp++) {
      coeffsCell.f1[tmp_data[coefsWithFlatStart_tmp] + 3 * i] =
          coefs[coefsWithFlatStart_tmp + 3 * i];
    }
  }
  st.site = &sh_emlrtRSI;
  linspace(st, sumColumnB(varargin_4), numSamples, t);
  st.site = &hb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  newSegmentCoeffs[0] = 0.0;
  newSegmentCoeffs[1] = 0.0;
  newSegmentCoeffs[2] =
      (coeffsCell.f1[0] * 0.0 + coeffsCell.f1[3] * 0.0) + coeffsCell.f1[6];
  std::memset(&coefsWithFlatStart[0], 0, 12U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    coefsWithFlatStart_tmp = i << 2;
    coefsWithFlatStart[coefsWithFlatStart_tmp] = newSegmentCoeffs[i];
    coefsWithFlatStart[coefsWithFlatStart_tmp + 1] = coeffsCell.f1[3 * i];
    coefsWithFlatStart[coefsWithFlatStart_tmp + 2] = coeffsCell.f1[3 * i + 1];
    coefsWithFlatStart[coefsWithFlatStart_tmp + 3] = coeffsCell.f1[3 * i + 2];
  }
  real_T evalPointVector_idx_0;
  real_T evalPointVector_idx_1;
  breaksWithFlatStart[0] = breaksCell.f1[0] - 1.0;
  breaksWithFlatStart[1] = breaksCell.f1[0];
  breaksWithFlatStart[2] = breaksCell.f1[1];
  breaksWithFlatStart[3] = breaksCell.f1[2];
  breaksWithFlatStart[4] = breaksCell.f1[3];
  c_st.site = &ub_emlrtRSI;
  holdPoint = breaksCell.f1[3] - breaksCell.f1[2];
  d_st.site = &vb_emlrtRSI;
  evalPointVector_idx_0 = mpower(d_st, holdPoint, 2.0);
  d_st.site = &vb_emlrtRSI;
  evalPointVector_idx_1 = mpower(d_st, holdPoint, 1.0);
  d_st.site = &vb_emlrtRSI;
  holdPoint = mpower(d_st, holdPoint, 0.0);
  newSegmentCoeffs[0] = 0.0;
  newSegmentCoeffs[1] = 0.0;
  newSegmentCoeffs[2] = (coefsWithFlatStart[3] * evalPointVector_idx_0 +
                         coefsWithFlatStart[7] * evalPointVector_idx_1) +
                        coefsWithFlatStart[11] * holdPoint;
  std::memset(&expl_temp.coefs[0], 0, 15U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    coefsWithFlatStart_tmp = i << 2;
    expl_temp.coefs[5 * i] = coefsWithFlatStart[coefsWithFlatStart_tmp];
    expl_temp.coefs[5 * i + 1] = coefsWithFlatStart[coefsWithFlatStart_tmp + 1];
    expl_temp.coefs[5 * i + 2] = coefsWithFlatStart[coefsWithFlatStart_tmp + 2];
    expl_temp.coefs[5 * i + 3] = coefsWithFlatStart[coefsWithFlatStart_tmp + 3];
    expl_temp.coefs[5 * i + 4] = newSegmentCoeffs[i];
  }
  for (i = 0; i < 5; i++) {
    expl_temp.breaks[i] = breaksWithFlatStart[i];
  }
  __m128d r;
  __m128d r1;
  __m128d r2;
  expl_temp.breaks[5] = breaksCell.f1[3] + 1.0;
  std::memset(&b_expl_temp.coefs[0], 0, 15U * sizeof(real_T));
  r = _mm_loadu_pd(&expl_temp.coefs[0]);
  r1 = _mm_set1_pd(2.0);
  _mm_storeu_pd(&b_expl_temp.coefs[5], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&expl_temp.coefs[2]);
  _mm_storeu_pd(&b_expl_temp.coefs[7], _mm_mul_pd(r1, r));
  b_expl_temp.coefs[9] = 2.0 * expl_temp.coefs[4];
  r = _mm_loadu_pd(&expl_temp.coefs[5]);
  r2 = _mm_set1_pd(1.0);
  _mm_storeu_pd(&b_expl_temp.coefs[10], _mm_mul_pd(r2, r));
  r = _mm_loadu_pd(&expl_temp.coefs[7]);
  _mm_storeu_pd(&b_expl_temp.coefs[12], _mm_mul_pd(r2, r));
  b_expl_temp.coefs[14] = expl_temp.coefs[9];
  std::memset(&c_expl_temp.coefs[0], 0, 15U * sizeof(real_T));
  r = _mm_loadu_pd(&b_expl_temp.coefs[0]);
  _mm_storeu_pd(&c_expl_temp.coefs[5], _mm_mul_pd(r1, r));
  r = _mm_loadu_pd(&b_expl_temp.coefs[2]);
  _mm_storeu_pd(&c_expl_temp.coefs[7], _mm_mul_pd(r1, r));
  c_expl_temp.coefs[9] = 2.0 * b_expl_temp.coefs[4];
  r = _mm_loadu_pd(&b_expl_temp.coefs[5]);
  _mm_storeu_pd(&c_expl_temp.coefs[10], _mm_mul_pd(r2, r));
  r = _mm_loadu_pd(&b_expl_temp.coefs[7]);
  _mm_storeu_pd(&c_expl_temp.coefs[12], _mm_mul_pd(r2, r));
  c_expl_temp.coefs[14] = b_expl_temp.coefs[9];
  b_st.site = &rb_emlrtRSI;
  ppval(b_st, expl_temp, t, r3);
  for (i = 0; i < 6; i++) {
    b_expl_temp.breaks[i] = expl_temp.breaks[i];
  }
  b_st.site = &sb_emlrtRSI;
  ppval(b_st, b_expl_temp, t, r4);
  for (i = 0; i < 6; i++) {
    c_expl_temp.breaks[i] = expl_temp.breaks[i];
  }
  b_st.site = &tb_emlrtRSI;
  ppval(b_st, c_expl_temp, t, r5);
  if (numSamples < 1.0) {
    coefsWithFlatStart_tmp = 0;
  } else {
    coefsWithFlatStart_tmp = loop_ub_tmp;
  }
  iv[0] = 1;
  iv[1] = coefsWithFlatStart_tmp;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r3.size(), 2, &e_emlrtECI,
                                (emlrtCTX)&sp);
  for (i = 0; i < coefsWithFlatStart_tmp; i++) {
    q[i] = r3[i];
  }
  if (numSamples < 1.0) {
    coefsWithFlatStart_tmp = 0;
  } else {
    coefsWithFlatStart_tmp = loop_ub_tmp;
  }
  iv[0] = 1;
  iv[1] = coefsWithFlatStart_tmp;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r4.size(), 2, &f_emlrtECI,
                                (emlrtCTX)&sp);
  for (i = 0; i < coefsWithFlatStart_tmp; i++) {
    qd[i] = r4[i];
  }
  if (numSamples < 1.0) {
    loop_ub_tmp = 0;
  }
  iv[0] = 1;
  iv[1] = loop_ub_tmp;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r5.size(), 2, &d_emlrtECI,
                                (emlrtCTX)&sp);
  for (i = 0; i < loop_ub_tmp; i++) {
    qdd[i] = r5[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void trapveltraj(const emlrtStack &sp,
                 const ::coder::array<real_T, 2U> &wayPoints, real_T numSamples,
                 const ::coder::array<real_T, 2U> &varargin_2,
                 const ::coder::array<real_T, 2U> &varargin_4,
                 ::coder::array<real_T, 2U> &q, ::coder::array<real_T, 2U> &qd,
                 ::coder::array<real_T, 2U> &qdd)
{
  ::coder::array<real_T, 3U> parameterMat;
  ::coder::array<real_T, 2U> breakMat;
  ::coder::array<real_T, 2U> coeffMat;
  ::coder::array<real_T, 2U> lspbSegIndices;
  ::coder::array<real_T, 2U> r3;
  ::coder::array<real_T, 2U> r4;
  ::coder::array<real_T, 2U> r5;
  ::coder::array<real_T, 2U> tAc;
  ::coder::array<real_T, 2U> tFi;
  ::coder::array<int32_T, 2U> r2;
  ::coder::array<int32_T, 1U> r6;
  ::coder::array<boolean_T, 1U> coefIndex;
  ::coder::bounded_array<d_struct_T, 3U, 1U> ppCell;
  cell_wrap_19 breaksCell[3];
  cell_wrap_30 coeffsCell[3];
  emlrtStack b_st;
  emlrtStack st;
  real_T bsum[3];
  real_T varargin_1[3];
  real_T d;
  real_T segATime;
  real_T segAcc;
  real_T segFTime;
  real_T segVel;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T firstBlockLength;
  int32_T hi;
  int32_T i;
  int32_T k;
  int32_T lastBlockLength;
  int32_T p;
  int32_T xoffset;
  int8_T unnamed_idx_0;
  boolean_T exitg1;
  boolean_T hasMultipleBreaks;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &tf_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (wayPoints.size(1) == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:trapveltraj:expectedNonempty", 3, 4, 9, "wayPoints");
  }
  b_st.site = &ib_emlrtRSI;
  hasMultipleBreaks = true;
  i = 3 * wayPoints.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(wayPoints[k])) &&
        (!muDoubleScalarIsNaN(wayPoints[k]))) {
      k++;
    } else {
      hasMultipleBreaks = false;
      exitg1 = true;
    }
  }
  if (!hasMultipleBreaks) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trapveltraj:expectedFinite", 3, 4, 9, "wayPoints");
  }
  st.site = &v_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  if (muDoubleScalarIsInf(numSamples) || muDoubleScalarIsNaN(numSamples)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:trapveltraj:expectedFinite", 3, 4, 1, "m");
  }
  p = wayPoints.size(1);
  st.site = &w_emlrtRSI;
  st.site = &x_emlrtRSI;
  st.site = &y_emlrtRSI;
  st.site = &ab_emlrtRSI;
  st.site = &bb_emlrtRSI;
  st.site = &cb_emlrtRSI;
  if (wayPoints.size(1) < 2) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &u_emlrtRTEI, "shared_robotics:robotcore:utils:WaypointsTooFew",
        "shared_robotics:robotcore:utils:WaypointsTooFew", 0);
  }
  st.site = &db_emlrtRSI;
  if (!isOptInputValid(st, static_cast<real_T>(wayPoints.size(1)),
                       varargin_4)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &v_emlrtRTEI,
        "shared_robotics:robotcore:utils:TrapVelOptInputSize",
        "shared_robotics:robotcore:utils:TrapVelOptInputSize", 3, 4, 7,
        "EndTime");
  }
  st.site = &eb_emlrtRSI;
  if (!b_isOptInputValid(st, static_cast<real_T>(wayPoints.size(1)),
                         varargin_2)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &w_emlrtRTEI,
        "shared_robotics:robotcore:utils:TrapVelOptInputSize",
        "shared_robotics:robotcore:utils:TrapVelOptInputSize", 3, 4, 9,
        "AccelTime");
  }
  st.site = &uf_emlrtRSI;
  reformatInput(st, varargin_4, static_cast<real_T>(wayPoints.size(1)), tFi);
  st.site = &vf_emlrtRSI;
  reformatInput(st, varargin_2, static_cast<real_T>(wayPoints.size(1)), tAc);
  q.set_size(&sb_emlrtRTEI, &sp, 3, static_cast<int32_T>(numSamples));
  firstBlockLength = 3 * static_cast<int32_T>(numSamples);
  for (i = 0; i < firstBlockLength; i++) {
    q[i] = 0.0;
  }
  qd.set_size(&tb_emlrtRTEI, &sp, 3, static_cast<int32_T>(numSamples));
  for (i = 0; i < firstBlockLength; i++) {
    qd[i] = 0.0;
  }
  qdd.set_size(&ub_emlrtRTEI, &sp, 3, static_cast<int32_T>(numSamples));
  for (i = 0; i < firstBlockLength; i++) {
    qdd[i] = 0.0;
  }
  parameterMat.set_size(&fd_emlrtRTEI, &sp, 3, wayPoints.size(1) - 1, 6);
  firstBlockLength = 3 * (wayPoints.size(1) - 1);
  xoffset = firstBlockLength * 6;
  for (i = 0; i < xoffset; i++) {
    parameterMat[i] = 0.0;
  }
  segAcc = 3.0 * (static_cast<real_T>(wayPoints.size(1)) - 1.0);
  d = segAcc * 3.0;
  if (d != static_cast<int32_T>(d)) {
    emlrtIntegerCheckR2012b(d, &n_emlrtDCI, (emlrtConstCTX)&sp);
  }
  xoffset = static_cast<int32_T>(d);
  coeffMat.set_size(&gd_emlrtRTEI, &sp, static_cast<int32_T>(d), 3);
  if (d != static_cast<int32_T>(d)) {
    emlrtIntegerCheckR2012b(d, &p_emlrtDCI, (emlrtConstCTX)&sp);
  }
  hi = static_cast<int32_T>(d) * 3;
  for (i = 0; i < hi; i++) {
    coeffMat[i] = 0.0;
  }
  breakMat.set_size(&hd_emlrtRTEI, &sp, 3, breakMat.size(1));
  if (segAcc + 1.0 != static_cast<int32_T>(segAcc + 1.0)) {
    emlrtIntegerCheckR2012b(segAcc + 1.0, &o_emlrtDCI, (emlrtConstCTX)&sp);
  }
  breakMat.set_size(&hd_emlrtRTEI, &sp, breakMat.size(0),
                    static_cast<int32_T>(segAcc + 1.0));
  if (segAcc + 1.0 != static_cast<int32_T>(segAcc + 1.0)) {
    emlrtIntegerCheckR2012b(segAcc + 1.0, &q_emlrtDCI, (emlrtConstCTX)&sp);
  }
  hi = 3 * static_cast<int32_T>(segAcc + 1.0);
  for (i = 0; i < hi; i++) {
    breakMat[i] = 0.0;
  }
  i = firstBlockLength * 3;
  iv[0] = 3;
  iv[1] = 3;
  for (int32_T b_i{0}; b_i < 3; b_i++) {
    for (k = 0; k <= p - 2; k++) {
      real_T coefs[9];
      real_T breaks[4];
      real_T b_parameterMat_tmp;
      real_T parameterMat_tmp;
      st.site = &fb_emlrtRSI;
      segVel = computeProfileParams(st, static_cast<real_T>(b_i) + 1.0,
                                    static_cast<real_T>(k) + 1.0, wayPoints,
                                    tFi, tAc, segAcc, segATime, segFTime);
      if (k + 1 > parameterMat.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, parameterMat.size(1),
                                      &ob_emlrtBCI, (emlrtConstCTX)&sp);
      }
      if (k + 1 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, wayPoints.size(1), &tb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      parameterMat_tmp = wayPoints[b_i + 3 * k];
      parameterMat[b_i + 3 * k] = parameterMat_tmp;
      if (k + 2 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 2, 1, wayPoints.size(1), &tb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_parameterMat_tmp = wayPoints[b_i + 3 * (k + 1)];
      parameterMat[(b_i + 3 * k) + 3 * parameterMat.size(1)] =
          b_parameterMat_tmp;
      parameterMat[(b_i + 3 * k) + 3 * parameterMat.size(1) * 2] = segVel;
      parameterMat[(b_i + 3 * k) + 3 * parameterMat.size(1) * 3] = segAcc;
      parameterMat[(b_i + 3 * k) + 3 * parameterMat.size(1) * 4] = segATime;
      parameterMat[(b_i + 3 * k) + 3 * parameterMat.size(1) * 5] = segFTime;
      if (k + 1 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, wayPoints.size(1), &ub_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if (k + 2 > wayPoints.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 2, 1, wayPoints.size(1), &vb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      st.site = &gb_emlrtRSI;
      computeScalarLSPBCoefficients(parameterMat_tmp, b_parameterMat_tmp,
                                    segVel, segAcc, segATime, segFTime, coefs,
                                    breaks);
      if (d != static_cast<int32_T>(d)) {
        emlrtIntegerCheckR2012b(d, &r_emlrtDCI, (emlrtConstCTX)&sp);
      }
      coefIndex.set_size(&id_emlrtRTEI, &sp, static_cast<int32_T>(d));
      if (d != static_cast<int32_T>(d)) {
        emlrtIntegerCheckR2012b(d, &r_emlrtDCI, (emlrtConstCTX)&sp);
      }
      for (int32_T i1{0}; i1 < xoffset; i1++) {
        coefIndex[i1] = false;
      }
      st.site = &wf_emlrtRSI;
      segVel = 3.0 * ((static_cast<real_T>(k) + 1.0) - 1.0) * 3.0 +
               (static_cast<real_T>(b_i) + 1.0);
      if (segVel + 6.0 < segVel) {
        lspbSegIndices.set_size(&jd_emlrtRTEI, &st, 1, 0);
      } else {
        hi = static_cast<int32_T>(((segVel + 6.0) - segVel) / 3.0);
        lspbSegIndices.set_size(&jd_emlrtRTEI, &st, 1, hi + 1);
        for (int32_T i1{0}; i1 <= hi; i1++) {
          lspbSegIndices[i1] = segVel + 3.0 * static_cast<real_T>(i1);
        }
      }
      r2.set_size(&kd_emlrtRTEI, &sp, 1, lspbSegIndices.size(1));
      hi = lspbSegIndices.size(1);
      for (int32_T i1{0}; i1 < hi; i1++) {
        firstBlockLength = static_cast<int32_T>(lspbSegIndices[i1]);
        if (lspbSegIndices[i1] != firstBlockLength) {
          emlrtIntegerCheckR2012b(lspbSegIndices[i1], &s_emlrtDCI,
                                  (emlrtConstCTX)&sp);
        }
        if ((firstBlockLength < 1) || (firstBlockLength > i)) {
          emlrtDynamicBoundsCheckR2012b(firstBlockLength, 1, i, &wb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        r2[i1] = firstBlockLength;
      }
      hi = r2.size(1);
      for (int32_T i1{0}; i1 < hi; i1++) {
        coefIndex[r2[i1] - 1] = true;
      }
      hi = coefIndex.size(0) - 1;
      firstBlockLength = 0;
      for (lastBlockLength = 0; lastBlockLength <= hi; lastBlockLength++) {
        if (coefIndex[lastBlockLength]) {
          firstBlockLength++;
        }
      }
      r6.set_size(&vb_emlrtRTEI, &sp, firstBlockLength);
      firstBlockLength = 0;
      for (lastBlockLength = 0; lastBlockLength <= hi; lastBlockLength++) {
        if (coefIndex[lastBlockLength]) {
          if (lastBlockLength > coeffMat.size(0) - 1) {
            emlrtDynamicBoundsCheckR2012b(lastBlockLength, 0,
                                          coeffMat.size(0) - 1, &sb_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          r6[firstBlockLength] = lastBlockLength;
          firstBlockLength++;
        }
      }
      iv1[0] = r6.size(0);
      iv1[1] = 3;
      emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, &iv[0], 2, &g_emlrtECI,
                                    (emlrtCTX)&sp);
      iv1[0] = r6.size(0);
      hi = r6.size(0);
      for (int32_T i1{0}; i1 < 3; i1++) {
        for (firstBlockLength = 0; firstBlockLength < hi; firstBlockLength++) {
          coeffMat[r6[firstBlockLength] + coeffMat.size(0) * i1] =
              coefs[firstBlockLength + iv1[0] * i1];
        }
      }
      segAcc = 3.0 * (static_cast<real_T>(k) + 1.0) - 2.0;
      hasMultipleBreaks = ((static_cast<int32_T>(segAcc) < 1) ||
                           (static_cast<int32_T>(segAcc) > breakMat.size(1)));
      if (hasMultipleBreaks) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(segAcc), 1,
                                      breakMat.size(1), &xb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      segVel = breakMat[b_i + 3 * (static_cast<int32_T>(segAcc) - 1)];
      breakMat[b_i + 3 * (static_cast<int32_T>(segAcc) - 1)] =
          breaks[0] + segVel;
      if ((static_cast<int32_T>(segAcc + 1.0) < 1) ||
          (static_cast<int32_T>(segAcc + 1.0) > breakMat.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(segAcc + 1.0), 1,
                                      breakMat.size(1), &ac_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      breakMat[b_i + 3 * (static_cast<int32_T>(segAcc + 1.0) - 1)] =
          breaks[1] + segVel;
      if ((static_cast<int32_T>(segAcc + 2.0) < 1) ||
          (static_cast<int32_T>(segAcc + 2.0) > breakMat.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(segAcc + 2.0), 1,
                                      breakMat.size(1), &ac_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      breakMat[b_i + 3 * (static_cast<int32_T>(segAcc + 2.0) - 1)] =
          breaks[2] + segVel;
      if ((static_cast<int32_T>(segAcc + 3.0) < 1) ||
          (static_cast<int32_T>(segAcc + 3.0) > breakMat.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(segAcc + 3.0), 1,
                                      breakMat.size(1), &ac_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      breakMat[b_i + 3 * (static_cast<int32_T>(segAcc + 3.0) - 1)] =
          breaks[3] + segVel;
    }
  }
  st.site = &xf_emlrtRSI;
  hasMultipleBreaks = checkPolyForMultipleBreaks(st, breakMat);
  st.site = &yf_emlrtRSI;
  processPolynomialResults(st, breakMat, coeffMat, hasMultipleBreaks,
                           static_cast<real_T>(wayPoints.size(1)), breaksCell,
                           coeffsCell);
  if (parameterMat.size(1) <= 1024) {
    firstBlockLength = parameterMat.size(1);
    lastBlockLength = 0;
    p = 1;
  } else {
    firstBlockLength = 1024;
    p = static_cast<int32_T>(static_cast<uint32_T>(parameterMat.size(1)) >> 10);
    lastBlockLength = parameterMat.size(1) - (p << 10);
    if (lastBlockLength > 0) {
      p++;
    } else {
      lastBlockLength = 1024;
    }
  }
  varargin_1[0] = parameterMat[3 * parameterMat.size(1) * 5];
  varargin_1[1] = parameterMat[3 * parameterMat.size(1) * 5 + 1];
  varargin_1[2] = parameterMat[3 * parameterMat.size(1) * 5 + 2];
  for (k = 2; k <= firstBlockLength; k++) {
    xoffset = (k - 1) * 3;
    varargin_1[0] += parameterMat[(xoffset % 3 + 3 * (xoffset / 3)) +
                                  3 * parameterMat.size(1) * 5];
    varargin_1[1] +=
        parameterMat[((xoffset + 1) % 3 + 3 * ((xoffset + 1) / 3)) +
                     3 * parameterMat.size(1) * 5];
    varargin_1[2] +=
        parameterMat[((xoffset + 2) % 3 + 3 * ((xoffset + 2) / 3)) +
                     3 * parameterMat.size(1) * 5];
  }
  for (int32_T b_i{2}; b_i <= p; b_i++) {
    firstBlockLength = (b_i - 1) * 3072;
    bsum[0] = parameterMat[(firstBlockLength % 3 + 3 * (firstBlockLength / 3)) +
                           3 * parameterMat.size(1) * 5];
    bsum[1] = parameterMat[((firstBlockLength + 1) % 3 +
                            3 * ((firstBlockLength + 1) / 3)) +
                           3 * parameterMat.size(1) * 5];
    bsum[2] = parameterMat[((firstBlockLength + 2) % 3 +
                            3 * ((firstBlockLength + 2) / 3)) +
                           3 * parameterMat.size(1) * 5];
    if (b_i == p) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }
    for (k = 2; k <= hi; k++) {
      xoffset = firstBlockLength + (k - 1) * 3;
      bsum[0] += parameterMat[(xoffset % 3 + 3 * (xoffset / 3)) +
                              3 * parameterMat.size(1) * 5];
      bsum[1] += parameterMat[((xoffset + 1) % 3 + 3 * ((xoffset + 1) / 3)) +
                              3 * parameterMat.size(1) * 5];
      bsum[2] += parameterMat[((xoffset + 2) % 3 + 3 * ((xoffset + 2) / 3)) +
                              3 * parameterMat.size(1) * 5];
    }
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&varargin_1[0]);
    r1 = _mm_loadu_pd(&bsum[0]);
    _mm_storeu_pd(&varargin_1[0], _mm_add_pd(r, r1));
    varargin_1[2] += bsum[2];
  }
  if (!muDoubleScalarIsNaN(varargin_1[0])) {
    firstBlockLength = 1;
  } else {
    firstBlockLength = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
        firstBlockLength = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (firstBlockLength == 0) {
    segVel = varargin_1[0];
  } else {
    segVel = varargin_1[firstBlockLength - 1];
    i = firstBlockLength + 1;
    for (k = i; k < 4; k++) {
      segAcc = varargin_1[k - 1];
      if (segVel < segAcc) {
        segVel = segAcc;
      }
    }
  }
  st.site = &sh_emlrtRSI;
  linspace(st, segVel, numSamples, lspbSegIndices);
  if (hasMultipleBreaks) {
    hi = 3;
    p = 1;
  } else {
    hi = 1;
    p = 3;
  }
  unnamed_idx_0 = static_cast<int8_T>(hi);
  ppCell.size[0] = hi;
  for (i = 0; i < unnamed_idx_0; i++) {
    if (i > ppCell.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, ppCell.size[0] - 1, &rb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    ppCell.data[i].breaks.set_size(&vb_emlrtRTEI, &sp, 1, 0);
    ppCell.data[i].coefs.set_size(&vb_emlrtRTEI, &sp, 0, 0, 3);
  }
  ppCell.size[0] = hi;
  for (int32_T b_i{0}; b_i < hi; b_i++) {
    int8_T rowSelection_data[3];
    int8_T tmp_data[3];
    if (hasMultipleBreaks) {
      lastBlockLength = 1;
      rowSelection_data[0] = static_cast<int8_T>(b_i + 1);
      firstBlockLength = b_i;
    } else {
      lastBlockLength = 3;
      rowSelection_data[0] = 1;
      rowSelection_data[1] = 2;
      rowSelection_data[2] = 3;
      firstBlockLength = 0;
    }
    if (b_i > ppCell.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, ppCell.size[0] - 1, &yb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    st.site = &hb_emlrtRSI;
    generateTrajectoriesFromCoefs(
        st, breaksCell[firstBlockLength].f1, coeffsCell[firstBlockLength].f1,
        static_cast<real_T>(p), lspbSegIndices, r3, r4, r5,
        ppCell.data[b_i].breaks, ppCell.data[b_i].coefs);
    if (numSamples < 1.0) {
      xoffset = 0;
    } else {
      if (q.size(1) < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, q.size(1), &o_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((static_cast<int32_T>(numSamples) < 1) ||
          (static_cast<int32_T>(numSamples) > q.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numSamples), 1,
                                      q.size(1), &n_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      xoffset = static_cast<int32_T>(numSamples);
    }
    for (i = 0; i < lastBlockLength; i++) {
      tmp_data[i] = static_cast<int8_T>(rowSelection_data[i] - 1);
    }
    iv1[0] = lastBlockLength;
    iv1[1] = xoffset;
    emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, r3.size(), 2, &e_emlrtECI,
                                  (emlrtCTX)&sp);
    for (i = 0; i < xoffset; i++) {
      for (int32_T i1{0}; i1 < lastBlockLength; i1++) {
        q[tmp_data[i1] + 3 * i] = r3[i1 + lastBlockLength * i];
      }
    }
    if (numSamples < 1.0) {
      xoffset = 0;
    } else {
      if (qd.size(1) < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, qd.size(1), &pb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((static_cast<int32_T>(numSamples) < 1) ||
          (static_cast<int32_T>(numSamples) > qd.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numSamples), 1,
                                      qd.size(1), &p_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      xoffset = static_cast<int32_T>(numSamples);
    }
    iv1[0] = lastBlockLength;
    iv1[1] = xoffset;
    emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, r4.size(), 2, &f_emlrtECI,
                                  (emlrtCTX)&sp);
    for (i = 0; i < xoffset; i++) {
      for (int32_T i1{0}; i1 < lastBlockLength; i1++) {
        qd[tmp_data[i1] + 3 * i] = r4[i1 + lastBlockLength * i];
      }
    }
    if (numSamples < 1.0) {
      xoffset = 0;
    } else {
      if (qdd.size(1) < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, qdd.size(1), &qb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      if ((static_cast<int32_T>(numSamples) < 1) ||
          (static_cast<int32_T>(numSamples) > qdd.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numSamples), 1,
                                      qdd.size(1), &m_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      xoffset = static_cast<int32_T>(numSamples);
    }
    iv1[0] = lastBlockLength;
    iv1[1] = xoffset;
    emlrtSubAssignSizeCheckR2012b(&iv1[0], 2, r5.size(), 2, &d_emlrtECI,
                                  (emlrtCTX)&sp);
    for (i = 0; i < xoffset; i++) {
      for (int32_T i1{0}; i1 < lastBlockLength; i1++) {
        qdd[tmp_data[i1] + 3 * i] = r5[i1 + lastBlockLength * i];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (trapveltraj.cpp)
