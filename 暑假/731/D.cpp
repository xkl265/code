#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000];
int main()
{
    int i,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    b[n-1]=a[n-1];
    for(i=n-2;i>=0;i--){
        if(a[i]<a[i+1])b[i]=a[i+1];
        else if(a[i]>b[i+1])b[i]=a[i];
        else b[i]=b[i+1];
    }
    for(i=0;i<n;i++){
        if(a[i]>=b[i])
            printf("%d ",-1);
            else printf("%d ",b[i]);
    }
    return 0;
}
