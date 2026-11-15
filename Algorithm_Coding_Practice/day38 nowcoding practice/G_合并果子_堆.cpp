// 题目描述
// 小紫在旧货市场盘下一个打包摊位，帮人把零散货物捆成一件寄走。摊位上摆着 n 个包裹，
// 第 i 个包裹重 ai 克（有的包裹可能是空的，重量为 0）。
// 摊位规定，一单货必须恰好捆成一件才能交货，而捆包只能两个两个地做：
// 每次从摊位上任意挑出两个包裹，用胶带把它们缠成一个，摊位上的包裹数量就减少一个。
// 麻烦出在记账上。每完成一次捆包，老板都要把这次合并得到的那个包裹整个再称一遍，
// 把称出的克数记进账本；而称重是要花时间的，称出的克数是多少，就要花多少秒
// （例如称出 7 克就要 7 秒），账本上这些秒数累加起来，就是这一单的总工时。
// 胶带本身不计工时。
// 每单的收费按总工时折算，所以小紫要自己决定先捆哪两个、后捆哪两个。
// 请你帮她算一算：把这 n 个包裹捆成一件，最少需要多少秒的总工时。
// （如果摊位上本来就只有一件包裹，那不需要捆包，总工时为 0 秒。）

// 输入描述:
// 第一行一个整数 n，表示包裹的个数。
// 第二行 n 个整数 a1, a2, ..., an，表示每个包裹的重量（克）。
// 数据范围：1 <= n <= 10^5，0 <= ai <= 10^9。

// 输出描述:
// 一行一个整数，表示把这 n 个包裹捆成一件所需的最少总工时（秒）。

// 示例1
// 输入:
// 3
// 1 2 3
// 输出:
// 9

// 示例2
// 输入:
// 1
// 5
// 输出:
// 0

// 示例3
// 输入:
// 4
// 1 1 1 1
// 输出:
// 8
#include <bits/stdc++.h>
using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    priority_queue<long long, vector<long long>, greater<long long>> pq;
     
    int n;
    cin >> n;
     
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        pq.push(x);
    }
     
    long long totalTime = 0;
     
    while (pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
         
        long long merged = first + second;
        pq.push(merged);
        totalTime += merged;
    }
     
    cout << totalTime;
    return 0;
}
