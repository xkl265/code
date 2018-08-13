#include<bits/stdc++.h>
using   namespace std;
long long f(long long x){
    x/=1009;
    if(x%2)return x/2+1;
    return x/2;
}
int main()
{
    long long t,a,b,c,d,sum;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)){
    sum=0;
    sum+=(b/2018-(a-1)/2018)*(d-c+1);
    sum+=(d/2018-(c-1)/2018)*(b-a+1);
    sum-=(d/2018-(c-1)/2018)*(b/2018-(a-1)/2018);
    sum+=(f(b)-f(a-1))*(d/2-(c-1)/2-(d/2018-(c-1)/2018));
    sum+=(f(d)-f(c-1))*(b/2-(a-1)/2-(b/2018-(a-1)/2018));
    printf("%lld\n",sum);}
}
