#include<cstdio>
#include<algorithm>

using namespace std;
long long a[1000000];

int main()
{
    long long n,i,m,r,l,mid,sum,j;
    while(~scanf("%lld",&n))
    {
            for(i=0;i<n;i++)scanf("%lld",&a[i]);
            sort(a,a+n);
            m=(n-1)*n/4;
            if(((n-1)*n)%4)m++;
            l=0;
            r=a[n-1];
            while(l<r)
            {
                mid=(r+l)>>1;sum=0;
                for(i=1;i<n;i++)
                {
                    j=0;
                    while(a[i]-a[j]>mid)j++;
                    sum+=i-j;
            }
            if(sum>=m)r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
