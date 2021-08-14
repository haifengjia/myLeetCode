/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int sum = 0;
        for (auto num : nums)
        {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end
