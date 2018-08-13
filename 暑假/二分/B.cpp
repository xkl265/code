#include<stdio.h>
#include<algorithm>
using namespace std;
int n,c,a[100005];
bool f(int mid)
{
    int sum=0;
    int len=1;
    for(int i=1;i<n;i++)
    {
        sum+=a[i]-a[i-1];
        if(sum>mid)
        {
            len++;
            sum=0;
        }
    }
    if(len<c)return false;
    else return true;
}
int main()
{
    int i,mid,low,high;
    scanf("%d%d",&n,&c);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    low=a[n-1]-a[0];high=a[n-1]-a[0];
    for(i=1;i<n;i++)low=min(low,a[i]-a[i-1]);

    while(low<high)
    {
        mid=(low+high)/2;
        if(f(mid))
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    printf("%d",low);
    return 0;
}
