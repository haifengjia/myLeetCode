/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int sup = maxSubArray(nums);
        int inf = minSubArray(nums);
        if (sup < 0)
            return sup;
        else
            return max(sup, accumulate(nums.begin(), nums.end(), 0) - inf);
    }

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

    int minSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int sum = 0;
        for (auto num : nums)
        {
            if (sum >= 0)
                sum = num;
            else
                sum += num;
            res = min(res, sum);
        }
        return res;
    }
};
// @lc code=end
