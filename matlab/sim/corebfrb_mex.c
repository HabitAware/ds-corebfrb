/* MATLAB MEX wrapper for corebfrb
 * Compile from the repository root with:
 *   mex -R2018a -I motion_algo/core matlab/sim/corebfrb_mex.c motion_algo/core/corebfrb.c
 * Usage in MATLAB:
 *   angle = corebfrb_mex(g1, g2);
 * where g1 and g2 are 3-element vectors (row or column).
 */

#include "mex.h"
#include "../../motion_algo/core/corebfrb.h"

static void validateInputVector(const mxArray *arr, const char *name, float out[3]) {
    if (!mxIsDouble(arr) || mxIsComplex(arr) || mxGetNumberOfElements(arr) != 3) {
        mexErrMsgIdAndTxt("corebfrb_mex:input", "%s must be a real double vector with 3 elements.", name);
    }
    double *ptr = mxGetPr(arr);
    for (mwSize i = 0; i < 3; ++i) {
        out[i] = (float)ptr[i];
    }
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    if (nrhs != 2) {
        mexErrMsgIdAndTxt("corebfrb_mex:nrhs", "Two input vectors required (g1 and g2).");
    }
    if (nlhs > 1) {
        mexErrMsgIdAndTxt("corebfrb_mex:nlhs", "Too many output arguments.");
    }

    float g1[3];
    float g2[3];
    validateInputVector(prhs[0], "g1", g1);
    validateInputVector(prhs[1], "g2", g2);

    float angle = corebfrb(g1, g2);
    plhs[0] = mxCreateDoubleScalar((double)angle);
} 