#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int sum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum+=arr[i];
        }
        
        int i=1;
        int ans=0;
        while(i<n){
            if(arr[i]==3 && arr[i-1]==2 && arr[i+1]==2){
                arr[i]=1;
                ans+=2;
                i++;
            }else if(arr[i]==3 && arr[i-1]==1 && arr[i+1]==3){
                int j=i+1;
                int cnt=1;
                while(j<n && arr[j]==arr[j+1]){
                    arr[j]=1;
                    cnt++;
                    j++;
                }
                ans+=(2*cnt);
                j++;
                while(j<n && arr[j]==1 && arr[j]==arr[j+1]){
                    j++;
                }
                j++;
                i=j;
            }else if(arr[i]==3 && arr[i-1]==3 && arr[i+1]==1){
                int j=i-1;
                int cnt=1;
                while(j>=0 && arr[j]==arr[j-1]){
                    arr[j]=1;
                    j--;
                    cnt++;
                }
                ans+=(2*cnt);
                i++;
            }else{
                i++;
            }
        }

        cout << sum - ans << endl;
    }
}
