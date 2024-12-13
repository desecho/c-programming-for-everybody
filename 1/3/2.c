#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000

int main() {
    char input[MAX_LINES];
    int i = 0;
    int first = 1;
    int val, max_val, min_val;

    while (1) {
        if (gets(input) == NULL) {
            printf("Reached end of file before receiving done");
            return 1;
        }

      	if (strcmp(input, "done") == 0) {
        	break;
        }
        val = atoi(input);
        if (first || val > max_val) {
            max_val = val;
        }
        if (first || val < min_val) {
            min_val = val;
        }
        first = 0;
    }

    printf("Maximum %d\n", max_val);
    printf("Minimum %d\n", min_val);
}
