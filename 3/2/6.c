#include <stdio.h>
#include <stdlib.h>

int main()
{
    char memory[256], token[256];
    int position = 0, value;

    while (scanf("%s", token) == 1) {
        value = atoi(token);
        if (value != 0) {
            memory[position] = value;
        } else {
          if (token[0] == '<') {
            position--;
          } else if (token[0] == '>') {
            position++;
          }
        }
    }
    printf("Memory:\n%s\n", memory);
}
