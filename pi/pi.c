#include <stdio.h>

#define BOUNDS 100000000
static double pi(void) {
    double sum = 0.0;
    double sign = 1.0;

    for (unsigned long long n = 0; n < BOUNDS; n++) {
        sum += sign / (2*n + 1);
        sign = -sign;
    }
    return 4.0 * sum;
}

int main(void) {
    printf("pi is: %.10f\n", pi());
}

