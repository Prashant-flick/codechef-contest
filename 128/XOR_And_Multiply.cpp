#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[32];
        for(int i=0; i<32; i++){
            if(((1<<i)&n)==(1<<i)){
                // cout << i << " " << 1 << endl;
                arr[i]=1;
            }else{
                // cout << i << " " << 0 << endl;
                arr[i]=0;
            }
        }
        
        int a = n;
        while(a+n<=8e18){
            a*=2;
            bool flag=true;
            for(int i=0; i<64; i++){
                if(((1<<i)&a)==(1<<i)){
                    if(i<32 && arr[i]==1){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                cout << a+n << " " << a << endl;
                break;
            }
        }
        
    }
    return 0;
}
