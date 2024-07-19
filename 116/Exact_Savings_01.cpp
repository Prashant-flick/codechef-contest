#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1ll<<60;
int dp[100001][1001];

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,x,z;
        cin >> n >> x >> z;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if(z%x==0){
            cout << z/x << endl;
            continue;
        }

        // vector<vector<int>> dp(n+1, vector<int> (x,1e18));
        for (int i = 0; i <= n ; i++)
        {
            for (int j = 0; j < x; j++)
            {
                dp[i][j] = 1e18;
            }
            
        }
        

        dp[0][0]=0;
        for (int i = 1; i <= n; i++)
        {
            for (int rem = 0; rem < x; rem++)
            {
                dp[i][rem] = min(dp[i-1][rem], dp[i-1][(((rem-arr[i-1])%x)+x)%x] + arr[i-1]);
            }
            
        }
        
        int p = z%x;
        if(dp[n][x-p]==1e18){
            cout << -1 << endl;
        }else{
            cout << (z+dp[n][x-p])/x << endl;
        }
    }
    
    return 0;
}