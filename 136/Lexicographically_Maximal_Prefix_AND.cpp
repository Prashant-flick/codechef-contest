#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int maxi = 0;
        int index = -1;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] > maxi) {
                index = i;
                maxi = arr[i];
            }
        }

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i) {
            if (i == index) continue;
            vec.emplace_back(arr[i] & maxi, arr[i]);
        }

        sort(vec.rbegin(), vec.rend());

        vector<int> result;
        result.push_back(maxi);
        for (const auto &p : vec) {
            result.push_back(p.second);
        }

        vector<int> B(n);
        B[0] = result[0];
        cout << B[0] << " ";
        for (int i = 1; i < n; ++i) {
            B[i] = B[i - 1] & result[i];
            cout << B[i] << " ";
        }
        cout << endl;
    }

    return 0;
}