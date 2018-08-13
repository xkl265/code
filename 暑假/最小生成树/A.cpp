#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,t,pa[20000],i,minn,maxn,fib[25],cas=0;
struct ve{
    int from,to,l;
}g[20000];
void f()
{
    fib[0]=1;
    fib[1]=1;
    for(i=2;i<=23;i++)fib[i]=fib[i-1]+fib[i-2];
}
void init()
{
    for(i=1;i<=n;i++)pa[i]=i;
}
bool cmp1(ve a,ve b){
    return(a.l<b.l);
}
bool cmp2(ve a,ve b){
    return(a.l>b.l);
}
int find(int x)
{
    if(pa[x]==x)return x;
    else return pa[x]=find(pa[x]);
}
int kruskal1()
{
    sort(g,g+m,cmp1);
    int ans=1,sum=0;
    init();
    for(i=0;i<m;i++){
        int x=find(g[i].from),y=find(g[i].to);
        if(x!=y){
           ans++;
           pa[x]=y;
           sum+=g[i].l;
        }
        if(ans==n)break;
    }
    if(ans<n)return -1;
    else return sum;
}
int kruskal2()
{
    sort(g,g+m,cmp2);
    int ans=1,sum=0;
    init();
    for(i=0;i<m;i++){
        int x=find(g[i].from),y=find(g[i].to);
        if(x!=y){
           ans++;
           pa[x]=y;
           sum+=g[i].l;
        }
        if(ans==n)break;
    }
    if(ans<n)return -1;
    else return sum;

}

int main()
{

    bool flag;
    scanf("%d",&t);
    f();
    while(t--)
    {
        scanf("%d%d",&n,&m);
        flag=0;
        for(i=0;i<m;i++)scanf("%d%d%d",&g[i].from,&g[i].to,&g[i].l);
        minn=kruskal1();
        maxn=kruskal2();
        for(i=1;i<=23;i++)if(fib[i]<=maxn&&fib[i]>=minn)flag=1;
        if(flag)printf("Case #%d: Yes\n",++cas);
        else printf("Case #%d: No\n",++cas);
    }

    return 0;
}
