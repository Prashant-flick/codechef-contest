#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        vector<pair<int,int>> vec(n);
        for(int i=0; i<n; i++){
            int temp = abs(arr[i])/k;
            if(abs(arr[i]) == temp*k){
                if(arr[i]<0){
                    vec[i] = make_pair(-temp, -temp);
                }else{
                    vec[i] = make_pair(temp, temp);
                }
            }else{
                if(arr[i]<0){
                    vec[i] = make_pair((-temp)-1, -temp);
                }else{
                    vec[i] = make_pair(temp, temp+1);
                }
            }
            // cout << vec[i].first << " " << vec[i].second << endl;
        }

        int ans=0;
        int rem=0;
        for(int i=0; i<n; i++){
            ans+=vec[i].first;
            if(vec[i].first != vec[i].second){
                rem++;
            }
        }
        if(ans==0){
            cout << "YES" << endl;
        }else{
            if(ans<0 && ans+rem>=0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}
