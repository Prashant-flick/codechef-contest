#include <bits/stdc++.h>
using namespace std;
#define int long long;

int32_t main() {
    vector<int> is_prime(1000001, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < 1000001; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 1000001 ; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if(k%2==0){
            cout << 2*k << endl;
            continue;
        }

        int p=2;
        for(; p<=k; p++){
            if(is_prime(p){
                if(k%i==0)break;
            }   
        }
        return k;



        cout << result << endl;
    }
    return 0;
}