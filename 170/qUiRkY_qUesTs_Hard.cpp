#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++){
            cin >> arr[i];
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        int cnt=0;
        int cnt2=0;
        for(int i=1; i<=n; i++){
            pq.push(arr[i]);
            cnt=cnt+arr[i]+0LL;
            int maxi=(cnt2*cnt2)+cnt;
            priority_queue<int,vector<int>,greater<int>> pq1=pq;
            int j=0;
            int index=-1;
            int cnt21=cnt2;
            int cnt11=cnt;
            bool flag=true;
            while(!pq1.empty()){
                int a = pq1.top();
                cnt2++;
                cnt=cnt-a+0LL;
                pq1.pop();
                if((cnt2*cnt2)+cnt>=maxi){
                    index=j;
                    maxi=(cnt2*cnt2)+cnt;
                }else if(!flag){
                    break;
                }else{
                    flag=false;
                }
                j++;
            }
            index++;
            cnt2=cnt21;
            cnt=cnt11;
            while(!pq.empty() && index--){
                int a = pq.top();
                cnt2++;
                cnt=cnt-a+0LL;
                pq.pop();
            }
            cout << (cnt2*cnt2*1LL)+cnt+0LL << " ";
        }
        cout << endl;
    }
}