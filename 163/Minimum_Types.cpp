#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int arr[n],brr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        for(int i=0; i<n; i++)cin >> brr[i];
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            vec[i]=(arr[i]*brr[i]);
        }
        sort(vec.rbegin(), vec.rend());
        int cnt=0;
        int ans=-1;
        for(int i=0; i<n; i++){
            cnt+=vec[i];
            if(cnt>=x){
                ans=i+1;
                break;
            }
        }
        cout << ans << endl;
    }
}
