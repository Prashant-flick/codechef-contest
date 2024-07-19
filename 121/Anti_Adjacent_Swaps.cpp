#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        if(n>3 || n==1){
            cout << "YES" << endl;
        }else if(n==3){
            if(arr[1]>=arr[0] && arr[1]<=arr[2] || arr[1]<=arr[0] && arr[1]>=arr[2]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            if(arr[0]<=arr[1]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}