# myLeetCode

## Some basic info

For lack of Data Structure knowledge, from now on I will focus on the questions of easy level. The hard and medium ones will be continued after maybe my senior 3. Practice makes perfection! Have fun.

## The structure

在 zilaio 文件夹存储了一些必要的资料；
main.cpp 和 main，还有 build 文件夹是用来本地 CMake 来 debug 的（test.in 用作测试的输入文件）
剩下的文件就是我的题解。

## Solution reviews

### 1

2020/09/13
Pass all the testcases

### 2

2020/09/13
失败

2020/12/21
成功 pass，但是内存和 runtime 还不是很满意。
第二次修改，这次的 runtime 击败了 65.69%的用户，但是内存还是 70+M，不是很满意，但是目前这个程度应该是足够了。结束战斗。

### 3

2020/09/14
我的方法有问题 因此我把它放在后缀叫 wrong 的文件里
用来提交的那个是学习别人的答案
这个 unodered set 很妙 叫做哈希集合 刚好满足这里的情形

### 7

2020/09/18
整数翻转
2020/12/17
finish, pass

### 455

2020/12/27
贪心算法，greedy algorithm
看了算法导论，学会了点皮毛，打算这几天以这个为主题展开学习，然后结合着递归和数据结构刷

### 746

2020/12/22

这道题是 recursion+动态规划 DP，学习了一下 DP 的知识和概念，ziliao 文件夹里有一个课件资料。
一开始的 runtime 超出范围了，最后用备忘录 memo[]解决了问题，减小了复杂度。
目前的 runtime 和 memory 都不是很理想，有待改进。

**Version_2** 现在我用了 DP table 的方法做，runtime 明显优化了，但是内存还是有点大。这个题解现在存在后缀为“\_2”的文件里，之前的递归+memo 的方法存放在“\_1”的文件里。

### 56

2021/05/09

运用了快速排序算法先将 intervals 按照第一个数字升序排列

然后运用遍历的方法逐个处理重复的 interval

已过 test

### 168

2021/07/03

我的算法太占内存了 orz，抄了网上的答案
数学题还是数学公式写清楚再码代码，否则很容易就把演算过程一并写入代码了。。。

### 110

2021/07/17

没啥问题，很正常的一道递归，和官方答案一致，pass

### 133

2021/07/20

使用 hash table 来存储已经访问过的结点，然后对 neighbors 进行 DFS 递归遍历即可
tip：STL 里，hash 是 **unordered_map**

### 997

2021/07/22

图，邻接表的寻找操作，基本上是数组题

- `find_if(beg, end, [](para x){return ...})` -> 寻找 vector 里符合相关条件的元素
- `find()` -> 寻找 vector 里某个元素，如果不存在则最终位于尾后迭代器 end
- 从 itr 到 index 直接做 `(itr-vec.begin())` 即可

### 1137 & 509

2021/08/11

DP 常规操作，pass

### 198

2021/8/13

DP 解题四步骤：

- 定义子问题
- 写出子问题的递推关系
- 确定 DP 数组的计算顺序
- 空间优化（可选）

### 213

2021/8/13

成环的意思就是要么取头不取尾，要么取尾不取头
所以就 0~sz-2 做一次，1~sz-1 做一次，取较大的即可

### 740

2021/8/13

把每个数字出现的次数\*数字本身 -> 存在一个哈希数组里
这道题目就转变为打家劫舍了
有、巧妙，值得回味

### 55

2021/8/13

这题用贪心最方便，动归那个方法 worst 是 O（n 方），具体代码在-dp 里
贪心的话肯定是 O（n），状态量设置成最远距离，线性更新到最后。具体代码在-greedy 里

### 45

2021/8/14

**这是一道好题**
贪心，多维护一个状态量叫做边界 end，用来记录下一次 jump 更新的边界
这道题的核心有 2 个点：

- 在一个 end 之内，所有的结点最小跳跃次数相同
- jump 序列和 i 序列错位了一个结点（i 落后 jump 一个点位）=> 所以最后只做到 sz-1 即可！
