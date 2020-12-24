/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        if (s.empty())
            return -1;

        if (s.size() == 1)
            return 0;

        int i = 0;
        for (; i < s.size(); i++)
        {
            if (i == 0 && s.find(s[i], i + 1) == -1)
                break;
            else if (s.rfind(s[i], i - 1) == -1 && i == s.size())
                break;
            else if (s.find(s[i], i + 1) == -1 && s.rfind(s[i], i - 1) == -1)
                break;
        }
        if (i < s.size())
            return i;
        else
            return -1;
    }
};
// @lc code=end
