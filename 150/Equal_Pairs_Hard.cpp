#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = (n*(n-1))/2;
        unordered_map<int,int> mp;
        
        int maxi=0;
        int sum=0;
        while(n--){
            int x,y;
            cin >> x >> y;
            sum-=(mp[y]*(mp[y]-1))/2;
            mp[y]++;
            sum+=(mp[y]*(mp[y]-1))/2;
            maxi=max(maxi, mp[y]);
            int m = maxi+n;
            int ans1 = (m*(m-1))/2;
            ans = (sum-((maxi*(maxi-1))/2))+ans1;
            cout << ans << " ";
        }
        cout << endl;
    }
}
