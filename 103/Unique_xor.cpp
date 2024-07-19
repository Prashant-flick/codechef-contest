
    #include <bits/stdc++.h>

    using namespace std;

    #define ll long long

    int main() {
        // your code goes here
        int t;
        cin >> t;
        while(t--){
            int n,k;
            string s;
            cin >> n >> k >> s;
            if(k==1){
                int zeros=0;
                int ones=0;
                for(int i=0; i<n; i++){
                    if(s[i]=='0'){
                        zeros++;
                    }else{
                        ones++;
                    }
                }
                if(ones%2==0){
                    ones/=2;
                }else{
                    ones = ones/2 + 2;
                }
                cout << min(zeros,ones) << endl;
            }else{
                int totzero=0;
                int totone=0;
                bool flag = true;
                for (int i = 0; i < k; i++)
                {
                    bool flag2=true;
                    int ones=0;
                    int zeros=0;
                    for(int j=i; j<n; j+=k){
                        if(s[j]=='0'){
                            zeros++;
                        }else{
                            flag2=false;
                            ones++;
                        }
                    }
                    if(flag2){
                        flag=false;
                    }
                    totzero+=zeros;
                    if(ones%2==0){
                        totone+=(ones/2);
                    }else{
                        totone += (ones/2)+2;
                    }
                }

                if(!flag){
                    cout << totone << endl;
                    continue;
                }
                cout << min(totone,totzero) << endl;
            }
        
            
        }
        
        return 0;
    }
