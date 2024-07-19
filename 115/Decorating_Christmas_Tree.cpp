#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n ,x, y;
	    cin >> n >> x >> y;
	    y/=3;
	    if(x<=y){
	        n-=x;
	        if(n<=0){
	            cout << "YES" << endl;
	        }else{
                cout << "NO" << endl;
            }
	    }else if(x>y){
	        n-=y;
	        x-=y;
	        x/=2;
            n-=x;
            if(n<=0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }

	    }
	 
	    
	}
	
	return 0;
}
