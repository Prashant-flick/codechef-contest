#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
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
        if(n<3){
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==1){
                cout << 3 << " ";
            }else if(arr[i]==3){
                cout << 1 << " ";
            }else{
                cout << arr[i] << " ";
            }
        }
        
        cout << endl;
	    
	}
	
	return 0;
}
