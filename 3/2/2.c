#include <stdio.h>
#include <string.h>

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

int main() {
    char s1[] = "   Hello   World    ";
    void py_rstrip();
    py_rstrip(s1);
    printf("-%s-\n", s1);
}
