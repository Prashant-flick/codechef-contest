#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    vector<int> isPrime(1000001, 1);
    vector<int> prime;

    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i < 1000001; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < 1000001; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    prime.push_back(2);
    for(int i=3; i<=1000000; i+=2){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        if(k%2==0){
            cout << k*2 << endl;
        }else{

            int p=k;
            for(int num: prime ){
                if(num*num>k)break;
                if(k%num==0){
                    p=num;
                    break;
                }
            }

            int ans=0;
            for(int num : prime){
                if(num>p)break;
                ans+=num*k;
            }
            cout << ans << endl;
        }
       
    }
}