#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define pb(x) push_back(x)

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
        ll a[n];
        ll b[n];
        vi ao, ae, bo, be;
        cin >> a[0];
        ae.pb(a[0]);
        for(int i = 1; i < n; i++) {
            cin >> a[i];
            a[i]+=a[i-1];
            if(i%2!=0)ao.pb(a[i]);
            else ae.pb(a[i]);
        }

        cin >> b[0];
        be.pb(b[0]);
        for(int i = 1; i < n; i++) {
            cin >> b[i];
            b[i]+=b[i-1];
            if(i%2!=0)bo.pb(b[i]);
            else be.pb(b[i]);
        }

        sort(ae.begin(),ae.end());
        sort(be.begin(),be.end());
        sort(ao.begin(),ao.end());
        sort(bo.begin(),bo.end());
        if(ae == be && ao == bo && a[n-1]==b[n-1])cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}