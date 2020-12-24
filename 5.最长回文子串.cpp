/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    static inline bool isPal(string s)
    {
        if (s.size() % 2)
        {
            string t = s.substr(s.size() / 2, s.size() / 2);
            reverse(t.begin(), t.end());
            return s.substr(0, s.size() / 2) == t;
        }
        else
        {
            string t = s.substr(s.size() / 2 + 1, s.size() / 2);
            reverse(t.begin(), t.end());
            return s.substr(0, s.size() / 2) == t;
        }
    }
    string longestPalindrome(string s)
    {
        if (isPal(s))
            return s;

        for (int i = s.size(); i > 0; i--)
        {
            for (int j = 0; j < s.size() - i + 1; j++)
            {
                if (s[j] != s[j + i - 1])
                    continue;
                else
                {
                    if (isPal(s.substr(j, i)))
                        return s.substr(j, i);
                }
            }
        }
        return "";
    }
};
// @lc code=end
