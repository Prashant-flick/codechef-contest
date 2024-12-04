#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    cin >> n >> m;
	    string s,t;
	    cin >> s >> t;
	    if(s==t){
	        cout << 0 << endl;
	        continue;
	    }
	    if(s[0]!=t[0]){
	        cout << -1 << endl;
	        continue;
	    }
        int diff=0;
        for(int i=0; i<(min(n,m)); i++){
            if(s[i]!=t[i]){
                diff++;
                break;
            }
        }
        if(diff==0){
            cout << 1 << endl;
            continue;
        }
        if(n==m){
            cout << 2 << endl;
            continue;
        }

        int i=0;
        int j=0;
        while(i<n && j<m){
            if(s[i]!=t[j]){
                break;
            }
            i++;
            j++;
        }
        if(n>m){
            int k=n-1;
            int l=m-1;
            bool flag=true;
            while(l>=j){
                if(s[k]!=t[l]){
                    flag=false;
                    break;
                }
                l--;
                k--;
            }
            if(flag){
                cout << 1 << endl;
                continue;
            }
        }else{
            int k=n-1;
            int l=m-1;
            bool flag=true;
            while(k>=i){
                if(s[k]!=t[l]){
                    flag=false;
                    break;
                }
                l--;
                k--;
            }
            if(flag){
                cout << 1 << endl;
                continue;
            }
        }
        cout << 2 << endl;
	}

}
