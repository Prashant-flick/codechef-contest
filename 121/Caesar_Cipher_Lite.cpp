#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;

        for(int i=0; i<n; i++){
            if(s[i] == t[i]){
                cout << 0 << " ";
                continue;
            }
            // cout << s[i]-'A' << " " << t[i]-'A' << endl;
            int len = s[i]-'A'> t[i]-'A' ? (26 - ((s[i]-'A') - (t[i]-'A'))) : (t[i]-'A') - (s[i]-'A');
            // cout << len << endl;
            int sum=0;
            int rem=0;
            while(len!=0){
                sum+=len/3;
                rem=len%3;
                if(rem==0){
                    break;
                }
                len=(26-((t[i]-'A')-rem))+t[i]-'A';
            }
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}