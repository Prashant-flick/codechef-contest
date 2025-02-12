#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mid = n/2;
        if((n%4)!=0){
            // cout << "here" << endl;
            for(int i=1; i<=n; i++){
                int s = mid;
                for(int j=1; j<=n; j++){
                    if(s==n+1)s=1;
                    cout << s << " ";
                    s++;
                }
                mid--;
                if(mid==0)mid=n;
                cout << endl;
            }
        }else{
            int arr[n];
            arr[0]=mid;
            int k = mid+2;
            int i=1;
            for(; i<n-1; i+=2){
                arr[i]=k;
                k+=2;
                if(k>n)k-=n;
            }
            arr[i]=mid+1;
            if(n>4){
                arr[i-1]=2;
                arr[i-2]--;
            }else{
                arr[0]=2;arr[1]=4;arr[2]=3;arr[3]=1;
            }
            k=3;
            for(int i=2; i<n-2; i+=2){
                if(k==arr[n-1])k+=2;
                arr[i]=k;
                k+=2;
            }
            // for(int i=0; i<n; i++){
            //     cout << arr[i] << " ";
            // }
            // cout << endl;
            k=0;
            for(int i=1; i<=n; i++){
                for(int j=0; j<n; j++){
                    cout << arr[((j-k)+n)%n] << " ";
                }
                cout << endl;
                k++;
            }
        }
        
    }
}
