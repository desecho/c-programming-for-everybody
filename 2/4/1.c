int sumseries(int val) {
    int below, sum, result;

    if (val < 1) {
        return 0;
    } else if (val > 100) {
        return -1;
    } else if (val == 1) {
        return 1;
    }

    below = val - 1;
    sum = sumseries(below);
    result = val + sum;

    return result;
}

#include <stdio.h>
int main() {
    printf("sumseries(0) returns %d\n", sumseries(0));
    printf("sumseries(1) returns %d\n", sumseries(1));
    printf("sumseries(5) returns %d\n", sumseries(5));
    printf("sumseries(42) returns %d\n", sumseries(42));
    printf("sumseries(-42) returns %d\n", sumseries(-42));
    printf("sumseries(100) returns %d\n", sumseries(100));
    printf("sumseries(101) returns %d\n", sumseries(101));
    printf("sumseries(1000) returns %d\n", sumseries(1000));
}
