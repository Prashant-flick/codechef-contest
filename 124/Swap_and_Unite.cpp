#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int finans=INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            char x = 'a';
            x += i;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]==x)
                {
                    cnt++;
                }
            }
            if(cnt==0)
            {
                continue;
            }
            int l=0;
            int r=cnt-1;
            int cntextra=0;
            for(int i=l;i<=r;i++)
            {
                if(s[i]!=x)
                {
                    cntextra++;
                }
            }
            int ans=cntextra;
            while(r<=n-1)
            {
                ans=min(ans,cntextra);
                if(s[l]!=x)
                {
                    cntextra--;
                }
                l++;
                r++;
                if(r<=n-1 && s[r]!=x)
                {
                    cntextra++;
                }
                
            }
            finans=min(ans,finans);

    
        }
        cout<<finans<<endl;
    }
}
