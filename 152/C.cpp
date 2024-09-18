#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        int arr[n];
        for(int i=0; i<n; i++)cin >> arr[i];
        vector<int> cnt1(n,0);
        vector<int> cnt2(n,0);
        vector<int> cnt3(n,0);
        for(int i=0; i<n; i++){
            if(i!=0){
                cnt1[i]=cnt1[i-1];
                cnt2[i]=cnt2[i-1];
                cnt3[i]=cnt3[i-1];
                if(arr[i]==1){
                    cnt1[i]++;
                }else if(arr[i]==2){
                    cnt2[i]++;
                }else{
                    cnt3[i]++;
                } 
            }else{
                if(arr[i]==1){
                    cnt1[i]=1;
                }else if(arr[i]==2){
                    cnt2[i]=1;
                }else{
                    cnt3[i]=1;
                }
            }
        }

        while(q--){
            int l,r;
            cin >> l >> r;
            if((r-l+1)%2==1){
                cout << "No" << endl;
                continue;
            }
            l--;
            r--;
            int a = cnt1[r]-(l==0?0:cnt1[l-1]); 
            int b = cnt2[r]-(l==0?0:cnt2[l-1]);
            int c = cnt3[r]-(l==0?0:cnt3[l-1]);
            int temp = (r-l+1)/2;
            if(a+b==temp || b+c==temp || c+a==temp){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
