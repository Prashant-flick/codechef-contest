#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int mid = (n+1)/2;
        int j=0;
        set<int> st;
        for(int i=1; i<=n; i++){ 
            st.insert(i);
        }
        int res=0;
        int b;
        int ans=0;
        for(int i=0; i<n; i++){
            st.erase(arr[i]);
            if(i>=k-1){
                if(i==k-1){
                    int p=1;
                    for(auto &it: st){
                        res+=it;
                        p++;
                        if(p>n-k){
                            b=it;
                            break;
                        }
                        res+=it;
                        p++;
                        if(p>n-k){
                            b=it;
                            break;
                        }
                    }
                }else{
                    if((n-k)%2==0){
                        if(arr[i]>=b){
                            res-=b;
                            auto it = st.lower_bound(b);
                            it--;
                            b=*it;
                        }else if(arr[i]<b){
                            res-=2*arr[i];
                            res+=b;
                        }
                    }else{
                        if(arr[i]<=b){
                            res-=2*arr[i];
                            auto it = st.upper_bound(b);
                            b=*it;
                            res+=b;
                        }else{
                            res-=b;
                        }
                    }
                }
                ans=max(ans,res);
                st.insert(arr[j]);
                if((n-k)%2==0){
                    if(arr[j]<=b){
                        res+=2*arr[j];
                        res-=b;
                    }else{
                        auto it = st.upper_bound(b);
                        res+=*it;
                        b=*it;
                    }
                }else{
                    if(arr[j]<=b){
                        res-=b;
                        res+=2*arr[j];
                        auto it = st.lower_bound(b);
                        it--;
                        b=*it;
                    }else{
                        res+=b;
                    }
                }
                j++;
            }  
        }
        cout << ans << endl;
    }
}
