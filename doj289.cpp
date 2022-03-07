#include<bits/stdc++.h>
using namespace std;
int n,a[1010],ans,dp[1010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i])dp[i]=max(dp[i],dp[j]+a[i]);
        }
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}
