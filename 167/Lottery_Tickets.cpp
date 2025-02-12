#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        int num = arr[0];
        sort(arr, arr+n);
        int x = lower_bound(arr, arr+n, num)-arr;
        if(x==0){
            int a = (arr[x]+arr[x+1])/2;
            cout << a << endl;
        }else if(x==n-1){
            int a = (arr[x]+arr[x-1]+1)/2;
            cout << (1e6 - a)+1 << endl;
        }else{
            int a = (arr[x]+arr[x+1])/2;
            int b = (arr[x]+arr[x-1]+1)/2;
            // cout << a << " " << b << endl;
            cout << a-b+1 << endl;
        }
    }
}
