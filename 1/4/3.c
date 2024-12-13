/* Celsius-Fahrenheit table */

#include <stdio.h>

int main() {
    int cel;
    for (cel = 0; cel <= 100; cel = cel + 20) {
        printf("%4d %6.1f\n", cel, (cel * 9 / 5 + 32.0));
    }
}
