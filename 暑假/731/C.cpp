#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,m,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        string s,s2;
        int ans=0,pos;
        char c[2];
        cin>>s;
        s2=string(s.rbegin(),s.rend());
        while(m--)
        {
            scanf("%d%s",&pos,&c);
            s.replace(pos-1,1,c);
            s2.replace(n-pos,1,c);
            if(!s.compare(s2))ans++;
        }
        printf("%d",ans);

    }
    return 0;
}
