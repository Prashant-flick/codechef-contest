#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        int j=n-1;
        int maxi=arr[n-1];
        j--;
        int ans=0;
        while(j>=0){
            int cnt=0;
            while(j>=0 && arr[j]<maxi){
                cnt++;
                j--;
            }
            ans=max(ans,cnt);
            maxi=arr[j];
            j--;
        }
        cout << ans << endl;
    }
}
