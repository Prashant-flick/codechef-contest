#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,l,r;
        cin >> n >> l >> r;
        int arr[n];
        unordered_map<int,int> mp;
        bool flag=false;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mp[arr[i]]++;
            if(mp[arr[i]]==2){
                flag=true;
            }
        }
        int ans=0;
        if(flag){
            if(ans>=l && ans<=r){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
            continue;
        }
        ans=1;
        for(int i=0; i<n-1; i++){
            flag=true;
            for(int j=i+1; j<n; j++){
                ans*=(arr[i]^arr[j]);
                if(ans==0){
                    flag=false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(ans>=l && ans<=r){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
