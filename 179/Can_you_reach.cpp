#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        int ans=0;
        int j=0;
        int prev=1;
        while(j<n-1){
            if(j<n-1 && arr[j]>arr[j+1]){
                int cnt=1;
                while(j<n-1 && arr[j]>arr[j+1]){
                    cnt++;
                    j++;
                }
                ans+=(cnt*(cnt-1))/2;
                ans+=((prev-1)*(cnt-1));
                prev=cnt;
            }else if(j<n-1 && arr[j]<arr[j+1]){
                int cnt=1;
                while(j<n-1 && arr[j]<arr[j+1]){
                    cnt++;
                    j++;
                }
                ans+=(cnt*(cnt-1))/2;
                ans+=((prev-1)*(cnt-1));
                prev=cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
