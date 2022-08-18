/*
 * @lc app=leetcode.cn id=1288 lang=c
 *
 * [1288] 删除被覆盖区间
 *
 * https://leetcode.cn/problems/remove-covered-intervals/description/
 *
 * algorithms
 * Medium (55.97%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 39.1K
 * Testcase Example:  '[[1,4],[3,6],[2,8]]'
 *
 * 给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
 *
 * 只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
 *
 * 在完成所有删除操作后，请你返回列表中剩余区间的数目。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：intervals = [[1,4],[3,6],[2,8]]
 * 输出：2
 * 解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
 *
 *
 *
 *
 * 提示：​​​​​​
 *
 *
 * 1 <= intervals.length <= 1000
 * 0 <= intervals[i][0] < intervals[i][1] <= 10^5
 * 对于所有的 i != j：intervals[i] != intervals[j]
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

// @lc code=start

int cmp(const void *a, const void *b)
{
    printf("%d, %d\n", ((const int **)a)[0], ((const int **)a)[1]);
    printf("%d, %d\n", ((const int **)b)[0], ((const int **)b)[1]);
    return (((const int **)a)[0] == ((const int **)b)[0]) ? (((const int **)a)[1] - ((const int **)b)[1])
                                                          : (((const int **)a)[0] - ((const int **)b)[0]);
}

void print2dArray(int **intervals, int intervalsSize, int *intervalsColSize)
{
    for (int i = 0; i < intervalsSize; i++)
    {
        printf("[");
        for (int j = 0; j < intervalsColSize[i]; j++)
        {
            printf("%d,", intervals[i][j]);
        }
        printf("] ");
    }
}

int removeCoveredIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    int res = intervalsSize;
    printf("%d\n", cmp(intervals, intervals + 1));
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    print2dArray(intervals, intervalsSize, intervalsColSize);
    for (size_t i = 0; i < intervalsSize - 1; ++i)
    {
        if ((intervals[i][0] <= intervals[i + 1][0]) && (intervals[i][1] >= intervals[i + 1][1]))
        {
            --res;
            size_t j = 2;
            for (; j < intervalsSize - i;)
            {
                if ((intervals[i][0] <= intervals[i + j][0]) && (intervals[i][1] >= intervals[i + j][1]))
                {
                    ++j;
                    --res;
                }
                else
                    break;
            }
            i += j;
        }
        else
            continue;
    }
    return res;
}
// @lc code=end
