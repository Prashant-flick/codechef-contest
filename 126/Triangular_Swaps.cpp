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
        if(n==3){
            if(s[0]==s[1] && s[1]==s[2]){
                cout << 1 << endl;
                continue;
            }else{
                cout << 1 << endl;
                continue;
            }
        }
        
        int i=1;
        int ans=0;
        bool flag=false;
        bool flag2=false;
        char a=s[0];
        if(s[0]!=s[1] || s[0]!=s[2]){
            ans++;
        }else{
            flag2=true;
        }
        while(i<n-2){
            if(s[i]==s[i+1] && s[i]==s[i+2]){
                flag2=true;
            }
            else if(s[i]==a && s[i+2]==a){
                if(s[i+1]==a){
                    flag2=true;
                }
            }else{
                ans++;
            }
            a=s[i];
            i++;
        }
        if(flag2){
            ans++;
        }
        cout << ans << endl;
        
    }
}
