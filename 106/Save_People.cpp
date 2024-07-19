#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    int x,y;
	    cin >> x >> y;
	    int xgap = max(n-x, x-1);
        int ygap = max(m-y, y-1);
        cout << max(xgap*m*1LL,ygap*n*1LL) << endl;
	    // if(xgap>=ygap){
        //     cout << max(xgap*m*1LL << endl;
        // }else {
        //     cout << ygap*n*1LL << endl;
        // }
	}
	
	return 0;
}
