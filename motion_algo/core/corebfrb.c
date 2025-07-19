#include "corebfrb.h"
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float clamp(float x, float min_val, float max_val) {
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}

float corebfrb(const float g1[3], const float g2[3]) {
    float dot = g1[0]*g2[0] + g1[1]*g2[1] + g1[2]*g2[2];
    dot = clamp(dot, -1.0f, 1.0f);
    return acosf(dot) * (180.0f / (float)M_PI);  // radians to degrees
}
