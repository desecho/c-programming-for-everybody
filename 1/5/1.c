#include <stdio.h>

int main() {
    int c, new_line_count, spaces_count;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            new_line_count++;
        } else if (c == ' ') {
            spaces_count++;
        }
    }

    printf("%d %d\n", spaces_count, new_line_count);
}
