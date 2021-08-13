/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int sz = nums.size();
        if (sz == 1)
            return nums[0];
        int res1 = rob_helper(nums, 0, nums.size() - 1);
        int res2 = rob_helper(nums, 1, nums.size() - 1);
        return max(res1, res2);
    }

    int rob_helper(vector<int> &nums, int beg, int n)
    {
        int a0 = nums[beg];
        if (n == 1)
            return a0;
        int a1 = max(a0, nums[beg + 1]);
        if (n == 2)
            return a1;
        int temp;
        for (int i = 0; i < (int)(n - 2); i++)
        {
            temp = max(a0 + nums[beg + 2 + i], a1);
            a0 = a1;
            a1 = temp;
        }
        return a1;
    }
};
// @lc code=end
