#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void findLCMOfSubsequences(const std::vector<int>& arr, std::vector<int>& result) {
    int n = arr.size();

    int totalSubsequences = 1 << n;
    std::vector<int> dp(totalSubsequences, 1);

    for (int mask = 1; mask < totalSubsequences; ++mask) {
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
                dp[mask] = lcm(dp[mask], arr[j]);
            }
        }
    }

    result = dp;
}

int main() {
    std::vector<int> arr = {2, 3, 5}; // Sample array, change this as needed
    std::vector<int> result;

    findLCMOfSubsequences(arr, result);

    // Display the LCM of subsequences
    std::cout << "LCM of subsequences in the array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
