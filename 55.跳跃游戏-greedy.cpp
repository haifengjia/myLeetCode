/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_dist = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (max_dist < i)
                return false;
            max_dist = max(max_dist, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end
