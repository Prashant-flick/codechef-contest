#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n >> x;
        string s;
        cin >> s;
        int cnt=0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='0' && cnt==0){
                flag = false;
                break;
            }
            if(s[i]=='0'){
                cnt--;
            }else{
                cnt=x;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}