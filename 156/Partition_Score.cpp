#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        sort(arr, arr+n);
        int ans = arr[n-1]+arr[n-2]+arr[0];
        if(k==1){
            cout << ans+arr[n-1] << endl;
        }else{
            cout << ans+arr[n-1-k] << endl;
        }
    }
    return 0;
}
