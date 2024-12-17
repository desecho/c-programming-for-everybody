/*

This program will prompt for 5 floating point numbers.
The program will print out the total of the five numbers and also print out the average.

*/
#include "stdio.h"

#define SIZE 5

void input_data(float data[]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        scanf("%f", &data[i]);
    }
}

float get_total(float data[]) {
    int i;
    float total = 0;
    for (i = 0; i < SIZE; i++) {
        total += data[i];
    }

    return total;
}

int main () {
    float data[SIZE];
    float total;
    float average;
    input_data(data);
    total = get_total(data);

    // Calculate average
    average = total / SIZE;
    printf("The total is: %.1f\n", total);
    printf("The average is: %.1f\n", average);
}
