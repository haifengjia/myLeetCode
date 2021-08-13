/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int sz = nums.size();
        vector<bool> can_reach(sz);
        can_reach[0] = true;
        int i;
        for (int k = 1; k < sz; ++k)
        {
            i = k - 1;
            for (; i > -1; --i)
            {
                if (can_reach[i] && (nums[i] + i >= k))
                {
                    can_reach[k] = true;
                    break;
                }
            }
            if (i == -1)
                can_reach[k] = false;
            else
                continue;
        }
        return can_reach[sz - 1];
    }
};
// @lc code=end
