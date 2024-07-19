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
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int mini=INT_MIN;
        int maxi=INT_MAX;
        bool flag=true;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]<arr[i-1] && i==n-1){
                int mini2=arr[i-1]-arr[i];
                if(mini2>maxi){
                    flag=false;
                    break;
                }
            }
            else if(arr[i]<arr[i-1]){
                int mini2=arr[i-1]-arr[i];
                int maxi2=arr[i+1]-arr[i];
                // cout << maxi << " " << mini << " " << maxi2 << " " << mini2 << endl;
                if(maxi2<mini2){
                    flag=false;
                    break;
                }
                if(maxi2<mini || mini2>maxi){
                    flag=false;
                    break;
                }
                if(maxi==INT_MAX){
                    maxi=maxi2;
                    mini=mini2;
                }else{
                    maxi=min(maxi, maxi2);
                    mini=max(mini, mini2);
                }
                i++;
            }
        }
        
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
