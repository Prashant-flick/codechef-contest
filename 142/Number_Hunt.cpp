#include <bits/stdc++.h> 
using namespace std; 
#define int long long 
 
int solve(int n){ 
    vector<int> vec; 
    while(vec.size() < 2){ 
        bool flag=true;
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                flag=false;
                break;
            }
        }
        if(flag)vec.push_back(n);
        n++; 
    } 
    int ans = vec[0];
    ans*=vec[1];
    return ans; 
} 
 
int32_t main() { 
    int t; 
    cin >> t; 
    while(t--){ 
        int n; 
        cin >> n; 
        if(n == 1) n++; 
        int ans = solve(n);
        
        cout << ans << endl;
    } 
    return 0; 
}