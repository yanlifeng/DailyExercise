#include <cstdio>
#include <iostream>
#define maxn 200010
using namespace std;
int n,m,num,head[maxn],val[maxn],dep[maxn];
int fa[maxn][30],sm[maxn][30];
struct edge{
    int pre,v;
}e[maxn*2];
void addEdge(int u,int v){
    num++;
    e[num].v=v;
    e[num].pre=head[u];
    head[u]=num;
}
void Dfs(int now,int from,int deep){
    fa[now][0]=from;
    dep[now]=deep;
    sm[now][0]=val[now];
    for(int i=head[now];i;i=e[i].pre){
        int v=e[i].v;
        if(v==from)continue;
        Dfs(v,now,deep+1);
    }
}
void getFa(){
    for(int i=1;i<=25;i++)
        for(int j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
            sm[j][i]=sm[j][i-1]^sm[fa[j][i-1]][i-1];
        }
}
int getLca(int u,int v){
    if(u==v)return val[u];
    int res=0;
    if(dep[u]<dep[v])swap(u,v);
    int df=dep[u]-dep[v];
    for(int i=20;i>=0;i--)
        if(df&(1<<i)){
            res^=sm[u][i];
            u=fa[u][i];
        }
    if(u==v)return res^val[u];
    for(int i=20;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            res^=sm[u][i];
            res^=sm[v][i];
            u=fa[u][i];
            v=fa[v][i];
        }
    return res^sm[u][0]^sm[v][0]^val[fa[u][0]];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    Dfs(1,0,0);
    getFa();
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        printf("%d\n",getLca(u,v));
    }
    return 0;
}
