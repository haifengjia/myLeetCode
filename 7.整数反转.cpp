/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start

#include <cmath>
class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
            return 0;

        bool isNeg = x < 0;
        // check whether x is INT_MIN
        if (x == -2147483648)
            return 0;
        if (isNeg)
            x = -x;

        // figure out the figures
        int digitNum = log10(x) + 1;
        int *digits = new int[digitNum];

        for (int i = 0; i < digitNum; i++)
        {
            digits[i] = x % 10;
            x = x / 10;
        }

        // reverse the order
        long res = 0;
        for (int i = 0; i < digitNum; i++)
            res += digits[i] * pow(10, digitNum - i - 1);

        // return
        if ((int)res == res)
            return (isNeg ? -res : res);
        else
            return 0;

        delete[] digits;
    }
};
// @lc code=end
