#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int cnt=0;
        int cnt2=0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i]==1){
                cnt++;
            }else{
                cnt2+=(arr[i]-2);
            }
        }
        if(cnt==0){
            if(cnt2%2==0){
                cout << "Bob" << endl;
            }else{
                cout << "Alice" << endl;
            }
        }
        else if(cnt%2==0){
            if(n==cnt){
                cout << "Draw" << endl;
            }
            else if(cnt2%2==0){
                cout << "Bob" << endl;
            }else{
                cout << "Alice" << endl;
            }
        }else{
            if(cnt2%2==0){
                cout << "Alice" << endl;
            }else{
                cnt2 = (n-cnt) + (cnt/2);
                cnt = (cnt/2+1);
                // cout << cnt << " " << cnt2 << endl;
                if(cnt2==cnt){
                    cout << "Draw" << endl;
                }else if(cnt > cnt2){
                    cout << "Alice" << endl;
                }else{
                    cout << "Bob" << endl;
                }
            }
        }
        
    }
}
