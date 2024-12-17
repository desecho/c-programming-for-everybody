#include <stdio.h>

int main()
{
    char line[256];
    char opcode;
    float value, display = 0.0;

    while(fgets(line, 256, stdin) != NULL) {
        // Use sscanf to parse data from a string
        sscanf(line, "%c %f", &opcode, &value);
        if ( opcode == 'S' ) break;

        switch (opcode) {
            case '=':
                display = value;
                break;
            case '+':
                display += value;
                break;
            case '-':
                display -= value;
                break;
            case '*':
                display *= value;
                break;
            case '/':
                display /= value;
                break;
            default:
                printf("Error");
                return 1;
        }

        printf("Display: %.2f\n", display);
    }
}
