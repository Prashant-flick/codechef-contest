#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n+1];
	    int sum=0;
	    for(int i=0; i<=n; i++){
	        cin >> arr[i];
	        sum+=arr[i];
	    }
	    
	    while(true){
	        int r=arr[n]*2;
	        int maxi=0;
	        int idx=-1;
	        for(int i=0; i<n; i++){
	            if(arr[i]<=r && maxi<arr[i]){
	                maxi=max(maxi, arr[i]);
	                idx=i;
	            }
	        }
	        if(idx==-1 || maxi<=arr[n]){
	            break;
	        }else{
	            swap(arr[idx], arr[n]);
	        }
	    }
	    cout << sum-arr[n] << endl;
	}

}
