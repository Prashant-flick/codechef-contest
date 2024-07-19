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


        int cnt1 = __builtin_clz(n);
        int cnt2 = __builtin_ctz(n);
        // cout << cnt1 << " " << cnt2 << endl;
        bool flag = true;
        int res=0;
        int cnt=0;
        for(int i=cnt2; i<=(31-cnt1); i++){
            if(((1<<i)&n)==0){
                if(!flag){
                    res+=cnt;
                    cnt=(1<<i);
                }
            }else{
                if(flag){
                    cnt+=(1<<i);
                }
                flag=false;
            }
        }

        cout << res << endl;
    }
}
