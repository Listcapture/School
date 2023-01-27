#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=4e5+10;//用无向图表示一颗树数组要开两倍
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) (x&-x)
const double eps=1e-8;
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
// 距离当前结点距离小于d的结点编号
/*
  首先最终每行数组的1的个数必须相同；
  可以按列枚举，预处理每一列中多一，少1的位置
  ，作为可操作数，如果某一行的1的个数不够，在进行处理。
  //runtime error rep表达式问题
*/

void solve()
{
 

}

int main()
{
    int tt;
    cin>>tt;
    startTime = clock();
    while(tt--)
    {
        solve();
        

        //printf("%.2lf",getCurrentTime());
    }
}


