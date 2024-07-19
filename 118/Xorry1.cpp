#include <bits/stdc++.h>
using namespace std;

#define int long long

int fact(int num){
    if(num==0)return 0;
    if(num==1)return 1;
    
    int ans=num;
    for(int i=num-1; i>=1; i--){
        ans += ((num-i)*i);
    }
    // cout << ans << endl;
    return ans;
}

int32_t main(){
    int t;
	cin >> t;
	while(t--){
	    int x;
	    cin >> x;
        
        int p = x;
        int q=0,r=0;
        while(p){
            r=q;
            q = __builtin_ctz(p);
            p-=(1<<q);
        }
        // cout << r << endl;
        for (int i = 0; i < r; i++)
        {
            if(((x&(1<<i))==(1<<i))){
                r--;
            }
        }
        // cout << r << endl;
        int f = fact(r);
        // cout << f << endl;
        cout << f+1LL << endl;
	}
    return 0;
}