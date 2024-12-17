#include <stdio.h>
#include <string.h>

void remove_leading_zero(char s[]) {
    int i;

    if (s[0] == '0') {
        for (i = 1; s[i]; i++) {
            s[i-1] = s[i];
        }
        s[i-1] = '\0';
    }
}

void itob(int n, char s[]) {
    int v, digit;
    void reverse();
    v = n;
    int i = 0;
    while (v > 0) {
        digit = v % 2;
        s[i] = digit + '0';
        i++;
        v = v / 2;
    }
    reverse(s);

    remove_leading_zero(s);
}

void itoh(int n, char s[]) {
    sprintf(s, "%x", n);
}


int main() {
    char s[1000];
    void itob(), itoh(), reverse();

    itob(42,s);
    printf("42 in base-2 is %s\n", s);
    itoh(42,s);
    printf("42 in base-16 is %s\n", s);

    itob(16,s);
    printf("16 in base-2 is %s\n", s);
    itoh(16,s);
    printf("16 in base-16 is %s\n", s);

    itob(59,s);
    printf("59 in base-2 is %s\n", s);
    itoh(59,s);
    printf("59 in base-16 is %s\n", s);

    itob(100,s);
    printf("100 in base-2 is %s\n", s);
    itoh(100,s);
    printf("100 in base-16 is %s\n", s);

    itob(254,s);
    printf("254 in base-2 is %s\n", s);
    itoh(254,s);
    printf("254 in base-16 is %s\n", s);
}

void reverse(t)
char t[];
{
    int i, j, len;
    char tmp;
    len = strlen(t);
    for(i=0, j=len-1;;i++,j--) {
        if (j<i) break;
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
    }
    return;
}
