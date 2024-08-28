#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int mini=INT_MAX;
        int mini2=INT_MAX;
        int maxi=INT_MIN;
        int maxi2=INT_MIN;
        int sum1=0;
        int sum2=0;
        int cnt=0;
        int cnt2=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]>=0){
                mini=min(mini, arr[i]);
                maxi2=max(maxi2, arr[i]);
                sum1+=arr[i];
            }else{
                sum2+=abs(arr[i]);
                maxi=max(maxi, abs(arr[i]));
                mini2=min(mini2, abs(arr[i]));
                cnt++;
            }
            
            if(arr[i]==0){
                cnt2++;
            }
        }

        int totsum=sum1+sum2;
        if(cnt%2==0 || cnt2>0){
            cout << totsum << endl;
        }else{
            cout << totsum-2*(min(mini2, mini)) << endl;
        }
    }
}
