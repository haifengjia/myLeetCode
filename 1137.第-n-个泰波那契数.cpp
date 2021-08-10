/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        int a0 = 0, a1 = 1, a2 = 1, a3 = 2, temp;
        if (n < 4)
            return ((n < 2) ? n : (n - 1));
        for (int i = 0; i < n - 3; ++i)
        {
            temp = a1 + a2 + a3;
            a0 = a1;
            a1 = a2;
            a2 = a3;
            a3 = temp;
        }
        return a3;
    }
};
// @lc code=end
