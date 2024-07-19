#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        vector<int> t;
        cin >> arr[0];
        int x = arr[0];
        t.push_back(x);
        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i]<=x){
                x=arr[i];
                t.push_back(x);
            }
        }
        
        int ans=n;
        int p=t.size();
        for (int i = p-1 ; i >=0 ; i-- )
        {
            ans = min(ans, t[i]+n-(p-i));
        }
        cout << ans << endl;
    }
    
    return 0;
}