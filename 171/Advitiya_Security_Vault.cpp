#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

// Function for modular exponentiation: (base^exp) % MOD
int mod_exponentiation(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If the exponent is odd, multiply result with base
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;  // Square the base
        exp /= 2;  // Reduce exponent by half
    }
    return result;
}

// Function to compute the number of even-length palindromes
int count_even_length_palindromes(int length, int low, int high) {
    int choices_per_position = high - low + 1;
    int half_length = length / 2;
    return mod_exponentiation(choices_per_position, half_length);
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);

        int cnt = 1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                cnt = (cnt * k) % MOD;  // Count total ways to fill zeros
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < (n+1) / 2; i++) {
            if (arr[i] == arr[n - i - 1] || arr[i] == 0 || arr[n - i - 1] == 0) {
                cnt1++;
            } else {
                break;  // Stop if we find an unequal pair that is not zero
            }
            if (arr[i] == arr[n - i - 1] && arr[i] == 0) {
                cnt2++;  // Count places where both are zero
            }
        }

        if (cnt2 >= 1) {
            int res = count_even_length_palindromes(cnt2 * 2, 1, k);
            cout << (cnt - res + MOD) % MOD << endl;  // Ensure positive output
        } else {
            cout << cnt % MOD << endl;
        }
    }

    return 0;
}
