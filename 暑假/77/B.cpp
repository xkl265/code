#include<bits/stdc++.h>
using namespace std;

char arc[100000+5][100000+5];
int minqua,mindis,qua,dis,visited[100000],n,d,first;
void DFS(int v)
{
	int j;
	qua++;
	bool test=0;
	visited[v-1]=1;
    for(j=0;j<n;j++)
        if(arc[v][j]!=0&&visited[j]==0)
			{dis+=arc[v][j];DFS(j);dis-=arc[v][j];test=1;}
    if(!test)
    {
        if(mindis==0){mindis=dis;minqua=qua;}
        else if(mindis>dis){mindis=dis;minqua=qua;}

    }
    qua--;
}
int main()
{
    int T,a,b,i,j;
    cin>>T;
    while(T--)
    {
        cin>>n>>d>>first;
        minqua=0;
        mindis=0;
        qua=0;
        dis=0;
        memset(arc,0,sizeof(arc));
        memset(visited,0,sizeof(visited));
        while(d--)
        {
            cin>>a>>b>>i;
            arc[b-1][a-1]=i;
        }
        DFS(first-1);
        cout<<minqua<<' '<<mindis<<endl;
	}


}
