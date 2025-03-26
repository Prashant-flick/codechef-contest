#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        
        int ans=1;
        int f=arr[0],f1=0;
        int cnt=1,cnt2=0;
        for(int i=1; i<n; i++){
            if(arr[i]==f){
                cnt++;
                if(f1){
                    cnt2++;
                    if(cnt2>0)ans++;
                }else if(cnt>0){
                    ans++;
                }
            }else{
                f1=1;
                cnt2--;
                cnt--;
            }
            if(cnt==0)break;
        }
        cout << ans << endl;
    }

}
