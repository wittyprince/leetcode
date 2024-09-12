//
// Created by 51676 on 2024/9/12.
//
#include <stdio.h>
/**
 * https://leetcode.com/problems/climbing-stairs/description/?envType=problem-list-v2&envId=dynamic-programming
 *
 * 70.Climbing Stairs
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 70.爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*/

/**
 * 7001. 爬楼梯变种
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 或 3 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 约定 n = 0 时, there is only one way to climb to the top (do nothing).
 */

 /**
  * 递归
  */
int climbStairs(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (n < 3) {
        return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2) + climbStairs(n - 3);
}

/**
 * 动态规划
 */
int climbStairsSums2(int n, int *sums) {
    if (n < 0) {
        return 0;
    }
    if (sums[n] > 0) {
        return sums[n];
    }
    sums[n] = climbStairsSums2(n - 1, sums) + climbStairsSums2(n - 2, sums) + climbStairsSums2(n - 3, sums);
    return sums[n];
}

int climbStairs2(int n) {
    int sums[n + 1];
    for (int i = 1; i <= n; ++i) {
        sums[i] = -1;
    }
    sums[0] = 1;
    sums[1] = 1;
    sums[2] = 2;
    return climbStairsSums2(n, sums);
}

int climbStairs3(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (n < 3) {
        return n;
    }
    int sums[n + 1];
    for (int i = 0; i <= n; ++i) {
        sums[i] = 0;
    }
    sums[0] = 1;
    sums[1] = 1;
    sums[2] = 2;
    for (int i = 3; i <= n; ++i) {
        sums[i] = sums[i - 1] + sums[i - 2] + sums[i - 3];
    }
    return sums[n];
}

int main() {
    int num = climbStairs3(3);
    printf("%3d\n", num);
    return 0;
}