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
    ll t;
    cin >> t;
    findPrimes();
    while(t--) {
        ll n,x;
        cin >> n >> x;
        
        vl pows;
        for(int i=0; i<primes.size() && x>=primes[i]; i++){
            if(x%primes[i]==0){
                int cnt=0;
                while(x%primes[i]==0){
                    cnt++;
                    x/=primes[i];
                }
                pows.pb(cnt);
            }else{
                pows.pb(0);
            }
        }

        if(x>1){
            pows.pb(1);
        }
    
        cout << pow_mod(3,4) << endl;
    }
    return 0;
}