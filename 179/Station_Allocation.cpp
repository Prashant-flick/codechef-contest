#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int totsum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            totsum+=arr[i];
        }
        sort(arr, arr+n);
        int q,x,y;
        cin >> q;
        while(q--){
            cin >> x >> y;
            int a = lower_bound(arr, arr+n, x) - arr;
            int res1=1e14,res2=1e14,res3=1e14,res4=1e14;
            if(a==n){
                res1=0;
                res1+=(x-arr[n-1]);
                int b = totsum-arr[n-1];
                if(b<y){
                    res1+=y-b;
                }
            }else{
                if(x<=arr[a]){
                    res2=0;
                    int b = totsum-arr[a];
                    if(b<y){
                        res2+=y-b;
                    }
                    if(a!=0){
                        res4=0;
                        a--;
                        res4+=(x-arr[a]);
                        b = totsum-arr[a];
                        if(b<y){
                            res4+=y-b;
                        }
                    }
                }else{
                    res3=0;
                    res3+=(x-arr[a]);
                    int b = totsum-arr[a];
                    if(b<y){
                        res3+=y-b;
                    }
                }
            }
            cout << min(res1,min(res2,min(res3, res4))) << endl;
        }
    }

}
