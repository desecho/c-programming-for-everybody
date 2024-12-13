#include <stdio.h>

int main() {
    int c, blank;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blank = 1;
        } else if (c != ' ' && blank){
            putchar(' ');
            putchar(c);
            blank = 0;
        } else {
            putchar(c);
        }
    }
}
