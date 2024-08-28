#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while(t--){
        int n, x, k;
        cin >> n >> x >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++)cin >> arr[i];

        sort(begin(arr), end(arr));
        int a = x;
        int b = x*k;
        int ans=0;
        int i=0;
        while(i<n && arr[i]<b){
            if(i<n-1 && arr[i]==arr[i+1]){
                while(i<n-1 && arr[i]<b && arr[i]==arr[i+1] ){
                    i++;
                }
            }else{
                ans++;
                i++;
            }
        }

        int pre[n]={0};
        i=0;
        int cnt=0;
        while(i<n){
            if(i<n-1 && arr[i]==arr[i+1]){
                pre[i]=cnt;
                i++;
                cnt++;
                while(i<n-1 && arr[i]==arr[i+1]){
                    pre[i]=cnt;
                    i++;
                }
            }else{
                pre[i]=cnt;
                i++;
            }
        }

        int pre2[n]={0};
        i=0;
        cnt=0;
        while(i<n){
            if(i<n-1 && arr[i]==arr[i+1]){
                cnt++;
                while(i<n-1 && arr[i]==arr[i+1]){
                    pre2[i]=cnt;
                    i++;
                }
                pre2[i]=cnt;
                i++;
            }else{
                cnt++;
                pre2[i]=cnt;
                i++;
            }
        }

        i = lower_bound(begin(arr), end(arr), a)-arr.begin();
        i--;
        int index = i;
        while(i>0){
            if(i>0 && arr[i]==arr[i-1]){
                int temp = arr[i]*k;
                int j = lower_bound(begin(arr), end(arr), temp)-arr.begin();
                j--;
                int ans1=0;
                if(index<=j){
                    ans1 = (pre[index]-(pre[i]-1))+pre2[j];
                }else{
                    ans1 = (pre[j]-(pre[i]-1))+pre2[j];
                }
                if(j<index){
                    ans1 += pre2[index]-pre2[j];
                }
                ans=max(ans, ans1);
                while(i>0 && arr[i]==arr[i-1]){
                    i--;
                }
            }else{
                i--;
            }
        }  


        cout << ans << endl;      
    }
}