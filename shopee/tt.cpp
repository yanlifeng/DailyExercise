
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cassert>
#define maxn 110
using namespace std;
int n,m;
int s[maxn][maxn],vis[maxn][maxn];
vector<int>Gx[maxn*20];
vector<int>Gy[maxn*20];
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&s[i][j]);
            if(s[i][j]){
                Gx[s[i][j]].push_back(i);
                Gy[s[i][j]].push_back(j);
            }
        }
    }
    queue<int>qx;
    queue<int>qy;
    queue<int>qs;
    int nowc=s[1][1];
    if(nowc==0){
        qx.push(1);
        qy.push(1);
        qs.push(0);
        vis[1][1]=1;
    }
    for(int i=0;i<Gx[nowc].size();i++){
        int xi=Gx[nowc][i];
        int yi=Gy[nowc][i];
        qx.push(xi);
        qy.push(yi);
        qs.push(0);
        vis[xi][yi]=1;
    }
    int ok=0;
    while(!qx.empty()){
        int nowx=qx.front();
        int nowy=qy.front();
        int step=qs.front();
        qx.pop();
        qy.pop();
        qs.pop();
        if(nowx==m&&nowy==n){
            ok=1;
            printf("%d\n",step);
            break;
        }
        for(int i=0;i<4;i++){
            int nx=nowx+xx[i];
            int ny=nowy+yy[i];
            if(nx>=1&&nx<=m&&ny>=1&&ny<=n&&vis[nx][ny]==0){
                int nc=s[nx][ny];
                if(nc==0){
                    qx.push(nx);
                    qy.push(ny);
                    qs.push(step+1);
                    vis[nx][ny]=1;
                }
                for(int t=0;t<Gx[nc].size();t++){
                    int xi=Gx[nc][t];
                    int yi=Gy[nc][t];
                    if(vis[xi][yi])continue;
                    qx.push(xi);
                    qy.push(yi);
                    qs.push(step+1);
                    vis[xi][yi]=1;
                }
            }
        }
    }
    assert(ok);
    return 0;

}
