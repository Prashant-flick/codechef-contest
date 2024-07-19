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
        int arr[n];
        int totsum=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            totsum+=arr[i];
        }

        if(n==1){
            cout << arr[0] << endl;
            continue;
        }

        bool flag1=true,flag2=true,flag3=true;
        int sum=0;
        int maxi1 = 0;
        int j=0;
        int index1=0,index2=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(i-j>=1 && maxi1>sum){
                index1=j;
                index2=i;
                maxi1=sum;
            }
            if(sum>0){
                sum=0;
                j=i+1;
            }
        }

        sum=0;
        j=n-1;
        int maxi2=0;
        int index3=0,index4=0;
        for(int i=n-1; i>=0; i--){
            sum+=arr[i];
            if(j-i>=1 && maxi2>sum){
                index3=i;
                index4=j;
                maxi2=sum;
            }
            if(sum>0){
                sum=0;
                j=i-1;
            }
        }

        int maxi3=0;
        int index5=0,index6=0;
        for(int i=0; i<n-1; i++){
            sum = arr[i]+arr[i+1];
            if(maxi3>sum){
                index5=i;
                index6=i+1;
                maxi3=sum;
            }
        }

        if(maxi2<maxi1){
            index1=index3;
            index2=index4;
            maxi1=maxi2;
        }

        if(maxi3<maxi1){
            index1=index5;
            index2=index6;
            maxi1=maxi3;
        }

        int sum2=0;
        if(index2-index1>=1){
            for(int i=0; i<index1; i++){
                sum2+=arr[i];
            }

            for(int i=index2+1; i<n; i++){
                sum2+=arr[i];
            }
        }

        cout << sum2 + abs(maxi1) << endl;
    }
}