#include <stdio.h>
#include <string.h>
#include <ctype.h>

void py_rstrip(inp)
    char inp[];
{
    int n; // Counter for the number of characters in a string
    int i;
    for (n=0; inp[n]; n++) {}

    for (i = n - 1; i > 0; i--) {
        if (inp[i] == ' ') {
            inp[i] = '\0';
        } else {
            break;
        }
    }
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

void py_lstrip(inp)
    char inp[];
{
    reverse(inp);
    py_rstrip(inp);
    reverse(inp);
}

int main() {
    char s1[] = "   Hello   World    ";
    void py_lstrip();
    py_lstrip(s1);
    printf("-%s-\n", s1);
}
