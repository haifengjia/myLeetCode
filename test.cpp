#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *pt1 = l1;
    ListNode *pt2 = l2;
    int len1 = 0, len2 = 0;
    int num1 = 0, num2 = 0;
    int i = 0, j = 0;
    while (pt1 != NULL)
    {
        len1++;
        pt1 = pt1->next;
    }
    while (pt2 != NULL)
    {
        len2++;
        pt2 = pt2->next;
    }
    cout << len1 << "  " << len2 << endl;
    pt1 = l1;
    pt2 = l2;
    for (int i = 0; i < len1; i++)
    {
        num1 += pt1->val * pow(10, i);
        pt1 = pt1->next;
    }
    for (int i = 0; i < len2; i++)
    {
        num2 += pt2->val * pow(10, i);
        pt2 = pt2->next;
    }
    int res = num1 + num2;
    cout << num1 << "  " << num2 << "  " << endl;
    cout << res << endl;
    int len = log10(res) + 1;
    cout << len << endl;
    vector<int> vec;
    for (int k = 0; k < len; k++)
    {
        vec.push_back(res - 10 * (res / 10));
        res = res / 10;
    }
    ListNode *resList = new ListNode(vec[0]);
    ListNode *pt = resList;
    for (int k = 1; k < len; k++)
    {
        ListNode *tempNode = new ListNode(vec[k]);
        pt->next = tempNode;
        pt = pt->next;
    }
    return resList;
};

int main()
{
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(3);
    ListNode *temp1 = new ListNode(2);
    ListNode *temp2 = new ListNode(4);
    l1->next = temp1;
    l2->next = temp2;
    ListNode *res = addTwoNumbers(l1, l2);
    // cout << res << endl;
    // ListNode *pt1 = l2;
    // while (pt1 != NULL)
    // {
    //     cout << pt1->val << endl;
    //     pt1 = pt1->next;
    // }

    return 0;
}
