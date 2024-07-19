#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mod 998244353

int32_t main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    int ans=0;
	    int cnt = max(n/2,m/2);
        if(n%2==0 && n/2==cnt){
            for (int i = n/2; i <= n/2+1; i++)
            {
                int j = max(1LL,m-cnt);
                int k = min(cnt+1,m);
                if(j>k)continue;
                // ans = (ans+((((((k*1LL*(k+1))%mod)/2)%mod - (((j*1LL*(j+1))%mod)/2))%mod)*i)%mod)%mod;

                int rows = ((k-j+1) * (k+j)/2)%mod;
                ans = (ans+((rows)*i)%mod)%mod;
            }
        }else if(n%2!=0 && n/2==cnt){
            for (int i = n/2+1; i <= n/2+1; i++)
            {
                int j = max(1LL,m-cnt);
                int k = min(cnt+1,m);
                if(j>k)continue;
                // ans = (ans+((((((k*1LL*(k+1))%mod)/2)%mod - (((j*1LL*(j+1))%mod)/2))%mod)*i)%mod)%mod;
                int rows = ((k-j+1) * (k+j)/2)%mod;
                ans = (ans+((rows)*i)%mod)%mod;
                
            }
        }else if(m%2==0 && m/2==cnt){
            for (int i = m/2; i <= m/2+1; i++)
            {
                int j = max(1LL,n-cnt);
                int k = min(cnt+1,n);
                if(j>k)continue;
                int rows = ((k-j+1) * (k+j)/2)%mod;
                ans = (ans+((rows)*i)%mod)%mod;
            }
        }else if(m%2!=0 && m/2==cnt){
            for (int i = m/2+1; i <= m/2+1; i++)
            {
                int j = max(1LL,n-cnt);
                int k = min(cnt+1,n);
                if(j>k)continue;
                int rows = ((k-j+1) * (k+j)/2)%mod;
                ans = (ans+((rows)*i)%mod)%mod;
            }
        }
        cout << ans%mod << endl;
	    
	}
	
	return 0;
}
