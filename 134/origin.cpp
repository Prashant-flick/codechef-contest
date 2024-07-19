#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long sum = 0;
        long long cycles = n / 9;
        long long remainder = n % 9;
        sum += cycles * 45;
        for(long long i = 1; i <= remainder; i++){
            sum += (i % 9 == 0) ? 9 : i % 9;
        }
        cout << sum << endl;
    }
    return 0;
}