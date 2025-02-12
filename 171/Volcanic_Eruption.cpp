#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++) {
            if(i==0){
                if(arr[i]==0){
                    left[i]=0;
                }else{
                    left[i]=INT_MAX;
                }
                continue;
            }
            left[i] = (arr[i] == 0) ? 0 : max(arr[i], left[i - 1]);
        }
        
        for (int i = n - 1;i >= 0; i--) {
            if(i==n-1){
                if(arr[i]==0){
                    right[i]=0;
                }else{
                    right[i]=INT_MAX;
                }
                continue;
            }
            right[i] = (arr[i] == 0) ? 0 : max(arr[i], right[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            int res = min(left[i], right[i]);
            cout << (res + p - 1) / p << " ";
        }
        cout << "\n";
    }
}
