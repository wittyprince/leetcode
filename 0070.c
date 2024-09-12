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
*/

/**
 * Example 1:
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
*/

/**
 * Example 2:
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
*/

/**
 * Constraints:
 * 1 <= n <= 45
 */

/**
 * 思路: 通过递归方式
 * 要想到达第n个台阶, 可以通过两种方式:
 *  方式一: 从n-1级台阶上去. 从n-1级台阶 再跳一步 可以上到 n 级台阶, 共一种方法
 *  方式二: 从n-2级台阶上去. 从n-2级台阶 再跳两步 可以上到 n 级台阶, 共一种方法.
 *      这里注意 如果从n-2级台阶通过先跳一步, 再跳一步的方法, 此种方法可以归类到从n-1级台阶上去, 即已经包含在了 方式一 中了.
 * 所以有: f(n) = f(n-1) + f(n-2)
 *
 * 时间复杂度 是 O(n^2) 和 空间复杂度 是 O(n)
 *
 * 此种方法的弊端: 递归方法 效率不高
*/
int climbStairs(int n) {
    if (n < 0) {
        return 0;
    }
    if (n < 3) {
        return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

/**
 * 使用数组记录重复计算的f(i) (i = 3, 4, ... n-2, n-1)
 *
 * 时间复杂度 是 O(n), 空间复杂度 是 O(n)
 */
int climbStairSum2(int n, int *sums) {
    if (sums[n] > 0) {
        return sums[n];
    }
    sums[n] = climbStairSum2(n - 1, sums) + climbStairSum2(n - 2, sums);
    return sums[n];
}

int climbStairs2(int n) {
    int memories[n + 1];
    for (int i = 0; i <= n; ++i) {
        memories[i] = 0;
    }
    memories[1] = 1;
    memories[2] = 2;
    return climbStairSum2(n, memories);
}

/**
 * 该方法与【climbStairs2()】方法思路一致, 只是更好理解
 * 使用数组记录重复计算的f(i) (i = 3, 4, ... n-2, n-1)
 * 时间复杂度 是 O(n), 空间复杂度 是 O(n)
 */
int climbStairs3(int n) {
    if (n < 0) {
        return 0;
    }
    if (n < 3) {
        return n;
    }
    int sums[n + 1];
    sums[1] = 1;
    sums[2] = 2;
    for (int i = 3; i <= n; ++i) {
        sums[i] = sums[i - 1] + sums[i - 2];
    }
    return sums[n];
}

/**
 * 思路: 动态规划 - 滚动数组 思想
 * 优化上面 【递归方式】, 由于f(n) 只与f(n-1) 和 f(n-2)有关, 通过 滚动数组 的思想 可以优化 时间 + 空间 复杂度
 *
 * 时间复杂度 是 O(n), 空间复杂度 是 O(1)
 *
 * 此种方法 也适合 求 【Fibonacci sequence斐波那契数列】
 */
int climbStairs4(int n) {
    if (n < 0) {
        return 0;
    }
    if (n < 3) {
        return n;
    }
    int p = 1, q = 2, r;
    for (int i = 3; i <= n; ++i) {
        r = p + q;
        p = q;
        q = r;
    }
    return r;
}

/**
 * 思路: 使用fibonacci数列通项公式来计算
 */
int climbStairs5(int n) {
    //TODO
    return 0;
}

/**
 * binet's formula
 * 矩阵快速幂
 */
int climbStairs6(int n) {
    //TODO
    return 0;
}

/**
 * 总结
 * 这里形成的数列正好是斐波那契数列，答案要求的 f(n) 即是斐波那契数列的第 n 项（下标从 0 开始）。
 * 我们来总结一下斐波那契数列第 n 项的求解方法：
 * 1. n 比较小的时候，可以直接使用过递归法求解，不做任何记忆化操作，时间复杂度是 O(2^n)，存在很多冗余计算。
 * 2. 一般情况下，我们使用「记忆化搜索」或者「迭代」的方法，实现这个转移方程，时间复杂度和空间复杂度都可以做到 O(n)。
 * 3. 为了优化空间复杂度，我们可以不用保存 f(x−2) 之前的项，我们只用三个变量来维护 f(x)、f(x−1) 和 f(x−2)，
 *      你可以理解成是把「滚动数组思想」应用在了动态规划中，也可以理解成是一种递推，这样把空间复杂度优化到了 O(1)。
 * 4. 随着 n 的不断增大 O(n) 可能已经不能满足我们的需要了，我们可以用「矩阵快速幂」的方法把算法加速到 O(logn)。
 * 5. 我们也可以把 n 代入斐波那契数列的通项公式计算结果，但是如果我们用浮点数计算来实现，可能会产生精度误差。

 * 作者：力扣官方题解
 * 链接：https://leetcode.cn/problems/climbing-stairs/solutions/286022/pa-lou-ti-by-leetcode-solution/
 * 来源：力扣（LeetCode）
 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
int main() {
    int num = climbStairs3(45);
    printf("%3d\n", num);
    return 0;
}