#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int brr[n-1];
        for(int i=0; i<n-1; i++)cin >> brr[i];

        sort(brr, brr+n);
        int arr[n];
        arr[0]=1;
        cout << arr[0] << " ";
        for(int i=1; i<n; i++){
            arr[i]=brr[i-1]-arr[i-1];
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
