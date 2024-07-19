#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n >> x;
        if(x>(n-2) && x!=0){
            cout << -1 << endl;
        }else{
            if (n%2==0)
            {
                if(x%2==0){
                    int a = n-x;
                    a/=2;
                    int b = n-a;
                    b++;
                    for (int i = b; i <= n; i++)
                    {
                        cout << i << " ";
                    }
                    for (int i = 1; i < b; i++)
                    {
                        cout << i << " ";
                    }
                    cout << endl;
                }else{
                    x++;
                    int a = n-x;
                    a/=2;
                    int b = n-a;
                    b++;
                    cout << 1 << " ";
                    for (int i = b; i <= n; i++)
                    {
                        cout << i << " ";
                    }
                    for (int i = 2; i < b; i++)
                    {
                        cout << i << " ";
                    }
                    cout << endl;
                }
            }else{
                if(x%2!=0){
                    int a = n-x;
                    a/=2;
                    int b = n-a;
                    b++;
                    for (int i = b; i <= n; i++)
                    {
                        cout << i << " ";
                    }
                    for (int i = 1; i < b; i++)
                    {
                        cout << i << " ";
                    }
                    cout << endl;
                }else{
                    x++;
                    int a = n-x;
                    a/=2;
                    int b = n-a;
                    b++;
                    cout << 1 << " ";
                    for (int i = b; i <= n; i++)
                    {
                        cout << i << " ";
                    }
                    for (int i = 2; i < b; i++)
                    {
                        cout << i << " ";
                    }
                    cout << endl;
                }
            }
            
            
        }
    }
    
    return 0;
}