#include <stdio.h>

void calcpay(p, r, h)
    float *p, r, h;
{
    float overtime;
    float result;

    if (h > 40) {
        overtime = h - 40;
        result = 40 * r + 1.5 * overtime * r;
    } else {
        result = h * r;
    }

    *p = result;
}

main() {
    int empno;
    float rate, hours, pay;
    void calcpay();

    while(1) {
        if (scanf("%d %f %f", &empno, &rate, &hours) < 3) break;
        calcpay(&pay, rate, hours);
        printf("Employee=%d Rate=%.2f Hours=%.2f Pay=%.2f\n", empno, rate, hours, pay);
    }
}
