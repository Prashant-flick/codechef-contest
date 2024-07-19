#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	int n, t;
	cin >> t;
	while(t--){
	    string s;
	    int n;
	    cin >> n >> s;
	    if(s.size()==1){
	        cout << 8 << endl;
	    }else if(s.size()==2){
	        int num = stoi(s);
	        if(num%8==0 && s[0]=='0'){
                cout << 8 << num << endl;
            }else if(num%8==0){
                cout << s << endl;
            }else{
                int rem = num%8;
	            int rem2 = 8-rem;
	            int check = s[n-1]-'0';
	            if(check+rem2>0 && check+rem2<10){
	                check+=rem2;
	                s[n-1]=char(48+check);
	                cout << s << endl;
	            }else if(check-rem>0 && check-rem<10){
	                check-=rem;
	                s[n-1]=char(48+check);
	                cout << s << endl;
	            }
                continue;
            }
	    }else{
	        string temp = s.substr(n-3,3);
	        int num = stoi(temp);
	        if(num==0){
	            if(n==3){
	                cout << 800 << endl;
	                continue;
	            }
	            cout << s << endl;
	        }
	        else if(num%8==0){
	            if(n==3 && s[0]=='0'){
	                cout << 8 << num << endl;
	                continue;
	            }
	            cout << s << endl;
	        }else{
	            if(n==3 && s[0]=='0'){
	                int rem = num%8;
    	            int rem2 = 8-rem;
    	            int check = s[n-1]-'0';
    	            if(check+rem2>0 && check+rem2<10){
    	                check+=rem2;
    	                cout << 8 << check << endl;
    	            }else if(check-rem>0 && check-rem<10){
    	                check-=rem;
    	                cout << 8 << check << endl;
    	            }
    	            continue;
	            }
	            int rem = num%8;
	            int rem2 = 8-rem;
	            int check = s[n-1]-'0';
	            if(check+rem2>0 && check+rem2<10){
	                check+=rem2;
	                s[n-1]=char(48+check);
	                cout << s << endl;
	            }else if(check-rem>0 && check-rem<10){
	                check-=rem;
	                s[n-1]=char(48+check);
	                cout << s << endl;
	            }
	        }
	    }
	    
	}
	
	return 0;
}
