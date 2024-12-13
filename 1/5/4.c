#include <stdio.h>
#include <string.h>

int main() {
    char t[1000];
    char *copy();
    void reverse();
    copy("Hello world", t);
    printf("%s\n", t);
    reverse(t);
    printf("%s\n", t);
    reverse(copy("XY", t));
    printf("%s\n", t);
    reverse(copy("Even", t));
    printf("%s\n", t);
    reverse(copy("Odd", t));
    printf("%s\n", t);
    reverse(copy("civic", t));
    printf("%s\n", t);
}

/* copy s1 to s2; assume s2 big enough */
char *copy(char s1[], char s2[]) {
    int i;
    for(i=0;(s2[i] = s1[i]);i++);
    return s2;
}

void reverse(char t[]) {
    int i;
    int j = 0;
    int length = strlen(t);
    char reversed[1000];

    for (i = length - 1; i >= 0; i--) {
        reversed[j] = t[i];
        j++;
    }

    reversed[length] = '\0';

    for (i = 0; i < length; i++) {
        t[i] = reversed[i];
    }
}
