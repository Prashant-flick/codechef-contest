#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        int maxi1=0;
        int maxi2=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(maxi1<arr[i]){
                if(maxi2<maxi1){
                    maxi2=maxi1;
                }
                maxi1=arr[i];
            }
        }
        if(k==2){
            cout << maxi1+maxi2 << endl;
            continue;
        }
        int ans=0;
        vector<int> right(n);
        right[n-1]=0;
        for(int i=n-2; i>=0; i--){
            right[i]=max(right[i+1], arr[i+1]);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;

        int k1=k;
        int i=n-1;
        int res=0;
        while(k1>0){
            pq1.push({arr[i],i});
            if(k1==k || k1==1){
                res+=arr[i];
            }else{
                res+=arr[i]*2;
            }
            i--;
            k1--;
        }
        ans = max(ans, res);
        vector<int> vis(n,0);
        int j=n-1;

        while(i>=0){
            res+=arr[i+1];
            res+=arr[i];
            int mini=pq1.top().first;
            int index=pq1.top().second;
            while(j>=0 && vis[j]!=0){
                j--;
            }
            vis[index]=1;
            if(index==j){
                res-=mini;
                while(j>=0 && vis[j]!=0){
                    j--;
                }
                res-=arr[j];
            }else{
                res-=mini*2;
            }
            pq1.pop();
            ans=max(ans, res);
            if(pq1.size()>0){
                mini=pq1.top().first;
                index=pq1.top().second;
                int ans1=res;
                int l=j;
                while(l>=0 && vis[l]!=0){
                    l--;
                }
                if(l!=index){
                    ans1-=mini*2;
                    ans1+=right[l];
                    ans1+=arr[l];
                    ans=max(ans,ans1);
                }
            }
            pq1.push({arr[i],i});
            i--;
        }
        

        cout << ans << endl;
    }
}