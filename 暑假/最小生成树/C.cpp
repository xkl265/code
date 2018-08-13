#include<bits/stdc++.h>
using namespace std;
int i,n,m,pa[3000+5],t,j,k,minn,s;
struct ve{
    int from,to,l;
}g[3000+5];
void init()
{
    for(int i=0;i<=3000;i++)pa[i]=i;
}
bool cmp1(ve a,ve b){
    return(a.l<b.l);
}
int find(int x)
{
    if(pa[x]==x)return x;
    else return pa[x]=find(pa[x]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%d%d%d",&g[i].from,&g[i].to,&g[i].l);
    sort(g,g+m,cmp1);
    scanf("%d",&k);
    while(k--)
    {
        minn=INT_MAX;
        scanf("%d%d",&s,&t);
        for(i=0;i<m;i++)
        {
            init();
            for(j=i;j<m;j++){
                int x=find(g[j].from),y=find(g[j].to);
                if(x!=y){
                    pa[x]=y;
                }

                if(find(s)==find(t)){minn=min(minn,g[j].l-g[i].l);break;}
            }
            if(find(s)!=find(t))break;
        }
        if(minn==INT_MAX)printf("-1");
        else printf("%d\n",minn);
    }
    return 0;

}
