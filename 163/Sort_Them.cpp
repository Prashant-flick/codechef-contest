#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;
        string s, p; cin >> s >> p;

        vector<int>ind(26);
        for(int i = 0; i < 26; i++) {
            ind[p[i] - 'a'] = i;
        }

        vector<vector<int>>dp(n, vector<int>(50, -1));

        auto f = [&](int index, int lastChar, auto &&self) -> int {

            if(index == n) return 0;
            if(dp[index][lastChar] != -1) return dp[index][lastChar];

            int first = n + 1, second = n + 1;

            if(s[index] - 'a' >= lastChar) first = self(index + 1, s[index] - 'a', self);
            if(p[25 - ind[s[index] - 'a']] - 'a' >= lastChar) {
                second = 1 + self(index + 1, p[25 - ind[s[index] - 'a']] - 'a', self);
            }
            
            return dp[index][lastChar] = min(first, second);
        };

        cout << (f(0, 0, f) > n ? -1 : f(0, 0, f)) << endl;
    }
}