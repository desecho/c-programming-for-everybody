#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];
    char keep[1000];

    while(gets(line) != NULL) {
        if (strcmp(line, keep) != 0) {
            printf("%s\n", line);
        }
        strcpy(keep, line);
    }
}
