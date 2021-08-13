#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int rob(unordered_map<int, int> &nums)
{
    size_t n = nums.size();
    int a0 = nums[0];
    if (n == 1)
        return a0;
    int a1 = max(nums[0], nums[1]);
    if (n == 2)
        return a1;
    int temp;
    for (int i = 0; i < (int)(n - 2); i++)
    {
        temp = max(a0 + nums[2 + i], a1);
        a0 = a1;
        a1 = temp;
    }
    return a1;
}

int deleteAndEarn(vector<int> &nums)
{
    // vector<int> tb(10001);
    unordered_map<int, int> tb;
    for (size_t i = 0; i < nums.size(); i++)
        tb[nums[i]] += nums[i];
    return rob(tb);
}

int main()
{
    vector<int> vec = {3, 4, 2};
    cout << deleteAndEarn(vec) << "\n";
    return 0;
}
