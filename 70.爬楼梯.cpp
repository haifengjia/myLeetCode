/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int a1 = 1, a2 = 2, a3 = 3, temp;
        if (n <= 3)
            return n;
        for (int i = 0; i < n - 3; i++)
        {
            temp = a2 + a3;
            a1 = a2;
            a2 = a3;
            a3 = temp;
        }
        return a3;
    }
};
// @lc code=end
