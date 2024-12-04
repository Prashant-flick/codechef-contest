#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        bool flag=false;
        int cnt=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]==i+1){
                flag=true;
                cnt++;
            }
        }
        if(cnt==n){
            cout << n << endl;
            continue;
        }
        if(flag){
            cout << n-1 << endl;
            continue;
        }
        cout << n-2 << endl;
    }
}
