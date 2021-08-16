/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include <vector>
#include <algorithm>
// #include <numeric>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxF = nums[0], minF = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            res = max(maxF, res);
        }
        return res;
    }
};
// @lc code=end
