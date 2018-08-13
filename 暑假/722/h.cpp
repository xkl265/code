#include<bits/stdc++.h>
#include<queue>
using namespace std;
typedef unsigned long long  ull;

ull gcd(ull a,ull b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    ull a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",a*b/gcd(a,b));
    return 0;

}
