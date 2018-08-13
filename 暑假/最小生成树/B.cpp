#include<bits/stdc++.h>
using namespace std;
int mmax,soe,cas=0,i,n,m,pa[3000000+5],t,j,a[3000000+5],k;
struct ve{
    int from,to,l;
}g[3000000];
void init()
{
    for(int i=0;i<=mmax;i++)pa[i]=i;
}
void add(int a,int b,int c)
{
    g[soe].from=a;
    g[soe].to=b;
    g[soe++].l=c;
}
bool cmp1(ve a,ve b){
    return(a.l<b.l);
}
int find(int x)
{
    if(pa[x]==x)return x;
    else return pa[x]=find(pa[x]);
}
int kruskal()
{
    sort(g,g+soe,cmp1);
    int sum=0;
    init();
    for(int i=0;i<soe;i++){
        int x=find(g[i].from),y=find(g[i].to);
        if(x!=y){
           pa[x]=y;
           sum+=g[i].l;
        }
    }

    return sum;
}
int main()
{

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)scanf("%d",&a[i*m+j]);
        soe=0;
        mmax=n*m;
        for(j=0;j<m;j++)
            for(i=1;i<n;i++)k=max(a[i*m+j],a[(i-1)*m+j])-min(a[i*m+j],a[(i-1)*m+j]),add(i*m+j,(i-1)*m+j,k);
        for(i=0;i<n;i++)
            for(j=1;j<m;j++)k=max(a[i*m+j],a[i*m+j-1])-min(a[i*m+j],a[i*m+j-1]),add(i*m+j,i*m+j-1,k);
        printf("Case #%d:\n%d\n",++cas,kruskal());
    }
}
