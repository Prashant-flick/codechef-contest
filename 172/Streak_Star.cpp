#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        int ans=0;
        for(int i=0; i<n; i++){
            arr[i]=arr[i]*k;
            int res=1;
            for(int j=0; j<n-1; j++){
                if(arr[j]<=arr[j+1]){
                    res++;
                }else{
                    res=1;
                }
                ans=max(ans,res);
            }
            arr[i]=arr[i]/k;
        }
        cout << ans << endl;
    }
}
