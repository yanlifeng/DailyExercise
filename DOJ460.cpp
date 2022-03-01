#include <cstdio>
using namespace std;
int n,m,a[110],b[110];
bool dp[110][100010];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j-a[i]>=0)dp[i][j]|=dp[i-1][j-a[i]];
            if(j-b[i]>=0)dp[i][j]|=dp[i-1][j-b[i]];
        }
    }
    for(int i=0;i<=m;i++)
        if(dp[n][i])printf("1");
        else printf("0");
    printf("\n");
    return 0;
}
