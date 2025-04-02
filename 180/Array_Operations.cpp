#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int maxi=0,maxi2=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i%2){
                maxi=max(arr[i],maxi);
            }else{
                maxi2=max(maxi2, arr[i]);
            }
        }
        if(n==1){
            cout << maxi2 << endl;
        }else{
            cout << max(maxi2+n/2,maxi+n/2-1) << endl;
        }
    }

}
