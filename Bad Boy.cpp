#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        int x,y;
        cin>>n>>m>>x>>y;
        if((x==1 and y==1) || (x==n and y==m))
        {
            cout<<1<<" "<<m<<" ";
            cout<<n<<" "<<1<<"\n";
        }
        else
        {
            cout<<1<<" "<<1<<" ";
            cout<<n<<" "<<m<<"\n";
        }
    }
    return 0;
}
