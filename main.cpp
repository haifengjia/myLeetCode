#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

// bool isBelong2(int n, vector<int> interval)
// {
//     return (n >= interval[0]) && (n <= interval[1]);
// }

int partition(vector<vector<int>> &arr, int low, int high)
{
    int pivot = arr[low][0]; //基准
    int subpivot = arr[low][1];
    while (low < high)
    {
        while (low < high && arr[high][0] >= pivot)
            --high;
        arr[low] = arr[high]; //交换比基准大的记录到左端
        while (low < high && arr[low][0] <= pivot)
            ++low;
        arr[high] = arr[low]; //交换比基准小的记录到右端
    }
    //扫描完成，基准到位
    arr[low] = vector<int>{pivot, subpivot};
    //返回的是基准的位置
    return low;
}

void qsort(vector<vector<int>> &arr, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high); //将数组分为两部分
    qsort(arr, low, pivot - 1);            //递归排序左子数组
    qsort(arr, pivot + 1, high);           //递归排序右子数组
}

void quickSort(vector<vector<int>> &arr)
{
    qsort(arr, 0, arr.size() - 1);
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 1)
        return intervals;

    quickSort(intervals);
    vector<vector<int>> res;
    for (int i = 0; i < intervals.size() - 1; i++)
    {
        vector<int> newIntv;
        int j = i;
        int cursor = intervals[j][1];
        // for (; j < intervals.size() - 1; j++)
        // {
        //     if (cursor < intervals[j + 1][0])
        //     {
        //         cursor = max(cursor, intervals[j + 1][1]);
        //         break;
        //     }
        //     else
        //         continue;
        // }
        // int max = intervals[j][1];
        // for (int k = i; k < j; k++)
        // {
        //     if (intervals[k][1] > max)
        //         max = intervals[k][1];
        // }
        for (; j < intervals.size() - 1; j++)
        {
            if (cursor >= intervals[j + 1][0])
            {
                if (cursor <= intervals[j + 1][1])
                {
                    cursor = intervals[j + 1][1];
                    continue;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                break;
            }
        }
        newIntv = vector<int>{intervals[i][0], cursor};
        res.push_back(newIntv);

        i = j;
    }
    if (res.back()[1] < intervals.back()[0])
        res.push_back(intervals.back());

    return res;
}

int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}, {5, 6}};
    v = merge(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i][0] << "  " << v[i][1] << endl;
    return 0;
}
