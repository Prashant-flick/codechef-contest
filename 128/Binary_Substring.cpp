#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        int cnt4=0;
        for(int i=0; i<n-1; i++){
            if(s[i]=='0' && s[i+1]=='0'){
                cnt1++;
            }else if(s[i]=='0' && s[i+1]=='1'){
                cnt2++;
            }else if(s[i]=='1' && s[i+1]=='0'){
                cnt3++;
            }else{
                cnt4++;
            }
            i++;
        }
        int ans = cnt4*2 + cnt1*2;
        if(cnt3>1){
            ans+=2;
        }else if(cnt3==1){
            ans+=1;
        }
        if(cnt2>=1){
            ans+=2;
        }
        cout << ans << endl;
    }
}
