#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, Q, in[MAXN], out[MAXN];
vector<int> G[MAXN], v;
void dfs(int u)
{
    in[u] = v.size();
    v.push_back(u);
    for (int i = 0; i < G[u].size();i++) dfs(G[u][i]);
    out[u] = v.size()-1;
}
int main()
{
    scanf("%d%d", &n, &Q);
    for (int i = 2; i <= n; i++)
    {
        int u; scanf("%d", &u);
        G[u].push_back(i);
    }
    dfs(1);
    while (Q--)
    {
        int u, k; scanf("%d%d", &u, &k);
        if (in[u]+k-1 <= out[u]) printf("%d\n", v[in[u]+k-1]);
        else printf("-1\n");
    }
    return 0;
}
