#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        if (k % 2 != n % 2 || k < 1LL * n * n / 4) {
            std::cout << -1 << std::endl;
            continue;
        }

        std::vector<int> arr(n, 1);

        for (int i = 0; i < n; i += 2) {
            if (k >= n - i) {
                arr[i] += n - i;
                k -= (n - i);
            } else {
                arr[i] += k;
                break;
            }
        }

        for (int i = 1; i < n; i += 2) {
            if (k >= n - i) {
                arr[i] += n - i;
                k -= (n - i);
            } else {
                arr[i] += k;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
