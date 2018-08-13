#include<bits/stdc++.h>
using namespace std;
long long psum[200000+5];
int main()
{
    long long n,res=0,l,r,a;
    scanf("%lld",&n);
    memset(psum,0,sizeof(psum));
    scanf("%lld",&psum[0]);
    for(int i=1;i<n;i++)scanf("%lld",&a),psum[i]=psum[i-1]+a;
    l=0;
    r=n-1;
    while(l<r){
        if(psum[l]==psum[n-1]-psum[r-1]) {res=psum[l];if (l < n-1)
					l++;
				else if (r > 0)
					r--;
}
        else if(psum[l]>psum[n-1]-psum[r-1]) r--;
        else l++;
    }
    printf("%d",res);
    return 0;
}
