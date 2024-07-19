#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000000

int32_t main() {
	// your code goes here
	int arr[200002];
    arr[0]=1;
    int sum=1;
    for(int i=1; i<29; i++){
        arr[i]+=(sum+1);
        sum+=arr[i];
        arr[i]=sum;
        // cout << arr[i] << " ";
    }
    // cout << endl;
    int t;
    cin >> t;
    while(t--){
        int k,n,x;
        cin >> n >> k >> x;
        if(k==1){
            cout << "YES" << endl;
        }
        
        if(k>31){
            cout << "NO" << endl;
            continue;
        }

        if(x>arr[k-2]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
}
