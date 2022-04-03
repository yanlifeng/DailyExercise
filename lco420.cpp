#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
short n,m,dp[51][21][65][2][8];
short ss[65];
short mp[565];
inline short min(short a,short b){
    return a<b?a:b;
}
inline short upSta(short S,short k){
    if(k>='a'&&k<='z')S|=1;
    if(k>='A'&&k<='Z')S|=2;
    if(k>='0'&&k<='9')S|=4;
    return S;
}
inline bool okSta(short S,short k){
    if(k>='a'&&k<='z'&&(S&1)==0)return 0;
    if(k>='A'&&k<='Z'&&(S&2)==0)return 0;
    if(k>='0'&&k<='9'&&(S&4)==0)return 0;
    return 1;
}
inline void updateState(short i1,short j1,short k1,short o1,short s1,short i2,short j2,short k2,short o2,short s2,short val){
    if(i1<0||j1<0)return;
    if(!okSta(s1,ss[k1]))return;
    if(!okSta(s2,ss[k2]))return;
    dp[i2][j2][k2][o2][s2]=min(dp[i2][j2][k2][o2][s2],dp[i1][j1][k1][o1][s1]+val);
}
short strongPasswordChecker(string s){
    n=s.length();
    set<int>S;
    for(int i=0;i<n;i++)
        S.insert(s[i]);
    int las;
    las=2;
    for(int i='a';i<='z'&&las>0;i++){
        if(S.find(i)!=S.end())continue;
        S.insert(i);
        las--;
    }
    las=2;
    for(int i='A';i<='Z'&&las>0;i++){
        if(S.find(i)!=S.end())continue;
        S.insert(i);
        las--;
    }
    las=2;
    for(int i='0';i<='9'&&las>0;i++){
        if(S.find(i)!=S.end())continue;
        S.insert(i);
        las--;
    }
    for(auto it:S){
        ss[m]=it;
        mp[it]=m++;
    }
    short res=1000;
    for(short i=0;i<n;i++)
        for(short j=0;j<=20;j++)
            for(short k=0;k<m;k++)
                for(short S=0;S<8;S++)
                    dp[i][j][k][0][S]=dp[i][j][k][1][S]=1000;
    dp[0][1][mp[s[0]]][0][upSta(0,s[0])]=0;
    for(short k=0;k<m;k++)
        dp[0][0][k][0][0]=1;
    for(short k=0;k<m;k++)
        if(ss[k]!=s[0])dp[0][1][k][0][upSta(0,ss[k])]=1;
    for(short j=2;j<=20;j++)
        for(short w=0;w<m;w++)
            for(short k=0;k<m;k++)
                for(short S=0;S<8;S++){
                    if(!okSta(S,ss[k]))continue;
                    short nS=upSta(S,ss[w]);
                    if(k!=w)dp[0][j][w][0][nS]=min(dp[0][j][w][0][nS],dp[0][j-1][k][0][S]+1);
                    if(k!=w)dp[0][j][w][0][nS]=min(dp[0][j][w][0][nS],dp[0][j-1][k][1][S]+1);
                    dp[0][j][w][1][nS]=min(dp[0][j][w][1][nS],dp[0][j-1][w][0][S]+1);
                }
    for(short i=1;i<n;i++)
        for(short j=0;j<=20;j++){
            //use s[i]
            for(short k=0;k<m;k++)
                for(short S=0;S<8;S++){
                    short si=mp[s[i]];
                    short nS=upSta(S,s[i]);
                    if(ss[k]!=s[i])updateState(i-1,j-1,k,0,S,i,j,si,0,nS,0);
                    if(ss[k]!=s[i])updateState(i-1,j-1,k,1,S,i,j,si,0,nS,0);
                    updateState(i-1,j-1,si,0,S,i,j,si,1,nS,0);
            }
            //del s[i]
            for(short k=0;k<m;k++)
                for(short S=0;S<8;S++){
                    short nS=S;
                    updateState(i-1,j,k,0,S,i,j,k,0,nS,1);
                    updateState(i-1,j,k,1,S,i,j,k,1,nS,1);
                }
            //change s[i]
            for(short w=0;w<m;w++){
                for(short k=0;k<m;k++)
                    for(short S=0;S<8;S++){
                        short nS=upSta(S,ss[w]);
                        if(k!=w)updateState(i-1,j-1,k,0,S,i,j,w,0,nS,1);
                        if(k!=w)updateState(i-1,j-1,k,1,S,i,j,w,0,nS,1);
                        updateState(i-1,j-1,w,0,S,i,j,w,1,nS,1);
                    }
            }
            //insert 
            for(short w=0;w<m;w++)
                for(short k=0;k<m;k++)
                    for(short S=0;S<8;S++){
                        short nS=upSta(S,ss[w]);
                        if(k!=w)updateState(i,j-1,k,0,S,i,j,w,0,nS,1);
                        if(k!=w)updateState(i,j-1,k,1,S,i,j,w,0,nS,1);
                        updateState(i,j-1,w,0,S,i,j,w,1,nS,1);
                    }
        }
    for(short j=6;j<=20;j++)
        for(short k=0;k<m;k++){
            res=min(res,dp[n-1][j][k][0][7]);
            res=min(res,dp[n-1][j][k][1][7]);
        }
    return res;
}
int32_t main(){
    
    string s;
    //cin>>s;
    s="ABABABABABABABABABAB1";
    cout<<strongPasswordChecker(s)<<endl;
    return 0;
}
