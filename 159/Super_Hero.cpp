#include <bits/stdc++.h>
using namespace std;

#define int long long

int primeFactors(int n) { 
    int sum=0;
    while (n % 2 == 0) 
    { 
        sum++;
        n = n/2; 
    } 
 
    for (int i = 3; i+i <= n; i = i + 2) 
    { 
        while (n % i == 0) 
        {
            sum++;
            n = n/i; 
        } 
    } 
 
    if (n > 2){ 
        sum++;
    }
    return sum;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        int h,k;
        cin >> h >> k;
        int maxi=0;
        for(int i=0; i<=12; i++){
            if(((1<<i)&k)==(1<<i)){
                maxi=i;
            }
        }
        
        int res = primeFactors(h);
        int res2 = primeFactors(k);
        cout << res2+res << endl;
    }

}
