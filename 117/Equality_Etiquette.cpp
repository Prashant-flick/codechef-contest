#include <iostream> 
#include <bits/stdc++.h> 
 
using namespace std;

#define int long long
 
int32_t main() { 
    int t; 
    cin >> t; 
 
    while (t--) { 
        int x, y; 
        cin >> x >> y; 
        if (x == y) {
             cout << 0 << endl; continue; 
        } 
 
        int diff = abs(x- y); 
        int total = 0;
        int ans;

        int low=0,high=diff;
        int mid = (low+high)/2;
        while (low<=high)
        {
            if((mid*(mid+1))/2==diff){
                break;
            }else if((mid*(mid+1))/2>diff){ 
                high=mid-1;
            }else{
                low=mid+1;
            }
            mid=(low+high)/2;
        }
        if((mid*(mid+1))/2==diff){
            cout << mid << endl;
            continue;
        }
        mid++;
        if(((mid*(mid+1))/2-diff)%2==0){
            cout << mid << endl;
            continue;
        }
        mid++;
        if(((mid*(mid+1))/2-diff)%2==0){
            cout << mid << endl;
        }else{
            cout << mid+1 << endl;
        }

        // for (int i = 1; i <= diff; i++)
        // {
        //     total+=i;
        //     if(diff==total){
        //         ans = i;
        //         break;
        //     }
        //     if(diff<total){
        //         if((total-diff)%2==0){
        //             ans = i;
        //             break;
        //         }else{
        //             if(((total%2==0) && ((i+1)%2!=0)) || ((total%2!=0) && ((i+1)%2!=0))){
        //                 ans = i+1;
        //                 break;
        //             }else{
        //                 ans = i+2;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // if(ans==0)ans = -1;
        // cout << ans << endl;
        
    } 
 
    return 0; 
}