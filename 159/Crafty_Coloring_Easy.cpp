#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        int mini = min(n,m);
        int alice=0,bob=0;
        int last=INT_MIN;
        int a=0,b=0;
        int sum=n+m-1;
        for(int i=0; i<mini; i++){
            if(s[i%(s.size())]=='A'){
                alice+=sum-(2*a);
                bob-=(2*b);
                a++;
            }else{
                bob+=sum-(2*b);
                alice-=(2*a);
                b++;
            }
        }
        if(alice==bob){
            cout << "Draw"<< endl;
        }else if(alice>bob){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }

}
