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
        string s1,s2;
        cin >> s1 >> s2;
        vector<int> arr1;
        vector<int> arr2;
        int temp1=0,temp2=0;
        bool flag=true;
        for(int i=0; i<n; i++){
            if((s1[i]=='b' && s2[i]!='b') || (s1[i]!='b' && s2[i]=='b')){
                flag=false;
                break;
            }
            else if(s1[i]=='b' && s2[i]=='b'){
                arr1.push_back(temp1);
                arr2.push_back(temp2);
                temp1=0;
                temp2=0;
            }
            else if(s1[i]=='a' && s2[i]=='c'){
                temp1++;
            }else if(s2[i]=='a' && s1[i]=='c'){
                temp2++;
            }
        }
        arr1.push_back(temp1);
        arr2.push_back(temp2);

        if(!flag){
            cout << "No" << endl;
        }else{
            int m = arr1.size();
            flag=true;
            int sum=0;
            for (int i = 0; i < m; i++)
            {
                if(sum>=arr2[i]){
                    sum-=arr2[i];
                }else{
                    flag=false;
                    break;
                }
                if(i==0 && arr2[i]!=0){
                    flag=false;
                    break;
                }
                sum+=arr1[i];
            }
            
            if(flag && sum==0){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}