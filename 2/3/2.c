#include <stdio.h>

int i = 0;

int bump() {
  	extern i;
    return i++;
}

int main() {
    int bump();
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
}
