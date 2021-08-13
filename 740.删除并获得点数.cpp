/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> tb(*max_element(nums.begin(), nums.end()));
        for (size_t i = 0; i < nums.size(); i++)
            tb[nums[i] - 1] += nums[i];
        return rob(tb);
    }
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
