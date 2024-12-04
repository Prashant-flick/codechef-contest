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
        int len = s.size();
        for(int i=0; i<min(mini,len); i++){
            if(s[i%(len)]=='A'){
                alice+=sum-(2*a);
                bob-=(2*b);
                a++;
            }else{
                bob+=sum-(2*b);
                alice-=(2*a);
                b++;
            }
        }
        int mini2=min(mini, len);
        if(mini2==mini){
            if(alice==bob){
                cout << "Draw"<< endl;
            }else if(alice>bob){
                cout << "Alice" << endl;
            }else{
                cout << "Bob" << endl;
            }
        }else{
            int a1=a;
            int b1=b;
            mini-=len;
            sum = ((n+m-1)*(a*b));
            cout << mini << " " << a1 << " " << b1 << endl;
            while(mini>0 && mini/len>0){
                alice+=sum-(2*a1);
                bob-=(2*b1);
                bob+=sum-(2*b1);
                alice-=(2*a1);
                mini-=len;
            }

            int i=0;
            while(mini>0){
                if(s[i%(len)]=='A'){
                    alice+=sum-(2*a);
                    bob-=(2*b);
                    a++;
                }else{
                    bob+=sum-(2*b);
                    alice-=(2*a);
                    b++;
                }
                mini--;
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

}
