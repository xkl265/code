#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll i,t,a[1000000],k,mid;
bool f(ll midd)
{
    ll cnt=0;
    for(i=0;i<t;i++)
    {
        if(a[i]>midd)
        {
            cnt+=(a[i]-midd)/(k-1);
            if((a[i]-midd)%(k-1))
            cnt++;
        }
    }
     if(cnt<=midd)
        return true;
        else return false;
}
int main()
{
    ll maxn=0,low=1;
    scanf("%d",&t);
    for(i=0;i<t;i++){scanf("%d",&a[i]);maxn=max(a[i],maxn);}
    scanf("%d",&k);
    if(k==1)
    {
        printf("%d",maxn);
        return 0;
    }
    while(low<maxn)
    {
        mid=(low+maxn)>>1;
        if(f(mid))maxn=mid;
        else low=mid+1;
    }
    printf("%d",maxn);
    return 0;
}
