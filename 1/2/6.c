#include <stdio.h>

int main() {
    char input[100];
    printf("Enter line\n");
    fgets(input, 100, stdin);
    printf("Line: %s\n", input);
}
