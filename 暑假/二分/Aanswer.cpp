#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define w(a) while(a)
#define ll long long
int n,a[4005],b[4005],c[4005],d[4005],sum1[16000005],sum2[16000005],len;

int main()
{
    int i,j,ans,l,r,mid;
    w(~scanf("%d",&n))
    {
        up(i,0,n-1)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        len=0;
        up(i,0,n-1)
        up(j,0,n-1)
        sum1[len++]=a[i]+b[j];
        len=0;
        up(i,0,n-1)
        up(j,0,n-1)
        sum2[len++]=c[i]+d[j];
        ans=0;
        sort(sum2,sum2+len);
        up(i,0,len-1)
        {
            l=0,r=len-1;
            w(l<r)
            {
                mid=(l+r)>>1;
                if(sum2[mid]<-sum1[i])
                    l=mid+1;
                else
                    r=mid;
            }
            while(sum2[l]==-sum1[i]&&l<len)
            {
                ans++;
                l++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
