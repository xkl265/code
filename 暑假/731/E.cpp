    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        long long z,t,i,n,k,sum,ave,ans,a[500000];
        scanf("%d",&t);
        for(z=1;z<=t;z++)
        {
            scanf("%d%d",&n,&k);
            sum=0;
            for(i=0;i<n;i++)scanf("%d",&a[i]),sum+=a[i];
            if(sum%k)printf("Case #%d: -1\n",z);
            else{
                ave=sum/k;
                ans=0;
                sum=0;
                for(i=0;i<n;i++){
                    if(sum)ans++;
                    sum+=a[i];
                    if(sum>=ave){ans+=sum/ave;sum=sum%ave;if(!sum)ans--;}

                }
                printf("Case #%d: %d\n",z,ans);
            }
        }
        return 0;
    }
