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
        for(int i=0; i<n; i++)cin >> arr[i];
        int brr[n];
        for(int i=0; i<n; i++)cin >> brr[i];
        
        bool flag = true;
        int i=n-2;
        for(; i>=0; i--){
            if(arr[i]+brr[i]<arr[i+1]){
                break;
            }
        }
        int i2=0;
        for(; i2<n-1; i2++){
            if(arr[i2]+brr[i2]<arr[i2+1]){
                break;
            }
        }
        int j=1;
        for(; j<n-2; j++){
            if(arr[j]-brr[j]>arr[j-1]){
                break;
            }
        }
        int j2=n-1;
        for(; j2>=1; j2--){
            if(arr[j2]-brr[j2]>arr[j2-1]){
                break;
            }
        }
        i++;
        j--;
        // cout << i << " " << i2 << " " << j << " " <<j2 << endl;
        if(i2+1<i && j+1<j2 && i2+1<j2 && j+1<i && arr[i2]+brr[i2]<arr[j2] && arr[j2]-brr[j2]>arr[i2]){
            flag=false;   
        }
        
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}