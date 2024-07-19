#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

int32_t main() {
    int fact[30001];
    fact[0]=1;
    for(int i=1; i<=30000; i++){
        fact[i]=(i*fact[i-1]*1LL)%mod;
    }
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fact[n] << " ";
        for(int i=2; i<=n; i++){
            cout << (fact[i]*fact[n-i]*1LL)%mod << " ";
        }
        cout << endl;
    }
}
