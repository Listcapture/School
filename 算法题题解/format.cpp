#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int a[N],temp[N];
int n;

void merge_sort(int a[] ,int l,int r )
{
      if(l>=r)  return ;
      int mid=(l+r)>>1;
      // 根据mid将数组划分为两部分递归处理
      merge_sort(a,mid+1,r),   merge_sort(a,l,mid);
      int i=l,j=mid+1,k=0;
       while(i<=mid&&j<=r)
       {
          
        if(a[i]<=a[j])  temp[k++]=a[i++];
        else  temp[k++]=a[j++];
       }
       while(i<=mid) temp[k++]=a[i++];
       while(j<=r)  temp[k++]=a[j++];
       for(int i=l,j=0;i<=r;i++,j++)  a[i]=temp[j];
}

int main()
{
  cin>>n;
  puts("Input:");
  for(int i=0;i<n;i++)  cin>>a[i];
  merge_sort(a,0,n-1);
  puts("Sorted_Array:");
  for(int i=0;i<n;i++)  
  cout<<a[i]<<' ';
  
    
    
    return 0;
}
