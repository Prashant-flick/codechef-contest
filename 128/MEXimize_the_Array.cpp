#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        // vector<int> brr;
        // set<int> st;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            // st.insert(arr[i]);
        }

        int ans=0;
        sort(arr, arr+n);
        for (int i = 0; i < n; i++)
        {
            ans+=abs(arr[i]-i);
        }
        

        // auto it = st.begin();
        // sort(brr.begin(), brr.end());
        // int ans=0;
        // int j=0;
        // for(int i=0; i<n; i++){
        //     if(*it == i){
        //         it++;
        //     }else{
        //         // cout << brr[j] << endl;
        //         ans+=abs(brr[j]-i);
        //         j++;
        //     }
        // }
        cout << ans << endl;
    }
}
