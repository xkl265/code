#include<stdio.h>
#include<math.h>
using namespace std;
const double pi=acos(-1);
long long t,i,n,f,sum;
double r,l,mid,a[1000000];
bool sss(double mid)
{
    sum=0;
    for(i=0;i<n;i++)sum+=int(a[i]/mid);
    if(sum>=f)return 1;
    else return 0;
}

int main()
{

    scanf("%lld",&t);
    while(t--)
    {
        l=0;
        scanf("%lld%lld",&n,&f);
        for(i=0;i<n;i++){
            scanf("%lf",&a[i]);
            a[i]=a[i]*a[i]*pi;
            if(a[i]>l)l=a[i];

        }
        f+=1;
        r=0;

        while(l-r>0.00001)
        {
            mid=(r+l)/2;
            if(sss(mid))r=mid;
            else l=mid;
        }
        printf("%.4f\n",l);
    }
    return 0;
}
