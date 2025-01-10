//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ppval.cpp
//
// Code generation for function 'ppval'
//

// Include files
#include "ppval.h"
#include "bsearch.h"
#include "eml_int_forloop_overflow_check.h"
#include "orientationTrajectory_mex_data.h"
#include "orientationTrajectory_mex_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo wb_emlrtRSI{
    85,                                                               // lineNo
    "ppval",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/ppval.m" // pathName
};

static emlrtRSInfo ch_emlrtRSI{
    95,                                                               // lineNo
    "ppval",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/ppval.m" // pathName
};

static emlrtRSInfo dh_emlrtRSI{
    100,                                                              // lineNo
    "ppval",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/ppval.m" // pathName
};

static emlrtRSInfo eh_emlrtRSI{
    107,                                                              // lineNo
    "ppval",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/ppval.m" // pathName
};

static emlrtRSInfo fh_emlrtRSI{
    112,                                                              // lineNo
    "ppval",                                                          // fcnName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/ppval.m" // pathName
};

static emlrtRTEInfo xb_emlrtRTEI{
    48,                                                               // lineNo
    24,                                                               // colNo
    "ppval",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/ppval.m" // pName
};

static emlrtRTEInfo ne_emlrtRTEI{
    77,                                                               // lineNo
    24,                                                               // colNo
    "ppval",                                                          // fName
    "/usr/local/MATLAB/R2023b/toolbox/eml/lib/matlab/polyfun/ppval.m" // pName
};

// Function Definitions
namespace trajectoryGeneration {
namespace coder {
void b_ppval(const emlrtStack &sp, const ::coder::array<real_T, 2U> &pp_breaks,
             const ::coder::array<real_T, 3U> &pp_coefs,
             const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T coefStride;
  int32_T nx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  coefStride = 3 * (pp_breaks.size(1) - 1);
  v.set_size(&ne_emlrtRTEI, &sp, 3, x.size(1));
  nx = x.size(1);
  st.site = &ch_emlrtRSI;
  if (x.size(1) > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T ix{0}; ix < nx; ix++) {
    real_T xloc;
    int32_T iv0;
    iv0 = ix * 3;
    xloc = x[ix];
    if (muDoubleScalarIsNaN(xloc)) {
      v[iv0] = x[ix];
      v[iv0 + 1] = x[ix];
      v[iv0 + 2] = x[ix];
    } else {
      int32_T icp;
      int32_T ip;
      ip = internal::b_bsearch(pp_breaks, xloc) - 1;
      icp = ip * 3;
      xloc -= pp_breaks[ip];
      v[iv0] = pp_coefs[icp];
      v[iv0 + 1] = pp_coefs[icp + 1];
      v[iv0 + 2] = pp_coefs[icp + 2];
      for (int32_T ic{0}; ic < 5; ic++) {
        __m128d r;
        __m128d r1;
        ip = icp + (ic + 1) * coefStride;
        r = _mm_loadu_pd(&v[iv0]);
        r1 = _mm_loadu_pd(&pp_coefs[ip]);
        _mm_storeu_pd(&v[iv0],
                      _mm_add_pd(_mm_mul_pd(_mm_set1_pd(xloc), r), r1));
        v[iv0 + 2] = xloc * v[iv0 + 2] + pp_coefs[ip + 2];
      }
    }
  }
}

void ppval(const emlrtStack &sp, const struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T xloc;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T ppval_numThreads;
  int32_T ub_loop;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  v.set_size(&xb_emlrtRTEI, &sp, 1, x.size(1));
  st.site = &wb_emlrtRSI;
  if (x.size(1) > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  ub_loop = x.size(1) - 1;
  emlrtEnterParallelRegion((emlrtCTX)&sp,
                           static_cast<boolean_T>(omp_in_parallel()));
  ppval_numThreads =
      emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                           omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(ppval_numThreads) private(                \
    low_i, xloc, low_ip1, high_i, mid_i)

  for (int32_T ix = 0; ix <= ub_loop; ix++) {
    if (muDoubleScalarIsNaN(x[ix])) {
      xloc = rtNaN;
    } else {
      low_i = 0;
      low_ip1 = 2;
      high_i = 6;
      while (high_i > low_ip1) {
        mid_i = ((low_i + high_i) + 1) >> 1;
        if (x[ix] >= pp.breaks[mid_i - 1]) {
          low_i = mid_i - 1;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      xloc = x[ix] - pp.breaks[low_i];
      xloc = xloc * (xloc * pp.coefs[low_i] + pp.coefs[low_i + 5]) +
             pp.coefs[low_i + 10];
    }
    v[ix] = xloc;
  }
  emlrtExitParallelRegion((emlrtCTX)&sp,
                          static_cast<boolean_T>(omp_in_parallel()));
}

void ppval(const emlrtStack &sp, const b_struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T xloc;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T ppval_numThreads;
  int32_T ub_loop;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  v.set_size(&xb_emlrtRTEI, &sp, 1, x.size(1));
  st.site = &wb_emlrtRSI;
  if (x.size(1) > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  ub_loop = x.size(1) - 1;
  emlrtEnterParallelRegion((emlrtCTX)&sp,
                           static_cast<boolean_T>(omp_in_parallel()));
  ppval_numThreads =
      emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                           omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(ppval_numThreads) private(                \
    low_i, xloc, low_ip1, high_i, mid_i)

  for (int32_T ix = 0; ix <= ub_loop; ix++) {
    if (muDoubleScalarIsNaN(x[ix])) {
      xloc = rtNaN;
    } else {
      low_i = 0;
      low_ip1 = 2;
      high_i = 4;
      while (high_i > low_ip1) {
        mid_i = ((low_i + high_i) + 1) >> 1;
        if (x[ix] >= pp.breaks[mid_i - 1]) {
          low_i = mid_i - 1;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      xloc = x[ix] - pp.breaks[low_i];
      xloc = xloc * (xloc * (xloc * pp.coefs[low_i] + pp.coefs[low_i + 3]) +
                     pp.coefs[low_i + 6]) +
             pp.coefs[low_i + 9];
    }
    v[ix] = xloc;
  }
  emlrtExitParallelRegion((emlrtCTX)&sp,
                          static_cast<boolean_T>(omp_in_parallel()));
}

void ppval(const emlrtStack &sp, const c_struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_v;
  real_T xloc;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T ppval_numThreads;
  int32_T ub_loop;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  v.set_size(&xb_emlrtRTEI, &sp, 1, x.size(1));
  st.site = &wb_emlrtRSI;
  if (x.size(1) > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  ub_loop = x.size(1) - 1;
  emlrtEnterParallelRegion((emlrtCTX)&sp,
                           static_cast<boolean_T>(omp_in_parallel()));
  ppval_numThreads =
      emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                           omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(ppval_numThreads) private(                \
    low_i, b_v, low_ip1, high_i, xloc, mid_i)

  for (int32_T ix = 0; ix <= ub_loop; ix++) {
    if (muDoubleScalarIsNaN(x[ix])) {
      b_v = rtNaN;
    } else {
      low_i = 0;
      low_ip1 = 2;
      high_i = 4;
      while (high_i > low_ip1) {
        mid_i = ((low_i + high_i) + 1) >> 1;
        if (x[ix] >= pp.breaks[mid_i - 1]) {
          low_i = mid_i - 1;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      xloc = x[ix] - pp.breaks[low_i];
      b_v = pp.coefs[low_i];
      for (low_ip1 = 0; low_ip1 < 5; low_ip1++) {
        b_v = xloc * b_v + pp.coefs[low_i + (low_ip1 + 1) * 3];
      }
    }
    v[ix] = b_v;
  }
  emlrtExitParallelRegion((emlrtCTX)&sp,
                          static_cast<boolean_T>(omp_in_parallel()));
}

void ppval(const emlrtStack &sp, const d_struct_T &pp,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_v;
  real_T b_xloc;
  int32_T b_ip;
  int32_T coefStride;
  int32_T elementsPerPage;
  int32_T nx;
  int32_T ppval_numThreads;
  uint32_T szv_idx_0;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  elementsPerPage = pp.coefs.size(0);
  coefStride = pp.coefs.size(0) * (pp.breaks.size(1) - 1);
  szv_idx_0 = static_cast<uint32_T>(pp.coefs.size(0));
  v.set_size(&ne_emlrtRTEI, &sp, static_cast<int32_T>(szv_idx_0), x.size(1));
  nx = x.size(1);
  if (pp.coefs.size(0) == 1) {
    int32_T ip;
    st.site = &wb_emlrtRSI;
    if (x.size(1) > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    ip = x.size(1) - 1;
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    ppval_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(ppval_numThreads) private(b_xloc, b_ip,   \
                                                               b_v)

    for (int32_T b_ix = 0; b_ix <= ip; b_ix++) {
      b_xloc = x[b_ix];
      if (muDoubleScalarIsNaN(b_xloc)) {
        b_v = rtNaN;
      } else {
        b_ip = internal::b_bsearch(pp.breaks, b_xloc) - 1;
        b_xloc -= pp.breaks[b_ip];
        b_v = pp.coefs[b_ip];
        b_v = b_xloc * b_v + pp.coefs[b_ip + coefStride];
        b_v = b_xloc * b_v + pp.coefs[b_ip + (coefStride << 1)];
      }
      v[b_ix] = b_v;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  } else {
    st.site = &ch_emlrtRSI;
    if (x.size(1) > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T ix{0}; ix < nx; ix++) {
      real_T xloc;
      int32_T iv0;
      iv0 = ix * elementsPerPage;
      xloc = x[ix];
      if (muDoubleScalarIsNaN(xloc)) {
        int32_T ip;
        st.site = &dh_emlrtRSI;
        if (elementsPerPage > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        ip = static_cast<uint8_T>(elementsPerPage);
        for (int32_T j{0}; j < ip; j++) {
          v[iv0 + j] = x[ix];
        }
      } else {
        int32_T icp;
        int32_T ip;
        int32_T scalarLB;
        int32_T vectorUB;
        ip = internal::b_bsearch(pp.breaks, xloc) - 1;
        icp = ip * elementsPerPage;
        xloc -= pp.breaks[ip];
        st.site = &eh_emlrtRSI;
        if (elementsPerPage > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        ip = static_cast<uint8_T>(elementsPerPage);
        for (int32_T j{0}; j < ip; j++) {
          v[iv0 + j] = pp.coefs[icp + j];
        }
        scalarLB = (static_cast<uint8_T>(elementsPerPage) >> 1) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T ic{0}; ic < 2; ic++) {
          int32_T i;
          int32_T ic0;
          ic0 = icp + (ic + 1) * coefStride;
          st.site = &fh_emlrtRSI;
          for (int32_T j{0}; j <= vectorUB; j += 2) {
            __m128d r;
            __m128d r1;
            i = iv0 + j;
            r = _mm_loadu_pd(&v[i]);
            r1 = _mm_loadu_pd(&pp.coefs[ic0 + j]);
            _mm_storeu_pd(&v[i],
                          _mm_add_pd(_mm_mul_pd(_mm_set1_pd(xloc), r), r1));
          }
          for (int32_T j{scalarLB}; j < ip; j++) {
            i = iv0 + j;
            v[i] = xloc * v[i] + pp.coefs[ic0 + j];
          }
        }
      }
    }
  }
}

void ppval(const emlrtStack &sp, const ::coder::array<real_T, 2U> &pp_breaks,
           const ::coder::array<real_T, 3U> &pp_coefs,
           const ::coder::array<real_T, 2U> &x, ::coder::array<real_T, 2U> &v)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T coefStride;
  int32_T nx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  coefStride = 3 * (pp_breaks.size(1) - 1);
  v.set_size(&ne_emlrtRTEI, &sp, 3, x.size(1));
  nx = x.size(1);
  st.site = &ch_emlrtRSI;
  if (x.size(1) > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T ix{0}; ix < nx; ix++) {
    real_T xloc;
    int32_T iv0;
    iv0 = ix * 3;
    xloc = x[ix];
    if (muDoubleScalarIsNaN(xloc)) {
      v[iv0] = x[ix];
      v[iv0 + 1] = x[ix];
      v[iv0 + 2] = x[ix];
    } else {
      __m128d r;
      __m128d r1;
      __m128d r2;
      int32_T icp;
      int32_T ip;
      ip = internal::b_bsearch(pp_breaks, xloc) - 1;
      icp = ip * 3;
      xloc -= pp_breaks[ip];
      v[iv0] = pp_coefs[icp];
      v[iv0 + 1] = pp_coefs[icp + 1];
      v[iv0 + 2] = pp_coefs[icp + 2];
      ip = icp + coefStride;
      r = _mm_loadu_pd(&v[iv0]);
      r1 = _mm_loadu_pd(&pp_coefs[ip]);
      r2 = _mm_set1_pd(xloc);
      _mm_storeu_pd(&v[iv0], _mm_add_pd(_mm_mul_pd(r2, r), r1));
      v[iv0 + 2] = xloc * v[iv0 + 2] + pp_coefs[ip + 2];
      ip = icp + (coefStride << 1);
      r = _mm_loadu_pd(&v[iv0]);
      r1 = _mm_loadu_pd(&pp_coefs[ip]);
      _mm_storeu_pd(&v[iv0], _mm_add_pd(_mm_mul_pd(r2, r), r1));
      v[iv0 + 2] = xloc * v[iv0 + 2] + pp_coefs[ip + 2];
      ip = icp + 3 * coefStride;
      r = _mm_loadu_pd(&v[iv0]);
      r1 = _mm_loadu_pd(&pp_coefs[ip]);
      _mm_storeu_pd(&v[iv0], _mm_add_pd(_mm_mul_pd(r2, r), r1));
      v[iv0 + 2] = xloc * v[iv0 + 2] + pp_coefs[ip + 2];
    }
  }
}

} // namespace coder
} // namespace trajectoryGeneration

// End of code generation (ppval.cpp)
