#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n,e;
        cin >> n >> e;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        const int mod = 1e9 + 7;
        int b = e;
        int d = n/2;

        int b_inv = 1;
        int exponent = mod - 2;
        int base = b;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                b_inv = (1LL * b_inv * base) % mod;
            }
            base = (1LL * base * base) % mod;
            exponent /= 2;
        }

        int d_inv = 1;
        exponent = mod-2;
        base = d;
        while(exponent>0){
            if (exponent % 2 == 1) {
                d_inv = (1LL * d_inv * base) % mod;
            }
            base = (1LL * base * base) % mod;
            exponent /= 2;
        }

        int res = (1LL * ((2*e)/3) * b_inv) % mod;
        int res2 = (1LL * (n/2) * d_inv) % mod;

        cout << (res*res2)%mod << endl;
    }
    
    return 0;
}
