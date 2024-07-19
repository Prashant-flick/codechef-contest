#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];

        if(n==1){
            cout << 1 << endl;
            continue;
        }

        int brr[n]={0};
        int vis[n]={0};
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                brr[i]+=arr[i]*arr[j];
                brr[j]+=arr[i]*arr[j];
            }
        }

        if(brr[0]<=c){
            cout << 1 << endl;
            continue;
        }

        int mini = 1e18;
        int index = -1;
        int ans = n;

        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                if(vis[j]==0){
                    if(brr[j]<mini){
                        mini = brr[j];
                        index =  j;
                    }
                }
            }

            for(int j=1; j<n; j++){
                if(vis[j]==1){
                    c+=(2*(arr[index]*arr[j]));
                }
            }
            // cout << c << " " << mini << endl;
            if(c>=mini){
                ans--;
                c-=mini;
            }else{
                break;
            }
            vis[index]=1;
            mini=1e18;
        }

        cout << ans << endl;
    }
}
