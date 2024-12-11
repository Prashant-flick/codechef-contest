#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;

void solve(int *arr, int *res){
    int i=1;
    int j=n-1;
    int k=0;
    while(k<n){
        if(k%2==0){
            res[k]=arr[i];
            k++;
            i+=2;
        }else{
            res[k]=arr[j];
            j-=2;
            k++;
        }
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n+1];
        for(int i=1;i<=n;i++){
            arr[i]=i;
        }

        int sum=0;
        for(int i=0; i<1e5; i++){
            sum+=i;
        }
        for(int i=0; i<1e5; i++){
            sum-=i;
        }
        int res[n];  
        if(sum==0){
            solve(arr,res);
        }

        if(n%2==0){
            cout << -1 << endl;
            continue;
        }
        for(int i=0; i<n; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}