#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
int n, m, F[maxn], num=0, head[maxn], depth[maxn], grand[maxn][25], gw[maxn][25], N, maxt[maxn][25];


struct n1{
	int u, v, w;
	bool operator < (const n1& tmp) const{
		return w<tmp.w;
	}
}a[maxn], b[maxn];//a��b������бߣ�b�����������

struct n2{
	int to, w, next;//�����С������
}e[3*maxn];

int _find(int x){
	return F[x]==x? x : F[x]=_find(F[x]);
}

void addEdg(int u, int v, int w){
	e[num].to=v;
	e[num].w=w;
	e[num].next=head[u];
	head[u]=num++;
}

ll Kruskal(){
	int cnt=0;
	ll ans=0;
	for(int i=1; i<=n; i++) F[i]=i;
	for(int i=1; i<=m; i++)
	{
		int x=_find(a[i].u), y=_find(a[i].v), w=a[i].w;
		if(x!=y)
		{

			addEdg(a[i].u, a[i].v, a[i].w);
			addEdg(a[i].v, a[i].u, a[i].w);//��˫��
			F[x]=y;
			cnt++;
			ans+=w;
			if(cnt==n-1)
				break;
		}
	}
	return ans;
}

void dfs(int x, int pre){
	for(int i=1; i<=N; i++)
	{
		grand[x][i]=grand[grand[x][i-1]][i-1];//����������
		maxt[x][i]=max(maxt[x][i-1], maxt[grand[x][i-1]][i-1]);//���������ֵ
	}

	for(int i=head[x]; i!=-1; i=e[i].next)
	{
		if(e[i].to==pre) continue;
		grand[e[i].to][0]=x;//��ʼ����������
		depth[e[i].to]=depth[x]+1;//�������
		maxt[e[i].to][0]=e[i].w;//��ʼ�����ֵ����
		dfs(e[i].to, x);
	}
}

void init(){
	N=floor(log(n+0.0)/log(2.0));//�������ݵ�����
	depth[1]=0;
	dfs(1, 0);
}

int lca(int a, int b){
	if(depth[a]>depth[b]) swap(a, b);//��֤a<=b
	int mx=0;//��ӱ���ɻ��е����ֵ����Ȼ����ñߵ����ֵ��
	for(int i=N; i>=0; i--)//�����Ʒֽ�
	{
		if(depth[a]<depth[b] &&  depth[a] <=depth[grand[b][i]] )//���depth[a]==depth[b]
		{
			mx=max(mx, maxt[b][i]);
			b=grand[b][i];
		}
	}

	for(int i=N; i>=0; i--)//�ҹ�������
	{
		if(grand[a][i]!=grand[b][i])
		{
			mx=max(mx, maxt[a][i]);
			mx=max(mx, maxt[b][i]);
			a=grand[a][i];
			b=grand[b][i];
		}
	}
	if(a!=b)//���a��b��������ô�Ϳ��Բ��ò�����һ��
	{
		mx=max( mx, maxt[a][0]);
		mx=max( mx, maxt[b][0]);
	}
	return mx;
}

int main(){
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[i].u=b[i].u=u; a[i].v=b[i].v=v; a[i].w=b[i].w=w;
	}

	sort(a+1, a+1+m);

	ll ans=0;

	ans=Kruskal();

	init();

	for(int i=1; i<=m; i++)
	{

		printf("%lld\n", ans-lca(b[i].u, b[i].v)+b[i].w);
	}

	return 0;
}
