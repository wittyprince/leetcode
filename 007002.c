//
// Created by 51676 on 2024/9/12.
//
#include <stdio.h>
/**
 * 7002. 爬楼梯变种
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 2的幂次方 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 约定 n = 0 时, there is only one way to climb to the top (do nothing).
 *
 * 同类题目：把一个正整数n拆分为 2的幂次方 之和, 共有多少种拆法?
 */

/**
 * dynamic programming
 */
/**
 * 对任一台阶i, 跳到该台阶的方式为：设为 f(i)种方式
 * 1. 从 i-1 台阶 跳 一步(2^0) 上来, 有 f(i - 1)种方式
 * 2. 从 i - 2^1 台阶 跳 2^1 步 上来, 有 f(i - 2^1)种方式. 这里隐含的包含 从 i - 2^1 跳到 i-1 台阶的情况, 可以参考【0070中递归方式】的解释.
 * 3. 从 i - 2^2 台阶 跳 2^2 步 上来, 有 f(i - 2^2)种方式. 解释同上
 * ...
 * 直到 i - 2^k >= 0, 有 f(i - 2^k) 种方式
 */
int climbStairs(int n) {
    int dp[n + 1];
    dp[0] = 1;
    // 第一个for循环, 主要是为了求前dp[1], dp[2], ... dp[n-1]
    // 这样求dp[n]时, 就可以直接使用了
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        // 第二个for循环, 是求跳到第i台阶的方式, 拆解为 i-1, i - 2^1, i - 2^2, i - 2^3, ...
        // (1 << j) is equivalent to 2^j
        for (int j = 0; (1 << j) <= i; j++) {
            dp[i] += dp[i - (1 << j)];
        }
    }
    return dp[n];
}

/**
 * 当f(0) = 0时
 * 思路同上, 只不过结果不同
 */
int climbStairs2(int n) {
    if (n < 0) {
        return 0;
    }
    if (n < 3) {
        return n;
    }

    int sums[n + 1];
    for (int i = 0; i <= n; ++i) {
        sums[i] = 0;
    }
    sums[0] = 0;
    sums[1] = 1;
    sums[2] = 2;

    for (int i = 3; i <= n; ++i) {
//        sums[i] = sums[i - 1] + sums[i - 2^1] + sums[i - 2^2] + ...
        for (int j = 0; (1 << j) <= i; ++j) {
            sums[i] += sums[i - (1 << j)];
        }
    }
    return sums[n];
}

int main() {
    int n = 4;
    int num = climbStairs2(n);
    printf("Number of ways to climb %d stairs: %d\n", n, num);
    return 0;
}