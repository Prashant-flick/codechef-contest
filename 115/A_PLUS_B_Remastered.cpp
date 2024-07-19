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
        vector<int> arr(n);
        vector<int> brr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin() , arr.end());
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
	    sort(brr.rbegin(), brr.rend());
        bool flag = true;
        for (int i = 0; n>1 && i < n-1; i++)
        {
            if(arr[i]+brr[i]!=arr[i+1]+brr[i+1]){
                flag = false;
                break;
            }
        }
        
        if(flag || n==1){
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; i++)
            {
                cout << brr[i] << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    
	}
	
	return 0;
}