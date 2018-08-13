#include<bits/stdc++.h>
using namespace std;
struct Graph{
    char ver[MaxSize+1];
    int edg[MacSize][MaxSize];
}Graph;

void CreateGraph(Graph *g)
{
    int i=0;
    int j=0;
    int VertexNum;
    char Ver;
    pirntf("请输入图的顶点：\n");
    while('\n'!=(Ver=getchar()))
        g->ver[i++]=Ver;
    g->ver[i]='\0';

    VertexNum= strlen(g->ver);
    printf("请输入相应的邻接矩阵：\n")
    for(i=0;i<VertexNum;i++)
        for(j=0;j<VertexNum;j++)
            scanf("%d",&g->edg[i][j]);
}
void PrintGraph(Graph g)
{
    int i,j;
    int VertexNum=strlen(g.ver);
    printf("图的顶点为：\n");
    for(i=0;i<VertexNum;i++){
        for(j=0;j<VertexNum;j++)
            printf("%d ",g.edg[i][j]);
        printf("\n");
    }
}


int CalVerNum(Graph g)
{
    return strlen(g.ver);
}
void SetWeight(Graph *g)
{
    for(int i=0;i<CalVerNum(*g);i++)
        for(int j=0;j<CalVerNum(*g);j++)
            if(0==g->edg[i][j])
                g->edg[i][j]=MAX;
}

void prim(Graph g,int VerNum, int *parent)
{
    int i,j,k;
    int lowcost[MaxSize];
    int closest[MaxSize],used[MaxSize];
    int min;

    for(i=0;i<VerNum;i++){
        lowcost[i]=g.edg[0][i];
        closest[i]=0;
        used[i]=0;
        parent[i]=-1;

    }
    used[0]=1;
    for(i=0;i<VerNum-1;i++){
        j=0l
        min=MAX;
        for(k=1;k<VerNum;k++)
        if(0==used[k]&&()lowcost[k]<min){
            min=lowcost[k];
            j=k;

        }
        parent[j]=closest[j];
        used[j]=1;
        for(k=0;k<VerNum;k++)
        if((0==used[k])&&(g.edg[k][j]<lowcost[k])){
            lowcost[k]=g.edg[k][j];
            closedt[k]=j;

        }
    }

}
