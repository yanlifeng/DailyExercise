#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define maxn 100010
using namespace std;
int n,m;
vector<int>Gx[maxn];
vector<int>Gy[maxn];
int main(){
    scanf("%d%d",&n,&m);
    int cl;
    int mxcl=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&cl);
            Gx[cl].push_back(i);
            Gy[cl].push_back(j);
            mxcl=max(mxcl,cl);
        }
    }
    ll ans=0;
    for(int i=1;i<=mxcl;i++){
        if(Gx[i].size()==0)continue;
        sort(Gx[i].begin(),Gx[i].end());
        sort(Gy[i].begin(),Gy[i].end());
        for(int j=1;j<=Gx[i].size();j++){
            ans+=1ll*Gx[i][j-1]*(j-1)-1ll*Gx[i][j-1]*(Gx[i].size()-j);
            ans+=1ll*Gy[i][j-1]*(j-1)-1ll*Gy[i][j-1]*(Gy[i].size()-j);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
