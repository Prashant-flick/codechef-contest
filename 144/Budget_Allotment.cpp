#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        int arr[n];
        map<int,int> mp;
        int maxi=0;
        int ans=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]>=x){
                ans++;
                maxi+=arr[i]-x;
            }else{
                mp[x-arr[i]]++;
            }
        }
        
        auto it=mp.begin();
        while(it!=mp.end()){
            int a = it->first;
            if(maxi<a){ 
                break;
            }
            int b = it->second;
            if((maxi/a)>=b){
                ans+=b;
                maxi-=(b*a);
            }else{
                int temp = maxi/a;
                ans+=temp;
                maxi-=(temp*a);
            }
            it++;
        }
        
        cout << ans << endl;
    }
}
