#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ll INF = 1e15;
const ll MOD = 998244353;

ll add(ll x, ll y)  { return (x%MOD + y%MOD)%MOD; }
ll sub(ll x, ll y)  { return (x%MOD - y%MOD + MOD)%MOD; }
ll mul(ll x, ll y)  { return (x%MOD * y%MOD)%MOD; }

ll pow_mod(ll base, ll p) {
        if(p == 0)      return 1;
        ll sqrt_pow = pow_mod(base, p/2);
        ll ans = mul(sqrt_pow, sqrt_pow);
        if(p&1) ans = mul(ans, base);
        return ans;
}

vector<int> primes;
void findPrimes() {
        ll MAX = 2e5;
        vector<bool> is_prime(MAX+1, true);
        for(ll i = 2;i <= MAX;i++) {
                if(is_prime[i]) {
                        primes.push_back(i);
                        for(ll j = i*i;j <= MAX;j += i)
                                is_prime[j] = false;
                }
        }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }
    return 0;
}