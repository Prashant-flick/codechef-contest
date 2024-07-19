#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,l;
        cin >> n >> l;
        int b=2;
        int c=1+b;
        if(c<=l){
            cout << 1 << " ";
            n--;
        }
        while(n && c<=l){
            cout << b << " ";
            b++;
            c+=2;
            n--;
        }
        if(b!=2){
            b--;
            c=b+l;
        }else{
            c=l;
            cout << c << " ";
            c=l+l;
            n--;
        }

        while(n){
            cout << c << " ";
            c=c+l;
            n--;
        }
        cout << endl;
    }
}
