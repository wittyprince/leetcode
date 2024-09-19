//
// Created by 51676 on 2024/9/19.
//

// fibonacci sequence 斐波那契数列
#include <stdio.h>
#include <math.h>

// 斐波那契的通项公式
int fib(int n) {
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
    return (int) round(fibn / sqrt5);
}

int main() {
    int f = fib(3);
    printf("%3d\n", f);
    return 0;
}