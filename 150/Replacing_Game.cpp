#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, k;
string a,b;

bool solve(int *store, int *store2){
    bool flag=true;
    vector<pair<int,char>> ans;

    int i=0;
    int l=-1, r=-1;
    char ch='$';
    for(i=0; i<n; i++){
        if(l!=-1){
            if(i>=l && i<=r){
                if(ch!=b[i]){
                    if(i!=0 && b[i-1]==b[i]){
                        if(i-store[i-1]+1>=k){
                            l=i-k+1;
                            r=l+k-1;
                        }else{
                            if(i>n-k){
                                if(store[i]+k-1<n){
                                    l=store[i];
                                    r=l+k-1;
                                }else{
                                    break;
                                }
                            }else{
                                l=store[i];
                                r=l+k-1;
                            }
                        }
                    }else{
                        if(i>n-k){
                            break;
                        }
                        l=i;
                        r=i+k-1;
                    }
                    ch=b[i];
                    a[i]=ch;
                    ans.push_back({l+1,ch});
                }else{
                    a[i]=ch;
                }
            }else{
                if(a[i]!=b[i]){
                    if(i!=0 && b[i-1]==b[i]){
                        if(i-store[i-1]+1>=k){
                            l=i-k+1;
                            r=l+k-1;
                        }else{
                            if(i>n-k){
                                if(store[i]+k-1<n){
                                    l=store[i];
                                    r=l+k-1;
                                }else{
                                    break;
                                }
                            }else{
                                l=store[i];
                                r=l+k-1;
                            }
                        }
                        ch=b[i];
                        a[i]=ch;
                    }else{
                        if(i>n-k){
                            break;
                        }
                        l=i;
                        r=i+k-1;
                    }
                    ans.push_back({l+1,ch});
                }else{
                    a[i]=b[i];
                }
            }
        }else{
            if(a[i]!=b[i]){
                if(i!=0 && b[i-1]==b[i]){
                    if(i-store[i-1]+1>=k){
                        l=i-k+1;
                        r=l+k-1;
                    }else{
                        if(i>n-k){
                            if(store[i]+k-1<n){
                                l=store[i];
                                r=l+k-1;
                            }else{
                                break;
                            }
                        }else{
                            l=store[i];
                            r=l+k-1;
                        }
                    }
                }else{
                    if(i>n-k){
                        break;
                    }
                    l=i;
                    r=i+k-1;
                }
                ch=b[i];
                a[i]=ch;
                ans.push_back({l+1,ch});
            }else{
                a[i]=b[i];
            }
        }
    }
    for(int i=l; i>=0&&i<n&&i<=r; i++){
        a[i]=ch;
    }

    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            flag=false;
            break;
        }
    }

    if(flag){
        if(l==-1){
            cout << 0 << endl;
        }else{
            cout << ans.size() << endl;
            for(int i=0; i<ans.size(); i++){
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
        return true;
    }

    flag=true;

    i=n-1;
    l=-1, r=-1;
    ch='$';
    for(i=n-1; i>=0; i--){
        if(l!=-1){
            if(i>=r && i<=l){
                if(ch!=b[i]){
                    if(i!=n-1 && b[i+1]==b[i]){
                        if(store2[i+1]-i+1>=k){
                            l=i+k-1;
                            r=l-k+1;
                        }else{
                            if(i<k-1){
                                if(store2[i]-k+1>=0){
                                    l=store2[i];
                                    r=l-k+1;
                                }else{
                                    break;
                                }
                            }else{
                                l=store2[i];
                                r=l-k+1;
                            }
                        }
                    }else{
                        if(i<k-1){
                            break;
                        }
                        l=i;
                        r=i-k+1;
                    }
                    ch=b[i];
                    a[i]=ch;
                    ans.push_back({r+1,ch});
                }else{
                    a[i]=ch;
                }
            }else{
                if(a[i]!=b[i]){
                    if(i!=n-1 && b[i+1]==b[i]){
                        if(store2[i+1]-i+1>=k){
                            l=i+k-1;
                            r=l-k+1;
                        }else{
                            if(i<k-1){
                                if(store2[i]-k+1>=0){
                                    l=store2[i];
                                    r=l-k+1;
                                }else{
                                    break;
                                }
                            }else{
                                l=store2[i];
                                r=l-k+1;
                            }
                        }
                    }else{
                        if(i<k-1){
                            break;
                        }
                        l=i;
                        r=l-k+1;
                    }
                    ch=b[i];
                    a[i]=ch;
                    ans.push_back({r+1,ch});
                }else{
                    a[i]=b[i];
                }
            }
        }else{
            if(a[i]!=b[i]){
                if(i!=n-1 && b[i+1]==b[i]){
                    if(store2[i+1]-i+1>=k){
                        l=i+k-1;
                        r=l-k+1;
                    }else{
                        if(i<k-1){
                            if(store2[i]-k+1>=0){
                                l=store2[i];
                                r=l-k+1;
                            }else{
                                break;
                            }
                        }else{
                            l=store2[i];
                            r=l-k+1;
                        }
                    }
                }else{
                    if(i<k-1){
                        break;
                    }
                    l=i;
                    r=l-k+1;
                }
                ch=b[i];
                a[i]=ch;
                ans.push_back({r+1,ch});
            }else{
                a[i]=b[i];
            }
        }
    }

    for(int i=r; i>=0&&i<n&&i<=l; i++){
        a[i]=ch;
    }

    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            flag=false;
            break;
        }
    }

    if(!flag){
        cout << -1 << endl;
        return false;
    }else{
        if(l==-1){
            cout << 0 << endl;
        }else{
            cout << ans.size() << endl;
            for(int i=0; i<ans.size(); i++){
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
        return true;
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> a >> b;
        int store[n];
        int j=0;
        while(j<n){
            int k=j;
            if(j<n-1 && b[j]==b[j+1]){
                while(j<n-1 && b[j]==b[j+1]){
                    store[j]=k;
                    j++;
                }
                store[j]=k;
                j++;
            }else{
                store[j]=k;
                j++;
            }
        }

        int store2[n];
        j=n-1;
        while(j>=0){
            int k=j;
            if(j>0 && b[j]==b[j-1]){
                while(j>0 && b[j]==b[j-1]){
                    store2[j]=k;
                    j--;
                }
                store2[j]=k;
                j--;
            }else{
                store2[j]=k;
                j--;
            }
        }
      
        solve(store, store2);
    }
}
