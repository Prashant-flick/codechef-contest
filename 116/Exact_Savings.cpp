/*
*	Author: rishabhxchoudhary
*	Created: 10.01.2024 23:35:19 (GMT+5:30)
*/
#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;
const int inf = 1ll<<60;


void solve(){
    int n,x,z;
    cin>>n>>x>>z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    if (z%x==0){
        cout<<z/x<<endl;
        return;
    }
    // we want to create a subset sum in a such that S + Z = kX and minimize k.
    // let dp[i][j] = minimum subset sum S from first i numbers such that sum is j%x.
    // clearly j goes from 0..x-1
    // dp[i][j] = min(dp[i-1][j],dp[i-1][(j-a[i])%x]+a[i])
    vector<vector<int>> dp(n+1,vector<int> (x,inf));
    dp[0][0] = 0;
    for (int i = 1; i <=n; i++) {
        for (int j = 0; j < x; j++) {
            dp[i][j] = min(dp[i-1][j],dp[i-1][(j-a[i-1])%x] + a[i-1]);
        }
    }
    int req = z%x;
    if (dp[n][x-req]==inf){
        cout<<-1<<endl;
    } else {
        cout<< (z + dp[n][x-req])/x <<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}