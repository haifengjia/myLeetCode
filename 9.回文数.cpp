/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <math.h>

using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x > -1 && x < 10)
            return true;
        else if (x < 0)
            return false;
        else
        {
            int digNum = log10(x) + 1;
            int *digArr = new int[digNum];
            int y = x;
            for (int i = 0; i < digNum; i++)
            {
                digArr[i] = y % 10;
                y = y / 10;
            }

            int dest = digNum / 2;
            for (int i = 0; i < dest; i++)
            {
                if (digArr[i] != digArr[digNum - 1 - i])
                    return false;
            }
            return true;

            delete[] digArr;
        }
    }
};
// @lc code=end
