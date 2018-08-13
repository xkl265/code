#include <stdio.h>
#include <algorithm>
using namespace std;
int t,n,a[4005],b[4005],c[4005],d[4005],e[16000005],f[16000005],l,r,mid;
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    int len=0;
    for(int i=0;i<t;i++)
        for(int j=0;j<t;j++)
        {
            e[len]=a[i]+b[j];f[len++]=c[i]+d[j];
        }
    sort(e,e+len);
    sort(f,f+len);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        l=0;r=len-1;
        while(l<r)
        {
            mid=(l+r)/2;
            if(e[i]+f[mid]<0)l=mid+1;
            else r=mid;
        }
        while(e[i]+f[l]==0&&l<len)
        {
            ans++;
            l++;
        }
    }
    printf("%d",ans);
    return 0;


}
