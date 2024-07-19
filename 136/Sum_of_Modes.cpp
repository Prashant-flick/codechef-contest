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
        string s;
        cin >> s;
        unordered_map<int, unordered_map<int, int>> mp;
        int ans = 0;
        int cnt1=0;
        int cnt2=0;
        int totcnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1')cnt1++;
            else cnt2++;
            
            if(cnt1==cnt2)totcnt+=2;
            else totcnt++;
            
            mp[cnt1-cnt2][cnt2-cnt1]++;
        }
        ans+=totcnt;
        
        cnt1=0;
        cnt2=0;
        int prev1=0;
        int prev2=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1')cnt1++;
            else cnt2++;

            totcnt--;
            
            mp[cnt1-cnt2][cnt2-cnt1]--;
            totcnt+=mp[cnt1-cnt2][cnt2-cnt1];
            totcnt-=mp[prev1][prev2];
            prev1=cnt1-cnt2;
            prev2=cnt2-cnt1;
            // cout << totcnt << endl;
            ans+=totcnt;
        }
        
        cout << ans << endl;
    }
}
