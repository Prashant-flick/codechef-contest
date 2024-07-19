#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll sq = sqrtl(n);
        // cout << sq << endl;
        if(sq%2==0){
            ll ans = sq/2;
            cout << ans << endl;
        }else{
            if(n%2==0){
                sq--;
                ll ans = sq/2;
                cout << ans << endl;
            }else{
                sq++;
                ll ans = sq/2;
                cout << ans << endl;
            }
        }
    }
    
    return 0;
}