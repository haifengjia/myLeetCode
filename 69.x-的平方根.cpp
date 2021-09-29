/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

#include <math.h>

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        double beg = 1, end = x;
        double mid = (beg + end) / 2;
        while (abs(mid * mid - static_cast<double>(x)) >= 1)
        {
            if (static_cast<size_t>(mid) * static_cast<size_t>(mid) == x)
                return mid;
            else if (mid * mid > static_cast<double>(x))
                end = mid;
            else
                beg = mid;
            mid = (beg + end) / 2;
        }
        return mid;
    }
};
// @lc code=end
