#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int i=0;
        int k1=k;
        while (k--)
        {
            arr[n-1]+=arr[i];
            i++;
        }

        for(i=k1; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }
}
