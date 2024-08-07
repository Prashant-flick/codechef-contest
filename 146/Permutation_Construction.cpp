#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i=1;
        int j=(n/2)+(n%2)+1;
        int k=0;
        while(k<n-1){
            cout << i << " " << j << " ";
            k+=2;
            i++;
            j++;
        }
        if(n%2==1){
          cout << i <<" ";
        }
        cout << endl;
    }
}
