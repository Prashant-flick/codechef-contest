#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        int res=0;
        int maxi=INT_MIN;
        int brr[61];
        for(int i=0; i<=60; i++){
            int sum=0;
            bool flag2 = false;
            for(int j=0; j<n; j++){
                if((arr[j]&(1LL<<i))==(1LL<<i)){
                    sum++;
                    flag2=true;
                }
            }
            brr[i]=sum;
            if(flag2 && sum%2!=0){
                res+=(1LL<<i);
            }else if(flag2 && sum%2==0){
                if(i>maxi){
                    maxi=i;
                }
            }
        }
        
        if(maxi!=INT_MAX){
            res+=(1LL<<maxi);
            for(int i=maxi-1; i>=0 && maxi!=INT_MIN ; i--){
                if(brr[i]!=0 && brr[i]%2==0){
                    res+=(1LL<<i);
                    maxi--;
                }
            }
            maxi--;
            if(maxi!=0){
                if(brr[0]!=0 && brr[0]%2!=0){
                    res-=1;
                }
            }
        }
        

        cout << res << endl;
    }
    return 0;
}