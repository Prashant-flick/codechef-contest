#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

int power(int num, int pow){
    int res=1;
    for(int i=0; i<num; i++){
        res = (res*2)%mod;
    }
    return res;
}

signed main() {
    const int size = 2e5+1;
    int fact[size];
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<size; i++){
        fact[i]=(fact[i-1]*1LL*i)%mod;
    }
    
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[2*n];
        int neg=0;
        int pos=0;
        int cnt=0;
        for(int i=0; i<2*n; i++){
            cin >> arr[i];
            if(i%2==1){
                if(arr[i]==arr[i-1])cnt++;
            }
            if(arr[i]==0)continue;
            if(arr[i]<=n){
                neg++;
            }else{
                pos++;
            }
        }

        neg = n-neg;
        pos = n-pos;
        
        int ans = (((fact[neg]*1LL*fact[pos])%mod)*1LL*power(cnt,2))%mod;
        cout << ans << endl;
    }
}
