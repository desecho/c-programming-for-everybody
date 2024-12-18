#include <stdio.h>

int main() {
    int i, v, arr[10], counter;
    for (i = 0; i < 10; i++) {
        scanf("%d", &v);
        arr[i] = v;
    }

    for (i = 9; i >= 0; i--) {
        printf("numb[%d] = %d\n", i, arr[i]);
    }

    printf("\n");
    printf("Searching for entries equal to 100\n\n");

    counter = 0;

    for (i=0; i < 10; i++) {
        if (arr[i] == 100) {
            printf("Found 100 at %d\n", i);
            counter++;
        }
    }

    printf("\n");
    printf("Found %d entries with 100\n", counter);
}
