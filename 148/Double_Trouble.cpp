#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            pq.push(arr[i]);
        }

        while (k > 0) {
            int min_elem = pq.top();
            pq.pop();

            int step = 1;
            while (k >= step) {
                k -= step;
                step *= 2;
                min_elem = min_elem*2;
            }

            pq.push(min_elem);
        }

        // Calculate the final result
        int ans = 0;
        while (!pq.empty()) {
            ans = (ans + pq.top()) % MOD;
            pq.pop();
        }
        cout << ans << endl;
    }
}
