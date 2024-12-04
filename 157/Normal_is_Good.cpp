#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)cin >> arr[i];
	    int i=0,j=0;
	    int ans=0;
	    while(i<n){
	        int cnt=1;
	        if(i<n-1 && arr[i]==arr[i+1]){
	            while(i<n-1 && arr[i]==arr[i+1]){
    	            cnt++;
    	            i++;
    	        }
    	        i++;
	        }else{
	            i++;
	        }
	        ans+=cnt;
	        cnt--;
	        ans+=(cnt*(cnt+1))/2;
	        
	    }

        i=0,j=0;
        int cnt1=0,cnt2=0,cnt3=0;
        while(j<n){
            if(arr[j]==1){
                cnt1++;
            }else if(arr[j]==2){
                cnt2++;
            }else{
                cnt3++;
            }
            if(cnt1>cnt3){
                while (i<n && cnt1>cnt3)
                {
                    if(arr[i]==1){
                        cnt1--;
                    }else if(arr[i]==2){
                        cnt2--;
                    }else{
                        cnt3--;
                    }
                    i++;
                } 
            }
            if(cnt1>0 && cnt3>0 && cnt1==cnt3 && j-i+1>=3){
                ans+=cnt2>0?1:0;
            }
            j++;
        }
        // j=n-1,i=n-1;
        // cnt1=cnt2=cnt3=0;
        // while(j>=0){
        //     if(arr[j]==1){
        //         cnt1++;
        //     }else if(arr[j]==2){
        //         cnt2++;
        //     }else{
        //         cnt3++;
        //     }
        //     if(cnt3>cnt1){
        //         while (i>=0 && cnt3>cnt1)
        //         {
        //             if(arr[i]==1){
        //                 cnt1--;
        //             }else if(arr[i]==2){
        //                 cnt2--;
        //             }else{
        //                 cnt3--;
        //             }
        //             i--;
        //         } 
        //     }
        //     if(cnt1>0 && cnt3>0 && cnt1==cnt3 && (i-j)+1>=3){
        //         ans+=cnt2>0?1:0;
        //     }
        //     j--;
        // }
	    cout << ans << endl;
	}

}
