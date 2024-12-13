#include <stdio.h>

int mymult(int a, int b) {
    return a * b;
}

int main() {
    int mymult();
    int retval;

    retval = mymult(6, 7);
    printf("Answer: %d\n", retval);
}
