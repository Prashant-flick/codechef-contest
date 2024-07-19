#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        long long n,k; 
        cin >> n >> k;
        if(k>=n){
            cout << n/2 << endl;
        }else{
            int temp1 = n%k;
            temp1++;
            int temp2 = temp1-2;
            int maxi1 = (temp1%k)*1LL*((n-temp1)%k);
            int maxi2 = (temp2%k)*1LL*((n-temp2)%k);
            if(maxi1>maxi1){
                cout << temp1 << endl;
            }else{
                cout << temp2 << endl;
            }
        }
    }
    
    return 0;
}