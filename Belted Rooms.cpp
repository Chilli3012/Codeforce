#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define eps 1e-12
#define inf 0x3f3f3f3f3f3f3f3f
#define MEM(c, b) memset((a), (b), sizeof(a))
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int maxmp = 1e3 + 10;

int main()
{
    fast;
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        string s;
        cin>>n>>s;
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-')
                c++;
            else if(s[i]=='>')
                a++;
            else
                b++;
        }
        if(b==0 || a==0)
            cout<<n<<"\n";
        else
        {
            int res=0;
            if(s[0]=='-' || s[n-1]=='-')
                res++;
            for(int i=1;i<n;i++)
                if(s[i-1]=='-' || s[i]=='-')
                    res++;
            cout<<res<<"\n";
        }
    }
    return 0;
}
