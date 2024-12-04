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
        
        auto check = [&](int m){
            int l=0,r=0,cnt=0,mn=arr[r],mx=arr[r];
            while(r<n){
                mx=max(mx,arr[r]);
                mn=min(mn,arr[r]);
                if((mx-mn+1)/2 <= m){
                    r++;
                }else{
                    l=r;cnt++;
                    mx=arr[l];
                    mn=arr[l];
                    r++;
                }
            }
            return cnt<=k;
        };
        
        int l=0,r=1e9,mid=(l+r)/2;
        int ans=1e9;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        cout << ans << endl;
    }
}
