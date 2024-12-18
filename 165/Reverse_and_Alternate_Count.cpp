#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        int i=0;
        int ones=0;
        int zero=0;
        while(i<n-1 && s[i]!=s[i+1]){
            if(s[i]=='0'){
                zero++;
            }else{
                ones++;
            }
            i++;
        }
        if(s[i]=='0'){
            zero++;
        }else{
            ones++;
        }
        i++;
        if(i==n){
            cout << (n*(n+1))/2 << endl;
            continue;
        }
        ans+=((zero+ones)*(zero+ones-1))/2;
        int one1=0;
        int zero1=0;
        int check=s[i]-'0';
        while(i<n-1 && s[i]!=s[i+1]){
            if(s[i]=='0'){
                zero1++;
            }else{
                one1++;
            }
            i++;
        }
        if(s[i]=='0'){
            zero1++;
        }else{
            one1++;
        }
        ans+=((zero1+one1)*(zero1+one1-1))/2;
        if(check){
            ans+=(zero*one1);
            ans+=(zero1*(ones+zero));
        }else{
            ans+=(ones*zero1);
            ans+=(one1*(ones+zero));
        }
        i++;
        while(i<n){
            int one2=0;
            int zero2=0;
            check=s[i]-'0';
            while(i<n-1 && s[i]!=s[i+1]){
                if(s[i]=='0'){
                    zero2++;
                }else{
                    one2++;
                }
                i++;
            }
            if(s[i]=='0'){
                zero2++;
            }else{
                one2++;
            }
            ans+=((zero2+one2)*(zero2+one2-1))/2;
            if(one1==zero1){
                ans+=(ones+zero)*(one2+zero2);
            }
            if(check){
                ans+=(zero2*one1);
                ans+=(zero1*(one2+zero2));
            }else{
                ans+=(one2*zero1);
                ans+=(one1*(one2+zero2));
            }
            ones=one1;
            zero=zero1;
            one1=one2;
            zero1=zero2;
            i++;
        }
        cout << ans << endl;
    }
}
