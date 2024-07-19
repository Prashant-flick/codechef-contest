#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
        while(t--){
            long long A, B;
        cin >> A >> B;

        long long X = 0;
        long long min_diff = abs((A ^ X) - (B ^ X));

        // Iterate through possible values of X
        for (long long i = 0; i < 29; ++i) {
            long long current_diff = abs((A ^ i) - (B ^ i));
            if (current_diff < min_diff) {
                min_diff = current_diff;
                X = i;
            }
        }

        cout << X << endl;
        }
    

    return 0;
}