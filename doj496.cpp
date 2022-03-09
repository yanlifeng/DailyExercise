#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int n,a[1010],b[1010];
set<pair<int,int>>S;
int GCD0(int x,int y){
    if(y==0)return x;
    return GCD0(y,x%y); 
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            int dx=a[i]-a[j];
            int dy=b[i]-b[j];
            int gcd=GCD0(dx>0?dx:-dx,dy>0?dy:-dy);
            S.insert({dx/gcd,dy/gcd});
        }
    }
    printf("%d\n",S.size());
    return 0;

}
