#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;

signed main(){
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt=0;
        int i=0;
        while(i<n-1){
            if(i<n-1 && s[i]!=s[i+1]){
                i++;
            }else{
                int cnt1=0;
                while(i<n-1 && s[i]==s[i+1]){
                    cnt1++;
                    i++;
                }
                cnt+=cnt1;
            }
        }

        int maxi = (n-cnt)-1;
        // int ans = maxi*cnt;
        // ans = ans+(maxi*(maxi-1))/2;
        // cout << ans << endl;
        // cout << maxi << " " << cnt << endl;
        int ans=0;
        i=cnt+1;
        while(cnt>0){
            ans = (ans+((maxi*(maxi+1))/2))%MOD;
            cnt--;
        }
        maxi--;
        while(maxi>0){
            ans = (ans+(i*((maxi*(maxi+1))/2)))%MOD;
            maxi--;
            i++;
        }
        cout << ans << endl;
    }
}