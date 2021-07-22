/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> trust_num(n, 0);
        for (auto t : trust)
            trust_num[t[1] - 1]++;
        auto res_it = find(trust_num.begin(), trust_num.end(), n - 1);
        if (res_it != trust_num.end())
        {
            int res = (res_it - trust_num.begin() + 1);
            for (auto t : trust)
            {
                if (t[0] == res)
                    return -1;
            }
            return res;
        }
        else
            return -1;
    }
};
// @lc code=end
