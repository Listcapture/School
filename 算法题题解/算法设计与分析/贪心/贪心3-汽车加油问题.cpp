#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int i,j;
    int a[n+1];
    for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int sum=a[0];//从第一站记起
    int count=0;
    for(i=0;i<=n;i++)
    {
        if((sum+a[i])<=m)
        {
            sum+=a[i];
        }
        else if(a[i]>m)
        {
            printf("No Solution!");
            return 0;
        }
        else
        {
            count++;
            sum=a[i];//更新距离
        }
    }
    printf("%d\n",count);
    return 0;
}