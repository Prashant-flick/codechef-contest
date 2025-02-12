#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, q, p, x;
    cin >> n;
    
    vector<int> arr(n + 1);
    vector<bool> st(n + 1, false), st2(n + 1, false);
    int countSt = 0, countSt2 = 0, maxIndexSt2 = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i]) {
            if (i == 1 || i % 2 == 0) {
                st[i] = true;
                countSt++;
            } else {
                st2[i] = true;
                countSt2++;
                maxIndexSt2 = max(maxIndexSt2, i);
            }
        }
    }

    cin >> q;
    while (q--) {
        cin >> p >> x;

        if (arr[p]) {
            if (p == 1 || p % 2 == 0) {
                st[p] = false;
                countSt--;
            } else {
                st2[p] = false;
                countSt2--;
                if (p == maxIndexSt2) {
                    maxIndexSt2 = 0;
                    for (int i = p - 1; i >= 1; i--) {
                        if (st2[i]) {
                            maxIndexSt2 = i;
                            break;
                        }
                    }
                }
            }
        }

        arr[p] = x;
        if (x) {
            if (p == 1 || p % 2 == 0) {
                st[p] = true;
                countSt++;
            } else {
                st2[p] = true;
                countSt2++;
                maxIndexSt2 = max(maxIndexSt2, p);
            }
        }

        int a = maxIndexSt2;
        int countStAfterA = countSt;
        for (int i = 1; i <= a; i++) {
            if (st[i]) countStAfterA--;
        }

        if (n % 2 == 1) {
            if (a == 0) countStAfterA--;
            cout << (countStAfterA == (n - a) / 2 ? 1 : 0) << endl;
        } else {
            if (a == 0) countStAfterA--;
            cout << (countStAfterA == ((n + 1) - a) / 2 ? 1 : 0) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
