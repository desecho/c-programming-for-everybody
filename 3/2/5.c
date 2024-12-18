#include <stdio.h>
#include <string.h>

void process(line)
    char line[];
{
    int size, i;
    printf("\nString: %s\n", line);
    for (size = 0; line[size]; size++) {}
    printf("Count=%d\n", size);
    if (size > 10) {
        printf("The ninth character is: %c\n", line[9]);
    }

    for (i = 0; i < size; i++) {
        if (line[i] == ' ') {
            line[i] = '-';
        }
    }

    printf("String: %s\n", line);
}


int main() {
    char line[1000];
    void process();
    strcpy(line, "Hi there and welcome to LBS290");
    process(line);
    strcpy(line, "I love C");
    process(line);
}
