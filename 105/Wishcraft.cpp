#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p,q;
        cin >> p >> q;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if(n==1){
            cout << arr[0] << endl;
            continue;
        }
        sort(arr,arr+n);
        if(arr[0]>=0){
            int mini=arr[0];
            int maxi=arr[n-1];
            int i=1;
            int j=n-2;
            while(q && i<=j){
                mini-=arr[j];
                j--;
                q--;
            }
            while(p && i<=j){
                maxi+=arr[j];
                j--;
                p--;
            }
            cout << maxi-mini << endl;
        }else if(arr[n-1]<=0){
            int mini=arr[0];
            int maxi=arr[n-1];
            int i=1;
            int j=n-2;
            while(q && i<=j){
                maxi-=arr[i];
                i++;
                q--;
            }
            while(p && i<=j){
                mini+=arr[i];
                i++;
                p--;
            }
            cout << maxi-mini << endl;
        }else{
            int i=1;
            int j=n-2;
            int mini=arr[0];
            int maxi=arr[n-1];
            while (q && i<=j)
            {
                if(arr[i]>=0 || arr[j]<=0){
                    break;
                }
                if(abs(arr[i])>=arr[j]){
                    maxi-=arr[i];
                    i++;
                }else{
                    mini-=arr[j];
                    j--;
                }
                q--;
            }
            if(q>0){
                if(arr[i]>=0){
                    while(q && i<=j){
                        mini-=arr[j];
                        j--;
                        q--;
                    } 
                }else if(arr[j]<=0){
                    while(q && i<=j){
                        maxi-=arr[i];
                        i++;
                        q--;
                    }
                }
            }

            while (p && i<=j)
            {
                if(arr[i]>=0 || arr[j]<=0){
                    break;
                }
                if(abs(arr[i])>=arr[j]){
                    mini+=arr[i];
                    i++;
                }else{
                    maxi+=arr[j];
                    j--;
                }
                p--;
            }
            if(p>0){
                if(arr[i]>=0){
                    while(p && i<=j){
                        maxi+=arr[j];
                        j--;
                        p--;
                    }
                }else if(arr[j]<=0){
                    while(p && i<=j){
                        mini+=arr[i];
                        i++;
                        p--;
                    }
                }
            }
            cout << maxi-mini+0LL << endl;
        }
        
        
    }
    
    return 0;
}