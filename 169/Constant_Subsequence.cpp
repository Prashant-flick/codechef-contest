#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int mid, queue<int> pos, queue<int> neg){
    if(pos.empty())return true;
    int sum = pos.front();
    pos.pop();
    while(!pos.empty()){
        if(sum>mid)return false;
        if(sum+pos.front()>mid){
            if(neg.empty())return false;
            sum+=neg.front();
            neg.pop();
            if(sum<=0)sum=0;
        }else{
            sum+=pos.front();
            pos.pop();
        }
    }
    return sum<=mid;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        queue<int> brr,crr;
        int sum=0;
        int maxi=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            maxi=max(maxi,arr[i]);
            if(arr[i]<0){
                crr.push(arr[i]);
            }else if(arr[i]>0){
                sum+=arr[i];
                brr.push(arr[i]);
            }
        }
        if(brr.empty()){
            cout << 0 << endl;
            continue;
        }
        int l=maxi,r=sum;
        int mid;
        int ans=r;
        while(l<=r){
            mid = (l+r)/2;
            if(check(mid, brr, crr)){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        cout << ans << endl;
    }
}
