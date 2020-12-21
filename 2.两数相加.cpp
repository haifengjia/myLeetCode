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
        ListNode *ansRoot = new ListNode(0);
        ListNode *curs = ansRoot;
        while (it1 || it2)
        {
            int val1 = it1 ? it1->val : 0;
            int val2 = it2 ? it2->val : 0;
            int temp = !isOverflow ? (val1 + val2) : (val1 + val2 + 1);

            isOverflow = (temp >= 10);
            it1 = it1 ? it1->next : nullptr;
            it2 = it2 ? it2->next : nullptr;

            temp = isOverflow ? temp % 10 : temp;
            ListNode *tempNode = new ListNode(temp);
            curs->next = tempNode;
            curs = tempNode;
        }

        if (!it1 && !it2 && isOverflow)
        {
            ListNode *tempNode = new ListNode(1);
            curs->next = tempNode;
        }

        return ansRoot->next;
    }
};
// @lc code=end
