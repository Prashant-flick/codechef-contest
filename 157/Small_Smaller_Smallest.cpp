#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    int ones=0;
	    int zero=0;
	    for(int i=0; i<n; i++){
	        if(s[i]=='1')ones++;
	        else zero++;
	    }
	    if(ones%2==0){
	        cout << 0 << endl;
	    }else{
	        cout << 1 << endl;
	    }
	}

}
