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
        for(int i=0; i<n; i++)cin >> arr[i];
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            ans+=abs(arr[i]-arr[i+1]);
        }

        int inc = max(0, max(abs(k-arr[1])-abs(arr[0]-arr[1]), abs(1-arr[1])-abs(arr[0]-arr[1])));
        
        inc = max(inc, max(abs(k-arr[n-2])-abs(arr[n-1]-arr[n-2]), abs(1-arr[n-2])-abs(arr[n-1]-arr[n-2])));

        for(int i=1; i<n-1; i++){
            inc = max(inc, (abs(k-arr[i-1])-abs(arr[i-1]-arr[i])) + (abs(k-arr[i+1])-abs(arr[i+1]-arr[i])));
            inc = max(inc, (abs(1-arr[i-1])-abs(arr[i-1]-arr[i])) + (abs(1-arr[i+1])-abs(arr[i+1]-arr[i])));
        }

        cout << ans+inc << endl;
    }
}
