#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 500010
int arr[N],vis[N];

int dfs(int u){
    vis[u]=1;
    if(!vis[arr[u]]){
        return 1 + dfs(arr[u]);
    }else{
        return 0;
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            vis[i]=0;
        }

        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1; i<=n; i++){
            if(!vis[arr[i]]){
                int cnt = 1+dfs(arr[i]);
                pq.push(cnt);
            }
        }
        
        if(pq.size()==1){
            cout << 0 << endl;
            continue;
        }

        int ans=0;
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans+=(a+b);
            pq.push(a+b);
        }
        
        cout << ans << endl;
    }
}
