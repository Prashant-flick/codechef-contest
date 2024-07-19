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

        int ans=0;
        int cnt=0;
        int cnt2=0;
        for(int i=0; i<n; i++){
            if(arr[i]%2==0){
                cnt2=max(cnt2, cnt);
                ans += (n-i)*(cnt+1);
                cnt=0;
            }else{
                cnt++;
            }
        }
        cnt2=max(cnt2, cnt);
        if(cnt2==1){
            ans++;
        }
        if(cnt2>1){
            int temp=(cnt2/2)+(cnt2%2==1?1:0);
            if(cnt2%2==0){
                ans+=temp*(temp+1);
            }else{
                ans+=temp*temp;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}