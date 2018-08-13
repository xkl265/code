#include<bits/stdc++.h>
using   namespace std;
int main()
{
    char s[1000],t[1000],c;
    int a[26],b[26],d[100000],n,i,j,ans=0;
    bool flag=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    for(i=0;i<n;i++)cin>>c,a[int(c-'a')]++,s[i]=c;
    for(i=0;i<n;i++)cin>>c,b[int(c-'a')]++,t[i]=c;
    for(i=0;i<26;i++)if(a[i]!=b[i]){flag=1;break;}
    if(flag){
        printf("-1\n");
    }else{

        for(i=0;i<n;i++){
            if(s[i]!=t[i]){
                for(j=i;j<n;j++)if(s[j]==t[i])break;

                while(j!=i)d[ans++]=j,c=s[j],s[j]=s[j-1],s[j-1]=c,j--;
                for(int f=0;f<n;f++)cout<<s[f];cout<<endl;
                for(int f=0;f<n;f++)cout<<t[f];cout<<endl;
            }

        }
        printf("%d\n%d",ans,d[0]);
        for(i=1;i<ans;i++)printf(" %d",d[i]);
    }
    return 0;

}
