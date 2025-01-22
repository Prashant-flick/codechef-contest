#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        std::vector<int> arr(n);
        for(int i=0; i<n; i++)cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        int ans=arr[0];
        int curr=x;
        for(int i=1; i<n; i++){
            if(arr[i]+curr>ans){
                ans=arr[i]+curr;
            }
            curr+=x;
        }
        cout << ans << endl;
    }
}
