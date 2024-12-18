#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int x1,y1,z1,x2,y2,z2,k;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> k;
        int a = abs(x1-x2);
        int b = abs(y1-y2);
        int c = abs(z1-z2);
        int x = max(a,max(b,c));
        int y = a==x?max(b,c):b==x?max(a,c):max(a,b);
        int z = a==x&&b==y?c:a==x&&c==y?b:b==x&&a==y?c:a==y&&c==x?b:a;
        int a1 = a;
        a=(x/k)+(x%k==0?0:1);
        int ans = a1+b+c;
        if(a-1<=(y+z)){
            cout << ans << endl;
        }else{
            int p = (a-1)-(y+z);
            if(p%2!=0){
                p++;
            }
            ans += p;
            cout << ans << endl;
        }
        
    }
}
