#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string s1="",s2="",s3="";
        int i=0;
        while(i<n-1 && s[i]!=s[i+1]){
            s1+=s[i];
            i++;
        }
        s1+=s[i];
        i++;
        if(i==n){
            cout << "Yes" << endl;
            continue;
        }
        while(i<n-1 && s[i]!=s[i+1]){
            s2+=s[i];
            i++;
        }
        s2+=s[i];
        i++;
        if(i==n){
            if(s1[s1.size()-1]!=s2[s2.size()-1] || s1[0]!=s2[0]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            while(i<n-1 && s[i]!=s[i+1]){
                s3+=s[i];
                i++;
            }
            s3+=s[i];
            i++;
            if(i==n){
                if(s1[s1.size()-1]!=s2[s2.size()-1] && s3[0]!=s2[0]){
                    cout << "Yes" << endl;
                }else{
                    cout << "No" << endl;
                }
            }else{
                cout << "No" << endl;
            }
        }
    }
}
