#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a=0,b=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='A'){
                if(b>0){
                    b--;
                    a++;
                }else{
                    a++;
                    ans++;
                }
            }else{
                if(a>0){
                    a--;
                    b++;
                }else{
                    b++;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
