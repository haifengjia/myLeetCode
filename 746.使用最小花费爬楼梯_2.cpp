/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{

public:
    int memo[1000]; // DP beiwanglu

    Solution()
    {
        for (int i = 0; i < 1000; i++)
            memo[i] = -1;
    };

    int helper(vector<int> &cost, int i)
    {
        if (memo[i] != -1)
            return memo[i];
        else
        {
            int len = cost.size();
            if (i == 1 || i == 0)
                memo[i] = cost[i];
            else
                memo[i] = min(helper(cost, i - 1), helper(cost, i - 2)) + cost[i];

            return memo[i];
        }
    }

    int minCostClimbingStairs(vector<int> &cost)
    {

        int len = cost.size();
        return min(helper(cost, len - 1), helper(cost, len - 2));
    }
};
// @lc code=end
