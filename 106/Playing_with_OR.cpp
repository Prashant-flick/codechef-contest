#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
	    int i=0;
	    int j=0;
        int odd=0;
        int ans=0;
	    while(j<n){
            if(arr[j]&1)odd++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(odd>0)ans++;
                if((arr[i]&1))odd--;
                i++;
                j++;
            }
        }
	 
	    cout << ans << endl;
	}
	
	return 0;
}
