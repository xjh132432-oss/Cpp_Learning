// 题目描述
// 小紫有 n 个礼物，第 i 个礼物的价值为 ai。她可以进行 k 次操作，每次操作是：
// 1. 选出当前价值最大的那个礼物（如果有多个一样大，任选一个）；
// 2. 把它的价值变成 floor(ai/2)，即除以 2 向下取整。
// 请你求出 k 次操作之后，所有礼物的价值之和。

// 输入描述:
// 第一行两个整数 n, k，表示礼物个数和操作次数。
// 第二行 n 个整数 a1, a2, ..., an，表示每个礼物的初始价值。
// 数据范围：1 <= n <= 10^5，0 <= k <= 10^5，0 <= ai <= 10^9。

// 输出描述:
// 一行一个整数，表示 k 次操作后所有礼物的价值之和。

// 示例1
// 输入:
// 3 2
// 5 3 2
// 输出:
// 5

// 示例2
// 输入:
// 1 3
// 7
// 输出:
// 0

// 示例3
// 输入:
// 2 5
// 0 0
// 输出:
// 0
#include<bits/stdc++.h>
using namespace std;

int main()
{    
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
     
    priority_queue<int> q;
     
    int n,k;
     
    cin>>n>>k;
     
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
         
        q.push(x);
    }
     
    for(int i=0;i<k;i++)
    {
        int max=q.top()/2;
         
        q.pop();
         
        q.push(max);
         
    }
     
    long long sum=0;
     
    for(int i=0;i<n;i++)
    {
        sum+=q.top();
        q.pop();
    }
     
    cout<<sum;
     
    return 0;
}
