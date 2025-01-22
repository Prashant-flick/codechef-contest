#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=arr[i];
            int j=n-i-1;
            sum=max(sum,(j*j)+cnt);
        }
        cout << max(sum,n*n) << endl;
    }
}
