/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> repeatedTime;
        for (int k = 0; k < s.size(); k++)
        {
            char ltr = s[k];
            int i;
            for (i = k + 1; i < s.size(); i++)
            {
                if (s[i] == ltr)
                {
                    break;
                }
            }

            int index1 = k, index2;
            if (i == s.size() && s[i] != ltr)
            {
                index2 = k;
            }
            else
            {
                index2 = i;
            }
            cout << index1 << endl;
            cout << index2 << endl;
            int len = index2 - index1;
            if (len == 0)
            {
                len = s.size() - index1;
            }
            cout << "the letter   " << ltr << "  has" << len << endl;
            if (len != s.size())
            {
                repeatedTime.push_back(len);
            }
        }
        int maxLen = *max_element(repeatedTime.begin(), repeatedTime.end());
        cout << maxLen << endl;
        return maxLen;
    }
};
// @lc code=end
