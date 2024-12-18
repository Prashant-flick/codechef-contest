#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)cin >> arr[i];
        int ans=0;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            ans+=((arr[i]-i)>=0?(arr[i]-i):0);
        }
        cout << ans << endl;
    }
}
