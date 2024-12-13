#include <stdio.h>

int main() {
    char input[1000];
    printf("Enter line\n");
    scanf("%[^\n]s", input);
    printf("Line: %s\n", input);
}
