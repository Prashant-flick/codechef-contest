#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k==1 || n==1){
            cout << -1 << endl;
            continue;
        }
        if(k==2 && n%2==1){
            cout << -1 << endl;
            continue;
        }
        if(n%2==0){
            for(int i=1; i<=n; i+=2){
                cout << i+1 << " " << i << " ";
            }
            cout << endl;
        }else{
            int i=1;
            for(; i<=n-3; i+=2){
                cout << i+1 << " " << i << " ";
            }
            cout << i+1 << " " << i+2 << " " << i ;
            cout << endl;
        }
    }
}
