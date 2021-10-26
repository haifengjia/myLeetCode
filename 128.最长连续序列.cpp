/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> memo;
        int res = 0;
        for (auto i : nums)
            memo.insert(i);

        for (int i = 0; i < nums.size(); ++i)
        {
            if (memo.find(nums[i] - 1) == memo.end())
            {
                int j = nums[i];
                while (memo.find(j) != memo.end())
                    ++j;
                res = max(res, j - nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
