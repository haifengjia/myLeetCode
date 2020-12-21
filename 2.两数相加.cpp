// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool isOverflow = false;
        ListNode *it1 = l1;
        ListNode *it2 = l2;
        vector<int> res;
        while (it1 || it2)
        {
            int val1 = it1 ? it1->val : 0;
            int val2 = it2 ? it2->val : 0;
            int temp = !isOverflow ? (val1 + val2) : (val1 + val2 + 1);
            if (temp < 10)
            {
                isOverflow = false;
                res.push_back(temp);
            }
            else
            {
                isOverflow = true;
                res.push_back(temp % 10);
            }
            it1 = it1 ? it1->next : nullptr;
            it2 = it2 ? it2->next : nullptr;
        }

        if (!it1 && !it2 && isOverflow)
            res.push_back(1);

        int len = res.size();
        ListNode *resList = new ListNode(res[0]);
        ListNode *itr = resList;
        for (int i = 1; i < len; i++)
        {
            ListNode *tempNode = new ListNode(res[i]);
            itr->next = tempNode;
            itr = itr->next;
        }
        return resList;
    }
};
// @lc code=end
