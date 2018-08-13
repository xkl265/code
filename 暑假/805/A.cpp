#include<bits/stdc++.h>
using   namespace std;
int main()
{
    int a[1000+5],b[1000+5],i,l,r,n,m,ans=0;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    while(n--)
    {
        scanf("%d%d",&l,&r);
        for(i=l;i<=r;i++)
            a[i]=1;
    }
    for(i=1;i<=m;i++)if (!a[i]) b[ans++]=i;
    printf("%d\n",ans);
    for(i=0;i<ans;i++)printf("%d ",b[i]);
    return 0;
}
