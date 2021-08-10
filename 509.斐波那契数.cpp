/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        int a0 = 0, a1 = 1, a2 = 1, temp;
        if (n < 3)
            return ((n == 0) ? 0 : 1);
        for (int i = 0; i < n - 2; ++i)
        {
            temp = a1 + a2;
            a0 = a1;
            a1 = a2;
            a2 = temp;
        }
        return a2;
    }
};
// @lc code=end
