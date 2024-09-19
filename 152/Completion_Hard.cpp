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
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[2*n];
        set<int> st;
        for(int i=1; i<=2*n; i++){
            st.insert(i);
        }
        int cnt=0;
        for(int i=0; i<2*n; i++){
            cin >> arr[i];
            if(i%2==1){
                if(arr[i]!=0 && arr[i-1]!=0){
                    st.erase(arr[i]);
                    st.erase(arr[i-1]);
                    continue;
                }
            }
        }
        int size = st.size();
        auto it = st.begin();
        for(int i=0; i<size/2; i++){
            it++;
        }
        int mid = *it;

        int neg=0;
        int pos=0;
        for(int i=0; i<2*n; i++){
            if(i%2==1){
                if(arr[i]!=0 && arr[i-1]!=0)continue;
                if(arr[i]==0 && arr[i-1]==0){
                    cnt++;
                }else if(arr[i]==0){
                    if(arr[i-1]<mid){
                        neg++;
                    }else{
                        pos++;
                    }
                }else{
                    if(arr[i]<mid){
                        neg++;
                    }else{
                        pos++;
                    }
                }
            }
        }
        size/=2;
        neg = size-neg;
        pos = size-pos;
        int res = (((fact[neg]*1LL*fact[pos])%mod)*power(cnt,2))%mod;
        cout << res << endl;

    }
}
