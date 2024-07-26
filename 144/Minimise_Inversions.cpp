#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int ones[n]={0};
        int zeros[n]={0};
        int cnt1=0;
        for(int i=0; i<n; i++){
            ones[i]=cnt1;
            if(s[i]=='1'){
                cnt1++;
            }
        }
        
        cnt1=0;
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            zeros[i]=cnt1;
            if(s[i]=='0'){
                cnt1++;
            }else{
                ans+=cnt1;
            }
        }
        int ans1=ans;

        int i=0;
        int j=n-1;
        while(s[i]!='1'){
            i++;
        }
        while(s[j]!='0'){
            j--;
        }

        int res = ans;
        int i1=i;
        int p=m;
        int sum1=0;
        while(i1<n && p){
            if(s[i1]=='1'){
                sum1+=zeros[i1];
                p--;
            }
            i1++;
        }

        int j1=j;
        p=m;
        int sum2=0;
        while(j1>=0 && p){
            if(s[j1]=='0'){
                sum2+=ones[j1];
                p--;
            }
            j1--;
        }

        p=m;
        while(p-- && i<=j){
            if(zeros[i]==ones[j]){
                if(sum1 >= sum2){
                    ans-=zeros[i];
                    sum1-=zeros[i];
                    i++;
                    for(int k=i; k<=j; k++){
                        ones[k]--;
                    }
                }else if(sum1 < sum2){
                    ans-=ones[j];
                    sum2-=ones[j];
                    j--;
                    for(int k=j; k>=i; k--){
                        zeros[k]--;
                    }
                }
            }
            else if(zeros[i]>ones[j]){
                ans-=zeros[i];
                i++;
                for(int k=i; k<=j; k++){
                    ones[k]--;
                }
            }else{
                ans-=ones[j];
                j--;
                for(int k=j; k>=i; k--){
                    zeros[k]--;
                }
            }
            while(s[i]!='1'){
                i++;
            }
            while(s[j]!='0'){
                j--;
            }
        }

        // int res = min(ans1-cnt1, ans1-cnt2);

        cout << min(ans,min(ans1-sum1, ans1-sum2)) << endl;
    }
}
