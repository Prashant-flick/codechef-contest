#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){   
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        string s[n];
        set<int>st;
        for(int i=0; i<n; i++){
            cin >> s[i];
            int f=0,ff=0;
            for(int j=0; j<k; j++){
                if(s[i][j]=='1'){
                    f++;
                    ff=j;
                }
            }
            if(f==1){
                st.insert(ff);
            }
        }
        if(st.size()==k){
            cout<<"YES"<< endl;
        }
        else{
            cout<<"NO"<< endl;
        }
    }
    return 0;
}
