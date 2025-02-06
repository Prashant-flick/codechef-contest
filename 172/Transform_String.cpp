#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        int n,m;
        n = s1.size();
        m = s2.size();
        if(n<m){
            cout << -1 << endl;
            continue;
        }
        int i=n-1;
        int cnt=0;
        int j=m-1;
        vector<pair<int,int>> vec;
        while(i>=0 && j>=0){
            if(s1[i]==s2[j]){
                vec.push_back({i+2,cnt});
                i--;
                j--;
                cnt=0;
            }else{
                cnt++;
                i--;
            }
        }
        if(j>=0){
            cout << -1 << endl;
        }else{
            while(i>=0){
                cnt++;
                i--;
            }
            vec.push_back({1,cnt});
            reverse(vec.begin(), vec.end());
            cnt=0;
            int ans=0;
            for(int i=0; i<vec.size(); i++){
                ans+=((vec[i].first-cnt)*vec[i].second);
                cnt+=vec[i].second;
            }
            cout << ans << endl;
        }
    }
}
