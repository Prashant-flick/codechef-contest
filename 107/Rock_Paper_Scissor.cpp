#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a;
        string b;
        cin >> a >> b;
        int win=0;
        int win2=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]=='R' && b[i]=='S' || a[i]=='P' && b[i]=='R' || a[i]=='S' && b[i]=='P'){
                win++;
            }else if(b[i]=='R' && a[i]=='S' || b[i]=='P' && a[i]=='R' || b[i]=='S' && a[i]=='P'){
                win2++;
            }
        }
        // cout << win << " " << win2 << endl;
        if(win>win2){
            cout << 0 << endl;
        }else if(win==win2){
            cout << 1 << endl;
        }else{
            cout << (win2-win)/2 + 1 << endl;
        }
    }
    
    return 0;
}