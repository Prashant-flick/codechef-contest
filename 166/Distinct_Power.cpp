#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int brr[n],arr[n];
        map<int, int, greater<int>> mp;
        for(int i=0; i<n; i++){
            cin >> brr[i];
            mp[brr[i]]=i;
        }
        int i=1;
        for(auto it: mp){
            arr[it.second]=i;
            i++;
        }
        int ans=0;
        int j=0;
        while(j<n){
            if(j<n-1 && abs(arr[j]-arr[j+1])==1){
                while(j<n-1 && abs(arr[j]-arr[j+1])==1){
                    j++;
                }
                j++;
                ans++;
            }else{
                j++;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
