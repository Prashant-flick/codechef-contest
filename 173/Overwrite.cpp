#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5+10;
int n,m;
int arr[N],brr[N],crr[N];

signed main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int mini=INT_MAX;
        int idx=-1;
        for(int i=0; i<m; i++){
            cin >> brr[i];
            if(mini>brr[i]){
                mini=brr[i];
                idx=i;
            }
        }
        if(m==1){
            for(int i=0; i<n; i++){
                arr[i]=min(arr[i],mini);
                cout << arr[i] << " ";
            }
            cout << endl;
            continue;
        }
        for(int i=0; i<m; i++){
            crr[i]=brr[(idx+i)%m];
        }
        int i=0;
        bool flag=false;
        for(; i<=n-m; i++){
            if(arr[i]>crr[0]){
                arr[i]=crr[0];
                flag=true;
                break;
            }
        }
        if(flag){
            for(; i<=n-m; i++){
                arr[i]=crr[0];
            }
            int k=1;
            for(; i<n; i++){
                arr[i]=crr[k];
                k++;
            }
        }else if(arr[n-m]==crr[0]){
            bool flag=true;
            for(int i=n-m; i<n; i++){
                if(arr[i]>crr[i-(n-m)]){
                    break;
                }else if(arr[i]<crr[i-(n-m)]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                for(int i=n-m; i<n; i++){
                    arr[i]=crr[i-(n-m)];
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
