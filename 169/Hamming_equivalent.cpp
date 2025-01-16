#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n],brr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
            brr[i]=arr[i];
        }
        sort(arr, arr+n);
        unordered_map<int,set<int>> mp;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<20; j++){
                if(((1<<j)&brr[i])==(1<<j))cnt++;
            }
            mp[cnt].insert(brr[i]);
        }

        bool flag=true;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<20; j++){
                if(((1<<j)&brr[i])==(1<<j))cnt++;
            }
            if(mp[cnt].find(arr[i])==mp[cnt].end()){
                flag=false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
