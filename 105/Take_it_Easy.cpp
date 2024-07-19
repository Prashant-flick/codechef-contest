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
	    int sum=0;
        bool odd=false;
        bool even=false;
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
            if(arr[i]%2==0){
                even=true;
            }else{
                odd=true;
            }
	        sum+=arr[i];
	    }

        if(sum%n!=0 || even && odd){
            cout << "No" << endl;
        }else{
            if(sum%n==0){
                if((sum/n)%2==0 && even){
                    cout << "Yes" << endl;
                }else if((sum/n)%2!=0 && odd){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }
        }
	}
	
	return 0;
}