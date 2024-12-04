#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s,t;
        cin >> s >> t;
        if(s==t){
            cout << "YES" << endl;
            continue;
        }
        
        if(n<m || s[0]!=t[0]){
            cout << "NO" << endl;
            continue;
        }
        int cnt=0;
        
        char ch=s[0];
        int i=0,j=0;
        bool flag=true;
        while(i<n && j<m){
            cnt++;
            int cnt1=0;
            while(i<n && s[i]==ch){
                i++;
                cnt1++;
            }
            int cnt2=0;
            while(j<m && t[j]==ch){
                j++;
                cnt2++;
            }
            if(cnt1%2!=cnt2%2 || cnt1<cnt2){
                flag=false;
                break;
            }
            ch=(ch=='A')?'B':'A';
        }
        if(!flag || i!=n || j!=m || cnt<=1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
