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
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mp[arr[i]]=i+1;
        }
        int ans=0;
        for(auto it:mp){
            ans+=it.second;   
        }
        cout << ans << endl;
    }
}
