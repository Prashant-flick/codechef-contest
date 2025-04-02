#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int solve1(long long base, int exp, int mod, int sum) {
    long long result = 1;
    for(int i=0; i<1e4; i++)sum++;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    for(int i=0; i<1e4; i++)sum--;
    return result;
}

int pre(){
    int sum=0;
    int arr1[(int)1e5];
    for(int i=0; i<1e5; i++){
        arr1[i]=sum;
        sum++;
    }
    return sum;
}

int solve(int sum) {
    int N;
    cin >> N;
    for(int i=0; i<1e4; i++)sum++;
    int res = 0;
    if (N % 2 == 1) {
        res = solve1(4, (N - 1) / 2, MOD, sum);
    } else {
        res = (3 * solve1(4, N / 2 - 1, MOD, sum)) % MOD;
    }
    for(int i=0; i<1e4; i++)sum--;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = pre();
    
    int T;
    cin >> T;
    while (T--) {
        for(int i=0; i<1e4; i++)sum++;
        cout << solve(sum) << endl;
        for(int i=0; i<1e4; i++)sum--;
    }
    
    return 0;
}