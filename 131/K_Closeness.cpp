#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arr[i]%=k;
        }
        
        sort(arr, arr+n);
        int maxi = arr[n-1];
        int mini = arr[0];
        int ans=maxi-mini;
        for(int i=0; i<n-1; i++){
            maxi=max(maxi, arr[i]+k);
            mini=arr[i+1];
            ans=min(ans, maxi-mini);
        }
        
        cout << ans << endl;
    }
}
