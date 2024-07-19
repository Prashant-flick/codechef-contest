#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans[n];
        if(n==3){
            cout << 3 << " " << 2 << " " << 1 << endl;
            continue;
        }
        if((n/2)%2==1 && n%2==1){
            int i=0; 
            int j=1;
            bool flag=true;
            while(i<n-5){
                if(flag){
                    ans[i]=j;
                    j++;
                    i++;
                    if(i==n-5)break;
                    ans[i]=j;
                    i++;
                    j++;
                    flag=false;
                }else{
                    ans[i]=j+1;
                    i++;
                    if(i==n-5)break;
                    ans[i]=j;
                    i++;
                    j+=2;
                    flag=true;
                }
            }
            // cout << flag << endl;
            ans[i]=j+4;
            i++;
            ans[i]=j+3;
            i++;
            ans[i]=j+2;
            i++;
            ans[i]=j+1;
            i++;
            ans[i]=j;
        }else{
            int i=0;
            int j=1;
            bool flag = true;
            while (i<n)
            {
                if(flag){
                    ans[i]=j;
                    j++;
                    i++;
                    if(i==n)break;
                    ans[i]=j;
                    i++;
                    j++;
                    flag=false;
                }else{
                    ans[i]=j+1;
                    i++;
                    if(i==n)break;
                    ans[i]=j;
                    i++;
                    j+=2;
                    flag=true;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        // bool flag = true;
        // for(int i=2; i<n; i++){
        //     if((ans[i-1]|ans[i-2])==ans[i]){
        //         cout << ans[i-2] << " " << ans[i-1] << " " << ans[i] << endl;
        //         flag = false;
        //         break;
        //     }
        // }
        // cout << flag;
        // cout << endl;
    }
    
    return 0;
}