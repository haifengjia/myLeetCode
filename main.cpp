#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int rob(vector<int> &nums)
{
    size_t n = nums.size();
    int a0 = nums[0];
    if (n == 1)
        return a0;
    int a1 = max(nums[0], nums[1]);
    if (n == 2)
        return a1;
    int a2 = max(a0 + nums[2], a1);
    if (n == 3)
        return a2;
    int temp;
    for (int i = 0; i < (int)(n - 3); i++)
    {
        temp = max(a1 + nums[3 + i], a2);
        a0 = a1;
        a1 = a2;
        a2 = temp;
    }
    return a2;
}

int main()
{
    vector<int> vec = {1, 2, 3, 1};
    cout << rob(vec) << "\n";
    return 0;
}
