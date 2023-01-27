#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

/*
andrew算法
1.将所有点按照x升序，y升序排序
2.用一个栈维护凸包，判重数组标记所有在栈中的点
3.从1-n枚举点，求解上凸包
4.把第一个点标记为未使用，求解下凸包。
信用卡凸包，多边形内角和为360度，恰好构成一个园周，同时
利用平行线构造出一个凸多边形。
*/
typedef pair<double, double> PDD;
const int N = 40010;
const double pi = acos(-1);

int n, cnt;
PDD q[N];
int stk[N], top;
bool used[N];

PDD rotate(PDD a, double b)
{
    return {a.x * cos(b) + a.y * sin(b), -a.x * sin(b) + a.y * cos(b)};
}

PDD operator- (PDD a, PDD b)
{
    return {a.x - b.x, a.y - b.y};
}

double cross(PDD a, PDD b)
{
    return a.x * b.y - a.y * b.x;
}

double area(PDD a, PDD b, PDD c)
{
    return cross(b - a, c - a);
}

double get_dist(PDD a, PDD b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double andrew()
{
    sort(q, q + cnt);
    for (int i = 0; i < cnt; i ++ )
    {
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
        {
            // 凸包边界上的点即使被从栈中删掉，也不能删掉used上的标记
            if (area(q[stk[top - 1]], q[stk[top]], q[i]) < 0)
                used[stk[top -- ]] = false;
            else top -- ;
        }
        stk[ ++ top] = i;
        used[i] = true;
    }
    used[0] = 0;
    for (int i = cnt - 1; i >= 0; i -- )
    {
        if (used[i]) continue;
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
            top -- ;
        stk[ ++ top] = i;
    }
    for(int i=1;i<=top;i++)
    {
      cout<<q[stk[i]].x<<" "<<q[stk[i]].y<<endl;
    }
    double res = 0;
    for (int i = 2; i <= top; i ++ )
        res += get_dist(q[stk[i - 1]], q[stk[i]]);
    return res;
}

int main()
{
    scanf("%d", &n);
    double a, b, r;
    scanf("%lf%lf%lf", &a, &b, &r);
    a = a / 2 - r, b = b / 2 - r;
    int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, -1, 1};
    while (n -- )
    {
        double x, y, z;
        scanf("%lf%lf%lf", &x, &y, &z);
        for (int i = 0; i < 4; i ++ )
        {
            auto t = rotate({dx[i] * b, dy[i] * a}, -z);
            q[cnt ++ ] = {x + t.x, y + t.y};
        }
    }

    double res = andrew();
    printf("%.2lf\n", res + 2 * pi * r);

    return 0;
}