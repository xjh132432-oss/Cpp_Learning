// 题目描述
// 小蓝的学校有 n 名学生，编号 1 ~ n。一开始每名学生各自是一个社团。
// 接下来有 m 条消息，每条消息是下面两种之一：
// 1 u v：表示 u 和 v 现在所在的社团合并成一个社团；
// 2 u v：询问 u 和 v 现在是否在同一个社团里。
// 对于每条 2 u v，如果两人在同一个社团输出 YES，否则输出 NO。

// 输入描述:
// 第一行两个整数 n, m，表示人数和消息条数。
// 接下来 m 行，每行三个整数 t, u, v，含义如上。
// 数据范围：1 <= n, m <= 2*10^5，t 属于 {1, 2}，1 <= u, v <= n，保证至少有一条 2 u v。

// 输出描述:
// 按输入中 2 u v 出现的顺序，每条输出一行 YES 或 NO。

// 示例1
// 输入:
// 4 5
// 2 1 2
// 1 1 2
// 2 1 2
// 1 3 4
// 2 2 4
// 输出:
// NO
// YES
// NO

// 示例2
// 输入:
// 1 2
// 2 1 1
// 1 1 1
// 输出:
// YES
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int p[N];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
    }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)p[i]=i;
    while(m--){
      int t,u,v;
      cin>>t>>u>>v;
      int ru=find(u);
      int rv=find(v);
      if(t==1){
         p[ru]=rv;
      }else{
         if(ru!=rv){
             cout<<"NO"<<"\n";
         }else{
             cout<<"YES"<<"\n";
         }
      }
    }
    return 0;
}
