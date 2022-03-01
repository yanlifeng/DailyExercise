#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 500010

using namespace std;
int n,k1,k2;
int fa[maxn][30],mx[maxn][30],mn[maxn][30],dep[maxn];
ll dp[maxn][2];
ll ans=0;
int head[maxn],num;
struct edge{
    int v,pre;
}e[maxn*2];
void addEdge(int u,int v){
    num++;
    e[num].v=v;
    e[num].pre=head[u];
    head[u]=num;
}
void Dfs(int now,int from,int deep,int val){
    fa[now][0]=from;
    dep[now]=deep;
    mx[now][0]=max(now,val);
    mn[now][0]=min(now,val);
    for(int i=head[now];i;i=e[i].pre){
        int v=e[i].v;
        if(v==from)continue;
        Dfs(v,now,deep+1,now);
    } 
}
void getFa(){
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
            mx[i][j]=max(mx[i][j-1],mx[fa[i][j-1]][j-1]);
            mn[i][j]=min(mn[i][j-1],mn[fa[i][j-1]][j-1]);
        }
}
pair<int,int> getLCA(int a,int b){
    int ret_mx=max(a,b);
    int ret_mn=min(a,b);
    if(dep[a]<dep[b])swap(a,b);
    int t=dep[a]-dep[b];
    for(int i=0;i<=20;i++)
        if(t&(1<<i)){
            ret_mx=max(ret_mx,mx[a][i]);
            ret_mn=min(ret_mn,mn[a][i]);
            a=fa[a][i];
        }
    if(a==b)return {ret_mx,ret_mn};
    for(int i=20;i>=0;i--)
        if(fa[a][i]!=fa[b][i]){
            ret_mx=max(ret_mx,mx[a][i]);
            ret_mx=max(ret_mx,mx[b][i]);
            ret_mn=min(ret_mn,mn[a][i]);
            ret_mn=min(ret_mn,mn[b][i]);
            a=fa[a][i];
            b=fa[b][i];
        }
    ret_mx=max(ret_mx,mx[a][0]);
    ret_mx=max(ret_mx,mx[b][0]);

    ret_mn=min(ret_mn,mn[a][0]);
    ret_mn=min(ret_mn,mn[b][0]);
    return {ret_mx,ret_mn};

}
bool Judge(int x,int y,int mx,int mn){
    return mn>=min(x,y)-k1&&mx<=max(x,y)+k2;
}
void Dfs0(int now,int from){
    dp[now][0]=1;
    for(int i=head[now];i;i=e[i].pre){
        int v=e[i].v;
        if(v==from)continue;
        Dfs0(v,now);
        if(v<now)dp[now][0]+=dp[v][0];
    }
}
void Dfs1(int now,int from){
    if(from<now)dp[now][1]=dp[from][1]+dp[from][0];
    else dp[now][1]=0;
    for(int i=head[now];i;i=e[i].pre){
        int v=e[i].v;
        if(v==from)continue;
        Dfs1(v,now);
    }
}
int main(){
    
    freopen("/Users/ylf9811/Downloads/test.in","r",stdin);
    scanf("%d%d%d",&n,&k1,&k2);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    if(n<=0){
        Dfs(1,0,0,0);
        mn[1][0]=1;
        mx[1][0]=1;
        getFa();
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                auto res=getLCA(i,j);
                if(Judge(i,j,res.first,res.second)){
                    ans++;
                }
                //  ans++;
            }
        }
        printf("%lld\n",ans);
    }else{
        printf("111\n");
        Dfs0(1,0);
        printf("111\n");
        Dfs1(1,0);
        printf("111\n");
        for(int i=1;i<=n;i++){
            printf("%d %d %d\n",i,dp[i][0],dp[i][1]);
            ans+=dp[i][0]+dp[i][1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
6 1 0
6 4
6 5
4 1
4 3
5 2

*/

