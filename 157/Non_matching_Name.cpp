#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int a,b;
	    cin >> a >> b;
	    string s,t;
	    cin >> s >> t;
	    vector<int> cnt(26,0);
	    for(int i=0; i<a; i++){
	        cnt[s[i]-'a']++;
	    }
	    bool flag=false;
	    for(int i=0; i<b; i++){
	        cnt[t[i]-'a']++;
	    }
	    for(int i=0; i<26; i++){
	        if(cnt[i]==0){
	            flag=true;
	            break;
	        }
	    }
	    if(flag){
	        cout << "YES" << endl;
	    }else{
	        cout << "NO" << endl;
	    }
	}

}
