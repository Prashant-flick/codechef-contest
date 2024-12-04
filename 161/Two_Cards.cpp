#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, temp;
        cin >> n;
        int maxi=0;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> temp;
            arr[i].first = temp;
            maxi=max(maxi, temp);
        }
        for(int i=0; i<n; i++){
            cin >> temp;
            arr[i].second = temp;
            maxi=max(maxi, temp);
        }
        sort(arr.rbegin(), arr.rend());
        if(max(arr[0].first, arr[0].second)>max(arr[1].first, arr[1].second)){
            cout << "Yes" << endl;
            continue;
        }
        if(max(arr[0].first, arr[0].second)<maxi){
            cout << "Yes" << endl;
        }else{
            cout << "No" <<  endl;
        }
    }
}
