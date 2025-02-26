#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD=998244353;

long long powerMod(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,q,x,v;
        cin >> n >> q;
        vector<int> arr(n),brr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            brr[i]=arr[i];
        }
        sort(arr.begin(), arr.end());
        int a = n-2;
        a = powerMod(2,a);
        int ans=0;
        vector<int> vec;
        for(int i=n-1; i>=0; i--){
            if(i>0){
                vec.push_back((int)(arr[i]*arr[i-1])%MOD);
            }
            int b = a;
            int j=0;
            while(b>0){
                int c = (int)(arr[i]*arr[j])%MOD;
                vec.push_back((int)(b*c)%MOD);
                j++;
                b/=2;
            }
            a/=2;
        }
        for(int i=0; i<vec.size(); i++){
            ans=(ans+vec[i])%MOD;
        }
        cout << ans << endl;
        while (q--)
        {
            cin >> x >> v;
            x--;
            brr[x]=v;
            arr=brr;
            sort(arr.begin(), arr.end());
            int a = n-2;
            a = powerMod(2,a);
            int ans=0;
            vector<int> vec;
            for(int i=n-1; i>=0; i--){
                if(i>0){
                    vec.push_back((int)(arr[i]*arr[i-1])%MOD);
                }
                int b = a;
                int j=0;
                while(b>0){
                    int c = (int)(arr[i]*arr[j])%MOD;
                    vec.push_back((int)(b*c)%MOD);
                    j++;
                    b/=2;
                }
                a/=2;
            }
            for(int i=0; i<vec.size(); i++){
                ans=(int)(ans+vec[i])%MOD;
            }
            a/=2;
            cout << ans << endl;
        }
    }
}