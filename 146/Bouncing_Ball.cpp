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
        for(int i=0;i<n;i++)cin >> arr[i];
        int left[n];
        int right[n];
        left[0]=arr[0];
        for(int i=1; i<n; i++){
            left[i]=left[i-1]+arr[i];
            // cout << left[i] << " ";
        }
        // cout << endl;
        right[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            right[i]=right[i+1]+arr[i];
            // cout << right[i] << " ";
        }
        // cout << endl;
        int ans=0;
        for(int i=0; i<n; i++){
            if(arr[i]==0){
                if(left[i]==right[i]){
                    ans+=2;
                }else if((left[i]==right[i]+1) || (left[i]+1==right[i])){
                    // cout << "here" << endl;
                    // cout << left[i] << " " << right[i] << endl;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
