#include <iostream>
using namespace std;
string s,t;
int T,n,m;
int main(){
    cin>>T;
    while(T--){
        cin>>s>>t;
        n=s.length();
        m=t.length();
        if(n!=m){
            cout<<"NO"<<endl;
            continue;

        }
        int ok1=0;
        int ok2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')ok1=1;
            if(t[i]=='1')ok2=1;

        }
        if(ok1^ok2==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;

}
