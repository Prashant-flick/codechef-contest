  #include <bits/stdc++.h>
  using namespace std;

  #define int long long

  int32_t main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);cout.tie(NULL);

      int t=1;
      cin >> t;
      while(t--){
        int n, q;
        cin >> n >> q;
        int arr[n];
        int maxi = INT_MIN;
        int ans = 0;
        for(int i=0; i<n; i++){
          cin >> arr[i];
          if(i==0){
            ans = arr[i];
          }else{
            ans = (ans&arr[i]);
          }
          maxi=max(maxi, arr[i]);
        }

        int store[22]={0};
        int mp[22]={0};
        for(int i=0; i<=21; i++){
          int j=0;
          int cnt=0;
          int cnt3=0;
          while(j<n){
            int cnt1=0;
            bool flag=true;
            while(j<n && ((arr[j]&(1<<i))==(1<<i))){
              cnt1++;
              j++;
              flag=false;
            }

            int cnt2=0;
            while(j<n && ((arr[j]&(1<<i))==0)){
              cnt2++;
              j++;
              flag=false;
            }
            if(flag){
              j++;
            }
            if(cnt2){
              cnt3++;
            }
            cnt+=cnt1;
          }
          store[i]=cnt;
          mp[i]=cnt3;
        }

        while(q--){
          int x,y;
          cin >> x >> y;
          int sum1=0;
          int j=21;
          bool flag=false;

          while(j>=0){
            if(((1<<j)&y)==(1<<j)){
              if(store[j]==n){
                flag=true;
                j--;
                break;
              }else{
                if(mp[j]<=x){
                  sum1=(sum1+0LL+(1<<j));
                  flag=true;
                  j--;
                  break;
                }else{
                  j--;
                }
              }
            }else{
              j--;
            }
          }

          if(flag){
            while(j>=0){
              if(((1<<j)&y)==(1<<j)){
                if(store[j]==n){
                  sum1 = (sum1-(1<<j));
                }
                j--;
              }else{
                j--;
              }
            }
          }

          cout << (ans+sum1) << endl;
        }
      }
      return 0;
  }
