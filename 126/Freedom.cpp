#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr;
        bool flag = false;
        int cnt=0;
        int cnt2=0;
        int cnt3=0;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            if(temp==6){
                cnt++;
            }
            if(temp==2){
                cnt2+=cnt;
            }
            if(temp==4)cnt3++;
        }

        cnt3 = cnt3*(cnt3-1)/2;
        
        cout << cnt2+cnt3 << endl;
    }
}
