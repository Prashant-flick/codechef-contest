#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int arr[N];

bool solve(int l, int r, int L, int R, int cnt){
    if(l>=r-1)return true;
    int mid = (l+r)/2,mid1 = (l+r+1)/2;
    if((arr[mid]<L && arr[mid]>R) && (arr[mid1]<L && arr[mid1]>R))return false;
    if(mid==mid1){

    }else{

    }
}

int main() {
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)cin >> arr[i];
        if(((arr[1]!=1 && arr[1]!=2) || (arr[n]!=1 && arr[n]!=2))){
            cout << "NO" << endl;
            continue;
        }
        int l=2,r=n-1;
        if(l>=r){
            cout << "YES" << endl;
            continue;
        }
        int k=2;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({(r-l+1),{l, r}});
        unordered_map<int,int> mp;
        mp[(r-l+1)]++;
        bool flag=true;
        while(!pq.empty()){
            int a = pq.top().first;
            int b = mp[a];
            int l1 = k+1;
            int r1 = k+mp[a]+(a%2==0?mp[a-1]:0);
            if(a==2){
                r1=n;
            }
            // cout << "here " << a << " " << l1 << " " << r1 << endl;
            while(!pq.empty() && (a==pq.top().first || (a%2==0 && pq.top().first==a-1))){
                int L = pq.top().second.first;
                int R = pq.top().second.second;
                int mid = (L+R)/2;
                int mid1 = (L+R+1)/2;
                // cout << L << " " << R << " " << mid << " " << mid1 << endl;
                if(mid==mid1){
                    if(arr[mid]<l1 || arr[mid]>r1){
                        flag=false;
                        break;
                    }
                    k++;
                    mid--;
                    mid1++;
                    if(L<=mid){
                        pq.push({mid-L+1,{L, mid}});
                        mp[mid-L+1]++;
                    }
                    if(mid1<=R){
                        pq.push({R-mid1+1,{mid1, R}});
                        mp[R-mid1+1]++;
                    }
                }else{
                    if((arr[mid]<l1 || arr[mid]>r1) && (arr[mid1]<l1 || arr[mid1]>r1)){
                        flag=false;
                        break;
                    }
                    if((arr[mid]>=l1 && arr[mid]<=r1)){
                        k++;
                        mid1=mid;
                        mid1++;
                        mid--;
                        if(L<=mid){
                            pq.push({mid-L+1,{L, mid}});
                            mp[mid-L+1]++;
                        }
                        if(mid1<=R){
                            pq.push({R-mid1+1,{mid1, R}});
                            mp[R-mid1+1]++;
                        }
                    }else{
                        k++;
                        mid=mid1;
                        mid1++;
                        mid--;
                        if(L<=mid){
                            pq.push({mid-L+1,{L, mid}});
                            mp[mid-L+1]++;
                        }
                        if(mid1<=R){
                            pq.push({R-mid1+1,{mid1, R}});
                            mp[R-mid1+1]++;
                        }
                    }
                }
                pq.pop();
            }
            if(!flag){
                break;
            }
        }
        
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
