/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

#include <iostream>
#include <vector>
#include <unordered_map> // STL hash table

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start

class Solution
{
public:
    unordered_map<Node *, Node *> visited_hash;
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return node;

        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        if (visited_hash.find(node) != visited_hash.end())
            return visited_hash[node];

        // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
        Node *cloneNode = new Node(node->val);
        // 哈希表存储
        visited_hash[node] = cloneNode;

        // 遍历该节点的邻居并更新克隆节点的邻居列表
        for (auto &neighbor : node->neighbors)
            cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
        return cloneNode;
    }
};
// @lc code=end
