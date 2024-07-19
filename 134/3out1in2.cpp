#include "bits/stdc++.h" 
using namespace std; 
#define int               long long 
 
#define uniq(v)    (v).erase(unique(v.begin(),v.end()),(v).end()) 
 
//const long long INF=1e18; 
//const int32_t M=1e9+7; 
//const int32_t MM=998244353; 
 
void solve() 
{ 
    int n,q; cin >> n>>q; 
 
    vector<int> a(n); 
    for (auto &x : a) cin >> x; 
     
    multiset<int> hi, lo; 
    int sum_hi = 0, sum_lo = 0; 
    vector<int>final; 
    for (int i = 0; i < n; ++i){ 
        if (i & 1){ 
            if (a[i] > *hi.begin()){ 
                sum_hi += a[i] - *hi.begin(); 
                sum_lo += *hi.begin(); 
                lo.insert(*hi.begin()); 
                hi.insert(a[i]); 
                hi.erase(hi.begin()); 
            } else{ 
                lo.insert(a[i]); 
                sum_lo += a[i]; 
            } 
        } else { 
            if (lo.empty()){ 
                hi.insert(a[i]); 
                sum_hi += a[i]; 
            } else if (a[i] < *lo.rbegin()){ 
                sum_hi += *lo.rbegin(); 
                sum_lo += a[i] - *lo.rbegin(); 
                hi.insert(*lo.rbegin()); 
                lo.insert(a[i]); 
                lo.erase(lo.find(*lo.rbegin())); 
            } else{ 
                hi.insert(a[i]); 
                sum_hi += a[i]; 
            } 
             
        } 
        final.push_back(sum_hi-sum_lo); 
    } 
    for(int i=0;i<q;i++){ 
       int x; 
       cin>>x; 
       cout<<final[x-1]<<" "; 
    } 
    cout<<endl; 
 
 
 
} 
signed main(){ 
  ios_base::sync_with_stdio(false); 
  cin.tie(0);cout.tie(0); 
  //freopen("input.txt", "r", stdin); 
  //freopen("output.txt", "w", stdout); 
  #ifdef SIEVE 
    sieve(); 
  #endif 
  #ifdef NCR 
    init(); 
  #endif 
  int t=1; 
  cin>>t; 
  while(t--) solve(); 
  return 0; 
}