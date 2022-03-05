#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#define maxn 200010
#define ll long long
using namespace std;
struct edge{
    int u,v,t,o;
}e[maxn*2];
int T,n,m,fa[maxn];
vector<int>GT[33];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool Judge(){
    int sum=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        if(e[i].o==0)continue;
        int r1=find(e[i].u);
        int r2=find(e[i].v);
        if(r1==r2)continue;
        sum++;
        fa[r1]=r2;
    }
    return sum==n-1;
}
int main(){
    //T=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int j=0;j<=32;j++)GT[j].clear();
        int u,v,t;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&t);
            e[i].u=u;
            e[i].v=v;
            e[i].t=t;
            e[i].o=1;
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<=32;j++){
                if(e[i].t&(1ll<<j)){
                    GT[j].push_back(i);
                }
            }
        }
        ll ans=0;
        vector<int>tmp;
        for(int S=32;S>=0;S--){
            tmp.clear();
            int ok=0;
            for(auto i:GT[S]){
                if(e[i].o){
                    ok=1;
                    e[i].o=0;
                    tmp.push_back(i);
                }
            }
            if(ok==0)continue;
            if(Judge())continue;
            else{
                for(auto i:tmp){
                    e[i].o=1;
                }
                ans+=1ll<<S;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
