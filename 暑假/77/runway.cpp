#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,re;
    cin>>n;
    while(n--)
    {

        cin>>a;
        re=a/10;
        if(a%10>=5)re++;
        if(re==0)re=18;
        if(re>18)re-=18;
        printf("%02d\n",re);

    }
    return 0;
}
