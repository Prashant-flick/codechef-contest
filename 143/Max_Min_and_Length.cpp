#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        sort(arr, arr+n);
        int ans=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int p = arr[j]-arr[i];
                if(p>=2 && p-2 <= j-i-1){
                    if(p-2==0)ans++;
                    else if(p-2==1)ans+=j-i-1;
                    else{
                        ans += ((j-i-1)-(p-1))*((j-i-1)-(p))/2;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
