#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int main()
{
    long long  t,ze,n,cnt=0,i;
    int len,a;
    scanf("%lld",&t);
    while(t--)
    {
        ze=0;
        len=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a);
            if(a==0)ze++;
            else{
                a-=ze;
                int p=lower_bound(b,b+len,a)-b;
                if(len==p) b[len++]=a;
                else b[p]=a;

            }
        }

        printf("Case #%lld: %lld\n",++cnt,len+ze);
    }

}
