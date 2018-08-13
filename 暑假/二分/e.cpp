#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long i,m,n,a[1000000],cnt,l,low,hi,mid;
bool sss(long long mid)
{
    cnt=0;
    long long sum=0;
    for(i=1;i<=n;i++){
        sum+=a[i]-a[i-1];
        if(sum<mid){
            cnt++;
        }else
        sum=0;

    }
//    cout<<cnt<<endl;
    if(cnt<=m)return true;
    else return false;
}
int main()
{

    scanf("%d%d%d",&l,&n,&m);
    a[0]=0;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=l;
    sort(a+1,a+n+2);
    low=0;hi=l;
    for(i=1;i<=n+1;i++)low=min(low,a[i]-a[i-1]);
    while(low<hi)
    {
        mid=(low+hi)>>1;
        if(sss(mid)) low=mid;
        else hi=mid;
     //   cout<<low<<' '<<hi<<' '<<mid<<endl;
    }
    cout<<mid<<endl;
    return 0;

}
