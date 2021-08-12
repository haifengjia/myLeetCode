/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
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
        size_t n = nums.size();
        int a0 = nums[0];
        if (n == 1)
            return a0;
        int a1 = max(nums[0], nums[1]);
        if (n == 2)
            return a1;
        int temp;
        for (int i = 0; i < (int)(n - 2); i++)
        {
            temp = max(a0 + nums[2 + i], a1);
            a0 = a1;
            a1 = temp;
        }
        return a1;
    }
};
// @lc code=end
