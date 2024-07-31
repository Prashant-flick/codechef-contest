#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;
const int size = 5e5+5;
int ans[500005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ans[0]=0;
	ans[1]=0;
	ans[2]=2;
	int cnt1=1;
	for(int i=3; i<size-2; i++){
		cnt1 = ((cnt1*2LL)%MOD + ((i-1)*(i-1)*1LL)%MOD)%MOD;
		ans[i]=((ans[i-1]*2LL)%MOD+(cnt1*2LL)%MOD)%MOD;
	}

	
    int t=1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
}
