#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s,t;
        cin >> s >> t;
        int cnt1=0,cnt2=0;
        int i=0,j=0;
        while(i<n && s[i]=='b'){
            cnt1++;
            i++;
        }
        while(j<m && t[j]=='b'){
            cnt2++;
            j++;
        }
        if(cnt1!=cnt2){
            cout << "No" << endl;
            continue;
        }

        vector<int> arr,brr;

        char ch = 'a';
        while(i<n){
            cnt1=0;
            while(i<n && ch==s[i]){
                cnt1++;
                i++;
            }
            ch=ch=='a'?'b':'a';
            arr.push_back(cnt1);
        }
        ch = 'a';
        while(j<m){
            cnt1=0;
            while(j<m && ch==t[j]){
                cnt1++;
                j++;
            }
            ch=ch=='a'?'b':'a';
            brr.push_back(cnt1);
        }

        bool flag=true;
        for(int i=0; i<min(arr.size(),brr.size()); i++){
            if(i%2==0 && arr[i]!=brr[i]){
                flag=false;
            }
        }

        if(!flag){
            cout << "No" << endl;
        }else{
            int s1=arr.size();
            int s2=brr.size();
            if(abs(s1-s2)>=2){
                cout << "No" << endl;
            }else{
                if(i<arr.size()){
                    if(i%2==0){
                        flag=false;
                    }
                }
                if(i<brr.size()){
                    if(i%2==0){
                        flag=false;
                    }
                }
            }
            if(flag){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
                
    }
}
