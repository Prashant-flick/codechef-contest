#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        unordered_map<int,int> mp;
        int maxi=0;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            maxi=max(maxi,mp[arr[i]]);
        }
        if(mp[k]==maxi){
            cout << 0 << endl;
            continue;
        }
        mp.clear();
        maxi=0;
        bool flag=false;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            maxi=max(maxi,mp[arr[i]]);
            if(mp[k]==maxi){
                flag=true;
                break;
            }
        }
        if(flag){
            cout << 1 << endl;
            continue;
        }
        mp.clear();
        maxi=0;
        for(int i=n-1; i>=0; i--){
            mp[arr[i]]++;
            maxi=max(maxi,mp[arr[i]]);
            if(mp[k]==maxi){
                flag=true;
                break;
            }
        }
        if(flag){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;   
        }
    }
}
