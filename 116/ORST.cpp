#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int maxi=0;
        for(int i=0; i<m; i++){
            int temp;
            cin >> temp;
            maxi = max(maxi, temp);
        }

        sort(arr.begin()+(n-maxi), arr.end());
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}