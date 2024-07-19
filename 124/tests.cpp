#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        if(n==0){
            cout << -1 << endl;
        }else{
            vector<int> store(26,0);
            string brr="";
            for(int i=0; i<n; i+=2){
                store[s[i]-'a']++;
                brr+=s[i];
            }
            for(int i=1; i<n; i+=2){
                store[s[i]-'a']++;
                brr+=s[i];
            }

            char ans=' ';
            for(int i=0; i<n; i++){
                if(store[brr[i]-'a']!=0 && store[brr[i]-'a']<2){
                    ans = brr[i];
                    break;
                }
            }
            if(ans==' '){
                cout << -1 << endl;
            }else{
                cout << ans << endl;
            }

        }
    }
    
    

    return 0;
}