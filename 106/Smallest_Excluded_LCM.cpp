// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long

// int gcd(int a, int b) {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// int lcm(int a, int b) {
//     return (a * b) / gcd(a, b);
// }

// void findLCMOfSubsequences(vector<int>& arr,set<int>& result) {
//     int n = arr.size();

//     for (int i = 0; i < (1 << n); ++i) {
//         int subsequenceLCM = 1;
//         for (int j = 0; j < n; ++j) {
//             if (i & (1 << j)) {
//                 subsequenceLCM = lcm(subsequenceLCM, arr[j]);
//             }
//         }
//         result.insert(subsequenceLCM);
//     }
// }

// int main() {
// 	int t;
// 	cin >> t;
// 	while(t--){
// 	    int n;
// 	    cin >> n;
// 	    vector<int> arr(n);
//         int mini=INT_MAX;
// 	    for(int i=0; i<n; i++){
// 	        cin >> arr[i];
//             mini = min(mini, arr[i]);
// 	    }
//         if(mini!=1){
//             cout << 1 << endl;
//             continue;
//         }
//         set<int> result;
// 	    findLCMOfSubsequences(arr, result);
//         auto it = result.begin();
//         int i=1;
//         while(it!=result.end())
//         {
//             if(*it!=i)break;
//             i++;
//             it++;
//         }
//         cout << i << endl;
// 	}
	
// 	return 0;
// }





#include <iostream>
#include <vector>

using namespace std;

const int MAX_LIMIT = 64; // Define the maximum limit of prime numbers to consider

int smallestLCMNotSubset(vector<int>& A, int n) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61}; // List of prime numbers
    int result = 1;

    for (int i = 0; i < primes.size(); ++i) {
        int currentPrime = primes[i];

        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (A[j] % currentPrime != 0) {
                found = true;
                break;
            }
        }

        if (found) {
            result = result * currentPrime;
            if (result > MAX_LIMIT) {
                return result;
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int smallestLCM = smallestLCMNotSubset(A, N);
    cout << smallestLCM << endl;
    }
    
    


    return 0;
}
