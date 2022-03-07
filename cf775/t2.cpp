#include <cstdio>
#include <iostream>
#define maxn 1000010
using namespace std;
int T,n,c,a[maxn],b[maxn];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&c);
        int x;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            a[x]=1;
        }
        for(int i=1;i<=c;i++){
            b[i]=b[i-1]+a[i];
        }
        int ok=1;
        for(int i=1;i<=c;i++){
            if(a[i])continue;
            for(int j=1;j*i<=c;j++){
                if(a[j]&&b[min(c,j*i+j-1)]-b[j*i-1]){
                    ok=0;
                    break;
                }
            }
            if(ok==0)break;
        }
          for(int i=1;i<=c;i++)a[i]=b[i]=0;
          if(ok)printf("Yes\n");
          else printf("No\n");
    }
    return 0;
}
