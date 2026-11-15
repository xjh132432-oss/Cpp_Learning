// 题目描述
// 给定一个长度为 n 的非降序整数数组 a1, a2, ..., an，再给定一个整数 S。
// 请你统计有多少对下标 (i, j) 同时满足 i < j 且 ai + aj <= S。

// 输入描述:
// 第一行两个整数 n, S，用空格分隔。
// 第二行 n 个整数 a1, a2, ..., an，用空格分隔，保证 a1 <= a2 <= ... <= an。
// 数据范围：1 <= n <= 2*10^5，|ai| <= 10^9，|S| <= 2*10^9。

// 输出描述:
// 一行一个整数，表示满足条件的下标对数。

// 示例1
// 输入:
// 5 6
// 1 2 3 4 5
// 输出:
// 6

// 示例2
// 输入:
// 4 -3
// -5 -2 0 4
// 输出:
// 2

// 示例3
// 输入:
// 1 10
// 7
// 输出:
// 0
#include <bits/stdc++.h>
using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     
    int n, S;
    cin >> n >> S;
     
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
     
    long long count = 0;
    for (int i = 0, j = n - 1; i < j; ) {
        long long sum = arr[i] + arr[j];
        if (sum <= S) {
            count += (j - i);
            ++i;
        } else {
            --j;
        }
    }
     
    cout << count << '\n';
    return 0;
}
