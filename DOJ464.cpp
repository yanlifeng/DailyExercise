#include <cstdio>
#include <iostream>
#include <algorithm>
#define maxn 100010
#define mid (l+r)/2
using namespace std;
int T,n,num,m,a[maxn],A[maxn];
int s[maxn*30],lc[maxn*30],rc[maxn*30],r[maxn*30],cnt;
int Build(int S,int L,int R){
    cnt++;
    s[cnt]=S;
    lc[cnt]=L;
    rc[cnt]=R;
    return cnt;
}
void Insert(int &now,int pre,int l,int r,int k){
    now=Build(s[pre]+1,lc[pre],rc[pre]);
    if(l==r)return;
    if(k<=mid)Insert(lc[now],lc[pre],l,mid,k);
    else Insert(rc[now],rc[pre],mid+1,r,k);
}
int Query(int L,int R,int x,int y,int l,int r){
    if(x<=l&&y>=r)return s[R]-s[L];
    int res=0;
    if(x<=mid)res+=Query(lc[L],lc[R],x,y,l,mid);
    if(y>mid)res+=Query(rc[L],rc[R],x,y,mid+1,r);
    return res;
}
int main(){
    scanf("%d",&T);
    while(T--){
        cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            A[i]=a[i];
        }
        sort(A+1,A+1+n);
        num=unique(A+1,A+1+n)-A-1;
        for(int i=1;i<=n;i++){
            int pos=lower_bound(A+1,A+1+num,a[i])-A;
            Insert(r[i],r[i-1],1,num,pos);
        }
        int L,R,K;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&L,&R,&K);
            int pos=upper_bound(A+1,A+1+num,K)-A-1;
            if(pos<1)printf("0 ");
            else printf("%d ",Query(r[L-1],r[R],1,pos,1,num));
        }
        printf("\n");
        for(int i=0;i<=cnt;i++){
            r[i]=lc[i]=rc[i]=s[i]=0;
        }
    }

    return 0;
}
