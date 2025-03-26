#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n],brr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        for(int i=0; i<n; i++)cin >> brr[i];
        int ans=0;
        int c=1e9;
        for(int i=0; i<n; i++){
            int a = abs(arr[i]-brr[i]);
            int b = 9-a;
            if(a<b){
                ans+=a;
                c=min(c,b);
            }else{
                ans+=b;
                c=min(c,a);
            }
        }

        if(ans<=k && (k-ans)%2==0){
            cout << "Yes" << endl;
        }else{
            ans+=c;
            ans-=9-c;
            if(ans<=k && (k-ans)%2==0){
                cout << "Yes" << endl;
                continue;
            }
            cout << "No" << endl;
        }
    }

}
