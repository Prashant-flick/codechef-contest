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
        int ones=0,zeros=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                zeros++;
            }else{
                ones++;
            }
        }
        if(zeros>0 && ones>0){
            cout << 1 << endl;
        }else{
            cout << n << endl;
        }
    }
}
