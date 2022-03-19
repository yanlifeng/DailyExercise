#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define ll long long
#define maxn 300010
using namespace std;
ll n,m,d;
ll dp[310][maxn];
struct node{
    ll a,b,t;
}c[310];
ll inputque[maxn];
ll indexque[maxn];
ll mxtmp[maxn];
int main(){
    scanf("%lld%lld%lld",&n,&m,&d);
    for(ll i=1;i<=m;i++){
        scanf("%lld%lld%lld",&c[i].a,&c[i].b,&c[i].t);
    }
    for(ll i=0;i<=m;i++)
        for(ll j=0;j<=n*2;j++){
            dp[i][j]=-1e15;
            inputque[j]=-1e15;
        }
    for(ll i=0;i<=n;i++)dp[0][i]=0;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++)inputque[j]=dp[i-1][j];
        ll dis=c[i].t-c[i-1].t;
        dis=dis*d;
        dis=min(dis,1ll*n);
        ll M=dis*2+1;
        M=min(M,2ll*n);
        ll rear=-1, front=0;
        for(ll j=1;j<=n*2;j++){
            if (rear+1 == front) indexque[++rear] = j;   
            else{
                while (inputque[j] >= inputque[indexque[rear]] && rear>=front) --rear;         
                indexque[++rear] = j; 
                if (j - indexque[front] == M) ++front;    
            }
            ll anss = inputque[indexque[front]];
            mxtmp[j]=anss;
        }
        for(ll j=1;j<=n;j++){
            dp[i][j]=mxtmp[j+dis];
            dp[i][j]+=c[i].b-fabs(c[i].a-j);
        }
    }
    ll ans=-1e15;
    for(ll i=0;i<=n;i++)
        ans=max(ans,dp[m][i]);
    printf("%lld\n",ans);
    return 0;
}

/*
   100 4 3
   4 454 66
   78 3242 90
   23 343 90
   12 43232 99



 * */
