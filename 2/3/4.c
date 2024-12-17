#include <stdio.h>

int main() {
    char line[256];
    char memory[256];
    char opcode;
    int count,address,value;

    while(fgets(line, 256, stdin) != NULL) {
        //printf("\nLine: %s\n",line);
        if ( line[0] == 'X' ) break;
        if ( line[0] == '*' ) {
            printf("%s",line);
            continue;
        }
        count = sscanf(line, "%d %c %d", &address, &opcode, &value);
        if ( count != 3 ) continue;
        //printf("address: %d opcode: %c value: %d\n", address, opcode, value);

        switch (opcode) {
        case '=':
            memory[address] = value;
            break;
        case '+':
            memory[address] += value;
            break;
        case '-':
            memory[address] -= value;
            break;
        default:
            break;
        }

        // printf("Memory:\n%s\n", memory);
    }
    printf("Memory:\n%s\n", memory);
}
