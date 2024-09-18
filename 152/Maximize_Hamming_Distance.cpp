#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> cnt1(n,0);
        vector<int> cnt2(n,0);
        vector<int> cnt3(n,0);
        while(m--){
            string s;
            cin >> s;
            for(int i=0; i<n; i++){
                if(s[i]=='1'){
                    cnt1[i]++;
                }else if(s[i]=='0'){
                    cnt2[i]++;
                }else{
                    cnt3[i]++;
                }
            }

        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            if(cnt3[i]==0){
                ans += cnt1[i]*1LL*cnt2[i];
            }else{
                if(cnt1[i]>cnt2[i]){
                    swap(cnt1[i], cnt2[i]);
                }
                // cout << cnt1[i] << " " << cnt2[i] << " " << cnt3[i] << endl;
                if(cnt1[i]<cnt2[i]){
                    int temp = cnt2[i]-cnt1[i];
                    if(temp<cnt3[i]){
                        cnt1[i]=cnt2[i];
                        cnt3[i]-=temp;
                        cnt1[i]+=cnt3[i]/2;
                        cnt2[i]+=cnt3[i]/2+cnt3[i]%2;
                    }else{
                        cnt1[i]+=cnt3[i];
                    }
                    ans += cnt1[i]*1LL*cnt2[i];
                }else{
                    cnt1[i]+=cnt3[i]/2;
                    cnt2[i]+=cnt3[i]/2+cnt3[i]%2;
                    ans += cnt1[i]*1LL*cnt2[i];
                }
            }
        }
        
        cout << ans << endl;
    }
}
