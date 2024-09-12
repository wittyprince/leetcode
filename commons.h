//
// Created by 51676 on 2024/9/11.
//

#ifndef LEETCODE_COMMONS_H
#define LEETCODE_COMMONS_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *a, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

#endif //LEETCODE_COMMONS_H
