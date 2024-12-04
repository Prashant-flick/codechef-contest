#include <bits/stdc++.h>
using namespace std;

int primeFactors(int n) { 
    int sum=0;
    while (n % 2 == 0) 
    { 
        sum++;
        n = n/2; 
    } 
 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            sum++;
            n = n/i; 
        } 
    } 
 
    if (n > 2) 
        sum++;

    return sum;
}

int main() {
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
        cout << maxi+res << endl;
    }

}
