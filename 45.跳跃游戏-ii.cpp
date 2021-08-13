/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int max_dist = 0, end = 0, jump = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            max_dist = max(max_dist, i + nums[i]);
            if (i == end)
            {
                end = max_dist;
                ++jump;
            }
        }
        return jump;
    }
};
// @lc code=end
