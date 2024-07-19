#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int arr[n];
        int brr[n];
        int totsum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            brr[i]=arr[i];
            totsum+=arr[i];
        }

        sort(brr, brr+n);

        int ans[n/2+1];
        ans[0]=arr[0];

        int neg=0;
        int mini=0;
        int maxi=n/2;
        for(int i=0; i<n/2; i++){
            neg+=brr[i];
        }

        ans[n/2]=totsum-(2*neg);
        for(int i=n-1; i>2;){
            totsum-=arr[i];
            neg-=brr[maxi];
            maxi++;
            if(arr[i]==brr[mini]){
                neg-=brr[mini];
                mini++;
                maxi++;
                neg+=brr[maxi];
            }else if(arr[i]==brr[maxi]){
                neg-=brr[maxi];
                maxi++;
                neg+=brr[maxi];
            }else if(arr[i]<maxi && arr[i]>mini){
                neg-=arr[i];
                maxi++;
                neg+=brr[maxi];
            }

            totsum-=arr[i-1];
            if(arr[i-1]==brr[mini]){
                neg-=brr[mini];
                mini++;
                maxi++;
                neg+=brr[maxi];
            }else if(arr[i-1]==brr[maxi]){
                neg-=brr[maxi];
                maxi++;
                neg+=brr[maxi];
            }else if(arr[i-1]<maxi && arr[i-1]>mini){
                neg-=arr[i-1];
                maxi++;
                neg+=brr[maxi];
            }

            i-=2;
            // cout << i << " " << totsum << " " << neg << endl;
            ans[i/2]=totsum-(2*neg);
        }

        
        for(int i=0; i<q; i++){
            int k;
            cin >> k;
            cout << ans[k/2] << " ";
        }
        cout << endl;
    }
}
