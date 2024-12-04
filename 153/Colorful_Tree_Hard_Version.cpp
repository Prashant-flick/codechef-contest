#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int dfs(unordered_map<int,vector<int>> &adj, int u, int *vis){
    vis[u]=1;
    int taken=0;
    for(int &v: adj[u]){
        if(!vis[v]){
            taken = max(taken,1+dfs(adj, v, vis));
        }
    }
    return taken;
}

signed main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n-1; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int vis[n+1]={0};
        int max = dfs(adj, 1, vis)+1;

        if(max==2){
            cout << (n-1)*3+2 << endl;
            continue;
        }

        int ans=1;
        for(int i=1; i<=n; i++){
            if(adj[i].size()==1){
                continue;
            }else{
                ans = (ans*2LL)%mod;
            }
        }
        cout << (3LL*ans)%mod << endl;
    }
}
