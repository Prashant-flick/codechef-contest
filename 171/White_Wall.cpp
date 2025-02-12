#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans=INT_MAX;
        vector<string> vec = {"RGB", "RBG", "GBR", "GRB", "BGR", "BRG"};
        for(int i=0; i<6; i++){
            int res=0;
            for(int j=0; j<n; j++){
                if(s[j]!=vec[i][j%3]){
                    res++;
                }
            }
            ans=min(ans,res);
        }
        cout << ans << endl;
    }
}
