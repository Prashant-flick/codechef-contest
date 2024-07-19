#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,m,x,y;
        cin >> n >>m >>x >> y;

        int x1,x2,y1,y2;
        x1 = x-1;
        x2 = n-x;
        y1 = y-1;
        y2 = m-y;

        if(x1==x2 && y1==y2){
            cout << 0 << endl;
        }else if(x1==x2){
            if(y1>y2){
                y1 = y1-y2;
                int ans=0;
                for(int i=1; i<=y1; i++){
                    ans^=abs(y-i);
                }
                cout << ans << endl;
            }else{
                y2 = y2-y1;
                int ans=0;
                for(int i=m; i>m-y2; i--){
                    ans^=abs(y-i);
                }
                cout << ans << endl;
            }
        }else if(y1==y2){
            if(x1>x2){
                x1 = x1-x2;
                int ans=0;
                for(int i=1; i<=x1; i++){
                    ans^=abs(x-i);
                }
                cout << ans << endl;
            }else{
                x2 = x2-x1;
                int ans=0;
                for(int i=n; i>n-x2; i--){
                    ans^=abs(x-i);
                }
                cout << ans << endl;
            }
        }else{
            if(x1 > x2 && y1>y2){
                x1-=x2;
                y1-=y2;
                int ans=0;
                if(x1>y1){
                    int p = (x1-y1)+1;
                    int q = 1;
                    for(int i=1; i<=min(x1,y1); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p++;
                        q++;
                    }
                    for(int i=1; i<=x1-y1; i++){
                        for(int j=1; j<=y1; j++){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else if(y1>x1){
                    int p = 1;
                    int q = (y1-x1)+1;
                    for(int i=1; i<=min(x1,y1); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p++;
                        q++;
                    }
                    for(int i=1; i<=x1; i++){
                        for(int j=1; j<=y1-x1; j++){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else{
                    int p = 1;
                    int q = 1;
                    for(int i=1; i<=min(x1,y1); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p++;
                        q++;
                    }
                }


                // if(x1==y1){
                //     cout << ans << endl;
                //     continue;
                // }
                for(int i=1; i<=x1; i++){
                    ans^=(abs(x-i));
                }
                for(int i=1; i<=y1; i++){
                    ans^=(abs(y-i));
                }
                cout << ans << endl;
            }else if(x1>x2 && y2>y1){
                x1-=x2;
                y2-=y1;
                int ans=0;
                if(x1>y2){
                    int p = (x1-y2)+1;
                    int q = m;
                    for(int i=1; i<=min(x1,y2); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p++;
                        q--;
                    }
                    for(int i=1; i<=x1-y2; i++){
                        for(int j=m; j>m-y2; j--){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else if(y2>x1){
                    int p = 1;
                    int q = m-(y2-x1);
                    for(int i=1; i<=min(x1,y2); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p++;
                        q--;
                    }
                    for(int i=1; i<=x1; i++){
                        for(int j=m; j>m-(y2-x1); j--){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else{
                    int p = 1;
                    int q = m;
                    for(int i=1; i<=min(x1,y2); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p++;
                        q--;
                    }
                }

                // if(x1==y2){
                //     cout << ans << endl;
                //     continue;
                // }

                for(int i=1; i<=x1; i++){
                    ans^=(abs(x-i));
                }
                for(int i=m; i>m-y2; i--){
                    ans^=(abs(y-i));
                }
                cout << ans << endl;
            }else if(x1<x2 && y1>y2){
                x2-=x1;
                y1-=y2;
                int ans=0;
                if(x2>y1){
                    int p = n-(x2-y1);
                    int q = 1;
                    for(int i=1; i<=min(x2,y1); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p--;
                        q++;
                    }
                    for(int i=n; i>n-(x2-y1); i--){
                        for(int j=1; j<=y1; j++){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else if(y1>x2){
                    int p = n;
                    int q = (y1-x2)+1;
                    for(int i=1; i<=min(x2,y1); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p--;
                        q++;
                    }
                    for(int i=n; i>n-x2; i--){
                        for(int j=1; j<=y1-x2; j++){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else{
                    int p = n;
                    int q = 1;
                    for(int i=1; i<=min(x2,y1); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p--;
                        q++;
                    }
                }

                // if(x2==y1){
                //     cout << ans << endl;
                //    continue;
                // }

                for(int i=n; i>n-x2; i--){
                    ans^=(abs(x-i));
                }
                for(int i=1; i<=y1; i++){
                    ans^=(abs(y-i));
                }
                cout << ans << endl;
            }else{
                x2-=x1;
                y2-=y1;
                int ans=0;
                if(x2>y2){
                    int p = n-(x2-y2);
                    int q = m;
                    for(int i=1; i<=min(x2,y2); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p--;
                        q--;
                    }
                    for(int i=n; i>n-(x2-y2); i--){
                        for(int j=m; j>m-y2; j--){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else if(y2>x2){
                    int p = n;
                    int q = m-(y2-x2);
                    for(int i=1; i<=min(x2,y2); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p--;
                        q--;
                    }
                    for(int i=n; i>n-x2; i--){
                        for(int j=m; j>m-(y2-x2); j--){
                            ans^=(abs(x-i)+abs(y-j));
                        }
                    }
                }else{
                    int p = n;
                    int q = m;
                    for(int i=1; i<=min(x2,y2); i++){
                        ans^=(abs(x-p)+abs(y-q));
                        p--;
                        q--;
                    }
                }

                // if(x2==y2){
                //     cout << ans << endl;
                //     continue;
                // }

                for(int i=n; i>n-x2; i--){
                    ans^=(abs(x-i));
                }
                for(int i=m; i>m-y2; i--){
                    ans^=(abs(y-i));
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}
