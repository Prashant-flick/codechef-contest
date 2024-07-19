#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans;
        for(int i=0; i<n; i++){
            if(k){
                if(s[i]=='0'){
                    ans+=s[i];
                }else{
                    k--;
                }
            }else{
                ans+=s[i];
            }
        }
        while(k-- && ans.size()>1){
            ans.pop_back();
        }
        cout << ans << endl;
    }
}
