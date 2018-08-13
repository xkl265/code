#include<bits/stdc++.h>
using   namespace std;
unsigned long long a[10000],b[10000],c[10000];
bool cmp(int h,int g){
    return((a[g]+b[g]+c[g])*(c[h])>(a[h]+b[h]+c[h])*(c[g]));
}
int main()
{
    int i,n,d[10000];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i],d[i]=i;
        sort(d,d+n,cmp);
        for(i=0;i<n;i++)cout<<d[i]+1<<' ';
        cout<<endl;
    }
    return 0;
}
