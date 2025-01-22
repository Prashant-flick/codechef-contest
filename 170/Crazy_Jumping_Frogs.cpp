#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int odd=0,even=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]%2==0){
                odd++;
            }else{
                even++;
            }
        }
        cout << max(odd,even) << endl;
    }
}
