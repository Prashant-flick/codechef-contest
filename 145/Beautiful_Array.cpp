  #include <bits/stdc++.h>
  using namespace std;

  int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);cout.tie(NULL);

      int t=1;
      cin >> t;
      while(t--){
        int n, q;
        cin >> n >> q;
        int arr[n];
        int ans = 0;
        for(int i=0; i<n; i++){
          cin >> arr[i];
          if(i==0){
            ans = arr[i];
          }else{
            ans = (ans&arr[i]);
          }
        }

        int mp[21]={0};
        string s[21];
        for(int i=0; i<21; i++){
          int j=0;
          int cnt3=0;
          string s1="";
          while(j<n){
            while(j<n && ((arr[j]&(1<<i))==(1<<i))){
              j++;
              s1+='1';
            }

            int cnt2=0;
            while(j<n && ((arr[j]&(1<<i))==0)){
              cnt2++;
              j++;
              s1+='0';
            }
            if(cnt2){
              cnt3++;
            }
          }
          s[i]=s1;
          mp[i]=cnt3;
        }

        while(q--){
          int x,y;
          cin >> x >> y;
          int sum1=0;
          bool flag=false;
          int j=21;

          int index=0;
          while(j>=0){
            if(((1<<j)&y)==(1<<j)){
              if(mp[j]==0){
                j--;
                break;
              }else{
                if(mp[j]<=x){
                  index=j;
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
                if(mp[j]==0){
                  sum1 = (sum1-(1<<j));
                }else if(s[index]==s[j]){
                  sum1 = (sum1+(1<<j));
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
