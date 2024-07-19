#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int N = 2e5 + 7, mod = 1e9 + 7;
int fac[N + 1], ifac[N + 1];

int power(int n, int k) {
    int ans = 1;
    for(int b = 0, res = n % mod; b < 30; b++, res = res * res % mod) {
        if((1 << b) & k) ans = ans * res % mod;
    }
    return ans;
}

int inv(int n) { return power(n, mod - 2); }

void precum() {
    fac[0] = 1;
    for(int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = inv(fac[N]);
    for(int i = N - 1; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
}

int32_t main(){
    int t;
    cin >> t;
    precum();
    while(t--){
        // int mod = 1e7;
        int n;
        cin >> n;
        int arr[n][n];
        int maxi = ((n*n)-n)/2;
        int gap = maxi+n;
        bool flag = true;
        int cnt=0;
        unordered_map<int,bool> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
                if(i==j){
                    if(arr[i][j]==0){
                        cnt++;
                    }else{
                        if(arr[i][j]<=maxi || arr[i][j]>(maxi+n)){
                            flag=false;
                        }
                    }
                }else{
                    if(arr[i][j]!=0){
                        mp[arr[i][j]]=true;
                    }
                    if(arr[i][j]!=0 && arr[i][j]>maxi && arr[i][j]<=maxi+n){
                        flag=false;
                    }
                }
            }
        } 

        if(n==1){
            if(arr[0][0]==0){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
            continue;
        }

        if(!flag){
            cout << 0 << endl;
        }else{
            int empty=0;
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(arr[i][j]==0 && arr[j][i]==0){
                        empty++;
                    }else if(arr[j][i]!=0 && arr[i][j]==0){
                        if(arr[j][i]>gap){
                            if(mp[arr[j][i]-gap]){
                                flag = false;
                                break;
                            }
                        }else{
                            if(mp[arr[j][i]+gap]){
                                flag = false;
                                break;
                            }
                        }
                        mp[arr[j][i]]=false;
                    }else if(arr[i][j]!=0 && arr[j][i]==0){
                        if(arr[i][j]>gap){
                            if(mp[arr[i][j]-gap]){
                                flag = false;
                                break;
                            }
                        }else{
                            if(mp[arr[i][j]+gap]){
                                flag = false;
                                break;
                            }
                        }
                        mp[arr[i][j]]=false;
                    }else if(arr[i][j]!=0 && arr[j][i]!=0){
                        if(abs(arr[i][j]-arr[j][i])!=gap){
                            flag = false;
                            break;
                        }
                    }
                }
            }
            // cout << ans << endl;
            int ans2 = (fac[cnt]*fac[empty]) %mod;
            ans2 = (ans2 * power(2, empty)) % mod;

            if(!flag){
                cout << 0 << endl;
            }else{
                cout << ans2 << endl;
            }
        }
    }
    return 0;
}