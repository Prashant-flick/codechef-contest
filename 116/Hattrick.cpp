#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int cnt=0;
        bool flag = false;
        for(int i=0; i<6; i++){
            char ch;
            cin >> ch;
            if(ch=='W'){
                cnt++;
            }else{
                cnt=0;
            }

            if(cnt==3)flag=true;
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
