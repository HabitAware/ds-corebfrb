#include <stdio.h>
#include "corebfrb.h"

int main() {
    float g1[3] = {0.0f, 0.0f, 1.0f};
    float g2[3] = {0.0f, 1.0f, 0.0f};

    float angle = corebfrb(g1, g2);
    printf("Angle = %.1f degrees\n", angle);  // Expected: 90.0

    return 0;
}
