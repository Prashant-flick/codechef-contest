#include <bits/stdc++.h>
using namespace std;
int n, k;
bool flag,flag1;

#define int long long

void solve1(unordered_map<int, vector<int>> &adj, int u, int *vis, vector<int> &path){
    if(vis[u])return;
    path.push_back(u);
    vis[u]=1;
    if(u==n){
        flag1=false;
        return;
    }
    for(int &v: adj[u]){
        if(!vis[v]){
            solve1(adj, v, vis, path);
            if(flag1){
                path.pop_back();
            }
        }
    }
}

int solve(unordered_map<int, vector<int>> &adj, int u, int check, int s){
    int vis[n+1]={0};
    if(check){
        vis[s]=1;
    }
    vis[1]=1;
    queue<int> q;
    q.push(u);
    int cnt=0;

    while(!q.empty()){
        int v = q.front();
        vis[v]=1;
        cnt++;
        q.pop();
        if(v==n){
            flag=false;
            break;
        }

        for(int &v: adj[v]){
            if(!vis[v]){
                q.push(v);
            }
        }
    }

    return cnt;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n-1; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        flag1=true;
        flag=true;
        int vis[n+1]={0};
        vector<int> path;
        solve1(adj, 1, vis, path);

        // for(int i=0; i<path.size(); i++){
        //     cout << path[i] << " ";
        // }
        // cout << endl;

        vector<int> minDist;

        int m1 = path.size();
        for(int i=0; i<m1-1; i++){  
            for(int &v: adj[path[i]]){
                if((i>0 && v==path[i-1]) || v==path[i+1])continue;
                int cnt = solve(adj, v, 1, path[i]);
                minDist.push_back(cnt);
            }
        }

        int m = minDist.size();
        sort(minDist.begin(), minDist.end());
        // for(int i=0; i<m; i++){
        //     cout << minDist[i] << " ";
        // }
        // cout << endl;
        int ans=m1;
        for(int i=0; i<(m-(k-1)); i++){
            ans+=minDist[i];
        }
        cout << ans << endl;
    }
}
