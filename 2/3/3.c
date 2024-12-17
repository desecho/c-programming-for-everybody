#include <stdio.h>

static int i = 0;

int bump() {
    return i++;
}

void start(int value) {
    i = value;
}

int main() {
    int bump();
    void start();
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    start(42);
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
}
