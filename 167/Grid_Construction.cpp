#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mid = (n+1)/2;
        for(int i=1; i<=n; i++){
            int s = mid;
            for(int j=1; j<=n; j++){
                if(s==n+1)s=1;
                cout << s << " ";
                s++;
            }
            mid--;
            if(mid==0)mid=n;
            cout << endl;
        }
    }
}
