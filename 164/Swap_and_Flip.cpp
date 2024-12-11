#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int zero=0,zero2=0;
        int ones=0,ones2=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                zero++;
            }else{
                ones++;
            }
            if(t[i]=='0'){
                zero2++;
            }else{
                ones2++;
            }
        }
        if(zero==zero2){
            cout << "YES" << endl;
        }else if(ones%2==ones2%2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
