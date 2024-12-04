#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    
	    int brr[n];
	    brr[0]=0;
	    int sum=0;
	    int maxi=0;
	    for(int i=1; i<n; i++){
	        int temp = (maxi+arr[i])-(sum);
	        brr[i]=temp;    
	        sum+=brr[i];
	        maxi=max(maxi, brr[i]);
	    }

        brr[0]=maxi+1;
        sum=maxi+1;
        maxi++;
        for(int i=1; i<n; i++){
	        int temp = (maxi+arr[i])-(sum);
	        brr[i]=temp;    
	        sum+=brr[i];
	        maxi=max(maxi, brr[i]);
	    }
	    
	    for(int i=0; i<n; i++){
	        cout << brr[i] << " ";
	    }
	    cout << endl;
	}

}
