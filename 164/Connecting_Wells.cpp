#include <bits/stdc++.h>
using namespace std;

#define int long long
#define size 2005
int rank1[size];
int parent[size];
int arr[size][size];

int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}

void Union(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);
    
    if(x_parent==y_parent){
        return;
    }

    if(rank1[x_parent]>rank1[y_parent]){
        parent[y_parent] = x_parent;
    }else if(rank1[y_parent]>rank1[x_parent]){
        parent[x_parent]=y_parent;
    }else{
        parent[x_parent]=y_parent;
        rank1[y_parent]++;
    }

    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> vec(n);
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            vec[i]=make_pair(x,y);
        }

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int a = abs(vec[i].first - vec[j].first);
                int b = abs(vec[i].second - vec[j].second);
                int sdist = max(a,b);
                if(min(a,b)==0){
                    sdist=(sdist+1)/2;
                }
                arr[i][j]=sdist;
            }
        }

        int l=0,r=1e9;
        int mid = (l+r)/2;
        int ans = 1e9;
        while(l<=r){
            for(int i=0; i<n; i++){
                rank1[i]=0;
                parent[i]=i;
            }
            mid = (l+r)/2;
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(mid>=arr[i][j]){
                        Union(i,j);
                    }
                }
            }

            bool flag=true;
            int prepar = find(0);
            for(int i=0; i<n-1; i++){
                int par =find(i+1);
                if(prepar!=par){
                    flag=false;
                    break;
                }
                prepar=par;
            }

            if(flag){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout << ans << endl;
    }
}
