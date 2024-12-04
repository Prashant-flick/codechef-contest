#include <bits/stdc++.h>
using namespace std;
#define int long long
// const int size = 1e6+10;
int mp[1000005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	// your code goes here
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        memset(mp, 0, sizeof mp);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                mp[arr[i]^arr[j]]++;
            }
        }

        int ans=0;
        for(int &v: mp){
            ans+=(v*(v-1))/2LL;
        }
        cout << ans*8LL << endl;
    }
    return 0;
}