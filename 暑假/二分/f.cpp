#include<cstdio>
#include<algorithm>

using namespace std;
long long i,n,m,a[1000000],hi,low,mid;
bool sss(long long mid)
{
    long long sum=0,cnt=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>mid){
            cnt++;
            sum=a[i];
        }else
        if(sum==mid){
            cnt++;
            sum=0;
        }

    }
    cnt++;
    if(cnt<=m)return true;
    else return false;

}
int main(){

    scanf("%lld%lld",&n,&m);low=0;
    for(i=0;i<n;i++)scanf("%d",&a[i]),hi+=a[i],low=max(low,a[i]);

    while(low<hi){
        mid=(hi+low)>>1;
        if(sss(mid))hi=mid;
        else low=mid+1;
    }
    printf("%lld\n",low);
    return 0;

}
