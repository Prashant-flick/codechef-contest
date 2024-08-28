#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;

int power(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            pq.push(arr[i]);
        }
        while(k>0){
          int temp = pq.top();
          if(temp*2>1e9)break;
          pq.pop();

          pq.push(temp*2);
          k--;
        }

        int i=0;
        while(!pq.empty()){
          arr[i]=pq.top();
          pq.pop();
          i++;
        }
        int k1=k/n;
        int k2=k%n;

        int ans=0;
        for(int i=0; i<n; i++){
          int pow = power(2LL, (i<k2?k1+1:k1));
          arr[i]=(arr[i]*pow*1LL)%MOD;
          ans=(ans+arr[i])%MOD;
        }
        cout << ans << endl;
    }
}
