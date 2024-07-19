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
	    string s;
	    cin >> s;
        bool flag = false;
	  
	    for(int i=1; i<n; i++){
	        if(s[i]<s[i-1]){
                flag=true;
	            s.erase(s.begin()+(i-1));
	            break;
	        }
	    }
        if(flag){
    	    cout << s << endl;
        }else{
            s.erase(s.begin()+(n-1));
	        cout << s << endl;
        }
	}
	
	return 0;
}
