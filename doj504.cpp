#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int n,a[200010],dp[200010],pre[200010];
map<int,int>mp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(mp.count(a[i]-1)){
            dp[i]=dp[mp[a[i]-1]]+1;
            pre[i]=mp[a[i]-1];
        }
        else{
            dp[i]=1;
        }
        mp[a[i]]=i;
        if(dp[i]>dp[ans]||(dp[i]==dp[ans]&&a[i]<a[ans]))ans=i;
    }
    printf("%d\n",dp[ans]);
    vector<int>Ans;
    while(ans){
        Ans.push_back(ans);
        ans=pre[ans];
    }
    for(int i=Ans.size()-1;i>=0;i--)
        printf("%d ",a[Ans[i]]);
    printf("\n");
    return 0;
}
