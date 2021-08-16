/*
 * @lc app=leetcode.cn id=1567 lang=cpp
 *
 * [1567] 乘积为正数的最长子数组长度
 */

#include <vector>
#include <algorithm>
// #include <numeric>

using namespace std;

// @lc code=start
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int res = 0, pos = 0, neg = 0;
        for (int num : nums)
        {
            if (num == 0)
                pos = neg = 0;
            else if (num > 0)
            {
                pos++;
                neg = (neg > 0) ? (neg + 1) : neg;
            }
            else
            {
                swap(neg, pos);
                neg++;
                pos = (pos > 0) ? (pos + 1) : pos;
            }
            res = max(res, pos);
        }
        return res;
    }
};
// @lc code=end
