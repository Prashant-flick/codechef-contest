#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> arr(n);
        vector<int> brr(m);
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=0; i<m; i++){
            cin >> brr[i];
        }
        
        if(n<4 || m<4 || n+m<11){
            cout << -1 << endl;
            continue;
        }
        
        sort(arr.rbegin(), arr.rend());
        sort(brr.rbegin(), brr.rend());
        int ans=0;
        for(int i=0; i<4; i++){
            ans+=arr[i]+0LL;
            ans+=brr[i]+0LL;
        }
        
        int i=4;
        int j=4;
        int k=3;
        while(i<n && j<m && k!=0){
            if(arr[i]>=brr[j]){
                ans+=arr[i]+0LL;
                i++;
            }else{
                ans+=brr[j]+0LL;
                j++;
            }
            k--;
        }
        while(i<n && k!=0){
            ans+=arr[i]+0LL;
            k--;
            i++;
        }
        while(j<m && k!=0){
            ans+=brr[j]+0LL;
            k--;
            j++;
        }
        
        cout << ans << endl;
    }
}
