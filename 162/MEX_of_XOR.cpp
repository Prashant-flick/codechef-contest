#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int l,r,x;
        cin >> l >> r >> x;
        if(l>x || r<x){
            cout << 0 << endl;
            continue;
        }

        int lf = (32 - __builtin_clz(x));
        cout << lf << endl;
        int start1=0,end=0,last=r-x;

        for(int i=0; i<lf; i++){
            if(((1<<i)&(x))!=(1<<i)){
                start1=(1<<i);
                break;
            }
        }
        
        int cnt=0;

        bool flag=false;
        for(int i=0; i<lf; i++){
            cnt+=(1<<i);
            if(((1<<i)&(x))!=(1<<i)){
                if(cnt<=last){
                    end=cnt;
                }else{
                    flag=true;
                    break;
                }
            }
        }

        // if(flag){
        //     cnt=0;
        //     for(int i=0; i<lf; i++){
        //         cnt+=(1<<i);
        //         if(((1<<i)&(x))!=(1<<i)){
        //             if(cnt<=r){
        //                 end=cnt;
        //             }else{
        //                 flag=true;
        //                 break;
        //             }
        //         }
        //     }
        // }

        cout << start1 << " " << end;
    }
}
